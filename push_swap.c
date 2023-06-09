/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:23:16 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/10 15:40:25 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION: 
numof_int functions returns the number of integers we will find along the arguments, 
which means, the len of our stack_a. 

In our case, we will also use this len for defining the size of stack_b.
------------------------------------------------------------------------------------*/
int numof_int2(int argc, char **argv)
{
	int	x;
	int	y;
	int	counter;
	int len_arg;

	x = 1;
    counter = 0;
    //printf("line 248 || argc = %d |||||||| and x = %d\n", argc, x);
    while(x < argc)
    {
        //printf("line 182 || x = %d\n", x);
        //printf("yes\n");
        //y = 0;
        len_arg = ft_strlen(argv[x]);
        //printf("line 188 || len_arg = %d\n", len_arg);
        y = 0;
        while(len_arg > 0) //1. siempre primero dentro del mismo argumento
        {
            //printf("hellowis\n");
            //printf("line 190 || x = %d || y = %d\n", x, y);
            if(argv[x][y] != ' ')
            {
                //printf("line 193                  || x = %d || y=%d || argv[x][y] = %c\n", x, y, argv[x][y]);
                counter++; //en cuanto encuentre algo distinto al espacio (negativo o digito), sumar counter
                while(argv[x][y] != ' ' && len_arg > 0)
                {
                    //printf("sartu da, x = %d eta y = %d eta len_arg = %d\n", x, y, len_arg);
                    y++;
                    len_arg--;
                }
                //printf("counter = %d\n", counter);
               
            }
            y++;
            len_arg--;
        }
        x++;
        printf("&&&&&& line 278 || kanpuan gare || counter lleva %d hemos estado en x = %d, y vamos a x = %d\n", counter, (x-1), x);
    }
    printf("---------------------------------->>>>>>>>>>>> counter FINALLY = %d\n", counter);
	return(counter);
}

int	push_swap(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	len_stack;

	//0. checkear todos los errores. Si hay alguno, imprimir error
	if (checkers_index (argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}	
	else
	{
		len_stack = numof_int2(argc, argv);
		stack_a = malloc(sizeof(int) * len_stack);
		stack_b = malloc(sizeof(int) * len_stack);
		fill_stack(&stack_a, argc, argv);
	}
	put_arr (stack_a, len_stack);
	put_arr (stack_b, len_stack);
}

/*ALGORITMO:
1. Chequear si stack_A está ya ordenado
    if YES --> no hacer nada. Devolverlo ya
    if NO --> empezar a trabajar
2. (esto no lo voy a hacer) Calcular cuánto de desordenado está
3. Empezar a ordenar pasando los números del stack A al stack B.
    3.1.- Pasar los valores de arriba del stack, random (los últimos 2 valores) del stack A al stack B
    3.2.- Tomar decisión: ¿Cuál será el próximo número a pasar? Calcular el "cheapest number"
            3.2.1.- Calcular el "cheapest number"
                - ¿Cuántos moves para llevarlo arriba del stack A (a última posición)?
                - ¿Cuántos moves para poner stack B ready para recibir nuevo valor?
                - + 1 (push b)
                - TOTAL ()
            3.2.2.- Comparar el total de los moves que requeriría cada número del stack A para pasarlo al B.
            3.2.3.- Elegir el que MENOS moves vaya a necesitar + pasarlo a la última posición del stack B (pb).

--------------------------------------*/
int	*letsgo(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	index_travel_nb;
	int	travel_nb;
	

	//1. get_travel_nb: Calculate the "cheapest number" = returns WHICH is the number that will travel from stack A to B
	index_travel_nb = get_cheapest_nb(stack_a, stack_b, len_a, len_b);
	travel_nb = stack_a[index_travel_nb];
	printf("TRAVELLING NUMBER WILL BE (after comparing among stack_a value options):\n");
	printf("push_swap.c | line 42 | index_travel_nb = %d | travel_nb = %d\n", index_travel_nb, travel_nb);
	//2. which_moves: numof_moves + move_type (1. top_stack, 2. org_b)
	which_moves(&stack_a, &stack_b, &len_a, &len_b, index_travel_nb);
	//call2moves.c > Movement instruction:
	//To see WHERE do we have to put travelling number in stack b
	return (stack_a);
}