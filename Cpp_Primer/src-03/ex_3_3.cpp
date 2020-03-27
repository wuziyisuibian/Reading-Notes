#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin, s1)){
        s2.append(s1);
        s2.append("\n");
    }

    if(!s1.empty()){
        cout << "--s1--" << endl;
        cout << s1 ;
    }
    if(s2.size() > -1){
        cout << "--s2--" << endl;
        cout << s2 ;
        cout << "s2-size: " << s2.size() << endl;
    }

    return 0;
}

