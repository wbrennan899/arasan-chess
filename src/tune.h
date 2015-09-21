// Copyright 2015 by Jon Dart. All Rights Reserved.

#ifndef _TUNE_H
#define _TUNE_H

#include "scoring.h"

#include <string>
#include <vector>

class Tune {

 public:

  struct TuneParam {
    int index;
    string name;
    int current;
    int min_value;
    int max_value;
    enum Scaling {None, Midgame, Endgame, Any};
    Scaling scaling;
    int tunable; // via MMTO

  TuneParam(int i, const string &n, int c, int minv, int maxv, Scaling s = None,int t = 0) :
    index(i),name(n),current(c),min_value(minv),max_value(maxv),scaling(s),tunable(t) {
    }
    TuneParam():
    index(-1), name(""), current(0), min_value(0), max_value(0),scaling(None),tunable(0) {
    }
  };

  Tune();

  virtual ~Tune() {
  }

  enum {
    RB_ADJUST1,
    RB_ADJUST2,
    RB_ADJUST3,
    RB_ADJUST4,
    RBN_ADJUST1,
    RBN_ADJUST2,
    RBN_ADJUST3,
    RBN_ADJUST4,
    QR_ADJUST0,
    QR_ADJUST1,
    QR_ADJUST2,
    QR_ADJUST3,
    KN_VS_PAWN_ADJUST0,
    KN_VS_PAWN_ADJUST1,
    KN_VS_PAWN_ADJUST2,
    CASTLING0,
    CASTLING1,
    CASTLING2,
    CASTLING3,
    CASTLING4,
    CASTLING5,
    KING_COVER0,
    KING_COVER1,
    KING_COVER2,
    KING_COVER3,
    KING_COVER4,
    KING_COVER_BASE,
    KING_FILE_OPEN,
    KING_DISTANCE_BASIS,
    KING_DISTANCE_MULT,
    PIN_MULTIPLIER_MID,
    PIN_MULTIPLIER_END,
    KRMINOR_VS_R,
    MINOR_FOR_PAWNS,
    ENDGAME_PAWN_ADVANTAGE,
    PAWN_ENDGAME1,
    PAWN_ENDGAME2,
    MINOR_ATTACK_FACTOR,
    ROOK_ATTACK_FACTOR,
    QUEEN_ATTACK_FACTOR,
    ROOK_ATTACK_BOOST,
    QUEEN_ATTACK_BOOST,
    QUEEN_ATTACK_BOOST2,
    KING_ATTACK_PARAM0,
    KING_ATTACK_PARAM1,
    KING_ATTACK_PARAM2,
    KING_ATTACK_PARAM3,
    KING_ATTACK_BOOST_THRESHOLD,
    KING_ATTACK_BOOST_DIVISOR,
    KING_ATTACK_BOOST_MAX,
    BISHOP_TRAPPED,
    BISHOP_PAIR_MID,
    BISHOP_PAIR_END,
    BISHOP_PAWN_PLACEMENT_END,
    BAD_BISHOP_MID,
    BAD_BISHOP_END,
    CENTER_PAWN_BLOCK,
    OUTSIDE_PASSER_MID,
    OUTSIDE_PASSER_END,
    WEAK_PAWN_MID,
    WEAK_PAWN_END,
    WEAK_ON_OPEN_FILE_MID,
    WEAK_ON_OPEN_FILE_END,
    SPACE,
    PAWN_CENTER_SCORE_MID,
    ROOK_ON_7TH_MID,
    ROOK_ON_7TH_END,
    TWO_ROOKS_ON_7TH_MID,
    TWO_ROOKS_ON_7TH_END,
    ROOK_ON_OPEN_FILE_MID,
    ROOK_ON_OPEN_FILE_END,
    ROOK_ATTACKS_WEAK_PAWN_MID,
    ROOK_ATTACKS_WEAK_PAWN_END,
    ROOK_BEHIND_PP_MID,
    ROOK_BEHIND_PP_END,
    QUEEN_OUT,
    KING_NEAR_PASSER,
    OPP_KING_NEAR_PASSER,
    PAWN_SIDE_BONUS,
    SUPPORTED_PASSER6,
    SUPPORTED_PASSER7,
    SIDE_PROTECTED_PAWN,
    KING_ATTACK_INFLECT1,
    KING_ATTACK_INFLECT2,
    KING_ATTACK_SLOPE_FACTOR,
    TRADE_DOWN_LINEAR,
    TRADE_DOWN_SQ,
    PASSED_PAWN_MID2,
    PASSED_PAWN_MID3,
    PASSED_PAWN_MID4,
    PASSED_PAWN_MID5,
    PASSED_PAWN_MID6,
    PASSED_PAWN_MID7,
    PASSED_PAWN_END2,
    PASSED_PAWN_END3,
    PASSED_PAWN_END4,
    PASSED_PAWN_END5,
    PASSED_PAWN_END6,
    PASSED_PAWN_END7,
    POTENTIAL_PASSER_MID2,
    POTENTIAL_PASSER_MID3,
    POTENTIAL_PASSER_MID4,
    POTENTIAL_PASSER_MID5,
    POTENTIAL_PASSER_MID6,
    POTENTIAL_PASSER_END2,
    POTENTIAL_PASSER_END3,
    POTENTIAL_PASSER_END4,
    POTENTIAL_PASSER_END5,
    POTENTIAL_PASSER_END6,
    CONNECTED_PASSER_MID2,
    CONNECTED_PASSER_MID3,
    CONNECTED_PASSER_MID4,
    CONNECTED_PASSER_MID5,
    CONNECTED_PASSER_MID6,
    CONNECTED_PASSER_MID7,
    CONNECTED_PASSER_END2,
    CONNECTED_PASSER_END3,
    CONNECTED_PASSER_END4,
    CONNECTED_PASSER_END5,
    CONNECTED_PASSER_END6,
    CONNECTED_PASSER_END7,
    DOUBLED_PAWNS_MID1,
    DOUBLED_PAWNS_MID2,
    DOUBLED_PAWNS_MID3,
    DOUBLED_PAWNS_MID4,
    DOUBLED_PAWNS_END1,
    DOUBLED_PAWNS_END2,
    DOUBLED_PAWNS_END3,
    DOUBLED_PAWNS_END4,
    TRIPLED_PAWNS_MID1,
    TRIPLED_PAWNS_MID2,
    TRIPLED_PAWNS_MID3,
    TRIPLED_PAWNS_MID4,
    TRIPLED_PAWNS_END1,
    TRIPLED_PAWNS_END2,
    TRIPLED_PAWNS_END3,
    TRIPLED_PAWNS_END4,
    ISOLATED_PAWN_MID1,
    ISOLATED_PAWN_MID2,
    ISOLATED_PAWN_MID3,
    ISOLATED_PAWN_MID4,
    ISOLATED_PAWN_END1,
    ISOLATED_PAWN_END2,
    ISOLATED_PAWN_END3,
    ISOLATED_PAWN_END4,
    PP_OWN_PIECE_BLOCK_MID = ISOLATED_PAWN_END4+1,
    PP_OWN_PIECE_BLOCK_END = PP_OWN_PIECE_BLOCK_MID+21,
    PP_OPP_PIECE_BLOCK_MID = PP_OWN_PIECE_BLOCK_END+21,
    PP_OPP_PIECE_BLOCK_END = PP_OPP_PIECE_BLOCK_MID+21,
    KNIGHT_PST_MIDGAME = PP_OPP_PIECE_BLOCK_END+21,
    KNIGHT_PST_ENDGAME = KNIGHT_PST_MIDGAME+32,
    BISHOP_PST_MIDGAME = KNIGHT_PST_ENDGAME+32,
    BISHOP_PST_ENDGAME = BISHOP_PST_MIDGAME+32,
    ROOK_PST_MIDGAME = BISHOP_PST_ENDGAME+32,
    ROOK_PST_ENDGAME = ROOK_PST_MIDGAME+32,
    QUEEN_PST_MIDGAME = ROOK_PST_ENDGAME+32,
    QUEEN_PST_ENDGAME = QUEEN_PST_MIDGAME+32,
    KING_PST_MIDGAME = QUEEN_PST_ENDGAME+32,
    KING_PST_ENDGAME = KING_PST_MIDGAME+32,
    KNIGHT_MOBILITY = KING_PST_ENDGAME+32,
    BISHOP_MOBILITY = KNIGHT_MOBILITY+9,
    ROOK_MOBILITY_MIDGAME = BISHOP_MOBILITY+15,
    ROOK_MOBILITY_ENDGAME = ROOK_MOBILITY_MIDGAME+15,
    QUEEN_MOBILITY_MIDGAME = ROOK_MOBILITY_ENDGAME+15,
    QUEEN_MOBILITY_ENDGAME = QUEEN_MOBILITY_MIDGAME+29,
    KING_MOBILITY_ENDGAME = QUEEN_MOBILITY_ENDGAME+29,
    KNIGHT_OUTPOST = KING_MOBILITY_ENDGAME+9,
    BISHOP_OUTPOST = KNIGHT_OUTPOST+16
  };
   
  int numTuningParams() const;

  // initialize scoring parameters from the current tuned parameter
  // set
  void applyParams() const;

  // check current param settings against bounds and verify indexes
  // in internal array
  void checkParams() const;

  // write parameter values to a stream
  void writeX0(ostream &);

  // read parameter values from a stream
  void readX0(istream &);

  void getParam(int index, TuneParam &param) const;

  int getParamValue(int index) const;

  void updateParamValue(int index, int value);

  int findParamByName(const string &name) const;

  static const int NUM_MISC_PARAMS = 145;

  double scale(double value,int index,int materialLevel) const;

 private:

  vector<TuneParam> tune_params;

};
#endif
