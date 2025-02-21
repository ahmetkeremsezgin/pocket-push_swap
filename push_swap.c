/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h> // INT_MIN için gerekli
#include "push_swap.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
} t_stack;

// Fonksiyon prototiplerini başa ekleyelim
void    sa(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    stack_init(t_stack *stack);
void    push(t_stack *stack, int value);
int     get_max_bits(t_stack *stack);
void    radix_sort(t_stack *a, t_stack *b);
char **ft_split(char *str);

// Stack işlemleri için yardımcı fonksiyonlar
void    stack_init(t_stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

void    push(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Stack operasyonları
void    sa(t_stack *a)
{
    if (a->size < 2)
        return;
    int temp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = temp;
    write(1, "sa\n", 3);
}

void    pb(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return;
    t_node *temp = a->top;
    a->top = a->top->next;
    temp->next = b->top;
    b->top = temp;
    a->size--;
    b->size++;
    write(1, "pb\n", 3);
}

// Yardımcı fonksiyonlar
int get_max_bits(t_stack *stack)
{
    int max = INT_MIN;
    t_node *current = stack->top;
    
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    
    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits = get_max_bits(a);
    
    for (int i = 0; i < max_bits; i++)
    {
        int items = a->size;
        for (int j = 0; j < items; j++)
        {
            int num = a->top->value;
            if ((num >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (b->size > 0)
            pa(a, b);
    }
}

// Stack operasyonları (eksik olanları ekleyelim)
void ra(t_stack *a)
{
    if (a->size < 2)
        return;
    t_node *first = a->top;
    t_node *last = a->top;
    
    while (last->next)
        last = last->next;
    
    a->top = first->next;
    first->next = NULL;
    last->next = first;
    
    write(1, "ra\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return;
    t_node *temp = b->top;
    b->top = b->top->next;
    temp->next = a->top;
    a->top = temp;
    b->size--;
    a->size++;
    write(1, "pa\n", 3);
}

// String split fonksiyonu ekleyelim
char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int word_count = 1;
    char **words;

    // Kelime sayısını hesapla
    while (str[i])
    {
        if (str[i] == ' ')
            word_count++;
        i++;
    }

    words = malloc(sizeof(char *) * (word_count + 1));
    if (!words)
        return NULL;

    i = 0;
    while (*str)
    {
        if (*str != ' ')
        {
            j = 0;
            while (str[j] && str[j] != ' ')
                j++;
            words[i] = malloc(j + 1);
            if (!words[i])
                return NULL;
            j = 0;
            while (*str && *str != ' ')
                words[i][j++] = *str++;
            words[i][j] = '\0';
            i++;
        }
        else
            str++;
    }
    words[i] = NULL;
    return words;
}

static void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	fill_stack(t_stack *a, char **numbers)
{
	int	i;
	int	num;

	i = 0;
	while (numbers[i])
		i++;
	while (--i >= 0)
	{
		num = atoi(numbers[i]);
		push(a, num);
	}
	return (1);
}

static int	init_stacks(t_stack *a, t_stack *b)
{
	stack_init(a);
	stack_init(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**numbers;

	if (argc != 2)
		return (0);
	if (!init_stacks(&a, &b))
		return (1);
	numbers = ft_split(argv[1]);
	if (!numbers)
		return (1);
	if (!fill_stack(&a, numbers))
	{
		free_split(numbers);
		return (1);
	}
	free_split(numbers);
	radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
