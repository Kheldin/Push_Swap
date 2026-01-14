/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 12:33:24 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/14 12:02:48 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	valid_arg(char *av, t_flags *flags)
{
	int	i;

	i = 0;
	if (ft_strncmp(flags->simple, av, 9) == 0)
		flags->flag_int = 1;
	else if (ft_strncmp(av, flags->medium, 9) == 0)
		flags->flag_int = 10;
	else if (ft_strncmp(av, flags->complex, 10) == 0)
		flags->flag_int = 100;
	else if (ft_strncmp(av, flags->bench, 7) == 0)
		flags->bench_int = 1;
	if (flags->flag_int > 0 || flags->bench_int > 0)
		return (1);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void parser(char **av, char **buffer)
{
	int		i;
	int		pos;
	char	**splited_arg;

	i = 0;
	pos = 0;
	splited_arg = ft_split(av[1], ' ');
	if (!splited_arg)
		return ; //  Rien a free ici jcrois
	while (splited_arg[i])
		buffer[pos++] = ft_strdup(splited_arg[i++]);
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
	}
	ft_free_buffer(buffer);
	return (count);
}

t_list	*input_parser(int ac, char **av, t_flags *flags)
{
	t_list	*stack_a;
	char	**buffer;
	int		nb_args;

	
	stack_a = NULL;
	nb_args = count_args(ac, av);
	(void)flags;
	ft_printf("Count args returned %d\n", nb_args);
	if (nb_args == -1)
		return (NULL);
	buffer = ft_calloc(nb_args + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	parser(av, buffer);
	// Ici jappelle valid arg et si ca return -1, free + null
	stack_a = create_list(buffer);
	ft_free_buffer(buffer);
	return (stack_a);
}
