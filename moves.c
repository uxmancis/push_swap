/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:35:57 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/28 12:05:20 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void push(int **stack_src, int **stack_dst, int **len_src, int **len_dst) //stack_src's len - 1, stack_dst's len + 1
{
    int tmp;
    int i;
    int *new_stack_src;
    int *new_stack_dst;
    int local_len_src;
    int local_len_dst;


    //printf("len, before: %d\n", *len_src[0]);
    *len_src[0] = *len_src[0] - 1;
    //printf("len, after: %d\n", *len_src[0]);
    local_len_src = *len_src[0];


    //1. Store 1st value of stack_src in tmp variable
    tmp = *stack_src[0];
    //2. Move up the rest of values of stack_src // copy in new resized_stack
    new_stack_src = malloc(sizeof(int)*(*len_src[0]));
    i = 0;
    while(local_len_src > 0)
    {
        new_stack_src[i] = (*stack_src)[i + 1];
        i++;
        local_len_src--;
    }
    i = 0;
    free(*stack_src);
    *stack_src = new_stack_src;
    //3. Move down total values of stack_dst
    //printf("old len_dst = %d\n", *len_dst[0]);
    *len_dst[0] = *len_dst[0] + 1;
    local_len_dst = *len_dst[0];
    //printf("new len_dst = %d\n", *len_dst[0]);
    new_stack_dst = malloc(sizeof(int)*(*len_dst[0]));
    i = 0;
    while((local_len_dst - 1) > 0)
    {
        new_stack_dst[i + 1] = (*stack_dst)[i];
        i++;
        local_len_dst--;
    }
    //4. Assign tmp value to stack_dst[0]
    new_stack_dst[0] = tmp;
    free(*stack_dst);
    *stack_dst = new_stack_dst;
    //put_2stacks(new_stack_src, new_len_src, new_stack_dst, new_len_dst);
}


//Just 1 stack involved. Len of array doesn't change
void reverse_rotate(int ****stack, int len) //Len of array doesn't change
{
    int tmp;
    int i;
    //int len;
    int keep_len;


    //len = len_arr(stack);
    keep_len = len;
    tmp = *stack[len - 1];
    i = 1;
    while (len > 1)
    {
        *stack[keep_len - i] = *stack[keep_len - (i + 1)];
        i++;
        len--;
    }
    *stack[0] = tmp;
}


//Just 1 stack involved. Len of array doesn't change
void rotate(int ****stack, int len)
{
    int tmp;
    //int len;
    int keep_len;
    int i;
   
    //printf("ha entrado en rotate_b\n");
    //len = len_arr(stack);
    keep_len = len;
    tmp = *stack[0];
    i = 1;
    while (len > 1) //because the move must happen 'len - 1' times.
    {
        *stack[i - 1] = *stack[i];
        i++;
        len--;
    }
    *stack[keep_len - 1] = tmp;
}


//Just 1 stack involved. Len of array doesn't change
void swap(int ****stack, int len)
{
    int tmp;


    if (len < 2)
        return (0);
    tmp = **stack[0];
    **stack[0] = stack[1];
    **stack[1] = tmp;
}


/*int   main(void)
{
    int *stack_a;
    int *stack_b;
    int len_a;
    int len_b;




    len_a = 5;
    stack_a = malloc(sizeof(int)*len_a);
    stack_a[0] = 1;
    stack_a[1] = 2;
    stack_a[2] = 3;
    stack_a[3] = 4;
    stack_a[4] = 5;


    len_b = 7;
    stack_b = malloc(sizeof(int)*len_b);
    stack_b[0] = 1;
    stack_b[1] = 2;
    stack_b[2] = 4;
    stack_b[3] = 6;
    stack_b[4] = 9;
    stack_b[5] = 13;
    stack_b[6] = 21;


    //new_stack_b = malloc(sizeof(int)*(len_b + 1));
    //new_stack_b = push_checkdst(stack_a, stack_b, len_a, len_b);
    printf("Before:\n");
    put_arr(stack_a, len_a);
    printf("\n");
    push_checksrc(stack_a, stack_b, len_a, len_b);
    printf("After:\n");
    put_arr(stack_a, len_a);
    return (0);
}*/



