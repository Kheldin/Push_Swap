/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:36:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/21 14:32:06 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_bench	init_bench_struct(void)
{
	t_bench	op_total;

	op_total.pa = 0;
	op_total.pb = 0;
	op_total.sa = 0;
	op_total.sb = 0;
	op_total.ss = 0;
	op_total.ra = 0;
	op_total.rb = 0;
	op_total.rr = 0;
	op_total.rra = 0;
	op_total.rrb = 0;
	op_total.rrr = 0;
	return (op_total);
}

void	print_bench_bis(t_bench *op_total)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(op_total->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(op_total->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(op_total->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(op_total->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(op_total->pb, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(op_total->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(op_total->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(op_total->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(op_total->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(op_total->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(op_total->rrr, 2);
	ft_putendl_fd("", 2);
}

void	print_strategy(int algo, int flag_int)
{
	if (flag_int == 1)
		ft_putendl_fd("Simple / O(n²)", 2);
	else if (flag_int == 10)
		ft_putendl_fd("Medium / O(n√n)", 2);
	else if (flag_int == 100)
		ft_putendl_fd("Complex / O(n log n)", 2);
	else
	{
		if (algo == 1)
			ft_putendl_fd("Adaptive / O(n²)", 2);
		else if (algo == 2)
			ft_putendl_fd("Adaptive / O(n√n)", 2);
		else
			ft_putendl_fd("Adaptive / O(n log n)", 2);
	}
}

void	print_bench(t_bench *op_total, float disorder, int flag_int, int algo)
{
	int		tot;
	char	*str;

	tot = op_total->sa + op_total->sb + op_total->ss + op_total->ra
		+ op_total->rb + op_total->rr + op_total->rra + op_total->rrb
		+ op_total->rrr + op_total->pa + op_total->pb + op_total->ss;
	ft_putstr_fd("[bench] disorder: ", 2);
	str = ft_itoa_disorder((int)disorder);
	if (str)
	{
		ft_putendl_fd(str, 2);
		free(str);
	}
	ft_putstr_fd("\n[bench] strategy: ", 2);
	print_strategy(algo, flag_int);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(tot, 2);
	ft_putendl_fd("", 2);
	print_bench_bis(op_total);
}
