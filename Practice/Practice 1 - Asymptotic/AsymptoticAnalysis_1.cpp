#include <iostream>
#include <chrono>
#include <fstream>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::ofstream;    


void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Stay(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);    
        }    
    }    
}

int main(){
    ofstream myfile;
    myfile.open("data.csv");

    int n = 100000;

    int array[100000];
    int best_arr[100000];
    int worst_arr[100000];
    
    // srand((unsigned)time(0)); 

    for (int i = 0; i < 100000; i+=5000){
        cout << "ke-" << i << endl;
        myfile << i << "; ";

        // Array initiation
        for(int j=0; j<i; j++){ 
            array[j] = (rand()%100)+1;
            best_arr[j] = j;
            worst_arr[j] = i-j;
            // cout << array[j] << " ";
        }

        // Random Test Case
        auto t0 = high_resolution_clock::now();
        
        Stay(array, i);

        auto t1 = high_resolution_clock::now();
        auto dt = t1-t0;
        double dtms = double(duration_cast<nanoseconds>(dt).count());

        myfile << dtms/1e9 << "; ";

        // Ascending Test Case
        auto t0_best = high_resolution_clock::now();
        
        Stay(best_arr, i);

        auto t1_best = high_resolution_clock::now();
        auto dt_best = t1_best-t0_best;
        double dtms_best = double(duration_cast<nanoseconds>(dt_best).count());

        myfile << dtms_best/1e9 << "; ";

        // Descending Test Case
        auto t0_worst = high_resolution_clock::now();
        
        Stay(worst_arr, i);

        auto t1_worst = high_resolution_clock::now();
        auto dt_worst = t1_worst-t0_worst;
        double dtms_worst = double(duration_cast<nanoseconds>(dt_worst).count());

        myfile << dtms_worst/1e9 << endl;
    }

    // myfile << n << ", ";
    // auto t0 = high_resolution_clock::now();
    
    // Stay(array, n);

    // auto t1 = high_resolution_clock::now();
    // auto dt = t1-t0;
    // long long dtms = duration_cast<microseconds>(dt).count();

    // myfile << dtms << endl;

    myfile.close();
     
}
