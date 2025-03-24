#include <iostream>
#include <vector>
#include "ALGORITHM_1_LFCO_2025_JC_AP.h"
#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include "ALGORITHM_3_LFCO_2025_JC_AP.h"

using namespace std;

int main() {
     //Generate 4 strings and put them into a vector, 2 valid and 2 invalid
    ALGORITHM_1_LFCO_2025_JC_AP p1;

   
    vector<string> strings;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0) {
            strings.push_back(p1.generateGrammarStrings());
        } else {
            strings.push_back(p1.generateNonGrammarStrings());
        }
    }
    
    for (int i = 0; i < strings.size(); i++) {
        cout << "String: " << strings[i] << endl;
    }
    cout << endl << endl;



    //Check if the strings are valid
    vector<string> validStrings;
    ALGORITHM_2_LFCO_2025_JC_AP p2;
    for (int i = 0; i < strings.size(); i++) {
        
        if (p2.stringCheck(strings[i])) {
            validStrings.push_back(strings[i]);
            cout << "The String: " << strings[i] << " is accepted by PDA." << endl;
        }
        else {
            cout << "The String: " << strings[i] << " is rejected by PDA." << endl;
        }
    }
    cout << endl << endl;


    //Check the sentential form and configuration of the valid strings
    cout << "Sentential Form and Configuration of the valid strings" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Rule 1 - S -> aSb" << endl;
    cout << "Rule 2 - S -> epsilon" << endl;
    cout << endl;


    
    ALGORITHM_3_LFCO_2025_JC_AP p3;
    for (int i = 0; i < validStrings.size(); i++) {
        cout << "String: " << validStrings[i] << endl;
        cout << endl;
        p3.sentential(validStrings[i]);
        cout << endl;
        cout << endl;
        p3.configurationM(validStrings[i]);
        cout << endl;
        cout << endl;
        
    }

    return 0;
}