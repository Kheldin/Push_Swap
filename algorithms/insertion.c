/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:18:58 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/07 17:24:35 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void push_new_max(t_list **stack_a, t_list **stack_b, t_list *temp_max)
{
	int stack_a_size;
	t_list *current_b;
	int pos_max;

	pos_max = 0;
	current_b = *stack_b;
	stack_a_size = ft_lstsize(*stack_a);
	while (current_b->content != temp_max->content)
	{
		current_b = current_b->next;
		pos_max++;
	}
	while (pos_max >= 0)
	{
		rotate(stack_b, 'b');
		pos_max--;
	}
	push(stack_a, stack_b, 'b');
}

void push_new_min(t_list **stack_a, t_list **stack_b, t_list *temp_min)
{
	int stack_a_size;
	t_list *current_b;
	int pos_min;

	current_b = *stack_b;
	pos_min = 0;
	stack_a_size = ft_lstsize(*stack_a); 
	while (current_b->content != temp_min->content)
	{
		current_b = current_b->next;
		pos_min++;
	}
	while (pos_min > 0)
	{
		rotate(stack_b, 'b');
		pos_min--;
	}
	push(stack_a, stack_b, 'b');
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_min;
	t_list *current_b;
	t_list *temp_max;
	int pos_b;
	int pos_b_temp;
	int stack_a_size;
	int stack_a_size_temp;
	
	stack_a_size = ft_lstsize(*stack_a) - 2;
	stack_a_size_temp = stack_a_size;
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	if ((*stack_b)->content < (*stack_b)->next->content)
	{
		temp_max = (*stack_b)->next;
		temp_min = (*stack_b);
	}
	else
	{
		temp_max = (*stack_b);
		temp_min = (*stack_b)->next;
	}
	while (stack_a_size > 0)
	{
		if ((*stack_a)->content >= temp_max->content)
		{
			push_new_max(stack_a, stack_b, temp_max);
			temp_max = *stack_b;
		}
		else if ((*stack_a)->content < temp_min->content)
		{
			push_new_min(stack_a, stack_b, temp_min);
			temp_min = *stack_b;
		}
		else
		{
			pos_b = 0;
			current_b = *stack_b;
			while (current_b->next && !((*stack_a)->content >= current_b->content && (*stack_a)->content <= current_b->next->content))
			{
				pos_b++;
				current_b = current_b->next;
			}
			pos_b_temp = pos_b;
			while (pos_b + 1 > 0)
			{
				rotate(stack_b, 'b');
				pos_b--;
			}
			push(stack_a, stack_b, 'b');
		}
		stack_a_size--;
	}
	while ((*stack_b) != temp_min)
		rotate(stack_b, 'b');
	final_push(stack_a, stack_b);
}


