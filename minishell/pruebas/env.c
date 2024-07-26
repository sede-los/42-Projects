#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int i;

	i = 0;
    while(envp[i] != NULL)
	{
        printf("Variable de entorno numero %d: %s\n", i, envp[i]);
		i++;
    }

    return 0;
}