/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/19 14:43:35 by kacherch         ###   ########.fr       */
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
	if (flags->flag_int == -1 || flags->flag_int == 1000)
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

	if (ac == 1)
		return (EXIT_SUCCESS);
	flags = init_flags_struct();
	if (flags == NULL)
		return (EXIT_FAILURE);
	stack_a = input_parser(ac, av, flags);
	if (!stack_a)
	{
		free(flags);
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	if (check_list_sort(&stack_a) == 1)
	{
		free(flags);
		ft_lstclear(&stack_a);
		return (EXIT_SUCCESS);		
	}
	stack_b = NULL;
	get_indexs(&stack_a);
	op_total = init_bench_struct();
	do_algorithms(flags, &stack_a, &stack_b, &op_total);
	ft_lstclear(&stack_a);
	free(flags);
	return (EXIT_SUCCESS);
}
