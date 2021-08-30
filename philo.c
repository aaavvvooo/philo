#include "./philo.h"

int init (t_philo *philo, t_data *data, int argc, char **argv)
{
    int i = -1;
    int j = -1;

    data->p_number = ft_atoi(argv[1]);
    data->die_time = ft_atoi(argv[2]);
    data->eat_time = ft_atoi(argv[3]);
    data->sleep_time = ft_atoi(argv[4]);
    data->count_of_meals = argc == 6 ? ft_atoi(argv[5]) : -1;
    data->is_dead = 0;
    if(!(data->philosophers = (t_philo *)malloc(sizeof(t_philo) * data->p_number)))
        return (0);
    if (!(data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->p_number)))
        return (0);
    while(++j < data->p_number)
    {
        data->philosophers[j].index = j + 1;
        data->philosophers[j].must_eat = data->count_of_meals;
        data->philosophers[j].left_fork = data->forks[i];
        data->philosophers[j].right_fork = data->forks[i + 1];
        data->philosophers[j].life_time = time_getter();
        data->philosophers[j].last_meal = 0;

    }
    while (++i < data->p_number)
        pthread_mutex_init(&data->forks[i], NULL);
    pthread_mutex_init(&data->notification, NULL);
    return (1);
}

int main (int argc, char ** argv)
{
    t_philo philo;
    t_data data;

    if (!parser(argc, argv))
        return (-1);
    
    if (!init(&philo, &data, argc, argv))
        return (0);
    for (int i = 0; i < data.p_number; ++i)
        printf("%d, %lld, %lld, %lld, %lld\n", data.philosophers[i].index, data.philosophers[i].last_meal, data.philosophers[i].life_time, data.philosophers[i].time_to_die, data.philosophers[i].time_to_eat);
    return (0);

}