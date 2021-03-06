#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string LON;
    cin >> LON; 
    cin.ignore();
    string LAT;
    cin >> LAT; 
    cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    string search=",";
    string replace=".";
    double pos,LONA,LATA,d[N],LONBBB,LATBBB;
    int position,position1,j=0,count,min1=0;;
    char *LONB,*LATB;
    string defi[N][200];
    //finding and replacing the , with .
    pos = LON.find(search);
    LON.replace(pos, search.size(), replace);
    pos = LAT.find(search);
    LAT.replace(pos, search.size(), replace);
    //making the strings floats
    LONA=stof(LON);
    LATA=stof(LAT);
    
    for (int i = 0; i < N; i++) 
    {
        string DEFIB,LONBB,LATBB;
        getline(cin, DEFIB);
        //initialising an array of strings to be the same as the DEFIB
        defi[i][i]=DEFIB;
        
        position1=defi[i][i].find(";");
        defi[i][i]=defi[i][i].substr(position1+1);        
        position1=defi[i][i].find(";");
        defi[i][i].resize(position1);
        //resizing the array of strings to hold only the name which is after the first ; and last of the second ;
       
        position=DEFIB.find_last_of(";");//finding the latitude which is after the last ;
        LATB=(char*)malloc((int(DEFIB.size())-position) * sizeof(char));//initialising the length of LATB
         
        for(int k=position+1;k<DEFIB.size();k++)//position+1 is the latitude after the last ;
        {
           LATB[j]=DEFIB[k];
            j++;
        }
        
        j=0;     
        LATBB=LATB;//setting the LATBB to be the latitude
 
        DEFIB.resize(position);//deleting from DEFIB the latitude

        position=DEFIB.find_last_of(";");//finding the longtitude which is after the last ;
        LONB=(char*)malloc((int(DEFIB.size())-position) * sizeof(char));//initialising the length of LONB
        
        for(int k=position+1;k<DEFIB.size();k++)//position+1 is the longtitude after the last ; as in line 50
        {
            LONB[j]=DEFIB[k];
            j++;
        }
        
        j=0;
        LONBB=LONB; //setting the LONBB to be the longtitude
        
        pos = LONBB.find(search);
        LONBB.replace(pos, search.size(), replace);
        pos = LATBB.find(search);
        LATBB.replace(pos, search.size(), replace);
        //finding and replacing the , with . as in lines 27-30
        LATBBB=stof(LATBB);
        LONBBB=stof(LONBB);
        //making the strings floats
        d[i]=sqrt(pow((LONA-LONBBB)*cos((LATA+LATBBB)/2),2)+ pow((LATA-LATBBB),2))*6371;//using the formula
    }    
    double min=d[0];
    //finding the min
    for(int a=1;a<N;a++)
    {
        if(min>d[a])
        {   
            min=d[a];
            min1=a;
        }
    }    
    cout << defi[min1][min1] << endl;
}
