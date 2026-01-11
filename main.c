/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/10 23:29:47 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bench.h"
#include "includes/push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char *av[])
{
	t_list *stack_a;
	t_list *stack_b;
	t_bench	*op_total;
	t_flags *flags;
	float disorder;

	flags = init_flags_struct();
	stack_a = input_parser(ac, av, flags);
	stack_b = NULL;	
	if (!stack_a)
	{
		write(1, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	disorder = get_disorder(&stack_a);
	if (disorder == -1)
	{
		ft_lstclear(&stack_a);
		return (EXIT_SUCCESS);
	}
	op_total = init_bench_struct();
	// ft_printf("stack_b->content = %d\n", stack_b->content);
	selection_sort(&stack_a, &stack_b, op_total);
	if (flags->flag_int == -1)
		ft_printf("faire adaptive\n");
	else if (flags->flag_int == 1)
		selection_sort(&stack_a, &stack_b, op_total);
	else if (flags->flag_int == 10)
		chunk_sort(&stack_a, &stack_b, op_total);
	else if (flags->flag_int == 100)
		//radix_sort;
	// ft_print_stacks(stack_a, stack_b);
	// ft_printf("%d\n", itoa_binary(11));
	ft_lstclear(&stack_a);
	free(op_total);
	return (EXIT_SUCCESS);
}
