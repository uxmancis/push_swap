/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call2moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:47:45 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/06 20:25:13 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


/*
It will include the following move-calling types depending on the purpose/objective to get


- 1st call2moves: put "travelling number" on top of stack A
- 2nd call2moves: put stack B ready to receive the travelling number in correct position
- 3rd call2moves: pb (travelling)
- 4rd call2moves: put stack B numbers back in stack A (pa)*/




/*DESCRIPTION
org_stack_b function returns the number of movements (rotate or reverse rotate)
stack_b needs in order to be ready/prepared to receive number from stack_a by pb
movement on its top


We will call org_stack_b when stack_b needs min. 1 movement in order to be ready.
Before calling org_stack_b, we will have checked that the travelling number
from stack a is neither higher than the highest number in stack b, nor smaller
than the smallest number in stack b.
· next_smallest: represents the highest number in stack b among the ones that are
smaller than the travelling number




By now: index_next_smallest function returns the index of the number in stack b which is the
highest among the numbers in stack b that are smaller than the travelling number
____________________________________________________________________________*/
int index_next_smallest (int *stack_b, int len_b, int travelling_nb)
{
   int keep_len_b;
   int i;
   int next_smallest;
   int index;


	put_arr(stack_b);
//    printf("stack_b[0] = %d\n", stack_b[0]);
//    printf("stack_b[1] = %d\n", stack_b[1]);
//    printf("stack_b[2] = %d\n", stack_b[2]);
//    printf("stack_b[3] = %d\n", stack_b[3]);
//    printf("stack_b[4] = %d\n", stack_b[4]);
//    printf("stack_b[5] = %d\n", stack_b[5]);
//    printf("stack_b[6] = %d\n", stack_b[6]);
   keep_len_b = len_b;
   next_smallest = 0;
   i= 0;
   while (len_b > 0)
   {
       if (stack_b[i] < travelling_nb)
       {
           if (stack_b[i] > next_smallest)
           {
               next_smallest = stack_b[i];
           }
       }
       i++;
       len_b--;
   }
   index = 0;
   while (keep_len_b > 0)
   {
       if (stack_b[index] == next_smallest)
           return (index);
       keep_len_b--;
       index++;
   }
   return(0);
}


/*DESCRIPTION
org_stack_b function returns the number of movements it takes to stack b to get ready
to receive travelling number from stack a
____________________________________________________________________________*/
int org_stack_b (int *stack_b, int len_b, int index_ns)
{
   int numof_moves;
  
   printf("call2moves.c line 88 | index_ns = %d\n", index_ns);
   if (len_b == 2) //Before making number travel
   {
       numof_moves = 0;
       return (numof_moves);
   }
   if (index_ns < (len_b / 2))
   {
       numof_moves = (index_ns + 1);
       return(numof_moves);
   }
   if (index_ns >= (len_b / 2))
   {
       numof_moves = (len_b - index_ns - 1);
       return(numof_moves);
   }
   return(0);
}


/*DESCRIPTION:
top_stack returns the minimum number of movements (swap, rotate or reverse rotate)
a number of a stack needs to get to the top of the stack (last position in array)


· len = len of stack
· index = position in stack of the number which numof_moves to get to the top of the stack
we want to analyse.
-----------------------------------------------------------------------------*/
int top_stack (int len, int index)
{
   int numof_moves;
  
   if (index >= len)
   {
       write(1, "Error: accessing to number of stack with this index\n", 52);
       return(0);
   }
   if (index == 1)
       numof_moves = 1; //swap 1 vez
   if (index <= (len / 2)) //este código también contempla el caso de index = 1 y el rtdo es el mismo, pero el move a hacer no.
       numof_moves = index; //rotate n veces
   if (index > (len / 2))
       numof_moves = (len - index); // reverse rotate n veces
   return(numof_moves);
}


/*DESCRIPTION:
cheapest_top_stack function tells us which is the number of stack A which needs the least
number of movements to get to the top of the stack.
How? Creates an array of integers with the number of movements needed to get to the top
   keep_len = len;
   keep_len_2 = len;
   arr1_numof_moves = malloc(sizeof(int) * len);
   i = 0;
   while (len > 0)
   {  
       arr1_numof_moves[i] = top_stack(keep_len, i);
       i++;
       len--;
   }


   printf("line 157 arr1_numof_moves[0] = %d\n", arr1_numof_moves[0]);
   printf("line 157 arr1_numof_moves[1] = %d\n", arr1_numof_moves[1]);
   printf("line 157 arr1_numof_moves[2] = %d\n", arr1_numof_moves[2]);
   printf("l
of the stack.
-----------------------------------------------------------------------------*/
int cheapest_top_stack (int *stack, int len)
{
   int *arr1_numof_moves;
   int i;
   int keep_len;
   int smallest_index;
   int keep_len_2;
//ine 157 arr1_numof_moves[3] = %d\n", arr1_numof_moves[3]);
   //printf("line 157 arr1_numof_moves[4] = %d\n", arr1_numof_moves[4]);

   smallest_index = 0;
   while (keep_len_2 > 0)
   {
       if (arr1_numof_moves[i] < smallest_index)
           smallest_index = arr1_numof_moves[i];
       i++;
       keep_len_2--;
   }
   printf("smalles_index = %d\n", smallest_index);
   //return (arr1_numof_moves[smallest_index]);
   return(0);
}


int *call2moves(int *stack_a, int *stack_b, int len_a, int len_b)
{
   int *result_stack_a;
   int *result_stack_b;


   result_stack_a = malloc(sizeof(int)*1000);
   result_stack_b = malloc(sizeof(int)*1000);
   //Checking that moves work:
   //result_stack_a = swap(stack_a, len_a);
   //result_stack_a = reverse_rotate(stack_a, len_a);
   //result_stack_a = reverse_rotate(stack_a, len_a);
   return (result_stack_a);
}



