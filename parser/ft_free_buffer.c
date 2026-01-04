/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:36:35 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/04 12:36:57 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_buffer(char **buffer)
{
	int	i;

	i = 0;
	while(buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
