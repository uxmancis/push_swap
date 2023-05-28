/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:08 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/09 19:25:44 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	len_arr(int *stack)
{
	int	len;

	len = 0;
	while (stack[len])
	{
		len++;
	}
	return (len);
}

void	put_arr(int *stack)
{
	int	len;

	len = len_arr(stack);
	len = len - 1;
	while (len >= 0)
	{
		printf("stack[%d] = %d\n", len, stack[len]);
		len--;
	}
}

int	*rotate(int *stack) //Len of array doesn't change
{
	int	tmp;
	int	i;
	int len;
	int	keep_len;

	len = len_arr(stack);
	keep_len = len;
	tmp = stack[len - 1];
	i = 1;
	while (len > 1)
	{
		stack[keep_len - i] = stack[keep_len - (i + 1)];
		i++;
		len--;
	}
	stack[0] = tmp;
	return (stack);
}

int	main(void)
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;


	len_a = 5;
	stack_a = malloc(sizeof(int)*len_a);
	stack_a[0] = 1;
	stack_a[1] = 2;
	stack_a[2] = 3;
	stack_a[3] = 4;
	stack_a[4] = 5;

    put_arr(stack_a);
    stack_a = rotate(stack_a);
	printf("-------MOVEMENT-----\n");
	put_arr(stack_a);
    return(0);
}