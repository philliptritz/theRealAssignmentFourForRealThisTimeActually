/**
*		file		theActualAssignment4ForRealThisTime.cpp
*		author		Phillip Tritz
*		date		11/29/2022
*		brief		Going to take user input file and count the file words










**/




#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Declaration of functions
int findWordPosition(vector<string> fileWords, string word);
void addWord(vector<string>& fileWords, vector<int>& counts, string word);
void reportToScreen(vector<string>& fileWords, vector<int>& counts);

//Main functions
int main()
{
	string inputFileName;
	cout << "Enter a File Name: "; cin >> inputFileName;

	// Input file stream object.
	ifstream inputFile;

	// Open File name.
	inputFile.open(inputFileName, ios::in);

	vector<string> fileWords;
	vector<int> counts;

	if (inputFile.is_open())
	{
		string word, row;

		// read lines from the file
		while (getline(inputFile, row))
		{
			// Make new String Stream to read the data separeted by the space.
			stringstream ss(row);

			// Check Every Word.
			while (ss >> word)
			{
				addWord(fileWords, counts, word);
			}

		}

		// Print Report on Screen.
		reportToScreen(fileWords, counts);

		// Close the file.
		inputFile.close();
	}
	else
	{
		cout << "File Not Found!";
	}

	return 0;
}// Return index of word in fileWords array. If not found, return -1.
int findWordPosition(vector<string> fileWords, string word)
{
	for (int i = 0; i < fileWords.size(); i++)
	{
		if (fileWords[i] == word)
			return i;
	}
	return -1;
}
// Add word into fileWords and count of word.
void addWord(vector<string>& fileWords, vector<int>& counts, string word)
{
	int pos = findWordPosition(fileWords, word);
	if (pos == -1) {
		fileWords.push_back(word);
		counts.push_back(1);
	}
	else {
		counts[pos]++;
	}
}
// Print to the screen using fileWords and counts.
void reportToScreen(vector<string>& fileWords, vector<int>& counts)
{
	cout << "\n\tWords Report \t\t\n" << endl;
	cout.width(25); cout << left << "Word";
	cout.width(25); cout << left << "Frequency\n" << endl;

	for (int i = 0; i < fileWords.size(); i++)
	{
		cout.width(25); cout << left << fileWords[i];
		cout.width(25); cout << left << counts[i] << endl;
	}
}
