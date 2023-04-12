#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "LetterGrid.h"
#include "WordFinder.h"

using namespace std;

void matchWords(wordFinder glossary, letterGrid grid)
{
    for(int row = 0; row < grid.getGrid().rows(); row++)
    {
        for(int col = 0; col < grid.getGrid().cols(); col++)
        {
            string word1, word2, word3, word4, word5, word6, word7, word8;
            int size = grid.getGrid().rows();
            for(int i = 0; i < grid.getGrid().rows(); i++)
            {
                int rowplus = row + i;
                int colplus = col + i;
                int rowminus = row - i;
                int colminus = col - i;
                word1[i] = (rowplus >= size) ? grid.getGrid()[rowplus - size][col] : grid.getGrid()[rowplus][col];
                word2[i] = (colplus >= size) ? grid.getGrid()[row][colplus - size] : grid.getGrid()[row][colplus];
                word3[i] = (rowminus < 0) ? grid.getGrid()[rowminus + size][col] : grid.getGrid()[rowminus][col];
                word4[i] = (colminus < 0) ? grid.getGrid()[row][colminus + size] : grid.getGrid()[row][colminus];
                word5[i] = (rowplus >= size) ? ((colplus >= size) ? grid.getGrid()[rowplus - size][colplus - size] : grid.getGrid()[rowplus - size][colplus]) : ((colplus >= size) ? grid.getGrid()[rowplus][colplus - size] : grid.getGrid()[rowplus][colplus]); 
                word6[i] = (rowplus >= size) ? ((colminus < 0) ? grid.getGrid()[rowplus - size][colminus + size] : grid.getGrid()[rowplus - size][colminus]) : ((colplus < 0) ? grid.getGrid()[rowplus][colminus + size] : grid.getGrid()[rowplus][colminus]); 
                word7[i] = (rowminus < 0) ? ((colplus >= size) ? grid.getGrid()[rowplus - size][colplus - size] : grid.getGrid()[rowplus - size][colplus]) : ((colplus >= size) ? grid.getGrid()[rowplus][colplus - size] : grid.getGrid()[rowplus][colplus]); 
                word8[i] = (rowminus < 0) ? ((colminus < 0) ? grid.getGrid()[rowplus - size][colminus + size] : grid.getGrid()[rowplus - size][colminus]) : ((colplus < 0) ? grid.getGrid()[rowplus][colminus + size] : grid.getGrid()[rowplus][colminus]); 
                if(i >= 5)
                {
                    if(glossary.findWord(word1))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word1 << endl;
                    }
                    if(glossary.findWord(word2))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word2 << endl;
                    }
                    if(glossary.findWord(word3))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word3 << endl;
                    }
                    if(glossary.findWord(word4))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word4 << endl;
                    }
                    if(glossary.findWord(word5))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word5 << endl;
                    }
                    if(glossary.findWord(word6))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word6 << endl;
                    }
                    if(glossary.findWord(word7))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word7 << endl;
                    }
                    if(glossary.findWord(word8))
                    {
                        cout << "Row: " << row << "  Col: " << col << "  Word: : " << word8 << endl;
                    }
                }
            }
        }
    }
}

int main()
{
    wordFinder glossary;
    glossary.readWords("Glossary.txt");
    letterGrid letter_grid("input15.txt");
    cout << letter_grid << endl;
    matchWords(glossary, letter_grid);
}
