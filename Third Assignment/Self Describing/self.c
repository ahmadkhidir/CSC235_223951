/*
 ============================================================================
 Name        : sdn.c
 Author      : Ahmad Khidir
 Version     : 1.0
 Description : CSC235: Self Describing Numbers

 This program check for self describing number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 1000
#define MAX_LINE_LENGTH 100

int sdn(char input[]) {
	int inp_len = strlen(input); // Assign the length of the string to a variable str_len
	for (int i=0; i<inp_len; i++) { // Loop through all the the element in the string and assign it to variable "current"
		char current = input[i];
		int count = 0;
		for (int j=0; j<inp_len; j++) { // Check if "current" index is equal to count of "current" in the input string
			// With that, it is said to be self describing
			int c = input[j]-48;
			if (c == i) {
				count++;
			}
		}
		int d = current-48;
		if (input[inp_len-1] == '\n') continue;
		if (d != count) { // If it is not equal it return 0 which denote that the input is not self describing
			return 0;
		}
	}
	// If it check for all elements and every elements in the string is self describing, it returns 1 to denote that all elements are self describing numbers.
	return 1;
}

int main(int argc, char **argv) {
	// Fetching inputs from a file named self.in using stdio library
	char path[MAX_BUFFER];
	getcwd(path, MAX_BUFFER);
	strcat(path, "\\self.in");
	FILE *ftpr;
	char input[MAX_LINE_LENGTH];
	ftpr = fopen(path, "r");
	while(fgets(input, MAX_LINE_LENGTH, ftpr)) { // getting the files line by line until it return void which marks the end of the lines
		int total = atoi(input);
		for (int i=0; i< total; ++i) {
			fgets(input, MAX_LINE_LENGTH, ftpr);
			int a = sdn(input); // calling the self_describing_numbers function(sdn) with the each line as input parameter
			if (a == 1) {
				printf("Self Describing \n"); // if the response is 1 then it is self describing numbers else not a self describing numbers
			} else {
				printf("Not Self Describing \n");
			}
		}
	}
	fclose(ftpr);
	return 0;
}
