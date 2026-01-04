/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/03 20:50:00 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <unistd.h>

void del(void *content)
{
	free(content);
}

void	swap(t_list *first, t_list *second, char stack)
{
	void	*temp_content;

	if (first == NULL || first->next == NULL)
		return ;
	temp_content = first->content;
	first->content = second->content;
	second->content = temp_content;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

void	swap_ss(t_list *first_a, t_list *second_a, t_list *first_b,
		t_list *second_b)
{
	swap(first_a, second_a, ' ');
	swap(first_b, second_b, ' ');
	write(1, "ss\n", 3);
}
