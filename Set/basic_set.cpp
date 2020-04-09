#include <iostream>
#include <set>
using namespace std;
using std::cout;

int main(){
    std::set<int>::iterator it;
    
    // ? Insert Array into set
    int myArr[5] = {10, 20, 30, 40, 50};
    std::set<int> mySet (myArr, myArr+5);

    // ? Print Set
    cout << "MySet : ";
    for ( it = mySet.begin(); it != mySet.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;

    // ? Insert into set
    mySet.insert(25);
    mySet.insert(it, 24);
    int myArr2[3] = {15, 35, 45};
    mySet.insert(myArr2, myArr2+3);

    // ? Print Set
    cout << "MySet : ";
    for ( it = mySet.begin(); it != mySet.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;

    // ? Insert a value which have added before
    mySet.insert(10);

     // ? Print Set
    cout << "MySet : ";
    for ( it = mySet.begin(); it != mySet.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;

    // ? Erase data
    mySet.erase(25);

    // ? Print Set
    cout << "MySet : ";
    for ( it = mySet.begin(); it != mySet.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;

    // ? erase with iterator
    it = mySet.find(40);
    mySet.erase(it, mySet.end());

    // ? Print Set
    cout << "MySet : ";
    for ( it = mySet.begin(); it != mySet.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;
}