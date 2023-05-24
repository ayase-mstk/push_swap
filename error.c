#include "push_swap.h"

static int	swaped_num(char **av)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (i < ft_strptrlen(av) - 1)
	{
		if (ft_atoi(av[i]) < ft_atoi(av[i + 1]))
			cnt++;
		i++;
	}
	if (cnt == ft_strptrlen(av) - 1)
	{
		// ft_printf("ERROR : already swapped\n");
		return (1);
	}
	return (0);
}

static int	same_num(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strptrlen(av))
	{
		j = i + 1;
		while (j < ft_strptrlen(av))
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
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

static int	outside_intlimit(char **av)
{
	size_t		i;
	long int	num;

	i = 0;
	while (i < ft_strptrlen(av))
	{
		num = ft_atoi(av[i]);
		if (num < INT_MIN || INT_MAX < num)
		{
			ft_printf("ERROR : over int limits\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	not_integer(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strptrlen(av))
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if ((av[i][j]) < '0' || av[i][j] > '9')
			{
				if (j != 0 && av[i][j] == '-')
				{
					ft_printf("ERROR : The sign is in the wrong place.\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error(char **av)
{
	if (not_integer(av) || outside_intlimit(av) || swaped_num(av) \
		|| same_num(av))
		return (1);
	return (0);
}
