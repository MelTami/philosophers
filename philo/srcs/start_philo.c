/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:14:14 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 16:58:14 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	unlock_mutex(t_philo *philo)
{
	if (philo->main->should_stop)
	{
		pthread_mutex_unlock(&philo->main->forks[philo->rfork]);
		pthread_mutex_unlock(&philo->main->forks[philo->lfork]);
		return (1);
	}
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->forks[philo->rfork]);
	if (philo->main->should_stop)
	{
		pthread_mutex_unlock(&philo->main->forks[philo->rfork]);
		return ;
	}
	print_status(get_now(), philo, FORK);
	pthread_mutex_lock(&philo->main->forks[philo->lfork]);
	if (unlock_mutex(philo))
		return ;
	print_status(get_now(), philo, FORK);
	philo->last_meal = get_now();
	print_status(get_now(), philo, EAT);
	philo->ate++;
	usleep(philo->main->time_to_eat * 1000);
	if (unlock_mutex(philo))
		return ;
	print_status(get_now(), philo, SLEEP);
	pthread_mutex_unlock(&philo->main->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->main->forks[philo->lfork]);
}


void	*alone_philo(t_philo *philo)
{
	print_status(get_now(), philo, FORK);
	usleep(philo->main->time_to_die * 1000);
	return (NULL);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->main->num_philo == 1)
		return (alone_philo(p));
	if (p->id % 2 == 0)
		usleep(1600);
	while (!p->main->should_stop)
	{
		eat(p);
		if (p->main->should_stop)
			break ;
		usleep(p->main->time_to_sleep * 1000);
		if (p->main->should_stop)
			break ;
		print_status(get_now(), p, THINK);
	}
	return (0);
}

int	start_life(t_main *main)
{
	int	i;

	i = -1;
	main->start = get_now();
	while (++i < main->num_philo)
		pthread_create(&main->philo[i].thread, NULL, &routine, &main->philo[i]);
	pthread_create(&main->monitor, NULL, &monitor_routine, main);
	i = -1;
	while (++i < main->num_philo)
		pthread_join(main->philo[i].thread, NULL);
	pthread_join(main->monitor, NULL);
	return (0);
}
