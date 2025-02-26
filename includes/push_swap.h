/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asezgin <asezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:04:21 by asezgin           #+#    #+#             */
/*   Updated: 2025/02/26 11:09:01 by asezgin          ###   ########.fr       */
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
int		push(t_stack *stack, int value);

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
long	ft_atoi(const char *str);
void	clean_exit(t_stack *a, t_stack *b);
void	free_and_exit(t_stack *a, t_stack *b, char **args, int free_args);
char	*ft_substr(char const *s, int start, int len);
/* Parse işlemleri */
char	**split_args(char const *str);
void	free_split(char **split);
t_stack	*parse_args(int argc, char **argv);
int		count_words(char const *str);
int		check_duplicates(int *numbers, int size);
void	normalize_numbers(t_stack *stack);
#endif 