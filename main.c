/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/10 13:14:18 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bench.h"
#include "includes/push_swap.h"
#include "libft/includes/libft.h"

int	main(int argc, char *argv[])
{
	t_list				*stack_a;
	t_list				*stack_b;
	t_bench	*op_total;

	stack_a = input_parser(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (EXIT_FAILURE);
	if (!stack_a)
	{
		write(1, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	op_total = NULL;
	init_bench_struct(op_total);
	get_indexs(&stack_a);
	// ft_print_stacks(stack_a, stack_b);
	// reverse_rotate(&stack_a, 'a');
	// push(&stack_a, &stack_b, 'b');
	//insertion_sort(&stack_a, &stack_b);
	// rotate(&stack_a, 'a');
	selection_sort(&stack_a, &stack_b, op_total);
	// ft_printf("pa : %d\n", op_total.pa);
	// chunk_sort(&stack_a, &stack_b);
	// ft_print_stacks(stack_a, stack_b);
	// ft_printf("%d\n", itoa_binary(11));
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
