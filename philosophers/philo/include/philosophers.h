/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 04:51:56 by sede-los          #+#    #+#             */
/*   Updated: 2024/10/04 04:51:59 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200

struct s_rules;

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				x_ate;
	long long		t_last_meal;
	pthread_t		pthread_id;
	struct s_rules	*rules;
}				t_philo;

typedef struct s_rules
{
	int				nb_philos;
	int				t_to_death;
	int				t_to_eat;
	int				t_to_sleep;
	int				nb_all_eat;
	int				flag_died;
	int				all_eat;
	long long		first_timestamp;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
}				t_rules;

//error_handler
int	write_error(char *str);

//parsing

//initialization
int	init_all(t_rules *rules, char **argv);
int	init_mutex(t_rules *rules);
int	init_philosophers(t_rules *rules);

//utils
int	ft_atoi(char *str);
#endif