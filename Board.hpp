#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    private: //2 private method, for max row and max column (unsinged ofcourse)
        uint maxRow, maxCol;

        std::vector<std::vector<char>> board;

    public:
        Board()
        {
            board = std::vector<std::vector<char>>(10, std::vector<char>(10, '_'));
            maxRow =  maxCol = 10;
        }
        ~Board() {}
        void post(uint row, uint column, Direction direction, std::string message); 
        std::string read(uint row, uint column, Direction direction, uint num);
        void show();
        void setSize(uint rows, uint columns);
    };
    

}