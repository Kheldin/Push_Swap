/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:11:48 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 19:28:33 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

static void  push_back(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
    t_list	*current_b;

	current_b = *stack_b;
	while (current_b)
	{
		push(stack_a, stack_b, 'a', op_total);
		current_b = current_b->next;
	}
}

static void	shift(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		current->index = current->index >> 1;
		current = current->next;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	size_t	max;
    size_t  count;
	int		stack_size;
	t_list	*current;

	
	current = *stack_a;
    count = 0;
	max = (itoa_binary(current->index));
	while (current)
	{
		if (itoa_binary(current->index) > (int)max)
			max = itoa_binary(current->index);
		current = current->next;
	}
	current = *stack_a;
	// Push 0 bit to B stack
	while (count < max)
	{
		stack_size = ft_lstsize(*stack_a);
		while (current && stack_size)
		{
			if (current->index & 0) 
			{
				push(stack_a, stack_b, 'b', op_total);
				current = current->next;
			}
			else
				rotate(stack_a, 'a', op_total, 0);
		}
		push_back(stack_a, stack_b, op_total);
		shift(stack_a);
		count++;
	}
}