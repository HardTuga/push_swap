/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_2_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:57:30 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/04 15:25:59 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smoll(t_list **stack_a, int ac)
{
	if (ac == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, 'a');
	}
	if (ac == 4)
		smoll_3(stack_a);
	if (ac > 4)
		smoll_5(stack_a);
}

void	smoll_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a < b && b < c)
		return ;
	if (a < b && b > c && a < c)
	{
		swap(stack_a, 'a');
		ttb(stack_a, 'a');
	}
	if (a < b && b > c && a > c)
		btt(stack_a, 'a');
	if (a > b && b > c)
	{
		swap(stack_a, 'a');
		btt(stack_a, 'a');
	}
	if (a > b && b < c && a < c)
		swap(stack_a, 'a');
	if (a > b && b < c && a > c)
		ttb(stack_a, 'a');
}

void	smoll_5(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	get_a_ready(stack_a, &stack_b);
	smoll_3(stack_a);
	while (ft_lstsize(stack_b) > 0)
		change_stack(stack_a, &stack_b, 'a');
	free (stack_b);
}

void	get_a_ready(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		a;
	int		i;

	i = 0;
	tmp = (*stack_a);
	a = find_smaller((*stack_a));
	while (tmp->content != a)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
		while ((*stack_a)->content != a)
			ttb(stack_a, 'a');
	else
	{
		while ((*stack_a)->content != a)
			btt(stack_a, 'a');
	}
	change_stack(stack_a, stack_b, 'b');
	if (ft_lstsize((*stack_a)) > 3)
		get_a_ready(stack_a, stack_b);
}

int	find_smaller(t_list	*stack_a)
{
	t_list	*tmp;
	int		a;

	tmp = stack_a;
	a = stack_a->content;
	while (tmp)
	{
		if (tmp->content < a)
			a = tmp->content;
		tmp = tmp->next;
	}
	return (a);
}
