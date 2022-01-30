#include "WordFreq.h"
#include <vector>
#include <map>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<iomanip>
#include <algorithm>

using namespace std;

///-----------------------------------------------------------------
/// Process the given text file and return the most frequent "k" words
///
vector<WordFreq> GetMostFrequentKWords(string filename, int k) {

	vector<WordFreq> result;
	string str;
	map< string, int >words;
	
	//reading
	ifstream f(filename); //taking file as inputstream
	if (f) {
		ostringstream ss;
		ss << f.rdbuf(); // reading data
		str = ss.str();
	}

	// using transform() function and ::tolower in STL
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	//remove punctuation
	for (int i = 0, len = str.size(); i < len; i++)
	{
		// check whether parsing character is punctuation or not
		if (ispunct(str[i]))
		{
			str.erase(i--, 1);
			len = str.size();
		}
	}
	
	// seperate str word by word
	istringstream ss(str);
	string w; // for storing each word
	int i,j,numOfValidWords=1;
	WordFreq newWord(" ");
   // Traverse through all words
   // while loop till we get 
   // strings to store in string word
	while (ss >> w)
	{
		
		if (w.length() >= 3) 
		{	
			if (words.count(w) > 0) {
				words.find(w)->second++;
			}
			else {
				words.insert(make_pair(w, 1));
			}
			
		}
		
	}
	/*cout << endl;
	cout << "Map elements: ";
	cout << endl;
	for (auto iter : words) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
		cout << endl;
	}*/
	int t = 0;
	for (auto iter : words) {
		if (iter.second > t) t = iter.second;
	}
	vector<vector<string>> k_words(t+1);
	
	for (int i = 1; i <= t; ++i) {
		for (auto it : words) {
			if (it.second == i) {
				k_words[i].push_back(it.first);
			}
		}
	}

	/*for ( i = 1; i <= t; i++) {
		for (j = 0; j < k_words[i].size(); j++)
		{
			rs = k_words[i][j];
			cout << rs << " ";
		}
		cout << endl;
	}*/
	
	WordFreq r(" ");
	for (i = k_words.size()-1; i > 0; i--) {
		for (j = 0; j < k_words[i].size(); j++) {
			if (result.size() == k )  {
				break;
			 }
			/*else if (k_words[i].size() < k && result.size() == k_words[i].size()) {

			}*/
			else {
				r.word = k_words[i][j];
				r.freq = i;
				result.push_back(r);
			}
			
		}
	}
	

	return result;
} //end-GetMostFrequentKWords