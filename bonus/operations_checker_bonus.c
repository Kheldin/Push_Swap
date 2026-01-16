/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:19:11 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/13 15:37:30 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/bench.h"

void	push_checker(t_list **first_a, t_list **first_b, char stack)
{
	t_list	*temp;

	if (stack == 'a')
	{
		if ((*first_b) == NULL)
			return ;
		temp = (*first_b);
		(*first_b) = (*first_b)->next;
		ft_lstadd_front(first_a, temp);
	}
	else if (stack == 'b')
	{
		if ((*first_a) == NULL)
			return ;
		temp = (*first_a);
		(*first_a) = (*first_a)->next;
		ft_lstadd_front(first_b, temp);
	}
}

void	rotate_checker(t_list **node)
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
}

void	reverse_rotate_checker(t_list **node)
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
}
