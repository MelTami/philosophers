/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:14:14 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/09 21:19:52 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*alone_philo(t_main *main)
{
	print_status(get_now(), main->philo, FORK);
	usleep(main->data.time_to_die * 1000);
	return (NULL);
}

void	start_life(t_main *main)
{
	int	i;

	i = 0;
	main->start = get_now();
	while (i < main->data.num_philo)
	{
		pthread_create(&main->philo[i++].thread, NULL, &routine, &i);
	}
	i = 0;
	while (i < main->data.num_philo)
	{
		pthread_join(main->philo[i++].thread, NULL);
	}
	return (TRUE);
}// if(main->data.num_philo == 1)
	// 	alone_philo(main);
	
}