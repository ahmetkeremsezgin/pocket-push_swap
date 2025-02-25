/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:06 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/25 13:07:10 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = (int *)malloc(sizeof(int) * size);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->numbers)
			free(stack->numbers);
		free(stack);
	}
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	push(t_stack *stack, int value)
{
	if (stack->top >= stack->size - 1)
		return (0);
	stack->top++;
	stack->numbers[stack->top] = value;
	return (1);
}

int	pop(t_stack *stack)
{
	int	value;

	if (is_empty(stack))
		return (0);
	value = stack->numbers[stack->top];
	stack->top--;
	return (value);
}
