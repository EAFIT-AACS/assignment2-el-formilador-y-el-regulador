#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include <stack>

bool ALGORITHM_2_LFCO_2025_JC_AP::stringCheck(string string_to_Check) {
        stack<char> stack;
        stack.push('#');
        string currentState = "q0";

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
                return true;
            } else {
                return false;
            }
            
        }

        if (string_to_Check == "") {
            return true;
        }

        return false;
    }
    

