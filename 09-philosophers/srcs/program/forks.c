/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:51:46 by rpaderi           #+#    #+#             */
/*   Updated: 2021/11/25 18:40:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void
	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	show_msg(philo, FORK_MSG);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	show_msg(philo, FORK_MSG);
}

void
	clean_forks(t_philo *philo)
{
	show_msg(philo, SLEEP_MSG);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	ft_usleep(philo->state->tosleep, philo->state->n_philo);
}
