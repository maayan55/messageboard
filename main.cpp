#include <iostream>
#include <string>
#include "Board.hpp"
using ariel::Direction;
using namespace std;

int main(){
    ariel::Board board;
    //post the message
    board.post(0,0,Direction::Horizontal,"This is the first row");
    board.post(1,10, Direction::Horizontal,"Good morning");
    board.post(10,15, Direction::Vertical, "cpp");
    board.post(3,4, Direction::Vertical, "message");
    board.post(4,1,Direction::Horizontal,"lov");
    //show the board
    board.show();
    cout<<"\n";
    //read message from the board
    cout<<"message read from themessage  board:\n";
    cout<<board.read(0,0,Direction::Horizontal,5)<<"\n";
    cout<<board.read(1,0,Direction::Horizontal,2)<<"\n";
    cout<<board.read(10,15,Direction::Vertical,4)<<"\n";
    cout<<board.read(0,10,Direction::Vertical,2)<<"\n";
    cout<<board.read(4,1,Direction::Horizontal,4)<<"\n";
    return 0;
}