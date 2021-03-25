
#include "Board.hpp" 
#include "doctest.h"
using namespace std;
using namespace ariel;

Board board;

TEST_CASE("before posting- read"){
    CHECK(board.read(0,0,Direction::Horizontal,3)==string("abc"));
    CHECK(board.read(1,2,Direction::Horizontal,1)==string("Ariel"));
    CHECK(board.read(2,3,Direction::Horizontal,5)==string("computer"));
    CHECK(board.read(4,5,Direction::Vertical,2)==string("hello"));
    CHECK(board.read(5,1,Direction::Vertical,4)==string("bye"));
    CHECK(board.read(6,3,Direction::Vertical,7)==string("good day"));
}


TEST_CASE("post"){
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"Hello"));
    CHECK_NOTHROW(board.post(0,4,Direction::Horizontal,"World"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"Hey"));
    CHECK_NOTHROW(board.post(4,0,Direction::Vertical,"There"));
    CHECK_NOTHROW(board.post(1,2,Direction::Vertical,"ove"));
}

TEST_CASE("read"){
    CHECK(board.read(0,0,Direction::Horizontal, 5)==string("Hello"));
    CHECK(board.read(0,0,Direction::Horizontal, 11)==string("Hello_World"));
    CHECK(board.read(0,4,Direction::Horizontal,3)==string("o_W"));
    CHECK(board.read(0,0,Direction::Vertical,3)==string("Hey"));
    CHECK(board.read(0,0,Direction::Vertical,5)==string("Hey_T"));
    CHECK(board.read(4,0,Direction::Vertical,5)==string("There"));
    CHECK(board.read(3,0,Direction::Vertical,8)==string("_There__"));
    CHECK(board.read(0,2,Direction::Vertical,4)==string("love"));
}



TEST_CASE("read empty string"){
    CHECK(board.read(5,5,Direction::Horizontal, 0)==string(""));
    CHECK(board.read(2,6,Direction::Horizontal, 0)==string(""));
    CHECK(board.read(2,3,Direction::Vertical,0)==string(""));
    CHECK(board.read(4,3,Direction::Vertical,0)==string(""));
    CHECK(board.read(5,1,Direction::Vertical,0)==string(""));
    CHECK(board.read(0,0,Direction::Vertical,0)==string(""));
}
