/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:45 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 13:33:46 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 2)
	{
		if (!argv[1][0])
			error_exit();
		args = split_args(argv[1]);
		if (!args)
			error_exit();
		i = 0;
		while (args[i])
		{
			if (!is_valid_number(args[i]))
			{
				free_split(args);
				error_exit();
			}
			i++;
		}
		free_split(args);
		return ;
	}
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	a = parse_args(argc, argv);
	b = create_stack(a->size);
	if (!b)
		free_and_exit(a, NULL, NULL, 0);
	if (!is_sorted(a))
		sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
