/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:41:51 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/12 19:41:54 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//file: main.c
int main(int argc, char **argv);

//file: push_swap.c
int	push_swap(int argc, char **argv);

//file: check_errors.c
int	ft_duplicate (int *arr, int len);
int next_position_with_int (char **argv, int x, int y, int counter_previous, int keep_len_arg);
char *fill_str(char **argv, int x, int y, char *str, int counter);
int *fill_stack (int *list_pre_checker2, int argc, char **argv);
int numof_int(int argc, char **argv);
int checker_last(int argc, char **argv);
int	checker_1(int argc, char **argv);
int checkers_index (int argc, char **argv);

//file: utils.c
void check_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b);
int	numof_digits(char **argv, int x, int y, int len_arg);
int ft_isdigit(char c);
int ft_strcmp (const char *str1, const char *str2);

//void put_matrix (char **list_moves);
int	atoi2(char *str);
int ft_strlen (char *str);
void put_str(char *str);
void put_2stacks (int *stack_a, int len_a, int *stack_b, int len_b);
void put_arr(int *stack, int len);

//file: moves.c
void    push(int **stack_src, int *len_src, int **stack_dst, int *len_dst);
void    reverse_rotate(int **stack, int len);
void    rotate(int **stack, int len);
void    swap(int **stack, int len);

//file: get_travel_nb.c
int ft_index_biggest (int *stack_b, int len_b);
int ft_index_next_smallest (int *stack_b, int len_b, int travelling_nb);
int	org_stack_b_2 (int *stack_b, int len_b, int index_top_stack);
int org_stack_b_1 (int *stack_b, int len_b, int travel_nb);
int top_stack (int len, int index);
int sum_moves(int *stack_a, int index, int *stack_b, int len_a, int len_b);
int get_cheapest_nb(int *stack_a, int len_a, int *stack_b, int len_b);

//file: exec_moves.c
void decide_move_both_stacks(char *move_type, int **stack_a, int *len_a, int **stack_b, int *len_b);
void decide_move_stack_b(char *move_type, int **stack_b, int *len_b);
void decide_move_stack_a(char *move_type, int **stack_a, int *len_a); 
void call2moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b, int **stack_a, int *len_a, int **stack_b, int *len_b);
char *org_stack_b_2s_move (int *stack_b, int len_b, int index_top_b);
char *top_stack_2s_move (int len, int index);
int *which_moves(int **stack_a, int *len_a, int **stack_b, int *len_b, int index_travel_nb);
