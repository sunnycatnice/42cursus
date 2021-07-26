/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:33:58 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/26 15:34:00 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_init(t_philo *philo)
{
	philo->n_philo = 0;
	philo->todie = 0;
	philo->toeat = 0;
	philo->tosleep = 0;
	philo->n_musteat = 0;
	philo->i = 0;
}

static int	ft_parser_checker(int ac, char **av, t_philo *philo)
{
	ac = 0;
	philo->n_philo = atoi(av[1]);
	philo->todie = atoi(av[2]);
	philo->toeat = atoi(av[3]);
	philo->tosleep = atoi(av[4]);
	if(av[5])
		philo->n_musteat = atoi(av[5]);
	return 0;
}

int	main(int ac, char **av)
{
	av[ac] = 0;
	t_philo	philo;
	ft_init(&philo);
	ft_parser_checker(ac, av, &philo);
	return 0;
}
