/**
 * Jack Robbins
 * UCID: jmr226
 * CS-341 Section 010
 * Spring Semester, 2024
*/

#include<stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

bool dfa_226(string w);

//All DFA states needed -> Note: q1 start state, q10 trap state
enum dfa_states_226 {q1, q2, q3, q4, q5, q6, q7, q8, q9, q10};

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
    for(int i = 1; i <= numStrings && numStrings != 0; i++){
        printf("Enter string %d of %d: ", i, numStrings);
        string word;
        scanf("%s", &word);

        dfa_226(word);
        
    }
    
    return 0;
}


bool dfa_226(string w){
    return false;
}