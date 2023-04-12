#ifndef LETTER_GRID
#define LETTER_GRID

/* System Libraries */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "sort_algorithms.h"
#include "d_matrix-1.h"

using namespace std;

class letterGrid
{
    private:
        matrix<char> grid;
        void initializeGrid(string file_name);
    
    public:
        letterGrid(string fileName);
        friend ostream& operator << (ostream& os, const letterGrid letter_grid);
        matrix<char> getGrid();
};

letterGrid::letterGrid(string fileName)
{
    initializeGrid(fileName);
}

void letterGrid::initializeGrid(string file_name)
{
    ifstream fin(file_name);
    if(!fin)
    {
        cout << "Cant open file: " << file_name << endl;
    }
    int rows, cols;
    fin >> rows >> cols;

    grid.resize(rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            fin >> grid[i][j];
        }
    }
    fin.close();
}

ostream& operator << (ostream& os, const letterGrid letter_grid)
{
    for(int i = 0; i < letter_grid.grid.rows(); i++)
    {
        for(int j = 0; j < letter_grid.grid.cols(); j++)
        {
            os << letter_grid.grid[i][j] << "   ";
        }
        os << endl << endl;
    }
    return os;
}

matrix<char> letterGrid::getGrid()
{
    return grid;
}

#endif	