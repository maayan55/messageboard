#include "Board.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace ariel
{

    void Board::post(uint row, uint column, Direction direction, std::string message)//getting locatin, direction, and string, and post it
    {
        bool raise=false;
        if (direction == Direction::Horizontal)//if its (-), add 1 row, and massage.length columns
        {
            setSize(row + 1, column + message.length());
            raise=true;
        }
        else //else, its (|),  add message.length rows, ans 1 column
        {
            setSize(row + message.length(), column + 1);
        }
        for (char c: message)
        {
            Board::board[row][column] = c;
            if (!raise)
            {
                row++;
            }
            else
            {
                column++;
            }
        }
    }

    string Board::read(uint row, uint column, Direction direction, uint num)//getting locatin, direction, number of char to read, and read (return it)
    {
        string str;
        uint temp = num;
        for (uint i = 0; i < num && row <= Board::maxRow - 1 &&  column <= Board::maxCol - 1;i++)
        {
            str += board.at(row).at(column);
            if (direction == Direction::Horizontal)
            {
                column++;
            }
            else
            {
                row++;
            }
            temp--;
        }
        for (uint i = 0; i < temp; i++)
        {
            str += "_";
        }
        return str;
    }

    void Board::show() //show the corrent messageboard
    {
        for (uint i = 0; i < Board::maxRow; i++)
        {
            cout<<"row "<< i<< " ";
            for (uint j = 0; j < Board::maxCol; j++)
            {
                cout << Board::board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

     void Board::setSize(uint rows, uint columns)
    {
        Board::maxRow = max(Board::maxRow, rows);
        Board::maxCol = max(Board::maxCol, columns);
        Board::board.resize(Board::maxRow);
        for (uint i = 0; i < Board::maxRow; i++)
        {
            Board::board[i].resize(Board::maxCol, '_');
        }
    }

}