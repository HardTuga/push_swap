/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opreations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:05:37 by pcampos-          #+#    #+#             */
/*   Updated: 2022/02/18 17:05:57 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btt(t_list **stack, char option)
{
	t_list	*temp;

	temp = (*stack);
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = temp;
	while (temp->next != (*stack))
		temp = temp->next;
	temp->next = NULL;
	if (option == 'a')
		write(1, "rra\n", 4);
	if (option == 'b')
		write(1, "rrb\n", 4);
}

void	btt2(t_list **stack1, t_list **stack2)
{
	btt(stack1, 'c');
	btt(stack2, 'c');
	write(1, "rrr\n", 4);
}
