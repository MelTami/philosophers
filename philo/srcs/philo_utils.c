/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:02:54 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/09 14:31:39 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > INT_MAX)
		return (0);
	return (n);
}

int	check_numbers(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (philo_isdigit(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	philo_isdigit(char *nb)
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

void	free_all(t_main *main)
{
	free(main->philo);
	free(main->forks);
	destroy_threads(main);
}