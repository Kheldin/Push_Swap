/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:24:40 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/07 21:38:47 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	final_push_insertion(t_list **stack_a, t_list **stack_b)
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
	rotate(stack_a, 'a');
}

void	final_push_selection(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size > 0)
	{
		push(stack_a, stack_b, 'a');
		stack_size--;
	}
}
