/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:35:26 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 10:36:56 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->top < 0)
		return ;
	push(a, b->numbers[b->top]);
	b->top--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top < 0)
		return ;
	push(b, a->numbers[a->top]);
	a->top--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top < 1)
		return ;
	temp = a->numbers[a->top];
	i = a->top;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top < 1)
		return ;
	temp = b->numbers[b->top];
	i = b->top;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = temp;
	write(1, "rb\n", 3);
}
