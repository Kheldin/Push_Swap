/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogard-antoine <rogard-antoine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:33:24 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 00:33:55 by rogard-anto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	valid_arg(char *av, t_flags *flags)
{
	int	i;
	int	temp;

	temp = flags->flag_int;
	i = 0;
	if (ft_strncmp(flags->bench, av, ft_strlen(av)) == 0)
	{
		flags->bench_int = 1;
		return (1);
	}
	if (ft_strncmp(flags->simple, av, ft_strlen(av)) == 0)
		flags->flag_int += 2;
	else if (ft_strncmp(av, flags->medium, ft_strlen(av)) == 0)
		flags->flag_int += 11;
	else if (ft_strncmp(av, flags->complex, ft_strlen(av)) == 0)
		flags->flag_int += 101;
	if (flags->flag_int != temp)
		return (1);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**one_arg_parser(char **av, t_flags *flags)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = ft_split(av[1], ' ');
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		if (!valid_arg(buffer[i], flags))
			return (ft_free_buffer(buffer), NULL);
		i++;
	}
	return (buffer);
}

char	**multiple_arg_parser(int ac, char **av, t_flags *flags)
{
	char	**buffer;
	int		i;

	i = 1;
	buffer = ft_calloc(ac + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	while (av[i])
	{
		if (!valid_arg(av[i], flags))
		{
			return (ft_free_buffer(buffer), NULL);
		}
		buffer[i - 1] = ft_strdup(av[i]);
		if (!buffer[i - 1])
			return (ft_free_buffer(buffer), NULL);
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}

t_list	*create_list(char **buffer)
{
	int		i;
	int		number;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	number = 0;
	while (buffer[i])
	{
		if (ft_isdigit(buffer[i][0]) == 1)
		{
			number = ft_atoi(buffer[i]);
			if (!stack_a)
				stack_a = ft_lstnew(number);
			else
				ft_lstadd_back(&stack_a, ft_lstnew(number));
		}
		i++;
	}
	return (stack_a);
}

t_list	*input_parser(int ac, char *av[], t_flags *flags)
{
	t_list	*stack_a;
	char	**buffer;

	(void)flags;
	stack_a = NULL;
	buffer = NULL;
	if (ac == 2)
		buffer = one_arg_parser(av, flags);
	else
		buffer = multiple_arg_parser(ac, av, flags);
	if (!buffer)
		return (NULL);
	stack_a = create_list(buffer);
	ft_free_buffer(buffer);
	return (stack_a);
}
