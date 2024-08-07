/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:36 by sergio            #+#    #+#             */
/*   Updated: 2024/08/07 12:47:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

//int mails = 0;
pthread_mutex_t mutex;
void *routine( void *arg)
{	
	int *mails;

	mails = (int *)arg;
	for(int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		(*mails)++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	int mails;
	pthread_t t1;
	pthread_t t2;

	mails = 0;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, &routine, &mails);
	pthread_create(&t2, NULL, &routine, &mails);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("Numbers of mails: %d\n", mails);
	return (0);
}