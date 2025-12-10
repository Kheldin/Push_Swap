/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2025/12/10 13:14:41 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	*init_stack(char *argv[])
{
	int	i;
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

	(void)argc;	
	(void)argv;	
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