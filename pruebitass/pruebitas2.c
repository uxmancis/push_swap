/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:01:11 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/09 20:08:59 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*DESCRIPTION
org_stack_b function returns the number of movements it takes to stack b to get ready
to receive travelling number from stack a
____________________________________________________________________________*/
int org_stack_b (int *stack_b, int len_b, int index_ns)
{
	int numof_moves;

	if (len_b == 2) //Before making number travel
	{
		numof_moves = 0;
		return (numof_moves);
	}
	if (index_ns < (len_b / 2))
	{
		numof_moves = (index_ns + 1);
		return(numof_moves);
	}
	if (index_ns >= (len_b / 2))
	{
		numof_moves = (len_b - index_ns - 1);
		return(numof_moves);
	}
	return(0);
}

/*DESCRIPTION -- AHORA MISMO (7.04PM) NO LE VEO SENTIDO // 7.55pm ya se lo veo de nuevo jaja
//8pm OK, hay que hacer esto, pero de la siguiente manera: 
cada 1 travelling number = tiene 1 distinto index_next_smallest

SÍ hay que generar un arr2_numof_moves, con 1 numero de moves correspondiente
generado por cada 1 index_next_smallest generado por 1 travelling number

NO hay que: generar 1 arr2_numof_moves de todos los moves posibles por cada 1 travelling number.
NO! porque cada travelling number posible, tiene 1 único numof lo que tardaría en ordenarsse
el stack b en base a eso.

So, el bucle para generar el arr2_numof_moves SÍ hay que generarlo, pero no aquí dentro, 1 vez 
que ya tenemos el X travelling number. NO! Tenermos que hacerlo fuerea, y mandarle quee por cada
travelling number distinto, nos genere 1 únic numof moves de stack b, y todos recogerlos en el arr2.
SÍ crear el arr2_numof_moves, pero no aquí dentro. Si no que fuera.

cheapst_org_stack_b function returns the index of the
____________________________________________________________________________*/
int	cheapst_org_stack_b(int *stack_b, int len_b, int travl_nb, int indx_nxt_smallst)
{
	int *arr2_numof_moves;
	int keep_len_b;
	int i;
	
	arr2_numof_moves = malloc(sizeof(int) * len_b);
	i = 0;
	while (len_b > 0)
	{
		arr2_numof_moves[i] = org_stack_b(stack_b, len_b, indx_nxt_smallst);
		i++;
		len_b--;
	}
	return (0);
}

/*DESCRIPTION
org_stack_b function returns the number of movements (rotate or reverse rotate)
stack_b needs in order to be ready/prepared to receive number from stack_a by pb
movement on its top

We will call org_stack_b when stack_b needs min. 1 movement in order to be ready.
Before calling org_stack_b, we will have checked that the travelling number 
from stack a is neither higher than the highest number in stack b, nor smaller
than the smallest number in stack b.
· next_smallest: represents the highest number in stack b among the ones that are
smaller than the travelling number


By now: index_next_smallest function returns the index of the number in stack b which is the 
highest among the numbers in stack b that are smaller than the travelling number.
Which means, taking the travelling number as comparison point, which is the next smallest
number in stack_b?
____________________________________________________________________________*/
int index_next_smallest (int *stack_b, int len_b, int travelling_nb)
{
	int	keep_len_b;
	int	i;
	int	next_smallest;
	int index;

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
smallest_nb returns the smallest number of the stack that is being analysed. 
It returns the actual number, not its index.
____________________________________________________________________________*/
int smallest_nb(int *stack_b, int len_b)
{
    int i;
    int smallest_nb;

    i = 0;
    smallest_nb = stack_b[i];
    while(len_b > 0)
    {
        if(stack_b[i] < smallest_nb)
            smallest_nb = stack_b[i];
        i++;
        len_b--;
    }
    return(smallest_nb);
}

/*DESCRIPTION
highest_nb returns the highest number of the stack that is being analysed. 
It returns the actual number, not its index.
____________________________________________________________________________*/
int	highest_nb(int *stack_b, int len_b)
{
	int	i;
	int	highest_nb;

	i = 0;
	highest_nb = stack_b[i];
	while (len_b > 0)
	{
		if (stack_b[i] > highest_nb)
			highest_nb = stack_b[i];
		i++;
		len_b--;
	}
	return (highest_nb);
}

/*DESCRIPTION
get_b_ready functions returns the number of movements
int	get_b_ready(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int	keep_len_a;
	int	keep_len_b;
	int	i;
	int num_of_moves;
	
	i = 0;
	while (len_a > 0)
	{
		if(stack_a[i] > highest_nb(stack_b, len_b) || stack_a[i] < smallest_nb(stack_b, len_b))
		{
			num_of_moves = 0;
			return (num_of_moves);
		}
		else
			num_of_moves = cheapst_org_stack_b
		len_a--;
	}
	return (0);
}*/

int main(void)
{
    int	*stack_a;
    int *stack_b;
	int	len_a;
    int len_b;
    int numof_moves;
    int index_of_cheapest;
    int index_ns;
	int travelling_nb;
    
	len_a = 7;
	stack_a = malloc(sizeof(int)*len_a);
	stack_a[0] = 8;
	stack_a[1] = 4;
	stack_a[2] = 9;
	stack_a[3] = 3;
	stack_a[4] = 6;
	stack_a[5] = 1;
	stack_a[6] = 7;

    len_b = 7;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 1;
	stack_b[1] = 2;
	stack_b[2] = 4;
	stack_b[3] = 6;
	stack_b[4] = 9;
	stack_b[5] = 13;
	stack_b[6] = 21;

    /*index_of_cheapest = cheapest_top_stack(stack_a, len_a);
    printf("index_of_cheapest = %d\n", index_of_cheapest);*/
	travelling_nb = 7;
	printf("travelling_nb = %d\n", travelling_nb);
    index_ns = index_next_smallest(stack_b, len_b, travelling_nb);
	printf("index_next_smallest = %d\n", index_ns);
	numof_moves = org_stack_b(stack_b, len_b, index_ns);
    printf("numof_moves to get stack b ready = %d\n", numof_moves);
    return(0);
}