#include <iostream>
#include <algorithm>

using namespace std;

int main()
{    
    string b;
    getline(cin, b);   
    int counter[b.size() + 1] = {0},  holder[b.size() + 1], c=0;
    /*Counter is an array to count the '1' in the string and holder
     is the array which holds all the '1' before and after a '0' (line 24). The length is b.size() + 1
     because all characters (numbers) could be 1. If all characters are '0' then the length should be +1 because
     if there are 2 '0' then the for in line 22 will run in range 0 to 1. So if i = 1 then counter[i + 1] will go out of bounds in line 24.
    */
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == '1')counter[c]++;             
        else c++;          
    }
    
    for(int i = 0; i < c; i++)
    {
        holder[i] = counter[i] + counter[i+1] +1 ;
    }
    
    cout<<*max_element(holder, holder + c);    
}