/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:37:40 by mvavasso          #+#    #+#             */
/*   Updated: 2023/05/30 18:59:29 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void* routine(void *i)
{
    int     *aux;
    
    aux = i;
    printf("Philosopher %d %s\n", *aux, EAT);
    printf("Philosopher %d %s\n", *aux, SLEEP);
    printf("Philosopher %d %s\n", *aux, THINK);
    return (0);
}

int    init_philo(t_main *main)
{
    int i;

    i = 0;
    while (i < main->data.num_philo)
    {
        pthread_create(&main->philo[i++].thread, NULL, &routine, &i);
    }
    i = 0;
    while (i < main->data.num_philo)
    {
        pthread_join(main->philo[i++].thread, NULL);
    }
    
    return (TRUE);
}

void    creat_philos(t_main *main)
{
    main->philo = malloc(sizeof(t_philo) * main->data.num_philo);
    main
}