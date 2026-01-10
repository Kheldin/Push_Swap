/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_for_chunk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:57:13 by rogard-anto       #+#    #+#             */
/*   Updated: 2026/01/10 11:35:55 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

static void	rotate_direction_chunk(t_list **stack_b, int stack_size,
		int pos_temp, t_bench *op_total)
{
	int	diff;

	diff = stack_size - pos_temp;
	if (pos_temp <= stack_size / 2)
	{
		while (pos_temp--)
			rotate(stack_b, 'b', op_total, 0);
	}
	else
	{
		while (diff > 0)
		{
			reverse_rotate(stack_b, 'b', op_total, 0);
			diff--;
		}
	}
}

static int	find_pos_chunk(t_list **stack_a)
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
		if ((current)->content > temp->content)
		{
			temp = current;
			pos_temp = position;
		}
		current = current->next;
		position++;
	}
	return (pos_temp);
}

void	selection_sort_chunk(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	int	stack_size;
	int	pos_temp;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size > 0)
	{
		stack_size = ft_lstsize(*stack_b);
		pos_temp = find_pos_chunk(stack_b);
		rotate_direction_chunk(stack_b, stack_size, pos_temp, op_total);
		push(stack_a, stack_b, 'a', op_total);
		stack_size--;
	}
}
