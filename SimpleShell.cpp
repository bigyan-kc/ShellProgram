//============================================================================
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define TOKEN_DELIM " ";

void printPrompt(){
	printf("My Shell\n");
}

char *readCommand(){
	char *line=NULL;
	size_t bufsize=0;
	getline(&line,&bufsize,stdin);
	return line;
}

char **parseCommand(char *command){

	int position=0;
	char *token;
	char **tokens = (char **)malloc(64 * sizeof(char*));
	token=strtok(command," \n");
	//printf("Hello");
	while(token!=NULL){
		tokens[position]=token;
		token=strtok(NULL," \n");
		++position;
	}
	//printf(tokens[1]);
	tokens[position]=NULL;
	return tokens;

}

int cmdExecute(char **args){
	pid_t pid;
	pid=fork();
	if(pid==0){
	execvp(args[0],args);
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
		cmdString=parseCommand(command);
		int status=cmdExecute(cmdString);
		//printf("%s\n",cmdString[0]);
	}
		return 0;

}
