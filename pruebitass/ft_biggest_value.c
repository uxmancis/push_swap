/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:59:16 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/11 16:11:38 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main (void)
{
    int *arr;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    printf("ind_biggest = %d\n", ft_index_biggest (arr, 5));
    return (0);
}