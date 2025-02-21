#include "push_swap.h"

// En büyük sayının kaç bit kullandığını bulur
int get_max_bits(t_stack *stack)
{
    int max = stack->numbers[0];
    int bits = 0;
    
    for (int i = 1; i < stack->size; i++)
        if (stack->numbers[i] > max)
            max = stack->numbers[i];
            
    while (max > 0)
    {
        bits++;
        max >>= 1;
    }
    return bits;
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits = get_max_bits(stack_a);
    
    // Her bit için
    for (int i = 0; i < max_bits; i++)
    {
        int size = stack_a->size;
        
        // Stack a'daki her sayı için
        for (int j = 0; j < size; j++)
        {
            // Eğer i. bit 0 ise b'ye pushla
            if ((stack_a->numbers[0] >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        
        // b'deki tüm sayıları geri a'ya pushla
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
}

// Sayıyı kontrol et
int is_number(char *str)
{
    int i = 0;
    
    if (str[0] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Stack'i başlat
t_stack *init_stack(int size)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
        
    stack->numbers = malloc(sizeof(int) * size);
    if (!stack->numbers)
    {
        free(stack);
        return (NULL);
    }
    
    stack->size = 0;
    return (stack);
}

// Stack'i temizle
void free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->numbers)
            free(stack->numbers);
        free(stack);
    }
}

// String'i bölen ve sayılara çeviren fonksiyon
char **split_numbers(char *str, int *count)
{
    char **numbers;
    char *start;
    int i = 0;
    int num_count = 1;
    
    // Boşluk sayısını say
    while (str[i])
    {
        if (str[i] == ' ')
            num_count++;
        i++;
    }
    
    numbers = malloc(sizeof(char *) * (num_count + 1));
    if (!numbers)
        return NULL;
    
    i = 0;
    start = str;
    num_count = 0;
    while (*str)
    {
        if (*str == ' ')
        {
            *str = '\0';
            if (start != str)
                numbers[num_count++] = start;
            start = str + 1;
        }
        str++;
    }
    if (start != str)
        numbers[num_count++] = start;
    numbers[num_count] = NULL;
    *count = num_count;
    
    return numbers;
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **numbers;
    int count;
    int i;
    
    if (argc < 2)
        return (0);
        
    if (argc == 2)
    {
        numbers = split_numbers(argv[1], &count);
        if (!numbers)
        {
            write(2, "Error\n", 6);
            return (1);
        }
    }
    else
    {
        numbers = argv + 1;
        count = argc - 1;
    }
    
    // Stack'leri başlat
    stack_a = init_stack(count);
    stack_b = init_stack(count);
    if (!stack_a || !stack_b)
    {
        if (argc == 2)
            free(numbers);
        write(2, "Error\n", 6);
        return (1);
    }
    
    // Sayıları stack_a'ya ekle
    for (i = 0; i < count; i++)
    {
        if (!is_number(numbers[i]))
        {
            if (argc == 2)
                free(numbers);
            write(2, "Error\n", 6);
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
        stack_a->numbers[stack_a->size] = atoi(numbers[i]);
        stack_a->size++;
    }
    
    if (argc == 2)
        free(numbers);
    
    // Sıralama yap
    radix_sort(stack_a, stack_b);
    
    // Belleği temizle
    free_stack(stack_a);
    free_stack(stack_b);
    
    return (0);
} 