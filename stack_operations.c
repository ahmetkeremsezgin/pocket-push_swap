/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->next = b->top;
	b->top = temp;
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	b->size--;
	a->size++;
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
} 