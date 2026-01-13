/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 17:41:57 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bench.h"
#include "includes/push_swap.h"
#include "libft/includes/libft.h"

static void	do_algorithms(t_flags *flags, t_list **stack_a, t_list **stack_b,
		t_bench *op_total)
{
	float	disorder;
	int		algo;

	algo = 0;
	disorder = get_disorder(stack_a);
	if (flags->flag_int == -1)
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
	t_bench	*op_total;
	t_flags	*flags;

	flags = init_flags_struct();
	stack_a = input_parser(ac, av, flags, 0);
	if (!stack_a)
	{
		ft_free_flags(flags);
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	stack_b = NULL;
	get_indexs(&stack_a);
	op_total = init_bench_struct();
	do_algorithms(flags, &stack_a, &stack_b, op_total);
	ft_lstclear(&stack_a);
	free(op_total);
	ft_free_flags(flags);
	return (EXIT_SUCCESS);
}
