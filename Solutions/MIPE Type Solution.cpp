#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string,string> mapp;
    map<string,string>::iterator it;
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();

    for (int i = 0; i < N; i++) 
    {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        
        transform(EXT.begin(),EXT.end(),EXT.begin(),::toupper);//make all the characters of the string uppercase chars
        mapp[EXT] = MT; // map the file extensions with the mime types
    }   
    
    for (int i=0; i<Q; i++) 
    {
        string result = "UNKNOWN"; // set the result to be UNKOWN
        string FNAME;
        getline(cin, FNAME);
        transform(FNAME.begin(),FNAME.end(),FNAME.begin(),::toupper);//make all the characters of the filename uppercase chars
        
        int point = FNAME.find_last_of(".");//find the position of the last dot in the filename
        if(point >= 0)//if the dot exists in filename 
        {
            FNAME = FNAME.substr(point+1);//set the FNAME to be equal with everything after the do example--newfile.txt then fname=txt
            it = mapp.find(FNAME);//set the iterator equal to the specified key if found else it will be equal to map end
            
            if(it != mapp.end())
            {   
                result = it->second; //if the specified key is found set the result to be the MT
            }
        }   
        cout << result << endl;
    }
}
