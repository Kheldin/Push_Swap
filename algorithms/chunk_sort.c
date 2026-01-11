/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:24:29 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/11 18:11:43 by anrogard         ###   ########.fr       */
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

int	push_chunk(t_list **stack_a, t_list **stack_b, int limit,
		t_bench *op_total)
{
	int	i;
	int j;
	int size;

	// ft_printf("limit == %d\n", limit);
	size = ft_lstsize(*stack_a);
	i = 0;
	j = 0;
	while (i < size)
	{
		// ft_printf("(*stack_a)->index == %d\n", (*stack_a)->index);
		// ft_printf("limit == %d\n", limit);
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
	int check;
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
	// ft_print_stacks(*stack_a, *stack_b);
	selection_sort_chunk(stack_a, stack_b, op_total);	
	// ft_print_stacks(*stack_a, *stack_b);
}
