#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main() { 
	char name[80];
	char *text;
	char greeting[100];

	printf("Name: ");
	scanf("%s", name);
	get_greeting(&name, &greeting);
	printf("%s\n", greeting);
}

get_greeting(char* name, char* greeting) {
	char *prefix = "Hello, ";
	char *suffix = "!";

	strcpy(greeting, prefix);
	printf("greeting: \"%s\"\n", greeting);
	strcat(greeting, name);
	printf("greeting: \"%s\"\n", greeting);
	strcat(greeting, suffix);
	printf("greeting: \"%s\"\n", greeting);
}
