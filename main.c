/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2025/12/09 18:25:27 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>

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
		ft_printf("%d\n", numbers[i]);
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

int	*init_stack(char *argv[])
{
	int	i;
	int	j;
	int	*numbers;

	i = 1;
	while (argv[i])
		i++;
	numbers = ft_calloc(i, sizeof(int));
	if (!numbers)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (numbers);
}
int	main (int argc, char *argv[])
{
	int		i;
	int		*numbers;
	float	disorder;

	numbers = init_stack(argv);
	if (!numbers)
		return (EXIT_FAILURE);
	i = 1;
	while (argv[i])
		i++;
	if (i == 2)
		disorder = 0;
	else
		disorder = get_disorder(numbers);
	printf("disorder = %f\n", disorder);
	return (EXIT_SUCCESS);
}