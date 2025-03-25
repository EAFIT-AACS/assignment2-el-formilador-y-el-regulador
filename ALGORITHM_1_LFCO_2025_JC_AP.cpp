#include "ALGORITHM_1_LFCO_2025_JC_AP.h"
#include "ALGORITHM_2_LFCO_2025_JC_AP.h"
string ALGORITHM_1_LFCO_2025_JC_AP::generateGrammarStrings()
{
    // generate a string with the same number of a's and b's, but with a's first
    // length of the string is between 0 and 10
    string string_to_push = "";
    int length_string = (rand() % 5) * 2;

    for (int j = 0; j < length_string / 2; j++)
    {
        string_to_push += 'a';
    }

    for (int j = 0; j < length_string / 2; j++)
    {
        string_to_push += 'b';
    }

    return string_to_push;
}

string ALGORITHM_1_LFCO_2025_JC_AP::generateNonGrammarStrings()
{
    // generate a string with the same number of a's and b's, but with b's first
    // length of the string is between 0 and 10
    string string_to_push = "";
    int length_string = (rand() % 10 + 1) ;

    
    // check that this string is invalid with the second algorithm
    ALGORITHM_2_LFCO_2025_JC_AP p2;
    do {
        for (int i = 0; i < length_string; i++)
        {
            if (rand() % 2 == 0)
            {
                string_to_push += 'a';
            }
            else
            {
                string_to_push += 'b';
            }
        }
    } while (p2.stringCheck(string_to_push) == true);
    

    return string_to_push;
}
