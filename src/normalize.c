/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:50:28 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 20:54:21 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swapped;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

static void	init_arrays(t_stack *stack, int **sorted, int **temp)
{
	int	i;

	*sorted = (int *)malloc(sizeof(int) * (stack->top + 1));
	*temp = (int *)malloc(sizeof(int) * (stack->top + 1));
	if (!(*sorted) || !(*temp))
	{
		free(*sorted);
		free(*temp);
		free_and_exit(stack, NULL, NULL, 0);
	}
	i = 0;
	while (i <= stack->top)
	{
		(*temp)[i] = stack->numbers[i];
		(*sorted)[i] = stack->numbers[i];
		i++;
	}
}

void	normalize_numbers(t_stack *stack)
{
	int	*sorted;
	int	*temp;
	int	i;
	int	j;

	init_arrays(stack, &sorted, &temp);
	bubble_sort(sorted, stack->top + 1);
	i = 0;
	while (i <= stack->top)
	{
		j = 0;
		while (j <= stack->top)
		{
			if (temp[i] == sorted[j])
			{
				stack->numbers[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
	free(temp);
}
