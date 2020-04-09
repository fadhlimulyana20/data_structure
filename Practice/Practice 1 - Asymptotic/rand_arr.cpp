#include <iostream>
using namespace std;
#include <fstream>

int main(){
    std::ofstream myfile;
    myfile.open("rand_arr.txt");
    int n = 100000;
    // cin >> n;

    int array[100000];
    
    // srand((unsigned)time(0)); 
        
    for(int i=0; i<n; i++){ 
        array[i] = (rand()%1000)+1; 
            
        myfile << array[i] << ", ";
    } 

    myfile.close();
}