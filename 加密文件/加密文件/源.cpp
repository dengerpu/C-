#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(){
	char secret_word[50]; //√‹‘øµ•¥ 
	char secret_key[26];
	int i=0,j =0,flag = 0;
	gets_s(secret_word);
	for (i = 0; i < strlen(secret_word); i++) {
		flag = 0;
		for (j = 0; j < i; j++) {
			if (secret_word[i] == secret_word[j])
				flag = 1;
		}
	}

	return 0;
}