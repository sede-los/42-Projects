#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct {
    int in;
    int out;
} t_mini;

int main(int ac, char **av, char **env) {
    t_mini mini;

    (void)ac;
    (void)av;
    (void)env;

    // Duplicate stdin and stdout
    mini.in = dup(STDIN_FILENO);
    if (mini.in == -1) {
        perror("dup stdin");
        return 1;
    }

    mini.out = dup(STDOUT_FILENO);
    if (mini.out == -1) {
        perror("dup stdout");
        close(mini.in);
        return 1;
    }

    // Open the file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        close(mini.in);
        close(mini.out);
        return 1;
    }
    printf("File opened successfully, fd: %d\n", fd); // Debug output

    // Redirect stdout to the file
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        close(fd);
        close(mini.in);
        close(mini.out);
        return 1;
    }
    close(fd);

    // Write to the file
    printf("Esto se escribe en el archivo 'output.txt'\n");

    // Restore stdout
    if (dup2(mini.out, STDOUT_FILENO) == -1) {
        perror("dup2 restore stdout");
        close(mini.out);
        close(mini.in);
        return 1;
    }
    close(mini.out);

    // Write to the console
    printf("Esto se escribe en la consola\n");

    // Close the duplicated stdin
    close(mini.in);

    return 0;
}
