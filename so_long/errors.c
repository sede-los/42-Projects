/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:51:49 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/02 21:16:45 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_printf("Error 0. Numero de argumentos erroneo\n");
	else if (error == 1)
		ft_printf("Error 1. Error al leer el mapa\n");
	else if (error == 2)
		ft_printf("Error 2. Mapa no valido, el mapa debe ser rectangular\n");
	else if (error == 3)
		ft_printf("Error 3. Caracteres invalidos\n");
	else if (error == 4)
		ft_printf("Error 4. Error de asignación de memoria\n");
	else if (error == 5)
		ft_printf("Error 5. Numero de jugadores y/o salidas incorrecto\n");
	else if (error == 6)
		ft_printf("Error 6. Extensión del mapa no valida\n");
	else if (error == 7)
		ft_printf("Error 7. Ruta del mapa no valida\n");
	else if (error == 8)
		ft_printf("Error 8. Dimensiones del mapa maximas 35x35\n");
	exit(-1);
}

void	ft_error_free(int error, t_vars *vars)
{
	if (error == 9)
	{
		ft_printf("Error 9. Bordes del mapa no validos\n");
		free_matrix(vars->matrix, vars);
	}
	exit(-1);
}
