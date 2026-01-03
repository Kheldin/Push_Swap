/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/03 20:55:53 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include "libft/includes/libft.h"

void	*ft_free_split(char **buffer)
{
	int	i;

	i = 0;
	while(buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

char	**one_arg_parser(char **argv)
{
	int		i;
	int		j;
	char	**buffer;

	i = 0;
	buffer = ft_split(argv[1], ' ');
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (!ft_isdigit(buffer[i][j]))
			{
				ft_free_split(buffer);
				return (NULL);
			}
			j++;
		}
		j = 0;
		while (buffer[i][j])
		{
			if (!ft_isdigit(buffer[i][j]))
			{
				ft_free_split(buffer);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (buffer);
}

char	**multiple_arg_parser()
{
	char	*line;

	line = get_next_line(2);
	ft_printf("%s\n", line);
	line = get_next_line(0);
	ft_printf("%s\n", line);
	return (NULL);
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
		{
			ft_free_split(buffer);
			return (NULL);
		}
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
	buffer = NULL; // a delete
	if (argc == 2)
		buffer = one_arg_parser(argv);
	else
		buffer = multiple_arg_parser();
	if (!buffer)
		return (stack_a);
	stack_a = create_list(buffer);
	return (stack_a);
}

int	main (int argc, char *argv[])
{
	int	i;
	t_list **h_stack_a;
	t_list	*stack_a;

	i = 0;
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
		printf("%d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}

	return (EXIT_SUCCESS);
}