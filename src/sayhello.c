#include <stdio.h>
#include <stdlib.h>

#include "greeting.h"

main() { 
	char name[80];
	char *text;
	char greeting[100];

	printf("Name: ");
	scanf("%s", name);
	get_greeting(&name, &greeting);
	printf("%s\n", greeting);
}
