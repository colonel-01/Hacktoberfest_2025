/*
 * LeetCode Problem 3703 – Partial Solution
 * Contest: Weekly Contest 470
 *
 * Solves approximately 456 of 1012 test cases.
 * The current issue lies in the left/right counter logic,
 * which fails for cases such as "()()".
 * Further debugging is in progress to refine the counter handling.
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RemoveSubString{
    private:
        vector<char> Stack;
        int k_balancer=1;
        int open_bracket=0,close_bracket=0;
        string items_to_delete,result;
    public:
        void input(string &expression,int &substring){
            cout<<"Enter the string to perform operation : ";
            getline(cin,expression);
            cout<<"Enter K : ";
            cin>>substring;
        }

        void output(string expression){
            cout<<"The remainder is : "<<expression;
        }

        bool CheckBracket(char bracket){
            return bracket=='(';
        }

        string RemoveKBrackets(string s,int k);

        void RemoveElements();
};

string RemoveSubString::RemoveKBrackets(string s,int k){
    for(char paranthesis:s){
        if(CheckBracket(paranthesis)){
            Stack.push_back(paranthesis);
        }
        else if(!CheckBracket(paranthesis) && k_balancer==k){
            Stack.push_back(paranthesis);
            RemoveElements();
        }
        else if(!CheckBracket(paranthesis) && k_balancer<k){
            Stack.push_back(paranthesis);
            k_balancer++;
        }
    }
    if(Stack.size()!=0){
        for(char bracket:Stack)
            result+=bracket;
    }
    return result;
}

void RemoveSubString::RemoveElements(){
    int Iterator=2*k_balancer;

    for(int i=0;i<Iterator;i++){
        //Exiting the loop because theres No consecutive )) thus telling its not encapsulated  
        if(CheckBracket(Stack.back()) && k_balancer>1 && items_to_delete=="")
            return;
        //Incase I have popped extra ) into the deleted string then encountered a (
        else if (CheckBracket(Stack.back()) && k_balancer>1){
            for(char paranthesis : items_to_delete)
                Stack.push_back(paranthesis);
            return;
        }
        //Popping k-length substring from the stack as we have encountered the right amount of ) brackets 
        else{
            char popped=Stack.back();
            Stack.pop_back();
            items_to_delete+=popped;
            if(CheckBracket(popped)){
                open_bracket++;
            }
            else{
                close_bracket++;
                k_balancer--;
            }
        }
    }

    if(open_bracket==close_bracket){
        items_to_delete.clear();
    }
    else{
        for(char bracket:items_to_delete)
            Stack.push_back(bracket);
        items_to_delete.clear();
    }
    //resetting k_balancer incase theres more substrings
    k_balancer=1;
}

int main(){
    string exp,Final_result;
    int K;
    RemoveSubString Operation;
    Operation.input(exp,K);
    Final_result=Operation.RemoveKBrackets(exp,K);
    Operation.output(Final_result);
    return 0;
}