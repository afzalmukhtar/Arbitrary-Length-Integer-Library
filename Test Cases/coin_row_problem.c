#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {
	int n = 7;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}

	char *result1;
	int index1;
    int counter = 0;
	clock_t start, end;

//------------------------------0------------------------------//

	strcpy(a[0], "5");
	strcpy(a[1], "22");
	strcpy(a[2], "26");
	strcpy(a[3], "10");
	strcpy(a[4], "4");
	strcpy(a[5], "8");

	start = clock();
    result1 = coin_row_problem(a, 6);
    end = clock();
    if(0 == strcmp("40", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

//------------------------------1------------------------------//
	strcpy(a[0], "5");
	strcpy(a[1], "1");
	strcpy(a[2], "2");
	strcpy(a[3], "10");
	strcpy(a[4], "6");
	strcpy(a[5], "3");

	start = clock();
    result1 = coin_row_problem(a, 6);
    end = clock();
    if(0 == strcmp("18", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

//------------------------------2------------------------------//

	strcpy(a[0], "7");
	strcpy(a[1], "9");
	strcpy(a[2], "10");
	strcpy(a[3], "9");
	strcpy(a[4], "3");
	strcpy(a[5], "5");
	strcpy(a[6], "2");

	start = clock();
    result1 = coin_row_problem(a, 7);
    end = clock();
    if(0 == strcmp("23", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

//------------------------------3------------------------------//

	strcpy(a[0], "7");
	strcpy(a[1], "3");
	strcpy(a[2], "9");
	strcpy(a[3], "10");
	strcpy(a[4], "8");
	strcpy(a[5], "6");

	start = clock();
    result1 = coin_row_problem(a, 6);
    end = clock();
    if(0 == strcmp("24", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

//------------------------------4------------------------------//

    start = clock();
    result1 = coin_row_problem(a, 0);
    end = clock();
    if(0 == strcmp("0", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

//------------------------------5------------------------------//

	strcpy(a[0], "5");
	strcpy(a[1], "1");
	strcpy(a[2], "2");
	strcpy(a[3], "10");
	strcpy(a[4], "6");
	strcpy(a[5], "2");

	start = clock();
    result1 = coin_row_problem(a, 6);
    end = clock();
    if(0 == strcmp("17", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }


//------------------------------6------------------------------//

    start = clock();
    result1 = coin_row_problem(a, 1);
    end = clock();
    if(0 == strcmp("5", result1)) {
        printf("Test coin_row_problem PASSED %d\t", counter++);
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
        printf("TIME TAKEN: %lf\n", time_taken);
    } else {
        printf("Test coin_row_problem FAILED.\n");
    }

	return 0;
}