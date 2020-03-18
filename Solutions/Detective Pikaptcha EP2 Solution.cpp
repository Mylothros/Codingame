#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width, height, counter=1, bi, bj, pos, end = 0, x = 1, y = 0, z = 0;  
    cin >> width >> height; cin.ignore();
    char A[height+2][width+2],finaldest;
    string dest = "><v^";//initializing the directions
    
    for (int i = 0; i < height+2; i++) 
    {
        for (int j = 0; j < width+2; j++) 
        {
             A[i][j] = '#';//adding a border of #(walls) for the labyrinth
        }
    }
    
    for (int i = 0; i < height; i++) 
    {
        string line;
        cin >> line; cin.ignore();
        
        for(int j = 0; j < line.size(); j++)
        {
            A[counter][j+1] = line[j];//making the labyrinth from j+1 and counter+1 sto there will be a border of # around of the labyrinth
            if(A[counter][j+1] != '0' && A[counter][j+1] != '#')//if the starter position is found
            {
                finaldest = A[counter][j+1];
                bi = counter;
                bj = j+1;
            }
        }
        counter++;
    }    
    string side;
    cin >> side; cin.ignore();
    pos = dest.find(finaldest);
    bool b = true;
    
    if(A[bi][bj+1] == '#' && A[bi+1][bj] == '#' && A[bi-1][bj] == '#' && A[bi][bj-1] == '#')//if it is trapped
    {
        A[bi][bj] = '0';
         b = false;
    }
    
    if(b == true)
    {
        A[bi][bj] = 'A';//initializing the starter position as A so A+1 will be B to know when to break the while line 64
        
        if(side == "R")
        {
            x = -1;
            y = 1;
            z = -1;
            //values to use for R side
        }
    }
       
    if(b == true)//trapped line 45
    {
        while(1)
        {   
            if(A[bi][bj] == 'B')//if starter position break and make the position 1 (B because A + 1 = B)
            {
                A[bi][bj] = '1';
                break;        
            }
            if(pos == 0)//if pos = 0 meaning the direction >
            {
                if(A[bi-(x)][bj] == '#' && A[bi][bj+1] == '#')//if left of > is # and forward + 1 is # the change the pos to 2(v) or 3(^) considering the side
                {
                    pos = 2 + y;
                } 
                                
                if(A[bi-(x)][bj] != '#' && pos == 0)//if left of > is not # then make pos to 3(^)
                {
                      A[bi-(x)][bj] = A[bi-(x)][bj] + 1;
                      bi = bi - x ;
                      pos = 3 + z;
                }
                if(A[bi][bj] == 'B')//if starter position break and make the position 1
                {
                    A[bi][bj] = '1';
                    break;        
                }
                if(A[bi][bj+1] != '#' && pos == 0)//if forward of > is not # then keep going >
                {
                     A[bi][bj+1] =  A[bi][bj+1] + 1;
                     bj++;
                }           
            }            
            if(pos == 1)
            {
                if(A[bi+(x)][bj] == '#' && A[bi][bj-1] == '#')
                {
                    pos = 3 + z;
                }               
                if(A[bi+(x)][bj] != '#' && pos == 1)
                {
                      A[bi+(x*1)][bj] = A[bi+(x*1)][bj] + 1;
                      bi = bi + x;
                      pos = 2 + y;    
                }
                if(A[bi][bj] == 'B')
                {
                    A[bi][bj] = '1';
                    break;        
                }
                if(A[bi][bj-1] != '#' && pos == 1)
                {
                      A[bi][bj-1] =  A[bi][bj-1] + 1;
                      bj--;
                }
            }           
            if(pos == 2)
            {              
                if(A[bi+1][bj] == '#' && A[bi][bj+(x)] == '#')
                {
                    pos = 1 + z;    
                }
                if(A[bi+1][bj] != '#' && pos == 2)
                {
                      A[bi+1][bj] = A[bi+1][bj] + 1;
                      bi++;
                }
                if(A[bi][bj] == 'B')
                {
                    A[bi][bj] = '1';
                    break;        
                }
                if(A[bi][bj+(x)] != '#' && pos == 2)
                {
                      A[bi][bj+(x)] =  A[bi][bj+(x)] + 1;
                      bj = bj + x;                     
                      pos = 0 + y;
                }
            }            
            if(pos == 3)
            {
                if(A[bi-1][bj] == '#' && A[bi][bj-(x)] == '#')
                {
                    pos = 0 +y;    
                }
                if(A[bi-1][bj] != '#' && pos == 3)
                {
                      A[bi-1][bj] = A[bi-1][bj] + 1;
                      bi--;
                }
                if(A[bi][bj] == 'B')
                {
                    A[bi][bj]='1';
                    break;        
                }
                if(A[bi][bj-(x)] != '#' && pos == 3)
                {
                      A[bi][bj-(x)] =  A[bi][bj-(x)] + 1;
                      bj = bj - x;                     
                      pos = 1 + z;
                }            
            }
            
        }
    }
    for (int i = 1; i < height+1; i++) 
    {
        for (int j = 1; j < width+1; j++) 
        {
            cout << A[i][j];
        }
        cout<< endl;
    }
}
