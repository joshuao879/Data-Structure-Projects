#include <iostream>
#include <string>
#include <stack>
#include <queue>

#include "evalExp.h"

using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;
using std::min;
using std::max;


bool isValidExpression(const string &exp) {
     bool balance = true;
     stack<char> stack; 
    
     for (int i = 0; i < exp.size(); i++) {

         if (exp[i] == '(') {
             stack.push(exp[i]); 
         }
         else if (exp[i] == ')') {
             
            if (stack.empty()) {
                balance = false; 
            }
            else {
                stack.pop();
            }
        } 
    }
    return balance;
}
    // Your code

queue<string> parseExpression(const string &exp) {
    queue<string> result; 
    string number;
    for (int i = 0; i < exp.size(); i++) {

        //   if (exp[i] >= '0' and exp[i] <= '9') {
        //       number += exp[i]; 
        //       result.push(number);
        //   }
        //    number = "";

          if (exp[i] >= '0' and exp[i] <= '9') {
              number = exp[i]; 
               std::string val1;
               std::string val2; 
               std::string val3; 
               std::string val4;
               std::string val5;
               std::string val6;
               val1.push_back(exp[i]);
               val2.push_back(exp[i+1]);
               val3.push_back(exp[i+2]);
               val4.push_back(exp[i+3]);
               val5.push_back(exp[i+4]);
               val6.push_back(exp[i+5]);

              if (exp[i+1] >= '0' and exp[i+1] <= '9') {
                  //val1.push_back(exp[i]);
                 // val2.push_back(exp[i+1]);
                  number += val2;
                  //result.push(number);
                  i++;
              }
              if (exp[i+1] >= '0' and exp[i+1] <= '9') {
                  number += val3;
                  i++;
              }
              if (exp[i+1] >= '0' and exp[i+1] <= '9') {
                  number += val4;
                  i++;
              }
              if (exp[i+1] >= '0' and exp[i+1] <= '9') {
                  number += val5;
                  i++;
              }
              if (exp[i+1] >= '0' and exp[i+1] <= '9') {
                  number += val6;
                  i++;
              }
      
              result.push(number);
              }
           number = "";


        if (exp[i] == 'm') {
            if (exp[i+1] == 'a') {
                result.push("max");
            }
            else if (exp[i+1] == 'i') {
                result.push("min");
             }
         }


        if (exp[i] == '-' or exp[i] == '/' or exp[i] == '*' or exp[i] == '+' or exp[i] == ')' 
        or exp[i] == '(' or exp[i] == ',') {
            string temp;
            temp.push_back(exp[i]);
            result.push(temp);
        }
    }
    return result;
}

bool checkPrec(const string &opr1, const string &opr2) {
    /* 
        Returns true if opr1 has higher or equal precedence as opr2.
        Returns false if opr1 has loWer precedence than opr2.
    */
    if ((opr1 == "(") or
        (opr1 == "+" and opr2 == "*") or
        (opr1 == "+" and opr2 == "/") or
        (opr1 == "-" and opr2 == "*") or
        (opr1 == "-" and opr2 == "/")) {
            return false;
    } else {
        return true;
    }
}

queue<string> inFixToPostFix(queue<string> &exp){
    queue<string> postfix; 
    stack<string> operators; 


//supposed to be until stack is empty not ur initial queue;
    while(!exp.empty()) {
        if (exp.front() >= "0" and exp.front() <= "9") {
            //cout << "yes" << endl;
            postfix.push(exp.front());
            exp.pop(); 
        }
        else if (exp.front() == "(") {
            //cout << "cool" << endl;
            operators.push(exp.front());
            exp.pop();
        }
        else if (exp.front() == ")") {
             while (operators.top() != "(") {
                //cout << "WASSUP" << endl;
                string temp = operators.top();
                operators.pop();
                postfix.push(temp); // enqueue the popped operator;
            } // while the popped operator is not left parenthesis
             exp.pop(); 
        }
        else if (exp.front() == "+" or exp.front() == "-" or exp.front() == "/" or exp.front() == "*") {
            if (operators.empty()) {
                //cout << "ok" << endl;
                operators.push(exp.front());
                exp.pop(); 
            }
            else {
                    string topstack = operators.top();
                    string current = exp.front();
                while (checkPrec(operators.top(), exp.front()) == true) {
                    postfix.push(topstack);
                    operators.pop();
                }
                    operators.push(current);
                    exp.pop();
            } 
        }
        else if (exp.front() == "min" or exp.front() == "max") {
        //     if (operators.empty()) {
        //         //cout << "ok" << endl;
                operators.push(exp.front());
                exp.pop(); 
        }
        //     }
        //     else {
        //     string temp3 = operators.top();
        //     operators.pop();
        //     postfix.push(temp3);
        //     }
        // }

        else if (exp.front() == ",") {
            while (operators.top() != "(") {
                //cout << "alright" << endl;
               string temp3 = operators.top();
               operators.pop();
               postfix.push(temp3);
            }
            exp.pop();
        }

    }
     while (!operators.empty()) {
         //maybe change later if problems
         if (operators.top() == "(" or operators.top() == ",") {
             operators.pop();
         }
         else {
           string temp4 = operators.top();
           operators.pop();
           postfix.push(temp4);  
         }
     }



    return postfix;
    // Your code
}

int EvalPostFixExp(queue<string> &exp) {
    //note that exp is in postfix form;
       stack<int> store; 
       while (!exp.empty()) {
           if (exp.front() >= "0" and exp.front() <= "9") {
               int num = stoi(exp.front());
               store.push(num);
               exp.pop();
           }
           else if (exp.front() == "+" or exp.front() == "-" or exp.front() == "/" or exp.front() == "*" or exp.front() == "min" or exp.front() == "max") {
               int val1 = store.top();
               store.pop();
               int val2 = store.top();
               store.pop();

               if (exp.front() == "+") {
                   int sum = val1 + val2;
                   store.push(sum);
               }
                if (exp.front() == "*") {
                   int product = val1 * val2;
                   store.push(product);
               }
                if (exp.front() == "-") {
                   int difference = val2 - val1;
                   store.push(difference);
               }
                if (exp.front() == "/") {
                   int quotient = val2 / val1;
                   store.push(quotient);
               }
                 if (exp.front() == "min") {
                   int minimum = min(val1, val2);
                   store.push(minimum);
               }
                 if (exp.front() == "max") {
                   int maximum = max(val1, val2);
                   store.push(maximum);
               }
               //do computation and push result onto the stack;
               exp.pop();
           }
       }
       return store.top();
    //return top value (the only value) in stack.
}

int EvalExp(const string &exp) {
    if (!isValidExpression(exp)) {
        return -1024;
    } else {
        queue<string> parsedExp = parseExpression(exp);
        queue<string> postFixExp = inFixToPostFix(parsedExp);
        int x = EvalPostFixExp(postFixExp);
        return x;
    }
}

void Print(queue<string> &exp) {
    while (!exp.empty()) {
        cout << " " << exp.front() << " ->";
        exp.pop();
    }
cout << endl;

}