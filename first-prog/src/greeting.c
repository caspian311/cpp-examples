#include <string.h>
#include <stdlib.h>

void get_greeting(char *name, char *greeting) {
	char *prefix = "Hello, ";
	char *suffix = "!";

	strcpy(greeting, prefix);
	strcat(greeting, name);
	strcat(greeting, suffix);
}
