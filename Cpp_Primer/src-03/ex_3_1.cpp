#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2(s1);
    s2.append("cc");
    string s3(10,'c');

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    return 0;
}

