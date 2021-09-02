/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:58:08 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/02 16:58:09 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void
	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->todie;
	show_msg(philo, EAT_MSG);
	ft_usleep(philo->state->toeat);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->eat_m);
}
