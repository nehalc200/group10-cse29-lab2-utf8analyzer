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
        
	char* str = strdup(argv[1]);
	
	for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    printf("Uppercased ASCII: %s.\n", str);

    int32_t count = 0;
    int i = 0;

    while (str[i] != '\0') {
        unsigned char byte = (unsigned char)str[i];

        if (byte <= 0x7F) {
            i += 1;  
        } else if ((byte & 0xE0) == 0xC0) {
            i += 2;  
        } else if ((byte & 0xF0) == 0xE0) {
            i += 3;  
        } else if ((byte & 0xF8) == 0xF0) {
            i += 4;  
        } else {
            i += 1;  
        }
        count++;
    }
   
    printf("Number of code points: %d\n", count);
    printf("Code points as decimal numbers: ");
    
    for (int i = 0; argv[1][i] != '\0'; i++) {
        printf("%d", (unsigned char)argv[1][i]);
        if (argv[1][i + 1] != '\0') {  
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
