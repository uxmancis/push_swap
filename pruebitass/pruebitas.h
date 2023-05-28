/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:52:51 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/15 18:53:02 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct bothstacks
{
	int *s_src;
	int *s_dst;
}   t_both;

//file: pruebitas10_structures.c
void put_struct (struct Bothstacks new, int new_len_src, int new_len_dst);
void put_2stacks (int *stack_a, int len_a, int *stack_b, int len_b);
struct Bothstacks push(int *stack_src, int *stack_dst, int len_src, int len_dst);