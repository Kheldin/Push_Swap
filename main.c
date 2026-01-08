/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogard-antoine <rogard-antoine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/08 15:00:36 by rogard-anto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/includes/libft.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = input_parser(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (EXIT_FAILURE);
	if (!stack_a)
	{
		write(1, "Error\n", 7);
		return (EXIT_FAILURE);
	}
    get_indexs(&stack_a);
	//ft_print_stacks(stack_a, stack_b);
	// reverse_rotate(&stack_a, 'a');
	// push(&stack_a, &stack_b, 'b');
	//insertion_sort(&stack_a, &stack_b);
	//rotate(&stack_a, 'a');
	selection_sort(&stack_a, &stack_b);
	// chunk_sort(&stack_a, &stack_b);
	// ft_print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	return (EXIT_SUCCESS);
}
