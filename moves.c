/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:35:57 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/13 11:53:52 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Both stacks involved. Len of array DOES change
int	*push_checkdst(int *stack_src, int *stack_dst, int len_src, int len_dst) //stack_src's len - 1, stack_dst's len + 1
{
	int	tmp;
	int	i;
	int	*new_stack_src;
	int	*new_stack_dst;
	
	//1. Store 1st value of stack_src in tmp variable
	tmp = stack_src[0];
	//2. Move up the rest of values of stack_src // copy in new resized_stack
	new_stack_src = malloc(sizeof(int)*(len_src - 1));
	i = 0;
	while(len_src > 1)
	{
		new_stack_src[i] = stack_src[i + 1];
		i++;
		len_src--;
	}
	i = 0;
	free(stack_src);
	//3. Move down total values of stack_dst
	new_stack_dst = malloc(sizeof(int)*(len_dst + 1));
	i = 0;
	while(len_dst > 0)
	{
		new_stack_dst[i + 1] = stack_dst[i];
		i++;
		len_dst--;
	}
	free(stack_dst);
	//4. Assign tmp value to stack_dst[0]
	new_stack_dst[0] = tmp;
	//put_arr(new_stack_dst);
	return(new_stack_dst);
}

//Both stacks involved. Len of array DOES change
int	*push_checksrc(int *stack_src, int *stack_dst, int len_src, int len_dst) //stack_src's len - 1, stack_dst's len + 1
{
	int	tmp;
	int	i;
	int	*new_stack_src;
	int	*new_stack_dst;

	//1. Store 1st value of stack_src in tmp variable
	tmp = stack_src[0];
	//2. Move up the rest of values of stack_src // copy in new resized_stack
	new_stack_src = malloc(sizeof(int)*(len_src - 1));
	i = 0;
	while(len_src > 1)
	{
		new_stack_src[i] = stack_src[i + 1];
		i++;
		len_src--;
	}
	i = 0;
	free(stack_src);
	
	//3. Move down total values of stack_dst
	new_stack_dst = malloc(sizeof(int)*(len_dst + 1));
	i = 0;
	while(len_dst > 0)
	{
		new_stack_dst[i + 1] = stack_dst[i];
		i++;
		len_dst--;
	}

	free(stack_dst);
	//4. Assign tmp value to stack_dst[0]
	new_stack_dst[0] = tmp;
	return (new_stack_src);
}

//Just 1 stack involved. Len of array doesn't change
int	*rotate(int *stack, int len) //Len of array doesn't change
{
	int	tmp;
	int	i;
	//int len;
	int	keep_len;

	//len = len_arr(stack);
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

//Just 1 stack involved. Len of array doesn't change
int	*reverse_rotate(int *stack, int len)
{
	int	tmp;
	//int len;
	int	keep_len;
	int	i;
	
	//len = len_arr(stack);
	keep_len = len;
	tmp = stack[0];
	i = 1;
	while (len > 1) //because the move must happen 'len - 1' times.
	{
		stack[i - 1] = stack[i];
		i++;
		len--;
	}
	stack[keep_len - 1] = tmp;
	return (stack);
}

//Just 1 stack involved. Len of array doesn't change
int	*swap(int *stack, int len)
{
	int	tmp;
	//int	len;

	//len = len_arr(stack);
	if (len < 2)
		return (0);
	tmp = stack[len - 1];
	stack[len - 1] = stack[len - 2];
	stack[len - 2] = tmp;
	return (stack);
}

/*int	main(void)
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

    len_b = 7;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 1;
	stack_b[1] = 2;
	stack_b[2] = 4;
	stack_b[3] = 6;
	stack_b[4] = 9;
	stack_b[5] = 13;
	stack_b[6] = 21;

	//new_stack_b = malloc(sizeof(int)*(len_b + 1));
	//new_stack_b = push_checkdst(stack_a, stack_b, len_a, len_b);
	return (0);
}*/