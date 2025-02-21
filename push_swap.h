/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* stack_operations.c */
void	sa(t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);

/* stack_utils.c */
void	stack_init(t_stack *stack);
void	push(t_stack *stack, int value);
int		get_max_bits(t_stack *stack);

/* sort.c */
void	radix_sort(t_stack *a, t_stack *b);

/* utils.c */
char	**ft_split(char *str);

#endif
