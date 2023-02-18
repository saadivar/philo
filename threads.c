/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:17:09 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/02/17 21:25:46 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philos *philos)
{
	pthread_mutex_lock(&(philos->msg));
	printf("%lld %d is thinking\n", gettimeofnow(philos), philos->id + 1);
	pthread_mutex_unlock(&(philos->msg));
}

void	sleeping(t_philos *philos)
{
	pthread_mutex_lock(&(philos->msg));
	printf("%lld %d is sleeping\n", gettimeofnow(philos), philos->id + 1);
	pthread_mutex_unlock(&(philos->msg));
	u_sleeping(philos, philos->philo_info->time_to_sleep);
}

void	eating(t_philos *philos)
{
	pthread_mutex_lock(&philos->forks[philos->id]);
	printstatus(philos, "has taken a fork\n");
	if (philos->id + 1 == philos->philo_info->number_of_philosophers)
		pthread_mutex_lock(&philos->forks[0]);
	else
		pthread_mutex_lock(&philos->forks[philos->id + 1]);
	printstatus(philos, "has taken a fork\n");
	pthread_mutex_lock(&(philos->checker));
	philos->last_meal = gettime();
	philos->nb_time_eat++;
	pthread_mutex_unlock(&(philos->checker));
	printstatus(philos, "is eating\n");
	u_sleeping(philos, philos->philo_info->time_to_eat);
	pthread_mutex_unlock(&philos->forks[philos->id]);
	if (philos->id + 1 == philos->philo_info->number_of_philosophers)
		pthread_mutex_unlock(&philos->forks[0]);
	else
		pthread_mutex_unlock(&philos->forks[philos->id + 1]);
}

void	*threadstatus(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
}

void	creatthreads(t_philos *philos, t_philo_info *philo_info)
{
	int	i;

	i = 0;
	while (i < philo_info->number_of_philosophers)
	{
		if (pthread_create(&philos[i].threads[i], NULL, &threadstatus,
				&philos[i]))
		{
			printf("error in thread creation\n");
			return ;
		}
		usleep(50);
		i++;
	}
}
