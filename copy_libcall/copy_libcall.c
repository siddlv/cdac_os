#include <stdio.h> 
#include <stdlib.h> // For exit() 

int main() 
{ 
	FILE *fptr1, *fptr2; 
	char file1[] = "file1.txt", file2[] = "file2.txt";
	char c; 

	// Open one file for reading 
	fptr1 = fopen(file1, "r"); 
	if (fptr1 == NULL) 
	{ 
		printf("Cannot open file %s \n", file1); 
		exit(0); 
	} 

	// Open another file for writing 
	fptr2 = fopen(file2, "w"); 
	if (fptr2 == NULL) 
	{ 
		printf("Cannot open file %s \n", file2); 
		exit(0); 
	} 

	// Read contents from file 
	c = fgetc(fptr1); 
	while (c != EOF) 
	{ 
		fputc(c, fptr2); 
		c = fgetc(fptr1); 
	} 

	//printf("\nContents copied to %s\n", filename); 

	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}
