/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:14:27 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/06 20:28:04 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int main(void)
{
   int *stack_a;
   int *stack_b;
   int len_a;
   int len_b;
   int i;
   int keep_len_a;
   int keep_len_b;


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
   keep_len_a = len_a;
   keep_len_b = len_b;
   printf("Before stack_a: ");
   i = 0;
   while (len_a > 0)
   {
       printf("%d", stack_a[i]);
       i++;
       len_a--;
   }
   printf("\n");
   printf("Before stack_b: ");
   i = 0;
   while (len_b > 0)
   {
       printf("%d", stack_b[i]);
       i++;
       len_b--;
   }
   printf("\n");
   push_swap(stack_a, stack_b, keep_len_a, keep_len_b);
   return (0);
}
