/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:55:50 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/20 15:24:03 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/bonus.h"
#include "includes/bench.h"
#include "includes/push_swap.h"

static void	checker(t_list **stack_a, t_list **stack_b)
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
		return (push_checker(stack_a, stack_b, 'a'), 0);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		return (push_checker(stack_a, stack_b, 'b'), 0);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		return (rotate_checker(stack_a), 0);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		return (rotate_checker(stack_b), 0);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		return (reverse_rotate_checker(stack_a), 0);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		return (reverse_rotate_checker(stack_b), 0);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		return (swap_checker(stack_a), 0);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		return (swap_checker(stack_b), 0);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		return (swap_ss_checker(stack_a, stack_b), 0);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		return (reverse_rotate_rrr_checker(stack_a, stack_b), 0);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		return (rotate_rr_checker(stack_a, stack_b), 0);
	return (-1);
}

static int	operation_loop(t_list **stack_a, t_list **stack_b)
{
	int		check;
	char	*operation;

	check = 0;
	operation = get_next_line(0);
	while (operation)
	{
		check = make_operation(operation, stack_a, stack_b);
		free(operation);
		if (check == -1)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		operation = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flags	*flags;
	int		check;

	stack_b = NULL;
	flags = init_flags_struct();
	if (!flags)
		return (EXIT_FAILURE);
	stack_a = input_parser(ac, av, flags);
	if (!stack_a)
	{
		ft_free_no_stack_a(flags);
		return (EXIT_FAILURE);
	}
	check = operation_loop(&stack_a, &stack_b);
	if (check == -1)
	{
		ft_free_stack_and_flags(flags, stack_a, stack_b);
		return (EXIT_FAILURE);
	}
	checker(&stack_a, &stack_b);
	ft_free_stack_and_flags(flags, stack_a, stack_b);
	return (EXIT_SUCCESS);
}
