#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d, k, k_index;

    // Meminta input variabel
    cin >> n;
    cin >> d;

// Mendeklarasikan list
    list <int> list_num;
    list <int> new_list_num;
    list <int> k_indexes;
    list <int> backup_list_num;

    int temp;

    // Meminta input unutk list
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        list_num.push_back(temp);
    }
    
    // Membuat salinan list
    backup_list_num.assign(list_num.begin(), list_num.end());

    // Cek apakah rotasi lebih besar dari panjang list, jika sama maka nggak di rotasi
    if(d >= list_num.size()) d %= list_num.size();

    // meminta input utuk jumlah index yang stay
    cin >> k;
    // Jika ada maka hapus index yang stay dari list asli dan catat indexnya dan push ke list yang menyimpan index
    if (k > 0) {
        for(int i = 0; i < k; i++){
            cin >> k_index;
            // Deklarasi iterator
            list<int>::iterator del_it = list_num.begin();
            // Push nilai index stay
            k_indexes.push_back(k_index);
            // iterator maju ke posisi index stay
            advance(del_it, k_index);
            // ubah nilai dari index stay ke 0
            *del_it = 0;
        }
        // hapus semua anngota list yang bernilai 0
        list_num.remove(0);
    }

    // for(list<int>::iterator it1 = list_num.begin(); it1 != list_num.end(); ++it1){
    //     cout << *it1 << " ";
    // }
    // cout << endl;

    // menggeser list dengan cara memncopy list dari index dengan nilai index adalah banay rotasi
    list<int>::iterator it = list_num.begin();
    advance(it, d);
    new_list_num.assign(it, list_num.end());

    // anggota list yang berada di sebelum index rotasi ditambahkan di akhir
    for(list<int>::iterator itn = list_num.begin(); itn != it; itn++){
        new_list_num.push_back(*itn);
    }
    
    // Jika ada index yang stay maka value nya akan dihapus, maka harus ditambahkan lagi ke array baru hasil rotasi
    if(k > 0) {
        for( list<int>::iterator add_it = k_indexes.begin(); add_it != k_indexes.end(); ++add_it){
            list<int>::iterator new_it = new_list_num.begin();
            list<int>::iterator ex_it = backup_list_num.begin();
            advance(new_it, *add_it);
            advance(ex_it, *add_it);
            new_list_num.insert(new_it, *ex_it);
        }
    }

    // Print hasil rotasi
    for(list<int>::iterator it1 = new_list_num.begin(); it1 != new_list_num.end(); ++it1){
        cout << *it1 << " ";
    }
    
    cout << endl;
    
    
    
}
