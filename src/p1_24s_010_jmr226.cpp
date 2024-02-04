/**
 * Jack Robbins
 * UCID: jmr226
 * CS-341 Section 010
 * Spring Semester, 2024
*/

#include<stdio.h>
#include <string.h>

using namespace std;

int main(){
    //Initial message
    printf("%s\n%s\n%s\n%s\n%s\n", "Project 1 for CS 341", "Section Number: 010", "Semester: Spring 2024", "Written by: Jack Robbins, jmr226", "Instructor: Marvin Nakayama, marvin@njit.edu");

    //Prompt user for number of strings to enter
    printf("Enter the number of strings that you would like to process: ");
    int numStrings;

    //Get and print the number of strings
    scanf("%d", &numStrings);
    printf("Processing %d%s%s\n", numStrings, " string", numStrings == 1 ? "" : "s");

    //Enter the main loop unless numStrings is 0
    for(int i = 0; i < numStrings && numStrings != 0; i++){
        printf("%d", i);
    }
    

    return 0;
}