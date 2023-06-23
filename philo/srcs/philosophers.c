/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:35:26 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/11 13:35:26 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_main	main;

	memset(&main, '\0', sizeof(t_main));
	if (check_error(argc, argv, &main) == FALSE)
		return (FALSE);
	start_life(&main);
	ft_free(&main);
	return (0);
}
