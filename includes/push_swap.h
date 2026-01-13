/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:08:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 17:41:24 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "bench.h"

typedef struct s_flags
{
	char	*simple;
	char	*medium;
	char	*complex;
	char	*bench;
	int		flag_int;
	int		bench_int;
}			t_flags;

// parser

void		ft_free_buffer(char **buffer);
t_list		*input_parser(int argc, char *argv[], t_flags *flags, int bench);

// operation

void		swap(t_list *first, char stack, t_bench *op_total, int is_rr);
void		swap_ss(t_list *first_a, t_list *first_b, t_bench *op_total);
void		rotate(t_list **node, char stack, t_bench *op_total, int is_rr);
void		rotate_rr(t_list **node_a, t_list **node_b, t_bench *op_total);
void		reverse_rotate(t_list **node, char stack, t_bench *op_total,
				int is_rr);
void		reverse_rotate_rr(t_list **node_a, t_list **node_b,
				t_bench *op_total);
void		push(t_list **first_a, t_list **first_b, char stack,
				t_bench *op_total);

// algos

void		selection_sort(t_list **stack_a, t_list **stack_b,
				t_bench *op_total);
void		selection_sort_chunk(t_list **stack_a, t_list **stack_b,
				t_bench *op_total);
void		chunk_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total);
void		radix_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total);

// utils

int			choose_algo(t_list **stack_a, t_list **stack_b, t_bench *op_total,
				float disorder);
float		get_disorder(t_list **stack_a);
t_flags		*init_flags_struct(void);
void		get_indexs(t_list **stack_a);
void		ft_print_stacks(t_list *stack_a, t_list *stack_b);
int			itoa_binary(int n);
void		final_push_selection(t_list **stack_a, t_list **stack_b,
				t_bench *op_total);
char		*ft_itoa_disorder(int n);
void		ft_free_flags(t_flags *flags);

#endif