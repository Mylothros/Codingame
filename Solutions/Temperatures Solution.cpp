#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;    
    cin >> n;
    
    int result=0, result1, i, t;
    
    for (i = 0; i < n; i++)
    {       
        cin >> t;
        
        if(i == 0)//saving the first temperature as the result
        {
            result1 = t;
            result = t;
        }
        
        if(i!=0)//checking from second temperature 
        {
            if(abs(result1) == abs(t))//if they are equal
            {
                if(result1 == t)//if they are both negatives the result should -5
                {
                    result = result1;    
                }
                else//if one is -5 and other 5 then the result should 5
                {
                    result = abs(result1);
                    result1 = abs(result1);
                }
            }            
            if(abs(result1) > abs(t))//next temperature is the new result
            {
                result = t;
                result1 = t;
            }           
        }
    } 
    cout << result;
}
