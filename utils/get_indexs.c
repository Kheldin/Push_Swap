/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:24:13 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/09 13:37:38 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	get_indexs(t_list **stack_a)
{
	t_list	*current;
	t_list	*min_node;
	int		i;
	int		size;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		current = *stack_a;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1)
			{
				if (min_node == NULL || current->content < min_node->content)
					min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = i;
		i++;
	}
}
