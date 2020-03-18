#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, counter=0;
    cin >> N; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    
    bool notSmart = false;
    L--;
    
    int OutOfBounds1=L,OutOfBounds2=L,OutOfBounds3=L,OutOfBounds4=L;//lines 42-46
    char A[N][N];
    
    for (int i = 0; i < N; i++) 
    {
        string LINE;
        getline(cin, LINE);
        for(int j = 0; j < LINE.size(); j++)
        {
            if(j % 2 == 0)
            {
                A[i][counter] = LINE[j];//initializing the 2D array and because the string has spaces ' ' after every character we are using j%2 to avoid them.(Other way is if(line[j]!= ' '))
                counter++;
            }
        }
        counter=0;
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i][j] == 'C')
            {
                if(i - L < 0) OutOfBounds1 = i;
                if(i + L > N-1) OutOfBounds2 = N-i-1;
    
                if(j - L < 0) OutOfBounds3 = j;
                if(j + L > N-1) OutOfBounds4 = N-j-1;
                //lines 42-46 dont go out of bounds
                for(int k = i-OutOfBounds1; k <= i+OutOfBounds2; k++)
                {
                    for(int p = j-OutOfBounds3; p <= j+OutOfBounds4; p++)
                    {
                        if(A[k][p] != 'C')
                        {
                            notSmart = false;
                            A[k][p] = '1';
                        }
                    }                    
                }
                
                OutOfBounds1=L;
                OutOfBounds2=L;
                OutOfBounds3=L;
                OutOfBounds4=L;
                //setting the OutOfBounds to be L for the next C if it is found
            }            
        }        
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i][j] == 'X')
            {
                counter++;
            }
        }
    }
    
    if(notSmart)//they are not very smart
    {
        cout << N*N << endl;
    }
    else
    {
        cout << counter;    
    }  
}