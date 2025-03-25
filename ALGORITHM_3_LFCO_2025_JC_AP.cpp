#include "ALGORITHM_3_LFCO_2025_JC_AP.h"
#include <stack>
#include <algorithm>
#include <iomanip>


void ALGORITHM_3_LFCO_2025_JC_AP::sentential(string string_to_Check) {
    
    string builder = "S";

    cout << setw(10) << "Rule" << setw(20) << "Sentential" << endl;

    for (int i = 0; i <= string_to_Check.size()/2; i++) {

        // In the first iteration of the loop, print the builder string under the "Sentential" column
        if (i == 0) {
            cout << setw(10) << "" << setw(20) << builder << endl;
            continue;
        }
        
        // Add the characte 'a' and the character 'b' to the head and tail, respectively, of the builder string
        builder = "a" + builder + "b";
        cout << setw(10) << "Rule 1" << setw(20) << builder << endl;

        // On the last iteration, remove the character 'S' from the builder string
        if (i == string_to_Check.size()/2){
            builder.erase(remove(builder.begin(), builder.end(), 'S'), builder.end());
            cout << setw(10) << "Rule 2" << setw(20) << builder << endl;
        }
    }

    // If the string is "", print builder and the apply the second rule
    if (string_to_Check == "") {
        cout << setw(10) << "" << setw(20) << builder << endl;
        cout << setw(10) << "Rule 2" << setw(20) << "" << endl;
        return;
    }
}

void ALGORITHM_3_LFCO_2025_JC_AP::configurationM(string string_to_Check) {
    stack<char> stack;
    stack.push('#');
    string currentState = "q0";

    // Create a string that's a copy of the parameter
    string currentString = string_to_Check;

    // Create a builder2 variable made of (state, string, elements of the stack)
    
    cout << "Accepting computation of M on input x" << endl << endl;    


    cout << left << setw(10) << "State" 
         << setw(10) << "String" 
         << setw(10) << "Stack" 
         << endl;

    cout << left << setw(10) << currentState
         << setw(10) << currentString
         << setw(10) << stackToString(stack)
         << endl;
         
    for (int i = 0; i <= string_to_Check.size(); i++) {
        // Analog to the first and second transitions, pushes 'A' into the stack and erases the first character of currentString
        if ((currentState == "q0") && (string_to_Check[i] == 'a') && (stack.top() == '#' || stack.top() == 'A')) {
            stack.push('A');
            currentString.erase(0, 1);

            cout << left << setw(10) << currentState
            << setw(10) << currentString
            << setw(10) << stackToString(stack)
            << endl;

            continue;
        }
        // Analog to the third transition, changes the value of currentState to "q1", pops the top of the stack and erases the first character of currentString 
        else if ((currentState == "q0") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            currentState = "q1";
            stack.pop();
            currentString.erase(0, 1);

            cout << left << setw(10) << currentState
            << setw(10) << currentString
            << setw(10) << stackToString(stack)
            << endl;

            continue;
        } 
        // Analog to the fourth transition, pops the top of the stack and erases the first character of currentString 
        else if ((currentState == "q1") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            stack.pop();
            currentString.erase(0, 1);

            if (currentString == "") {
                currentString = "\U000003B5";
            }

            cout << left << setw(10) << currentState
            << setw(10) << currentString
            << setw(10) << stackToString(stack)
            << endl;

            continue;
        } 
        // Analog to the fifth transition, pops the top of the stack
        else if ((currentState == "q1") && (i == string_to_Check.length()) && (stack.top() == '#'))
        {
            stack.pop();
            currentString = "\U000003B5";

            cout << left << setw(10) << currentState
            << setw(10) << currentString
            << setw(10) << stackToString(stack)
            << endl;
            
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