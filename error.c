#include "push_swap.h"

static int	swaped_num(int ac, char **av)
{
	size_t	i;
	size_t	cnt;

	i = 1;
	cnt = 0;
	while (i < (size_t)ac - 1)
	{
		if (atoi(av[i]) < atoi(av[i + 1]))
			cnt++;
		i++;
	}
	if (cnt == (size_t)ac - 2)
	{
		ft_printf("ERROR : already swapped\n");
		return (1);
	}
	return (0);
}

static int	same_num(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac - 1)
	{
		j = i + 1;
		while (j < (size_t)ac - 1)
		{
			if (atoi(av[i]) == atoi(av[j]))
			{
				ft_printf("ERROR : same number\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	outside_intlimit(int ac, char **av)
{
	size_t		i;
	long int	num;

	i = 1;
	while (i < (size_t)ac - 1)
	{
		num = atoi(av[i]);
		printf("num = %ld\n", num);
		if (num < INT_MIN || INT_MAX > num)
		{
			ft_printf("ERROR : over int limits\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	outside_integer(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if ((av[i][j]) < '0' || av[i][j] > '9')
			{
				if (j != 0 && av[i][j] == '-')
				{
					ft_printf("ERROR : not integer\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error(int ac, char **av)
{
	if (outside_integer(ac, av) || outside_intlimit(ac, av) || swaped_num(ac, av) \
		|| same_num(ac, av))
		return (1);
	return (0);
}
