/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:13:26 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 18:15:19 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

t_stack  *process_quoted_string(char *str)
{
    t_stack *a;
    char    **tmp;
    int     i;
    int     nbr;

    a = NULL;
    i = 0;
    tmp = ft_split(str, 32);
    while(tmp[i])
    {
        nbr = ft_atoi2(tmp[i]);
        ft_add_back(&a, ft_new_stack(nbr));
        i++;
    }
    ft_freestr(tmp);
    free(tmp);
    return (a);
}

t_stack *ft_process(int argc, char **argv)
{
    t_stack *a;
    int     i;
    int     nbr;

    i = 1;
    a = NULL;
    if (argc < 2)
        ft_error();
    if (argc == 2)
        a = process_quoted_string(argv[1]);
    else
        while(i < argc)
        {
            nbr = ft_atoi2(argv[i]);
            ft_add_back(&a, ft_new_stack(nbr));
            i++;
        }
    return (a);
}