#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f1;
	char ch[5];
	f1 = fopen("file1.txt", "r+");
	if (f1 == NULL)
		printf("Error");
	while(fgets(ch,4,f1),!feof(f1)){
		printf("%s",ch);
	}
	fclose(f1);
}
