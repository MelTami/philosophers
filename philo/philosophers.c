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

#include "includes/philo.h"

int	main(int argc, char *argv[])
{
	t_main	main;

	if (check_error(argc, argv, &main) == FALSE)
		return (FALSE);
	printf("To funcionando\n");
	return (0);
}
