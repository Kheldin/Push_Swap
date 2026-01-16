/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:10:50 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/16 18:26:47 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_flags	*init_flags_struct(void)
{
	t_flags	*flag;

	flag = ft_calloc(sizeof(t_flags), 1);
	if (!flag)
		return (NULL);
	flag->flag_int = NO_FLAGS;
	flag->bench_int = NO_BENCH_FLAG;
	return (flag);
}
