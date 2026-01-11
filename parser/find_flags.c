/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:01:15 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/10 22:32:34 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	find_flags(int ac, char **av, t_flags *flags)
{
	char	*simple;
	char	*medium;
	char	*complex;
	char	*all_args;
	int		i;

	(void)ac;
	i = 1;
	simple = ft_substr("--simple", 8);
	medium = ft_substr("--medium", 8);
	complex = ft_substr("--complex", 9);
	all_args = ft_substr("", 1);
	while (i < ac)
	{
	    all_args = ft_strjoin(all_args, av[i]);
	    i++;    
	}
	if (ft_strnstr(all_args, simple, ft_strlen(all_args)))
		flags->flag_int = 1;
	else if (ft_strnstr(all_args, medium, ft_strlen(all_args)))
		flags->flag_int = 10;
	else if (ft_strnstr(all_args, complex, ft_strlen(all_args)))
		flags->flag_int = 100;
}
