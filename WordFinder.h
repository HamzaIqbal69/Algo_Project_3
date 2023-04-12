#ifndef WORD_FINDER
#define WORD_FINDER

/* System Libraries */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "sort_algorithms.h"

using namespace std;

class wordFinder
{
    private:
        vector<string> words;
        void sortWords();
    
    public:
        wordFinder();
        void readWords(string filename);
        string findWord(string find_word);
        friend ostream& operator << (ostream& os, const wordFinder wordList);
        vector<string> getWords();
};

wordFinder::wordFinder()
{
    words = {};
}

void wordFinder::readWords(string filename)
{
    ifstream inFile(filename);

    if (inFile.is_open()) 
    {
        string word;
        while (inFile >> word) 
        {
            words.push_back(word);
        }
        inFile.close();
        sortWords();
    }
    else 
    {
        cout << "Unable to open file " << filename << endl;
    }
}

void wordFinder::sortWords()
{
    selectionSort(words);
}


vector<string> wordFinder::getWords()
{
    return words;
}

ostream& operator<<(ostream& os, const wordFinder wordList)
{
    for(int i = 0; i < wordList.words.size(); i++)
    {
        os << wordList.words[i] << ", \n";
    }
    return os;
}

string wordFinder::findWord(string find_word)
{
    int left = 0;
    int right = words.size();
    int mid = (right + left) / 2;
    while(left <= right)
    {
        if(words[mid] == find_word)
        {
            return words[mid];
        }
        if(words[mid] < find_word)
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        if(words[mid] > find_word)
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    throw out_of_range("Word not found");
}

#endif	