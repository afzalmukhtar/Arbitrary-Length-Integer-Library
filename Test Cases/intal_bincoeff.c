#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {

	char *result1;
	int index1;
	int counter = 0;
	clock_t start, end;

	start = clock();
	result1 = intal_bincoeff(50, 25);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "126410606437752")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(100, 89);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "141629804643600")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(500, 250);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "116744315788277682920934734762176619659230081180311446124100284957811112673608473715666417775521605376810865902709989580160037468226393900042796872256")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(600, 450);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "12779168511110343121743686684712978601166067528647159599210122229587477945945942798968735988572227507979644437906069421788093063476741931161574096")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(1000, 900);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(800, 600);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "77251804243102249900492680663173121937380428827121913983653641771247184259511395708778940396868688593938893892876285454025018169910351416052742960313511746489365778233208840410665960743057530800")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(1000, 500);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "270288240945436569515614693625975275496152008446548287007392875106625428705522193898612483924502370165362606085021546104802209750050679917549894219699518475423665484263751733356162464079737887344364574161119497604571044985756287880514600994219426752366915856603136862602484428109296905863799821216320")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(1000, 900);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(1500, 500);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "98010513044822919834407342078238239157186727586439781144418266253357798614326731613867071445415360139050763348777436107629999592084166534088385225622816961675507827371501303248023952245574590017845282159263100212480872360068509433124385593841191804557601213955653337688570435422501226993482092868405683701669235947844925661098604727643099468550419961004099635651249338198098248645967339936333684932921501644321120")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_bincoeff(100, 100);
	end = clock();
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_bincoeff PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_bincoeff FAILED.\n");
		}
		free(result1);
	}



	return 0;
}