/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call2moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:47:45 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/15 07:10:24 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*char move_type(char *str) //Fuunciona perfect, pero por ahora no lo necesito.
{
	int i;
	char type; 

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == 'a' || str[i] == 'b')
		{
			if (str[i] == 'a')
			{
				type = 'a';
				return (type);
			}
			if (str[i] == 'b')
			{
				type = 'b';
				return (type);
			}
		}
		i++;
	}
	return (0);
}*/

// Structure defined outside of a function
structure 2stacks
{
	int *stack_a;
	int *stack_b;
}

struct 2stacks replace_values(int *stack_a, int *stack_b, int len_a, int len_b)
{
	struct 2stacks new;

	new.stack_a = malloc(sizeof(int) * (len_a - 1));
	new_stack_b = malloc(sizeof(int) * (len_b + 1));

	
}

void decide_move_both_stacks(char *move_type, int *stack_a, int len_a, int *stack_b, int len_b)
{
	if(strcmp(move_type, "pa") == 0) //??????????????????????????????
	{
		push_checksrc(stack_a, stack_b, len_a, len_b);//call to the movement
		write(1, "pa\n", 3);//print the move_type
	}
	else if(strcmp(move_type, "pb") == 0)
	{
		push_checksrc(stack_b, stack_a, len_b, len_a);//call to the movement //////¿¿¿¿¿¿¿¿????????????
		write(1, "pb\n", 3);//print the move_type
	}
}

int *decide_move_stack_b(char *move_type, int *stack_b, int len_b) //cambiaré el prototipo a int *decide_move, porque como lo utilizaré para llamar a los movimientos, voy a querer recibir los stacks modificados.
{
	printf("\nESTAMOS DENTRO DE DECIDE_MOVE: stack A\n");
	//put_str(move_type);
	if(strcmp(move_type, "sb") == 0)
	{
		stack_b = swap(stack_b, len_b);//call to the movement
		//write(1, "sb\n", 3);//print the move_type
	}
	else if(strcmp(move_type, "rb") == 0)
	{
		//printf("line 66 | sí que está aquí dentro\n");
		stack_b = rotate(stack_b, len_b);//call to the movement
		write(1, "rb\n", 3);//print the move_type
	}
	else if(strcmp(move_type, "rrb") == 0)
	{
		stack_b = reverse_rotate(stack_b, len_b);//call to the movement
		write(1, "rrb\n", 4);//print the move_type
	}
	return (stack_b);
}

int *decide_move_stack_a(char *move_type, int *stack_a, int len_a) //cambiaré el prototipo a int *decide_move, porque como lo utilizaré para llamar a los movimientos, voy a querer recibir los stacks modificados.
{
	printf("\nESTAMOS DENTRO DE DECIDE_MOVE: stack B\n");
	//put_str(move_type);
	if(strcmp(move_type, "sa") == 0)
	{
		stack_a = swap(stack_a, len_a);//call to the movement
		write(1, "sa\n", 3);//print the move_type
	}
	else if(strcmp(move_type, "ra") == 0)
	{
		stack_a = rotate(stack_a, len_a);//call to the movement
		write(1, "ra\n", 3);//print the move_type
	}
	else if(strcmp(move_type, "rra") == 0)
	{
		stack_a = reverse_rotate(stack_a, len_a);//call to the movement
		write(1, "rra\n", 4);//print the move_type
	}
	return (stack_a);
}

//después, pondré que devuelta int * para que devuelva el stack
void call2moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b, int *stack_a, int len_a, int *stack_b, int len_b)
{
	char *last_move;
	//char a_or_b; //'a' or 'b' type --> ya no lo necesito
	/*int len_move_type_top_stack;
	int len_move_type_org_b;
	
	len_move_type_top_stack = ft_strlen(move_type_top_stack);
	len_move_type_org_b = ft_strlen(move_type_org_b);*/
	last_move = "pb" ;
	//call2moves_ TOP STACK
	while (numof_moves_top_stack > 0)
	{
		printf("TOP_STACK\n");
		//put_str(move_type_top_stack);
		stack_a = decide_move_stack_a(move_type_top_stack, stack_a, len_a);
		numof_moves_top_stack--;
	}
	//call2moves_ ORGANISE B
	while(numof_moves_org_b > 0)
	{
		printf("ORG_B | line 82 | move_type_org_b:\n ");
		put_str(move_type_org_b);
		printf("\n");
		stack_b = decide_move_stack_b(move_type_org_b, stack_b, len_b);
		numof_moves_org_b--;
	}
	//printf("call2moves.c | line 135:\n");
	//put_2stacks(stack_a, len_a, stack_b, len_b);
	//call2: pb
	push_checksrc(stack_a, stack_b, len_a, len_b);
	
	//put_arr(stack_a, (len_a - 1));
	//push_checkdst(stack_a, stack_b, len_a, len_b);
	//put_2stacks(stack_a, len_a, stack_b, len_b);
	//decide_move_both_stacks("pb", stack_a, len_a, stack_b, len_b);
}

/*void read_moves (char **list_moves)
{
	int x;
	int y;
	int len;
	char *move;

	x = 0;
	while(list_moves[x][0] != '\0')
	{
		y = 0;
		while(list_moves[x][y] != '\0')
		{
			y++;
		}
		len = y;
		printf("len = %d\n", len);
		move = malloc(sizeof(char) * len);
		y = 0;
		while (len > 0)
		{
			move[y] = list_moves[x][y];
			len --;
		}
		//printf("ez\n");
		call2move(move);
		x++;
	}
}

DESCRIPTION
list_moves function pretends to store all the movements/instructions that our algorithm will use in order to sort 
the numbers. 
It is the result we will want to print in push_swap.*/
/*char **list_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b)
{
	char **list_moves;
	int len_move_type_top_stack;
	int len_move_type_org_b;
	int x;
	int y;

	len_move_type_top_stack = ft_strlen(move_type_top_stack);
	len_move_type_org_b = ft_strlen(move_type_org_b);
	//printf("len_move_type_top_stack = %d\n", len_move_type_top_stack);
	//printf("len_move_type_org_b = %d\n", len_move_type_org_b);

	list_moves = malloc(sizeof(char *) * (numof_moves_top_stack + numof_moves_org_b + 2)); //(top_stack) + (org_b) + 2 (pb, '\0')
	//First, top_stack list of moves:
	//printf("numof_moves_top_stack = %d\n", numof_moves_top_stack);
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
	//printf("numof_moves_org_b = %d\n", numof_moves_org_b);
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
	//put_matrix(list_moves);
	read_moves (list_moves);
	return (list_moves);
}*/

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
		move_type = "rb";
	if (index_ns >= (len_b / 2))
		move_type = "rrb";
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
		move_type = "rra";
	if (index >= (len / 2) && index != len)
		move_type = "ra";
	return (move_type);
}

int	*which_moves(int *stack_a, int *stack_b, int len_a, int len_b, int index_travel_nb)
{
	int		travel_nb;
	int		numof_moves_top_stack;
	int		numof_moves_org_b;
	char	*move_type_top_stack;
	char	*move_type_org_b;

	travel_nb = stack_a[index_travel_nb];
	//travel_nb = 10;
	printf("travel_nb = %d\n", travel_nb);
	printf("index_travel_nb = %d\n", index_travel_nb);
	numof_moves_top_stack = top_stack (len_a, index_travel_nb);
	move_type_top_stack = top_stack_2s_move(len_a, index_travel_nb);
	numof_moves_org_b = org_stack_b (stack_b, len_b, index_next_smallest(stack_b, len_b, stack_a[index_travel_nb]));
	move_type_org_b = org_stack_b_2s_move (stack_b, len_b, index_next_smallest(stack_b, len_b, stack_a[index_travel_nb]));
	printf("call2moves.c | line 260 | which_moves function checkers:\n");
	check_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);
	//printf("Before:\n");
	//put_2stacks(stack_a, len_a, stack_b, len_b);
	call2moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b, stack_a, len_a, stack_b, len_b);
	//list_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);

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