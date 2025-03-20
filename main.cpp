#include <iostream>
#include <vector>
#include "ALGORITHM_1_LFCO_2025_JC_AP.h"
#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
#include "ALGORITHM_3_LFCO_2025_JC_AP.h"

using namespace std;

int main() {

    ALGORITHM_1_LFCO_2025_JC_AP p;

    //Generate 4 strings and put them into a vector, 2 valid and 2 invalid
    vector<string> strings;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0) {
            strings.push_back(p.generateGrammarStrings());
        } else {
            strings.push_back(p.generateNonGrammarStrings());
        }
    }
    
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }


    return 0;
}