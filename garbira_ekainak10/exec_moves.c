/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:30:41 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/11 15:34:01 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//antiguamente llamaba a este file "call2moves.c" en una versión anterior a crear esta carpeta
#include "push_swap.h"


/*DESCRIPTION:
decide_move_both_stacks function calls to moves and writes them. We use decide_move_both_stacks for movements 
related to stack_b. 

Explanation: 
We had to divide the function due to the number of lines, and decided to separate it the following
way: stack_a moves (decide_move_stack_a), then stack_b moves (decide_move_stack_b), and finally pa and pb, 
(decide_move_both_stacks) which involve both of the stacks.
-------------------------------------------------------------------*/
void decide_move_both_stacks(char *move_type, int **stack_a, int *len_a, int **stack_b, int *len_b)
{
    printf("exec_moves.c | line 28 | AQUÍ TAMBIÉ HA LLLEGAOOO\n");
    if(ft_strcmp(move_type, "pa") == 0) //??????????????????????????????
    {
        push(stack_b, len_b, stack_a, len_a);//call to the movement
        write(1, "pa\n", 3);//print the move_type
    }
    else if(ft_strcmp(move_type, "pb") == 0)
    {
        push(stack_a, len_a, stack_b, len_b);//call to the movement //////¿¿¿¿¿¿¿¿????????????
        write(1, "pb\n", 3);//print the move_type
        //printf("line 38\n");
        //put_arr(stack_b, len_b);
    }
}

/*DESCRIPTION:
decide_move_stack_b function calls to moves and writes them. We use decide_move_stack_b for movements 
related to stack_b. 

Explanation: 
We had to divide the function due to the number of lines, and decided to separate it the following
way: stack_a moves (decide_move_stack_a), then stack_b moves (decide_move_stack_b), and finally pa and pb, 
which involve both of the stacks.
-------------------------------------------------------------------*/
void decide_move_stack_b(char *move_type, int **stack_b, int *len_b) //cambiaré el prototipo a int *decide_move, porque como lo utilizaré para llamar a los movimientos, voy a querer recibir los stacks modificados.
{
    printf("\nESTAMOS DENTRO DE DECIDE_MOVE: stack A\n");
    //put_str(move_type);
    if(ft_strcmp(move_type, "sb") == 0)
    {
        swap(stack_b, *len_b);//call to the movement
        //write(1, "sb\n", 3);//print the move_type
    }
    else if(ft_strcmp(move_type, "rb") == 0)
    {
        //printf("line 66 | sí que está aquí dentro\n");
        rotate(stack_b, *len_b);//call to the movement
        write(1, "rb\n", 3);//print the move_type
    }
    else if(ft_strcmp(move_type, "rrb") == 0)
    {
        reverse_rotate(stack_b, *len_b);//call to the movement
        write(1, "rrb\n", 4);//print the move_type
    }
}

/*DESCRIPTION:
decide_move_stack_a function calls to moves and writes them. We use decide_move_stack_a for movements 
related to stack_a. 

Explanation: 
We had to divide the function due to the number of lines, and decided to separate it the following
way: stack_a moves (decide_move_stack_a), then stack_b moves, and finally pa and pb, which involve 
both of the stacks.
-------------------------------------------------------------------*/
void decide_move_stack_a(char *move_type, int **stack_a, int *len_a) //cambiaré el prototipo a int *decide_move, porque como lo utilizaré para llamar a los movimientos, voy a querer recibir los stacks modificados.
{
    printf("\nESTAMOS DENTRO DE DECIDE_MOVE: stack B\n");
    //put_str(move_type);
    if(ft_strcmp(move_type, "sa") == 0)
    {
        swap(stack_a, *len_a);//call to the movement
        write(1, "sa\n", 3);//print the move_type
    }
    else if(ft_strcmp(move_type, "ra") == 0)
    {
        rotate(stack_a, *len_a);//call to the movement
        write(1, "ra\n", 3);//print the move_type
    }
    else if(ft_strcmp(move_type, "rra") == 0)
    {
        reverse_rotate(stack_a, *len_a);//call to the movement
        write(1, "rra\n", 4);//print the move_type
    }
}

//después, pondré que devuelta int * para que devuelva el stack
void call2moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b, int **stack_a, int *len_a, int **stack_b, int *len_b)
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
        decide_move_stack_a(move_type_top_stack, stack_a, len_a); //stack_a sí va a cambiar, pero len_a no.
        numof_moves_top_stack--;
    }
    //call2moves_ ORGANISE B
    while(numof_moves_org_b > 0)
    {
        printf("ORG_B | line 82 | move_type_org_b:\n ");
        put_str(move_type_org_b);
        printf("\n");
        decide_move_stack_b(move_type_org_b, stack_b, len_b); //stack_b sí va a cambiar, pero len_b no.
        numof_moves_org_b--;
    }
    //printf("call2moves.c | line 135:\n");
    //put_2stacks(stack_a, len_a, stack_b, len_b);
    //call2: pb
    printf("exec_moves.c | line 132 | POR AQUÍ SÍ QUE PASA\n");
    decide_move_both_stacks("pb", stack_a, len_a, stack_b, len_b);
    //push(&stack_a, &len_a, &stack_b, &len_b);
    //put_arr(stack_a, (len_a - 1));
    //push_checkdst(stack_a, stack_b, len_a, len_b);
    //put_2stacks(stack_a, len_a, stack_b, len_b);
    //decide_move_both_stacks("pb", stack_a, len_a, stack_b, len_b);
}

/*DESCRIPTION
org_stack_b_2s_move function indicates which is the type of movement the
travelling number will need to organise b stack: "rb" or "rrb".
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
travelling number will need to get to the top of the stack: "sa", "ra" or "rra".
------------------------------------------------------------------------------*/
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

int *which_moves(int **stack_a, int *len_a, int **stack_b, int *len_b, int index_travel_nb)
{
    int		numof_moves_top_stack;
    int		numof_moves_org_b;
    char	*move_type_top_stack;
    char	*move_type_org_b;
    int		index_top_b;

    printf("exec_moves.c | line 27 | index_travel_nb = %d\n", index_travel_nb);
    numof_moves_top_stack = top_stack (*len_a, index_travel_nb);
    move_type_top_stack = top_stack_2s_move(*len_a, index_travel_nb);
    index_top_b = org_stack_b_1 (*stack_b, *len_b, *stack_a[index_travel_nb]);
	printf("exec_moves.c | line 204 | index_top_b = %d\n", index_top_b);
    numof_moves_org_b = org_stack_b_2 (*stack_b, *len_b, index_top_b);
    move_type_org_b = org_stack_b_2s_move (*stack_b, *len_b, index_top_b);
    //printf("exec_moves.c | line 206 | which_moves function checkers:\n");
    //check_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);
    //printf("Before:\n");
    //put_2stacks(stack_a, len_a, stack_b, len_b);
    call2moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b, stack_a, len_a, stack_b, len_b);
    //list_moves(numof_moves_top_stack, move_type_top_stack, numof_moves_org_b, move_type_org_b);


    /*printf("ORG B:\n");
    printf("number = %d\n", numof_moves_org_b);
    printf("move type = %s", move_type_org_b);*/
    return (0);
}