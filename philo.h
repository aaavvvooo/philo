#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct  s_philo
{
	int index;

	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	pthread_t pilisopa;

	long long time_to_eat;
	long long time_to_die;
	long long last_meal;
	long long life_time;
	int must_eat;


}  t_philo;

typedef struct s_data
{
	int is_dead;
	int p_number;
	int eat_time;
	int die_time;
	int sleep_time;
	int count_of_meals;
	
	pthread_mutex_t *forks;
	pthread_mutex_t notification;
	t_philo *philosophers;

}   t_data;

int init(t_philo *philo, t_data *data, int argc, char **argv);
long long time_getter();
long ft_atoi(const char *str);
int parser(int argc, char **argv);

#endif