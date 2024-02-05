/**
 * Jack Robbins
 * UCID: jmr226
 * CS-341 Section 010
 * Spring Semester, 2024
*/

#include <iostream>
#include<stdio.h>
#include <string.h>
#include <sstream>


using namespace std;

//All DFA states needed -> Note: q1 start state, q10 trap state
enum dfa_state_226 {q1 = 1, q2, q3, q4, q5, q6, q7, q8, q9, q10};

//Predeclare
bool dfa_226(string w);

//all characters that make up the language sigma
string psi = "abcdefghijklmnopqrstuvwxyz";
string pi = ".";
string phi = "@";

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
        //Prompt user and get string entered
        printf("Enter string %d of %d: ", i, numStrings);
        string word;
        cin >> word;

        cout << word << endl;

        dfa_226(word);
    }
    
    return 0;
}


bool dfa_226(string w){
    stringstream word(w);

    //All strings start out in q1
    dfa_state_226 currState = q1;
    cout << "Beginning processing, currently in start state: q1" << endl;

    char ch;
    bool inAccept;

    while(word.get(ch)){
        inAccept = false;

        switch(currState){
            //Start state, all strings begin here
            case q1:
                //If we find a lowercase roman numeral, move to q2
                if(psi.find(ch) != string::npos){
                    currState = q2;
                //If we read anything besides a roman numeral in q1, string is invalid
                } else {
                    currState = q10;
                }

                break;

            case q2:
                //if we read in a character, we stay in q2
                if(psi.find(ch) != string::npos){
                    currState = q2;

                //If we get here, we found a ".", move back to q1
                } else if(pi.find(ch) != string::npos){
                    currState = q1;

                //if we get here, we found "@", move to q3
                } else if(phi.find(ch) != string::npos){
                    currState = q3;
                
                //we got something weird, go to trap state q10
                } else {
                    currState = q10;
                }

                break;

            //we've just read the "@" symbol, we must see another roman numeral here to be valid
            case q3:
                //if we see a roman numeral, go to q4
                if(psi.find(ch) != string::npos){
                    currState = q4;
                //invalid, go to trap state
                } else {
                    currState = q10;
                }

                break;

            //allowed to read either a "." or roman numerals
            case q4:
                //If we see a roman numeral, stay in q4
                if(psi.find(ch) != string::npos){
                    currState = q4;
                //If we see a ".", go to q5
                } else if(pi.find(ch) != string::npos){
                    currState = q5;
                //Invalid, go to trap state
                } else {
                    currState = q10;
                }

                break;

            //If we see a "g", advance forward, otherwise go back to q4
            case q5:
                //potentially at a ".gov" or ".gr"
                if(ch == 'g'){
                    currState = q6;
                //Go back to q4 if we see a roman numeral
                } else if(psi.find(ch) != string::npos){
                    currState = q4;
                //If we get here, the string is invalid, go to trap state
                } else {
                    currState = q10;
                }
                
                break;

            case q6:
                //if we see an 'r', go to q7, an accepting state
                if(ch == 'r'){
                    inAccept = true;
                    currState = q7;
                //if we see an 'o', potential for ".gov", go to q9
                } else if (ch == 'o'){
                    currState = q8;
                //If we see a roman numeral, accepting "sequence" is messed up, go back to q4
                } else if (psi.find(ch) != string::npos){
                    currState = q4;
                //if we see ".", back to q5
                } else if(pi.find(ch) != string::npos) {
                    currState = q5;
                //invalid, to trap state
                } else {
                    currState = q10;
                }

                break;

            //q7 is an accepting state, but if we get here, we've read another character after being in q7, we need to keep processing
            case q7:
                //If we see a roman numeral, go back to q4
                if(psi.find(ch) != string::npos){
                    currState = q4;
                //If we read a ".", back to q5
                } else if(pi.find(ch) != string::npos){
                    currState = q5;
                //trap state
                } else {
                    currState = q10;
                }

                break;

            //We get to q8 by reading ".go", potentially an accepting sequence
            case q8:
                //If we read a "v", go to q9, an accepting state
                if(ch == 'v'){
                    inAccept = true;
                    currState = q9;
                //If we don't see a v, back to q4
                } else if(psi.find(ch) != string::npos){
                    currState = q4;
                //If we see a ".", back to q5
                } else if(pi.find(ch) != string::npos){
                    currState = q5;
                //some invalid entry, go to trap state
                } else {
                    currState = q10;
                }

                break;

            //q9 is an accepting state, but if we get here we've read another character after the "v"
            case q9:
                //If we see a roman numeral, back to q4
                if(psi.find(ch) != string::npos){
                    currState = q4;
                //If we see a ".", back to q5
                } else if(pi.find(ch) != string::npos){
                    currState = q5;
                //Otherwise, some invalid entry, go to trap state
                } else {
                    currState = q10;
                }
            
            break;


            //Trap state, inescapable
            case q10:
                break;

            //Added to avoid compile warnings, we should never get here
            default:
                return false;
        }

        cout << "In state q" << currState << " after processing character: " << ch << endl;
    }

    cout << inAccept << endl;

    return inAccept;
}