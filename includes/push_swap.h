/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:08:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/04 15:11:53 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

float get_disorder(int *numbers);

void	ft_free_buffer(char **buffer);

int	valid_arg(char *argv);
char	**one_arg_parser(char **argv);
char	**multiple_arg_parser(int argc, char **argv);
t_list	*create_list(char **buffer);
t_list	*input_parser(int argc, char *argv[]);

void	swap(t_list *first, t_list *second, char stack);
void	swap_ss(t_list *first_a, t_list *second_a, t_list *first_b,
		t_list *second_b);

void rotate(t_list **node, char stack);
void rotate_rr(t_list **node_a, t_list **node_b);
void reverse_rotate(t_list **node, char stack);

void push(t_list **first_a, t_list **first_b, char stack);

#endif