#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,result,temp1,temp2,min; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        if (n == 1) //no temperatures are added
        {
            result=t;    
        }
        if (i == 0)
        {
            min=t;//setting the first temperature to be the min
        }
        else if (i >= 1)
        {
            if (abs(min) > abs(t)) //checking if the absolute number of the new temp is the new min
            {
                min=t;
                result=min;
            }
            if (min > t) //checking iif the new temp is the new min
            {
                min=min;
                result=min;
            }
            
            if (abs(min) == abs(t)) //checking if the absolute number of the 2 temps is equal
            {
                temp1 = min+min;
                temp2 = t+t;
                //finding which is +
                if(temp1>0)
                {         
                    result=min;    
                }
                else if(temp2>0)
                {
                    result=t;    
                }
                if (temp1<0 && temp2<0) //if neither is + then result=min
                {
                    result=min;
                }
                
            }
        }
    }
    cout << result << endl;
}
