#include <iostream>
#include <vector>
#include <string>
#include <set>
#include<conio.h>
#include <limits>
#include <cstdlib>


#define RESET   "\x1b[0m"
#define RED     "\x1b[91m"
#define GREEN   "\x1b[92m"
#define YELLOW  "\x1b[38;5;227m"
#define BLUE    "\x1b[96m"
#define PINK    "\x1b[38;5;201m"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
    #include <windows.h>
    #define COLOR_SUPPORT 0
    void Color(int color){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
#else
    #define CLEAR_SCREEN "clear"
    #define COLOR_SUPPORT 1

#endif
using namespace std;



class Game{
   vector<vector<string>> board;


public:
    Game(){
        board = {{" 1 ", " 2 ", " 3 "}, {" 4 "," 5 "," 6 "}, {" 7 ", " 8 ", " 9 "}};
    }
    string winner;
    void draw_board(){
        #ifdef _WIN32
        Color(11);
        cout << "   TIC-TAC-TOE" << endl;
        Color(14);
        cout << "-*-*-*-*-*-*-*-*-" << endl;
        #else
        cout << BLUE << "   TIC-TAC-TOE" << RESET << endl;
        cout << YELLOW << "-*-*-*-*-*-*-*-*-" << RESET << endl;
        #endif

        for(int i = 0; i < 3; i++){
            #ifdef _WIN32
               Color(15);
            #endif
            cout << endl;
            cout << "   ";
            for(int j = 0; j < 3; j++){
                #ifdef _WIN32
                  if(j == 0 || j == 1){
                     if(board[i][j] == " X ") Color(12);
                     else if (board[i][j] == " O ") Color(11);

                     cout << board[i][j];
                     Color(15);
                     cout << "|";
                  }
                  else{
                     if(board[i][j] == " X ") Color(12);
                     else if (board[i][j] == " O ") Color(11);

                     cout << board[i][j];
                     Color(15);
                  }

                #else

                  if(j == 0 || j == 1){
                     if(board[i][j] == " X ") cout << RED;
                     else if (board[i][j] == " O ") cout << BLUE;
                     else cout << "";

                     cout << board[i][j] << RESET;
                     cout << "|";
                  }
                  else{
                     if(board[i][j] == " X ") cout << RED;
                     else if (board[i][j] == " O ") cout << BLUE;
                     else cout << "";

                     cout << board[i][j] << RESET;
                  }
                #endif
            }

            cout << endl;
            if(i == 0 || i == 1){
                cout << "  ____|___|____  " << endl;
            }
        }
    }

    void takeInput(int n, int turn_of){
        int row = (n - 1) / 3;
        int col = (n - 1) % 3;
        if (board[row][col] == " " + to_string(n) + " ") {
            if (turn_of % 2 == 0) board[row][col] = " X ";
            else board[row][col] = " O ";
        } else {
            cout << "Grid already taken. Please choose an empty grid." << endl;
        }
    }

    bool checkWinner(){
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                return true;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                winner = board[0][i];
                return true;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
            return true;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
            return true;
        }
        return false;
    }
};

bool playableMove(set<int>& playedGrid, int grid, string& prompt){
    if(grid >= 1 && grid <=9){
        auto it = playedGrid.find(grid);
        if (it != playedGrid.end()) {
            prompt = "Cell already taken! Please choose another cell: ";
            return false;
        } else {
            prompt = "Enter any number (1-9): ";
            return true;
        }
    } else {
        prompt = "Please choose a correct cell (1-9): ";
        return false;
    }
}

int main(){

    Game game;
    set<int> playedGrid;
    string prompt = "Enter any number (1-9): ";
    int index = 0;
    for(int i = 0; i < 9; i++){
        if(game.checkWinner()){
            system(CLEAR_SCREEN);
            game.draw_board();
            cout << endl << endl;
            #ifdef _WIN32
               Color(10);
               cout << "Player ";
               if(game.winner == " X ")
                  Color(12);
               else
                  Color(11);
               cout << game.winner ;
               Color(10);
               cout<< " has won!" << endl << endl;
               Color(14);
               cout << "Press any key to quit...";
            #else
             cout << GREEN << "Player " << RESET;
             if(game.winner == " X ")
                  cout << RED;
               else
                 cout << BLUE;
                 cout << game.winner << RESET;
                 cout<< GREEN << " has won!" << RESET << endl << endl;
                 cout << YELLOW << "Press any key to quit..." << RESET;
            #endif

            getch();
            break;
        }
        int grid;
        game.draw_board();
        string player = "";
        (i % 2 == 0) ? player = "X" : player = "O";

        cout << endl << endl;
        #ifdef _WIN32
         Color(13);
         cout << "Turn of: ";
         if(player == "X"){
             Color(12);
            cout << player << endl << endl;
         }
         else{
             Color(11);
            cout << player << endl << endl;
         }
         Color(15);
        #else
        cout << PINK << "Turn of: " << RESET;
        if(player == "X"){
            cout << RED << player << RESET << endl << endl;
         }
         else{
            cout << BLUE << player << RESET << endl << endl;
         }

        #endif


        #ifdef _WIN32
         Color(14);
         cout << prompt;
         Color(15);
        #else
        cout << YELLOW << prompt << RESET;
        #endif
         if (!(cin >> grid)) {
            system(CLEAR_SCREEN);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            prompt = "Invalid input. Please enter a number (1-9): ";
            --i;
            continue;
        }

        if(playableMove(playedGrid, grid, prompt)){
                game.takeInput(grid, i);
                playedGrid.insert(grid);
                system(CLEAR_SCREEN);
            } else {
                i--;
                system(CLEAR_SCREEN);
                continue;
            }
            index = i;
            system(CLEAR_SCREEN);
    }
    if(index == 8){
      system(CLEAR_SCREEN);
      game.draw_board();
      cout << endl << endl;
      #ifdef _WIN32
         Color(13);
         cout << "Game draw!" << endl << endl;
         Color(14);
         cout << "Press any key to quit...";
      #else
         cout << PINK << "Game draw!" << RESET << endl << endl;
      #endif

      getch();
    }

    return 0;
}
