#include <iostream>
#include <string>

using namespace std;

int funct (int *output, int *ready, string *operation, string *arg1, string *arg2, int i);

int main() {
    int N;
    cin >> N; cin.ignore();

    int ready[N], output[N];
    string operation[N], arg1[N], arg2[N];
    
    for (int i = 0; i < N; i++)
    {
        cin >> operation[i] >> arg1[i] >> arg2[i]; cin.ignore();
        ready[i] = 0;//to see if the recursion in the cell has been made before to stop it from doing it again line 29
    }
    
    for (int i = 0; i < N; i++)
         cout << funct (output, ready, operation, arg1, arg2, i) << endl;
}

int funct (int *output, int *ready, string *operation, string *arg1, string *arg2, int i)
{
    int a, b;

    if (ready[i] == 0)
    {
        if (arg1[i][0] == '$')
            a = funct (output, ready, operation, arg1, arg2, stoi(arg1[i].substr(1)));//if the argument1 begins with $ make recursion
        else
            a = stoi(arg1[i]);//else take the value and save it in b

        if (arg2[i][0] == '$')
            b = funct (output, ready, operation, arg1, arg2, stoi(arg2[i].substr(1)));//if the argument2 begins with $ make recursion
        else if (arg2[i][0] != '_')//else if the argument 2 is not _ then save in b the value
            b = stoi(arg2[i]);

        if (operation[i] == "VALUE")
            output[i] = a;
        else if (operation[i] == "ADD")
            output[i] = a + b;
        else if (operation[i] == "SUB")
            output[i] = a - b;
        else if (operation[i] == "MULT")
            output[i] = a * b;
            
        ready[i] = 1;
    }
    
    return output[i];
}