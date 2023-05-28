/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas10_structures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:11:04 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/15 18:53:58 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebitas.h"

void put_struct (t_both new, int new_len_src, int new_len_dst)
{
    int i;
    
    i = 0;
    while (new_len_src > 0)
    {
        printf("new_stack_src[%d] = %d\n", i, new.g_stack_src[i]);
        new_len_src--;
    }
    printf("\n");
    i = 0;
    while (new_len_dst > 0)
    {
        printf("new_stack_dst[%d] = %d\n", i, new.g_stack_dst[i]);
        new_len_dst--;
    }
    printf("\n");
}

void put_2stacks (int *stack_a, int len_a, int *stack_b, int len_b)
{
	int min_numof_lines;
	int max_numof_lines;
	char longest;
	int diff;
	int i;

	//printf("len_a = %d\n", len_a);
	//printf("len_b = %d\n", len_b);
	if (len_a < len_b)
	{
		min_numof_lines = len_a;
		max_numof_lines = len_b;
		longest = 'B';
	}
	if (len_a > len_b)
	{
		min_numof_lines = len_b;
		max_numof_lines = len_a;
		longest = 'A';
	}
	diff = max_numof_lines - min_numof_lines;
	//printf("min_numof_lines = %d\n", min_numof_lines);
	//printf("max_numof_lines = %d\n", max_numof_lines);
	//printf("diff = %d\n", diff);
	len_a = len_a - 1;
	len_b = len_b - 1;
	//printf("v2 len_a = ")
	i = 0;
	while(min_numof_lines > 0)
	{
		printf("stack_a[%d] = %d               stack_b[%d] = %d\n", i, stack_a[i], i, stack_b[i]);
		i++;
		min_numof_lines--;
	}
	//printf ("i = %d\n", i);
	//printf("max_numof_lines = %d\n", max_numof_lines);
	//printf("min_numof_lines = %d\n", min_numof_lines);
	if(longest == 'A')
	{
		while (diff > 0)
		{
			printf("stack_a[%d] = %d\n", i, stack_a[i]);
			diff--;
		}
	}
	if (longest == 'B')
	{	
		while (diff > 0)
		{
			printf("                             stack_b[%d] = %d\n", i, stack_b[i]);
			i++;
			diff--;
		}
	}
}

t_both push(int *stack_src, int *stack_dst, int len_src, int len_dst)
{
	t_both new;
    int i;
    int tmp;
    int new_len_src;
    int new_len_dst;

	printf("dentro de función PUSH\n");
    put_2stacks(stack_src, len_src, stack_dst, len_dst);
    new_len_src = len_src - 1;
    new_len_dst = len_dst + 1;
    new.s_src = malloc(sizeof(int) * (new_len_src));
	new.s_dst = malloc(sizeof(int) * (new_len_dst));
    tmp = stack_src[0];
    i = 0;
    while (len_src > 1)
    {
        new.s_src[i] = stack_src[i + 1];
        i++;
        len_src--;
    }
	free (stack_src);
    i = 0;
    while (len_dst > 0)
    {
        new.s_src[i + 1] = stack_dst[i];
        i++;
        len_dst--;
    }
    new.s_src[0] = tmp;
    free (stack_dst);
    printf("inside push function printing\n");
    put_struct(new, new_len_src, new_len_dst);
    printf("listo\n");
    return (new);
}

int main(void)
{
    int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	t_both result;


	len_a = 5;
	stack_a = malloc(sizeof(int)*len_a);
	stack_a[0] = 1;
	stack_a[1] = 3;
	stack_a[2] = 5;
	stack_a[3] = 7;
	stack_a[4] = 16;

    len_b = 7;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 21;
	stack_b[1] = 13;
	stack_b[2] = 9;
	stack_b[3] = 6;
	stack_b[4] = 4;
	stack_b[5] = 2;
	stack_b[6] = 0;

    //Checking BEFORE:
	printf("Beginning:\n");
	put_2stacks (stack_a, len_a, stack_b, len_b);
    printf("\n");
	result = push(stack_a, stack_b, len_a, len_b);
    put_struct(result, 4, 8);
    printf("\ndespués de función PUSH\n");
    put_2stacks (stack_a, len_a, stack_b, len_b);
	//check_before(stack_a, stack_b, len_a, len_b);
	//push_swap(stack_a, stack_b, len_a, len_b);
	return (0);
}