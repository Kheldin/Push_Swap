/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:36:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 11:10:10 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "../includes/bench.h"

void init_bench_struct(t_bench *op_total)
{
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
}

// void    print_bench()
// {
    
// }
