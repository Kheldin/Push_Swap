/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/16 18:00:52 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../libft/includes/libft.h"

void	swap(t_list *first, char stack, t_bench op_total, int is_rr)
{
	int		temp_content;
	t_list	*second;

	second = first->next;
	if (first == NULL || first->next == NULL)
		return ;
	temp_content = first->content;
	first->content = second->content;
	second->content = temp_content;
	if (!is_rr)
	{
		if (stack == 'a')
		{
			write(1, "sa\n", 3);
			op_total.sa += 1;
		}
		else if (stack == 'b')
		{
			write(1, "sb\n", 3);
			op_total.sb += 1;
		}
	}
}

void	swap_ss(t_list *first_a, t_list *first_b, t_bench op_total)
{
	swap(first_a, ' ', op_total, 1);
	swap(first_b, ' ', op_total, 1);
	write(1, "ss\n", 3);
	op_total.ss += 1;
}
