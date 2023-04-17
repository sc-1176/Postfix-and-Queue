#pragma once
#include <stack>

/*
An infix-to-postfix class implemented with a stack. Can do the following:
- read an infix expression from the user
- check if the parentheses in the expression are valid and return a message if they're not
- convert to postfix expression if the parentheses are deemed valid
- determine the priority of operators
- display a postfix expression
*/

using namespace std;

class Postfix {
public:
	int priority(char oper);			//establishes the priority of the different operators
	string inputString();				//creates an infix expression using an input from the user
	string convertPostfix();			//converts the infix expression to postfix
	bool balancedBrackets();			//checks if the brackets are balanced
	void display();						//displays the infix expression, the postfix expression, and whether or not the brackets are balanced

private:
	string postfix;						//stores the postfix expression
	string infix;						//stores the user-generated infix expression
	bool status;						//stores whether or not the expression's brackets are balanced
};
