/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/10 14:27:03 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bench.h"
#include "includes/push_swap.h"
#include "libft/includes/libft.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	float	disorder;
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
	disorder = get_disorder(&stack_a);
	__builtin_printf("disorder === %f\n", disorder);
	__builtin_printf("disorder = %s\n", ft_itoa_float(disorder));
	op_total = init_bench_struct();
	// get_indexs(&stack_a);
	// insertion_sort(&stack_a, &stack_b);
	// rotate(&stack_a, 'a');
	//selection_sort(&stack_a, &stack_b, op_total);
	//print_bench(op_total, disorder);
	// ft_printf("pa : %d\n", op_total->pa);
	// chunk_sort(&stack_a, &stack_b, op_total);
	// ft_print_stacks(stack_a, stack_b);
	// ft_printf("%d\n", itoa_binary(11));
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
