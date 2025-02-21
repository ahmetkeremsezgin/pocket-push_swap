/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;
	int	items;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		items = a->size;
		j = 0;
		while (j < items)
		{
			num = a->top->value;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
} 