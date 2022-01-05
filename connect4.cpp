#include<bits/stdc++.h>
using namespace std;
const int num_row =6;
const int num_col =7;

// TO DISPLAY THE BOARD 
void show_board(int board[][num_col]){
    for(int row=0; row<num_row; row++){
        for(int col=0; col<num_col; col++){
                cout << board[row][col]<<" ";
        }
        cout << endl;
    }
}

// TO ADD VALUES TO THE BOARD
void add_value(int col,int  player,int board[][num_col]){
    col =col-1;
    for(int row=num_row-1; row>-1; row--){
        if(board[row][col]==0){
            board[row][col]=player;
            break;
        }
    }

}

bool win_horiz(int board[][num_col]){                       //TO CHECK HORIZONTALLY
    for(int row=0; row<num_row; row++){
        for(int col=0; col<4; col++){
            if(board[row][col]>0){
                if(board[row][col]&&board[row][col+1]&&board[row][col+2]&&board[row][col+3]){
                        cout<<"PLAYER "<<board[row][col]<<" WON THE GAME"<<endl;
                        return true;
                }
            }
        }
    }

    return false;
}


bool win_verti(int board[][num_col]){
                                                        //TO CHECK VERTICALLY
    for(int row=0; row<3; row++){
        for(int col=0; col<num_col; col++){
            if(board[row][col]>0){
                if(board[row][col]&&board[row+1][col]&& board[row+2][col]&&board[row+3][col]){
                        cout<<"PLAYER "<<board[row][col]<<" WON THE GAME"<<endl;
                        return true;
                }
            }
        }
    }
    return false;
}


bool win_diag(int board[][num_col]){
                                                        //TO CHECK DIAGONALLY
    for(int row=3; row<num_row; row++){
        for(int col=0; col<4; col++){
            if(board[row][col]>0){
                if(board[row][col]&&board[row-1][col+1]&&board[row-2][col+2]&&board[row-3][col+3]){
                        cout<<"PLAYER "<<board[row][col]<<" WON THE GAME"<<endl;
                        return true;
                }
            }
        }
    }


    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            if(board[row][col]>0){
                if(board[row][col]&&board[row+1][col+1]&& board[row+2][col+2]&&board[row+3][col+3]){
                        cout<<"PLAYER "<<board[row][col]<<" WON THE GAME"<<endl;
                        return true;
                }
            }
        }
    }

    return false;
}



bool win(int board[][num_col]){
    if(win_horiz(board) || win_verti(board) || win_diag(board)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int board[6][7]={{0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0}};
    
    
    
    int player=1;
    do {
        int col;                                    // TO TAKE THE COLUMN NUMBER TO ADD VALUE                            
        cout<<"ENTER THE COLUMN(1 - 7):  ";
        cin>>col;
        add_value(col, player, board);                  //FUNCTION TO ADD VALUE TO  THE BOARD
        show_board(board);                             //FUNCTION TO DISPLAY THE BOARD
                                                     // TO CHANGE THE PLAYERS ONE AFTER ANOTHER
        if(player==1){
            player=2;
        }
        else{
            player=1;
        }
    }while((win(board)==false));

    return 0;
}