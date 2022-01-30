#include <string>
#include <stack>
#include<iostream>
#include<algorithm>

//Bengisu Sahin || 152120191064 || bngsshn@gmail.com

using namespace std;


int add(stack<int>s) 
{
	int top2;
	int top1;
	top1 = s.top();
	s.pop();
	top2 = s.top(); s.pop();
	return top1 + top2;
}

int mult(stack<int>s)
{
	int top2;
	int top1;
	top1=s.top();
	s.pop();
	top2=s.top();
	s.pop();
	return top1 * top2;
}

int subs(stack<int>s)
{
	int top2;
	int top1;
	top1 = s.top();
	s.pop();
	top2 = s.top(); s.pop();
	return top2 - top1;
}
int div(stack<int>s)
{
	int top2;
	int top1;
	top1 = s.top();
	s.pop();
	top2 = s.top(); s.pop();
	return top2 / top1;
}

int determine_priority(char ch)
{
	if (ch == '*' ||  ch == '/') return 2;
	else if (ch == '+' || ch == '-') return 1;
	else return -1;
}

bool opOrNot(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

string edit(string str)
{
	string s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i+1] != '+' && str[i+1] != '-' && str[i+1] != '*' && str[i+1] != '/' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			s = s + str[i];
		else if ((str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/') && (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/'))
		{
			s = s + str[i] + " ";
		}
		else
			s = s + str[i] ;
	}
	return s;
}
///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string &s)
{
	// Fill this in

	string result;
	stack<char>stack;
	string infix = s,str1,str2;
	int i = 0,j;
	infix.erase(std::remove_if(infix.begin(), infix.end(), ::isspace), infix.end());
	if (infix[0] == '-') {
		for (j = 1; j < infix.length(); j++) {
			str1 += infix[j];
		}
	}
	for (; i < infix.length(); i++)
	{
		
		if (infix[i] == '0' || infix[i] == '1' || infix[i] == '2' || infix[i] == '3' || infix[i] == '4' || infix[i] == '5'
			|| infix[i] == '9' || infix[i] == '6' || infix[i] == '7' || infix[i] == '8' )
		{
			result += infix[i];
			if (infix[i + 1] == '+' || infix[i + 1] == '-' || infix[i + 1] == '*' || infix[i + 1] == '/' || infix[i + 1] == '(' || infix[i + 1] == ')')
			{
				result += " ";
			}
		}
		else if (infix[i] == '(') {
			stack.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while ((stack.top() != '(') && (!stack.empty())) {
				
				result += stack.top();
				result += " ";
				stack.pop();
			}
			stack.pop();
		}
		else //if (opOrNot(infix[i]) == true)
		{
			while (!stack.empty() && determine_priority(infix[i]) <= determine_priority(stack.top())) {
				result += stack.top();
				result += " ";
				stack.pop();
			}
			stack.push(infix[i]);
			
			/*if (stack.empty())
			{
				stack.push(infix[i]);
			}
			else
			{
				if (determine_priority(infix[i]) > determine_priority(stack.top()))
				{
					stack.push(infix[i]);
				}
				else if ((determine_priority(infix[i]) == determine_priority(stack.top())) && (infix[i]=='+' || infix[i]=='-'))
				{
					
					result += stack.top();
					stack.pop();
					stack.push(infix[i]);
				}
				else
				{
					while ((!stack.empty()) && (determine_priority(infix[i]) <= determine_priority(stack.top())))
					{
						
						result += stack.top();
						result += " ";
						stack.pop();
					}
					stack.push(infix[i]);
				}
			}*/
		}


	}
	//For return a postfix representation of eq
	while (!stack.empty()) {
		result += stack.top();
		//result += " ";
		stack.pop();
	}
	/*if (infix[0] == '-')
		str2 += infix[0];
		{
		for (j = 0; j < result.length(); j++) {
			str2 += result[j];
		}
		result = str2;
		}
		*/
	result = edit(result);
	string strNum;
	//postfix.erase(std::remove_if(postfix.begin(), postfix.end(), ::isspace), postfix.end());
	string nstr;

	//loop through the characters of the input string
	for (int i = 0; i < result.length(); ) {
		//check if character is white space
		if (result[i] == ' ') {
			/*
			  *do not include the white space, if-
			  *it is at the trailing or leading position
			*/
			if (i == 0 || i == result.length() - 1) {
				i++;
				continue;
			}

			/*
			  *if space is inbetween then skip it-
			  *except the last occurrence
			*/
			while (result[i + 1] == ' ')
				i++;
		}

		//concatenate the character to the new string
		nstr += result[i++];
	}
	return nstr;

}// end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {

	stack<int>calculate;
	int i;
	int num;
	int newTop;
	int flag=0;
	string postfix = s;
	string strNum;
	string nstr;

	for(i=0;i< s.length();i++)
	{
		/*if ( postfix[0] == '-' && i==0)
		{
			flag = -1; i++;
		}
*/

		if (postfix[i] == '0' || postfix[i] == '1' || postfix[i] == '2' || postfix[i] == '3' || postfix[i] == '4' || postfix[i] == '5'
			|| postfix[i] == '9' || postfix[i] == '6' || postfix[i] == '7' || postfix[i] == '8')
		{
				strNum += postfix[i];
			
		}
		if (postfix[i] == ' ' && strNum!="")
		{
			/*if (flag == -1) {
				num = stoi(strNum);
				num = num * (-1);
				calculate.push(num);
				strNum = "";
				flag = 0;
			}
			if(flag==0 && strNum != "") {*/
			/*	if (postfix[i - 1] == '-') {
					num = num * (-1);
				}*/
				num = stoi(strNum);
				calculate.push(num);
				strNum = "";
		/*	}*/

		}
		if (postfix[i] == '*'&& calculate.size() > 1)
		{
			
			newTop=mult(calculate);
			calculate.pop();
			calculate.pop();
			calculate.push(newTop);
		}
		if (postfix[i] == '-' && i!=0 && calculate.size()>1) {

			
			newTop = subs(calculate);
			calculate.pop();
			calculate.pop();
			calculate.push(newTop);
		}
		if (postfix[i] == '+'&& calculate.size() > 1)
		{
			newTop=add(calculate); 
			calculate.pop(); 
			calculate.pop();
			calculate.push(newTop);
		}
		if (postfix[i] == '/'&& calculate.size() > 1)
		{
			newTop = div(calculate); 
			calculate.pop(); 
			calculate.pop();
			calculate.push(newTop);
		}

	}
	int top = calculate.top();
	return top;
} // end-EvaluatePostfixExpression

