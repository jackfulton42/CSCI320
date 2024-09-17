#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Returns an array of tokens
char** tokenize(char* input)
{
    char** tokens = malloc(sizeof(char*) * (51));
    char* oneToken;

    //sorts input into tokens, adds NULL pointer to the end
    int i = 0;
    while(input != NULL)
    {
        oneToken = strsep(&input, "\n");
        if(oneToken[0] == '\0')
        {
            break;
        }
        tokens[i] = oneToken;
        i++;
    }
    tokens[i] = NULL;

    return tokens;
}

//Runs the command entered into the shell
void runCommand(char** tokens)
{
    const char* command = tokens[0];
    int pid;
    pid = fork();
    if(pid == 0)
    {
        //Child process
        execvp(command, tokens);
    }
    else
    {
        //Parent process
        wait(NULL);
    }
}

int main(int argc, char* argv[])
{
    char command[50];

    //runs the shell until the user kills the process
    while(!feof(stdin))
    {
        printf("$> ");
        fgets(command, 50, stdin);
        
        //Checks to make sure a blank line isn't inputted
        while(command[0] == '\n')
        {
            printf("$> ");
            fgets(command, 50, stdin);
        }

        char** allTokens = tokenize(command);

        runCommand(allTokens);

        free(allTokens);
    }
    
    return 0;
}