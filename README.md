# 📌 Project README
```
██████╗ ██████╗  █████╗  
██╔══██╗██╔══██╗██╔══██╗ 
██████╔╝██║  ██║███████║ 
██╔═══╝ ██║  ██║██╔══██║ 
██║     ██████╔╝██║  ██║ 
╚═╝     ╚═════╝ ╚═╝  ╚═╝
----------------------------
 ██████╗███████╗ ██████╗ 
██╔════╝██╔════╝██╔════╝ 
██║     █████╗  ██║  ███╗
██║     ██╔══╝  ██║   ██║
╚██████╗██║     ╚██████╔╝
 ╚═════╝╚═╝      ╚═════╝ 
```
# 📌 Table of Contents

1. [📖 Description](#-description)
2. [📚 Class Information](#-class-information)
3. [👨‍🏫 Teacher](#-teacher)
4. [👨‍🎓 Students](#-students)
5. [💻 System Information](#-system-information)
6. [🚀 Running](#-running)
    - [Compilation](#compilation)
    - [Execution](#execution)
7. [📖 Explanation](#-explanation)
    - [Algorithm 1](#algorithm-1)
    - [Algorithm 2](#algorithm-2)
    - [Algorithm 3](#algorithm-3)

## 📖 Description
This project focuses on implementing and analyzing a Context-Free Grammar (CFG) and a Pushdown Automaton (PDA) for language recognition. It consists of implementation of three main algorithms in the following order:

+ String Generation according to the grammar G
+ PDA that recognizes strings from the CFG.
+ Leftmost derivation tree for sentential form and configuration of the PDA.

## 📚 Class Information
- **Class Number:** 7308  

## 👨‍🏫 Teacher
- **Adolfo Andrés Castro Sánchez** 

## 👨‍🎓 Students
- **Jeronimo Campuzano Castaño** 
- **Andres Perez Quinchia**  

## 💻 System Information
- **OS:** Ubuntu 24.04.2 LTS x86_64  
- **Programming Language:** C++  
- **Compiler Version:** g++ 13.3.0  

---

## 🚀 Running 
- **Compilation** To compile the project, use a C++ compiler to produce the binary file. Ensure to include all the .cpp files, here is an example with g++ in linux
```bash
g++ -o a ALGORITHM_1_LFCO_2025_JC_AP.cpp ALGORITHM_2_LFCO_2025_JC_AP.cpp ALGORITHM_3_LFCO_2025_JC_AP.cpp main.cpp
```
- **Execution** After this you will have the binary file in the same location you ran the comand.

```bash
./a
```

Here is an example with g++ in windows
```powershell
g++ -o a.exe ALGORITHM_1_LFCO_2025_JC_AP.cpp ALGORITHM_2_LFCO_2025_JC_AP.cpp ALGORITHM_3_LFCO_2025_JC_AP.cpp main.cpp
```
- **Execution** After this you will have the binary file in the same location you ran the comand.

```powershell
.\a.exe
```





## 📖 Explanation

### Algorithm 1
To generate valid strings, we first generate a random length that is a multiple of 2 and insert half 'a's first, followed by half 'b's. 
```cpp
string ALGORITHM_1_LFCO_2025_JC_AP::generateGrammarStrings()
{
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
```

For invalid strings, we generate a random length and insert 'a' or 'b' in any order. To ensure the string is truly invalid, we make slight use of Algorithm 2 to verify it. If the string is valid, we regenerate it until it becomes invalid, as requested.


```cpp
string ALGORITHM_1_LFCO_2025_JC_AP::generateNonGrammarStrings()
{
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
```

### Algorithm 2
For this algorithm, we used a function that uses one string and returns true if is accepted or false otherwise.
```cpp
bool ALGORITHM_2_LFCO_2025_JC_AP::stringCheck(string string_to_Check) 
```

As requested, the stack was created with its initial element and the initial state of the automaton.

```cpp
stack<char> stack;
stack.push('#');
string currentState = "q0";
```

Now we will start reading the string, and depending on the current state, the processed character, and the stack state, we will use one rule or another. In this way, if the automaton is not able to process a character under certain conditions, it will immediately reject the string. 

This are the transitions
((q0,a,#),(q0,A#)) 

((q0,a,A),(q0,AA)) 

((q0,b,A),(q1,epsilon)) 

((q1,b,A),(q1,epsilon)) 

((q1,epsilon,#),(q1,epsilon))

```cpp
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
    
```

### Algorithm 3
For the third algortihm, our implementation relied on two different functions:

+ The first method prints the proccess for the construction of the Sentential Form tree.
It recieves as a parameter an string, we then define a variable called builder of the string type and assing it the value of "S", and we print two columns: one for the rules and the other one for the builder string.

```cpp
string builder = "S";

cout << setw(10) << "Rule" << setw(20) << "Sentential" << endl;
```

We then create a for loop, that will repeat itself a number of times equal to half of the length of the string the method received as a parameter plus one (For example, if the string had a length of 4, the loop will repeat itself 3 times). Inside this loop, we make a condition, which says that, if it is the first iteration of the loop, it shall print the builder string on the second column and continue to the next iteration.

After that, each time the loop repeats itself, it will add the character 'a' at the head of the builder string and the character 'b' at the tail (which represents the First Rule), and then it prints the rule it just applied under the first column and the builder string under the second column. On the last iteration of the loop, which is identified by a conditional, the character 'S' is ereased from the builder string (which represents the Second Rule), and then prints therule it just applied under the first column and the builder string under the second column.

```cpp
for (int i = 0; i <= string_to_Check.size()/2; i++) {
        if (i == 0) {
            cout << setw(10) << "" << setw(20) << builder << endl;
            continue;
        }
        
        builder = "a" + builder + "b";
        cout << setw(10) << "Rule 1" << setw(20) << builder << endl;

        if (i == string_to_Check.size()/2){
            builder.erase(remove(builder.begin(), builder.end(), 'S'), builder.end());
            cout << setw(10) << "Rule 2" << setw(20) << builder << endl;
        }
    }

    if (string_to_Check == "") {
        cout << setw(10) << "Rule 2" << setw(20) << "" << endl;
        return;
    }
```

At the end there is also an special clause which states that, if the string that is being received as a parameter is an empty string, then it will print the first part as normal and then immediately apply the Second Rule

```cpp
if (string_to_Check == "") {
        cout << setw(10) << "" << setw(20) << builder << endl;
        cout << setw(10) << "Rule 2" << setw(20) << "" << endl;
        return;
    }
```

+ The second method prints the proccess for the constuction of the M Configuartion tree.
Much like the first method, it receives as a parameter a string, we then define some string type variables called builder2, currentState and currentString, aswell as a stack of characters called stack. We also print a single column which will contain all of the variations of the builder2 variable.

```cpp
stack<char> stack;
    stack.push('#');
    string currentState = "q0";
    string currentString = string_to_Check;

    string builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";

    cout << "Configurations an accepting computation of M on input x" << endl;
    cout << setw(10) << builder2 << endl;
```

For this, we also created a third function called stackToString, that creates an string with all the elements present in the stack by a while loop.

```cpp
string ALGORITHM_3_LFCO_2025_JC_AP::stackToString(stack<char> stack) {
    string stackString = "";
    while (!stack.empty()) {
        stackString += stack.top();
        stack.pop();
    }
    return stackString;
}
```

Then we create a for loop that will repeat itself a number of times equal to the size of the string plus one (For example, if the string had a length of 4, the loop will repeat itself 5 times). Inside the loop we create different conditionals, each one representing one of the transition functions of the PDA.

The first condition represents the transition functions ((q0,a,#),(q0,A#)) and ((q0,a,A),(q0,AA)). Inside, it will push the character 'A' into the stack, erase the first character of the currentString variable, update the builder2 variable and print the result.

```cpp
if ((currentState == "q0") && (string_to_Check[i] == 'a') && (stack.top() == '#' || stack.top() == 'A')) {
    stack.push('A');
    currentString.erase(0, 1);

    builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
    cout << setw(10) << builder2 << endl;

    continue;
}
```

The second condition represents the transition function ((q0,b,A),(q1,epsilon)). Inside, it will update the currentState variable, pop the top element of the stack, erase the first character of the currentString variable, update the builder2 variable and print.

```cpp
if ((currentState == "q0") && (string_to_Check[i] == 'b') && (stack.top() == 'A')) {
    currentState = "q1";
    stack.pop();
    currentString.erase(0, 1);

    builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
    cout << setw(10) << builder2 << endl;

    continue;
}
```

The third condition represents the transition function ((q1,b,A),(q1,epsilon)). Inside, it will pop the top element of the stack, erase the first character of the currentString variable, update the builder2 variable and print.

```cpp
if ((currentState == "q1") && (string_to_Check[i] == 'b') && (stack.top() == 'A')) {
    stack.pop();
    currentString.erase(0, 1);

    builder2 = "(" + currentState + ", " + currentString + ", " + stackToString(stack) + ")";
    cout << setw(10) << builder2 << endl;

    continue;
}
```
And last, the fourth condition represents the transition function ((q1,epsilon,#),(q1,epsilon)). Inside it will pop the top element of the stack, update the builder2 variable, print and stop the function.

```cpp
if ((currentState == "q1") && (i == string_to_Check.length()) && (stack.top() == '#')) {
    stack.pop();

    builder2 = "(" + currentState + ", " + currentString + ", " + "" + ")";
    cout << setw(10) << builder2 << endl;
            
    return;
}
```