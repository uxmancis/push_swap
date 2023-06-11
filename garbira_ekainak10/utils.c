/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:47:47 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/10 18:02:48 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void check_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b)
{
    printf("\nThe movements/instructions that will be executed are the following ones:\n");
    printf(" \n---------- TOP_STACK: ----------------------\n");
    printf("Which movement?: %s\n", move_type_top_stack);
    printf("How many times? %d\n", numof_moves_top_stack);
    printf("\n------------ ORG_B: ----------------------\n");
    printf("Which movement?: %s\n", move_type_org_b);
    printf("How many times? %d\n", numof_moves_org_b);
    printf("\n");
}

/*DESCRIPTION:
numof_digits cuenta el número de digitos total que tiene cada integer
---------------------------------------------------------------------*/
int	numof_digits(char **argv, int x, int y, int len_arg)
{
	int	counter;

	counter = 0;
	//printf("line 129 | numof_digits function, x = %d | y = %d | len_arg = %d\n", x, y, len_arg);
	while (ft_isdigit(argv[x][y]) == 1)
	{
		//printf("line 172 || bucle dentro de numof_digits\n");
		counter++;
		y++;
	}
	return (counter);
}

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

/*DESCRIPTION:
isdigit function:
returns 1: if YES: '-', or [0-9]
returns 0: if NOT
__________________________________*/
int ft_isdigit(char c)
{
	if (c == '-' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*DESCRIPTION
strcmp function compares str1 and str2.
Returns:
1: NOT the same, they are different
0: 100% same str.
------------------------------------------------*/
int ft_strcmp (const char *str1, const char *str2)
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

int	atoi2(char *str)
{
	int	sign;
	int	i;
	int	result;

	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	i++;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - 48);
	}
	return (result);
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
