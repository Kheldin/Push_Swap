/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/04 15:17:51 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>

void	swap(t_list *first, char stack)
{
	void	*temp_content;
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
	t_list	*second_a;
	t_list	*second_b;

	second_a = first_a->next;
	second_b = first_b->next;
	swap(first_a, ' ');
	swap(first_b, ' ');
	write(1, "ss\n", 3);
}
