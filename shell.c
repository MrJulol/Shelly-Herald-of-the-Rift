#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#ifdef __APPLE__
#define clrscr() system("clear")
#define HELLO() printf("Hey Apple User!\n")
#elif _Windows
#define clrscr() system("cls")
#define HELLO() printf("Hey you poor Windows user\n")
#elif __linux__
#define clrscr() system("clear")
#define HELLO() printf("You Gigachad Linux User\n")
#else
#define clrscr() printf("GET A GOOD PC\n")
#define HELLO() printf("What dafuq are you running as OS\n")
#endif

int event_loop = 1;

void end_event_loop()
{
    event_loop = 0;
}

void strtrim(char *string)
{
    string[strlen(string) - 1] = '\0';
}

void start_menu()
{
    clrscr();
    printf("Shelly, Herald of the Rift\n");
    printf("Version 1.0\n");
    printf("By Juls, aLeg, iVan and Schle\n");
    printf("Usable Commands: touch, ls (ADD COMMANDS HERE)\n");
}

void userbar()
{
    printf("Shelly@User >");
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

void get_command()
{
    int buffersize_command = 100;

    char buffer[buffersize_command];
    fflush(stdin);
    fgets(buffer, buffersize_command, stdin);
    strtrim(buffer);
    if (buffer[0] == 't' && buffer[1] == 'o' && buffer[2] == 'u' && buffer[3] == 'c' && buffer[4] == 'h' && buffer[5] == ' ')
    {
        touch(buffer);
    }
    if (buffer[0] == 'l' && buffer[1] == 's' && buffer[2] == ' ')
    {
        ls(buffer);
    }
    if (buffer[0] == 's' && buffer[1] == 'l')
    {
        sl();
    }
    if (buffer[0] == 'c' && buffer[1] == 'a' && buffer[2] == 't' && buffer[3] == ' ')
    {
        cat(buffer);
    }
    if (buffer[0] == 'm' && buffer[1] == 'k' && buffer[2] == 'd' && buffer[3] == 'i' && buffer[4] == 'r' && buffer[5] == ' ')
    {
        mkdir(buffer);
    }
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
