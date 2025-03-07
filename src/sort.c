/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:06:29 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 13:38:48 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->numbers[a->top];
	n2 = a->numbers[a->top - 1];
	n3 = a->numbers[a->top - 2];
	if (n1 > n2 && n2 < n3 && n3 > n1)
		sa(a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n2 < n3 && n3 < n1)
		ra(a);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		rra(a);
}

static int	find_min_position(t_stack *a)
{
	int	min;
	int	min_pos;
	int	i;

	min = a->numbers[a->top];
	min_pos = a->top;
	i = a->top - 1;
	while (i >= 0)
	{
		if (a->numbers[i] < min)
		{
			min = a->numbers[i];
			min_pos = i;
		}
		i--;
	}
	return (min_pos);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	size = a->top + 1;
	if (size <= 3)
	{
		sort_three(a);
		return ;
	}
	while (a->top >= 3)
	{
		min_pos = find_min_position(a);
		while (min_pos != a->top)
		{
			if (min_pos > a->top / 2)
				ra(a);
			else
				rra(a);
			min_pos = find_min_position(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->top >= 0)
		pa(a, b);
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = a->top + 1;
	max_bits = 0;
	i = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->numbers[a->top] >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->top >= 0)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (a->numbers[1] > a->numbers[0])
			sa(a);
	}
	else if (size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}
