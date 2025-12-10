/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:41 by kacherch          #+#    #+#             */
/*   Updated: 2025/12/10 16:31:34 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

float get_disorder(int *numbers)
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
