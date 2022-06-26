#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {

    string lhs = "0";
    string rhs = "0";
    char operand = '-';
    
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    if (lhs == "quit" || lhs == "q"){
        cout << "farvel!" << endl;
        return 0;
    }
    while (!(lhs == "quit" || lhs == "q")){
        cout << ">>" << " " << endl;
        cin >> lhs >> operand >> rhs;
        if (lhs == "quit" || lhs == "q"){
            cout << "farewell!";
            return 0;
        }   
        if (operand == '+'){
            cout << "ans =" << endl << endl << "    " << add(lhs, rhs) << endl << endl;
        }
        if (operand == '*'){
            cout << "ans =" << endl << endl <<  "    " << multiply(lhs, rhs) << endl << endl;
        }
    }
}

