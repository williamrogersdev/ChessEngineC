#ifdef DEFS_H
#define DEFS_H

//defined 64 bit integer

typedef unsigned long long U64;

#define NAME 'C Chess Engine'
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

//enum for piece types
enum {EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK}; 

//file definitions
enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};

//rank definitions
enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

//color definitions
enum {WHITE, BLACK, BOTH};


//square definitions

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};


enum {FALSE, TRUE};

//represeneted by 4 bits
// 1001 = white can castle kingside, black can castle queenside

    enum {WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8}; // castling permissions for kings.  Queenside and Kingside castling



// Ability to undo moves
    typedef struct {

        int move;
        int castlePerm;
        int enPas;
        int fiftyMove;
        U64 posKey;

    } S_UNDO;


typedef struct {

    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; // 1 bit for each pawn on the board
    int KingSq[2];
    int side;
    int enPas;
    int fiftyMove; // fifty move rule. if 50 moves have been made without a capture or pawn move, the game is a draw
    int ply; // half moves
    int hisPly; // keeping track of how manymoves have been made
    U64 posKey; // unique key for each position
    int castlePerm; // castling permissions


    int pceNum[13]; // number of pieces on the board

    int bigPce[3]; // number of big pieces on the board. .Any piece that is not a pawn
    int majPce[3]; // number of major pieces on the board. . Rooks and Queens
    int minPce[3]; // number of minor pieces on the board. . Bishops and Knights


S_UNDO history[MAXGAMEMOVES]; // history of moves. Everyone time a move is made, it is stored in the history array

} S_BOARD;


#endif