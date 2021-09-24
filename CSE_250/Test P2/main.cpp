#include <iostream>

#include "evalExp.h"

using std::string;
using std::stack;
using std::queue;
using std::cout;
using std::endl;
using std::min;
using std::max;

void Converter(string exp);


int main() {


string exp0 = "1222+200/10-9*5";
// string exp0 = "6734020+1243";




  queue<string> test = parseExpression(exp0);
  //Print(test);
  queue<string> answer = inFixToPostFix(test);
    Print(answer);
  //int result = EvalPostFixExp(answer);
 // cout << result << endl;





    return 0; 
}

void Converter(string exp) {
    string number;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] >= 0 or exp[i] <= 9) {
            number = exp[i];
            for (int j = i+1; j < exp.size(); j++) {
                if (exp[j] >= 0 or exp[j] <= 9) {
                    number += exp[j]; 
                }
            }
            break;
        }
}
}