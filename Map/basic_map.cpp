#include <iostream>
#include <map>
using namespace std;
using std::cout;

int main(){
    std::map<char, int> myMap;
    std::map<char,int>::iterator it;

    // ? Insert data to map;
    myMap.insert(std::pair<char, int>('d', 100));
    myMap.insert(std::pair<char, int>('b', 200));
    myMap.insert(std::pair<char, int>('c', 300));

    // ? showing content
    cout << "myMap : " << endl;
    for(it=myMap.begin(); it!=myMap.end(); ++it){
        cout << it->first << " => " << it->second << endl;
    }

    // ? Insert into specific position
    myMap.insert(myMap.begin(), std::pair<char,int>('a', 400));

    // ? showing content
    cout << "myMap : " << endl;
    for(it=myMap.begin(); it!=myMap.end(); ++it){
        cout << it->first << " => " << it->second << endl;
    }
}

