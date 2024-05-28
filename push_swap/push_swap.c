/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:09:32 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 18:09:35 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;

    a = ft_process(argc, argv);
    if (!a || ft_check_dup(a))
    {
        ft_free(&a);
        ft_error();
    }
    if (!ft_check_sorted(a))
    {
        ft_sort(&a);
    }
    //pruebas - borrar
    /*
    ft_printf("\n");
    while(a)
    {
        ft_printf("%i\n", a->nbr);
        a = a->next;
    }
    ft_free(&a);
    return (0);
    */
}