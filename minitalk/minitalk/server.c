/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:46:33 by sede-los          #+#    #+#             */
/*   Updated: 2024/06/12 00:46:39 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

volatile sig_atomic_t	g_received_data = 0;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int		bit_count = 0;
	static pid_t	client_pid = 0;

	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		g_received_data |= (0 << bit_count);
	else if (signal == SIGUSR2)
		g_received_data |= (1 << bit_count);
	bit_count++;
	kill(client_pid, SIGUSR1);
	if (bit_count == 8)
	{
		if (g_received_data == '\0')
		{
			kill(client_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
		{
			ft_printf("%c", g_received_data);
			fflush(stdout);
		}
		bit_count = 0;
		g_received_data = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Servidor iniciado. PID: [%d]\n", getpid());
	ft_printf("\n---------------Área de Impresión--------------\n\n");
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigfillset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error al manejar SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error al manejar SIGUSR2");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
