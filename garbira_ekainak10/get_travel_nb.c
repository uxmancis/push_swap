/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_travel_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:53 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/11 16:12:08 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
index_biggest returns the index of the biggest value in the stack we pass as an argument.

We use it to get biggest value in stack_b. 

When? After travelling_nb is identified, we check which is next smallest value in stack_b. But, sometimes, 
there will be NOT be any smaller value than travelling_nb in stack_b. In those cases, the way of organising stack_b
will be putting the biggest value on the top of it. In index_biggest we identify the value we want to put
on the top of stack_b in order to receive travelling_nb, when this travelling_nb will become the new smallest value
in stack_b.
------------------------------------------------------------------------------------------------------------*/
int ft_index_biggest (int *stack_b, int len_b)
{
	int value_biggest;
	int ind_biggest;
	int i;
	int keep_len_b;

	keep_len_b = len_b;
	i = 0;
	value_biggest = stack_b[i];
    printf("get_travel_nb.c | line 36 | value_biggest = %d | len_b = %d\n", value_biggest, len_b);
	while (len_b > 0) //get the value of the biggest value in stack_b
	{
		if (stack_b[i] > value_biggest)
        {
            value_biggest = stack_b[i];
            printf("get_travel_nb.c | line 41 | reasignar valor value_biggest, new value_biggest = %d\n", value_biggest);
        }
			
		i++;
		len_b--;
	}
	//printf("get_travel_nb.c | line 33 | value_biggest = %d | keep_len_b = %d\n", value_biggest, keep_len_b);
	i = 0;
	while (keep_len_b > 0) //identificar el índice del biggest value, que es lo que nos interesa para poder ver cuál es el movimiento que vamos a necesitar hacer
	{
        //printf("hona sartu da bai\n");
		if (stack_b[i] == value_biggest)
		{
            printf("here also\n");
			ind_biggest = i;
            printf("line 44 | ind_biggest = %d\n", ind_biggest);
			return (ind_biggest);
		}
		keep_len_b--;
        i++;
	}
	return (0);
}

/*DESCRIPTION:
index_next_smallest function returns the index of the number in stack b which is the
highest among the numbers in stack b that are smaller than the travelling number.
Which means, taking the travelling number as comparison point, which is the next smallest
number in stack_b?

It returns the index (position) of the next smallest number in stack_b, not the value
itself.
____________________________________________________________________________*/
int ft_index_next_smallest (int *stack_b, int len_b, int travelling_nb)
{
    //int len_b;
    int keep_len_b;
    int keep_len_b_2;
    int i;
    int next_smallest;
    int index;
    
    //printf("travelling_nb = %d\n", travelling_nb);
    //len_b = len_arr(stack_b);
    //en caso de que en stack_b no haya un número más pequeño que el travelling nb
    
    keep_len_b = len_b;
    keep_len_b_2 = len_b;
    next_smallest = 0;

    while(keep_len_b_2 > 0)
    {
        if (travelling_nb < stack_b[i])
            i++;
    }
    i= 0;
    while (len_b > 0) //conseguir identificar el valor (next smallest) del stack_b
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
    while (keep_len_b > 0) // conseguir el índice en stack_b del valor que queremos (next smallest)
    {
        if(stack_b[index] == next_smallest)
            return(index);
        keep_len_b--;
        index++;
    }
    return (0);
}

/*DESCRIPTION
org_stack_b function returns the number of movements it takes to stack b to get ready
to receive travelling number from stack a.

For that, it calculates which is the least number of movements the value with index_top_stack
needs to get to the top.
This value can be either of the following 2: 
1. next smallest number in stack_b: when there are smaller numbers than travel_nb in stack_b)
2. biggest number in stack_b: when there is NOT any smaller number than travel_nb in stack_b
____________________________________________________________________________*/
int	org_stack_b_2 (int *stack_b, int len_b, int index_top_stack)
{
	int	numof_moves;

	printf("get_travel_nb.c | line 77 | index_top_stack = %d\n", index_top_stack);
	//printf("call2moves.c line 88 | index_ns = %d\n", index_ns);
	if (len_b == 2) //Before making number travel
		numof_moves = 0;
	if (index_top_stack <= (len_b / 2))
		numof_moves = index_top_stack;
	if (index_top_stack > (len_b / 2))
		numof_moves = len_b - index_top_stack;
	//printf("org_stack_b | index_ns = %d | numof_moves = %d\n", index_ns, numof_moves);
	return (numof_moves);
}

/*DESCRIPTION:
1. org_stack_b_1 function decides in which way will we organise the stack_b in order to receive 
travelling number from stack_a.

There are 2 ways, depending on the answer to the question: "Is there any value in stack_b which is smaller
than the travelling number?"
YES: 1. get next smallest number, 2. move it to the top
NO: 1. identify biggest value in stack_b, 2. move it to the top

2. Also, it returns the number of movements it will take to organise stack_b.
---------------------------------------------------------------------------------------------------------*/
int org_stack_b_1 (int *stack_b, int len_b, int travel_nb)
{
	int index_next_smallest;
	int index_biggest;
    int value_next_smallest;
	int i;
	int keep_len_b;

	keep_len_b = len_b;
	i = 0;
	value_next_smallest = travel_nb;
	while (len_b > 0) //get the value of the next_smallest value in stack_b
	{
		if (stack_b[i] < value_next_smallest)
			value_next_smallest = stack_b[i];
		i++;
		len_b--;
	}
    printf("get_travel_nb.c | line 172 | travel_nb = %d | value_next_smallest = %d\n", travel_nb, value_next_smallest);
	if (value_next_smallest == travel_nb) //significa que no hay valores más pequeños que el travel_nb en stack_b --> so, para ordenar stack_b, el que hay que pasar arriba del todo = el número biggest de stack_b
	{
		index_biggest = ft_index_biggest(stack_b, keep_len_b);
        printf("get_travel_nb.c | line 175 | NO HAY VALORES MÁS PEQUEÑOS QUE EL TRAVELLING NB, index que va al top: index_biggest = %d\n", index_biggest);
        return (index_biggest);
        //1. identificar index del valor más grande de stack_b
		//2. moverlo arriba
		//aquí solo devolveremos el índice, de moverlo arriba se encarga primero org_stack_b_2s_move para decir qué move va a necesitar, luego decide_move_org_b para actually ejecutarlo
	}
	else //significa que sí que hay valores más pequeñitos
	{
        index_next_smallest = ft_index_next_smallest (stack_b, len_b, travel_nb);
        printf("get_travel_nb.c | line 184 | SÍ hay valores más pequeños, el index que va al top: index_next_smallest = %d\n", index_next_smallest);
        return (index_next_smallest);
		//1. identificar el next_smallest value_biggest
		//2. moverlo arriba
		//aquí solo devolveremos el índice, de moverlo arriba se encarga primero org_stack_b_2s_move para decir qué move va a necesitar, luego decide_move_org_b para actually ejecutarlo
	}
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
    int numof_moves;


    //printf("get_travel_nb | line 103 | top_stack | len = %d\n", len);
    if (index >= len)
    {
        write(1, "Error: accessing to number of stack with this index\n", 52);
        return (0);
    }
    if (index == 0)
        numof_moves = 0; //el valor que ya está en la última posición / top del stack_a
    if (index == 1)
        numof_moves = 1; //swap 1 vez
    if (index <= (len / 2)) //este código también contempla el caso de index = 1 y el rtdo es el mismo, pero el move a hacer no.
        numof_moves = index; //rotate n veces
    if (index > (len / 2) && index != len)
        numof_moves = (len - index); // reverse rotate n veces
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
    int numof_moves_top_stack;
    int numof_moves_org_b;
    int total_numof_moves;


    printf("index = %d\n", index);
    numof_moves_top_stack = top_stack (len_a, index);
    printf("moves_top_stack = %d\n", numof_moves_top_stack);
    numof_moves_org_b = org_stack_b_2 (stack_b, len_b, org_stack_b_1(stack_b, len_b, stack_a[index])); // chiquita liada, hemen stack_a[index] pasatze jat, baina ez jat hau pasau bihar. 3.40pm. Oin iruditze jata baietz.
    printf("moves_org_b = %d\n", numof_moves_org_b);
    total_numof_moves = numof_moves_top_stack + numof_moves_org_b + 1;
    printf("TOTAL_moves = %d\n\n", total_numof_moves);
    return (total_numof_moves);
}

/*DESCRIPTION
get_cheapest_nb function returns the index of number in stack_a that is going to travel to stack_b.
For doing so, it calculates which is the "cheapest" value of stack_a, meaning which is the value
in stack_a which needs the least amount of movements to get to the correct position
in stack_b.
---------------------------------------------------------------------------------------------------*/
int get_cheapest_nb(int *stack_a, int len_a, int *stack_b, int len_b)
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