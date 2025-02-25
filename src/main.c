/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:45 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/25 13:04:54 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(int *numbers, int size)
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

static int	count_words(char const *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	**split_args(char const *str)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != ' ')
				i++;
			result[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (!result[j])
				return (NULL);
			ft_strlcpy(result[j++], &str[start], i - start + 1);
		}
	}
	result[j] = NULL;
	return (result);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**args;
	int		i;
	int		count;
	long	num;
	int		min;

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
	stack = create_stack(count);
	if (!stack)
		error_exit();
	i = count - 1;
	min = INT_MAX;
	while (i >= 0)
	{
		num = ft_atoi(args[i]);
		if (num > 2147483647 || num < -2147483648)
			error_exit();
		if (num < min)
			min = num;
		push(stack, (int)num);
		i--;
	}
	// Tüm sayıları pozitif yap
	if (min < 0)
	{
		i = 0;
		while (i <= stack->top)
		{
			stack->numbers[i] -= min;
			i++;
		}
	}
	if (argc == 2)
		free_split(args);
	if (check_duplicates(stack->numbers, stack->size))
		error_exit();
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	b = create_stack(a->size);
	if (!b)
		error_exit();
	if (!is_sorted(a))
		sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
