#include <iostream>
#include <vector>
#include "ALGORITHM_1_LFCO_2025_JC_AP.h"
#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include "ALGORITHM_3_LFCO_2025_JC_AP.h"

using namespace std;

int main() {
    //Generate 16 strings and put them into a vector, 8 valid and 8 invalid
    ALGORITHM_1_LFCO_2025_JC_AP p1;
    vector<string> strings;

    cout << "Generating strings" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0) {
            strings.push_back(p1.generateGrammarStrings());
        } else {
            strings.push_back(p1.generateNonGrammarStrings());
        }
    }
    //Print the strings
    for (int i = 0; i < strings.size(); i++) {
        cout << "\u2A7C String: " << strings[i] << endl;
    }
    cout << endl << endl;




    //Print the PDA
    cout << "PDA" << endl;
    cout << "\u2713 Q = {q0,q1}" << endl;
    cout << "\u2713 Sigma = {a,b}" << endl;
    cout << "\u2713 Gamma = {A,#}" << endl;
    cout << "\u2713 Delta = \n{((q0,a,#),(q0,A#)) \n((q0,a,A),(q0,AA)) \n ((q0,b,A),(q1,epsilon)) \n ((q1,b,A),(q1,epsilon)) \n ((q1,epsilon,#),(q1,epsilon))}" << endl;
    cout << "\u2713 Starting state = q0" << endl;
    cout << "\u2713 Acceptance states = {q1}" << endl << endl << endl;
    cout << "Checking the strings" << endl;
    cout << "---------------------" << endl;

    //Check if the strings are valid
    vector<string> validStrings; 
    ALGORITHM_2_LFCO_2025_JC_AP p2;

   
    for (int i = 0; i < strings.size(); i++) {
        
        if (p2.stringCheck(strings[i])) {
            validStrings.push_back(strings[i]);
            cout << "\u2705 The String: " << strings[i] << " is accepted by the PDA." << endl;
        }
        else {
            cout << "\u274C The String: " << strings[i] << " is rejected by the PDA." << endl;
        }
    }
    cout << endl << endl;


    //Print the sentential form and configuration of the valid strings
    cout << "Sentential Form and Configuration of the valid strings" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Rule 1 - S -> aSb" << endl;
    cout << "Rule 2 - S -> \U000003B5" << endl;
    cout << endl;


    
    ALGORITHM_3_LFCO_2025_JC_AP p3;
    for (int i = 0; i < validStrings.size(); i++) {
        cout << "------------------------------------------------------" << endl;
        cout << "String: " << validStrings[i] << endl;
        cout << endl;
        p3.sentential(validStrings[i]);
        cout << endl;
        cout << endl;
        p3.configurationM(validStrings[i]);
        cout << "------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        
    }

    return 0;
}