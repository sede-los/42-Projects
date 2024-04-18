/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:57:56 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/17 18:02:27 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_stack
{
    long    nbr;
    long    index;
    struct s_stack *next;
    struct s_stack *prev;
}               t_stack;

t_stack     *ft_process(int argc, char **argv);
void        ft_error(void);
int         ft_atoi2(const char *str);
t_stack     *ft_new_stack(int content);
void	    ft_freestr(char **lst);
t_stack     *ft_stacklast(t_stack *stack);
void        ft_add_back(t_stack **stack,  t_stack *new_stack);
void	    ft_free(t_stack **lst);
int         ft_check_dup(t_stack *a);
int         ft_check_sorted(t_stack *a);
int         ft_find_index(t_stack *a, int nbr);
int         ft_min(t_stack *a);
int         ft_max(t_stack *a);
int         ft_stack_size(t_stack *stack);
int         ft_find_place_b(t_stack *stack_b, int nbr_push);
int	        ft_find_place_a(t_stack *stack_a, int nbr_push);
int	        ft_case_rarb(t_stack *a, t_stack *b, int c);
int	        ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int	        ft_case_rrarb(t_stack *a, t_stack *b, int c);
int	        ft_case_rarrb(t_stack *a, t_stack *b, int c);
int	        ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int	        ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int	        ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
t_stack     *ft_stacklast(t_stack *stack);
int         ft_rotate_type_ab(t_stack *a, t_stack *b);
int	        ft_rotate_type_ba(t_stack *a, t_stack *b);
void	    ft_ra(t_stack **a, int j);
void        ft_sa(t_stack **a, int j);
void	    ft_pa(t_stack **a, t_stack **b, int j);
void	    ft_rra(t_stack **a, int j);
void	    ft_ss(t_stack **a, t_stack **b, int j);
void	    ft_rr(t_stack **a, t_stack **b, int j);
void	    ft_rrr_sub(t_stack **b, int j);
void	    ft_rrr(t_stack **a, t_stack **b, int j);
void	    ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void	    ft_rrb(t_stack **b, int j);
void	    ft_rb(t_stack **b, int j);
void	    ft_sb(t_stack **b, int j);

#endif
