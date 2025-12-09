/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:04:52 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/03 16:50:27 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	metsign;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	metsign = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	while (nptr[i] && (nptr[i] == '+' || nptr[i] == '-') && metsign == 0)
	{
		if (nptr[i] == '-')
			sign = -1;
		metsign = 1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
