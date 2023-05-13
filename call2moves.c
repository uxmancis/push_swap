/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call2moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:47:45 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/13 17:36:32 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **list_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b)
{
	char **list_moves;
	int len_move_type_top_stack;
	int len_move_type_org_b;
	int x;
	int y;

	len_move_type_top_stack = ft_strlen(move_type_top_stack);
	len_move_type_org_b = ft_strlen(move_type_org_b);
	printf("len_move_type_top_stack = %d\n", len_move_type_top_stack);
	printf("len_move_type_org_b = %d\n", len_move_type_org_b);

	list_moves = malloc(sizeof(char *) * (numof_moves_top_stack + numof_moves_org_b + 2)); //(top_stack) + (org_b) + 2 (pb, '\0')
	//First, top_stack list of moves:
	printf("numof_moves_top_stack = %d\n", numof_moves_top_stack);
	x = 0;
	while(numof_moves_top_stack > 0)
	{
		x = 0;
		list_moves[x] = malloc(sizeof(char) * (len_move_type_top_stack + 1));
		while(list_moves[x][0] != '\0')
		{
			y = 0;
			while(list_moves[x][y] != '\0')
			{
				list_moves[x][y] = move_type_top_stack[y];
				y++;
			}
			list_moves[x][y] = '\0';
			x++;
		}
		numof_moves_top_stack--;
	}
	//printf("x = %d\n", x);
	//Then, org_b list of moves:
	printf("numof_moves_org_b = %d\n", numof_moves_org_b);
	list_moves[x] = malloc(sizeof(char) * (len_move_type_org_b + 1));
	while (numof_moves_org_b > 0)
	{
		//printf("yes\n");
		list_moves[x] = malloc(sizeof(char) * (len_move_type_org_b + 1));
		y = 0;
		while(move_type_org_b[y] != '\0')
		{
			list_moves[x][y] = move_type_org_b[y];
			y++;
		}
		list_moves[x][y] = '\0';
		numof_moves_org_b--;
	}
	//Finally, the compulsory movement: pb
	x++;
	//printf("line 79 | x = %d\n", x);
	list_moves[x] = malloc(sizeof(char)* 3);
	list_moves[x][0] = 'p';
	list_moves[x][1] = 'b';
	list_moves[x][2] = '\0';
	x++;
	list_moves[x] = malloc(sizeof(char)* 1);
	list_moves[x][0] = '\0';
	printf("\nLet's try to print it!\n");
	put_matrix(list_moves);
	return (list_moves);
}

/*void call2moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b)
{
	
}*/

/*DESCRIPTION
org_stack_b_2s_move function indicates which is the type of movement the 
travelling number will need to organise b stack.
____________________________________________________________________________*/
char *org_stack_b_2s_move (int *stack_b, int len_b, int index_ns)
{
	char *move_type;
	
	printf("line 23 | len_b = %d\n", len_b);
	printf("index_ns = %d\n", index_ns);
	//printf("call2moves.c line 88 | index_ns = %d\n", index_ns);
	if (len_b == 2)
		//No movement needed
	if (index_ns < (len_b / 2))
		move_type = "rrb";
	if (index_ns >= (len_b / 2))
		move_type = "rb";
	//printf("org_stack_b | index_ns = %d | numof_moves = %d\n", index_ns, numof_moves);
	//printf("move_type_org_b_2s_move = %s\n", move_type);
	return (move_type);
}

/*DESCRIPTION
top_stack_choose_move function indicates which is the type of movement the 
travelling number will need to get to the top of the stack.
--------------------------------------------------------------------------*/
char *top_stack_2s_move (int len, int index)
{
	char *move_type;

	if (index >= len)
	{
		write(1, "Error: accessing to number of stack with this index\n", 52);
		return (0);
	}
	if (index == (len - 1))
		//No movement needed
	if (index == (len - 2))
		move_type = "sa";
	if (index < (len / 2)) //este código también contempla el caso de index = 1 y el rtdo es el mismo, pero el move a hacer no.
		move_type = "ra";
	if (index >= (len / 2) && index != len)
		move_type = "rra";
	return (move_type);
}

int	*which_moves(int *stack_a, int *stack_b, int len_a, int len_b, int index_travel_nb)
{
	int travel_nb;
	int numof_moves_top_stack;
	int numof_moves_org_b;
	char *move_type_top_stack;
	char *move_type_org_b;

	travel_nb = stack_a[index_travel_nb];
	//travel_nb = 10;
	printf("travel_nb = %d\n", travel_nb);
	printf("index_travel_nb = %d\n", index_travel_nb);
	numof_moves_top_stack = top_stack (len_a, index_travel_nb);
	move_type_top_stack = top_stack_2s_move(len_a, index_travel_nb);
	numof_moves_org_b = org_stack_b (stack_b, len_b, index_next_smallest(stack_b, len_b, stack_a[index_travel_nb]));
	move_type_org_b = org_stack_b_2s_move (stack_b, len_b, index_next_smallest(stack_b, len_b, stack_a[index_travel_nb]));

	check_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);
	printf("numof_moves_top_stack = %d\n", numof_moves_top_stack);
	printf("move_type_top_stack = %s\n", move_type_top_stack);
	printf("numof_moves_org_b = %d\n", numof_moves_org_b);
	printf("move_type_org_b = %s\n", move_type_org_b);
	list_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);

	/*printf("ORG B:\n");
	printf("number = %d\n", numof_moves_org_b);
	printf("move type = %s", move_type_org_b);*/
	return (0);
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

    //Checking BEFORE:
	call2moves(stack_a, stack_b, 3);
	return (0);
}*/