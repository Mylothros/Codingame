#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;    
    cin >> n; cin.ignore();
    int a[n],res;
    
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t; cin.ignore();
        a[i]=t;
    }
    
    if(n==0)
    {
        res=0;    
    }
    else
    {
        sort(a, a + n);//sorting the array
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)//finding the first temperature closest to 0
            {
                res = a[i];
                break;
            }
            if(i == n-1)//if last loop and line 31 never was true then closest temperature is the last negative temperature n-1
            {
                res = a[i];    
            }
        }
    }
    cout << res << endl;
}
