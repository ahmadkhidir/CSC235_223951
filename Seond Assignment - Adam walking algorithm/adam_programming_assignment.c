/*
 ============================================================================
 Name        : adam_programming_assignment.c
 Author      : Ahmad Khidir
 Version     : 1.0
 Description : CSC235: Adam Programming Assignment
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int using_while(char steps[]) {
	int steps_len = strlen(steps);
	int count = 0;
	while(steps[count]) {
		if ((steps[count] == 'D')
			| (count == steps_len)
		) {
			break;
		} ++count;
	}
	return count;
}

int using_for(char steps[]) {
	int steps_len = strlen(steps);
	int count = 0;
	for (int c = 0; c < steps_len; ++c) {
		if (steps[c] == 'D') {
			break;
		} ++count;
	}
	return count;
}

int using_recursion(char steps[], int count) {
	int steps_len = strlen(steps);
	char i=steps[0];
	if ((steps_len == 0) | (i == 'D')) {
		return count;
	} else {
		char steps_1_last[]="";
		strncpy(steps_1_last, steps+1, steps_len-1); // memcpy(steps_1_last, steps+1, steps_len-1);
		return using_recursion(steps_1_last, count+1);
	}
}

int using_strchr(char steps[]) {
	char *e;
	int index;
	e = strchr(steps, 'D');
	index = (int)(e-steps); //Interpret as an integer in the memory
	if (index >= 0) return index;
	return strlen(steps);
}

int main(void) {
	int MAX_BUFFER = 1000;
	int MAX_LINE_LENGTH = 100;
	char path[MAX_BUFFER];
	getcwd(path, MAX_BUFFER);
	strcat(path, "\\src\\adam.in");
	FILE *ftpr;
	char input[MAX_LINE_LENGTH];
	ftpr = fopen(path, "r");
	while(fgets(input, MAX_LINE_LENGTH, ftpr)) {
		int w = using_while(input);
		printf("%i \n", w);
	}
	fclose(ftpr);
	return EXIT_SUCCESS;
}
