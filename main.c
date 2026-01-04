/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/04 11:49:42 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include "libft/includes/libft.h"

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

int	valid_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**one_arg_parser(char **argv)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = ft_split(argv[1], ' ');
	if (!buffer)
		return NULL;
	while (buffer[i])
	{
		if (!valid_arg(buffer[i]))
			return (ft_free_buffer(buffer), NULL);
		i++;
	}
	return (buffer);
}

char	**multiple_arg_parser(int argc, char **argv)
{
	char	**buffer;
	int		i;

	i = 1;
	buffer = ft_calloc(argc + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	while (argv[i])
	{
		if (!valid_arg(argv[i]))
			return (ft_free_buffer(buffer), NULL);
		buffer[i-1] = ft_strdup(argv[i]);
		if (!buffer[i-1])
			return (ft_free_buffer(buffer), NULL);
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}

t_list	*create_list(char **buffer)
{
	int	i;
	int	*number;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (buffer[i])
	{
		number = ft_calloc(1, sizeof(int));
		if (!number)
			return (ft_free_buffer(buffer), NULL); // need to free stack to
		*number = ft_atoi(buffer[i]);
		if (!stack_a)
			stack_a = ft_lstnew(number);
		else
			ft_lstadd_back(&stack_a, ft_lstnew(number));
		i++;
	}
	return stack_a;
}

t_list	*input_parser(int argc, char *argv[])
{
	t_list *stack_a;
	int		i;
	char 	**buffer;

	i = 0;
	stack_a = NULL;
	buffer = NULL;
	if (argc == 2)
		buffer = one_arg_parser(argv);
	else
	{
		buffer = multiple_arg_parser(argc, argv);
	}
	if (!buffer)
		return (NULL);
	stack_a = create_list(buffer);
	return (stack_a);
}

int	main (int argc, char *argv[])
{
	int	i;
	t_list **h_stack_a;
	t_list	*stack_a;

	i = 1;
	while (argv[i])
	{
		ft_printf("Arg nb %d = %s\n", i, argv[i]);
		i++;
	}
	stack_a = input_parser(argc, argv);
	if (!stack_a)
		return (EXIT_FAILURE);
	h_stack_a = &stack_a;
	if (!stack_a)
	{
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	while (stack_a)
	{
		printf("Node = %d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}

	return (EXIT_SUCCESS);
}