/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:58:14 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/02 16:58:15 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	clear_state(t_data *state)
{
	int	i;

	if (state->forks_m)
	{
		i = 0;
		while (i < state->n_philo)
			pthread_mutex_destroy(&state->forks_m[i++]);
		free(state->forks_m);
	}
	if (state->philos)
	{
		i = 0;
		while (i < state->n_philo)
		{
			pthread_mutex_destroy(&state->philos[i].mtx);
			pthread_mutex_destroy(&state->philos[i++].eat_m);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->can_print);
	pthread_mutex_destroy(&state->someone_died);
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
