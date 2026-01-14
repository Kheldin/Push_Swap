/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:33:24 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/14 14:47:05 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	handle_flags(char *arg, t_flags *flags)
{
	ft_printf("flag being tested = %s\n", arg);
	if (ft_strncmp(flags->simple, arg, ft_strlen(arg)) == 0
	&& flags->flag_int == -1)
		flags->flag_int = 1;
	else if (ft_strncmp(arg, flags->medium, ft_strlen(arg)) == 0 
	&& flags->flag_int == -1)
		flags->flag_int = 10;
	else if (ft_strncmp(arg, flags->complex, ft_strlen(arg)) == 0
	&& flags->flag_int == -1)
		flags->flag_int = 100;
	else if (ft_strncmp(arg, flags->bench, ft_strlen(arg)) == 0
			&& flags->bench_int == -1)
		flags->bench_int = 1;
	else
		return (-1);
	return (1);
}

static int	valid_args(char **buffer, t_flags *flags)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		if (!ft_isdigit(buffer[i][0]))
		{
			ret = handle_flags(buffer[i], flags);
			if (ret == -1)
				return (-1);
		}
		else
			while (buffer[i][j])
			{
				if (!ft_isdigit(buffer[i][j]))
					return (-1);
				j++;
			}
		i++;
	}
	return (1);
}


void parser(char **av, char **buffer, int nb_args)
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
			return (ft_free_buffer(buffer));
		i = 0;
		while (splited_arg[i])
			buffer[pos++] = ft_strdup(splited_arg[i++]);
		ft_free_buffer(splited_arg);
	}
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
static int	count_args(int ac, char **av)
{
	int	count;
	int	j;
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
	ft_printf("Count args returned %d\n", nb_args);
	if (nb_args == -1)
		return (NULL);
	buffer = ft_calloc(nb_args + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	parser(av, buffer, nb_args);
	if (valid_args(buffer, flags) == -1)
		return (ft_free_buffer(buffer), NULL);
	stack_a = create_list(buffer);
	ft_free_buffer(buffer);
	return (stack_a);
}
