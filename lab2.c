/* A lexical analyzer system for simple
arithmetic expressions */
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
/******************************************************/
/* main driver */
int main() {
/* Open the input data file and process its contents */
    if ((in_fp = fopen("front.txt", "r")) == NULL) printf("ERROR - cannot open front.in \n"); // * If file is empty



    else {
        int test  = 5;
        printf("%d",test); // ! Need to have first parameter to print a variable
        // getChar();
        // do {
        //     lex(); // ! A single call returns a single lexeme
        // } while (nextToken != EOF); 
    }
    return 0;
}
/*****************************************************/
// * lookup - a function to lookup operators and parentheses and return the token 
// int lookup(char ch) {
// switch (ch) {
// case '(':
// addChar();
// nextToken = LEFT_PAREN;
// break;
// case ')':
// addChar();
// nextToken = RIGHT_PAREN;
// break;

// }
// return nextToken;
// }
// /*****************************************************/
// * addChar - a function to add nextChar to lexeme 
void addChar() { // ? DONE ?
    if (lexLen <= 98) {
        lexeme[lexLen] =  nextChar; // ? lexLen is the index ?
    }
    else printf("Error - lexeme is too long \n");
    }
// /*****************************************************/
// *  getChar - a function to get the next character of input and determine its character class 
void getChar() { // ! DONE
    if ((nextChar = getc(in_fp)) != EOF) {
        
        if (isalpha(nextChar)) charClass = LETTER; // ! Checks whether the character is an alphabet
        else if (isdigit(nextChar)) charClass = DIGIT; // ! Checks if the character is digit
        else charClass = UNKNOWN;
        }
    else {
        charClass = EOF;
        }


}
// /*****************************************************/
// * getNonBlank - a function to call getChar until it returns a non-whitespace character 
// void getNonBlank() {
// while (isspace(nextChar))
// getChar();
// }
/*
*****************************************************/
// * lex - a simple lexical analyzer for arithmetic expressions 
// int lex() {
//     lexLen = 0;
//     getNonBlank();
//     switch (charClass) {

//         /* Parse identifiers */
//         case (LETTER):
//             addChar();
//             getChar();
//             while (charClass == LETTER || charClass == DIGIT) {
//                 addChar();
//                 getChar();
//             }
//             nextToken = IDENT;
//             break;
//             /* Parse integer literals */
//             //YOUR CODE
//             /* Parentheses and operators */
//             break;
//             case UNKNOWN:
//             //YOUR CODE
//                 break;

//             /* EOF */
//             case EOF:
//                 nextToken = EOF;
//                 lexeme[0] = 'E';
//                 lexeme[1] = 'O';
//                 lexeme[2] = 'F';
//                 lexeme[3] = 0;
//                 break;
//                 } /* End of switch */
//                 printf("Next token is: %d, Next lexeme is %s\n",
//                 nextToken, lexeme);
//                 return nextToken;
// } /* End of function lex */
