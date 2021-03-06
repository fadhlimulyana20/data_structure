#include <iostream>
#include <list>

using namespace std;

int main(){
    std::list<int> myList;

    //?? push front command
    myList.push_front(2);
    myList.push_front(3);

    //?? Print List
    cout << "myList container :" << endl;
    for(std::list<int>:: iterator it=myList.begin(); it !=myList.end(); ++it){
        cout  << *it << ", ";
    }

    //?? push back command
    myList.push_back(6);
    myList.push_back(8);

    cout << endl;

    //?? Print List after push front
    cout << "myList container after push back :" << endl;
    for(std::list<int>:: iterator it=myList.begin(); it !=myList.end(); ++it){
        cout  << *it << ", ";
    }

    //?? check if similar value added
    myList.push_back(8);
    myList.push_front(3);

    cout << endl;

    //?? Print List after push front
    cout << "myList container after similar value added :" << endl;
    for(std::list<int>:: iterator it=myList.begin(); it !=myList.end(); ++it){
        cout  << *it << ", ";
    }

    cout << endl;

    // ?? Check the size
    cout << "myList Size : " << myList.size() << endl;

    //?? Pop Front
    cout << myList.front() << " popped" << endl;
    myList.pop_front();

    // ?? Check the size
    cout << "myList Size : " << myList.size() << endl;

    //?? Pop Front
    cout << myList.back() << " popped" << endl;
    myList.pop_back();

    // ?? Check the size
    cout << "myList Size : " << myList.size() << endl;

    // ? change the element
    std::list<int>::iterator advanceIt=myList.begin();
    advance(advanceIt,1);
    *advanceIt = 21;

    //?? Print List after push front
    cout << "myList after change :" << endl;
    for(std::list<int>:: iterator it=myList.begin(); it !=myList.end(); ++it){
        cout  << *it << ", ";
    }
}