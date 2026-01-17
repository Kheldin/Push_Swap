/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:55:50 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/17 16:11:31 by kacherch         ###   ########.fr       */
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
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_checker(stack_a, stack_b, 'a');
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_checker(stack_a, stack_b, 'b');
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_checker(stack_b);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_rotate_checker(stack_a);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_rotate_checker(stack_b);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_checker(stack_a);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_checker(stack_b);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
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
			//free(operation);
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
		free(operation);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		return (EXIT_FAILURE);
	}
	checker(&stack_a, &stack_b);
	free(flags);
	free(operation);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (EXIT_SUCCESS);
}
