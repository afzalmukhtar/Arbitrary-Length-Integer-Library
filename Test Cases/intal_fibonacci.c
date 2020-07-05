#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {

	char *result1;

	clock_t start, end;
	int counter = 0;
	start = clock();
	result1 = intal_fibonacci(10);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "55")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_fibonacci(55);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "139583862445")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(95);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "31940434634990099905")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(115);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "483162952612010163284885")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(180);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "18547707689471986212190138521399707760")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(200);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "280571172992510140037611932413038677189525")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(250);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "7896325826131730509282738943634332893686268675876375")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(300);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "222232244629420445529739893461909967206666939096499764990979600")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(350);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "6254449428820551641549772190170184190608177514674331726439961915653414425")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(450);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "4953967011875066473162524925231604047727791871346061001150551747313593851366517214899257280600")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(550);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3923892811677015020359893809756397635478575034984185810645229419917883032980568363855269097880889736899565213021775")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(700);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "87470814955752846203978413017571327342367240967697381074230432592527501911290377655628227150878427331693193369109193672330777527943718169105124275")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(900);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "54877108839480000051413673948383714443800519309123592724494953427039811201064341234954387521525390615504949092187441218246679104731442473022013980160407007017175697317900483275246652938800")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(1200);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "27269884455406270157991615313642198705000779992917725821180502894974726476373026809482509284562310031170172380127627214493597616743856443016039972205847405917634660750474914561879656763268658528092195715626073248224067794253809132219056382939163918400")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_fibonacci(1450);
	end = clock();
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "481496750250011136428843571903967081463488874846314827219887914560410643881950301258052067445040606537505445337730931321003621678926140591263467695247836877739842986829023011443446962382567319797291217068990256207415422421635642952339494141165239234107295736899191170326343890944201012061648917274457975")) {
			printf("Test intal_fibonacci PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_fibonacci FAILED.\n");
		}
		free(result1);
	}


	return 0;
}