/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_write_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:41:32 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/29 18:41:34 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_write_case7(char *a, t_all *all, t_philo_features *philo)
{
	int	ad;
	int	as;

	ad = philo_write_utils(all);
	as = get_time(all) - all->philo->last_eat > all->died_time;
	if (as && !ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->dead_control2);
		all->dead = 1;
		ad = 1;
		pthread_mutex_unlock(&all->dead_control2);
		printf("%lld %d %s \n", get_time(all), philo->position, "dead");
		return ;
	}
	return ;
}

void	philo_write_case(char *a, t_all *all, t_philo_features *philo)
{
	int	ad;
	int	as;

	ad = philo_write_utils(all);
	as = philo_write_utils2(all);
	if (as && !ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->dead_control2);
		all->dead = 1;
		ad = 1;
		pthread_mutex_unlock(&all->dead_control2);
		printf("%lld %d %s \n", get_time(all), philo->position, "dead");
		return ;
	}
	if (!ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->print);
		if (dead_and_eat_control(all))
			printf("%lld %d %s \n", get_time(all), philo->position, a);
		pthread_mutex_unlock(&all->print);
	}
	return ;
}

void	philo_write_case1(char *a, t_all *all, t_philo_features *philo)
{
	int	ad;
	int	as;

	ad = philo_write_utils(all);
	as = philo_write_utils2(all);
	if (as && !ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->dead_control2);
		all->dead = 1;
		ad = 1;
		pthread_mutex_unlock(&all->dead_control2);
		printf("%lld %d %s \n", get_time(all), philo->position, "dead");
		return ;
	}
	if (!ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->print);
		if (dead_and_eat_control(all))
		{
			printf("%lld %d %s \n", get_time(all), philo->position, a);
		}
		pthread_mutex_unlock(&all->print);
	}
	return ;
}

void	philo_write_case_2_1_utils(int ad, t_all *all, char *a,
						t_philo_features *philo)
{
	int	ae;

	pthread_mutex_lock(&all->all_eat_control);
	ae = all->all_eat;
	pthread_mutex_unlock(&all->all_eat_control);
	if (!ad && ae != 1)
	{
		pthread_mutex_lock(&all->print);
		if (1)
		{
			printf("%lld %d %s \n", get_time(all), philo->position, a);
			if (max_eat_control(all) && all->max_eat != -1)
			{
				pthread_mutex_lock(&all->all_eat_control);
				all->all_eat = 1;
				pthread_mutex_unlock(&all->all_eat_control);
			}
		}
		pthread_mutex_unlock(&all->print);
	}
}

void	philo_write_case2(char *a, t_all *all, t_philo_features *philo)
{
	int	ad;
	int	as;

	ad = philo_write_utils(all);
	as = philo_write_utils2(all);
	if (as && !ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->dead_control2);
		all->dead = 1;
		pthread_mutex_unlock(&all->dead_control2);
		printf("%lld %d %s \n", get_time(all), philo->position, "dead");
		return ;
	}
	philo_write_case_2_1_utils(ad, all, a, philo);
	return ;
}
