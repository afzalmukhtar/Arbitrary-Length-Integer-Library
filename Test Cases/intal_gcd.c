#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {
	int n = 16;
	char **a = (char**) malloc(n * sizeof(char*));
	char **b = (char**) malloc(n * sizeof(char*));
	char **c = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
		b[i] = (char*) malloc(1001 * sizeof(char));
		c[i] = (char*) malloc(1001 * sizeof(char));
	}
	


strcpy(a[0], "9150275847616067581460997646785869428735");
strcpy(a[1], "10722731145886221077269344155551755394918");
strcpy(a[2], "6747749281044235752481767253772232061866");
strcpy(a[3], "6172474992016942564675129989808431875653");
strcpy(a[4], "3369532467806111427495150360140669573971");
strcpy(a[5], "12070544683400687036972252586151766611782");
strcpy(a[6], "12238801943633345786587521628543501302257");
strcpy(a[7], "5621925320835325215714963353876579745848");
strcpy(a[8], "1732451015344214543817137814590955969455");
strcpy(a[9], "328");
strcpy(a[10], "956");
strcpy(a[11], "502");
strcpy(a[12], "112");
strcpy(a[13], "999999");
strcpy(a[14], "13");
strcpy(a[15], "0");

strcpy(b[0], "89068129124845808743227830652202545265296647");
strcpy(b[1], "385559291359293034464161592451862696939634054");
strcpy(b[2], "390516416308708360636642864323294908877516920");
strcpy(b[3], "425524492144886941831606933692769912494176659");
strcpy(b[4], "172773463452493148624921800532309557783207741");
strcpy(b[5], "133254854417047534992710804451994711387025384");
strcpy(b[6], "185582399873853043309925752844622384234367096");
strcpy(b[7], "27575776378450314030791455797400071142083271");
strcpy(b[8], "413684138447052390753127970174756669702954220");
strcpy(b[9], "64758");
strcpy(b[10], "44943");
strcpy(b[11], "25952");
strcpy(b[12], "32854");
strcpy(b[13], "111111");
strcpy(b[14], "0");
strcpy(b[15], "0");

strcpy(c[0], "1");
strcpy(c[1], "2");
strcpy(c[2], "2");
strcpy(c[3], "1");
strcpy(c[4], "1");
strcpy(c[5], "2");
strcpy(c[6], "1");
strcpy(c[7], "1");
strcpy(c[8], "5");
strcpy(c[9], "2");
strcpy(c[10], "1");
strcpy(c[11], "2");
strcpy(c[12], "2");
strcpy(c[13], "111111");
strcpy(c[14], "13");
strcpy(c[15], "0");

	char *result1;
	int index1;

	clock_t start, end;

	for(int i = 0; i < n; i++)
	{
		start = clock();
		result1 = intal_gcd(a[i], b[i]);
		end = clock();
		if(!result1) {
			printf("Test intal_gcd FAILED.\n");
		} else {
			if(0 == strcmp(result1, c[i])) {
				printf("Test intal_gcd PASSED %d\t", i);
				double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
				printf("TIME TAKEN: %lf\n", time_taken);			
			} else {
				printf("Test intal_gcd FAILED. %d\nExpected: %s\nYourAnswer: %s\n", i, c[i], result1);
			}
			free(result1);
		}
	}

	return 0;
}