#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;    
    cin >> n; cin.ignore();
    int a[n],res,res1=0,res2=0,b=1,t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[i] = t;
    }
   
    if(n == 0)//if there are no temperatures
    {
        res = 0; 
    }
    else
    {
        sort(a, a + n);//sorting the array
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)//finding the first positive temperature closest to 0
            {
                res1 = a[i];
                res2 = a[i-1];
                break;
            }
            else if(i == n-1)//if all a[i] < 0 then res should be the biggest negative number which is the nearest number to 0
            {
                res =  a[i];
                b = 0;//dont check the requirements
            }
        }
        if(b == 1)//check the requirements
        {
            if(res1 > abs(res2))
            {
                res = res2;
            }
            else
            {
                res = res1;    
            }
            if(res1 == abs(res2))
            {
                res = res1;   
            }
        }
    }
    cout << res << endl;
}
