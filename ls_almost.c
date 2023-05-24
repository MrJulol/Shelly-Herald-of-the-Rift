#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ls(char *string)
{
    char *arg1;
    char *arg2;
    char *arg3;

    int pid = fork();
    printf("help %d", pid);
    
        while (pid == -1)
        {
            pid = fork();
            printf("Error occured while trying to fork;");
        }
    
    if (pid == 0)
    {

        printf("help me please");
        int j = 0;
        for (int i = 3; string[i] != ' '; i++)
        {

            arg1[j] = string[i];
            printf("\n%c1\n", string[i]);
            printf("\n%c2\n", arg1[j]);
            j++;
        }
        j = 0;

        for (int i = 6; string[i] != '\0'; i++)
        {

            arg3[j] = string[i];
            printf("\n%c3\n", string[i]);
            printf("\n%c4\n", arg3[j]);
            j++;
        }
        for (int i = 0; i < 2; i++)
        {
            arg2[i] = arg3[i];
        }

        printf("\n%s5\n", arg1);
        printf("\n%s6\n", arg2);
        if (arg1[0] == '-' && arg2[0] != '-')
        {
            execl("/bin/ls", arg1, NULL);
            printf("Error occured executing 1\n");
            exit(0);
        }
        else if (arg1[0] == '-' && arg2[0] == '-')
        {
            execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);
            printf("Error occured executing 2\n");
            exit(0);
        }
        else
        {
            execl("/bin/ls", "/bin/ls", NULL);
            printf("Error occured executing 3\n");
            exit(0);
        }
    }
}

int main()
{
    char *input = "ls -a -l";
    printf("cock ");
    ls(input);
    return 0;
}