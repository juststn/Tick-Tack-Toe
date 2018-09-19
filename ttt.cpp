#include <iostream>
using namespace std;

int main ()
{
  const int XTURN = 0;
  const int OTURN = 1;
  const int BLANK = 0;
  const int XMOVE = 1;
  const int OMOVE = 2;

  char board [4][4];
    board [0][1] = 'a';
    board [0][2] = 'b';
    board [0][3] = 'c';
    board [0][0] = ' ';
    board [1][0] = '1';
    board [2][0] = '2';
    board [3][0] = '3';
 string input = "";
    int turn = XTURN;
    bool playing = true;
    for(int i = 0; i<4; i++){
      for(int j = 0; j<4; j++){
       board [i][j] = BLANK;
       board [0][1] = 'a';
       board [0][2] = 'b';
       board [0][3] = 'c';
       board [0][0] = ' ';
       board [1][0] = '1';
       board [2][0] = '2';
       board [3][0] = '3';
        cout << board [i][j] << " ";
      }
      cout << endl;
    }
    while (playing == true){
      cin >>input;
      if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
        cout<<"elighble rows are a,b,c"<<endl;
      }

      else {
        int column = input[0] - 'a';
        int row = input[1]-'1';
          if (board[row+1][column+1] == BLANK){
            if(turn == XTURN){
              board[row+1][column+1]=XMOVE;
              turn = OTURN;
            }
            else {
              board[row+1][column+1] = OMOVE;
              turn = XTURN;
            }

          }
          else {
            cout<<"invalid"<<endl;
          }
         for(int i = 0; i<4; i++){
          for(int j = 0; j<4; j++){

            if(board [i][j] ==  XMOVE){
              board [i][j] = 'X';
            }
            if (board [i][j] == OMOVE){
              board [i][j] = 'O';
            }

            board [0][1] = 'a';
            board [0][2] = 'b';
            board [0][3] = 'c';
            board [0][0] = ' ';
            board [1][0] = '1';
            board [2][0] = '2';
            board [3][0] = '3';

            cout << board [i][j] << " ";
          }
          cout << endl;
        }
      }
}
      return 8008;
}

