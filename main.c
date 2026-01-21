/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/21 14:24:54 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bench.h"
#include "includes/push_swap.h"
#include "libft/includes/libft.h"

void	push_mins(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	if (ft_lstlast(*stack_a)->index == 0)
		reverse_rotate(stack_a, 'a', op_total, 0);
	else
	{
		while ((*stack_a)->index != 0)
			rotate(stack_a, 'a', op_total, 0);
	}
	push(stack_a, stack_b, 'b', op_total);
	while ((*stack_a)->index != 1)
		rotate(stack_a, 'a', op_total, 0);
	push(stack_a, stack_b, 'b', op_total);
}

void	mini_algo(t_list **stack_a, t_list **stack_b, t_bench *op_total)
{
	t_list	*current;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size == 5)
		push_mins(stack_a, stack_b, op_total);
	last = ft_lstlast(*stack_a);
	current = *stack_a;
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, 'a', op_total, 0);
	rotate(stack_a, 'a', op_total, 0);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, 'a', op_total, 0);
	reverse_rotate(stack_a, 'a', op_total, 0);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, 'a', op_total, 0);
	if (*stack_b)
	{
		push(stack_a, stack_b, 'a', op_total);
		push(stack_a, stack_b, 'a', op_total);
	}
}

static void	do_algorithms(t_flags *flags, t_list **stack_a, t_list **stack_b,
		t_bench *op_total)
{
	float	disorder;
	int		algo;
	int		size;

	algo = 0;
	disorder = get_disorder(stack_a);
	size = ft_lstsize(*stack_a);
	if (size == 3 || size == 5)
		mini_algo(stack_a, stack_b, op_total);
	else if (flags->flag_int == -1 || flags->flag_int == 1000)
		algo = choose_algo(stack_a, stack_b, op_total, disorder);
	else if (flags->flag_int == 1)
		selection_sort(stack_a, stack_b, op_total);
	else if (flags->flag_int == 10)
		chunk_sort(stack_a, stack_b, op_total);
	else if (flags->flag_int == 100)
		radix_sort(stack_a, stack_b, op_total);
	if (flags->bench_int == 1)
		print_bench(op_total, disorder, flags->flag_int, algo);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	op_total;
	t_flags	*flags;

	stack_b = NULL;
	flags = init_flags_struct();
	if (flags == NULL)
		return (EXIT_FAILURE);
	stack_a = input_parser(ac, av, flags);
	if (!stack_a)
	{
		ft_free_no_stack_a(flags, ac);
		return (EXIT_FAILURE);
	}
	if (check_list_sort(&stack_a) == 1)
	{
		ft_free_stack_and_flags(flags, stack_a, stack_b);
		return (EXIT_SUCCESS);
	}
	get_indexs(&stack_a);
	op_total = init_bench_struct();
	do_algorithms(flags, &stack_a, &stack_b, &op_total);
	ft_free_stack_and_flags(flags, stack_a, stack_b);
	return (EXIT_SUCCESS);
}
