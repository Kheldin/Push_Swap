/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:34:20 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/20 13:57:37 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/bench.h"

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

void	rotate_rr_checker(t_list **stack_a, t_list **stack_b)
{
	rotate_checker(stack_a);
	rotate_checker(stack_b);
}

void	reverse_rotate_rrr_checker(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_checker(stack_a);
	reverse_rotate_checker(stack_b);
}
