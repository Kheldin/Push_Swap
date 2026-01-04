/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/04 13:43:18 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/includes/libft.h"

int	main (int argc, char *argv[])
{
	t_list **h_stack_a;
	t_list	*stack_a;
	
	stack_a = input_parser(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	h_stack_a = &stack_a;
	if (!stack_a)
	{
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	ft_lstclear(&stack_a, free);
	return (EXIT_SUCCESS);
}