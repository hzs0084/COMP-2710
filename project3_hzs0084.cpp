/*
 * @author - Hemant Sherawat (hzs0084)
 * @version - 10/07/2020
 * 
 * project3_hzs0084.cpp
 *
 * Consulted project document and handout.
 * Also consulted previous java class notes to help in sorting.
 */ 
 
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool check_file(string file) {
	ifstream stream;
	
	stream.open(file.c_str());
	if (stream.fail()) {
		cout << "Incorrect file name or path, please check file name and path and try again!\n";
		cout << endl;
		return false;
	}
	stream.close();
	
	return true;
	
}

vector<int> read_file(string file) {
	ifstream stream;
	vector<int> v;
	int i;
	
	stream.open(file.c_str());
	while (stream.good()) {
		stream >> i;
		v.push_back(i);
	}
	v.pop_back(); 
	stream.close();
	
	return v;
} 

void write_file(string file, vector<int> v, int size) {
	ofstream stream;
		
	stream.open(file.c_str());
	if (stream.good()) {
		for(int i = 0; i < size; i++) { 
			stream << v[i] << " ";
		}
	}
	stream.close();
	
	cout << "*** Please check the new file - " << file << " ***\n";
	cout << "*** Goodbye. ***\n";
}

vector<int> merge(vector<int> v1, vector<int> v2) {
	vector<int> v3;
	int temp;
	
	for (int i = 0; i < v1.size() + v2.size(); i++) {
			v3.push_back(v1[i]);
			v3.push_back(v2[i]);
	}
	
	for(int j = 0; j < v1.size() + v2.size(); j++) {
		int min = j;
 		for(int k = j + 1; k < v1.size() + v2.size(); k++) {
 			if (v3[k] < v3[min]) {
 				min = k;
 			}
 		}
 		temp = v3[j];
 		v3[j] = v3[min];
		v3[min] = temp;
 	}
				
	return v3;
}

void to_string(string file, vector<int> v) {
	unsigned short i;
	vector<int> v1;
	
	for(i = 0; i < v.size(); i++) {
		v1.push_back(v[i]);
	}
	
	cout << "The list of " << i << " numbers in file " << file << " is:\n";
	for(int j = 0; j < v1.size(); j++) {
		cout << v1[j] << "\n";
	}
	cout << endl;
}

int main() {
	//Declare variables
	ifstream stream1;
	ifstream stream2;
	
	string file1;
	string file2;
	string file3;

	vector<int> numbers1;
	vector<int> numbers2;
	vector<int> numbers3;
	
	cout << "*** Welcome to Hemant's sorting program ***\n";

	do {
		cout << "Enter the first input file name: ";
		cin >> file1;
	} while (cin.fail() || !check_file(file1));
	stream1.open(file1.c_str());
	
	numbers1 = read_file(file1);
	to_string(file1, numbers1);
	
	do {
		cout << "Enter the second input file name: ";
		cin >> file2;
	} while (cin.fail() || !check_file(file2));
	stream2.open(file2.c_str());
	
	numbers2 = read_file(file2);
	to_string(file2, numbers2);
	
	numbers3 = merge(numbers1, numbers2);
	cout << "The sorted list of " << numbers1.size() + numbers2.size() << " numbers is: ";
	for (int i = 0; i < numbers1.size() + numbers2.size(); i++) {
		cout << numbers3[i] << " ";
	}
	cout << endl;
	
	do {
		cout << "Enter the output file name: ";
		cin >> file3;
	} while (cin.fail());
	
	write_file(file3, numbers3, numbers1.size() + numbers2.size());
	
	stream1.close();
	stream2.close();
}
