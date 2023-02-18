/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:50:59 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/02/17 21:44:51 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime(void)
{
	struct timeval	t;
	long long		ms;

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000;
	ms += t.tv_usec / 1000;
	return (ms);
}

long long	gettimeofnow(t_philos *philos)
{
	return (gettime() - philos->philo_info->init_time);
}

void	u_sleeping(t_philos *philos, long long time_to_sleep)
{
	long long	time;
	long long	h;

	h = gettimeofnow(philos);
	while (1)
	{
		time = gettimeofnow(philos);
		if (time >= h + time_to_sleep)
			break ;
		usleep(500);
	}
}

void	printstatus(t_philos *philos, char *s)
{
	pthread_mutex_lock(&(philos->msg));
	printf("%lld %d %s", gettimeofnow(philos), philos->id + 1, s);
	pthread_mutex_unlock(&(philos->msg));
}
