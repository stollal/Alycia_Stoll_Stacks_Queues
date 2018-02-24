#include <iostream>
#include <string>
#include "functions.h"
#include <stack>


bool balancedSymbols(std::string input){
/***
* Creates an empty stack
*/
	std::stack<char> S;
/***
*Creates a for loop to read Characters until the end
*/
	for(int i=0; i<input.length(); i++){
/**
* Checks for the open symbol and pushes it on to the stack
*/
			if(input[i] == '(' || input[i] == '{' || input[i] == '['){
					S.push(input[i]);
				}
/**
*Checks for the closed symbol and if the stack is empty throws an error otherwise it will pop them off the stack
*/
			else if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
					if(S.empty()){
						return false;
					}
					else{
						S.pop();
					}
			}
			}

/**
*Makes sure the symbols being popped off are the same symbol for the open and close
*/
			if((!S.pop().equals('{' && '}')) || (!S.pop().equals('[' && ']')) || (!S.pop().equals( '(' && ')'))){
					return false;
			}
			else{
					return true;
}
/**
*After everything is popped off it makes sure the stack is empty
*/
			if(!S.empty()){
					return false;
			}
			else{
					return true;
			}
}
/**
 *Creates a function to rank operator functions
 */
int getWeight(char i){
	switch(i){
	case'/':return 3;
	case'*':return 2;
	case'+':return 1;
	case'-':return 1;
	default:return 0;
}
}
std::string iToP(std::string input){

	std::stack<char> S;
	char output[0];
	int weight;
	int l=0;
	char i;
/**
 *Loop through characters in the function to seperate from stack and output
 */
for(int k; k<input.length();k++){
			i = input[k];
			//pushes it to the stack
			if(i=='('){
					S.push(i);
					continue;
			}
			//pops the operands off the stack
			if(i==')'){
					while(!S.empty()&& S.top() != '('){
							output[l++] = S.top();
							S.pop();
					}
			//pops the ')' off the stack
			if(!S.empty()){
					S.pop();
			}
			continue;
	}
	//makes sure the operands are in the right order on the stack
	weight = getWeight(i);
	if (weight==0){
			output[l++] = i;
	}
	else{
			if(S.empty()){
					S.push(i);
			}
			else{
					while(!(!S.empty() && S.top()).equals('(') && weight <= getWeight(S.top())){
							output[l++] = S.top();
							S.pop();
					}
			push(i);
	}
	}
	}
	while(!S.empty()){
			output[l++] = S.top();
			S.pop();
			}
	//prints out the postfix
	output[l] = input;
	std::cout << input << '\n';
}

