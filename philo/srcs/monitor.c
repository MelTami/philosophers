/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:42:54 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 20:13:10 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	should_stop(t_main *main)
{
	int	i;
	int	have_ate_enough;

	i = 0;
	have_ate_enough = 0;
	while (i < main->num_philo)
	{
		if ((get_now() - main->philo[i].last_meal) >= main->time_to_die)
		{
			print_status(get_now(), main->philo, DIED);
			return (1);
		}
		if (main->philo[i].ate >= main->num_of_times_eat)
			have_ate_enough++;
		i++;
	}
	if (main->num_of_times_eat && (have_ate_enough == main->num_philo))
		return (1);
	return (0);
}

void	*monitor_routine(void *set)
{
	t_main	*main;

	main = set;
	while (!main->should_stop)
	{
		main->should_stop = should_stop(main);
		usleep(500);
	}
	return (NULL);
}