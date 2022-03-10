/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:08:09 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/05 10:48:30 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_list	**stack_a, int *array, int ac)
{
	t_list	*stack_b;
	t_chunk	chunk;
	int		len_ch;
	int		max;

	stack_b = NULL;
	max = ft_lstsize(*stack_a);
	len_ch = max / num_chunks(max);
	chunk_things(&chunk, array, len_ch, 1);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (check_chunk(chunk, *stack_a))
			push_chunk(chunk, stack_a, &stack_b);
		else
			chunk_things(&chunk, array, len_ch, 2);
	}
	smoll_3(stack_a);
	while (ft_lstsize(stack_b) > 0)
		push_back(stack_a, &stack_b);
	if (!(is_sorted(*stack_a)))
		final_adjust(stack_a, ac);
}

int	num_chunks(int max)
{
	if (max <= 100)
		return (2);
	else
		return (5);
}

void	chunk_things(t_chunk *chunk, int *array, int len, int op)
{
	if (op == 1)
	{
		chunk->i_min = 0;
		chunk->i_max = len - 1;
	}
	else
	{
		chunk->i_min += len;
		chunk->i_max += len;
	}
	chunk->min_ch = array[chunk->i_min];
	chunk->max_ch = array[chunk->i_max];
}

int	check_chunk(t_chunk chunk, t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content >= chunk.min_ch && tmp->content <= chunk.max_ch)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk(t_chunk ch, t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content >= ch.min_ch && (*stack_a)->content <= ch.max_ch)
		change_stack(stack_a, stack_b, 'b');
	else
	{
		ttb(stack_a, 'a');
	}
}
