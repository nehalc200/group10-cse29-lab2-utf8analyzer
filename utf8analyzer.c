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
	
    	char scopy[strlen(argv[1])];
	for (int i = 0; i < strlen(argv[1]); i++){
		scopy[i] = argv[1][i];
	}
    
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
    printf("Uppercased ASCII: %s\n", str);

    int index2 = 0;
    while(argv[1][index2] != 0){
	index2++;
    }
    printf("Length in bytes: %d\n", index2); 

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

	int index3 = 0;
	int current = 0;
	int num[strlen(argv[1])];
	while(argv[1][index3] != 0){
		unsigned char byte = (unsigned char)argv[1][index3];
		int i3 = 0;
		if (byte <= 0x7F) {
            		i3 = 1;  
        	} else if ((byte & 0xE0) == 0xC0) {
            		i3 = 2;  
        	} else if ((byte & 0xF0) == 0xE0) {
            		i3 = 3;  
        	} else if ((byte & 0xF8) == 0xF0) {
            		i3 = 4;  
        	} else {
            		i3 = 1;  
        	}
		index3 += i3;
		num[current] = i3;
		current++;
	}

	printf("Bytes per code point: ");
	for (int i = 0; i < current; i++) {
        	printf("%d ", num[i]);
    	}
    	printf("\n");

	int index4 = 0;
	int current2 = 0;
	while(argv[1][index4] != 0 && current2 < 6){
		unsigned char byte = (unsigned char)argv[1][index4];
		int i4 = 0;
		if (byte <= 0x7F) {
            		i4 = 1;  
        	} else if ((byte & 0xE0) == 0xC0) {
            		i4 = 2;  
        	} else if ((byte & 0xF0) == 0xE0) {
            		i4 = 3;  
        	} else if ((byte & 0xF8) == 0xF0) {
            		i4 = 4;  
        	} else {
            		i4 = 1;  
        	}
		index4 += i4;
		current2++;
	}
	char str4[index4+1];
	for (int i = 0; i < index4; i++){
		str4[i] = scopy[i];
	}
	str4[index4] = 0;
	printf("Subtring of the first 6 codepoints: %s\n", str4);

	char numthree = argv[1][3];
	numthree++;
	printf("Next character of Codepoint at index 3: %c\n", numthree);
    return 0;
}
