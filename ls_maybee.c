#include <stdio.h>
#include <unistd.h>
#include <string.h>

void execute_ls_command(char *args)
{

    char arg1[2];
    char arg2[2];

    printf("\n1l\n");
    for (int i = 3; args[i] != ' '; i++)
    {
        arg1[i - 3] = args[i];
    }
    printf("\n2l\n");
    for (int i = 6; args[i] != '\0'; i++)
    {
        arg2[i - 6] = args[i];
    }
    // arg1[strlen(arg1 - 2)] = '\0';

    // arg2 = "-l";
    printf("\n1a\n");
    printf("\n%s\n", arg1);
    printf("\n%lu\n", strlen(arg1));
    printf("\n2a\n");
    printf("\n%s\n", arg2);

    execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);

    perror("Error executing ls command");
}

int main()
{
    char *options = "ls -a -l";
    execute_ls_command(options);

    return 0;
}
