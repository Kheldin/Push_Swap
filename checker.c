/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:55:50 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 17:59:55 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/bonus.h"
#include "includes/bench.h"
#include "includes/push_swap.h"

void	checker(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current->next)
	{
		if (current->content > current->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		current = current->next;
	}
	ft_printf("OK\n");
}

static void	make_operation(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "pa", 2) == 0)
		push_checker(stack_a, stack_b, 'a');
	else if (ft_strncmp(operation, "pb", 2) == 0)
		push_checker(stack_a, stack_b, 'b');
	else if (ft_strncmp(operation, "ra", 2) == 0)
		rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rotate_checker(stack_b);
	else if (ft_strncmp(operation, "rra", 2) == 0)
		reverse_rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rrb", 2) == 0)
		reverse_rotate_checker(stack_b);
}
		
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*operation;
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;

	stack_b = NULL;
	flags = init_flags_struct();
	stack_a = input_parser(ac, av, flags, 1);
	operation = get_next_line(0);
	while (operation)
	{
		make_operation(operation, &stack_a, &stack_b);
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
	checker(&stack_a);
	ft_free_flags(flags);
	ft_lstclear(&stack_a);
	return (0);
}
