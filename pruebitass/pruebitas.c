/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:14:22 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/06 16:53:05 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*int top_stack (int len, int index)
{
	int numof_moves;
    
    if (index >= len)
    {
        write(1, "Error when accessing to number of stack with this index\n", 56);
        return(0);
    }
	if (index == 1)
		numof_moves = 1; //swap 1 vez
	if (index <= (len / 2)) //este código también contempla el caso de index = 1 y el rtdo es el mismo, pero el move a hacer no.
		numof_moves = index; //rotate n veces
	if (index > (len / 2))
		numof_moves = (len - index); // reverse rotate n veces
	return(numof_moves);
}

int cheapest_top_stack (int *stack, int len)
{
	int *arr_numof_moves;
	int i;
	int keep_len;
	int smallest_index;
	int keep_len_2;

	keep_len = len;
	keep_len_2 = len;
	arr_numof_moves = malloc(sizeof(int) * len);
	i = 0;
	while (len > 0)
	{	
		arr_numof_moves[i] = top_stack(keep_len, i);
		i++;
		len--;
	}

	printf("arr_numof_moves[0] = %d\n", arr_numof_moves[0]);
	printf("arr_numof_moves[1] = %d\n", arr_numof_moves[1]);
	printf("arr_numof_moves[2] = %d\n", arr_numof_moves[2]);
	printf("arr_numof_moves[3] = %d\n", arr_numof_moves[3]);
	printf("arr_numof_moves[4] = %d\n", arr_numof_moves[4]);

	smallest_index = keep_len_2;
	while (keep_len_2 > 0)
	{
		if (arr_numof_moves[i] < smallest_index)
			smallest_index = arr_numof_moves[i];
		i++;
		keep_len_2--;
	}
	return (arr_numof_moves[smallest_index]);
}

int main(void)
{
    int	*stack_a;
	int	len_a;
    int numof_moves;
    int index_of_cheapest;
    
	len_a = 5;
	stack_a = malloc(sizeof(int)*len_a);
	stack_a[0] = 1;
	stack_a[1] = 2;
	stack_a[2] = 3;
	stack_a[3] = 4;
	stack_a[4] = 5;

    index_of_cheapest = cheapest_top_stack(stack_a, len_a);
    printf("index_of_cheapest = %d\n", index_of_cheapest);
    numof_moves = top_stack(stack_a, 10, 10);
    printf("numof_moves of number in position CHOSEn of stack = %d\n", numof_moves);
    return (0);
}*/