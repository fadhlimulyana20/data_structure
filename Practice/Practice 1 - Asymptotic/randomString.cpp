#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

static const char alphanum[] =
"0123456789"
"!@#$%^[]:|&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{

    return alphanum[rand() % stringLength];
}

std::string randomString(int n){
    std::string Str;
    for(unsigned int i = 0; i < n; ++i)
    {
    Str += genRandom();
    }

    return Str;
}

int main()
{
    // for (int i = 0; i < 20; i++)
    // {
    //     std::string Str = randomString(i);
    //     cout << Str << endl;
    // }
    std::string Str = randomString(56348);
    cout << Str << endl;

}


