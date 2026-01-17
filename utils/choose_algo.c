/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:15:13 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/17 13:03:09 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	choose_algo(t_list **stack_a, t_list **stack_b, t_bench *op_total,
		float disorder)
{
	disorder /= 10000;
	if (disorder < 0.2)
	{
		selection_sort(stack_a, stack_b, op_total);
		return (1);
	}
	else if (disorder < 0.5)
	{
		chunk_sort(stack_a, stack_b, op_total);
		return (2);
	}
	else
	{
		radix_sort(stack_a, stack_b, op_total);
		return (3);
	}
	return (0);
}
