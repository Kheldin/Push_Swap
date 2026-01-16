/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:33:24 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/16 18:24:39 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <limits.h>

static int	valid_args(char **buffer, t_flags *flags)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		if (!ft_isdigit(buffer[i][0]))
		{
			if (handle_flags(buffer[i], flags) == -1)
				return (-1);
		}
		else
		{
			while (buffer[i][j])
			{
				if (!ft_isdigit(buffer[i][j]))
					return (-1);
				j++;
			}
		}
		i++;
	}
	return (1);
}

static int	parser(char **av, char **buffer, int nb_args)
{
	int		i;
	int		j;
	int		pos;
	char	**splited_arg;

	pos = 0;
	j = 1;
	while (pos < nb_args)
	{
		splited_arg = ft_split(av[j++], ' ');
		if (!splited_arg)
			return (ft_free_buffer(buffer), -1);
		i = 0;
		while (splited_arg[i])
		{
			if (is_duplicate(buffer, splited_arg[i]) == 1)
				return (ft_free_buffer(splited_arg), -1);
			buffer[pos++] = ft_strdup(splited_arg[i++]);
		}
		ft_free_buffer(splited_arg);
	}
	return (0);
}

static t_list	*create_list(char **buffer)
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
			if (number > INT_MAX || number < 0)
				return (ft_lstclear(&stack_a), NULL);
			if (!stack_a)
				stack_a = ft_lstnew(number);
			else
				ft_lstadd_back(&stack_a, ft_lstnew(number));
		}
		i++;
	}
	return (stack_a);
}

static int	count_args(int ac, char **av)
{
	int		count;
	int		j;
	char	**buffer;

	count = 0;
	ac--;
	while (ac)
	{
		j = 0;
		buffer = ft_split(av[ac], ' ');
		if (!buffer)
			return (-1);
		while (buffer[j])
		{
			j++;
			count++;
		}
		ac--;
		ft_free_buffer(buffer);
	}
	return (count);
}

t_list	*input_parser(int ac, char **av, t_flags *flags)
{
	t_list	*stack_a;
	char	**buffer;
	int		nb_args;

	stack_a = NULL;
	nb_args = count_args(ac, av);
	if (nb_args == -1)
		return (NULL);
	buffer = ft_calloc(nb_args + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	if (parser(av, buffer, nb_args) == -1 || valid_args(buffer, flags) == -1)
		return (ft_free_buffer(buffer), NULL);
	stack_a = create_list(buffer);
	if (!stack_a)
		return (ft_lstclear(&stack_a), ft_free_buffer(buffer), NULL);
	ft_free_buffer(buffer);
	return (stack_a);
}
