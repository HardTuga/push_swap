/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:28:24 by pcampos-          #+#    #+#             */
/*   Updated: 2022/02/25 12:17:09 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*look_the_best(t_list **stack_a, t_list **stack_b)
{
	t_list	*c;
	t_list	*sp_c;
	t_list	*b;
	t_list	*sp_b;

	c = *stack_b;
	b = *stack_b;
	sp_b = find_spot(*stack_a, b);
	while (c)
	{
		sp_c = find_spot(*stack_a, c);
		if (steps(stack_a, stack_b, sp_c, c) < steps(stack_a, stack_b, sp_b, b))
		{
			b = c;
			sp_b = sp_c;
		}
		c = c->next;
	}
	return (b);
}

t_list	*find_spot(t_list *stack_a, t_list *stack_b)
{
	t_list	*c_a;
	int		c_b;

	c_a = stack_a;
	c_b = stack_b->content;
	if (c_b > ft_lstlast(stack_a)->content
		&& last_great(&stack_a) == ft_lstlast(stack_a))
		return (c_a);
	if (c_b < smaller(stack_a)->content)
	{
		c_a = smaller(stack_a);
		return (c_a);
	}
	if (c_a->content > c_b && ft_lstlast(stack_a)->content < c_b)
		return (c_a);
	if (c_b > last_great(&stack_a)->content)
	{
		c_a = last_great(&stack_a)->next;
		return (c_a);
	}
	while (!(c_a->content < c_b && c_a->next->content > c_b))
		c_a = c_a->next;
	while (c_a->content < c_b)
		c_a = c_a->next;
	return (c_a);
}

t_list	*last_great(t_list **stack)
{
	t_list	*greatest;
	t_list	*cursor;

	cursor = *stack;
	greatest = cursor;
	while (cursor)
	{
		if (cursor->content > greatest->content)
			greatest = cursor;
		cursor = cursor->next;
	}
	return (greatest);
}

t_list	*smaller(t_list *stack)
{
	t_list	*cursor;
	t_list	*smaller;

	cursor = stack;
	smaller = cursor;
	while (cursor)
	{
		if (cursor->content < smaller->content)
			smaller = cursor;
		cursor = cursor->next;
	}
	return (smaller);
}

int	is_sorted(t_list *stack)
{
	t_list	*cursor;

	cursor = stack;
	while (cursor->next)
	{
		if (cursor->content > cursor->next->content)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
