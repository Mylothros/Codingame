#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int X;
    cin >> X;
    int N;
    cin >> N;
    
    double a = 0;
    int m[N], counter = 1, counter1 = 0;
    
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }
    
    sort(m, m+N, greater<int>());//sort the array with descending order
    
    for (int i = 0; i < N; i++)
    {
        if(counter1 == X)//if counter1 == X means the row is completed
        {
            counter++;//change the row to + 1
            counter1 = 0;//make counter1 = 0
        }

        a += ((counter - 1) * 6.5) / 100 * 10 * m[i];
        counter1++;//add + 1 to counter1 until the row is completed line 29
    }
    
   cout << fixed << setprecision(3) << a;//printing with 3 decimal places
}