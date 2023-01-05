#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

struct Users {//Ahmed Sabzwari
			 //Yusuf Zaidi
			 //Michael Moran Lopez
	char my_word[40];
	int tries;// amount of tries left
	int max_tries;//the amount of tries allowed
	char name[40];
};
int main() {
	struct Users user1;
	struct Users user2;
	printf("Welcome to the hangman game!!!!\n");
	printf("please enter name for user1 who will enter the word: ");
	fgets(user1.name, 40, stdin);
	int inLen = strlen(user1.name);
	user1.name[inLen - 1] = '\0';
	printf("%s\n", user1.name);
	printf("please enter name for user2 who will be the guesser: ");
	fgets(user2.name, 40, stdin);
	inLen = strlen(user2.name);
	user2.name[inLen - 1] = '\0';
	printf("%s\n", user2.name);
	printf("%s  enter a word: ", user1.name);
	fgets(user1.my_word, 40, stdin);
	inLen = strlen(user1.my_word);
	user1.my_word[inLen - 1] = '\0';
	if (strlen(user1.my_word) > 2) {// the amount of tries will be based on how many characters the word has. A space counts as a character
		user2.tries = strlen(user1.my_word);
		user2.max_tries = strlen(user1.my_word);

	}
	else {//the user will have two tries to guess a word that is 2 letters or less in length
		user2.tries = 2;
		user2.max_tries = 2;
	}
	int i;
	for (i = 0; i < strlen(user1.my_word); i++) {
		user2.my_word[i] = 'x'; //user2's word is unknown so it is followed by asterisks
	}
	user2.my_word[i] = '\0';
	int j;
	for (j = 0; j < strlen(user1.my_word); j++) {
		printf("%c", user2.my_word[j]);
	}
	printf("\n");
	printf("User 2 is allowed %d tries\n", user2.max_tries);
	char ch;
	int count = 0;
	int secCount = 0;
	char lettersUsed[26];
	int usedCount = 0;
	while (strcmp(user2.my_word, user1.my_word) != 0) {
		printf("Enter a character user 2:\n ");
		scanf_s(" %c", &ch);//space between char to avoid phantom line
		lettersUsed[usedCount] = ch;
		for (int j = 0; j < strlen(lettersUsed); j++) {
			for (int k = j; k < strlen(lettersUsed); k++) {
				if (lettersUsed[j] == toupper(lettersUsed[k] || lettersUsed[j] == tolower(lettersUsed[k]))) {
					secCount++;
				}
			}
		}
		usedCount++;
		for (int i = 0; i < strlen(user1.my_word); i++) {

			if ((tolower(user1.my_word[i]) == ch && isupper(user1.my_word[i])) || (ch == user1.my_word[i]) || (tolower(ch) == user1.my_word[i])) {
				user2.my_word[i] = user1.my_word[i];

				count++;
			}
			else if ((tolower(user1.my_word[i]) == ch && islower(user1.my_word[i])) || (ch == user1.my_word[i]) || (toupper(ch) == user1.my_word[i])) {
				user2.my_word[i] = user1.my_word[i];
				count++;
			}
			

		}
		if ((count == 0 && secCount != 0)||(secCount!=0)) {
			user2.tries = user2.tries;
		}
		 if (count == 0 && secCount ==0 ){
			printf("%c is the wrong character\n", ch);
			user2.tries = user2.tries - 1;
			printf("%s has %d lives left\n", user2.name, user2.tries);
		}  
		printf("%s\n", user2.my_word);
		count = 0;
		secCount = 0;
		if (user2.tries == 0) {
			break;
		}
	}//end of while loop

	if (user2.tries == 0) {

		printf("GAME OVER! GUESS THE WORD CORRECTLY NEXT TIME\n");
		exit(0);
	}
	else if (user2.tries != 0 && strcmp(user2.my_word, user1.my_word) == 0) {
		printf("CONGRATULATIONS!!! YOU GUESSED THE WORD CORRECTLY\n");
		exit(0);
	}
	return(EXIT_SUCCESS);
}