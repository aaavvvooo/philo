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
        data->philosophers[j].time_to_eat = data->eat_time;
        data->philosophers[j].time_to_die = data->die_time;

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
        return (-1);
    for (int i = 0; i < data.p_number; ++i)
        printf("index -> %d, ms since last meal -> %lld, life_time -> %lld, time_to_die -> %lld, time_to_eat -> %lld\n", data.philosophers[i].index, data.philosophers[i].last_meal, data.philosophers[i].life_time, data.philosophers[i].time_to_die, data.philosophers[i].time_to_eat);
    if(data.p_number == 1)
    {
        printf("Isn't it lovely all alone,you might think, but one philosopher always dies, because there's only one fork:( ");
        return (-1);
    }
    
    return (0);

}