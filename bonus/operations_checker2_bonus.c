/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:34:20 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/20 15:35:03 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/bench.h"

int	rotate_checker(t_list **node)
{
	t_list	*last;
	t_list	*first;

	if ((*node) == NULL || (*node)->next == NULL)
		return (0);
	first = (*node);
	(*node) = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
	return (0);
}

int	reverse_rotate_checker(t_list **node)
{
	t_list	*last;
	t_list	*first;
	t_list	*penultimate;

	if ((*node) == NULL || (*node)->next == NULL)
		return (0);
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
	return (0);
}

int	rotate_rr_checker(t_list **stack_a, t_list **stack_b)
{
	rotate_checker(stack_a);
	rotate_checker(stack_b);
	return (0);
}

int	reverse_rotate_rrr_checker(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_checker(stack_a);
	reverse_rotate_checker(stack_b);
	return (0);
}
