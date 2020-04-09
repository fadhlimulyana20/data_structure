#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace std::chrono;

void swap(int *xp, int *yp)  {  
    int temp = *xp; 
    *xp = *yp;  
    *yp = temp;  
}  
  
void STAY(int arr[], int n){  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}    


int main(){  
    int arr[100000];
    int worst_arr[100000];
    int best_arr[100000];
	int i, j;

    cout << "Panjang Array, Waktu rata-rata, Best case, worst case" <<endl;

    for (j = 0; j < sizeof(arr); j+=5000)
    {
        for (i = 0; i < j ; i++)
        {
            arr[i] = rand();
            worst_arr[i] = sizeof(arr)-i;
            best_arr[i] = i;
        }

        int n = sizeof(arr) / sizeof(arr[0]); // jumlah array / jumlah array pertaman
        
        // Untuk mencari rata-rata running time
        auto t0 = high_resolution_clock::now();
        STAY(arr, j); 
        auto t1 = high_resolution_clock::now();
        auto dt = t1 - t0;
        long long dtms = duration_cast<microseconds>(dt).count();

        // untuk mencari best case
        auto t0_best = high_resolution_clock::now();
        STAY(best_arr, j); 
        auto t1_best = high_resolution_clock::now();
        auto dt_best = t1_best - t0_best;
        long long dtms_best = duration_cast<nanoseconds>(dt_best).count();

        // untuk mencari worst case
        auto t0_worst = high_resolution_clock::now();
        STAY(worst_arr, j); 
        auto t1_worst = high_resolution_clock::now();
        auto dt_worst = t1_worst - t0_worst;
        long long dtms_worst = duration_cast<nanoseconds>(dt_worst).count();
        
        /*clock_t t0 = clock();
        STAY(arr, n); 
        clock_t t1= clock();
        clock_t dt = (double)t1 - t0 / CLOCKS_PER_SEC;
        */
        cout << j << ", ";
        cout <<dtms<<", ";
        cout <<dtms_best<<", ";
        cout <<dtms_worst<<endl;
	
    }
   
		  
    return 0;  
}  
	
	


