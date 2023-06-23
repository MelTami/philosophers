/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:23:07 by mvavasso          #+#    #+#             */
/*   Updated: 2023/06/23 14:27:48 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_status(long int now, t_main *main, char *status)
{
	pthread_mutex_lock(main->print);
	printf("%ld %d %s\n", (now - main->start), main->philo->id, status);
	pthread_mutex_unlock(main->print);
	return (0);
}
