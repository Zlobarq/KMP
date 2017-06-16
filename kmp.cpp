#include <iostream>
#include <string>
#include <array>
using namespace std;
int main() {
    string String;
    cout << "Enter String: ";
    getline (cin, String);
    string Pattern;
    cout << "Enter Pattern: ";
    getline (cin, Pattern);
    int stringlen = String.length();
    const int patternlen = Pattern.length();
    cout <<"stringlen "<<stringlen<<"\n";
    cout <<"patternlen "<<patternlen<<"\n";
    int Table[patternlen];
    int tablelen=sizeof(Table) / sizeof (Table[0]);
    cout <<"tablelen "<<tablelen<<"\n";
    int j=0;
    int i=2;
    Table[0]=-1;
    Table[1]=0;
    while (i < patternlen) {
            if (Pattern[i-1] == Pattern[j])
                {
                j=j+1;
                Table[i] = j;
                i=i+1;
                cout<< i << "\n";
            }
            else if (j > 0) 
                {j = Table[j];}
            else
            {
            	Table[i] = 0;
		        i=i+1;
            }
            
}

i=0; j=0;
    while (j+i < stringlen) {
            if (Pattern[i] == String[j+i]){ 
            if (i == patternlen -1) {cout<<"found at: "<<j<<"\n";}
            	i+=1;
        	}
            else
            {
           		j=j+i-Table[i];
            if (Table[i] > -1) 
            	{i = Table[i];}
            else {i = 0;}
    		}
                
           
        }




	return 0;
}