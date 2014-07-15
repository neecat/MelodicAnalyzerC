// Melodic Analyzer
// By Nathanial Karahalis
// April 8th, 2013 - 11:00:00 EDT
// Coded on GNU/Linux

/*
TODO: Add a GUI in QT or GTK
*/


//Std. C Library Includes
#include <stdio.h>
#include <string.h>
#include <math.h>

//Version String
char *curvers="1.02a-stable";

//Global Variables

//modification: addition of float vars - April 9th, 2013 - 10:18:00 EDT
//Associate Letters and Sharps to floating decimal numbers
char* natnoteletters[]={"C","D","E","F","G","A","B"};
float natural[]={1.0,2.0,3.0,3.5,4.5,5.5,6.5};

char* sharpnoteletters[]={"B#","C#","D#","E#","F#","G#","A#"};
float sharp[]={1.0,1.5,2.5,3.5,4.0,5.0,6.0};

char* flatnoteletters[]={"Db","Eb","Fb","Gb","Ab","Bb","Cb"};
float flat[]={1.5,2.5,3.5,4.0,5.0,6.0,6.5};


//Prototypes
int analyze(char *filepath,int length);

//Main Function
int main (int argc, char *argv[])
{
    int numberofnotes;
    char outs[256];
    char* outputfile=&outs[256];
    printf("Melodic Analyzer %s\nBy: Nathanial Karahalis\nWritten in C\n\nWhere would you like to save the file?(*.csv): ",curvers);
    scanf("%s", outputfile);

    printf("How many notes are in this melody?: ");
    scanf("%i",&numberofnotes);

    printf("\n\nTo input notes format them with the letter name and octave number\nnote: C 4 is middle, Insert notes one by one.\n\n");
    analyze(outputfile,numberofnotes);
    return 0;
}

//Sub-Routines


/*analyze(character-pointer, integer)
  This Function takes the the length of a melody,
  accepts user input, and outputs the user input to
  a given *.CSV file.
  
*/
int analyze(char *filepath,int length)
{
   int x=0; //Generic While Loop Counter
   int xa=0; //12 Note System counter
   int durcounter=0;
   int s=1; //While Break Flag
   int flag=0; //Library Flag
   int octav=1; //Octave Modifier
   int i=0; //Generic For Loop
   int *octave=&octav; //Octave Modifer Pointer Initialization
   char curnote[256]; //Current Note Holder
   char *currentnote=&curnote[256]; //Pointer for Current Note
   float pitchvalue=0; //Store Value with Octave Modifer
   float duration=8.0; //Variable to store note length in 8th note lengths
   FILE *csvfile;
   //File IO Actions
   csvfile=fopen(filepath,"w");

   //Take note names and store into a file.
   do
   {
       printf("?: ");
       scanf("%s %i",currentnote,octave);
       printf("Line %i of %i\n",x+1,length);
       printf("Enter duration of note in 8thnotes(ex: 1.0)\n?:");
       scanf("%f",&duration);
       //Search Note Library
       for(i=0; i<6; i++)
       {
	  /* Modified: April 11, 2013 23:24 EDT
             Description: (int)durcounter must be re-assigned to 0 on
             every pass of the encompassing for loop to increase resolution
             of data collected.
           */
	  durcounter=0;
          if(strcmp(currentnote,natnoteletters[i])==0)
	  {
            // printf("main.c(73): Found Natural Note!\n");
	     //printf("main.c(74): Note: %s Base Pitch: %f\n",currentnote,natural[i]);
             pitchvalue=(float)octav*natural[i];
             //printf("With Octave Modifer: %f\n",pitchvalue);
 	     do{
                fprintf(csvfile,"%f,",pitchvalue);
                durcounter++;
             }while(durcounter<duration);
          }
          if(strcmp(currentnote,sharpnoteletters[i])==0)
          {
             //code
   //          printf("main.c(77): Found Sharp Note!\n");
	//     printf("main.c(78): Note: %s Base Pitch: %f\n",currentnote,sharp[i]);
	     pitchvalue=(float)octav*sharp[i];
          //   printf("With Octave Modifer: %f\n",pitchvalue);
	     do{
                fprintf(csvfile,"%f,",pitchvalue);
		durcounter++;
             }while(durcounter<duration);
          }
          if(strcmp(currentnote,flatnoteletters[i])==0)
          {
	    //some other code
//	     printf("main.c(87): Found Flat Note!\n");
//	     printf("main.c(88): Note: %s Base Pitch: %f\n",currentnote,flat[i]);
	     pitchvalue=(float)octav*flat[i];
//	     printf("With Octave Modifer: %f\n",pitchvalue);
	     do{
                fprintf(csvfile,"%f,",pitchvalue);
	        durcounter++;
             }while(durcounter<duration);
          }
 	}      
       x=x+1; //next note!
   }while(x<length); 
   fclose(csvfile); 
   return 0;
}
