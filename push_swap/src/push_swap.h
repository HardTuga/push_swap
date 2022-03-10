/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:14:25 by pcampos-          #+#    #+#             */
/*   Updated: 2022/03/07 12:18:28 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_chunk
{
	int	min_ch;
	int	max_ch;
	int	i_max;
	int	i_min;
}		t_chunk;

void	create_stack(t_list **stack, int av, char **ac);
void	smoll(t_list **stack_a, int ac);
void	smoll_3(t_list **stack_a);
void	smoll_5(t_list **stack_a);
void	get_a_ready(t_list **stack_a, t_list **stack_b);
int		find_smaller(t_list	*stack_a);
void	swap(t_list **stack, char option);
void	swap2(t_list **stack1, t_list **stack2);
void	change_stack(t_list **stack_a, t_list **stack_b, char option);
void	ttb(t_list **stack, char option);
void	ttb2(t_list **stack1, t_list **stack2);
void	btt(t_list **stack, char option);
void	btt2(t_list **stack1, t_list **stack2);
int		*create_array(t_list **stack_a, int size);
int		*sort_array(int *array, int size);
void	start_sort(t_list	**stack_a, int *array, int ac);
int		num_chunks(int max);
void	chunk_things(t_chunk *chunk, int *array, int len, int op);
int		check_chunk(t_chunk chunk, t_list *stack);
void	push_chunk(t_chunk ch, t_list **stack_a, t_list **stack_b);
void	push_back(t_list **stack_a, t_list **stack_b);
t_list	*look_the_best(t_list **stack_a, t_list **stack_b);
t_list	*find_spot(t_list *stack_a, t_list *stack_b);
t_list	*last_great(t_list **stack);
void	joint_moves(t_list **stack_a,
			t_list **stack_b, t_list *b, t_list *spot);
int		cost_r(t_list *stack, t_list *spot);
int		cost_rr(t_list	*spot);
t_list	*smaller(t_list *stack);
int		is_sorted(t_list *stack);
void	final_adjust(t_list **stack, int ac);
long	ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	get_stack_ready(t_list **stack_a, t_list **stack_b);
int		steps(t_list **stack_a, t_list **stack_b, t_list *s, t_list *c);
int		errors(int ac, char **av);
int		check_doubles(int ac, char **av);
int		check_int(int ac, char **av);
int		check_sorted(int ac, char **av);
int		check_num(int ac, char **av);

#endif
