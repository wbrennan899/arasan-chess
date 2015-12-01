// Copyright 2015 by Jon Dart. All Rights Reserved.
// This is a generated file. Do not edit.
//

const int Scoring::Params::RB_ADJUST[4] = {-183, -18, 124, 187};
const int Scoring::Params::RBN_ADJUST[4] = {-433, -614, -776, -1052};
const int Scoring::Params::QR_ADJUST[4] = {-436, 66, 565, 567};
const int Scoring::Params::KN_VS_PAWN_ADJUST[3] = {-68, -2341, -1436};
const int Scoring::Params::CASTLING[6] = {60, -16, -115, 222, 136, -217};
const int Scoring::Params::KING_COVER[5] = {138, 310, 250, 29, -37};
const int Scoring::Params::KING_COVER_BASE = -293;
const int Scoring::Params::KING_FILE_OPEN = -285;
const int Scoring::Params::KING_DISTANCE_BASIS = 312;
const int Scoring::Params::KING_DISTANCE_MULT = 77;
const int Scoring::Params::PIN_MULTIPLIER_MID = 207;
const int Scoring::Params::PIN_MULTIPLIER_END = 340;
const int Scoring::Params::ROOK_VS_PAWNS = 266;
const int Scoring::Params::KRMINOR_VS_R = -168;
const int Scoring::Params::KRMINOR_VS_R_NO_PAWNS = -568;
const int Scoring::Params::KQMINOR_VS_Q = -41;
const int Scoring::Params::KQMINOR_VS_Q_NO_PAWNS = -168;
const int Scoring::Params::MINOR_FOR_PAWNS = 292;
const int Scoring::Params::ENDGAME_PAWN_ADVANTAGE = 0;
const int Scoring::Params::PAWN_ENDGAME1 = 118;
const int Scoring::Params::PAWN_ENDGAME2 = 54;
const int Scoring::Params::MINOR_ATTACK_FACTOR = 315;
const int Scoring::Params::ROOK_ATTACK_FACTOR = 585;
const int Scoring::Params::QUEEN_ATTACK_FACTOR = 640;
const int Scoring::Params::ROOK_ATTACK_BOOST = 79;
const int Scoring::Params::QUEEN_ATTACK_BOOST = 332;
const int Scoring::Params::QUEEN_ATTACK_BOOST2 = 169;
const int Scoring::Params::KING_ATTACK_PARAM0 = -48;
const int Scoring::Params::KING_ATTACK_PARAM1 = 325;
const int Scoring::Params::KING_ATTACK_PARAM2 = 24;
const int Scoring::Params::KING_ATTACK_PARAM3 = 25;
const int Scoring::Params::KING_ATTACK_BOOST_THRESHOLD = -787;
const int Scoring::Params::KING_ATTACK_BOOST_DIVISOR = 850;
const int Scoring::Params::KING_ATTACK_BOOST_MAX = 128;
const int Scoring::Params::BISHOP_TRAPPED = -1470;
const int Scoring::Params::BISHOP_PAIR_MID = 400;
const int Scoring::Params::BISHOP_PAIR_END = 532;
const int Scoring::Params::BISHOP_PAWN_PLACEMENT_END = -120;
const int Scoring::Params::BAD_BISHOP_MID = -14;
const int Scoring::Params::BAD_BISHOP_END = -34;
const int Scoring::Params::CENTER_PAWN_BLOCK = -127;
const int Scoring::Params::OUTSIDE_PASSER_MID = 35;
const int Scoring::Params::OUTSIDE_PASSER_END = 159;
const int Scoring::Params::WEAK_PAWN_MID = -32;
const int Scoring::Params::WEAK_PAWN_END = -34;
const int Scoring::Params::WEAK_ON_OPEN_FILE_MID = -114;
const int Scoring::Params::WEAK_ON_OPEN_FILE_END = -131;
const int Scoring::Params::SPACE = 48;
const int Scoring::Params::PAWN_CENTER_SCORE_MID = 30;
const int Scoring::Params::ROOK_ON_7TH_MID = 269;
const int Scoring::Params::ROOK_ON_7TH_END = 275;
const int Scoring::Params::TWO_ROOKS_ON_7TH_MID = 270;
const int Scoring::Params::TWO_ROOKS_ON_7TH_END = 294;
const int Scoring::Params::ROOK_ON_OPEN_FILE_MID = 210;
const int Scoring::Params::ROOK_ON_OPEN_FILE_END = 202;
const int Scoring::Params::ROOK_ATTACKS_WEAK_PAWN_MID = 116;
const int Scoring::Params::ROOK_ATTACKS_WEAK_PAWN_END = 164;
const int Scoring::Params::ROOK_BEHIND_PP_MID = 85;
const int Scoring::Params::ROOK_BEHIND_PP_END = 122;
const int Scoring::Params::QUEEN_OUT = -68;
const int Scoring::Params::PAWN_SIDE_BONUS = 257;
const int Scoring::Params::KING_OWN_PAWN_DISTANCE = 9;
const int Scoring::Params::KING_OPP_PAWN_DISTANCE = 117;
const int Scoring::Params::SUPPORTED_PASSER6 = 334;
const int Scoring::Params::SUPPORTED_PASSER7 = 668;
const int Scoring::Params::SIDE_PROTECTED_PAWN = -92;
const int Scoring::Params::KING_OPP_PASSER_DISTANCE[6] = {0, 0, 76, 107, 118, 128};
const int Scoring::Params::KING_POSITION_LOW_MATERIAL[3] ={180, 160, 150};
const int Scoring::Params::KING_ATTACK_SCALE[512] = {0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 20, 21, 21, 22, 23, 24, 24, 25, 26, 27, 27, 28, 29, 30, 30, 31, 32, 33, 33, 34, 35, 36, 36, 37, 38, 39, 39, 40, 41, 42, 42, 43, 44, 45, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68, 69, 71, 72, 73, 74, 76, 77, 78, 79, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 96, 97, 98, 99, 101, 102, 103, 104, 106, 107, 108, 109, 111, 112, 113, 114, 116, 117, 118, 119, 121, 122, 123, 124, 126, 127, 128, 129, 131, 132, 133, 134, 136, 137, 138, 139, 141, 142, 143, 144, 146, 147, 148, 149, 151, 152, 153, 154, 156, 157, 158, 159, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 196, 197, 198, 198, 199, 200, 201, 201, 202, 203, 204, 204, 205, 206, 207, 207, 208, 209, 209, 210, 211, 212, 212, 213, 214, 214, 215, 216, 217, 217, 218, 219, 219, 220, 221, 222, 222, 223, 224, 224, 225, 226, 226, 227, 228, 228, 229, 230, 230, 231, 232, 232, 233, 234, 234, 235, 236, 236, 237, 238, 238, 239, 240, 240, 241, 242, 242, 243, 244, 244, 245, 246, 246, 247, 247, 248, 249, 249, 250, 251, 251, 252, 252, 253, 254, 254, 255, 256, 256, 257, 257, 258, 259, 259, 260, 260, 261, 262, 262, 263, 263, 264, 265, 265, 266, 266, 267, 267, 268, 269, 269, 270, 270, 271, 272, 272, 273, 273, 274, 274, 275, 275, 276, 277, 277, 278, 278, 279, 279, 280, 280, 281, 282, 282, 283, 283, 284, 284, 285, 285, 286, 286, 287, 287, 288, 288, 289, 290, 290, 291, 291, 292, 292, 293, 293, 294, 294, 295, 295, 296, 296, 297, 297, 298, 298, 299, 299, 300, 300, 301, 301, 302, 302, 302, 303, 303, 304, 304, 305, 305, 306, 306, 307, 307, 308, 308, 309, 309, 309, 310, 310, 311, 311, 312, 312, 313, 313, 314, 314, 314, 315, 315, 316, 316, 317, 317, 317, 318, 318, 319, 319, 320, 320, 320, 321, 321, 322, 322, 322, 323, 323, 324, 324, 324, 325, 325, 326, 326, 326, 327, 327, 328, 328, 328, 329, 329, 330, 330, 330, 331, 331, 331, 332, 332, 333, 333, 333, 334, 334, 334, 335, 335, 335, 336, 336, 337, 337, 337, 338, 338, 338, 339, 339, 339, 340, 340, 340, 341, 341, 341, 342, 342, 342, 343, 343, 343, 344, 344, 344, 344, 345, 345, 345, 346, 346, 346, 347, 347, 347, 348, 348, 348, 348, 349, 349, 349, 350, 350, 350, 350, 351, 351, 351, 352, 352, 352, 352, 353, 353, 353, 353, 354, 354, 354, 354, 355, 355, 355, 355};
const int Scoring::Params::TRADE_DOWN[16] = {756, 713, 671, 627, 591, 546, 497, 319, 383, 233, 217, 283, 104, 76, 19, 0};
const int Scoring::Params::PASSED_PAWN[2][8] = {{0, 0, 7, 54, 128, 293, 615, 1165}, {0, 0, 58, 107, 234, 447, 876, 1348}};
const int Scoring::Params::POTENTIAL_PASSER[2][8] = {{0, 0, 0, 0, 13, 33, 289, 0}, {0, 0, 0, 5, 58, 147, 423, 0}};
const int Scoring::Params::CONNECTED_PASSER[2][8] = {{0, 0, 0, 50, 158, 282, 594, 838}, {0, 0, 0, 50, 228, 300, 622, 868}};
const int Scoring::Params::ADJACENT_PASSER[2][8] = {{0, 0, 0, 54, 98, 89, 362, 833}, {0, 0, 0, 59, 103, 146, 330, 733}};
const int Scoring::Params::PP_OWN_PIECE_BLOCK[2][21] = {{-66, -66, -69, -62, -75, -73, -83, -83, -75, -79, -94, -94, -8, -103, -68, -12, -39, -128, -16, -15, -22}, {-12, -81, 0, -69, -48, -98, -108, -123, -115, -137, -126, -69, -69, -87, -78, -109, -114, -122, -155, -165, -317}};
const int Scoring::Params::PP_OPP_PIECE_BLOCK[2][21] = {{-224, -143, -99, -77, -67, -83, -244, -153, -117, -96, -91, -267, -148, -102, -105, -280, -75, -134, -286, -125, -289}, {-195, -168, -102, -81, -91, -177, -207, -135, -161, -121, -193, -227, -210, -174, -127, -265, -211, -147, -333, -255, -333}};
const int Scoring::Params::DOUBLED_PAWNS[2][8] = {{-114, -41, -158, -71, -71, -158, -41, -114}, {-145, -152, -138, -165, -165, -138, -152, -145}};
const int Scoring::Params::TRIPLED_PAWNS[2][8] = {{-6, -61, -93, -230, -230, -93, -61, -6}, {-156, -116, -227, -352, -352, -227, -116, -156}};
const int Scoring::Params::ISOLATED_PAWN[2][8] = {{-27, -23, -91, -144, -144, -91, -23, -27}, {-71, -79, -78, -127, -127, -78, -79, -71}};

const int Scoring::Params::KNIGHT_PST[2][64] = {{-280, -176, -158, -143, -143, -158, -176, -280, -172, -115, -92, -49, -49, -92, -115, -172, -178, -22, -6, 38, 38, -6, -22, -178, -132, 30, 54, 62, 62, 54, 30, -132, -58, 14, 57, 79, 79, 57, 14, -58, -65, -83, 33, 55, 55, 33, -83, -65, -213, -62, 12, 22, 22, 12, -62, -213, -247, -157, -137, -24, -24, -137, -157, -247}, {-294, -250, -216, -202, -202, -216, -250, -294, -187, -145, -110, -98, -98, -110, -145, -187, -152, -108, -80, 11, 11, -80, -108, -152, -135, -75, 38, 46, 46, 38, -75, -135, -133, -63, 37, 43, 43, 37, -63, -133, -129, -6, -17, 34, 34, -17, -6, -129, -189, -120, -103, -4, -4, -103, -120, -189, -236, -192, -135, -138, -138, -135, -192, -236}};
const int Scoring::Params::BISHOP_PST[2][64] = {{-260, -52, -98, -184, -184, -98, -52, -260, -52, 116, -49, 23, 23, -49, 116, -52, -38, 54, 29, 44, 44, 29, 54, -38, -47, -52, 1, 147, 147, 1, -52, -47, -63, 1, 95, 115, 115, 95, 1, -63, 162, 35, 50, 142, 142, 50, 35, 162, -45, -52, -78, -166, -166, -78, -52, -45, -125, -163, -37, -134, -134, -37, -163, -125}, {-118, -92, -51, -14, -14, -51, -92, -118, -61, 10, -25, 22, 22, -25, 10, -61, -41, 52, 78, 101, 101, 78, 52, -41, 8, 20, 124, 139, 139, 124, 20, 8, -8, 37, 63, 108, 108, 63, 37, -8, 57, 46, 57, 63, 63, 57, 46, 57, 9, 40, -15, 31, 31, -15, 40, 9, -12, 13, 50, -8, -8, 50, 13, -12}};
const int Scoring::Params::ROOK_PST[2][64] = {{-51, -50, 36, 47, 47, 36, -50, -51, -62, -57, -57, -40, -40, -57, -57, -62, -56, -59, 8, 29, 29, 8, -59, -56, -64, -48, 32, 31, 31, 32, -48, -64, 50, 59, 59, 62, 62, 59, 59, 50, 60, 63, 61, 61, 61, 61, 63, 60, 41, 40, 50, 35, 35, 50, 40, 41, 46, 66, 59, 37, 37, 59, 66, 46}, {-50, -59, -55, -57, -57, -55, -59, -50, -59, -59, -46, -46, -46, -46, -59, -59, -40, -38, -32, -41, -41, -32, -38, -40, 44, 39, 55, 34, 34, 55, 39, 44, 48, 54, 59, 56, 56, 59, 54, 48, 58, 57, 59, 57, 57, 59, 57, 58, 23, 26, 41, 32, 32, 41, 26, 23, 55, 61, 59, 63, 63, 59, 61, 55}};
const int Scoring::Params::QUEEN_PST[2][64] = {{-21, -37, -46, 32, 32, -46, -37, -21, 33, -22, 48, 42, 42, 48, -22, 33, -52, 6, 45, -53, -53, 45, 6, -52, -49, -41, 20, -5, -5, 20, -41, -49, -53, -8, 26, -7, -7, 26, -8, -53, -57, 19, 56, 56, 56, 56, 19, -57, -39, -60, 46, 10, 10, 46, -60, -39, 69, 68, 65, 68, 68, 65, 68, 69}, {-64, -65, -62, -63, -63, -62, -65, -64, -61, -62, -66, -63, -63, -66, -62, -61, -57, -47, 2, -48, -48, 2, -47, -57, -32, 49, 58, 55, 55, 58, 49, -32, 1, 61, 61, 59, 59, 61, 61, 1, 14, 58, 62, 60, 60, 62, 58, 14, 27, 56, 59, 58, 58, 59, 56, 27, 50, 53, 55, 60, 60, 55, 53, 50}};
const int Scoring::Params::KING_PST[2][64] = {{-54, 53, -60, 57, 57, -60, 53, -54, 27, 57, -50, 56, 56, -50, 57, 27, -75, -28, -39, -14, -14, -39, -28, -75, -304, -332, -314, -340, -340, -314, -332, -304, -311, -433, -428, -430, -430, -428, -433, -311, -293, -310, -428, -325, -325, -428, -310, -293, -292, -293, -293, -429, -429, -293, -293, -292, -292, -292, -423, -292, -292, -423, -292, -292}, {-305, -176, -211, -162, -162, -211, -176, -305, -169, -127, -147, -52, -52, -147, -127, -169, -202, -76, -30, 13, 13, -30, -76, -202, -128, -13, 42, 90, 90, 42, -13, -128, -45, 56, 102, 141, 141, 102, 56, -45, -43, 118, 77, 111, 111, 77, 118, -43, 38, 104, 121, 167, 167, 121, 104, 38, 15, 92, 125, 167, 167, 125, 92, 15}};

const int Scoring::Params::KNIGHT_MOBILITY[9] = {-241, -123, -63, -31, 54, 90, 106, 114, 68};
const int Scoring::Params::BISHOP_MOBILITY[15] = {-235, -146, -108, -54, 23, 62, 94, 120, 93, 136, 67, 90, 33, 135, 22};
const int Scoring::Params::ROOK_MOBILITY[2][15] = {{-247, -152, -75, -69, -38, 31, 93, 132, 153, 178, 205, 232, 240, 281, 305}, {-341, -215, -144, 13, 3, 70, 121, 161, 204, 248, 277, 304, 310, 267, 262}};
const int Scoring::Params::QUEEN_MOBILITY[2][29] = {{-116, -74, -11, -32, 8, 33, 57, 70, 145, 174, 192, 206, 229, 236, 247, 259, 256, 271, 273, 276, 278, 278, 278, 278, 278, 278, 278, 278, 142}, {-188, -123, -73, -41, -8, 26, 65, 84, 108, 115, 194, 236, 272, 293, 306, 311, 307, 318, 310, 309, 309, 243, 266, 193, 314, 196, 193, 193, 192}};
const int Scoring::Params::KING_MOBILITY_ENDGAME[9] = {-250, -149, -80, 8, 54, 33, 64, -9, -38};

const int Scoring::Params::KNIGHT_OUTPOST[3][64] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 101, 101, 82, 0, 0, 0, 0, 0, 114, 114, 0, 0, 0, 0, 0, 62, 62, 62, 62, 0, 0, 0, 0, 0, 49, 49, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 147, 196, 196, 147, 28, 0, 72, 89, 142, 189, 189, 142, 89, 72, 78, 0, 95, 116, 116, 95, 0, 78, 0, 0, 77, 0, 0, 77, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61, 147, 189, 189, 147, 61, 0, 0, 70, 16, 198, 198, 16, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78, 78, 78, 78, 78, 78, 0}};
const int Scoring::Params::BISHOP_OUTPOST[3][64] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 79, 101, 101, 79, 0, 0, 67, 0, 79, 89, 89, 79, 0, 67, 60, 55, 41, 0, 0, 41, 55, 60, 69, 62, 61, 0, 0, 61, 62, 69},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 37, 159, 159, 37, 8, 0, 0, 7, 23, 51, 51, 23, 7, 0, 0, 71, 0, 0, 0, 0, 71, 0, 0, 67, 0, 0, 0, 0, 67, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96, 27, 50, 50, 27, 96, 0, 0, 0, 2, 147, 147, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 78, 0}};
