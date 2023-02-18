/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:16:25 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/02/18 01:08:51 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	long long		init_time;
	int				death;
}					t_philo_info;
typedef struct s_philo
{
	pthread_mutex_t	checker;
	t_philo_info	*philo_info;
	int				id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_t		*threads;
	long long		last_meal;
	int				nb_time_eat;
}					t_philos;

int					ft_atoi(const char *str);
long long			gettime(void);
long long			gettimeofnow(t_philos *philos);
void				u_sleeping(t_philos *philos, long long time_to_sleep);
void				printstatus(t_philos *philos, char *s);
pthread_mutex_t		*creatforks(t_philo_info *philo_info);
t_philos			*creatphilos(t_philo_info *philo_info,
						pthread_mutex_t *forks);
void				thinking(t_philos *philos);
void				sleeping(t_philos *philos);
void				eating(t_philos *philos);
void				*threadstatus(void *arg);
void				creatthreads(t_philos *philos, t_philo_info *philo_info);
int					mallocfail(void);
#endif
