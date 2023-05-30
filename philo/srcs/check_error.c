/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:21:30 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/30 21:26:58 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_error(int argc, char *argv[], t_main *main)
{
	if (argc < 5)
	{
		printf("You need to put at least 4 or 5 arguments\n");
		return (FALSE);
	}
	else if (check_numbers(argv) == FALSE)
	{
		printf("Some arguments are wrong, test numbers\n");
		return (FALSE);
	}
	else
		init_input(argc, argv, main);
	return (TRUE);
}

int	init_input(int argc, char *argv[], t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->data.num_philo = philo_atoi(argv[1]);
		main->data.time_to_die = philo_atoi(argv[2]);
		main->data.time_to_eat = philo_atoi(argv[3]);
		main->data.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->data.num_of_times_eat = philo_atoi(argv[5]);
		return (TRUE);
	}
	return (FALSE);
}

