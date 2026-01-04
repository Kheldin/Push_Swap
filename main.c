/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/04 15:13:46 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/includes/libft.h"

void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("Stack A: \n");
	while (stack_a)
	{
		ft_printf("%d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("Stack B: \n");
	while (stack_b)
	{
		ft_printf("%d\n", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
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
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	ft_print_stacks(stack_a, NULL);
	swap(stack_a, stack_a->next, 'a');
	ft_print_stacks(stack_a, NULL);
	ft_lstclear(&stack_a, free);
	return (EXIT_SUCCESS);
}