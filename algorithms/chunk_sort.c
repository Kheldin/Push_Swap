/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:24:29 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 11:36:40 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	ft_sqrt(int numbers)
{
	int	n;

	n = 1;
	while (n * n < numbers)
		n++;
	return (n);
}

void	push_chunk(t_list **stack_a, t_list **stack_b, int max, int minimum,
		t_bench *op_total)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < size)
	{
		if ((*stack_a)->index < max && (*stack_a)->index >= minimum)
			push(stack_a, stack_b, 'b', op_total);
		else
			rotate(stack_a, 'a', op_total, 0);
		i++;
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b,
		t_bench *op_total)
{
	int	stack_a_size;
	int	chunks;
	int	size;
	int	i_chunks;

	stack_a_size = ft_lstsize(*stack_a);
	chunks = ft_sqrt(stack_a_size);
	i_chunks = chunks + 1;
	while (i_chunks > 0)
	{
		push_chunk(stack_a, stack_b, stack_a_size, stack_a_size - chunks + 1, op_total);
		i_chunks--;
		stack_a_size--;
	}
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		push(stack_a, stack_b, 'b', op_total);
		size--;
	}
	selection_sort_chunk(stack_a, stack_b);
}
