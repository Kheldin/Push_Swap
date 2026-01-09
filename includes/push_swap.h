/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:08:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/10 00:00:05 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "bench.h"

float	get_disorder(int *numbers);

void	ft_free_buffer(char **buffer);

int		valid_arg(char *argv);
char	**one_arg_parser(char **argv);
char	**multiple_arg_parser(int argc, char **argv);
t_list	*create_list(char **buffer);
t_list	*input_parser(int argc, char *argv[]);

void	swap(t_list *first, char stack);
void	swap_ss(t_list *first_a, t_list *first_b);
void	rotate(t_list **node, char stack);
void	rotate_rr(t_list **node_a, t_list **node_b);
void	reverse_rotate(t_list **node, char stack);
void	reverse_rotate_rr(t_list **node_a, t_list **node_b);
void	push(t_list **first_a, t_list **first_b, char stack,
			struct bench_struct *op_total);

void	ft_print_stacks(t_list *stack_a, t_list *stack_b);

void	insertion_sort(t_list **stack_a, t_list **stack_b);
void	selection_sort(t_list **stack_a, t_list **stack_b,
			struct bench_struct *op_total);
void	selection_sort_chunk(t_list **stack_a, t_list **stack_b);

// void	final_push_insertion(t_list **stack_a, t_list **stack_b);
void	final_push_selection(t_list **stack_a, t_list **stack_b,
			struct bench_struct *op_total);

void	chunk_sort(t_list **stack_a, t_list **stack_b,
			struct bench_struct *op_total);
void	get_indexs(t_list **stack_a);
int		itoa_binary(int n);

#endif