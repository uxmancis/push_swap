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


int *push_swap(int *stack_a, int *stack_b, int len_a, int len_b)
{
   int *tester_stack;
   int result;
   int *arr2_numof_moves;
   int keep_len_b;
   int i;
   int ind_ns;
   int travelling_nb;
  
   keep_len_b = len_b;
   //decideTravelNum: Calculate the "cheapest number" = returns WHICH is the number that will travel from stack A to B
   //call2moves.c > Movement instruction:
  
   //To see WHERE do we have to put travelling number in stack b
   travelling_nb = cheapest_top_stack (stack_a, len_a);
   ind_ns = index_next_smallest (stack_b, len_b, travelling_nb);
   arr2_numof_moves = malloc(sizeof(int)*len_b);
   i = 0;
   while (len_b > 0)
   {
       arr2_numof_moves[i] = org_stack_b(stack_b, len_b, ind_ns);
       i++;
       len_b--;
   }
   printf("push_swap.c line 58 arr2_numof_moves[0] = %d\n", arr2_numof_moves[0]);
   printf("push_swap.c line 58 arr2_numof_moves[1] = %d\n", arr2_numof_moves[1]);
   printf("push_swap.c line 58 arr2_numof_moves[2] = %d\n", arr2_numof_moves[2]);
   printf("push_swap.c line 58 arr2_numof_moves[3] = %d\n", arr2_numof_moves[3]);
   printf("push_swap.c line 58 arr2_numof_moves[4] = %d\n", arr2_numof_moves[4]);
   printf("push_swap.c line 58 arr2_numof_moves[5] = %d\n", arr2_numof_moves[5]);
   printf("push_swap.c line 58 arr2_numof_moves[6] = %d\n", arr2_numof_moves[6]);
   result = cheapest_top_stack(stack_a, len_a);
   tester_stack = malloc(sizeof(int)*1000);
   tester_stack = call2moves(stack_a, stack_b, len_a, len_b);//Checking AFTER:
   printf("------------MOVES----------\n");
   printf("RESULT (chosen stack): \n");
   printf("tester_stack[0] = %d\n", tester_stack[0]);
   printf("tester_stack[1] = %d\n", tester_stack[1]);
   printf("tester_stack[2] = %d\n", tester_stack[2]);
   printf("tester_stack[3] = %d\n", tester_stack[3]);
   printf("tester_stack[4] = %d\n", tester_stack[4]);
   return(stack_a);
}
