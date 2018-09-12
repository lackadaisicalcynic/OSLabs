#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char command[100];
	while (0 != strncmp(command, "quit", 100)) {
		printf("> ");
		scanf("%s", command);
		system(command);
	}
	return 0;
}
