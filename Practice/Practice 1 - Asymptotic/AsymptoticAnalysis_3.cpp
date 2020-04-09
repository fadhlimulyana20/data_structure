#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::ofstream;    


static const char alphanum[] =
"0123456789"
"!@#$%^[]:|&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom(){
    return alphanum[rand() % stringLength];
}

std::string randomString(int n){
    std::string Str;
    for(unsigned int i = 0; i < n; ++i){
    	Str += genRandom();
    }

    return Str;
}


int eraseAT(std	::string str) {
	std::string acc;
	bool a, b;
	int x = 0;
	if (str.length() == 0)
		return 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[' || str[i] == ':' || str[i] == '|') {
			if (str[i] == '[') {
				acc.push_back(str[i]);
				a = true;
			} else if (str[i] == ':' && a) {
				if (str[i] == ':' && acc[acc.length() - 1] == ':') {
						acc.pop_back();
						b = false;
				} else {
						acc.push_back(str[i]);
						b = true;
				}
			} else if (str[i] == '|' && b) {
			} else x++;
        } else if (str[i] == ']') {
			if (acc.length() == 0)
				x++;
			else {
				acc.pop_back();
				a = false;
			}
		} else x++;
	}
	if (acc.length() == 0) return x;
	else return -1;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < str.length(); j++)
			for (int k = 0; k < str.length(); k++){
				cout << "yes";
				str[i] = str[k];
			}
	return 0;
}



int main(){
	ofstream myfile;
    myfile.open("data.csv");

	int n = 100000;
	for (int i = 0; i < n; i+=10000){
		std::string Str = randomString(i);
		
		myfile << i << "; ";
		auto t0 = high_resolution_clock::now();
		eraseAT(Str);
		auto t1 = high_resolution_clock::now();
		auto dt = t1-t0;
		double dtms = double(duration_cast<nanoseconds>(dt).count());

		myfile << dtms << endl;
	}
	myfile.close();
}
