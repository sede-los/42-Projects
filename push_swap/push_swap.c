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
    //pruebas - borrar
    while(a)
    {
        ft_printf("%i\n", a->nbr);
        a = a->next;
    }
}