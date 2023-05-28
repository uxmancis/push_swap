/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas5_ander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:41:47 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/15 19:45:14 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int len_arr(int *stack)
{
    int len; 

    len = 0;
    while(stack[len])
    {
        len++;
    }
    return(len);
}

void	put_arr(int *stack, int len)
{
	len = len - 1;
    //printf("len = %d\n", len);
	while (len >= 0)
	{
		printf("stack[%d] = %d\n", len, stack[len]);
		len--;
	}
}

void change_arr(int **stack)
{
    int *new;

    new = malloc(sizeof(int)*2);
    new[0] = 2;
    new[1] = 2;
    printf("new:\n");
    put_arr(new, 2);
    free(*stack);
    *stack = new;
    printf("ahora:\n");
    put_arr(*stack, 2);
    //printf("stack pointer within scope: %p\n", *stack);
    //return (stack);
}

/*void changechar(char *c)
{
    *c = 'd';
}*/

int main(void)
{
    int *arr;

    arr = malloc(sizeof(int)*4);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    //char c = 'c';
    //changechar(&c);
    //printf("Char is c: %c\n", c);
    put_arr(arr, 4);
    //arr = change_arr(arr);
    change_arr(&arr);
    printf("---\n");
    put_arr(arr, 2);
    //printf("stack pointer main: %p\n", arr);
    return (0);
}