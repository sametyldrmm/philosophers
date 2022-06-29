/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:41:36 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/29 18:41:37 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(t_all *all)
{
	static long		first_time = 0;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (first_time == 0)
		first_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - first_time);
}

int	eat_control(t_all *all)
{
	int					i ;
	int					a ;
	t_philo_features	*tmp;

	tmp = all->philo;
	i = -1;
	a = 0;
	while (++i < all->total_philo)
	{
		if (tmp->eat_count >= all->max_eat)
		{
			a++;
			tmp = tmp->next_philo;
			if (a == all->total_philo)
				return (1);
		}
	}
	return (0);
}

int	max_eat_control(t_all *all)
{
	int					i;
	int					a;
	t_philo_features	*tmp;

	a = 0;
	i = -1;
	tmp = all->philo;
	while (++i <= tmp->position)
	{
		if (tmp->eat_count >= all->max_eat)
			a++;
		if (a == all->total_philo)
			return (1);
		tmp = tmp->next_philo;
	}
	return (0);
}

void	deneme_init_mutex(t_all *all)
{
	while (all->philo->position != all->total_philo)
	{
		pthread_mutex_init(&all->philo->fork_mutexs, NULL);
		all->philo = all->philo->next_philo;
	}
	pthread_mutex_init(&all->philo->fork_mutexs, NULL);
	all->philo = all->philo->next_philo;
	pthread_mutex_init(&all->check, NULL);
	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->dead_control, NULL);
	pthread_mutex_init(&all->dead_control2, NULL);
	pthread_mutex_init(&all->wait_control, NULL);
	pthread_mutex_init(&all->time_control, NULL);
	pthread_mutex_init(&all->all_eat_control, NULL);
}

int	dead_and_eat_control(t_all *all)
{
	if (1)
	{
		pthread_mutex_lock(&all->dead_control);
		pthread_mutex_lock(&all->time_control);
		if (get_time(all) - all->philo->last_eat > all->died_time)
		{
			philo_write_case7("dead", all, all->philo);
			pthread_mutex_lock(&all->dead_control2);
			all->dead = 1;
			pthread_mutex_unlock(&all->dead_control2);
			pthread_mutex_unlock(&all->time_control);
			pthread_mutex_unlock(&all->dead_control);
			return (0);
		}
		pthread_mutex_unlock(&all->time_control);
		pthread_mutex_unlock(&all->dead_control);
	}
	return (1);
}
