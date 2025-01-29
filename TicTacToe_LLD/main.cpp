#include<bits/stdc++.h>
using namespace std;

enum class PieceType{
    O,
    X
};

class PlayingPiece{
public:
    PieceType type;
    PlayingPiece(PieceType type) : type(type){}
    virtual ~PlayingPiece() = default;
};

class PlayingPieceO : public PlayingPiece{
public:
    PlayingPieceO(PieceType type): PlayingPiece(PieceType :: O){}
};
class PlayingPieceX : public PlayingPiece{
public:
    PlayingPieceX(PieceType type): PlayingPiece(PieceType :: X){}
};

class Player{
public:
    string name;
    PlayingPiece* playingPiece;

    Player(string name, PlayingPiece* playingPiece) : name(name), playingPiece(playingPiece){}

    string getName(){
        return name;
    }
    PlayingPiece* getPiece(){
        return playingPiece;
    }
    void setName(string name){
        this->name = name;
    }
    void setPlayingPiece(PlayingPiece* playingPiece){
        this->playingPiece = playingPiece;
    }
};

class Board{
public: 
    int size;
    vector<vector<PlayingPiece*>> *board;            //VERY IMPORTANT
    Board(int size){
        this->size = size;
        this->board = new vector<vector<PlayingPiece*>> (size, vector<PlayingPiece*>(size, nullptr));          //VERY IMPORTANT
    }
    bool addPiece(int row, int col, PlayingPiece* playingPiece){        //how to know when to refer and when to derefer
        if(row >= size || col >= size) return false;
        if((*board)[row][col] != nullptr) return false;

        (*board)[row][col] = playingPiece;
        return true;
    }
    vector<pair<int,int>> getFreeCells(){
        vector<pair<int,int>> freeCells;
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if((*board)[i][j] == nullptr){
                    freeCells.push_back({i,j});
                }
            }
        }
        return freeCells;
    }
    void printBoard(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if((*board)[i][j] != nullptr){
                    cout << ((*board)[i][j]->type == PieceType::O ? " O " : " X ") ;
                }else{
                    cout << "   ";
                }
                cout << " | ";
            }
            cout << endl;
        }
    }   
};  

class TicTacToe{
    deque<Player*> players;
    Board* gameBoard;
public:
    void initializeGame(int n){
        PlayingPieceO* noughtsPiece = new PlayingPieceO(PieceType::O);
        PlayingPieceX* crossPiece = new PlayingPieceX(PieceType::X);

        Player* p1 = new Player("Player1", noughtsPiece);
        Player* p2 = new Player("Player2", crossPiece);

        players.push_back(p1);
        players.push_back(p2);

        gameBoard = new Board(n);
    }
    string startGame(){
        bool noWinner = true;
        for(auto it : players){

        }
        while(noWinner){
            Player* playerTurn = players.front();
            gameBoard->printBoard();
            vector<pair<int,int>> freeCells = gameBoard->getFreeCells();
            if(freeCells.size() == 0){
                noWinner = false;
                continue;
            }
            cout << "Player: " << playerTurn->name << " Enter row, coloumn : " << endl;
            int inputRow, inputCol; cin >> inputRow >> inputCol;
            bool pieceAddedSuccessfully = gameBoard->addPiece(inputRow, inputCol, playerTurn->playingPiece);
            if(!pieceAddedSuccessfully){
                cout << "Incorrect position choosen : Please try again!!!" << endl;
                players.push_front(playerTurn);
                continue;
            }
            players.pop_front();
            players.push_back(playerTurn);
            bool winner = isThereWinner(inputRow, inputCol, (playerTurn->playingPiece->type));
            if(winner){
                gameBoard->printBoard();
                return playerTurn->name;
            }
        }
        return "Tie!!!";
    }
    bool isThereWinner(int inputRow, int inputCol, PieceType pieceType){

        bool rowWin = true, colWin = true, diagonalWin = true, antiDiagonalWin = true;

        for(int i=0;i<gameBoard->size; i++){
            if((*gameBoard->board)[i][inputCol] == nullptr || (*gameBoard->board)[i][inputCol]->type != pieceType){
                rowWin = false;
            }
        }
        for(int j=0; j<gameBoard->size; j++){
            if((*gameBoard->board)[inputRow][j] == nullptr || (*gameBoard->board)[inputRow][j]->type != pieceType){
                colWin = false;
            }
        }
        for(int i=0,j=0; i<gameBoard->size; i++,j++){
            if((*gameBoard->board)[i][j] == nullptr || (*gameBoard->board)[i][j]->type != pieceType){
                diagonalWin = false;
            }
        }
        for(int i=gameBoard->size-1,j=0; i>=0; i--,j++){
            if((*gameBoard->board)[i][j] == nullptr || (*gameBoard->board)[i][j]->type != pieceType){
                antiDiagonalWin = false;
            }
        }
        return rowWin || colWin || diagonalWin || antiDiagonalWin;
    }

};


int main(){
    TicTacToe* game = new TicTacToe();
    game->initializeGame(5);
    string winner = game->startGame();
    cout << "Game winner is -----> " << winner << endl;
    return 0;
}