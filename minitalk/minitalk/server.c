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

volatile sig_atomic_t received_data = 0;

void handle_signal(int signal, siginfo_t *info, void *context) {
	static int bit_count = 0;
	static pid_t client_pid = 0;

	if (client_pid == 0)
	{
		client_pid = info->si_pid;
	}

	if (signal == SIGUSR1)
		received_data |= (0 << bit_count);
	else if (signal == SIGUSR2)
        received_data |= (1 << bit_count);
	bit_count++;

	kill(client_pid, SIGUSR1);

	if (bit_count == 8)
	{
	ft_printf("%c", received_data);
	fflush(stdout);
	bit_count = 0;
	received_data = 0;
	}
}

int main(void)
{
	ft_printf("Servidor iniciado con PID: %d\n", getpid());

	struct sigaction sa;
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigfillset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1) {
		ft_printf("Error al manejar SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1) {
		ft_printf("Error al manejar SIGUSR2");
		exit(EXIT_FAILURE);
	}

	while (1) {
		pause();
	}

	return 0;
}