#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(int r1, int r2, int r1sum, int r2sum, int m, int sum)
{
    if(r1 < r2)
    {
        while(r1 < r2)//find the river of r1 while r1 < r2
        {
            while(r1sum > 0)    
            {    
                m = r1sum % 10;    
                sum = sum + m;    
                r1sum = r1sum /10;  
            }
            
            r1 = r1 + sum;
            r1sum = r1;
            sum = 0;
        }
    }
    
    if(r1 > r2)
    {
        while(r1 > r2)//find the river of r2 while r2 < r1
        {
            while(r2sum > 0)    
            {    
                m = r2sum % 10;    
                sum = sum + m;    
                r2sum = r2sum / 10;  
            }
            
            r2 = r2 + sum;
            r2sum = r2;
            sum = 0;
        }
    }
    
    if(r1 == r2)
    {
        cout << r1;
    }
    else
    {
        calculate(r1, r2, r1sum, r2sum, m, sum);//if r1 != r2, which means->(r1 got bigger than r2 or r2 got bigger than r1) and not equal, so find the next river until r1 == r2
    }
}
int main()
{
    long long r1, r2;
    cin >> r1 >> r2;

    int r1sum = r1,r2sum = r2, m, sum = 0;

    calculate(r1, r2, r1sum, r2sum, m, sum);

}