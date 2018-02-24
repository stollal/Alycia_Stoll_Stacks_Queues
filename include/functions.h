#ifndef functions_H
#define functions_H
#include <iostream>
#include <string>
#include <stack>

class Stacks_Queues{
public:
bool balancedSymbols(std::string input);
std::string iToP(std::string input);
int getWeight(char i);
private:
std::stack<char> S;
int weight;
int l;
char i;
int k;

};
#endif
