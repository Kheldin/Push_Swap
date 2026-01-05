/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/05 21:47:30 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>

void	swap(t_list *first, char stack)
{
	int		temp_content;
	t_list	*second;

	second = first->next;
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

void	swap_ss(t_list *first_a, t_list *first_b)
{
	swap(first_a, ' ');
	swap(first_b, ' ');
	write(1, "ss\n", 3);
}
