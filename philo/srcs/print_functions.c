/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:23:07 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 16:49:13 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_status(long int now, t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->main->print);
	printf("%ld %d %s\n", (now - philo->main->start), philo->id, status);
	pthread_mutex_unlock(philo->main->print);
	return (0);
}
