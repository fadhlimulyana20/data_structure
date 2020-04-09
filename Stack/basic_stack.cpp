#include <iostream>
#include <stack>
using namespace std;
using std::cout;

int main(){
    std::stack<int> myStack;

    // ? Insert into stack using for 
    for (int i = 1; i <= 5 ; i++){
        myStack.push(i);
    }

    // ? Check Size
    cout << "myStack Size : " << myStack.size();
    cout << endl;

    // ? popping data
    cout << "myStack : ";
    while(!myStack.empty()){
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // ? Check if Empty
    if(myStack.empty()) cout << "myStack is Empty" << endl; 
    
}