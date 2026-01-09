/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:41 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/09 13:49:55 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

float	get_disorder(int *numbers)
{
	float	mistakes;
	float	total_pair;
	int		i;
	int		j;

	mistakes = 0;
	total_pair = 0;
	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			total_pair++;
			if (numbers[i] > numbers[i + 1])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pair);
}
