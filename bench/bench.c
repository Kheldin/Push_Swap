/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:36:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 13:22:52 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "../includes/bench.h"

t_bench *init_bench_struct(void)
{
    t_bench *op_total;

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

// void    print_bench()
// {
    
// }
