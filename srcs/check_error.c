/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:21:30 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:35 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int argc, char *argv[], t_main *main)
{
	if (argc < 5)
	{
		ft_printf("You need to put at least 4 or 5 arguments\n");
		return (0);
	}
	else if (init_input(argc, argv, main) == FALSE)
	{
		ft_printf("Some arguments are wrong, test numbers\n");
		return (0);
	}
	return (1);
}

int	init_input(int argc, char *argv[], t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = philo_atoi(argv[1]);
		main->input.time_to_die = philo_atoi(argv[2]);
		main->input.time_to_eat = philo_atoi(argv[3]);
		main->input.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_eat = philo_atoi(argv[5]);
		return (TRUE);
	}
	return (FALSE);
}
