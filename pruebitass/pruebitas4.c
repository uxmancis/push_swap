/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:09:29 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/09 20:13:23 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{	
	int	*stack_b;
	int	len_b;
    int travelling_nb = 1;
    int nb;


	len_b = 5;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 1;
	stack_b[1] = 2;
	stack_b[2] = 3;
	stack_b[3] = 4;
	stack_b[4] = 5;
    nb = index_next_smallest (stack_b, len_b, travelling_nb);
    printf("nb = %d\n", nb);
    return (0);
}