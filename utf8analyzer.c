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
	
	int cp_index = 0;
    int byte_index = 0;
	printf("Substring of the first 6 codepoints: \"%s\"\n", str4);


	char ans[strlen(argv[1])+1];
	int index5 = 0;
	int r = 0;
	while(argv[1][index5] != 0){
		uint32_t cp = 0;
		int len = 0;
		unsigned char byte = (unsigned char)argv[1][index5];
		if (byte <= 0x7F) {
            		len = 1;  
        	} else if ((byte & 0xE0) == 0xC0) {
            		len = 2;  
        	} else if ((byte & 0xF0) == 0xE0) {
            		len = 3;  
        	} else if ((byte & 0xF8) == 0xF0) {
            		len = 4;  
        	} else {
            		len = 1;  
        	}
		if (len == 1){        		
			cp = argv[1][index5];
		}
    		else if (len == 2){
        		cp = ((argv[1][index5] & 0x1F) << 6) | (argv[1][index5+1] & 0x3F);
		}
    		else if (len == 3){
        		cp = ((argv[1][index5] & 0x0F) << 12) | ((argv[1][index5+1] & 0x3F) << 6) | (argv[1][index5+2] & 0x3F);
		}
    		else if (len == 4){
        		cp = ((argv[1][index5] & 0x07) << 18) | ((argv[1][index5+1] & 0x3F) << 12) | ((argv[1][index5+2] & 0x3F) << 6) | (argv[1][index5+3] & 0x3F);
		}
		if ((cp >= 128000 && cp <= 128063) || (cp >= 129408 && cp <= 129710)){
			for (int i = 0; i < len; i++){
				ans[r+i] = argv[1][index5+i];
			}
			r += len;
		}
		index5 += len;
	}
	ans[r] = 0;
	printf("Animal emojis: %s\n", ans);



    while (argv[1][byte_index] != '\0' && cp_index < 3) {
        unsigned char byte = (unsigned char)argv[1][byte_index];
        if (byte <= 0x7F) byte_index += 1;
        else if ((byte & 0xE0) == 0xC0) byte_index += 2;
        else if ((byte & 0xF0) == 0xE0) byte_index += 3;
        else if ((byte & 0xF8) == 0xF0) byte_index += 4;
        else byte_index += 1;
        cp_index++;
    }

    char next_char = argv[1][byte_index] + 1;

    printf("Next character of Codepoint at index 3: %c\n", next_char);
    return 0;
}
