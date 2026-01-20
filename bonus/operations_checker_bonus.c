/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:19:11 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/20 12:34:35 by kacherch         ###   ########.fr       */
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

void	swap_checker(t_list **first)
{
	int		temp_content;
	t_list	*second;

	if ((*first) == NULL || (*first)->next == NULL)
		return ;
	second = (*first)->next;
	temp_content = (*first)->content;
	(*first)->content = second->content;
	second->content = temp_content;
}

void	swap_ss_checker(t_list **first_a, t_list **first_b)
{
	swap_checker(first_a);
	swap_checker(first_b);
}
