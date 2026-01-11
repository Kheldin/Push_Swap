/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:11:48 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/11 11:10:22 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

static void  push_back(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
    t_list	*current_b;
	int		stack_size;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size -1)
	{
		ft_printf("ROTATING  ");
		rotate(stack_b, 'b', op_total, 0);
		stack_size--;
	}
	current_b = *stack_b;
	while (current_b)
	{
		ft_printf("Push back Current = %d index = %d  ", current_b->content, current_b->index);
		push(stack_a, stack_b, 'a', op_total);
		current_b = *stack_b;
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
			max = value;
		current = current->next;
	}
	return (max);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	int	max;
	int		stack_size;
	t_list	*current;

	
	current = *stack_a;
	max = find_max(stack_a);
	ft_printf("MAX lenght Binary = %d\n\n", max);
	current = *stack_a;
	while (max)
	{
		stack_size = ft_lstsize(*stack_a);
		current = *stack_a;
		while (current && stack_size)
		{
			if ((current->index & 1) == 0) 
			{
				ft_printf("PUSH B Current = %d index = %d  ", current->content, current->index);
				push(stack_a, stack_b, 'b', op_total);
			} 
			else
			{
				ft_printf("ROTATE A Current = %d index = %d  ", current->content, current->index);
				rotate(stack_a, 'a', op_total, 0);
			}
			stack_size--;
			current = *stack_a;
		}
		max--;
		push_back(stack_a, stack_b, op_total);
		shift(stack_a);
		ft_printf("\n=== NEXT ITERATION ===\n");
	}
}