#include <iostream>
using namespace std;

//TicTacToe by Justin He: Tic Tac toe game in C++ for two players.
//Have user enter a move in a 3x3 board if it is legal.
//After a win/tie with three in a row it asks to reset
//the board and play again.

int main ()
{
  //init variabls
  const int XTURN = 0;
  const int OTURN = 1;
  const char BLANK = ' ';
  const int XMOVE = 1;
  const int OMOVE = 2;
  int XSCORE = 0;
  int OSCORE = 0;
  int TIE =0;
  int in_game=1;
  int scorecount = 0;

  char board [4][4];
    board [0][1] = '1';
    board [0][2] = '2';
    board [0][3] = '3';
    board [0][0] = ' ';
    board [1][0] = 'a';
    board [2][0] = 'b';
    board [3][0] = 'c';
    string input = "";
    int turn = XTURN;
    bool playing = true;

    while (in_game ==1) {
      scorecount = 0;
    // init and draw board
    for(int i = 0; i<4; i++){
      for(int j = 0; j<4; j++){
       board [i][j] = BLANK;
       board [0][1] = '1';
       board [0][2] = '2';
       board [0][3] = '3';
       board [0][0] = ' ';
       board [1][0] = 'a';
       board [2][0] = 'b';
       board [3][0] = 'c';
       cout << board [i][j] << " ";
      }
      cout << endl;
    }

    // start playing
    turn = XTURN;
    playing = true;

    while (playing == true){

      if (turn == XTURN) {
        cout << "X's turn:" << endl;
      }
      else {
        cout << "O's turn: " << endl;
      }

      //take input and check if valid
      cin >>input;
      if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
        cout<<"eligible rows are a,b,c"<<endl;
    }
       if (input[1] != '1' && input[1] != '2' && input[1] != '3' ){
        cout<<"eligible columns are 1,2,3"<<endl;
      }

       //read input and assign row/column
      else {
        int row = input[0] - 'a';
        int column = input[1]-'1';
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
    // draw the board and pieces
         for(int i = 0; i<4; i++){
          for(int j = 0; j<4; j++){

            if(board [i][j] ==  XMOVE){
              board [i][j] = 'X';
              scorecount++;
            }
            if (board [i][j] == OMOVE){
              board [i][j] = 'O';
              scorecount++;
                }

            board [0][1] = '1';
            board [0][2] = '2';
            board [0][3] = '3';
            board [0][0] = ' ';
            board [1][0] = 'a';
            board [2][0] = 'b';
            board [3][0] = 'c';

            cout << board [i][j] << " ";

          }
          cout << endl;
        }
      }

      // check row/columns
      for (int a = 1; a<4; a++){

        if (board[a][1] == 'X' && board[a][2] == 'X' && board[a][3] == 'X'){
          cout << "X WINS" << endl;
          XSCORE++;
          playing = false;
        }
        if (board[a][1] == 'O' && board[a][2] == 'O' && board[a][3] == 'O'){
          cout << "O WINS" << endl;
          OSCORE++;
          playing = false;
        }
        if (board[1][a] == 'X' && board[2][a] == 'X' && board[3][a] == 'X'){
          cout << "X WINS" << endl;
          XSCORE++;
          playing = false;
        }
  if (board[1][a] == 'O' && board[2][a] == 'O' && board[3][a] == 'O'){
          cout << "O WINS" << endl;
          OSCORE++;
          playing = false;
        }
      }

        // check diagonal
        if (board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') {
          cout << "X WINS" << endl;
          XSCORE++;
          playing = false;
        }

        if (board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O') {
          cout << "O WINS" << endl;
          OSCORE++;
          playing = false;
        }

         if (board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X') {
          cout << "X WINS" << endl;
          XSCORE++;
          playing = false;
        }

        if (board[3][1] == 'O' && board[2][2] == 'O' && board[1][3] == 'O') {
          cout << "O WINS" << endl;
          OSCORE++;
          playing = false;
        }

        // check for tie
        if (scorecount == 9){
          cout<< "TIE" << endl;
          TIE++;
          playing = false;
        }

    }  // end of while

     cout << "# X wins: " << XSCORE << ", # O wins: " << OSCORE << ", #Ties: " << TIE << endl << endl;

     //play again
     cout << "Play again (y/n)?" << endl;
     cin >> input;

     if (input =="y" || input =="Y") {
      in_game =1;
     }
     else {
      in_game =0;
     }

    }
      return 998;
}
