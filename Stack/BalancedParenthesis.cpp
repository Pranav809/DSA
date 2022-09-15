#include<stack>
bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='['){
            s.push(expression[i]);
        }
        else if(expression[i]==')' || expression[i]=='{' || expression[i]==']'){
            if(s.empty())
                return false;
            
            char ch = s.top();
            s.pop();
            if(expression[i]==')' && ch=='(' ){
                continue;
            }
            else if(expression[i]=='}' && ch=='{'){
                continue;
            }
            else if(expression[i]==']' && ch=='['){
                continue;
            }
            else{
                return false;
            }
        }
    }
    
	return s.empty();
}

