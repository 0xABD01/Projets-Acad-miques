#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool estPalindrome(char ch[]);
void inverseCh(char ch[]);

int main() {
	char ch[20];
	printf("saisir un mot :");
	scanf("%s", &ch);
	if (estPalindrome(ch))
		printf("%s est palindrome .", ch);
	else
		printf("%s est NON palindrome .", ch);
	printf("\nsaisir un mot que tu veux inverse : ");
	scanf("%s", &ch);
	inverseCh(ch);
}

bool estPalindrome(char ch[]) {
	char *P1 = ch;
	char *P2 = ch + strlen(ch) - 1;
	while (P1 < P2) {
		if (*P1 != *P2)
			return false;
		P2--;
		P1++;
	}
	return true;
}
void inverseCh(char ch[]) {
	char *P1 = ch;
	char *P2 = ch + strlen(ch) - 1;
	while (P1 < P2) {
		char chx = *P1;
		*P1 = *P2;
		*P2 = chx;
		P1++;
		P2--;
	}
	printf("\nle mot inverse est : %s .", ch);
}
