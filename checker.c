/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:55:50 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 12:53:14 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // PAS OUBLIER DE DELETE

int main(int ac, char **av)
{
    //int	ret;
	int	i;

	i = 0;
    printf("CHECKER nb args %d\n", ac);
	while (av[i])
	{
		printf("arg nb %d = %s\n", i, av[i]);
		i++;
	}
    return (0);
}