#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1="aA1";
    cout << s1.size() << s1.length() << endl;
    //for(unsigned i=0; i<s1.size(); ++i){
    for(auto c : s1){
        cout << c << endl;
        if(isalnum(c))
            cout << "alpha or digit\n";
        if(isalpha(c))
            cout << "alpha\n";
        if(iscntrl(c))
            cout << "control\n";
        if(isdigit(c))
            cout << "digit\n";
        if(isgraph(c))
            cout << "graph\n";
        if(islower(c))
            cout<< "lowwer\n";
        if(isprint(c))
            cout << "print\n";
        if(ispunct(c))
            cout << "punct\n";
        if(isspace(c))
            cout << "space\n";
        if(isupper(c))
            cout << "upper\n";
        if(isxdigit(c))
            cout << "Xdigit\n";
    }
    s1[0] = toupper(s1[0]);
    s1[1] = tolower(s1[1]);
    cout << s1 << endl;

    return 0;
}

