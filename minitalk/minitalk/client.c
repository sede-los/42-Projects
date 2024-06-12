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

volatile sig_atomic_t confirmation_received = 0;

void confirmation_handler(int signal) 
{
	if (signal == SIGUSR1) 
		confirmation_received = 1;
}

void send_byte(pid_t server_pid, char c)
{
	int i;

	i = 0;
	while(i < 8)
	{
		if (c & (1 << i)) {
            kill(server_pid, SIGUSR2);
        } else {
            kill(server_pid, SIGUSR1);
        }
		i++;
		while (!confirmation_received) {
            pause();
        }
        confirmation_received = 0;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error. Uso: %s <PID del servidor> <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pid_t server_pid = ft_atoi(argv[1]);
	const char *message = argv[2];

	struct sigaction sa;
	sa.sa_handler = &confirmation_handler;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1) {
		ft_printf("Error al manejar SIGUSR1");
		exit(EXIT_FAILURE);
	}

	while (*message)
	{
		send_byte(server_pid, *message);
		message++;
	}
	return 0;
}