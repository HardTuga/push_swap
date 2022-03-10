/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:10:12 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/07 15:00:42 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(int ac, char **av)
{
	if (check_doubles(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_int(ac, av) || check_num(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_sorted(ac, av))
		return (1);
	return (0);
}

int	check_doubles(int ac, char **av)
{
	int	i;
	int	cursor;

	i = 1;
	while (i < ac)
	{
		cursor = i + 1;
		while (cursor < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[cursor]))
				return (1);
			cursor++;
		}
		i++;
	}
	return (0);
}

int	check_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	check_sorted(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac - 1)
	{
		if (ft_atoi(av[i]) >= ft_atoi(av[i + 1]))
			return (0);
		else
			continue ;
	}
	return (1);
}

int	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if ((av[i][0] == '-' && (av[i][1] >= 48 && av[i][1] <= 57))
			|| (av[i][0] == '+' && (av[i][1] >= 48 && av[i][1] <= 57)))
			j = 2;
		while (av[i][j])
		{
			if (av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
