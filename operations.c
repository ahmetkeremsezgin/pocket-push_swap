#include "push_swap.h"

// Stack'in en üstündeki iki elemanı değiştirir
void sa(t_stack *stack_a)
{
    int temp;
    
    if (stack_a->size < 2)
        return;
        
    temp = stack_a->numbers[0];
    stack_a->numbers[0] = stack_a->numbers[1];
    stack_a->numbers[1] = temp;
    write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
    int temp;
    
    if (stack_b->size < 2)
        return;
        
    temp = stack_b->numbers[0];
    stack_b->numbers[0] = stack_b->numbers[1];
    stack_b->numbers[1] = temp;
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    int temp;
    
    if (stack_a->size >= 2)
    {
        temp = stack_a->numbers[0];
        stack_a->numbers[0] = stack_a->numbers[1];
        stack_a->numbers[1] = temp;
    }
    
    if (stack_b->size >= 2)
    {
        temp = stack_b->numbers[0];
        stack_b->numbers[0] = stack_b->numbers[1];
        stack_b->numbers[1] = temp;
    }
    write(1, "ss\n", 3);
}

// Stack b'den stack a'ya en üstteki elemanı taşır
void pa(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    
    if (stack_b->size == 0)
        return;
        
    // Stack a'yı bir sağa kaydır
    for (i = stack_a->size; i > 0; i--)
        stack_a->numbers[i] = stack_a->numbers[i - 1];
        
    // b'nin en üstündeki elemanı a'ya ekle
    stack_a->numbers[0] = stack_b->numbers[0];
    stack_a->size++;
    
    // b'yi bir sola kaydır
    for (i = 0; i < stack_b->size - 1; i++)
        stack_b->numbers[i] = stack_b->numbers[i + 1];
    stack_b->size--;
    
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    
    if (stack_a->size == 0)
        return;
        
    // Stack b'yi bir sağa kaydır
    for (i = stack_b->size; i > 0; i--)
        stack_b->numbers[i] = stack_b->numbers[i - 1];
        
    // a'nın en üstündeki elemanı b'ye ekle
    stack_b->numbers[0] = stack_a->numbers[0];
    stack_b->size++;
    
    // a'yı bir sola kaydır
    for (i = 0; i < stack_a->size - 1; i++)
        stack_a->numbers[i] = stack_a->numbers[i + 1];
    stack_a->size--;
    
    write(1, "pb\n", 3);
}

// Stack'i yukarı kaydırır (ilk eleman sona gider)
void ra(t_stack *stack_a)
{
    int temp;
    int i;
    
    if (stack_a->size < 2)
        return;
        
    temp = stack_a->numbers[0];
    for (i = 0; i < stack_a->size - 1; i++)
        stack_a->numbers[i] = stack_a->numbers[i + 1];
    stack_a->numbers[stack_a->size - 1] = temp;
    
    write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{
    int temp;
    int i;
    
    if (stack_b->size < 2)
        return;
        
    temp = stack_b->numbers[0];
    for (i = 0; i < stack_b->size - 1; i++)
        stack_b->numbers[i] = stack_b->numbers[i + 1];
    stack_b->numbers[stack_b->size - 1] = temp;
    
    write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}

// Stack'i aşağı kaydırır (son eleman başa gelir)
void rra(t_stack *stack_a)
{
    int temp;
    int i;
    
    if (stack_a->size < 2)
        return;
        
    temp = stack_a->numbers[stack_a->size - 1];
    for (i = stack_a->size - 1; i > 0; i--)
        stack_a->numbers[i] = stack_a->numbers[i - 1];
    stack_a->numbers[0] = temp;
    
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
    int temp;
    int i;
    
    if (stack_b->size < 2)
        return;
        
    temp = stack_b->numbers[stack_b->size - 1];
    for (i = stack_b->size - 1; i > 0; i--)
        stack_b->numbers[i] = stack_b->numbers[i - 1];
    stack_b->numbers[0] = temp;
    
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
} 