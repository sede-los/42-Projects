/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:15:01 by sede-los          #+#    #+#             */
/*   Updated: 2024/06/12 02:15:03 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

volatile sig_atomic_t	g_confirmation_received = 0;

void	ft_client_error(int error)
{
	if (error == 0)
	{
		ft_printf("Error. Uso: client <PID del servidor> <string>\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 1)
	{
		ft_printf("Error al manejar SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		ft_printf("Error al manejar SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
	exit(-1);
}

void	confirmation_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		g_confirmation_received = 1;
	}
	else if (signal == SIGUSR2)
	{
		g_confirmation_received = 1;
		ft_printf("Mensaje enviado y recibido con exito\n");
	}
}

void	send_byte(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i++;
		while (!g_confirmation_received)
			pause();
		g_confirmation_received = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	const char			*message;
	struct sigaction	sa;

	if (argc != 3)
		ft_client_error(0);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = &confirmation_handler;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_client_error(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_client_error(2);
	while (*message)
	{
		send_byte(server_pid, *message);
		message++;
	}
	send_byte(server_pid, '\0');
	return (0);
}
