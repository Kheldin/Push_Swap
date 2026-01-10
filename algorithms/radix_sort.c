/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:11:48 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 22:24:11 by kacherch         ###   ########.fr       */
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
		current->index >>= 1;
		current = current->next;
	}
}

int	find_max(t_list **stack_a)
{
	int		max;
	int		value;
	t_list	*current;

	current = *stack_a;
	max = 0;
	while (current)
	{
		value = itoa_binary(current->index);
		if (value > max)
		{
			ft_printf("New Max index is %d\n", current->index);
			max = value;
		}
		current = current->next;
	}
	return (max);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	int	max;
    int  count;
	int		stack_size;
	t_list	*current;

	
	current = *stack_a;
    count = 0;
	max = find_max(stack_a);
	ft_printf(" === MAX = %d\n", max);
	current = *stack_a;
	while (count < max)
	{
		stack_size = ft_lstsize(*stack_a);
		while (current && stack_size)
		{
			if ((current->index & 1) == 0) 
			{
				push(stack_a, stack_b, 'b', op_total);
			} 
			else
				rotate(stack_a, 'a', op_total, 0);
			current = *stack_a;
			stack_size--; // Peut etre mettre ca dans le if au dessus ? 
		}
		push_back(stack_a, stack_b, op_total);
		shift(stack_a);
		count++;
	}
}