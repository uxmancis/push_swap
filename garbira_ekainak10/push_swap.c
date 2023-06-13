/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:42:32 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/13 20:23:29 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a2b (int **stack_a, int *len_stack_a, int **stack_b, int *len_stack_b)
{
	int	index_travel_nb;
	int	travel_nb;

	//1. Which number is gonna travel?
	index_travel_nb = get_cheapest_nb(*stack_a, *len_stack_a, *stack_b, *len_stack_b);
	travel_nb = *stack_a[index_travel_nb]; //no pillo todavía lo de * para dereference. Future issue
	printf("travel_nb = %d\n", travel_nb);
	//2. Make it travel! Check the name of the moves to be executed and carry them out!

	/*printf("TRAVELLING NUMBER WILL BE (after comparing among stack_a value options):\n");
	printf("push_swap.c | line 42 | index_travel_nb = %d | travel_nb = %d\n", index_travel_nb, travel_nb);*/
	//2. which_moves: numof_moves + move_type (1. top_stack, 2. org_b)
	which_moves(stack_a, len_stack_a, stack_b, len_stack_b, index_travel_nb);
	//which_moves(stack_a, len_stack_a, stack_b, len_stack_b, index_travel_nb);
	//call2moves.c > Movement instruction:
	//To see WHERE do we have to put travelling number in stack b
	//return (stack_a);
	//rotate(stack_b, *len_stack_b); //no entiendo muy bien por qué le tengo que quitar el * al stack_b y ponérselo al len_stack_b! jaja yo lo tenía al revés. chatgpt me lo ha explicado, pero todavía no lo veoo. Future issue
}

int	*sort_it(int *stack_a, int len_stack_a, int *stack_b, int len_stack_b) //se imprime aquí el BEFORE y el AFTER de los 2 stacks
{
	int keep_len_stack_a;
	int keep_len_stack_b;
	int index_biggest_in_stack_b;
	int i;
	int ind_b_ns;
	int numof_moves_org_b;
	char *move_type_org_b;
	int ind_ns;
	int travel_nb;
	int index_top_b;
	int keep_len_b;

	keep_len_stack_a = len_stack_a - 1 -2; //porque quiero que en el stack_a quede 1 número, so, quiero que los pb-s sean 1 menos que el len del stack_a. y luego le quito 2 más, por los 2 pb-s que hacemos nada más empezar. el -1 hay que mantenerlo sí o sí, porque no puedo pasar todos los númeross. porque, cuando se passa el úlltiimo es por descarte, y hace pb directamente, y lo descuaddra todo.
	printf("keep_len_stack_a = %d\n", keep_len_stack_a);
	//1. push_b x 2
	i = 2;
	while (i > 0) //2 times "pb", to start
	{
		decide_move_both_stacks("pb", &stack_a, &len_stack_a, &stack_b, &len_stack_b);
		i--;
	}
	printf("Before:\n");
	//put_2stacks (stack_a, len_stack, stack_b, len_stack);
	printf("stack_a:\n");
	put_arr (stack_a, len_stack_a);
	printf("stack_b:\n");
	put_arr (stack_b, len_stack_b);

	//2. n veces, todo el travelling (n = algo que ver con el len del stack_a)
	while (keep_len_stack_a > 0)
	{
		a2b(&stack_a, &len_stack_a, &stack_b, &len_stack_b);
		printf("After:\n");
		printf("stack_a:\n");
		put_arr (stack_a, len_stack_a);
		printf("stack_b:\n");
		put_arr (stack_b, len_stack_b);
		printf("\n----------------berrixe hasi, next movement: ----------\n");
		keep_len_stack_a--;
	}
	//3. cuando solo quede 1 last valor que passar, ya sabemoss cuál va a ser el travel_nb. Organizar b para recibirlo + pasarlo
	travel_nb = stack_a[0];
	index_top_b = org_stack_b_1 (stack_b, len_stack_b, travel_nb);
	numof_moves_org_b = org_stack_b_2 (stack_b, len_stack_b, index_top_b);
	move_type_org_b = org_stack_b_2s_move (stack_b, len_stack_b, index_top_b);
	call2moves(0, "sa", numof_moves_org_b, move_type_org_b, &stack_a, &len_stack_a, &stack_b, &len_stack_b);
	printf("FINALLY:\n");
	printf("stack_a:\n");
	put_arr (stack_a, len_stack_a);
	printf("stack_b:\n");
	put_arr (stack_b, len_stack_b);

	//4. Detectar cuál es el index biggests de todo el stack_b para ordenarlo
	index_biggest_in_stack_b = ft_index_biggest (stack_b, len_stack_b);
	index_top_b = index_biggest_in_stack_b;
	printf("index_top_b = %d\n", index_top_b);
	numof_moves_org_b = org_stack_b_2 (stack_b, len_stack_b, index_top_b);
	move_type_org_b = org_stack_b_2s_move (stack_b, len_stack_b, index_top_b);
	while (numof_moves_org_b > 0)
	{
		decide_move_stack_b(move_type_org_b, &stack_b, &len_stack_b);
		numof_moves_org_b--;
	}
	//call2moves(0, "sa", numof_moves_org_b, move_type_org_b, &stack_a, &len_stack_a, &stack_b, &len_stack_b);
	printf("BEFORE PAs de vuelta:\n");
	printf("stack_a:\n");
	put_arr (stack_a, len_stack_a);
	printf("stack_b:\n");
	put_arr (stack_b, len_stack_b);

	//5. Devolver pa-s a stack_a de vuelta tantas como len_stack_b veces
	printf("len_stack_b = %d\n", len_stack_b);
	keep_len_b = len_stack_b;
	while(keep_len_b > 0)
	{
		decide_move_both_stacks("pa", &stack_a, &len_stack_a, &stack_b, &len_stack_b);
		keep_len_b--;
	}
	printf("AFTER PAs de vuelta:\n");
	printf("stack_a:\n");
	put_arr (stack_a, len_stack_a);
	printf("stack_b:\n");
	put_arr (stack_b, len_stack_b);

	//printf("push_swap.c | line 75 | last value, stack_a[0] = %d\n", stack_a[0]);
	//ind_b_ns = index_next_smallest(stack_b, len_stack_b, stack_a[0]);
	//printf("push_swap.c | line 76 | ind_b_n = %d\n", ind_b_ns);
	//numof_moves_org_b = org_stack_b (stack_b, len_stack_b, index_next_smallest(stack_b, len_stack_b, stack_a[0]));
	//printf("push_swap.c | line 75 | numof_moves_org_b = %d\n", numof_moves_org_b);
	//move_type_org_b = org_stack_b_2s_move (stack_b, len_stack_b, index_next_smallest(stack_b, len_stack_b, stack_a[0]));
	//printf("push_swap.c | line 77 | move_type_org_b = %s\n", move_type_org_b);
	//call2moves(0, "sa", numof_moves_org_b, move_type_org_b, &stack_a, &len_stack_a, &stack_b, &len_stack_b);
	//push(&stack_a, &len_stack_a, &stack_b, &len_stack_b); //stack_src's len - 1, stack_dst's len + 1
	//decide_move_both_stacks("pb", &stack_a, &len_stack_a, &stack_b, &len_stack_b);
	/*keep_len_stack_b = len_stack_b;
	printf("line 79 | keep_len_stack_b = %d\n", keep_len_stack_b);
	while (keep_len_stack_b > 0)
	{
		decide_move_both_stacks("pa", &stack_b, &len_stack_b, &stack_a, &len_stack_a);
		keep_len_stack_b--;
	}*/
	return (0);
}

int	push_swap(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	len_stack_a;
	int len_stack_b;

	len_stack_b = 0;
	//0. checkear todos los errores. Si hay alguno, imprimir error
	if (checkers_index (argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}	
	else
	{
		len_stack_a = numof_int(argc, argv);
		stack_a = malloc(sizeof(int) * len_stack_a);
		stack_b = malloc(sizeof(int) * len_stack_b); //para pasarle los primeros 2 números de stack_a para empezar
		stack_a = fill_stack(stack_a, argc, argv);
	}
	sort_it(stack_a, len_stack_a, stack_b, len_stack_b);
	return (0);
}