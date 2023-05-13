/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_travel_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:23:56 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/13 13:33:02 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The functions of this file aim to return WHICH is the number that will travel from stack A to stack B.

/*3.2.1.- Calcular el "cheapest number
				- ¿Cuántos moves para llevarlo arriba del stack A (a última posición)?
					- call2moves.c | cheapest_top_stack: devuelve 
				- ¿Cuántos moves para poner stack B ready para recibir nuevo valor?
				- + 1 (push b)
				- TOTAL ()
			3.2.2.- Comparar el total de los moves que requeriría cada número del stack A para pasarlo al B.
			3.2.3.- Elegir el que MENOS moves vaya a necesitar + pasarlo a la última posición del stack B (pb).*/

/*DESCRIPTION:
index_next_smallest function returns the index of the number in stack b which is the 
highest among the numbers in stack b that are smaller than the travelling number.
Which means, taking the travelling number as comparison point, which is the next smallest
number in stack_b?
____________________________________________________________________________*/
int index_next_smallest (int *stack_b, int len_b, int travelling_nb)
{
	//int len_b;
	int	keep_len_b;
	int	i;
	int	next_smallest;
	int index;

	//printf("travelling_nb = %d\n", travelling_nb);
	//len_b = len_arr(stack_b);
	keep_len_b = len_b;
	next_smallest = 0;
	i= 0;
	while (len_b > 0)
	{
		if (stack_b[i] < travelling_nb)
		{
			if (stack_b[i] > next_smallest)
            {
                next_smallest = stack_b[i];
            }
		}
		i++;
		len_b--;
	}
	index = 0;
	while(keep_len_b > 0)
	{
		if(stack_b[index] == next_smallest)
			return(index);
		keep_len_b--;
		index++;
	}
    return(0);
}


/*DESCRIPTION
org_stack_b function returns the number of movements it takes to stack b to get ready
to receive travelling number from stack a.
____________________________________________________________________________*/
int org_stack_b (int *stack_b, int len_b, int index_ns)
{
	int numof_moves;

	printf("get_travel_nb.c | line 77 | index_ns = %d\n", index_ns);
	//printf("call2moves.c line 88 | index_ns = %d\n", index_ns);
	if (len_b == 2) //Before making number travel
		numof_moves = 0;
	if (index_ns < (len_b / 2))
		numof_moves = (index_ns + 1);
	if (index_ns >= (len_b / 2))
		numof_moves = (len_b - index_ns - 1);
	//printf("org_stack_b | index_ns = %d | numof_moves = %d\n", index_ns, numof_moves);
	return (numof_moves);
}


/*DESCRIPTION:
top_stack returns the minimum number of movements (swap, rotate or reverse rotate) 
a number of a stack needs to get to the top of the stack (last position in array)

· len = len of stack 
· index = position in stack of the number which numof_moves to get to the top of the stack
we want to analyse.
-----------------------------------------------------------------------------*/
int top_stack (int len, int index)
{
	int	numof_moves;

	//printf("get_travel_nb | line 103 | top_stack | len = %d\n", len);
	if (index >= len)
	{
		write(1, "Error: accessing to number of stack with this index\n", 52);
		return (0);
	}
	if (index == (len - 1))
		numof_moves = 0; //el valor que ya está en la última posición / top del stack_a
	if (index == (len - 2))
		numof_moves = 1; //swap 1 vez
	if (index < (len / 2)) //este código también contempla el caso de index = 1 y el rtdo es el mismo, pero el move a hacer no.
		numof_moves = index + 1; //rotate n veces
	if (index >= (len / 2) && index != len)
		numof_moves = (len - index - 1); // reverse rotate n veces
	//printf("top_stack | index = %d | numof_moves = %d\n", index, numof_moves);
	return (numof_moves);
}

/*DESCRIPTION
sum_moves function returns the total number of movements a particular value from
stack_a needs in order to travel to the correct position in stack_b.

For that, it will take into account the followings:
1. Number of movements value in stack_a needs in order to get to the top of stack_a
2. Number of movements stack_b needs in order to move and be ready for receiving value of stack_a
3. + 1 = push_b (pb) movement, to travel*/
int sum_moves(int *stack_a, int index, int *stack_b, int len_a, int len_b)
{
	int moves_top_stack;
	int moves_org_b;
	int total_moves;

	printf("index = %d\n", index);
	moves_top_stack = top_stack (len_a, index);
	printf("moves_top_stack = %d\n", moves_top_stack);
	moves_org_b = org_stack_b (stack_b, len_b, index_next_smallest(stack_b, len_b, stack_a[index]));
	printf("moves_org_b = %d\n", moves_org_b);
	total_moves = moves_top_stack + moves_org_b + 1;
	printf("TOTAL_moves = %d\n\n", total_moves);
	return (total_moves);
}

/*DESCRIPTION
get_cheapest_nb function returns the number that is going to travel to stack_b.
For doing so, it calculates which is the "cheapest" value of stack_a, meaning which is the value
in stack_a which needs the least amount of movements to get to the correct position 
in stack_b.*/
int get_cheapest_nb(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int *arr_final_numof_moves;
	int index;
	int numof_least_moves;
	int i;
	int keep_len_a;

	//len = len_arr(stack_a);
	arr_final_numof_moves = malloc(sizeof(int)*len_a);
	keep_len_a = len_a;
	index = 0;
	while (len_a > 0)
	{
		arr_final_numof_moves[index] = sum_moves(stack_a, index, stack_b, keep_len_a, len_b);
		index++;
		len_a--;
	}
	printf("\narr_final_numof_moves: \n");
	put_arr(arr_final_numof_moves, keep_len_a);
	printf("\n");
	index = 0;
	numof_least_moves = arr_final_numof_moves[index];
	printf("numof_least_moves = %d --------------> PRE: line 172\n", numof_least_moves);
	//printf("index = %d\n", index);
	//printf("arr_final_numof_moves[%d] = %d\n", index, arr_final_numof_moves[index]);
	//printf("keep_len_a = %d\n", keep_len_a);
	while (keep_len_a > 0)
	{
		if (arr_final_numof_moves[index] < numof_least_moves)
			numof_least_moves = arr_final_numof_moves[index];
		else
		{
			keep_len_a--;
			index++;
		}
	}
	printf("numof_least_moves = %d --------------> PRE: line 183\n", numof_least_moves);
	i = 0;
	while (arr_final_numof_moves[i])
	{
		if (arr_final_numof_moves[i] == numof_least_moves)
			return (i);
		else
			i++;
	}
	return (i);
}

/*int main(void)
{
	int len;
	int index;
	int numof_moves;
	int index_ns;	
	int	*stack_b;
	int	len_b;
	int travelling_nb;

    len_b = 7;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 1;
	stack_b[1] = 2;
	stack_b[2] = 4;
	stack_b[3] = 6;
	stack_b[4] = 9;
	stack_b[5] = 13;
	stack_b[6] = 21;

	len = 11;
	index = 0;
	//numof_moves = top_stack(len, index);
	travelling_nb = 3;
	index_ns = index_next_smallest (stack_b, travelling_nb);
	printf("index_ns = %d\n", index_ns);
	numof_moves = org_stack_b (stack_b, index_ns);
	//printf("index = %d\n", index);
	printf("numof_moves = %d\n", numof_moves);
}*/