#include "philo.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

static int not_number(char *num)
{
	int i = -1;
	while (num[++i] != 0)
		if(num[i] < '0' || num[i] > '9')
			return (1);
	return (0);
}

long long	time_getter()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int parser(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("%d <-You should have given 4 or 5 arguments, so what the fuck is this?", argc);
		return (0);
	}
	else  
	{
		if (not_number(argv[1]) || not_number(argv[2]) || not_number(argv[3]) || not_number(argv[4]))
		{
			printf ("I am working only with numbers dude");
			return (0);
		}
		if (argv[5] && not_number(argv[5]))
		{
			printf ("I am working only with numbers dude");
			return (0);
		}
	}
	return (1);
}