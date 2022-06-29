/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:23:54 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/29 19:26:29 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait1(long long int wait_time, t_all *all)
{
	size_t	t;

	t = get_time(all);
	while (get_time(all) - t <= wait_time)
	{
		dead_and_eat_control(all);
		usleep(100);
	}
}

void	philo_eat(t_philo_features *philo)
{
	t_all	*all;

	all = philo->all_p;
	pthread_mutex_lock(&philo->fork_mutexs);
	philo_write_case("has forks", all, philo);
	pthread_mutex_lock(&philo->prev_philo->fork_mutexs);
	philo_write_case1("has forks", all, philo);
	pthread_mutex_lock(&all->check);
	philo->eat_count++;
	philo_write_case2("is eat", all, philo);
	pthread_mutex_unlock(&all->check);
	pthread_mutex_lock(&all->time_control);
	philo->last_eat = get_time(all);
	pthread_mutex_unlock(&all->time_control);
	wait1(all->eat_time, all);
	pthread_mutex_unlock(&all->wait_control);
	pthread_mutex_unlock(&philo->fork_mutexs);
	pthread_mutex_unlock(&philo->prev_philo->fork_mutexs);
}

void	*philo_life(void *arg)
{
	t_philo_features	*philo;
	t_all				*all;
	int					c;

	c = 0;
	philo = (t_philo_features *)arg;
	all = (t_all *)philo->all_p;
	if (philo->position % 2 == 0)
		usleep(100);
	while (dead_and_eat_control(all) && !c && all->all_eat != 1)
	{
		philo_eat(philo);
		philo_write_case3("sleep", all, philo);
		wait1(all->sleep_time, all);
		philo_write_case4("think", all, philo);
		pthread_mutex_lock(&all->dead_control2);
		c = all->dead;
		pthread_mutex_unlock(&all->dead_control2);
	}
	usleep(1000);
	return (NULL);
}

t_all	first_main(int argc, char **argv)
{
	t_all	all;

	if (error_controller(argc, argv))
	{
		printf("hataa");
		all.argv_controller = 1;
		return (all);
	}
	if (get_args(argv, &all, argc))
		all.argv_controller = 1;
	all.tmp_i = -1;
	all.philo = get_philo_features(&all);
	deneme_init_mutex(&all);
	get_time(&all);
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	all = first_main(argc, argv);
	if (all.argv_controller)
		return (0);
	while (++all.tmp_i < all.total_philo)
	{
		if (pthread_create(&all.philo->thread
				, NULL, philo_life, (void *)all.philo))
		{
			printf("\nERROR\n");
			return (0);
		}
		usleep(12);
		all.philo = all.philo->next_philo;
	}
	all.tmp_i = -1;
	while (++all.tmp_i < all.total_philo)
	{
		pthread_join(all.philo->thread, NULL);
		pthread_mutex_destroy(&all.philo->fork_mutexs);
		free(all.philo->prev_philo);
		all.philo = all.philo->next_philo;
	}
}
