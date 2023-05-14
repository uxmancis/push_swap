/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:14:27 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/14 16:54:23 by uxmancis         ###   ########.fr       */
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

void	check_before (int *stack_a, int *stack_b, int len_a, int len_b)
{
	printf("\n");
	printf("Beginning:\n");
	printf("- stack_a:\n");
	put_arr(stack_a, len_a);
	printf("\n");
	printf("- stack_b:\n");
	put_arr(stack_b, len_b);
	printf("\n");
	printf("-----------------------\n");
	printf("\n");
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
	stack_a[1] = 3;
	stack_a[2] = 5;
	stack_a[3] = 7;
	stack_a[4] = 16;

    len_b = 7;
	stack_b = malloc(sizeof(int)*len_b);
	stack_b[0] = 21;
	stack_b[1] = 13;
	stack_b[2] = 9;
	stack_b[3] = 6;
	stack_b[4] = 4;
	stack_b[5] = 2;
	stack_b[6] = 0;

    //Checking BEFORE:
	printf("Beginning:\n");
	put_2stacks (stack_a, len_a, stack_b, len_b);
	//check_before(stack_a, stack_b, len_a, len_b);
	push_swap(stack_a, stack_b, len_a, len_b);
	return (0);
}