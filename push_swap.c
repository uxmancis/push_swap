/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:23:16 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/28 12:12:39 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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

int	*push_swap(int *stack_a, int *stack_b, int *len_a, int *len_b)
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