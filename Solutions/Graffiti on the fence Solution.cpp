#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L, N, st[N], ed[N], temp;
    cin >> L >> N;
    cin.ignore();

    bool b = false;
    
    for (int i = 0; i < N; i++)
    {              
        cin >> st[i] >> ed[i];
        cin.ignore();       
    }

    for (int i = 0; i < N-1; i++) 
    {       
        for (int j = 0; j < N-i-1; j++) 
        { 
            if (st[j] > st[j+1])//using bubble sort for the start of the painting
            { 
                temp = st[j]; 
                st[j] = st[j+1]; 
                st[j+1] = temp; 
                temp = ed[j]; 
                ed[j] = ed[j+1]; 
                ed[j+1] = temp;      
            }
        }
    }
   
    for (int i = 0; i < N; i++) 
    {
        for (int j = i+1; j < N; j++) 
        { 
            if (st[i] < st[j] && ed[i] > ed[j])//everytime e start position of the next painting is lesser than the next and the end position is greater than the next make the start position and end position the same because they painted the same part of the wall
            { 
                st[j] = st[i];
                ed[j] = ed[i];
            }
            else
            {
                i = j - 1;
                break;
            }    
        }   
    }
   
   if(st[0] != 0)//if the first painting is not the start
   {
       b = true;
       cout << "0 " << st[0] << endl;
   }
   
    for (int i = 0; i < N; i++) 
    {
        for(int j = i+1; j < N; j++)
        {
            if(ed[i] != ed[i-1] && ed[i] < st[j])//first condition is to check for not repeated painting on the same positions of the wall and the second to check if the ending is lesser than the next start
            {
                b = true;
                cout << ed[i] << " " << st[j] << endl;
                break;
            }
            if(ed[i] < ed[j])//if ending lesser than the next ending break it so it wont check the rest of the wall
            {               
                break;
            }
        }
    }
    
    if(ed[N-1] != L)//if the last painting is not the end
    {
        b = true;
        cout << *max_element(ed, ed + N) << " " << L << endl;
    }
    
    if(b == false)// if b is false and never has been made true everything is painted
    {
        cout << "All painted";    
    }
}
