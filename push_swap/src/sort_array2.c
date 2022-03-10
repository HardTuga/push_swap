/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:29:48 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/02 16:36:38 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*spot;

	b = look_the_best(stack_a, stack_b);
	spot = find_spot(*stack_a, b);
	while (*stack_b != b || *stack_a != spot)
	{
		joint_moves(stack_a, stack_b, spot, b);
		while (b != *stack_b)
		{
			if (cost_r(*stack_b, b) > cost_rr(b))
				while (*stack_b != b)
					btt(stack_b, 'b');
			else
				while (*stack_b != b)
					ttb(stack_b, 'b');
		}
		if (cost_r(*stack_a, spot) > cost_rr(spot))
			while (*stack_a != spot)
				btt(stack_a, 'a');
		else
			while (*stack_a != spot)
				ttb(stack_a, 'a');
	}
	change_stack(stack_a, stack_b, 'a');
}

void	final_adjust(t_list **stack, int ac)
{
	if (ft_lstsize(last_great(stack)) > ac / 2)
		while (!(is_sorted(*stack)))
			ttb(stack, 'a');
	else
		while (!(is_sorted(*stack)))
			btt(stack, 'a');
}
