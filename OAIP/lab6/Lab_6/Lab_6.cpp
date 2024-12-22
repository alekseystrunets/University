#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[256];

    cout << "Enter string: ";
    cin >> str;

    cout << "Numbers in the string: " << endl;

    for (int i = 0; i < strlen(str); i++) 
        if (isdigit(str[i]))
            cout << str[i] << " ";

    return 0;
}