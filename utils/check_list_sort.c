/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:10:28 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/16 18:14:18 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	check_list_sort(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return -1;
		current = current->next;
	}
	return (1);
}
