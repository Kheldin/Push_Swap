/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:10:50 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/12 21:45:16 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_flags	*init_flags_struct(void)
{
	t_flags	*flag;

	flag = ft_calloc(1, sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag->simple = ft_substr("--simple", 8);
	flag->medium = ft_substr("--medium", 8);
	flag->complex = ft_substr("--complex", 9);
	flag->bench = ft_substr("--bench", 7);
	flag->flag_int = -1;
	flag->bench_int = -1;
	return (flag);
}
