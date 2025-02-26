/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:50:13 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 11:10:53 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(int count, char **args, int argc)
{
	t_stack	*stack;

	stack = create_stack(count);
	if (!stack)
	{
		if (argc == 2)
			free_and_exit(NULL, NULL, args, 1);
		error_exit();
	}
	return (stack);
}

static void	process_numbers(t_stack *stack, char **args, int count, int argc)
{
	int		i;
	long	num;

	i = count - 1;
	while (i >= 0)
	{
		num = ft_atoi(args[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			if (argc == 2)
				free_and_exit(stack, NULL, args, 1);
			free_and_exit(stack, NULL, NULL, 0);
		}
		push(stack, (int)num);
		i--;
	}
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**args;
	int		count;

	if (argc == 2)
	{
		args = split_args(argv[1]);
		if (!args)
			error_exit();
		count = count_words(argv[1]);
	}
	else
	{
		args = argv + 1;
		count = argc - 1;
	}
	stack = init_stack(count, args, argc);
	process_numbers(stack, args, count, argc);
	normalize_numbers(stack);
	if (argc == 2)
		free_split(args);
	if (check_duplicates(stack->numbers, stack->size))
		free_and_exit(stack, NULL, NULL, 0);
	return (stack);
}

int	count_words(char const *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (count);
}
