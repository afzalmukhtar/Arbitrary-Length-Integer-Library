#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {
	int n = 28;

	char *result1;
	int index1;

	clock_t start, end;
	int counter = 0;
	start = clock();
	result1 = intal_pow("500", 20);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "953674316406250000000000000000000000000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}



	start = clock();
	result1 = intal_pow("800", 50);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "14272476927059598810582859694494951363827466240000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("100", 100);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("650", 20);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "181245458363349909198770523071289062500000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("900", 60);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1797010299914431210413179829509605039731475627537851106401000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("1000", 20);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_pow("5", 13);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1220703125")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("0", 250);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_pow("13", 50);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "49792922297912707801714181535533618316401192004725734249")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_pow("65", 10);
	end = clock();
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1346274334462890625")) {
			printf("Test intal_pow PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_pow FAILED.\n");
		}
		free(result1);
	}

	return 0;
}