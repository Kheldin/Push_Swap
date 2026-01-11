/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:10:50 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 22:22:43 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_flags *init_flags_struct(void)
{
    t_flags *flags;

    flags = ft_calloc(1, sizeof(t_flags));
    if (!flags)
        return (NULL);
    flags->simple = ft_substr("--simple", 8);
	flags->medium = ft_substr("--medium", 8);
	flags->complex = ft_substr("--complex", 9);
    flags->flag_int = -1;
    return (flags);
}