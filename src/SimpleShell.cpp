//============================================================================
// Author      : Bigyan K C
// Version     :1.0
// Copyright   : Your copyright notice
// Description : Shell Program
//============================================================================

#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define WHITE_SPACE " \t\n"
#define MAX_ARGS 64
#define MAX_LINE_LEN 10

void printPrompt(){
	printf("My Shell\n");
}

//Read the command line
char *readCommand(){
	char *line=NULL;
	size_t bufsize=0;
	getline(&line,&bufsize,stdin);
	return line;
}

//Parse command
char **parseCommand(char *command){

	int position=0;
	char *token;
	char **tokens = (char **)malloc(MAX_LINE_LEN * sizeof(char*));
	token=strtok(command,WHITE_SPACE);
	//printf("Hello");
	while(token!=NULL){
		tokens[position]=token;
		token=strtok(NULL,WHITE_SPACE);
		++position;
	}
	//printf(tokens[1]);
	tokens[position]=NULL;
	return tokens;

}

//Create child and execute the command
int cmdExecute(char **args){
	pid_t pid;
	pid=fork();
	if(pid==0){
	if((execvp(args[0],args))==-1){
		printf("Error in program execution\n");
	}
	}
	wait();
	return 1;
}

int main(int argc,char **argv) {
	char *command=NULL;
	char **cmdString;
	while(1){
		printPrompt();
		command=readCommand();
//Parse Command entered from the keyboard
		cmdString=parseCommand(command);
//Execute the command
		int status=cmdExecute(cmdString);
	}
		return 0;

}
