#include <iostream>
#include <map>
using namespace std;

//enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
//enum romans { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };

int getInt_Value(char inChar) {
  
    // Create a map of strings to integers
    map<char, int> mp;

    // Insert some values into the map
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    auto it = mp.find(inChar);
    return it->second;
}

int main()
{
    char userChoice, char1;

    cout << "Enter a character: ";
    cin >> userChoice;
    cout << getInt_Value(userChoice) << endl << endl;

    system("pause");
    return 0;
}

