#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int q;
    cin >> q;
    queue <long> myQueue;

    for (int i = 0; i < q; i++)
    {
        int selector;
        cin >> selector;
        if (selector == 1)
        {
            long val;
            cin >> val;
            myQueue.push(val);
        }else if(selector == 2){
            myQueue.pop();
        }else{
            cout << myQueue.front() << endl;
        }
        
    }
}
