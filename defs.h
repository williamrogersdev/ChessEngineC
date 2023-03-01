#ifdef DEFS_H
#define DEFS_H

//defined 64 bit integer

typedef unsigned long long U64;

#define NAME 'C Chess Engine'
#define BRD_SQ_NUM 120

//enum for piece types

enum {EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK};

//file definitions

enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};

//rank definitions

enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

//color definitions

enum {WHITE, BLACK, BOTH};


#endif