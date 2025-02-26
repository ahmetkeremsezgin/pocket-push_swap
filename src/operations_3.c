/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:35:55 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 10:37:26 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->top >= 1)
	{
		temp = a->numbers[a->top];
		i = a->top;
		while (i > 0)
		{
			a->numbers[i] = a->numbers[i - 1];
			i--;
		}
		a->numbers[0] = temp;
	}
	if (b->top >= 1)
	{
		temp = b->numbers[b->top];
		i = b->top;
		while (i-- > 0)
			b->numbers[i] = b->numbers[i - 1];
		b->numbers[0] = temp;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top < 1)
		return ;
	temp = a->numbers[0];
	i = 0;
	while (i < a->top)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[a->top] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top < 1)
		return ;
	temp = b->numbers[0];
	i = 0;
	while (i < b->top)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[b->top] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
