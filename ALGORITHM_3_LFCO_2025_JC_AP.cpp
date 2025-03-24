#include "ALGORITHM_3_LFCO_2025_JC_AP.h"
#include <stack>
#include <algorithm>
#include <iomanip>


void ALGORITHM_3_LFCO_2025_JC_AP::sentential(string string_to_Check) {
    
    string builder = "S";

    cout << setw(10) << "Rule" << setw(20) << "Sentential" << endl;

    for (int i = 0; i <= string_to_Check.size()/2; i++) {
        if (i == 0) {
            cout << setw(10) << "" << setw(20) << builder << endl;
            continue;
        }
        
        builder = "a" + builder + "b";
        cout << setw(10) << "Rule 1" << setw(20) << builder << endl;

        if (i == string_to_Check.size()/2){
            builder.erase(remove(builder.begin(), builder.end(), 'S'), builder.end());
            cout << setw(10) << "Rule 2" << setw(20) << builder << endl;
        }
    }

    if (string_to_Check == "") {
        cout << setw(10) << "Rule 2" << setw(20) << "" << endl;
        return;
    }
}

void ALGORITHM_3_LFCO_2025_JC_AP::configurationM(string string_to_Check) {
    stack<char> stack;
    stack.push('#');
    string currentState = "q0";
    string currentString = string_to_Check;

    string builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";

    cout << "Configurations an accepting computation of M on input x" << endl;
    cout << setw(10) << builder2 << endl;

    for (int i = 0; i <= string_to_Check.size(); i++) {
        if ((currentState == "q0") && (string_to_Check[i] == 'a') && (stack.top() == '#' || stack.top() == 'A')) {
            stack.push('A');
            currentString.erase(0, 1);

            builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
            cout << setw(10) << builder2 << endl;

            continue;
        } else if ((currentState == "q0") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            currentState = "q1";
            stack.pop();
            currentString.erase(0, 1);

            builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
            cout << setw(10) << builder2 << endl;

            continue;
        } else if ((currentState == "q1") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            stack.pop();
            currentString.erase(0, 1);

            builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
            cout << setw(10) << builder2 << endl;

            continue;
        } else if ((currentState == "q1") && (i == string_to_Check.length()) && (stack.top() == '#'))
        {
            stack.pop();

            builder2 = "(" + currentState + ", " + currentString + ", " + "" + ")";
            cout << setw(10) << builder2 << endl;
            
            return;
        }
    }
}

string ALGORITHM_3_LFCO_2025_JC_AP::stackToString(stack<char> stack) {
    string stackString = "";
    while (!stack.empty()) {
        stackString += stack.top();
        stack.pop();
    }
    return stackString;
}