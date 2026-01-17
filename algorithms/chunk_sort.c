/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:24:29 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/17 13:02:11 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

static int	ft_sqrt(int numbers)
{
	int	n;

	n = 1;
	while (n * n < numbers)
		n++;
	return (n);
}

static int	push_chunk(t_list **stack_a, t_list **stack_b, int limit,
		t_bench *op_total)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(*stack_a);
	i = 0;
	j = 0;
	while (i < size)
	{
		if ((*stack_a)->index < limit)
		{
			push(stack_a, stack_b, 'b', op_total);
			j++;
			if (!*stack_a)
				return (-1);
		}
		else
			rotate(stack_a, 'a', op_total, 0);
		i++;
	}
	return (0);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	int	stack_a_size;
	int	chunks;
	int	check;
	int	size;
	int	i;

	stack_a_size = ft_lstsize(*stack_a);
	chunks = ft_sqrt(stack_a_size);
	i = 1;
	while (i <= chunks)
	{
		check = push_chunk(stack_a, stack_b, chunks * i, op_total);
		if (check == -1)
			break ;
		i++;
	}
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		push(stack_a, stack_b, 'b', op_total);
		size--;
	}
	selection_sort_chunk(stack_a, stack_b, op_total);
}
