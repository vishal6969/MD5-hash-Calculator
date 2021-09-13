#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

//main driver code
int main (int argc, char* argv[]){

    char* text = (char*) malloc(1000 * sizeof(char));
    char* hash;
    int length;
    Blocks* blocks;
    
    //when user passed a file name to read as arguement
    if(argc > 1){
        FILE* f = fopen(argv[1], "r");
      
      	//when there was some error reading file
        if(!readFile(text, f)){
            return 0;
        }
    }
    else{
        scanf("%[^\n]s", text);
    }

    //take length of input string
    length = strLen( text);

    //make blocks of input and call hash function
    blocks = makeBlocks(text, length);
    hash = md5(blocks);

    printf("\nMD5 Hash Value: %s", hash);

    //free allocated memory
    free(hash);

}


//function reads text file and copies it to passed variable 
int readFile(char* text, FILE* f){

    if(f){
        printf("\nReading File...");

        int  i = 0;             //iterator
        char c;                 

        while((c = getc(f)) != EOF){
        //when file exceeds max length(1000)
            if(i >= 1000){
                printf("\nError: File Exceeds max length");
                return 0;
            }

            text[i++] = c;
        }

        //terminate with null
        text[i] = '\0';
    }
    else{
        printf("\nInvalid File");
        return 0;
    }

    return 1;
}


//function to calculate length of a string
int strLen(char* string) {

    int count = 0;

    while(string[count] != '\n' && string[count] != '\0') {
     
	count++;
    }

    return count;
}
