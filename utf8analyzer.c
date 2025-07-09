#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    // implement the UTF-8 analyzer here
	int index1 = 0;
	int j1 = 0;
	while(argv[1][index1] != 0){
		if (argv[1][index1] > 127 || argv[1][index1] < 0){
			printf("Valid ASCII: %s\n", "false");
			j1 = 1;
			break;
		}
		index1++;
	}
	if (j1 == 0){ printf("Valid ASCII: %s\n", "true"); }
}
