/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:47:15 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/29 19:05:57 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "./libft/libft.h"

typedef struct s_all			t_all;
typedef struct s_philo_features	t_philo_features;
typedef struct s_philo_features
{
	int					position;
	int					eat_count;
	long long int		last_eat;

	t_philo_features	*next_philo;
	t_philo_features	*prev_philo;
	pthread_mutex_t		fork_mutexs;
	pthread_t			thread;
	t_all				*all_p;
}	t_philo_features;

typedef struct s_all
{
	int					total_philo;
	int					died_time;
	int					eat_time;
	int					sleep_time;
	int					max_eat;
	int					dead;
	int					all_eat;
	int					dead_2;
	long long			init_time;
	int					tmp_i;
	int					argv_controller;

	t_philo_features	*philo;
	pthread_mutex_t		print;
	pthread_mutex_t		dead_control;
	pthread_mutex_t		dead_control2;
	pthread_mutex_t		wait_control;
	pthread_mutex_t		write_control;
	pthread_mutex_t		check;
	pthread_mutex_t		time_control;
	pthread_mutex_t		all_eat_control;
}						t_all;

//	philo_utils.c
int					get_args(char **argv, t_all *all, int argc);
int					error_controller(int argc, char **argv);
t_philo_features	*get_philo_features(t_all *all);
void				get_philo_features1(t_philo_features *philo);
t_philo_features	*create_node(t_philo_features *previous);

//	philo_utils2.c
long long int		get_time(t_all *all);
int					eat_control(t_all *all);
int					max_eat_control(t_all *all);
void				deneme_init_mutex(t_all *all);
int					dead_and_eat_control(t_all *all);
//	philo_write_case.c
void				philo_write_case7(char *a, t_all *all,
						t_philo_features *philo);
void				philo_write_case(char *a, t_all *all,
						t_philo_features *philo);
void				philo_write_case1(char *a, t_all *all,
						t_philo_features *philo);
void				philo_write_case2(char *a, t_all *all,
						t_philo_features *philo);
void				philo_write_case3(char *a, t_all *all,
						t_philo_features *philo);
//		philo_write_case2.c
void				philo_write_case4(char *a, t_all *all,
						t_philo_features *philo);
int					philo_write_utils(t_all *all);
int					philo_write_utils2(t_all *all);
int					philo_write_utils3(t_all *all);
int					philo_write_case_ae(t_all *all);

#endif

// int eat_control(t_all *all)
// {
// 	int i = -1;
// 	int a = 0;
// 	t_philo_features *tmp;

// 	tmp = all->philo;
// 	while (++i < all->total_philo)
// 	{
// 		if(tmp->eat_count >= all->max_eat)
// 		{
// 			a++;
// 			tmp = tmp->next_philo;
// 			if(a == all->total_philo)
// 				return(1);
// 		}
// 	}
// 	return(0);
// }