/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:30:47 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/07 17:54:02 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../includes/push_swap.h"
	#include "../libft/includes/libft.h"

void	final_push(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size > 0)
	{
		push(stack_a, stack_b, 'a');
		if (stack_size != 1)
			rotate(stack_a, 'a');
		stack_size--;
	}
}

static void	rotate_direction(t_list **stack_a, int stack_size, int pos_temp)
{
	int	diff;

	diff = stack_size - pos_temp;
	if (pos_temp <= stack_size / 2)
	{
		while (pos_temp--)
			rotate(stack_a, 'a');
	}
	else
	{
		while (diff > 0)
		{
			reverse_rotate(stack_a, 'a');
			diff--;
		}
	}
}

static int	find_pos(t_list **stack_a)
{
	t_list	*current;
	t_list	*temp;
	int		position;
	int		pos_temp;

	position = 0;
	pos_temp = 0;
	current = *stack_a;
	temp = current;
	while (current)
	{
		if ((current)->content < temp->content)
		{
			temp = current;
			pos_temp = position;
		}
		current = current->next;
		position++;
	}
	return (pos_temp);
}

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	int		stack_size;
	int		pos_temp;

	stack_size = ft_lstsize(*stack_a);
	while (stack_size > 0)
	{
		pos_temp = find_pos(stack_a);
		if (pos_temp != 0)
		{
			rotate_direction(stack_a, stack_size, pos_temp);
			push(stack_a, stack_b, 'b');
		}
		stack_size--;
	}
	final_push(stack_a, stack_b);
}
