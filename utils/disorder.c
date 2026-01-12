/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:41 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/12 21:45:52 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	get_disorder(t_list **stack_a)
{
	t_list	*current;
	t_list	*current_bis;
	float	mistakes;
	float	total_pair;

	current = *stack_a;
	mistakes = 0;
	total_pair = 0;
	while (current->next)
	{
		current_bis = current->next;
		while (current_bis)
		{
			total_pair++;
			if (current->content > current_bis->content)
				mistakes++;
			current_bis = current_bis->next;
		}
		current = current->next;
	}
	if (mistakes == 0)
		return (-1);
	if (total_pair == 0)
		return (0);
	return ((mistakes / total_pair) * 10000);
}
