

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "help.h"
#define PI 3.1415926535

void trig() {
	// User input prompt
	printf("\nPlease input request (h-help, q-quit): ");
	char entire_input[30] = "";
	fgets(entire_input, 100, stdin);
	
	//printf("%s\n", entire_input);
	
	char type[] ="scr";
	double start_value, final_value;
	double intermediate_rows;
	sscanf(entire_input, "%s %lf %lf %lf", type, &start_value, &final_value, &intermediate_rows);
	
	//printf("%s\n%.3lf\n%.3lf\n%d\n", type, start_value, final_value, intermediate_rows); 
	
	char letter_s = 's', letter_c = 'c', letter_t = 't', letter_d = 'd', letter_r = 'r';
	
	// Check for whitespaces
	int length = strlen(entire_input);
	int spaces = -1;
	for (int q = 0; q < length; q++) {
		if (isspace(entire_input[q])) {
			spaces += 1;
		}
	}
	
	char sstring[100], fstring[100], istring[100];
	
	// Convert type string to lowercase
	for (int i = 0; i < strlen(type); i++) {
		type[i] = tolower(type[i]);
	}
	
	if (spaces <= 1) {
		// If input is single character, check for help or quit triggers
		if (strlen(type) == 1) {
			char letter_h = 'h';
			char *h_result;
			char letter_q = 'q';
			char *q_result;
			h_result = strchr(type, letter_h);
			q_result = strchr(type, letter_q);
			if (h_result != NULL) {
				help_message();
				return;
			}
			else if (q_result != NULL) {
				exit(1);
				}
			else {
				printf("\nError: Illegal input!\n");
				//printf("FAIL 1\n");
				return;
			}
		}
		else {
			printf("\nError: Illegal input!\n");
			return;
		}
	}
	else if (spaces == 2) {
		sscanf(entire_input, "%lf %lf %lf", &start_value, &final_value, &intermediate_rows);
		//printf("are we doing this?\n");
		sscanf(entire_input, "%s %s %s", sstring, fstring, istring);
	}
	else if (spaces > 3){
		printf("\nError: Illegal input!\n");
		//printf("FAIL 2\n");
		return;
	}
	else {
		sscanf(entire_input, "%s %lf %lf %lf", type, &start_value, &final_value, &intermediate_rows); // added & to type
		sscanf(entire_input, "%s %s %s %s", type, sstring, fstring, istring);
		//printf("this???\n");
		
		// Convert type string to lowercase
		for (int i = 0; i < strlen(type); i++) {
			type[i] = tolower(type[i]);
		}
		
		// Check for illegal characters in 'type'
		for (int x = 0; x <= strlen(type)-1; ++x) {
			if (type[x] == letter_s) {
			}
			else if (type[x] == letter_c) {
			}
			else if (type[x] == letter_t) {
			}
			else if (type[x] == letter_d) {
			}
			else if (type[x] == letter_r) {
			}
			else {
				printf("\nError: Illegal input!\n");
				//printf("FAIL 3\n");
				return;
			}
		}

	}

	// Check for illegal characters in the three numerical input values
	for (int i = 0; i < strlen(sstring); i++){
		if (isalpha(sstring[i])){
			printf("\nError: Illegal input!\n");
			//printf("FAIL 4\n");
			return;
		}
	}
	for (int i = 0; i < strlen(fstring); i++){
		if (isalpha(fstring[i])){
			printf("\nError: Illegal input!\n");
			//printf("FAIL 5\n");
			return;
		}
	}
	for (int i = 0; i < strlen(istring); i++){
		if (isalpha(istring[i])){
			printf("\nError: Illegal input!\n");
			//printf("FAIL 6\n");
			return;
		}
	}

	// Check for non-integer or negative row values
	if (intermediate_rows < 0) {
		printf("\nError: Illegal input!\n");
		//printf("FAIL 7\n");
		return;
	}
	
	int rowsInt = (int)intermediate_rows;
	if (intermediate_rows != rowsInt) {
		printf("\nError: Illegal input!\n");
		//printf("FAIL 8\n");
		return;
	}
	
	// Convert type string to lowercase
	for (int i = 0; i < strlen(type); i++) {
		type[i] = tolower(type[i]);
	}
	
	// Ensure only valid characters present in 'type'
	char valid[] = "sctdr";
	for (int i = 0; i < strlen(valid); ++i){
		int marker = 0;
		for (int p = 0; p < strlen(type); p++){
			if (type[p] == valid[i]){
				marker += 1;
			}
			if (marker > 1){
				printf("\nError: Illegal input!\n");
				//printf("FAIL 9\n");
				return;
			}
		}
		
	}
	
	// Check for degrees/radians triggers, & set first and last values for results output
	char *d_result;
	char *r_result;
	d_result = strchr(type, letter_d);
	r_result = strchr(type, letter_r);
	
	double start_value_degrees, start_value_radians;
	double final_value_degrees, final_value_radians;
	
	if ((d_result != NULL && r_result == NULL) || (d_result == NULL && r_result == NULL)){
		start_value_degrees = start_value;
		final_value_degrees = final_value;
		start_value_radians = start_value * PI/180;
		final_value_radians = final_value * PI/180;
	}
	else if (d_result == NULL && r_result != NULL) {
		start_value_degrees = start_value * 180/PI;
		final_value_degrees = final_value * 180/PI;
		start_value_radians = start_value;
		final_value_radians = final_value;
	}
	else if (d_result != NULL && r_result != NULL) {
		printf("\nError: Illegal input!\n");
		return;
	}
	
	// Create an array for the degrees and radians columns
	int rows = intermediate_rows+1;
	double degrees[rows];
	double radians[rows];
	degrees[0] = start_value_degrees;
	radians[0] = start_value_radians;
	degrees[rows] = final_value_degrees;
	radians[rows] = final_value_radians;
	//printf("%.3f\t%.3f", degrees[0], radians[0]);
	
	for (int j = 1; j <= rows-1; ++j) {
		degrees[j] = start_value + (j*(final_value_degrees-start_value_degrees)/(rows));
		radians[j] = start_value_radians + (j*(final_value_radians-start_value_radians)/(rows));
		//printf("%.3f\t%.3f\n", degrees[j], radians[j]);
	}
	
	//printf("%.3f\t%.3f", degrees[rows], radians[rows]);
	
	// Create array for the output table's column headers.
	char *col_headers[5];
	col_headers[0] = "Degrees";
	col_headers[1] = "Radians";
	int nextColHeader = 1;
	
	// Check for trig function triggers & create column titles accordingly
	char *s;
	char *c;
	char *t;
	s = strchr(type, letter_s);
	c = strchr(type, letter_c);
	t = strchr(type, letter_t);
	int dosin = 0;
	int docos = 0;
	int dotan = 0;
	
	if (s != NULL) {
		nextColHeader += 1;
		col_headers[nextColHeader] = "Sin";
		dosin = 1;
	}
	if (c != NULL) {
		nextColHeader += 1;
		col_headers[nextColHeader] = "Cos";
		docos = 1;
	}
	if (t != NULL) {
		nextColHeader += 1;
		col_headers[nextColHeader] = "Tan";
		dotan = 1;
	}
	if (s == NULL && c == NULL && t == NULL) {
		col_headers[2] = "Sin";
		col_headers[3] = "Cos";
		col_headers[4] = "Tan";
		nextColHeader += 3;
		dosin = 1;
		docos = 1;
		dotan = 1;
	}

	printf("\n");
	// Print out a table
	for (int m = 0; m < nextColHeader+1; ++m) {
		printf("%10s", col_headers[m]);
	}
	
	printf("\n\n");
	
	for (int n = 0; n <= rows; ++n) {
		double k = radians[n];
		printf("%10.3lf%10.3lf", degrees[n], radians[n]);
		if (dosin == 1) {
			printf("%10.3lf", sin(k));
		}
		if (docos == 1) {
			printf("%10.3lf", cos(k));
		}
		if (dotan == 1) {
			// Account for undefined results
			double ninety = 90.000;
			double oneEighty = 180.000;
			double na = fmod(degrees[n], ninety);
			double aa = fmod(degrees[n], oneEighty);
			if (degrees[n] == 0.00) {
				printf("%10.3lf", tan(k));
			}
			else if ((na == 0) && (aa != 0)) {
				printf("%10.3s", "N/A");
			}
			else {
				printf("%10.3lf", tan(k));
			}
		}
		printf("\n");
	}	
}
