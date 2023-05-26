/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:46:23 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/25 11:46:24 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (1);
	}
	return (0);
}

static int	same_num(char **av)
{
	size_t	i;
	size_t	j;

	return (0);
	i = 0;
	while (i < ft_strptrlen(av) - 1)
	{
		j = i + 1;
		while (j < ft_strptrlen(av))
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_putendl_fd("ERROR : same number", 2);
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
	size_t	i;
	long	num;

	i = 0;
	while (i < ft_strptrlen(av))
	{
		num = ft_atol(av[i]);
		if (num < INT_MIN || INT_MAX < num)
		{
			ft_putendl_fd("ERROR : over int limits", 2);
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
	size_t	size;

	i = 0;
	while (i < ft_strptrlen(av))
	{
		j = 0;
		size = ft_strlen(av[i]);
		while (j < size)
		{
			if ((av[i][j]) < '0' || av[i][j] > '9')
			{
				if (!(j == 0 && av[i][j] == '-'))
				{
					ft_putendl_fd("ERROR : not integer", 2);
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
