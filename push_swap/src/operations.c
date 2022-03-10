/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:00:26 by pcampos-          #+#    #+#             */
/*   Updated: 2022/02/18 17:05:25 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char option)
{
	t_list	*temp;

	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (option == 'a')
		write(1, "sa\n", 3);
	if (option == 'b')
		write(1, "sb\n", 3);
}

void	swap2(t_list **stack1, t_list **stack2)
{
	swap(stack1, 'c');
	swap(stack2, 'c');
	write(1, "ss\n", 3);
}

void	change_stack(t_list **stack_a, t_list **stack_b, char option)
{
	t_list	*temp;

	if (option == 'a')
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		temp->next = (*stack_a);
		(*stack_a) = temp;
		write(1, "pa\n", 3);
	}
	if (option == 'b')
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp->next = (*stack_b);
		(*stack_b) = temp;
		write(1, "pb\n", 3);
	}
}

void	ttb(t_list **stack, char option)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack;
	temp2 = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	(*stack) = (*stack)->next;
	temp->next = temp2;
	temp2->next = NULL;
	if (option == 'a')
		write(1, "ra\n", 3);
	if (option == 'b')
		write(1, "rb\n", 3);
}

void	ttb2(t_list **stack1, t_list **stack2)
{
	ttb(stack1, 'c');
	ttb(stack2, 'c');
	write(1, "rr\n", 3);
}
