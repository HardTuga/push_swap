/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:35:28 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/04 11:47:17 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps(t_list **stack_a, t_list **stack_b, t_list *s, t_list *c)
{
	int	cost;

	if (cost_r(*stack_b, c) > cost_rr(c))
	{
		if (cost_r(*stack_a, s) > cost_rr(s))
			cost = cost_rr(c) + cost_rr(s);
		else
			cost = cost_rr(c) + cost_r(*stack_a, s);
	}
	else
	{
		if (cost_r(*stack_a, s) > cost_rr(s))
			cost = cost_r(*stack_b, c) + cost_rr(s);
		else
			cost = cost_r(*stack_b, c) + cost_r(*stack_a, s);
	}
	return (cost);
}
