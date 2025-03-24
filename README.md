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


## 📖 Description
Implementation of three algorithms in the following order: creation of strings according to grammar, validation of the strings, creation of the sentential form, and configuration of the automaton.

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

### Algorithm 2
For this algorithm, we used a function that uses a string and returns true if is accepted or false otherwise.
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

((q0,b,A),(q1,#)) 

((q1,b,A),(q1,#)) 

((q1,epsilon,#),(q1,#))

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
