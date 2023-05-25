#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int event_loop = 1; // Variable to define loop

void end_event_loop()
{
    event_loop = 0;
}

void start_menu()
{
    // clrscr();
    printf("Shelly, Herald of the Rift\n");
    printf("Version 1.0\n");
    printf("By Juls, aLeg, iVan and Schle\n");
    printf("Usable Commands: touch, !!ls!!, rm, mkdir, sl, echo, whoami (ADD COMMANDS HERE)\n");
}

void userbar()
{
    printf("Shelly@User >");
}

void strtrim(char *string)
{
    string[strlen(string) - 1] = '\0';
}

void clrscr()
{
    system("clear");
}

void get_command()
{
    int max_userinput = 100;

    char user_Input[max_userinput];
    fflush(stdin);
    fgets(user_Input, max_userinput, stdin);
    strtrim(user_Input);
    if (user_Input[0] == 't' && user_Input[1] == 'o' && user_Input[2] == 'u' && user_Input[3] == 'c' && user_Input[4] == 'h' && user_Input[5] == ' ')
    {
        touch(user_Input);
    }
    else if (user_Input[0] == 'l' && user_Input[1] == 's' && user_Input[2] == ' ')
    {
        ls(user_Input);
    }
    else if (user_Input[0] == 's' && user_Input[1] == 'l')
    {
        sl();
    }
    else if (user_Input[0] == 'c' && user_Input[1] == 'a' && user_Input[2] == 't' && user_Input[3] == ' ')
    {
        cat(user_Input);
    }
    else if (user_Input[0] == 'm' && user_Input[1] == 'k' && user_Input[2] == 'd' && user_Input[3] == 'i' && user_Input[4] == 'r' && user_Input[5] == ' ')
    {
        mkdir(user_Input);
    }
    else if (user_Input[0] == 'r' && user_Input[1] == 'm' && user_Input[2] == ' ' && user_Input[3] == '-' && user_Input[4] == 'r' && user_Input[5] == ' ')
    {
        rmr(user_Input);
    }
    else if (user_Input[0] == 'r' && user_Input[1] == 'm' && user_Input[2] == ' ')
    {
        rm(user_Input);
    }
    else if (user_Input[0] == 'e' && user_Input[1] == 'c' && user_Input[2] == 'h' && user_Input[3] == 'o' && user_Input[4] == ' ')
    {
        echo(user_Input);
    }
    else if (user_Input[0] == 'w')
    {
        whoami();
    }
    else
    {
        no_known_command(user_Input);
    }
}

void no_known_command(char *input)
{
    printf("%s not known\n", input);
}

void touch(char *input)
{
    char name[100];
    for (int i = 6; i <= strlen(input); i++)
    {
        name[i - 6] = input[i];
    }
    FILE *fp;
    fp = fopen(name, "w");
    fclose(fp);
}

void sl()
{
    int pid = fork();
    if (pid == -1)
    {
        perror("forking");
    }
    else if (!pid)
    {
        execl("/opt/homebrew/Cellar/sl/5.02/bin/sl", "/opt/homebrew/Cellar/sl/5.02/bin/sl", NULL);
    }
    else
    {
        wait(NULL);
    }
}

void cat(char *input)
{
    char c;

    char name[100];
    for (int i = 4; i <= strlen(input); i++)
    {
        name[i - 4] = input[i];
    }

    FILE *fp;
    fp = fopen(name, "r");

    if (fp == NULL)
    {
        printf("Shelly can`t read this file");
    }
    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}

void mkdir(char *input)
{
    char name[100];
    int pid = fork();
    for (int i = 6; i <= strlen(input); i++)
    {
        name[i - 6] = input[i];
    }
    if (!pid)
    {
        execl("/bin/mkdir", "mkdir", name, NULL);
    }
}

void ls(char *input)
{
}

void rm(char *input)
{
    char name[100];
    int pid = fork();
    for (int i = 3; i <= strlen(input); i++)
    {
        name[i - 3] = input[i];
    }
    if (!pid)
    {
        execl("/bin/rm", "rm", name, NULL);
    }
}

void rmr(char *input)
{
    char name[100];
    int pid = fork();
    for (int i = 6; i <= strlen(input); i++)
    {
        name[i - 6] = input[i];
    }
    if (!pid)
    {
        execl("/bin/rm", "/bin/rm", "-r", name, NULL);
    }
}

void echo(char *input)
{
    char name[100];
    for (int i = 5; i <= strlen(input); i++)
    {
        name[i - 5] = input[i];
    }

    printf("%s\n", name);
}

void whoami()
{
    printf("\nI am the great Sir George William Washington Herald of the Rift the third. \nFound in the top jungle of the summoners rift, in the baron pit after 7 minutes have passed and before 20 minutes.");
}

int main()
{
    signal(SIGINT, end_event_loop);

    start_menu();
    while (event_loop)
    {
        userbar();
        get_command();
    }

    return EXIT_SUCCESS;
}
