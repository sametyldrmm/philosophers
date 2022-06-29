/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:44:52 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/29 18:54:07 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_args(char **argv, t_all *all, int argc)
{
	all->total_philo = ft_atoi(argv[1]);
	all->died_time = ft_atoi(argv[2]);
	all->eat_time = ft_atoi(argv[3]);
	all->sleep_time = ft_atoi(argv[4]);
	all->max_eat = -1;
	if (argc == 6)
		all->max_eat = ft_atoi(argv[5]);
	all->dead = 0;
	all->dead_2 = 0;
	all->all_eat = 0;
	if (all->total_philo == 1)
	{
		printf("%lld %d %s \n", get_time(all), 1, "has fork");
		usleep(all->died_time * 1000);
		printf("%lld %d %s \n", get_time(all), 1, "dead");
		return (1);
	}
	return (0);
}

int	error_controller(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_philo_features	*get_philo_features(t_all *all)
{
	t_philo_features	*tmp;
	t_philo_features	*last;
	int					i;

	i = 0;
	tmp = NULL;
	last = NULL;
	while (i < all->total_philo)
	{
		tmp = create_node(last);
		last = tmp;
		i++;
		last->position = i;
		last->eat_count = 0;
		last->all_p = all;
	}
	return (last->next_philo);
}

void	get_philo_features1(t_philo_features *philo)
{
	philo->eat_count = 0;
	philo->last_eat = get_time(philo->all_p);
}

t_philo_features	*create_node(t_philo_features *previous)
{
	t_philo_features	*node;
	t_philo_features	*tmp;

	node = (t_philo_features *)malloc(sizeof(t_philo_features));
	if (node)
	{
		get_philo_features1(node);
		if (previous)
		{
			node->prev_philo = previous;
			node->next_philo = previous->next_philo;
			previous->next_philo = node;
			tmp = node->next_philo;
			if (tmp->prev_philo)
				tmp->prev_philo = node;
		}
		else
		{
			node->next_philo = node;
			node->prev_philo = node;
		}
	}
	return (node);
}
