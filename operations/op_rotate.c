/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:35:14 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 11:30:29 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/bench.h"

void	rotate(t_list **node, char stack, t_bench *op_total, int is_rr)
{
	t_list	*last;
	t_list	*first;

	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	first = (*node);
	(*node) = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
	if (!is_rr)
	{
		if (stack == 'a')
			write(1, "ra\n", 3);
		if (stack == 'b')
			write(1, "rb\n", 3);
	}
}

void	rotate_rr(t_list **node_a, t_list **node_b, t_bench *op_total)
{
	rotate(node_a, ' ', op_total, 1);
	rotate(node_b, ' ', op_total, 1);
	op_total->rr += 1;
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **node, char stack, t_bench *op_total, int is_rr)
{
	t_list	*last;
	t_list	*first;
	t_list	*penultimate;

	if ((*node) == NULL || (*node)->next == NULL)
		return ;
	penultimate = (*node);
	first = (*node);
	last = (*node);
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = first;
	(*node) = last;
	if (!is_rr)
	{
		if (stack == 'a')
		{
			write(1, "rra\n", 4);
			op_total->rra += 1;
		}
		else
		{
			write(1, "rrb\n", 4);
			op_total->rrb += 1;
		}	
	}
}

void	reverse_rotate_rr(t_list **node_a, t_list **node_b, t_bench *op_total, int is_rr)
{
	reverse_rotate(node_a, ' ', op_total, 1);
	reverse_rotate(node_b, ' ', op_total, 1);
	write(1, "rrr\n", 4);
	op_total->rrr += 1;
}
