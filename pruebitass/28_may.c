/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28_may.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:29:56 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/28 18:37:32 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen (char *str)
{
    int len;


    len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return (len);
}

void put_str(char *str)
{
    int len;


    len = 0;
    while(str[len] != '\0')
    {
        write(1, &str[len], 1);
        len++;
    }
    write(1, "\n", 1);
}

int atoi2(char *str)
{
    int sign;
    int i;
    int result;
    int len_str;
   
    printf("atoi barruan gare\n");
    i = 0;
    sign = 1;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    /*printf("str[0] = %d\n", str[0]);
    printf("str[1] = %d\n", str[1]);
    printf("str[2] = %d\n", str[2]);
    printf("str[3] = %d\n", str[3]);*/
    len_str = ft_strlen(str);
    //printf("len_str = %d\n", ft_strlen(str));
    result = 0;
    while(len_str > 0)
    {
        //printf("str[%d] = %d\n", i, str[i]);
        result = result*10 + str[i];
        //printf("result (por ahora) = %d\n", result);
        len_str--;
        i++;
    }
    printf("line 49 | atoi result int = %d\n", result);
    return (result);
}

int fill_str(char **argv, int x, int y, char **str, int len)
{
    int index_str;
   
    index_str = 0;
    printf("line 70 fill_st arguments: x = %d || y = %d\n", x, y);
    while(argv[x][y] != ' ' && len > 0) //lo del len es para que no se pase del total de *argv[x]
    {
        printf("BEFORE (line 60) | x = %d | y = %d | i = %d\n", x, y, index_str);
        (*str)[index_str] = argv[x][y] - 48; //estas cosas raras de [y[0]] es porque paso la y commo puntero porque quiero que se actualice el valor. En consecuencia, para que la y sea un int, tengo que poner a y[0]
        printf("argv[%d][%d] = %c\n", x, y, argv[x][y]);
        printf("*str[%d] = %d\n", index_str, (*str)[index_str]);
        index_str++;
        //x++;
        y++;
        len--;
        //printf("AFTER (line 67) | x = %d | y = %d | i = %d\n", x, y, index_str);
    }
    (*str)[index_str] = '\0';
    return (y);
    //put_str(*str); //no sé por qué motivo no me lo imprime bien
}

int get_len_str(char **argv, int x, int y)
{
    int len_str;
   
    len_str = 0;
    while(argv[x][y] != ' ' && argv[x][y] != '\0')
    {
        printf("numof_digits function: calculando len_str para atoi\n");
        len_str++;
        y++;
    }
    return (len_str);
}

/*DESCRIPTION:
fill_stack function updates list_pre_checker2 by filling it with values
-----------------------------------------------------------------*/
void fill_stack (int **list_pre_checker_last, int argc, char **argv, int numof_int)
{
    //int *stack_a;
    int x;
    int y;
    int a;
    int b;
    char *str;
    int len_str;
    int m;
    int result;
    int *tmp_list;
    
    printf("numof_int (es decir, el espacio que tenemos para que 'm' exista = %d\n", numof_int);
    tmp_list = malloc(sizeof(int) *numof_int);
    printf("kaixo kaixo estamos en fill_stack\n");
    x = 1;
    a = 0;
    m = 0;
    printf("argc = %d\n", argc);
    while((argc - 1) > 0)
    {
        printf("1ST BUCLE IN\n");
        y = 0;
        //printf("line 126 | argv[1][0] = %c\n", argv[1][0]);
        while(argv[x][y] != '\0' ) //1. siempre primero dentro del mismo argumento
        {
            //printf("hellowis\n");
            //printf("line 129 | argv[1][0] = %c\n", argv[1][0]);
            if(argv[x][y] != ' ') //si es negativo o numero
            {
                len_str = get_len_str(argv, x, y);
                str = malloc(sizeof(char) * (len_str + 1)); //+1 = `para el final nulo
                printf("send arguments to fill_str: x = %d || y = %d || len_str = %d\n", x, y, len_str);
                y = fill_str(argv, x, y, &str, len_str); //utilizo esto para 1. actualizar los valores de str, pero también para recuperar de vuelta el número y
                printf("antes de atoi2, char *str:\n");
                //put_str(str); //no sé por qué no me lo imprime
                put_str(str); //hau gero kendu
                printf("argumento número 'm' = %d | El total es el counter\n", m);
                tmp_list[m] = atoi2(str);
                free (str);
                //printf("line 146 | len_str = %d\n", len_str);
            }
            printf("hey, vamonos para el próximo int dentro del mismo argumento! :)\n\n");
            m++;
            y++;
        }
        x++;
        argc--;
    }
    *list_pre_checker_last = tmp_list;
}

int checker_last(int argc, char **argv)
{
    int x;
    int y;
    int numof_int;
    int *list_pre_checker_last;
    int len_arg;


    x = 1;
    y = 0;
    numof_int = 0;
    //printf("argc = %d |||||||| x = %d ||||||||| y = %d ||||||||| counter = %d\n", argc, x, y, counter);
    while(x < argc) //argc > 1 izan behar da (que haya más argumentos que ./a.out). argc - x (la diferencia) = el número de argumentos distintos que se han pasado, en cada uno habrá n integers
    {
        //printf("yes\n");
        y = 0;
        len_arg = ft_strlen(argv[x]);
        while(len_arg > 0) //1. siempre primero dentro del mismo argumento, recórremelo hasta el final
        {
            //printf("hellowis\n");
            //y = 0;
            if(argv[x][y] != ' ')
            {
                numof_int++; //en cuanto encuentre algo distinto al espacio (negativo o digito), sumar counter
                //printf("x = %d |||| y = %d |||| counter = %d\n", x, y, counter);
                while(argv[x][y] != ' ' && argv[x][y] != '\0')
                {
                    //printf("y = %d\n", y);
                    y++;
                    if(argv[x][y] == '\0')
                        break;
                }
                //printf("counter = %d\n", counter);
            }
            if(argv[x][y] == '\0')
                break;
            y++;
            len_arg--;
        }
        x++;
    }
    printf("counter FINALLY (number of integers) = %d\n", numof_int);
    list_pre_checker_last = malloc(sizeof(int)*numof_int);
    printf("kaixo estamos aquí\n");
    fill_stack(&list_pre_checker_last, argc, argv, numof_int); //así rellenenan los números en cada posición del array list_pre_checker_2. Si no hay duplicados, este se convertirá en el stack_a. En caso contrario, error. Le pasamos la dirección de list
    //printf("list_pre_checker2: ");
    //put_arr(list_pre_checker2, counter);
    return (0); //a boleo oingoz   
}

int main(int argc, char **argv)
{
    int rtdo_checker_1;
    int rtdo_checker_last;
    int rtdo_checker_3;

    //printf("len_argv[2] = %d\n", ft_strlen(argv[2]));
    rtdo_checker_last = checker_last(argc, argv);
    //printf("Checker_1: %d\n", rtdo_checker_1);
    return (0);
}