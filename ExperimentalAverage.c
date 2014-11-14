#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]){

	FILE *file_ptr;
        if(argc == 1){
                printf("Sorry, no arguments were passed. Include one data file.");
        }

	//open the file in binary mode, so we can use ftell()
        file_ptr = fopen(argv[1], "rtb");
        if(file_ptr == NULL){
                printf("Error. File does not exist.");
                return;
        }

	//get the size of the file so we can know how maximally large to make the array	
	fseek(file_ptr, 0, SEEK_END);
        int fileSize;
        fileSize = ftell(file_ptr);

        //go back to the beginning of the file
	rewind(file_ptr);

	//make a line array and a delimiter to be used with strtok
	char line[fileSize];
	const char delim[2] = ",";
	char *token;

	//while we are still cycling through the file
	while(fgets(line, fileSize-1, file_ptr) != NULL){

		float sum = 0;
		//gets the first token
		token = strtok(line, delim);
		float numtoken = 1;

		//gets other tokens
		while(token != NULL){
			if((int)numtoken == 1){
				//we have selected the name of the experiment
				printf("%s ", token);
				numtoken++;
				token = strtok(NULL, delim);
			}
			else{
				//keep track of numtoken for division later
				//use atof to get numbers, sum them continually
				numtoken++;

				float atofval;
				atofval = atof(token);

				sum += atofval;
				token = strtok(NULL, delim);
			}
		}
		//we have collected all the numbers into a sum
		//now we will average them, round, and print
		//then we return to the top to repeat for subsequent lines

		//minus 2 b/c we increment at the name, and once extra at the end
		numtoken -= 2;
		float average;
		average = sum/numtoken;
		float roundedaverage = roundf(average*100)/100;

		//print only until the 2nd decimal place of the already rounded number
		printf("%.2f \n", roundedaverage);
	}
	return 0;
}
