#include "ALGORITHM_1_LFCO_2025_JC_AP.h"

string ALGORITHM_1_LFCO_2025_JC_AP::generateGrammarStrings()
{
    string string_to_push = "";
    int length_string = (rand() % 4) * 2;

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
    string string_to_push = "";
    int length_string = (rand() % 4 + 1) * 2;

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
    // check that this string is invalid with the second algorithm
    /*
    do {
        for (int i = 0; i < length_string; i++) {
        if (rand() % 2 == 0) {
            string_to_push += 'a';
        } else {
            string_to_push += 'b';
        }
    }
    } while (checkString(string_to_push) == true);
    */

    return string_to_push;
}
