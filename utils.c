/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:58:00 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/28 12:06:39 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


/*size_t    len_arr(int *stack)
{
    size_t  len;


    len = 0;
    while (stack[len] != '\0')
    {
        len++;
    }
    //return (sizeof(stack)/sizeof(stack[0]));
    return (len);
}*/


/*DESCRIPTION
strcmp function compares str1 and str2.
Returns:
1: NOT the same, they are different
0: 100% same str.
------------------------------------------------*/
int strcmp (const char *str1, const char *str2)
{
    int i;
   
    i = 0;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] == str2[i])
            i++;
        else
            return(1);
    }
    return (0);
}


void put_matrix (char **list_moves)
{
    int x;
    int y;
   
    x = 0;
    while(list_moves[x][0] != '\0')
    {
        //printf("line 36 hemen\n");
        y = 0;
        while(list_moves[x][y] != '\0')
        {
            //printf("line 40\n");
            write(1, &list_moves[x][y], 1);
            y++;
        }
        write(1, "\n", 1);
        //printf("line 44 hemen\n");
        x++;
    }
}


int ft_strlen (char *str)
{
    int len;


    len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return (len);
}


void put_str(char *str)
{
    int len;


    len = 0;
    while(str[len] != '\0')
    {
        write(1, &str[len], 1);
        len++;
    }
    write(1, "\n", 1);
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


void    put_arr(int *stack, int len)
{
    int i;


    i = 0;
    while (len > 0)
    {
        printf("stack[%d] = %d\n", i, stack[i]);
        len--;
        i++;
    }
}


// int  main(void)
// {
//  int *stack_a;
//  int *stack_b;
//  int len_b;
//     int  i;
//  int keep_len_a;
//  int keep_len_b;
//  int len;


//  stack_a = malloc(sizeof(int)*5);
//  stack_a[0] = 1;
//  stack_a[1] = 2;
//  stack_a[2] = 3;
//  stack_a[3] = 4;
//  stack_a[4] = 5;
//  //put_arr(stack_a);
//  len = len_arr(stack_a);
//  printf("len = %d\n", len);
//  return(0);
// }
