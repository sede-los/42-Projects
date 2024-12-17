/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:04:57 by sede-los          #+#    #+#             */
/*   Updated: 2024/12/17 22:05:00 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 200

struct	s_rules;

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
	int				flag_all_eat;
	long long		first_timestamp;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[PHILO_MAX];
	t_philo			philos[PHILO_MAX];
}				t_rules;

//error_handler
int			write_error(char *str);

//parsing
int			parse_checker(char	**argv);

//initialization
int			init_all(t_rules *rules, char **argv);
int			init_mutex(t_rules *rules);
int			init_philosophers(t_rules *rules);

//launcher
int			launcher(t_rules *rules);
void		*p_thread(void *void_phi);
int			philo_eats(t_philo *phi);
void		death_checker(t_rules *r, t_philo *p);
void		exit_launcher(t_rules *rules, t_philo *philos);

//utils
int			ft_atoi(char *str);
int			check_arg_content(char *arg);
long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		action_print(t_rules *rules, int id, char *str);
void		smart_sleep(long long time, t_rules *rules);

#endif
