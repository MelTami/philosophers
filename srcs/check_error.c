/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:21:30 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/21 22:47:20 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_error(int argc, char *argv[], t_main **main)
{
	if (argc < 5)
	{
		ft_printf("You need to put at least 4 or 5 arguments\n");
		return (0);
	}
	argv[1] = "1";
	// if (init_input(argc, argv, main) == FALSE)
	// {
	// 	ft_printf("Some arguments are wrong, test numbers\n");
	// 	return (0);
	// }
	return (1);
}