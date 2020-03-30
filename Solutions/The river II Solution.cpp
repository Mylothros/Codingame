#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(int r1, int r2, int r3, int r1sum, int m, int sum)
{
    while(r1sum > 0)//finding the sum of the digits of r1
    {    
        m = r1sum % 10;    
        sum = sum + m;    
        r1sum = r1sum /10;  
    }
    
    r1 = r1 + sum;
    sum = 0;

    if(r1 == r3)//if r1 == r3 then it is true
    {
        cout << "YES";
    }
    else
    {
        r1 = r2 - 1;//trying the next number if it is false (r2 holds the first value of r1 line 44-45)
        r2 = r1;
        r1sum = r1;
        if(r1 == 0)//if r1 == 0 it means that there is not a meeting point
        {
            cout <<"NO";
        }
        else
        {
            calculate(r1, r2, r3, r1sum, m, sum);
        }
    }
}

int main()
{
    int r1, r2, r3;
    cin >> r3;
    
    r1 = r3 - 1;
    r2 = r1;
    
    int r1sum = r1, r3sum = r3, m, sum = 0;
    
    calculate(r1, r2, r3, r1sum, m, sum);
}