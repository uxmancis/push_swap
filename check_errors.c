/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:27:58 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/28 12:29:06 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


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


void    put_arr(int *stack, int len)
{
    int i;


    i = 0;
    while (len > 0)
    {
        printf("stack[%d] = %d\n", i, stack[i]);
        len--;
        i++;
    }
}


void fill_str(char **argv, int x, int y, char **str)
{
    int i;
   
    i = 0;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    /*while(argv[x][y] != ' ')
    {
        printf("hemen gaude\n");
        *str[i] = argv[x][y];
        i++;
        x++;
        y++;
    }*/
    argv[x][y] = '\0';
}


int numof_digits(char **argv, int x, int y)
{
    int counter;
   
    counter = 0;
    while(argv[x][y] != ' ')
    {
        printf("ya\n");
        counter++;
        y++;
    }
    return (counter);
}


int atoi2(char *str)
{
    int sign;
    int i;
    int result;
   
    i = 0;
    sign = 1;
    if(str[i] == '-')
        sign = -1;
    i++;


    result = 0;
    while(str[i] != '\0')
    {
        result = result*10 + (str[i] - 48);
    }
    return (result);
}


/*DESCRIPTION:
fill_stack function updates list_pre_checker2 by filling it with values
-----------------------------------------------------------------*/
void fill_stack (int **list_pre_checker2, int argc, char **argv)
{
    //int *stack_a;
    int x;
    int y;
    int a;
    int b;
    char *str;
    int counter;
    int m;


    printf("kaixo kaixo estamos en fill_stack\n");
   
    x = 1;
    a = 0;
    m = 0;
    printf("argc = %d\n", argc);
    while(x < argc)
    {
        printf("1ST BUCLE IN\n");
        y = 0;
        while(argv[x][y] != '\0' ) //1. siempre primero dentro del mismo argumento
        {
            //printf("hellowis\n");
            if(argv[x][y] != ' ')
            {
                counter = numof_digits(argv, x, y);
                str = malloc(sizeof(char) * (counter + 1)); //+1 = `para el final nulo
                fill_str(argv, x, y, &str);
                printf("antes de atoi2, char *str = %s\n", str);
                *list_pre_checker2[m] = atoi(str);
                free (str);
                printf("JAJA counter = %d\n", counter);
            }
            m++;
            y++;
        }
        x++;
    }
}


/*DESCRIPTION:
checker_2 makes sure that there are no duplicated numbers along the arguments.
It returns error(1) or not error(0) after analysing arguments.
How?
1. Convert arguments in integers of an array
    1.0 counts how many integers are among arguments. Variable used: counter
    1.1 allocates "counter" size memory for int *stack_a with malloc.
    1.1 splits numbers of arguments through identifying spaces. Every space = split!
    1.2 each number = 1 position of array as integer
2. Compares integers (is there any value repeated? YES/NO)


//para que entre aquí ya solo tienen que ser los siguientes: (checker_1)
- dígitos
- espacios
- negativos


1: error found
0: NO error found, OK!
---------------------------------------------------------------------------*/
int checker_2(int argc, char **argv)
{
    int x;
    int y;
    int counter;
    int *list_pre_checker2;
    int len_arg;


    x = 1;
    counter = 0;
    printf("argc = %d |||||||| and x = %d\n", argc,x);
    y = 0;
    while(x < argc)
    {
        printf("yes\n");
        //y = 0;
        len_arg = ft_strlen(argv[x]);
        while(argv[x][y] != '\0' ) //1. siempre primero dentro del mismo argumento
        {
            //printf("hellowis\n");
            if(argv[x][y] != ' ')
            {
                counter++; //en cuanto encuentre algo distinto al espacio (negativo o digito), sumar counter
                while(argv[x][y] != ' ')
                    y++;
                printf("counter = %d\n", counter);
            }
        y++;
        }
        x++;
    }
    printf("counter FINALLY = %d\n", counter);
    list_pre_checker2 = malloc(sizeof(int)*counter);
    //printf("kaixo estamos aquí\n");
    fill_stack(&list_pre_checker2, argc, argv); //así rellenenan los números en cada posición del array list_pre_checker_2. Si no hay duplicados, este se convertirá en el stack_a. En caso contrario, error. Le pasamos la dirección de list
    printf("list_pre_checker2: ");
    put_arr(list_pre_checker2, counter);
    return (0); //a boleo oingoz   
}
   
    /*x = 1;
    while(x < argc)
    {
        y = 0;
        a = 0;
        b = 0;
        while(argv[x][y] != '\0') //esto se cierra en cada argumento
        {
            while(argv[x][y] == ' ') //cuando hay espacios, palanteee no nos interesa
                y++;
            a = 0; //una vez sale del bucle de espacios y se encuentre con un dígito / signo negativo,
            while(argv[x][y] != ' ') //mientras que no sea un espacio, todo eso, hasta encontrar el siguiente espacio (o que termine el argumento) porfa mételo en el primer argumento de nuestra lista de strings.
            {
                list_nums[a][b] = argv[x][y];
                y++;
                b++;
            }
            a++;
        }
        x++;
    }
    a = 0;
    b = 0;
    while(x > 0)
    {
        printf("*argv[%d] = %s\n", a, *argv[a]);
    }
}


DESCRIPTION:
checker_1 makes sure that only digits (0-9), space ' ' and negative sign '-'
are found along the arguments and returns a integer indicating whether if
the error has been found or not.
1: error found
0: NO error found, OK!
---------------------------------------------------------------------------*/
int checker_1(int argc, char **argv)
{
    int x;
    int y;


    x = 1;
    y = 0;


    while(x < argc)
    {
        y = 0;
        while(argv[x][y] != '\0')
        {
            if((argv[x][y] >= '0' && argv[x][y] <= '9') || argv[x][y] == (char)32 || argv[x][y] == '-')
            {
                //printf("yes\n");
                y++;
            }
            else
            {
                printf("x = %d\ny = %d\n", x, y);
                return (1);
            }
        }
        x++;
    }
    return (0);
}


/*DESCRIPTION:
argc (argument count): number of arguments (integer)
argv (argument vector): array of strings


//luego a esta función main le cambiaré el nombre a check_errors y lo llamaré desde mi push_swap


errores que quiero chequear:
1. solo números, espacios y signos negativos
2. después de negativo, solo números, si no error
3.
--------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    int rtdo_checker_1;
    int rtdo_checker_2;
    int rtdo_checker_3;


    //rtdo_checker_1 = checker_1(argc, argv);
    //printf("Checker_1: %d\n", rtdo_checker_1);


    rtdo_checker_2 = checker_2(argc, argv);
    printf("Checker_1: %d\n", rtdo_checker_1);
    return (0);
}