/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:11:48 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 13:10:54 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

// void	radix_sort(t_list **stack_a, t_list **stack_b, t_bench *op_total)
// {
// 	size_t	max;
// 	t_list	*current;

// 	(void)stack_b;
// 	current = *stack_a;
// 	max = (itoa_binary(current->index));
// 	while (current)
// 	{
// 		if (itoa_binary(current->index) > (int)max)
// 			max = itoa_binary(current->index);
// 		current = current->next;
// 	}
// 	current = *stack_a;
// 	ft_printf("Max binary lenght = %d\n", (int)max);
// 	// Push 0 bit to B stack
// 	while (current)
// 	{
// 		if (current->index & 0) 
// 		{
// 			push(stack_a, stack_b, 'b', op_total);
// 			current = current->next;
// 		}
// 		else
// 			rotate(stack_a, 'a');
// 	}
// }