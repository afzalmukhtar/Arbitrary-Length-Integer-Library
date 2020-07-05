#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#include <time.h>

int main(int argc, char const *argv[]) {
	
	char *result1;
	int index1;

	clock_t start, end;
	int counter = 0;
	start = clock();
	result1 = intal_factorial(0);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(30);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "265252859812191058636308480000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(50);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "30414093201713378043612608166064768844377641568960512000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(80);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(100);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(150);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "57133839564458545904789328652610540031895535786011264182548375833179829124845398393126574488675311145377107878746854204162666250198684504466355949195922066574942592095735778929325357290444962472405416790722118445437122269675520000000000000000000000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(200);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "788657867364790503552363213932185062295135977687173263294742533244359449963403342920304284011984623904177212138919638830257642790242637105061926624952829931113462857270763317237396988943922445621451664240254033291864131227428294853277524242407573903240321257405579568660226031904170324062351700858796178922222789623703897374720000000000000000000000000000000000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(250);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3232856260909107732320814552024368470994843717673780666747942427112823747555111209488817915371028199450928507353189432926730931712808990822791030279071281921676527240189264733218041186261006832925365133678939089569935713530175040513178760077247933065402339006164825552248819436572586057399222641254832982204849137721776650641276858807153128978777672951913990844377478702589172973255150283241787320658188482062478582659808848825548800000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}

	start = clock();
	result1 = intal_factorial(1);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}


	start = clock();
	result1 = intal_factorial(700);
	end = clock();
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2422040124750272179867875093812352218590983385729207299450679664929938160215647420444519051666484819249321456671497049842327525093874817343838393757631459228450828499972271274140160311057830558463636337124079332447820739281101037112665387537180790257577919273108262916904750405235055060084012219492892375635136296622020023178109619818046179906897450420548912610870589088056503913584562211037693288782960900195074130999799035970711436279339094292032866260496375825461427727555710003007752906141470639574390024988514914264449865006458873226951941899545970333910351588559232940829569276986080222200289966128343931630028789203382654749603473516314765262772257171154686716862814184728741187147936349501653197457455660413134506049122044947052623384682088864790673309569292384215611788014274954905914148362303226200246816441301934846080254998647325270606104512088058712293349862185399243309054299576381718806247238195232604642614329894070636163753672091232751612378348273840757873567717532879242518337119540602943609411629349009566043720836737401090882392975031224612531245642687296717053747734506443314924558119560479901478736209556925161517737110399754730551854066328420014728657896286936523787080206476327157136441318773432751007263108056958251693811280957243202460157111778617472683761623869704457588005158037495665069625778930898095725794710701639238231528115579619120287378689238934335198508665933917257143975277707590597511989345068701735940169672561864713107115016747368992690116082633762172346688969840862517264384000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")) {
			printf("Test intal_factorial PASSED %d\t", counter++);
			double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
			printf("TIME TAKEN: %lf\n", time_taken);
		} else {
			printf("Test intal_factorial FAILED.\n");
		}
		free(result1);
	}


	return 0;
}