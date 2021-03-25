#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{

    class Board{
        unsigned int row;
        unsigned int col;
        vector<vector<char>> m;

        public:
            Board(){
                row=1;
                col=1;
                m=vector<vector<char>>(1,vector<char>(1,'_'));
            }
            void post(unsigned int i, unsigned int j, ariel::Direction d, string ad);
            string read(unsigned int i, unsigned int j, ariel::Direction d, unsigned int k);
            void show();
    };
}