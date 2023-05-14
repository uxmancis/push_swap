/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:53:56 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/14 14:27:21 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //For variadic function: va_list, va_start, va_arg, va_end
# include <unistd.h>
# include <stdio.h>
# include <limits.h> //Includes INT_MIN and INT_MAX values
# include <stdlib.h> //Includes: malloc

//file: main.c
void	check_before (int *stack_a, int *stack_b, int len_a, int len_b);
void check_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b);

//file: push_swap.c
int *push_swap(int *stack_a, int *stack_b, int len_a, int len_b);

//file: get_travel_nb.c
int index_next_smallest(int *stack_b, int len_b, int travelling_nb);
int org_stack_b(int *stack_b, int len_b, int index_ns);
int top_stack(int len, int index);
int sum_moves(int *stack_a, int index, int *stack_b, int len_a, int len_b);
int get_cheapest_nb(int *stack_a, int *stack_b, int len_a, int len_b);

//file: utils.c
int strcmp (const char *str1, const char *str2);

//int	    len_arr(int *stack);
void	put_arr(int *stack, int len);
void put_2stacks (int *stack_a, int len_a, int *stack_b, int len_b);
void put_str(char *str);
int ft_strlen (char *str);
void put_matrix (char **list_moves);

//file: moves.c
int	*push_checkdst(int *stack_src, int *stack_dst, int len_src, int len_dst);
int	*push_checksrc(int *stack_src, int *stack_dst, int len_src, int len_dst);
int	*reverse_rotate(int *stack, int len);
int	*rotate(int *stack, int len);
int	*swap(int *stack, int len);

//file: call2moves.c
int	*which_moves(int *stack_a, int *stack_b, int len_a, int len_b, int index_travel_nb);
char *top_stack_2s_move (int len, int index);
char *org_stack_b_2s_move (int *stack_b, int len_b, int index_ns);

#endif