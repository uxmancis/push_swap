/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:53:56 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/06 20:17:31 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //For variadic function: va_list, va_start, va_arg, va_end
# include <unistd.h>
# include <stdio.h>
# include <limits.h> //Includes INT_MIN and INT_MAX values
# include <stdlib.h> //Includes: malloc

//file: utils.c
void put_arr(int *stack);

//file: moves.c
int *push_checkdst(int *stack_src, int *stack_dst, int len_src, int len_dst);
int *push_checksrc(int *stack_src, int *stack_dst, int len_src, int len_dst);
int *reverse_rotate(int *stack, int len);
int *rotate(int *stack, int len);
int *swap(int *stack);

//file: call2moves.c
int index_next_smallest (int *stack_b, int len_b, int travelling_nb);
int org_stack_b (int *stack_b, int len_b, int index_ns);
int top_stack (int len, int index);
int cheapest_top_stack (int *stack, int len);
int *call2moves(int *stack_a, int *stack_b, int len_a, int len_b);


//file: push_swap.c
int *push_swap(int *stack_a, int *stack_b, int len_a, int len_b);


#endif


