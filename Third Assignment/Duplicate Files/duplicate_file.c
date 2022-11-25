#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_BUFFER 1000
#define MAX_LINE_LENGTH 100

// A function that split the file into name and id, in name_id structure.
void split_it(char text[], char * names[100], int ids[], int i) {

	int hi = strlen(text), n = 0;
	char id[100]="";
	char name[100]="";
	for (int i=hi-1; i > 0; i--) {
		if (text[i] == ' ') {
			n = i;
			break;
		}
	}

	strncpy(name, text, n);
	names[i] = name;
	strncpy(id, text+n+1, hi);
	ids[i] = atoi(id);
}


//A sorting function that sort array of name_id in ascending name order
void sort_name(int size_of_array, char * names[], int ids[]) {
	char * name;
	int id;
	for(int i=0; i<size_of_array; i++){
	    for(int j=0; j<size_of_array-1-i; j++){
	      if(strcmp(names[j], names[j+1]) > 0){
	        //swap array[j] and array[j+1]
	    	  id = ids[j];
	    	  name = names[j];
	    	  names[j] = names[j+1];
	    	  ids[j] = ids[j+1];
	    	  names[j+1] = name;
	    	  ids[j+1] = id;
	      }
	    }
	  }
}

//A sorting function that sort array of name_id in ascending id order
void sort_id(int size_of_array,  char * names[], int ids[]) {
	int id;
	char * name;
	for(int i=0; i<size_of_array; i++){
	    for(int j=0; j<size_of_array-1-i; j++){
	      if(ids[j] > ids[j+1]){
	        //swap array[j] and array[j+1]
	    	  id = ids[j];
	    	  name = names[j];
	    	  names[j] = names[j+1];
	    	  ids[j] = ids[j+1];
	    	  names[j+1] = name;
	    	  ids[j+1] = id;
	      }
	    }
	  }
}

//A sorting function that sort array of numbers in ascending order
void sort_numb(int size_of_array, int numb[]) {
	int temp;
	for(int i=0; i<size_of_array; i++){
	    for(int j=0; j<size_of_array-1-i; j++){
	      if(numb[j] > numb[j+1]){
	        //swap array[j] and array[j+1]
	    	  temp = numb[j];
	    	  numb[j] = numb[j+1];
	    	  numb[j+1] = temp;
	      }
	    }
	  }
}

// A compare function that compare a to b
int cmp(char *a, char *b) {
	int max = strlen(a);
	for (int i = 0;  i < max; ++i) {

		if (a[i] != b[i]) return 0;

	} return 1;
}

int main(int argc, char **argv) {
	char path[MAX_BUFFER];
	getcwd(path, MAX_BUFFER);
	strcat(path, "\\files.in");
	FILE *ftpr;
	char input[MAX_LINE_LENGTH];
	ftpr = fopen(path, "r");

	while(fgets(input, MAX_LINE_LENGTH, ftpr)) {
		int total = atoi(input);
		for (int i = 0; i < total; i++) {
			fgets(input, MAX_LINE_LENGTH, ftpr);
			int t = atoi(input);

			char * names[100];
			int ids[100];
			for (int j = 0; j < t; j++) {
				fgets(input, MAX_LINE_LENGTH, ftpr);

				split_it(input, names, ids, j);
			}

			sort_id(t, names, ids);
			sort_name(t, names, ids);
//
			char * p;

			int result[100];

			int r = 0;
			for (int i = 0; i < t; ++i) {
				if (cmp(p, names[i]) == 0) {
					result[r] = ids[i];
					++r;
					p = names[i];
				}
			}
			sort_numb(r, result);
			for (int i = 0; i < r; ++i) {
				printf("%d \n", result[i]);
			}
		}
	}


	return 0;
}
