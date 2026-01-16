/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:40:45 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/16 10:36:32 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	is_duplicate(char **buffer, char *arg)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(buffer[i], arg,
				ft_strlen(arg) + ft_strlen(buffer[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}
