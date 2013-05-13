// Copyright 1994-2002, 2004, 2008-2009 by Jon Dart.  All Rights Reserved.

#ifndef _LEARN_H
#define _LEARN_H

// Support for learning

#include "board.h"
#include "log.h"
#include <istream>

// Activate the book learning feature. Call after a move
// has been added to the log. Board is the position before the move.
extern void learn(const Board &board, int rep_count);

// Learn after a game has been played.
extern void learnResult(ColorType computerSide, Log::GameResult result, int ratingDiff);

struct LearnRecord {
  hash_t hashcode;
  int in_check;
  int score, depth;
  Square start, dest;
  PieceType promotion;
};

// Retrieve position learning info
extern int getLearnRecord(istream &learnFile, LearnRecord &);

#endif
