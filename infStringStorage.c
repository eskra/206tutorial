#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define ITALIAN
#define ENGLISH

struct WORD_node{
	char word[100];
	struct WORD_node *next;
};

struct WORD_node *myStringStorage = 0;

void addWord(char []);
void printList(void);

void addWord(char inputword[]){
	struct WORD_node *currentword, *last;
	currentword = (struct WORD_node *)malloc(sizeof(struct WORD_node));
	
	if(currentword == 0){
		printf("MALLOC FAILURE.\n");
	}
	strcpy(currentword->word, inputword);
	currentword->next = 0;
	
	if(myStringStorage == 0){
		myStringStorage = currentword;
		return;
	}
	for(last = myStringStorage; last->next !=0; last = last->next){}
	last->next = currentword;
}

void printList(void){
	struct WORD_node *p;
	#ifdef ITALIAN
		printf("Lista di parole: \n");
		for(p = myStringStorage; p != 0; p = p->next){
			printf("Parola: %s\n", p->word);
		}
	#endif
	#ifdef ENGLISH
		printf("Word List: \n");
		for(p = myStringStorage; p != 0; p = p->next){
			printf("Word: %s\n", p->word);
		}
	#endif
}

int containsASpace(char userinput[]){
	int j;
        for(j = 0; j < strlen(userinput); j++){
        	if(userinput[j] == ' '){
                	return j;
                 }
        }
	return 0;
}
	
int main(){
	
	//we have an empty list
	
	//get input from user
	#ifdef ITALIAN
		printf("Benvenuto al programma di archivazione infinito di parole. \nInseri una sola parola. Quando hai finito, entri ***END***   ");
	#endif
	#ifdef ENGLISH
		printf("Welcome to the infinite String Storage Program.\nPlease input a word. When you are done, enter ***END***   ");
	#endif

	char userinput[100];
	
	while(gets(userinput) != NULL){
		
		if(!strcmp(userinput, "***END***")){
                        printList();
                        exit(0);
                        //make last node point to null
                }

		#ifdef ITALIAN
			printf("Inseri una sola parola, per piacere. ");
		#endif
		#ifdef ENGLISH
			printf("Please input a single word. ");
		#endif
		
		//add the word to the current node's word array
		int i = containsASpace(userinput);
		if(i != 0){
			char temparray[100];
			strncpy(temparray, userinput, i);
			temparray[i] = '\0';
			addWord(temparray);
		}
		if(i == 0){
			char temparray[100];
			strncpy(temparray, userinput, strlen(userinput)+1);
			addWord(temparray);
		}
	}
}
