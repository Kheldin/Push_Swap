/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/20 18:11:56 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../libft/includes/libft.h"

void	swap(t_list **head, char stack, t_bench *op_total, int is_ss)
{
	t_list *first;
	t_list	*second;
	t_list	*third;
	
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	head = &second;
	second->next = first;
	first->next = third;
	if (!is_ss)
	{
		if (stack == 'a')
		{
			write(1, "sa\n", 3);
			op_total->sa += 1;
		}
		else if (stack == 'b')
		{
			write(1, "sb\n", 3);
			op_total->sb += 1;
		}
	}
}

void	swap_ss(t_list **head_a, t_list **head_b, t_bench *op_total)
{
	swap(head_a, ' ', op_total, 1);
	swap(head_b, ' ', op_total, 1);
	write(1, "ss\n", 3);
	op_total->ss += 1;
}
