#include <iostream>
#include <vector>
#include "ALGORITHM_1_LFCO_2025_JC_AP.h"
#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include "ALGORITHM_3_LFCO_2025_JC_AP.h"

using namespace std;

int main() {

    ALGORITHM_1_LFCO_2025_JC_AP p1;

    //Generate 4 strings and put them into a vector, 2 valid and 2 invalid
    vector<string> strings;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0) {
            strings.push_back(p1.generateGrammarStrings());
        } else {
            strings.push_back(p1.generateNonGrammarStrings());
        }
    }
    
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
    
    ALGORITHM_2_LFCO_2025_JC_AP p2;
    for (int i = 0; i < strings.size(); i++) {
        cout << p2.stringCheck(strings[i]) << endl;
    }

    ALGORITHM_3_LFCO_2025_JC_AP p3;
    for (int i = 0; i < strings.size(); i++) {
        p3.printProccess(strings[i]);
    }


    return 0;
}