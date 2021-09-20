#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE_BUFFER_SIZE 1024

const char* getfield(char* line, const char* sep, int num)
{
    const char* tok;
    for (tok = strtok(line, sep);
            tok && *tok;
            tok = strtok(NULL, "\n")){
        	if (!--num) return tok;
    }
    return NULL;
}

bool read_csv(char* path)
{
	FILE* f = fopen(path, "r");

	char line[LINE_BUFFER_SIZE];

	if (f == NULL) return false;

	char** children = malloc(sizeof(char*));
	char** parents = malloc(sizeof(char*));
	
	int i = 0;
	while(fgets(line, LINE_BUFFER_SIZE, f)) {
		char* current_line = strdup(line);
		


		printf("%s", current_line);

		free(current_line);
	}

	return true;
}

int main(int argc, char** argv) {
	bool da = read_csv("data/data.csv");
	printf("Test\n");
	return EXIT_SUCCESS;
}
