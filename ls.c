#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void ls(char *args)
{

    char arg1[3];
    char arg2[3];

    for (int i = 0; i < 2; i++)
    {
        arg1[i] = args[i + 3];
        arg2[i] = args[i + 6];
    }
    arg1[2] = '\0';
    arg2[2] = '\0';

    execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);

    perror("Error executing ls command");
}

int main()
{
    char *input = "ls -a -l";
    ls(input);

    return 0;
}