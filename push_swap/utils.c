/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:09:44 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/18 00:09:47 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_index(t_stack *a, int nbr)
{
    int i;

    i = 0;
    while(a->nbr != nbr)
    {
        i++;
        a = a->next;
    }
    a->index = 0;
    return (i);
}

int ft_find_place_b(t_stack *stack_b, int nbr_push)
{
    int i;
    t_stack *tmp;
    ft_printf("prueba\n"); //prueba - borrar
    i = 1;
    if (nbr_push > stack_b->nbr && nbr_push < ft_stacklast(stack_b)->nbr)
    {
        i = 0;
        ft_printf("prueba_2\n"); //borrar    
    }
    else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
        i = ft_find_index(stack_b, ft_max(stack_b));
    else
        tmp = stack_b->next;
        while(stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
        {
            i++;
            stack_b  = stack_b->next;
            tmp = stack_b->next;
        }
    return (i);
}

int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_stacklast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}