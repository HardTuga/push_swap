/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:10:26 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/05 16:17:42 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*cursor;

	cursor = lst;
	while (cursor)
	{
		printf("%d\n", cursor->content);
		cursor = cursor->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		*array;

	stack_a = NULL;
	if (errors(ac, av) || ac < 3)
		return (0);
	create_stack(&stack_a, ac, av);
	array = create_array(&stack_a, ac);
	if (ac <= 6)
		smoll(&stack_a, ac);
	else
		start_sort(&stack_a, array, ac);
	free (stack_a);
	free (array);
	return (0);
}

void	create_stack(t_list **stack, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}
