#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSetPrompt(char userinput[]){
	int i;
	for(i = 0; i < 1;){
		if(userinput[i] == 's' || userinput[i] == 'S'){ i++; }
		if(userinput[i] == 'e' || userinput[i] == 'E'){ i++; }
		if(userinput[i] == 't' || userinput[i] == 'T'){ i++; }
		if(userinput[i] == ' ' || userinput[i] == ' '){ i++; }
		if(userinput[i] == 'p' || userinput[i] == 'P'){ i++; }
		if(userinput[i] == 'r' || userinput[i] == 'R'){ i++; }
		if(userinput[i] == 'o' || userinput[i] == 'O'){ i++; }
		if(userinput[i] == 'm' || userinput[i] == 'M'){ i++; }
		if(userinput[i] == 'p' || userinput[i] == 'P'){ i++; }
		if(userinput[i] == 't' || userinput[i] == 'T'){ return 1; }
		else{ break; }}
		return 0;
}

void getSubstring(char prompt[], char userinput[]){
	//"set prompt" has  10 characters, so we locate the 11th position
	//11th pos: because there is a space between the input prompt and the command
	int m;
	int p = 0;
	for(m = 11; m <= strlen(userinput); m++){
		prompt[p] = userinput[m];
		p++;
	}
}

int isQuit(char userinput[]){
	int j;
	for(j = 0; j < 1;){
		if(userinput[j] == 'q' || userinput[j] == 'Q'){ j++; }
		if(userinput[j] == 'u' || userinput[j] == 'U'){ j++; }
		if(userinput[j] == 'i' || userinput[j] == 'I'){ j++; }
		if(userinput[j] == 't' || userinput[j] == 'T'){ return 1; }
		else{ break; }}
	return 0;
}

int main(void){
	
	char prompt[100];
	char *initialprompt = "Yo bitch.";
	//copy the initial prompt into prompt array for changing
	memcpy(prompt, initialprompt, strlen(initialprompt)+1);
	printf("%s %s", prompt, " ");
	
	char userinput[100];
//	printf("%s", userinput);
//	printf("%d", isQuit(userinput));
//	printf("%d", isSetPrompt(userinput));
	while(gets(userinput) != NULL){
	//the user inputs valid things

		if(isSetPrompt(userinput) == 1){
		//we want to set the prompt
		//get subString also sets the prompt
			getSubstring(prompt, userinput);
		}
		if(isQuit(userinput) == 1){
		//we want to quit	
			exit(0);
		}
		else{
			system(userinput);
		}
		printf("%s %s", prompt, " ");
	}
}
