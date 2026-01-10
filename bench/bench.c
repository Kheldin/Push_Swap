/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:36:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 18:18:41 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

char	*ft_itoa_disorder(int n)
{
	char	*res;
	int		len;
	long	nb;
	int i;
	
	if (n > 2147483647 || n < -214483648)
	{
		ft_putstr_fd("100.00%", 2);
		return (NULL);
	}
	i = 0;
	len = 6;
	if (n == 10000)
		len += 1;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n == 10000)
	{
		res = "100.00%";
		return (res);
	}
	nb = n;
	res[len] = '\0';
	res[--len] = '%';
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		if (i == 2)
			res[--len] = '.';
		else
		{
			res[--len] = (nb % 10) + '0';
			nb /= 10;
		}
		i++;
	}
	return (res);
}

t_bench	*init_bench_struct(void)
{
	t_bench	*op_total;

	op_total = ft_calloc(1, sizeof(t_bench));
	if (!op_total)
		return (NULL);
	op_total->pa = 0;
	op_total->pb = 0;
	op_total->sa = 0;
	op_total->sb = 0;
	op_total->ss = 0;
	op_total->ra = 0;
	op_total->rb = 0;
	op_total->rr = 0;
	op_total->rra = 0;
	op_total->rrb = 0;
	op_total->rrr = 0;
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
}

void	print_bench(t_bench *op_total, float disorder)
{
	int	tot;
	char *str;

	tot = op_total->sa + op_total->sb + op_total->ss + op_total->ra
		+ op_total->rb + op_total->rr + op_total->rra + op_total->rrb
		+ op_total->rrr + op_total->pa + op_total->pb + op_total->ss;
	ft_putstr_fd("[bench] disorder: ", 2);
	str = ft_itoa_disorder((int)disorder);
	ft_putendl_fd(str, 2);
	if (str)
		free(str);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(tot, 2);
	ft_putendl_fd("", 2);
	print_bench_bis(op_total);
}
