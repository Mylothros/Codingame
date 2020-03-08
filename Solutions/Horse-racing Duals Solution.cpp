#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    int N;
    cin >> N; cin.ignore();
    int Pi[N];
    
    for (int i = 0; i < N; i++) 
    {        
        cin >> Pi[i]; 
        cin.ignore();
    }
    
    sort(Pi, Pi+N-1);//sorting the strengths
    int a[N-1];
    
    for (int i = 0; i < N-1; i++) 
    {
        a[i]=abs(Pi[i]-Pi[i+1]);//finding the differences by consecutively pairs of 2                         
    }
    sort(a, a+N-1);//sorting again
    
    cout << a[0] << endl;
}
