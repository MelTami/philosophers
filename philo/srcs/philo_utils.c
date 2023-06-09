/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:02:54 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 16:24:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int	check_numbers(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = main->num_philo;
	while (i)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i--;
	}
	pthread_mutex_destroy(main->print);
	return (0);
}

int	ft_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
	free(main->print);
	destroy_threads(main);
	return (0);
}

long int	get_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
