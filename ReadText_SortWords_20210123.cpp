#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	//open file:
	ifstream word_file("word.txt");
	
	//prepare iterator of type string to run through the file:
	//btw, the string-iterator uses whitespaces for separating strings
	istream_iterator<string> start(word_file), end;
	//save strings to vector:
	vector<string> words(start, end);
	
	//print out words as displayed in file:
	cout << "\n words as read \n";
	for (auto str : words)
		cout << str << "\t";
	
	// use standard template library quicksort-algo from "algorithm" library
	sort(words.begin(), words.end());
	cout << "\n\nwords as sorted\n";
	//print out sorted vector of strings:
	for(auto str : words)
		cout << str << "\t";
	cout << endl;
	
}
