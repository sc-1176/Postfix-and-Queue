#include <iostream>
#include "Postfix.h"
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

int Postfix::priority(char oper)				//determines the priority order of the operators
{
	if (oper == '+' || oper == '-')
		return 1;
	else if (oper == '*' || oper == '/')
		return 2;
	else if (oper == '^')
		return 3;
	else
		return 0;

	return 0;
}

string Postfix::inputString()					//alows the user to input the infix string to be operated on
{

	infix = "";									//empty any preexisting infix string
	cout << "What expression would you like to check?" << "\t";
	cin >> infix;								//accept input for the user for the new infix string

	return infix;
}

string Postfix::convertPostfix()				//converts the infix string to postfix format
{
	postfix = "";								//clear any preexisting postfix string

	stack<char> operatorStack;					//create a stack to store the operators in
	
	balancedBrackets();							//check if the brackets of the equation are balanced

		for (size_t i = 0; i < infix.length(); i++) {
												//iterate through the string
			if((infix[i] >= 'a' and infix[i] <= 'z')
				|| (infix[i] >= 'A' && infix[i] <= 'Z')) {
				postfix+= infix[i];				//if the inputted character at index i is any letter of the alphabet, add to the postfix
			}
			else if ((infix[i] == '(')
				|| (infix[i] == '{')
				|| (infix[i] == '[')) {
				balancedBrackets();				//continues only if the brackets are balanced
				if(status == true) {
					operatorStack.push(infix[i]);	//if the inputted character at index i is an opening bracket, push to the operator stack
				}
				else if (status == false)
				{
					cout << "Parentheses are not balanced, please check your equation and try again." << endl;
					return infix;
				}
			}
			else if ((infix[i] == ')')	
				|| (infix[i] == '}')
				|| (infix[i] == ']')) {			
				while ((operatorStack.top() != '(')
					&& (operatorStack.top() != '{')
					&& (operatorStack.top() != '[')) {
					postfix += operatorStack.top();
					operatorStack.pop();		/*if the inputted character at index i is a closing bracket, and the character on the stack is 
												not an opening bracket, add the top of the stack to the postfix string and pop the stack*/
				}
				operatorStack.pop();			//pop the opening bracket from the stack
			}
			else {
				while (!operatorStack.empty() && priority(infix[i]) <= priority(operatorStack.top())) {
					postfix += operatorStack.top();
					operatorStack.pop();		//add the operators from the stack to the postfix and pop them from the stack
				}
				operatorStack.push(infix[i]);	
			}
		}
		while (!operatorStack.empty()) {		//pop any remaining operators
			postfix += operatorStack.top();
			operatorStack.pop();
		}

		return postfix;							//return the remaining postfix

}

bool Postfix::balancedBrackets()				//checks to see if the brackets in an expression are balanced
{
	
	status = false;								//set the default status to false as an initializer

	stack<char> temp;							//holds bracket values
	stack<char> nonbrackets;					//holds everything except brackets

	for (size_t i = 0; i < infix.length(); i++) {
		if (temp.empty()) {
			if ((infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
				|| (infix[i] == '(' || infix[i] == '{' || infix[i] == '['))
			{
				temp.push(infix[i]);			//push the term onto the bracket stack if the bracket stack is empty and the term is a bracket
			}
			else
			{
				nonbrackets.push(infix[i]);		//if not a bracket, shove onto the nonbrackets stack
			}
		}
		else if ((temp.top() == '(' && infix[i] == ')')
			|| (temp.top() == '{' && infix[i] == '}')
			|| (temp.top() == '[' && infix[i] == ']')) 
		{
			temp.pop();							//pop opening bracket from the stack if the current term is its pair
		}
		else if((infix[i] != ')' || infix[i] != '}' || infix[i] != ']')
			&& (infix[i] != '(' || infix[i] != '{' || infix[i] != '['))
		{
			nonbrackets.push(infix[i]);			//push anything else onto the nonbracket stack
		}
		else {
			temp.push(infix[i]);				//push anything else onto the bracket stack to force a false
		}
	}
	if (temp.empty()) {							//if the bracket stack is empty, return true
		status = true;
		return true;
	}
	else {										//if the bracket stack is not empty, return false
		status = false;
	}

	return false;

}

void Postfix::display()							//displays the infix expression, the postfix expression, and a 1 for if the brackets are balanced 
{
	cout << "Infix expression: " << '\t' << infix << endl;
	cout << "Postfix conversion: " << '\t' << postfix << endl;
	cout << "Balanced brackets?" << '\t' << balancedBrackets() << endl;
}