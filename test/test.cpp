#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool validateDbl(string &str1) {
    istringstream iss(str1);
}

int main()
{

    double n = 456321.7651234;
    string str = to_string(n);
    cout << "String is: " << str;
    return 0;
}

