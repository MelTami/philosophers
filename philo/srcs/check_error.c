/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:21:30 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 15:00:33 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_input(int argc, char *argv[], t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->num_philo = philo_atoi(argv[1]);
		main->time_to_die = philo_atoi(argv[2]);
		main->time_to_eat = philo_atoi(argv[3]);
		main->time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->num_of_times_eat = philo_atoi(argv[5]);
		main->num_forks = main->num_philo;
		return (TRUE);
	}
	return (FALSE);
}

int	invalid_args(t_main *main, char **argv)
{
	if (main->num_philo == 0)
	{
		printf("There are less than 1 philosopher.\n");
		return (FALSE);
	}
	else if (main->time_to_die == 0 || main->time_to_eat == 0 || \
	main->time_to_sleep == 0)
	{
		printf("There are invalid arguments.\n");
		return (FALSE);
	}
	else if (argv[5] && main->num_of_times_eat <= 0)
		return (printf("There are invalid arguments.\n"));
	return (TRUE);
}

int	create_philos(t_main *main)
{
	int	i;

	i = 0;
	main->philo = malloc(sizeof(t_philo) * main->num_philo);
	main->forks = malloc(sizeof(pthread_mutex_t) * main->num_philo);
	main->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(main->print, NULL);
	while (i < main->num_philo)
	{
		main->philo[i].id = i + 1;
		main->philo[i].ate = 0;
		main->philo[i].rfork = i;
		main->philo[i].lfork = i + 1;
		main->philo[i].last_meal = get_now();
		main->philo[i].main = main;
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
	main->philo[i - 1].lfork = 0;
	return (0);
}

int	check_error(int argc, char *argv[], t_main *main)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("You need to put at least 4 or 5 arguments\n");
		return (FALSE);
	}
	while (argv[i])
	{
		if (check_numbers(argv[i]) == FALSE)
		{
			printf("The arguments need to be numbers! Try again.\n");
			return (FALSE);
		}
		i++;
	}
	if (init_input(argc, argv, main) == FALSE)
		return (FALSE);
	if (invalid_args(main, argv) == FALSE)
		return (FALSE);
	create_philos(main);
	if (!main->forks || !main->philo)
		return (ft_free(main));
	return (TRUE);
}
