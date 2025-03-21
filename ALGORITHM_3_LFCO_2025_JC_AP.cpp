#include "ALGORITHM_3_LFCO_2025_JC_AP.h"
#include <stack>
#include <iomanip> 

void ALGORITHM_3_LFCO_2025_JC_AP::printProccess(string string_to_Check)
{
    string s1 = "Rule";
    string s2 = "Sentential";
    string s3 = "ConfigutionM";

    printer(s1, s2, s3);
    stack<char> stack;
    stack.push('#');
    string currentState = "q0";

    s1 = "";
    s2 = string_to_Check;
    s3 = "("+ currentState + "," + string_to_Check  + "," + stackToString(stack) + ")";
    printer(s1, s2, s3);
    
    

    for (int i = 0; i <= string_to_Check.length(); i++) {
        if ((currentState == "q0") && (string_to_Check[i] == 'a') && (stack.top() == '#' || stack.top() == 'A')) {
            stack.push('A');
            
            continue;
        } else if ((currentState == "q0") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            currentState = "q1";
            stack.pop();
            continue;
        } else if ((currentState == "q1") && (string_to_Check[i] == 'b') && (stack.top() == 'A'))
        {
            stack.pop();
            continue;
        } else if ((currentState == "q1") && (string_to_Check.length() == i ) && (stack.top() == '#'))
        {
            cout << "String is accepted" << endl;
            return;
        }       
    }
}

void ALGORITHM_3_LFCO_2025_JC_AP::printer(string str1, string str2, string str3)
{
    cout << left
    << setw(15) << str1
    << setw(10) << str2
    << setw(10) << str3
    << endl;
}
string ALGORITHM_3_LFCO_2025_JC_AP::stackToString(stack<char> s) {
    string result;

    while (!s.empty()) {
        result += s.top();  // Append the character
        s.pop();
    }

    return result;
}

