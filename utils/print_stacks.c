/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:26:59 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/07 21:27:20 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%d ", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if (stack_b)
		{
			ft_printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("_ _\na b\n\n");
}
