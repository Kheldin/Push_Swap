/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:55:50 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/16 19:20:41 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/bonus.h"
#include "includes/bench.h"
#include "includes/push_swap.h"

void	checker(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if ((*stack_b))
	{
		ft_printf("KO\n");
		return ;
	}
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

static int	make_operation(char *operation, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(operation, "pa", 2) == 0)
		push_checker(stack_a, stack_b, 'a');
	else if (ft_strncmp(operation, "pb", 2) == 0)
		push_checker(stack_a, stack_b, 'b');
	else if (ft_strncmp(operation, "ra", 2) == 0)
		rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rotate_checker(stack_b);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		reverse_rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		reverse_rotate_checker(stack_b);
	else if (ft_strncmp(operation, "sa", 2) == 0)
		swap_checker(stack_a);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		swap_checker(stack_b);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		swap_ss_checker(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int	operation_loop(char *operation, t_list **stack_a, t_list **stack_b)
{
	int	check;

	check = 0;
	while (operation)
	{
		check = make_operation(operation, stack_a, stack_b);
		if (check == -1)
		{
			free(operation);
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		free(operation);
		operation = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*operation;
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;
	int		check;

	if (ac == 1)
		return (EXIT_SUCCESS);
	stack_b = NULL;
	flags = init_flags_struct();
	stack_a = input_parser(ac, av, flags);
	if (!stack_a)
	{
		free(flags);
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	operation = get_next_line(0);
	check = operation_loop(operation, &stack_a, &stack_b);
	if (check == -1)
	{
		free(flags);
		ft_lstclear(&stack_a);
		return (EXIT_FAILURE);
	}
	checker(&stack_a, &stack_b);
	free(flags);
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
