#include <iostream>
#include <queue>
using namespace std;
using std::cout;

int main(){
    std::queue<int> myQueue;

    // ? push data to queue
    myQueue.push(5);
    myQueue.push(2);
    myQueue.push(7);

    // ? Check size
    cout << "Size : " << myQueue.size() << endl;

    // ? check front
    cout << "Front : " << myQueue.front() << endl;

    // ? check back
    cout << "Back : " << myQueue.back() << endl;

    // ? popping element
    cout << "myQueue pop : ";
    while(!myQueue.empty()){
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    // ? Check size
    cout << "Size : " << myQueue.size() << endl;
}