/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:21 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/25 13:11:51 by asezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				*numbers;
	int				size;
	int				top;
}	t_stack;

/* Stack işlemleri */
t_stack	*create_stack(int size);
void	free_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);

/* Sıralama operasyonları */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Yardımcı fonksiyonlar */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	error_exit(void);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);
int		check_duplicates(int *numbers, int size);

#endif 