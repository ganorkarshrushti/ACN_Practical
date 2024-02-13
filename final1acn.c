
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char ip_str[40];     //to store the input IPv4 address as a string.
    int num, cells = 0;  //cells will count the no. of segments in ip address , num to store converted segm values

    printf("Enter an IPv4 address: ");
    scanf("%s", ip_str);

    // Validate IP address
    for (int i = 0; ip_str[i] != '\0'; i++) {  //loop iterates over each char of array till the end of string
        if (!isdigit(ip_str[i]) && ip_str[i] != '.') { //checks if each char is digit or dot opr
            printf("Invalid character in the IP address\n");
            return 1;   //exits prog if invalid character found
        }

        if (ip_str[i] == '.') {
            cells++;  // if the character is a dot increments cell variable, counting no. of segments
        }
    }

    if (cells != 3) {  //No. of cells should not be equal to 3
        printf("Invalid number of cells in the IP address\n");
        return 1;
    }

    // Validate each cell value ,strtok std. library for tokenizing strings 
    char *token = strtok(ip_str, ".");    //used to tokenize the ip_str string based on the dot (.) delimiter.
    while (token != NULL) {
        num = atoi(token);  //atoi converts each token into integer

        if (num < 0 || num > 255) {   //checks value is within range of 0 to 255
            printf("Invalid cell value in the IP address\n");
            return 1;
        }

        token = strtok(NULL, ".");  
    }

    // Identify class and special addresses
    num = atoi(strtok(ip_str, ".")); //conversion of token to integer

    if (num >= 0 && num <= 127) {
        printf("Class A address\n");
        if (num == 0 || num == 127) {
            printf("Special address\n");
        }
        
    } else if (num >= 128 && num <= 191) {
        printf("Class B address\n");
    } else if (num >= 192 && num <= 223) {
        printf("Class C address\n");
    } else if (num >= 224 && num <= 239) {
        printf("Class D address\n");
    } else if (num >= 240 && num <= 255) {
        printf("Class E address\n");
    }

    return 0;
}
