/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:37 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/11 13:16:37 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define FALSE 0
# define TRUE 1

# define INT_MAX 2147483647

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}	t_data;

typedef struct s_forks
{
	pthread_mutex_t	mutex;
}	t_forks;

typedef struct s_philo
{
	int				rfork;
	int				lfork;
	pthread_t		thread;
	t_forks			*forks;
}	t_philo;

typedef struct s_main
{
	int				num_forks;
	t_data			data;
	t_philo			*philo;
}	t_main;

int		check_numbers(char *nb);
int		init_input(int argc, char *argv[], t_main *main);
int		philo_atoi(char *str);
int		check_error(int argc, char *argv[], t_main *main);
int		init_philo(t_main *main);
void	*routine(void *i);
void	creat_philos(t_main *main);
void	ft_free(t_main *main);

#endif