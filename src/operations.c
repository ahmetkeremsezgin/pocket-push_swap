/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:36:31 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 22:46:52 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top < 1)
		return ;
	temp = a->numbers[a->top];
	a->numbers[a->top] = a->numbers[a->top - 1];
	a->numbers[a->top - 1] = temp;
	write(1, "sa\n", 3);
}

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
