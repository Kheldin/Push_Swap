/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/06 10:37:38 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/includes/libft.h"

void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%d ", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf("  ");
		if (stack_b)
		{
			ft_printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("_ _\na b\n\n");
}

int	main (int argc, char *argv[])
{
	t_list **h_stack_a;
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = input_parser(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (EXIT_FAILURE);
	h_stack_a = &stack_a;
	if (!stack_a)
	{
		write(1, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	//ft_print_stacks(stack_a, stack_b);
	//reverse_rotate(&stack_a, 'a');
	// push(&stack_a, &stack_b, 'b');
	//insertion_sort(&stack_a, &stack_b);
	// rotate(&stack_a, 'a');
	selection_sort(&stack_a, &stack_b);
	//ft_printf("\n");
	//ft_print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	return (EXIT_SUCCESS);
}
