/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:07:51 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 14:31:33 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

char	*ft_itoa_float(float disorder)
{
	char	*result;
	int		i;
	int		number;

	result = ft_calloc(7, sizeof(char));
	if (!result)
		return (NULL);
	number = disorder * 10000;
	i = 0;
	while (i < 5)
	{
		ft_printf("Number = %d\n", number);
		if (i == 2)
			result[i] = '.';
		else
		{
			
			result[i] = number % 10 + '0';
			number /= 10;
		}
		i++;
	}
	result[5] = '%';
	result[6] = '\0';
	return (result);
}
