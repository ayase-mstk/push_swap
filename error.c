#include "push_swap.h"

int	swaped_num(int ac, char **av)
{
	size_t i;

	i = 1;
	while (i < (size_t)ac - 1)
	{
		if (atoi(av[i]) > atoi(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	same_num(int ac, char **av)
{
	size_t i;

	i = 1;
	while (i < (size_t)ac - 1)
	{
		if (atoi(av[i]) == atoi(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	error(int ac, char **av)
{
	if (swaped_num(ac, av) || same_num(ac, av))
		return (1);
	return (0);
}
