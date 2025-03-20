#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include <stack>

bool ALGORITHM_2_LFCO_2025_JC_AP::stringCheck(string string_to_Check) {
        stack<char> stack;

        //If the string's length is 0, the PDA will accept it
        if (string_to_Check.empty()) {
            return true;
        }
        
        //If the string is odd, the PDA will reject it
        if (string_to_Check.length() % 2 == 1) {
            return false;
        }
        
        //If the string's length is even, we check if the string is accepted by the PDA
        for (int j = 0; j < string_to_Check.length(); j++) {
            if (string_to_Check[j] == 'a') {
                stack.push('A');
            } else {
                if (string_to_Check[j] == 'b') {
                    if(!stack.empty()) {
                        stack.pop();
                    }
                    
                }
            }
        }

        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
}

