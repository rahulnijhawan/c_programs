#include <stdio.h>
#include <string.h>

#define N 2
#define STRING_LENGTH 10

struct Alloy {
	char type[15];
	float chromium;
	float nickel;
	float tin;
	float zinc;
	float copper;
};

int main(int argc, char const *argv[])
{
	struct Alloy alloys[100];
	// SATINLESS STEEL = ADD CHROMIUM AND NICKEL TO IRON.
	char str1[STRING_LENGTH] = "SLS";
	// BRASS = COPPER + ZINC
	char str2[STRING_LENGTH] = "BRASS";
	// BRONZE = COPPER + TIN
	char str3[STRING_LENGTH] = "BRONZE";

	char s[STRING_LENGTH];
	float f1, f2;
	int i;
	printf("Enter the alloy name.\n");
	printf(" %% of nickel and chromium for steel\n");
	printf(" %% of copper and zinc for brass \n");
	printf(" %% of copper and tin for bronze \n");

	for (i = 0; i < N; i++) {
		
		scanf("%s%f%f", s, &f1, &f2);

		strcpy(alloys[i].type, s);
		if (strcmp(s, str1) == 0) {
			// steel
			alloys[i].nickel = f1;
			alloys[i].chromium = f2;
		} else if (strcmp(s, str2) == 0) {
			// brass
			alloys[i].copper = f1;
			alloys[i].zinc = f2;

		} else if (strcmp(s, str3) == 0) {
			//bronze
			alloys[i].copper = f1;
			alloys[i].tin = f2;

		} else {
			printf("wrong choice try again\n");
			i--;
		}

	}

	i = 0;

	for (;i < N; i++) {
		printf("type: %s \n", alloys[i].type);
	}
	return 0;
}