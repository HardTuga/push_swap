/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:51:00 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/05 15:05:37 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(t_list **stack_a, int size)
{
	int		*array;
	int		i;
	t_list	*cursor;

	array = malloc(size * sizeof(int));
	cursor = *stack_a;
	i = 0;
	while (cursor)
	{
		array[i] = cursor->content;
		i++;
		cursor = cursor->next;
	}
	return (sort_array(array, size));
}

int	*sort_array(int *array, int size)
{
	int	c;
	int	i;
	int	tmp;

	i = 0;
	c = 1;
	while (c != 0)
	{
		c = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				c++;
			}
			i++;
		}
	}
	return (array);
}

void	joint_moves(t_list **stack_a, t_list **stack_b, t_list *b, t_list *spot)
{
	if (*stack_a != spot && *stack_b != b)
	{
		if (cost_r(*stack_b, b) > cost_rr(b))
		{
			if (cost_r(*stack_a, spot) > cost_rr(spot))
				btt2(stack_a, stack_b);
		}
		else
		{
			if (cost_r(*stack_a, spot) < cost_rr(spot))
				ttb2(stack_a, stack_b);
		}
	}
}

int	cost_r(t_list *stack, t_list *spot)
{
	return (ft_lstsize(stack) - ft_lstsize(spot));
}

int	cost_rr(t_list	*spot)
{
	return (ft_lstsize(spot));
}
