/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:40:45 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/14 20:44:01 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	is_duplicate(char **buffer, char *arg)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(buffer[i], arg, ft_strlen(arg)) == 0)
			return (1);
		i++;
	}
	return (0);
}
