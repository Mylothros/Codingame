#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    for (int i = 0; i < N; i++) 
    {
        int y=0,u;
        string x;
        getline(cin, x);
        string j=x;
        int count=0;
        while(1)
        {
            count++;
            for(int i=0;i<x.size();i++)
            {      
                u = x[i]-'0';//converting the char x[i](which is the first digit of the number) to integer
                y += pow(u,2);//finding the sum of the squares and storing them into y
            }
            
            if(y == 1)//if y=1 then the number is happy number
            {
                cout << j <<" :)" << endl;
                break;
            } 
            
            if(y <= 30 && y%10 == 0 && y != 10)//these restrictions are foretelling if the number is unhappy number.
            {
                cout << j <<" :(" << endl;
                break;
            }
            
            x = to_string(y);
            y = 0;         
        }
    }
}