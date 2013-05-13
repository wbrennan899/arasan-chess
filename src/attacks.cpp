// Copyright 2008-2012 by Jon Dart.  All Rights Reserved.
//
#include "attacks.h"
#include "util.h"
#include "debug.h"

int Attacks::directions[64][64];

const Bitboard Attacks::knight_attacks[64] = {
  Bitboard(0x20400ULL),
  Bitboard(0x50800ULL),
  Bitboard(0xa1100ULL),
  Bitboard(0x142200ULL),
  Bitboard(0x284400ULL),
  Bitboard(0x508800ULL),
  Bitboard(0xa01000ULL),
  Bitboard(0x402000ULL),
  Bitboard(0x2040004ULL),
  Bitboard(0x5080008ULL),
  Bitboard(0xa110011ULL),
  Bitboard(0x14220022ULL),
  Bitboard(0x28440044ULL),
  Bitboard(0x50880088ULL),
  Bitboard(0xa0100010ULL),
  Bitboard(0x40200020ULL),
  Bitboard(0x204000402ULL),
  Bitboard(0x508000805ULL),
  Bitboard(0xa1100110aULL),
  Bitboard(0x1422002214ULL),
  Bitboard(0x2844004428ULL),
  Bitboard(0x5088008850ULL),
  Bitboard(0xa0100010a0ULL),
  Bitboard(0x4020002040ULL),
  Bitboard(0x20400040200ULL),
  Bitboard(0x50800080500ULL),
  Bitboard(0xa1100110a00ULL),
  Bitboard(0x142200221400ULL),
  Bitboard(0x284400442800ULL),
  Bitboard(0x508800885000ULL),
  Bitboard(0xa0100010a000ULL),
  Bitboard(0x402000204000ULL),
  Bitboard(0x2040004020000ULL),
  Bitboard(0x5080008050000ULL),
  Bitboard(0xa1100110a0000ULL),
  Bitboard(0x14220022140000ULL),
  Bitboard(0x28440044280000ULL),
  Bitboard(0x50880088500000ULL),
  Bitboard(0xa0100010a00000ULL),
  Bitboard(0x40200020400000ULL),
  Bitboard(0x204000402000000ULL),
  Bitboard(0x508000805000000ULL),
  Bitboard(0xa1100110a000000ULL),
  Bitboard(0x1422002214000000ULL),
  Bitboard(0x2844004428000000ULL),
  Bitboard(0x5088008850000000ULL),
  Bitboard(0xa0100010a0000000ULL),
  Bitboard(0x4020002040000000ULL),
  Bitboard(0x400040200000000ULL),
  Bitboard(0x800080500000000ULL),
  Bitboard(0x1100110a00000000ULL),
  Bitboard(0x2200221400000000ULL),
  Bitboard(0x4400442800000000ULL),
  Bitboard(0x8800885000000000ULL),
  Bitboard(0x100010a000000000ULL),
  Bitboard(0x2000204000000000ULL),
  Bitboard(0x4020000000000ULL),
  Bitboard(0x8050000000000ULL),
  Bitboard(0x110a0000000000ULL),
  Bitboard(0x22140000000000ULL),
  Bitboard(0x44280000000000ULL),
  Bitboard(0x88500000000000ULL),
  Bitboard(0x10a00000000000ULL),
  Bitboard(0x20400000000000ULL)
};

const Bitboard Attacks::king_attacks[64] = {
  Bitboard(0x302ULL),
  Bitboard(0x705ULL),
  Bitboard(0xe0aULL),
  Bitboard(0x1c14ULL),
  Bitboard(0x3828ULL),
  Bitboard(0x7050ULL),
  Bitboard(0xe0a0ULL),
  Bitboard(0xc040ULL),
  Bitboard(0x30203ULL),
  Bitboard(0x70507ULL),
  Bitboard(0xe0a0eULL),
  Bitboard(0x1c141cULL),
  Bitboard(0x382838ULL),
  Bitboard(0x705070ULL),
  Bitboard(0xe0a0e0ULL),
  Bitboard(0xc040c0ULL),
  Bitboard(0x3020300ULL),
  Bitboard(0x7050700ULL),
  Bitboard(0xe0a0e00ULL),
  Bitboard(0x1c141c00ULL),
  Bitboard(0x38283800ULL),
  Bitboard(0x70507000ULL),
  Bitboard(0xe0a0e000ULL),
  Bitboard(0xc040c000ULL),
  Bitboard(0x302030000ULL),
  Bitboard(0x705070000ULL),
  Bitboard(0xe0a0e0000ULL),
  Bitboard(0x1c141c0000ULL),
  Bitboard(0x3828380000ULL),
  Bitboard(0x7050700000ULL),
  Bitboard(0xe0a0e00000ULL),
  Bitboard(0xc040c00000ULL),
  Bitboard(0x30203000000ULL),
  Bitboard(0x70507000000ULL),
  Bitboard(0xe0a0e000000ULL),
  Bitboard(0x1c141c000000ULL),
  Bitboard(0x382838000000ULL),
  Bitboard(0x705070000000ULL),
  Bitboard(0xe0a0e0000000ULL),
  Bitboard(0xc040c0000000ULL),
  Bitboard(0x3020300000000ULL),
  Bitboard(0x7050700000000ULL),
  Bitboard(0xe0a0e00000000ULL),
  Bitboard(0x1c141c00000000ULL),
  Bitboard(0x38283800000000ULL),
  Bitboard(0x70507000000000ULL),
  Bitboard(0xe0a0e000000000ULL),
  Bitboard(0xc040c000000000ULL),
  Bitboard(0x302030000000000ULL),
  Bitboard(0x705070000000000ULL),
  Bitboard(0xe0a0e0000000000ULL),
  Bitboard(0x1c141c0000000000ULL),
  Bitboard(0x3828380000000000ULL),
  Bitboard(0x7050700000000000ULL),
  Bitboard(0xe0a0e00000000000ULL),
  Bitboard(0xc040c00000000000ULL),
  Bitboard(0x203000000000000ULL),
  Bitboard(0x507000000000000ULL),
  Bitboard(0xa0e000000000000ULL),
  Bitboard(0x141c000000000000ULL),
  Bitboard(0x2838000000000000ULL),
  Bitboard(0x5070000000000000ULL),
  Bitboard(0xa0e0000000000000ULL),
  Bitboard(0x40c0000000000000ULL)
};

const Bitboard Attacks::pawn_attacks[64][2] = {
{Bitboard(0x0ULL),Bitboard(0x200ULL)},
{Bitboard(0x0ULL),Bitboard(0x500ULL)},
{Bitboard(0x0ULL),Bitboard(0xa00ULL)},
{Bitboard(0x0ULL),Bitboard(0x1400ULL)},
{Bitboard(0x0ULL),Bitboard(0x2800ULL)},
{Bitboard(0x0ULL),Bitboard(0x5000ULL)},
{Bitboard(0x0ULL),Bitboard(0xa000ULL)},
{Bitboard(0x0ULL),Bitboard(0x4000ULL)},
{Bitboard(0x2ULL),Bitboard(0x20000ULL)},
{Bitboard(0x5ULL),Bitboard(0x50000ULL)},
{Bitboard(0xaULL),Bitboard(0xa0000ULL)},
{Bitboard(0x14ULL),Bitboard(0x140000ULL)},
{Bitboard(0x28ULL),Bitboard(0x280000ULL)},
{Bitboard(0x50ULL),Bitboard(0x500000ULL)},
{Bitboard(0xa0ULL),Bitboard(0xa00000ULL)},
{Bitboard(0x40ULL),Bitboard(0x400000ULL)},
{Bitboard(0x200ULL),Bitboard(0x2000000ULL)},
{Bitboard(0x500ULL),Bitboard(0x5000000ULL)},
{Bitboard(0xa00ULL),Bitboard(0xa000000ULL)},
{Bitboard(0x1400ULL),Bitboard(0x14000000ULL)},
{Bitboard(0x2800ULL),Bitboard(0x28000000ULL)},
{Bitboard(0x5000ULL),Bitboard(0x50000000ULL)},
{Bitboard(0xa000ULL),Bitboard(0xa0000000ULL)},
{Bitboard(0x4000ULL),Bitboard(0x40000000ULL)},
{Bitboard(0x20000ULL),Bitboard(0x200000000ULL)},
{Bitboard(0x50000ULL),Bitboard(0x500000000ULL)},
{Bitboard(0xa0000ULL),Bitboard(0xa00000000ULL)},
{Bitboard(0x140000ULL),Bitboard(0x1400000000ULL)},
{Bitboard(0x280000ULL),Bitboard(0x2800000000ULL)},
{Bitboard(0x500000ULL),Bitboard(0x5000000000ULL)},
{Bitboard(0xa00000ULL),Bitboard(0xa000000000ULL)},
{Bitboard(0x400000ULL),Bitboard(0x4000000000ULL)},
{Bitboard(0x2000000ULL),Bitboard(0x20000000000ULL)},
{Bitboard(0x5000000ULL),Bitboard(0x50000000000ULL)},
{Bitboard(0xa000000ULL),Bitboard(0xa0000000000ULL)},
{Bitboard(0x14000000ULL),Bitboard(0x140000000000ULL)},
{Bitboard(0x28000000ULL),Bitboard(0x280000000000ULL)},
{Bitboard(0x50000000ULL),Bitboard(0x500000000000ULL)},
{Bitboard(0xa0000000ULL),Bitboard(0xa00000000000ULL)},
{Bitboard(0x40000000ULL),Bitboard(0x400000000000ULL)},
{Bitboard(0x200000000ULL),Bitboard(0x2000000000000ULL)},
{Bitboard(0x500000000ULL),Bitboard(0x5000000000000ULL)},
{Bitboard(0xa00000000ULL),Bitboard(0xa000000000000ULL)},
{Bitboard(0x1400000000ULL),Bitboard(0x14000000000000ULL)},
{Bitboard(0x2800000000ULL),Bitboard(0x28000000000000ULL)},
{Bitboard(0x5000000000ULL),Bitboard(0x50000000000000ULL)},
{Bitboard(0xa000000000ULL),Bitboard(0xa0000000000000ULL)},
{Bitboard(0x4000000000ULL),Bitboard(0x40000000000000ULL)},
{Bitboard(0x20000000000ULL),Bitboard(0x200000000000000ULL)},
{Bitboard(0x50000000000ULL),Bitboard(0x500000000000000ULL)},
{Bitboard(0xa0000000000ULL),Bitboard(0xa00000000000000ULL)},
{Bitboard(0x140000000000ULL),Bitboard(0x1400000000000000ULL)},
{Bitboard(0x280000000000ULL),Bitboard(0x2800000000000000ULL)},
{Bitboard(0x500000000000ULL),Bitboard(0x5000000000000000ULL)},
{Bitboard(0xa00000000000ULL),Bitboard(0xa000000000000000ULL)},
{Bitboard(0x400000000000ULL),Bitboard(0x4000000000000000ULL)},
{Bitboard(0x2000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0x5000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0xa000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0x14000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0x28000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0x50000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0xa0000000000000ULL),Bitboard(0x0ULL)},
{Bitboard(0x40000000000000ULL),Bitboard(0x0ULL)}
};
const CACHE_ALIGN Bitboard Attacks::file_mask[8] = {
  Bitboard(0x101010101010101ULL),
  Bitboard(0x202020202020202ULL),
  Bitboard(0x404040404040404ULL),
  Bitboard(0x808080808080808ULL),
  Bitboard(0x1010101010101010ULL),
  Bitboard(0x2020202020202020ULL),
  Bitboard(0x4040404040404040ULL),
  Bitboard(0x8080808080808080ULL),
};
const CACHE_ALIGN  Bitboard Attacks::rank_mask[8] = {
  Bitboard(0xffULL),
  Bitboard(0xff00ULL),
  Bitboard(0xff0000ULL),
  Bitboard(0xff000000ULL),
  Bitboard(0xff00000000ULL),
  Bitboard(0xff0000000000ULL),
  Bitboard(0xff000000000000ULL),
  Bitboard(0xff00000000000000ULL)
};
const CACHE_ALIGN Bitboard Attacks::file_mask_up[64] = {
Bitboard(0x101010101010100ULL),
Bitboard(0x202020202020200ULL),
Bitboard(0x404040404040400ULL),
Bitboard(0x808080808080800ULL),
Bitboard(0x1010101010101000ULL),
Bitboard(0x2020202020202000ULL),
Bitboard(0x4040404040404000ULL),
Bitboard(0x8080808080808000ULL),
Bitboard(0x101010101010000ULL),
Bitboard(0x202020202020000ULL),
Bitboard(0x404040404040000ULL),
Bitboard(0x808080808080000ULL),
Bitboard(0x1010101010100000ULL),
Bitboard(0x2020202020200000ULL),
Bitboard(0x4040404040400000ULL),
Bitboard(0x8080808080800000ULL),
Bitboard(0x101010101000000ULL),
Bitboard(0x202020202000000ULL),
Bitboard(0x404040404000000ULL),
Bitboard(0x808080808000000ULL),
Bitboard(0x1010101010000000ULL),
Bitboard(0x2020202020000000ULL),
Bitboard(0x4040404040000000ULL),
Bitboard(0x8080808080000000ULL),
Bitboard(0x101010100000000ULL),
Bitboard(0x202020200000000ULL),
Bitboard(0x404040400000000ULL),
Bitboard(0x808080800000000ULL),
Bitboard(0x1010101000000000ULL),
Bitboard(0x2020202000000000ULL),
Bitboard(0x4040404000000000ULL),
Bitboard(0x8080808000000000ULL),
Bitboard(0x101010000000000ULL),
Bitboard(0x202020000000000ULL),
Bitboard(0x404040000000000ULL),
Bitboard(0x808080000000000ULL),
Bitboard(0x1010100000000000ULL),
Bitboard(0x2020200000000000ULL),
Bitboard(0x4040400000000000ULL),
Bitboard(0x8080800000000000ULL),
Bitboard(0x101000000000000ULL),
Bitboard(0x202000000000000ULL),
Bitboard(0x404000000000000ULL),
Bitboard(0x808000000000000ULL),
Bitboard(0x1010000000000000ULL),
Bitboard(0x2020000000000000ULL),
Bitboard(0x4040000000000000ULL),
Bitboard(0x8080000000000000ULL),
Bitboard(0x100000000000000ULL),
Bitboard(0x200000000000000ULL),
Bitboard(0x400000000000000ULL),
Bitboard(0x800000000000000ULL),
Bitboard(0x1000000000000000ULL),
Bitboard(0x2000000000000000ULL),
Bitboard(0x4000000000000000ULL),
Bitboard(0x8000000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL)
};
const CACHE_ALIGN Bitboard Attacks::file_mask_down[64] = {
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x1ULL),
Bitboard(0x2ULL),
Bitboard(0x4ULL),
Bitboard(0x8ULL),
Bitboard(0x10ULL),
Bitboard(0x20ULL),
Bitboard(0x40ULL),
Bitboard(0x80ULL),
Bitboard(0x101ULL),
Bitboard(0x202ULL),
Bitboard(0x404ULL),
Bitboard(0x808ULL),
Bitboard(0x1010ULL),
Bitboard(0x2020ULL),
Bitboard(0x4040ULL),
Bitboard(0x8080ULL),
Bitboard(0x10101ULL),
Bitboard(0x20202ULL),
Bitboard(0x40404ULL),
Bitboard(0x80808ULL),
Bitboard(0x101010ULL),
Bitboard(0x202020ULL),
Bitboard(0x404040ULL),
Bitboard(0x808080ULL),
Bitboard(0x1010101ULL),
Bitboard(0x2020202ULL),
Bitboard(0x4040404ULL),
Bitboard(0x8080808ULL),
Bitboard(0x10101010ULL),
Bitboard(0x20202020ULL),
Bitboard(0x40404040ULL),
Bitboard(0x80808080ULL),
Bitboard(0x101010101ULL),
Bitboard(0x202020202ULL),
Bitboard(0x404040404ULL),
Bitboard(0x808080808ULL),
Bitboard(0x1010101010ULL),
Bitboard(0x2020202020ULL),
Bitboard(0x4040404040ULL),
Bitboard(0x8080808080ULL),
Bitboard(0x10101010101ULL),
Bitboard(0x20202020202ULL),
Bitboard(0x40404040404ULL),
Bitboard(0x80808080808ULL),
Bitboard(0x101010101010ULL),
Bitboard(0x202020202020ULL),
Bitboard(0x404040404040ULL),
Bitboard(0x808080808080ULL),
Bitboard(0x1010101010101ULL),
Bitboard(0x2020202020202ULL),
Bitboard(0x4040404040404ULL),
Bitboard(0x8080808080808ULL),
Bitboard(0x10101010101010ULL),
Bitboard(0x20202020202020ULL),
Bitboard(0x40404040404040ULL),
Bitboard(0x80808080808080ULL)
};
const CACHE_ALIGN Bitboard Attacks::rank_mask_right[64]={
Bitboard(0xfeULL),
Bitboard(0xfcULL),
Bitboard(0xf8ULL),
Bitboard(0xf0ULL),
Bitboard(0xe0ULL),
Bitboard(0xc0ULL),
Bitboard(0x80ULL),
Bitboard(0x0ULL),
Bitboard(0xfe00ULL),
Bitboard(0xfc00ULL),
Bitboard(0xf800ULL),
Bitboard(0xf000ULL),
Bitboard(0xe000ULL),
Bitboard(0xc000ULL),
Bitboard(0x8000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe0000ULL),
Bitboard(0xfc0000ULL),
Bitboard(0xf80000ULL),
Bitboard(0xf00000ULL),
Bitboard(0xe00000ULL),
Bitboard(0xc00000ULL),
Bitboard(0x800000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe000000ULL),
Bitboard(0xfc000000ULL),
Bitboard(0xf8000000ULL),
Bitboard(0xf0000000ULL),
Bitboard(0xe0000000ULL),
Bitboard(0xc0000000ULL),
Bitboard(0x80000000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe00000000ULL),
Bitboard(0xfc00000000ULL),
Bitboard(0xf800000000ULL),
Bitboard(0xf000000000ULL),
Bitboard(0xe000000000ULL),
Bitboard(0xc000000000ULL),
Bitboard(0x8000000000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe0000000000ULL),
Bitboard(0xfc0000000000ULL),
Bitboard(0xf80000000000ULL),
Bitboard(0xf00000000000ULL),
Bitboard(0xe00000000000ULL),
Bitboard(0xc00000000000ULL),
Bitboard(0x800000000000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe000000000000ULL),
Bitboard(0xfc000000000000ULL),
Bitboard(0xf8000000000000ULL),
Bitboard(0xf0000000000000ULL),
Bitboard(0xe0000000000000ULL),
Bitboard(0xc0000000000000ULL),
Bitboard(0x80000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0xfe00000000000000ULL),
Bitboard(0xfc00000000000000ULL),
Bitboard(0xf800000000000000ULL),
Bitboard(0xf000000000000000ULL),
Bitboard(0xe000000000000000ULL),
Bitboard(0xc000000000000000ULL),
Bitboard(0x8000000000000000ULL),
Bitboard(0x0ULL)
};
const CACHE_ALIGN Bitboard Attacks::rank_mask_left[64]={
Bitboard(0x0ULL),
Bitboard(0x1ULL),
Bitboard(0x3ULL),
Bitboard(0x7ULL),
Bitboard(0xfULL),
Bitboard(0x1fULL),
Bitboard(0x3fULL),
Bitboard(0x7fULL),
Bitboard(0x0ULL),
Bitboard(0x100ULL),
Bitboard(0x300ULL),
Bitboard(0x700ULL),
Bitboard(0xf00ULL),
Bitboard(0x1f00ULL),
Bitboard(0x3f00ULL),
Bitboard(0x7f00ULL),
Bitboard(0x0ULL),
Bitboard(0x10000ULL),
Bitboard(0x30000ULL),
Bitboard(0x70000ULL),
Bitboard(0xf0000ULL),
Bitboard(0x1f0000ULL),
Bitboard(0x3f0000ULL),
Bitboard(0x7f0000ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000ULL),
Bitboard(0x3000000ULL),
Bitboard(0x7000000ULL),
Bitboard(0xf000000ULL),
Bitboard(0x1f000000ULL),
Bitboard(0x3f000000ULL),
Bitboard(0x7f000000ULL),
Bitboard(0x0ULL),
Bitboard(0x100000000ULL),
Bitboard(0x300000000ULL),
Bitboard(0x700000000ULL),
Bitboard(0xf00000000ULL),
Bitboard(0x1f00000000ULL),
Bitboard(0x3f00000000ULL),
Bitboard(0x7f00000000ULL),
Bitboard(0x0ULL),
Bitboard(0x10000000000ULL),
Bitboard(0x30000000000ULL),
Bitboard(0x70000000000ULL),
Bitboard(0xf0000000000ULL),
Bitboard(0x1f0000000000ULL),
Bitboard(0x3f0000000000ULL),
Bitboard(0x7f0000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000000000ULL),
Bitboard(0x3000000000000ULL),
Bitboard(0x7000000000000ULL),
Bitboard(0xf000000000000ULL),
Bitboard(0x1f000000000000ULL),
Bitboard(0x3f000000000000ULL),
Bitboard(0x7f000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x100000000000000ULL),
Bitboard(0x300000000000000ULL),
Bitboard(0x700000000000000ULL),
Bitboard(0xf00000000000000ULL),
Bitboard(0x1f00000000000000ULL),
Bitboard(0x3f00000000000000ULL),
Bitboard(0x7f00000000000000ULL)
};
const CACHE_ALIGN Bitboard Attacks::diag_a1_lower_mask[64] = {
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x1ULL),
Bitboard(0x2ULL),
Bitboard(0x4ULL),
Bitboard(0x8ULL),
Bitboard(0x10ULL),
Bitboard(0x20ULL),
Bitboard(0x40ULL),
Bitboard(0x0ULL),
Bitboard(0x100ULL),
Bitboard(0x201ULL),
Bitboard(0x402ULL),
Bitboard(0x804ULL),
Bitboard(0x1008ULL),
Bitboard(0x2010ULL),
Bitboard(0x4020ULL),
Bitboard(0x0ULL),
Bitboard(0x10000ULL),
Bitboard(0x20100ULL),
Bitboard(0x40201ULL),
Bitboard(0x80402ULL),
Bitboard(0x100804ULL),
Bitboard(0x201008ULL),
Bitboard(0x402010ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000ULL),
Bitboard(0x2010000ULL),
Bitboard(0x4020100ULL),
Bitboard(0x8040201ULL),
Bitboard(0x10080402ULL),
Bitboard(0x20100804ULL),
Bitboard(0x40201008ULL),
Bitboard(0x0ULL),
Bitboard(0x100000000ULL),
Bitboard(0x201000000ULL),
Bitboard(0x402010000ULL),
Bitboard(0x804020100ULL),
Bitboard(0x1008040201ULL),
Bitboard(0x2010080402ULL),
Bitboard(0x4020100804ULL),
Bitboard(0x0ULL),
Bitboard(0x10000000000ULL),
Bitboard(0x20100000000ULL),
Bitboard(0x40201000000ULL),
Bitboard(0x80402010000ULL),
Bitboard(0x100804020100ULL),
Bitboard(0x201008040201ULL),
Bitboard(0x402010080402ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000000000ULL),
Bitboard(0x2010000000000ULL),
Bitboard(0x4020100000000ULL),
Bitboard(0x8040201000000ULL),
Bitboard(0x10080402010000ULL),
Bitboard(0x20100804020100ULL),
Bitboard(0x40201008040201ULL)
};
const CACHE_ALIGN Bitboard Attacks::diag_a1_mask[64] = {
Bitboard(0x804020108040200ULL),
Bitboard(0x80402010080400ULL),
Bitboard(0x804020100800ULL),
Bitboard(0x8040201000ULL),
Bitboard(0x080402000ULL),
Bitboard(0x0804000ULL),
Bitboard(0x08000ULL),
Bitboard(0x00ULL),
Bitboard(0x402010084020000ULL),
Bitboard(0x804020108040001ULL),
Bitboard(0x80402010080002ULL),
Bitboard(0x804020100004ULL),
Bitboard(0x8040200008ULL),
Bitboard(0x080400010ULL),
Bitboard(0x0800020ULL),
Bitboard(0x040ULL),
Bitboard(0x201008042000000ULL),
Bitboard(0x402010084000100ULL),
Bitboard(0x804020108000201ULL),
Bitboard(0x80402010000402ULL),
Bitboard(0x804020000804ULL),
Bitboard(0x8040001008ULL),
Bitboard(0x080002010ULL),
Bitboard(0x04020ULL),
Bitboard(0x100804020ULL),
Bitboard(0x2010080410000ULL),
Bitboard(0x4020100820100ULL),
Bitboard(0x8040201040201ULL),
Bitboard(0x80402080402ULL),
Bitboard(0x8040100804ULL),
Bitboard(0x80201008ULL),
Bitboard(0x0402010ULL),
Bitboard(0x80402000ULL),
Bitboard(0x100804001000000ULL),
Bitboard(0x201008002010000ULL),
Bitboard(0x402010004020100ULL),
Bitboard(0x804020008040201ULL),
Bitboard(0x80400010080402ULL),
Bitboard(0x800020100804ULL),
Bitboard(0x040201008ULL),
Bitboard(0x40200000ULL),
Bitboard(0x80400010ULL),
Bitboard(0x100800021000000ULL),
Bitboard(0x201000042010000ULL),
Bitboard(0x402000084020100ULL),
Bitboard(0x804000108040201ULL),
Bitboard(0x80002010080402ULL),
Bitboard(0x4020100804ULL),
Bitboard(0x20000000ULL),
Bitboard(0x40001000ULL),
Bitboard(0x80002010ULL),
Bitboard(0x100004021000000ULL),
Bitboard(0x200008042010000ULL),
Bitboard(0x400010084020100ULL),
Bitboard(0x800020108040201ULL),
Bitboard(0x402010080402ULL),
Bitboard(0x00ULL),
Bitboard(0x100000ULL),
Bitboard(0x201000ULL),
Bitboard(0x402010ULL),
Bitboard(0x804021000000ULL),
Bitboard(0x1008042010000ULL),
Bitboard(0x2010084020100ULL),
Bitboard(0x4020108040201ULL)};
const CACHE_ALIGN Bitboard Attacks::diag_a1_upper_mask[64] = {
Bitboard(0x8040201008040200ULL),
Bitboard(0x80402010080400ULL),
Bitboard(0x804020100800ULL),
Bitboard(0x8040201000ULL),
Bitboard(0x80402000ULL),
Bitboard(0x804000ULL),
Bitboard(0x8000ULL),
Bitboard(0x0ULL),
Bitboard(0x4020100804020000ULL),
Bitboard(0x8040201008040000ULL),
Bitboard(0x80402010080000ULL),
Bitboard(0x804020100000ULL),
Bitboard(0x8040200000ULL),
Bitboard(0x80400000ULL),
Bitboard(0x800000ULL),
Bitboard(0x0ULL),
Bitboard(0x2010080402000000ULL),
Bitboard(0x4020100804000000ULL),
Bitboard(0x8040201008000000ULL),
Bitboard(0x80402010000000ULL),
Bitboard(0x804020000000ULL),
Bitboard(0x8040000000ULL),
Bitboard(0x80000000ULL),
Bitboard(0x0ULL),
Bitboard(0x1008040200000000ULL),
Bitboard(0x2010080400000000ULL),
Bitboard(0x4020100800000000ULL),
Bitboard(0x8040201000000000ULL),
Bitboard(0x80402000000000ULL),
Bitboard(0x804000000000ULL),
Bitboard(0x8000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x804020000000000ULL),
Bitboard(0x1008040000000000ULL),
Bitboard(0x2010080000000000ULL),
Bitboard(0x4020100000000000ULL),
Bitboard(0x8040200000000000ULL),
Bitboard(0x80400000000000ULL),
Bitboard(0x800000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x402000000000000ULL),
Bitboard(0x804000000000000ULL),
Bitboard(0x1008000000000000ULL),
Bitboard(0x2010000000000000ULL),
Bitboard(0x4020000000000000ULL),
Bitboard(0x8040000000000000ULL),
Bitboard(0x80000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x200000000000000ULL),
Bitboard(0x400000000000000ULL),
Bitboard(0x800000000000000ULL),
Bitboard(0x1000000000000000ULL),
Bitboard(0x2000000000000000ULL),
Bitboard(0x4000000000000000ULL),
Bitboard(0x8000000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL)
};
const CACHE_ALIGN Bitboard Attacks::diag_a8_lower_mask[64] = {
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x2ULL),
Bitboard(0x4ULL),
Bitboard(0x8ULL),
Bitboard(0x10ULL),
Bitboard(0x20ULL),
Bitboard(0x40ULL),
Bitboard(0x80ULL),
Bitboard(0x0ULL),
Bitboard(0x204ULL),
Bitboard(0x408ULL),
Bitboard(0x810ULL),
Bitboard(0x1020ULL),
Bitboard(0x2040ULL),
Bitboard(0x4080ULL),
Bitboard(0x8000ULL),
Bitboard(0x0ULL),
Bitboard(0x20408ULL),
Bitboard(0x40810ULL),
Bitboard(0x81020ULL),
Bitboard(0x102040ULL),
Bitboard(0x204080ULL),
Bitboard(0x408000ULL),
Bitboard(0x800000ULL),
Bitboard(0x0ULL),
Bitboard(0x2040810ULL),
Bitboard(0x4081020ULL),
Bitboard(0x8102040ULL),
Bitboard(0x10204080ULL),
Bitboard(0x20408000ULL),
Bitboard(0x40800000ULL),
Bitboard(0x80000000ULL),
Bitboard(0x0ULL),
Bitboard(0x204081020ULL),
Bitboard(0x408102040ULL),
Bitboard(0x810204080ULL),
Bitboard(0x1020408000ULL),
Bitboard(0x2040800000ULL),
Bitboard(0x4080000000ULL),
Bitboard(0x8000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x20408102040ULL),
Bitboard(0x40810204080ULL),
Bitboard(0x81020408000ULL),
Bitboard(0x102040800000ULL),
Bitboard(0x204080000000ULL),
Bitboard(0x408000000000ULL),
Bitboard(0x800000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x2040810204080ULL),
Bitboard(0x4081020408000ULL),
Bitboard(0x8102040800000ULL),
Bitboard(0x10204080000000ULL),
Bitboard(0x20408000000000ULL),
Bitboard(0x40800000000000ULL),
Bitboard(0x80000000000000ULL),
Bitboard(0x0ULL)
};
const CACHE_ALIGN Bitboard Attacks::diag_a8_upper_mask[64] = {
Bitboard(0x0ULL),
Bitboard(0x100ULL),
Bitboard(0x10200ULL),
Bitboard(0x1020400ULL),
Bitboard(0x102040800ULL),
Bitboard(0x10204081000ULL),
Bitboard(0x1020408102000ULL),
Bitboard(0x102040810204000ULL),
Bitboard(0x0ULL),
Bitboard(0x10000ULL),
Bitboard(0x1020000ULL),
Bitboard(0x102040000ULL),
Bitboard(0x10204080000ULL),
Bitboard(0x1020408100000ULL),
Bitboard(0x102040810200000ULL),
Bitboard(0x204081020400000ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000ULL),
Bitboard(0x102000000ULL),
Bitboard(0x10204000000ULL),
Bitboard(0x1020408000000ULL),
Bitboard(0x102040810000000ULL),
Bitboard(0x204081020000000ULL),
Bitboard(0x408102040000000ULL),
Bitboard(0x0ULL),
Bitboard(0x100000000ULL),
Bitboard(0x10200000000ULL),
Bitboard(0x1020400000000ULL),
Bitboard(0x102040800000000ULL),
Bitboard(0x204081000000000ULL),
Bitboard(0x408102000000000ULL),
Bitboard(0x810204000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x10000000000ULL),
Bitboard(0x1020000000000ULL),
Bitboard(0x102040000000000ULL),
Bitboard(0x204080000000000ULL),
Bitboard(0x408100000000000ULL),
Bitboard(0x810200000000000ULL),
Bitboard(0x1020400000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x1000000000000ULL),
Bitboard(0x102000000000000ULL),
Bitboard(0x204000000000000ULL),
Bitboard(0x408000000000000ULL),
Bitboard(0x810000000000000ULL),
Bitboard(0x1020000000000000ULL),
Bitboard(0x2040000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x100000000000000ULL),
Bitboard(0x200000000000000ULL),
Bitboard(0x400000000000000ULL),
Bitboard(0x800000000000000ULL),
Bitboard(0x1000000000000000ULL),
Bitboard(0x2000000000000000ULL),
Bitboard(0x4000000000000000ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL),
Bitboard(0x0ULL)
};
const CACHE_ALIGN Bitboard Attacks::diag_a8_mask[64] = {
Bitboard(0x080ULL),
Bitboard(0x08100ULL),
Bitboard(0x0810200ULL),
Bitboard(0x081020400ULL),
Bitboard(0x812040800ULL),
Bitboard(0x81024081000ULL),
Bitboard(0x8102048102000ULL),
Bitboard(0x01ULL),
Bitboard(0x08000ULL),
Bitboard(0x0810004ULL),
Bitboard(0x081020008ULL),
Bitboard(0x812040010ULL),
Bitboard(0x81024080020ULL),
Bitboard(0x8102048100040ULL),
Bitboard(0x8102040810200081ULL),
Bitboard(0x0100ULL),
Bitboard(0x0800000ULL),
Bitboard(0x081000408ULL),
Bitboard(0x812000810ULL),
Bitboard(0x81024001020ULL),
Bitboard(0x8102048002040ULL),
Bitboard(0x8102040810004081ULL),
Bitboard(0x204081020008100ULL),
Bitboard(0x010000ULL),
Bitboard(0x080000000ULL),
Bitboard(0x8140810ULL),
Bitboard(0x810281020ULL),
Bitboard(0x810204102040ULL),
Bitboard(0x81020408204081ULL),
Bitboard(0x2040810408100ULL),
Bitboard(0x4081020810000ULL),
Bitboard(0x01000000ULL),
Bitboard(0x800ULL),
Bitboard(0x81004081020ULL),
Bitboard(0x8102008102040ULL),
Bitboard(0x8102040010204081ULL),
Bitboard(0x204080020408100ULL),
Bitboard(0x408100040810000ULL),
Bitboard(0x810200081000000ULL),
Bitboard(0x10ULL),
Bitboard(0x80000ULL),
Bitboard(0x8100048102040ULL),
Bitboard(0x8102000810204081ULL),
Bitboard(0x204001020408100ULL),
Bitboard(0x408002040810000ULL),
Bitboard(0x810004081000000ULL),
Bitboard(0x102000810ULL),
Bitboard(0x1000ULL),
Bitboard(0x8000000ULL),
Bitboard(0x8100040810204081ULL),
Bitboard(0x200081020408100ULL),
Bitboard(0x400102040810000ULL),
Bitboard(0x800204081000000ULL),
Bitboard(0x100040810ULL),
Bitboard(0x200081000ULL),
Bitboard(0x100000ULL),
Bitboard(0x800000000ULL),
Bitboard(0x4081020408100ULL),
Bitboard(0x8102040810000ULL),
Bitboard(0x10204081000000ULL),
Bitboard(0x2040810ULL),
Bitboard(0x4081000ULL),
Bitboard(0x8100000ULL),
Bitboard(0x10000000ULL)
  };
const Bitboard Attacks::ep_mask[8][2] =
{
{Bitboard(0x2000000ULL), Bitboard(0x200000000ULL)}, 
{Bitboard(0x5000000ULL), Bitboard(0x500000000ULL)}, 
{Bitboard(0xa000000ULL), Bitboard(0xa00000000ULL)}, 
{Bitboard(0x14000000ULL), Bitboard(0x1400000000ULL)}, 
{Bitboard(0x28000000ULL), Bitboard(0x2800000000ULL)}, 
{Bitboard(0x50000000ULL), Bitboard(0x5000000000ULL)}, 
{Bitboard(0xa0000000ULL), Bitboard(0xa000000000ULL)}, 
{Bitboard(0x40000000ULL), Bitboard(0x4000000000ULL)}
};

Bitboard Attacks::rank7mask[2];

#ifdef _64BIT
const CACHE_ALIGN unsigned Attacks::r_shift[64]=
{
	52, 53, 53, 53, 53, 53, 53, 52,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 54, 54, 54, 54, 53,
	53, 54, 54, 53, 53, 53, 53, 53
};

const CACHE_ALIGN Bitboard Attacks::r_magic[64]=
{
   Bitboard(0x0080001020400080ULL), Bitboard(0x0040001000200040ULL), Bitboard(0x0080081000200080ULL), Bitboard(0x0080040800100080ULL),
	Bitboard(0x0080020400080080ULL), Bitboard(0x0080010200040080ULL), Bitboard(0x0080008001000200ULL), Bitboard(0x0080002040800100ULL),
	Bitboard(0x0000800020400080ULL), Bitboard(0x0000400020005000ULL), Bitboard(0x0000801000200080ULL), Bitboard(0x0000800800100080ULL),
	Bitboard(0x0000800400080080ULL), Bitboard(0x0000800200040080ULL), Bitboard(0x0000800100020080ULL), Bitboard(0x0000800040800100ULL),
	Bitboard(0x0000208000400080ULL), Bitboard(0x0000404000201000ULL), Bitboard(0x0000808010002000ULL), Bitboard(0x0000808008001000ULL),
	Bitboard(0x0000808004000800ULL), Bitboard(0x0000808002000400ULL), Bitboard(0x0000010100020004ULL), Bitboard(0x0000020000408104ULL),
	Bitboard(0x0000208080004000ULL), Bitboard(0x0000200040005000ULL), Bitboard(0x0000100080200080ULL), Bitboard(0x0000080080100080ULL),
	Bitboard(0x0000040080080080ULL), Bitboard(0x0000020080040080ULL), Bitboard(0x0000010080800200ULL), Bitboard(0x0000800080004100ULL),
	Bitboard(0x0000204000800080ULL), Bitboard(0x0000200040401000ULL), Bitboard(0x0000100080802000ULL), Bitboard(0x0000080080801000ULL),
	Bitboard(0x0000040080800800ULL), Bitboard(0x0000020080800400ULL), Bitboard(0x0000020001010004ULL), Bitboard(0x0000800040800100ULL),
	Bitboard(0x0000204000808000ULL), Bitboard(0x0000200040008080ULL), Bitboard(0x0000100020008080ULL), Bitboard(0x0000080010008080ULL),
	Bitboard(0x0000040008008080ULL), Bitboard(0x0000020004008080ULL), Bitboard(0x0000010002008080ULL), Bitboard(0x0000004081020004ULL),
	Bitboard(0x0000204000800080ULL), Bitboard(0x0000200040008080ULL), Bitboard(0x0000100020008080ULL), Bitboard(0x0000080010008080ULL),
	Bitboard(0x0000040008008080ULL), Bitboard(0x0000020004008080ULL), Bitboard(0x0000800100020080ULL), Bitboard(0x0000800041000080ULL),
	Bitboard(0x00FFFCDDFCED714AULL), Bitboard(0x007FFCDDFCED714AULL), Bitboard(0x003FFFCDFFD88096ULL), Bitboard(0x0000040810002101ULL),
	Bitboard(0x0001000204080011ULL), Bitboard(0x0001000204000801ULL), Bitboard(0x0001000082000401ULL), Bitboard(0x0001FFFAABFAD1A2ULL)
};
#else // 32 bit
const CACHE_ALIGN unsigned Attacks::r_shift[64] = {
20, 21, 21, 21, 21, 21, 21, 20, 
21, 22, 22, 22, 22, 22, 22, 21, 
21, 22, 22, 22, 22, 22, 22, 21, 
21, 22, 22, 22, 22, 22, 22, 21, 
21, 22, 22, 22, 22, 22, 22, 21, 
21, 22, 22, 22, 22, 22, 22, 21, 
21, 22, 22, 22, 22, 22, 22, 21, 
20, 21, 21, 21, 21, 21, 21, 20
};
const CACHE_ALIGN Bitboard Attacks::r_magic[64]=
{
  Bitboard(0xa0588002001205ULL),
  Bitboard(0x2410004001400220ULL),
  Bitboard(0x110040220600408ULL),
  Bitboard(0x1003100810080082ULL),
  Bitboard(0x2200100220404204ULL),
  Bitboard(0x300088311000204ULL),
  Bitboard(0x121000401000092ULL),
  Bitboard(0x80308001800941ULL),
  Bitboard(0x1024090000080208ULL),
  Bitboard(0x30402c0000004010ULL),
  Bitboard(0x44a200042004018ULL),
  Bitboard(0x2008401200181001ULL),
  Bitboard(0x102001004020818ULL),
  Bitboard(0x100c0000420202ULL),
  Bitboard(0x5120008010201ULL),
  Bitboard(0x410412e010020101ULL),
  Bitboard(0x40314000a081002ULL),
  Bitboard(0xa12400400182020ULL),
  Bitboard(0x4080110000b20208ULL),
  Bitboard(0x22004020080204ULL),
  Bitboard(0x4a1408800040404ULL),
  Bitboard(0x200440010c80b01ULL),
  Bitboard(0x2091080200240c02ULL),
  Bitboard(0x2482024000800101ULL),
  Bitboard(0x480002010504501ULL),
  Bitboard(0x48a2003020004582ULL),
  Bitboard(0xb02104404242282ULL),
  Bitboard(0x200421020445a22ULL),
  Bitboard(0x341006000801280eULL),
  Bitboard(0x2010c0200045096ULL),
  Bitboard(0x204210000200a81ULL),
  Bitboard(0x4800408200000101ULL),
  Bitboard(0x3804020048400880ULL),
  Bitboard(0x40412c020204009ULL),
  Bitboard(0x1004028209012095ULL),
  Bitboard(0x300082440032010ULL),
  Bitboard(0x100049040202a01ULL),
  Bitboard(0x40020008030144ULL),
  Bitboard(0x820204002812002ULL),
  Bitboard(0x42040403408040bULL),
  Bitboard(0x40402901841062ULL),
  Bitboard(0x2002101400004805ULL),
  Bitboard(0x10101200020064ULL),
  Bitboard(0x20201000802c82ULL),
  Bitboard(0x4600480010010042ULL),
  Bitboard(0xa000c10101082ULL),
  Bitboard(0x441003400800803ULL),
  Bitboard(0x4010200406903ULL),
  Bitboard(0xc0204020862801ULL),
  Bitboard(0xc8202012480204fULL),
  Bitboard(0x90410004422001ULL),
  Bitboard(0x2012005008444aULL),
  Bitboard(0x104004000004c0aULL),
  Bitboard(0x508200822045489ULL),
  Bitboard(0x922010100400c05ULL),
  Bitboard(0x2800040010000c1ULL),
  Bitboard(0x180136100001045ULL),
  Bitboard(0x50208101010040ULL),
  Bitboard(0x3092100a00502042ULL),
  Bitboard(0x4010002100040409ULL),
  Bitboard(0x1210040700490408ULL),
  Bitboard(0x844108101400803ULL),
  Bitboard(0x105240010c1200c5ULL),
  Bitboard(0x4010244701080481ULL)
};
#endif

#ifdef _64BIT
//my original tables for bishops
const CACHE_ALIGN unsigned Attacks::b_shift[64]=
{
	58, 59, 59, 59, 59, 59, 59, 58,
	59, 59, 59, 59, 59, 59, 59, 59,
	59, 59, 57, 57, 57, 57, 59, 59,
	59, 59, 57, 55, 55, 57, 59, 59,
	59, 59, 57, 55, 55, 57, 59, 59,
	59, 59, 57, 57, 57, 57, 59, 59,
	59, 59, 59, 59, 59, 59, 59, 59,
	58, 59, 59, 59, 59, 59, 59, 58
};
const Bitboard Attacks::b_magic[64]=
{
	Bitboard(0x0002020202020200ULL), Bitboard(0x0002020202020000ULL), Bitboard(0x0004010202000000ULL), Bitboard(0x0004040080000000ULL),
	Bitboard(0x0001104000000000ULL), Bitboard(0x0000821040000000ULL), Bitboard(0x0000410410400000ULL), Bitboard(0x0000104104104000ULL),
	Bitboard(0x0000040404040400ULL), Bitboard(0x0000020202020200ULL), Bitboard(0x0000040102020000ULL), Bitboard(0x0000040400800000ULL),
	Bitboard(0x0000011040000000ULL), Bitboard(0x0000008210400000ULL), Bitboard(0x0000004104104000ULL), Bitboard(0x0000002082082000ULL),
	Bitboard(0x0004000808080800ULL), Bitboard(0x0002000404040400ULL), Bitboard(0x0001000202020200ULL), Bitboard(0x0000800802004000ULL),
	Bitboard(0x0000800400A00000ULL), Bitboard(0x0000200100884000ULL), Bitboard(0x0000400082082000ULL), Bitboard(0x0000200041041000ULL),
	Bitboard(0x0002080010101000ULL), Bitboard(0x0001040008080800ULL), Bitboard(0x0000208004010400ULL), Bitboard(0x0000404004010200ULL),
	Bitboard(0x0000840000802000ULL), Bitboard(0x0000404002011000ULL), Bitboard(0x0000808001041000ULL), Bitboard(0x0000404000820800ULL),
	Bitboard(0x0001041000202000ULL), Bitboard(0x0000820800101000ULL), Bitboard(0x0000104400080800ULL), Bitboard(0x0000020080080080ULL),
	Bitboard(0x0000404040040100ULL), Bitboard(0x0000808100020100ULL), Bitboard(0x0001010100020800ULL), Bitboard(0x0000808080010400ULL),
	Bitboard(0x0000820820004000ULL), Bitboard(0x0000410410002000ULL), Bitboard(0x0000082088001000ULL), Bitboard(0x0000002011000800ULL),
	Bitboard(0x0000080100400400ULL), Bitboard(0x0001010101000200ULL), Bitboard(0x0002020202000400ULL), Bitboard(0x0001010101000200ULL),
	Bitboard(0x0000410410400000ULL), Bitboard(0x0000208208200000ULL), Bitboard(0x0000002084100000ULL), Bitboard(0x0000000020880000ULL),
	Bitboard(0x0000001002020000ULL), Bitboard(0x0000040408020000ULL), Bitboard(0x0004040404040000ULL), Bitboard(0x0002020202020000ULL),
	Bitboard(0x0000104104104000ULL), Bitboard(0x0000002082082000ULL), Bitboard(0x0000000020841000ULL), Bitboard(0x0000000000208800ULL),
	Bitboard(0x0000000010020200ULL), Bitboard(0x0000000404080200ULL), Bitboard(0x0000040404040400ULL), Bitboard(0x0002020202020200ULL)
};
#else // 32 bit
const CACHE_ALIGN unsigned Attacks::b_shift[64] = {
26, 27, 27, 27, 27, 27, 27, 26, 
27, 27, 27, 27, 27, 27, 27, 27, 
27, 27, 25, 25, 25, 25, 27, 27, 
27, 27, 25, 23, 23, 25, 27, 27, 
27, 27, 25, 23, 23, 25, 27, 27, 
27, 27, 25, 25, 25, 25, 27, 27, 
27, 27, 27, 27, 27, 27, 27, 27, 
26, 27, 27, 27, 27, 27, 27, 26
};
const CACHE_ALIGN Bitboard Attacks::b_magic[64]=
{
  Bitboard(0x41084004c2022eULL),
  Bitboard(0x101410160023014ULL),
  Bitboard(0x221010004900312ULL),
  Bitboard(0x1000061800080e89ULL),
  Bitboard(0x43110020460610ULL),
  Bitboard(0x4001110000110482ULL),
  Bitboard(0x610141004042402ULL),
  Bitboard(0x1028440020011255ULL),
  Bitboard(0x80a00c000031223ULL),
  Bitboard(0x104770010000803ULL),
  Bitboard(0x500286160204314ULL),
  Bitboard(0x88000508411904ULL),
  Bitboard(0x900000230001112ULL),
  Bitboard(0x61d8480c01000481ULL),
  Bitboard(0x8200c8200900086ULL),
  Bitboard(0x811041400840082ULL),
  Bitboard(0x2444008100220240ULL),
  Bitboard(0x40800c0400a0930ULL),
  Bitboard(0x20410008102c56ULL),
  Bitboard(0x108200000014198ULL),
  Bitboard(0x1018002004852614ULL),
  Bitboard(0x4200a0440002c01ULL),
  Bitboard(0x9004d502420081ULL),
  Bitboard(0x4405440000082125ULL),
  Bitboard(0x2882522024201010ULL),
  Bitboard(0x600801c008014840ULL),
  Bitboard(0x3000208010414400ULL),
  Bitboard(0xc00420000120820ULL),
  Bitboard(0x10402100101100ULL),
  Bitboard(0x3d90100100055441ULL),
  Bitboard(0x612110000412480ULL),
  Bitboard(0x41404c1000210a00ULL),
  Bitboard(0x9cb022304021090ULL),
  Bitboard(0x1010420420085128ULL),
  Bitboard(0x631014018001406ULL),
  Bitboard(0x20220000002858ULL),
  Bitboard(0x9a0101000084254ULL),
  Bitboard(0x1081008014022442ULL),
  Bitboard(0x124441400162081ULL),
  Bitboard(0x58c300880101ULL),
  Bitboard(0x6000649400021220ULL),
  Bitboard(0x2082160000405202ULL),
  Bitboard(0x2040148400020101ULL),
  Bitboard(0xc08008004230094ULL),
  Bitboard(0x3400118000c00181ULL),
  Bitboard(0xa0018c005040488ULL),
  Bitboard(0x5040610001a00204ULL),
  Bitboard(0x530008008502106ULL),
  Bitboard(0x100800bc24004210ULL),
  Bitboard(0x4224040109842104ULL),
  Bitboard(0x91080001110042ULL),
  Bitboard(0x8484200100a0901ULL),
  Bitboard(0x242000d10002012ULL),
  Bitboard(0x4a0a040004024518ULL),
  Bitboard(0x881040a10404508ULL),
  Bitboard(0x143140008080648ULL),
  Bitboard(0x8228000482008aULL),
  Bitboard(0x4822000400a18a2ULL),
  Bitboard(0x8411002a601026ULL),
  Bitboard(0x2084042000021508ULL),
  Bitboard(0x1052020260021049ULL),
  Bitboard(0x1004012012045040ULL),
  Bitboard(0x1c2950c200001220ULL),
  Bitboard(0x820423001200484ULL)
};
#endif

CACHE_ALIGN Attacks::MagicData Attacks::bishopMagicData[64];
CACHE_ALIGN Attacks::MagicData Attacks::rookMagicData[64];

CACHE_ALIGN Bitboard Attacks::magicmovesbdb[5248];
CACHE_ALIGN Bitboard Attacks::magicmovesrdb[102400];

struct MoveInfo {
    int dir;
    Bitboard edges;
};

static const MoveInfo ROOK_INFO[4] = {
    {1,Bitboard(0x8080808080808080ULL)},
    {-1,Bitboard(0x101010101010101ULL)},
    {8,Bitboard(0xff00000000000000ULL)},
    {-8,Bitboard(0xffULL)}};

static const MoveInfo BISHOP_INFO[4] = {
    {7,Bitboard(0xff01010101010101ULL)},
    {-7,Bitboard(0x80808080808080ffULL)},
    {9,Bitboard(0xff80808080808080ULL)},
    {-9,Bitboard(0x1010101010101ffULL)}};

static Bitboard generateSlidingMoves(Square sq, const Bitboard &occ,
                                     const MoveInfo * const limits,
                                     bool excludeEdge = false) {
    Bitboard moves;
    for (int i = 0; i < 4; i++) {
        const int dir = limits[i].dir;
        Square dest = sq;
        Bitboard limit(occ | limits[i].edges);
        if (!limits[i].edges.isSet(dest)) {
            do {
                dest += dir;
                ASSERT(OnBoard(dest));
                if (!excludeEdge || 
                    !limits[i].edges.isSet(dest)) moves.set(dest);
            } while (!limit.isSet(dest));
        }
    }
    return moves;
}

static Bitboard generateMask(Square sq, const MoveInfo *limits) {
    return generateSlidingMoves(sq,Bitboard(0),limits,true);
}

// Generate possible Rook moves from "sq" given board occupancy "occ"
static Bitboard generateRookMoves(Square sq, const Bitboard &occ) {
    return generateSlidingMoves(sq,occ,ROOK_INFO);
}

// Generate possible Rook moves excluding edges
static Bitboard generateRookMask(Square sq) {
    return generateMask(sq,ROOK_INFO);
}

// Generate possible Bishop moves from "sq" given board occupancy "occ"
static Bitboard generateBishopMoves(Square sq, const Bitboard &occ) {
    return generateSlidingMoves(sq,occ,BISHOP_INFO);
}

// Generate possible Bishop moves excluding edges
static Bitboard generateBishopMask(Square sq) {
    return generateMask(sq,BISHOP_INFO);
}

// Select, out of the set of n (generaly non-contiguous) bits in "squares",
// that subset that have their corresponding (0..n-1) bit set in "index".
static Bitboard generateOccupancy(const Bitboard &squares, const Bitboard &index) {
    Bitboard tmp(squares);
    Square sq;
    Bitboard occ;
    int n = 0;
    while (tmp.iterate(sq)) {
        if (index.isSet(n)) occ.set(sq);
        n++;
    }
    return occ;
}

void Attacks::initMagicData() {
    int b_index = 0;
    Square sq;
    Bitboard edges;
    Bitboard all_edges(file_mask[0] | file_mask[7] | rank_mask[7] | file_mask[7]);
    edges = file_mask[0] | file_mask[7] | rank_mask[0] | rank_mask[7];
    for(sq=0;sq<64;sq++)  {
        // This is the set of possible squares reachable by a Bishop
        // on "sq":
        const Bitboard mask(generateBishopMask(sq));
        int numSquares = mask.bitCount();
        bishopMagicData[sq].moves = magicmovesbdb+b_index;
        bishopMagicData[sq].shift = b_shift[sq];
        bishopMagicData[sq].mask = mask;
        bishopMagicData[sq].magic = b_magic[sq];
        // iterate through each possible combination of squares 
        // that can be occupied and generate the attacks.
        for (uint64 occBits = 0; occBits < (1ULL)<<numSquares; occBits++) {
            Bitboard occ = generateOccupancy(mask,occBits);
            setBishopAttacks(sq,occ,generateBishopMoves(sq,occ));
            b_index++;
        }
        /**
           #ifdef _64BIT
           b_index += 1<<(64-b_shift[i]);
           #else
           b_index += 1<<(32-b_shift[i]);
           #endif
        **/
        if (b_index > 5248) cout << "error" << endl;
    }
    int r_index = 0;
    for (sq=0; sq < 64; sq++) {
        // This is the set of possible squares reachable by a Rook
        // on "sq":
        const Bitboard mask(generateRookMask(sq));
        int numSquares = mask.bitCount();
        rookMagicData[sq].moves = magicmovesrdb+r_index;
        rookMagicData[sq].shift = r_shift[sq];
        rookMagicData[sq].mask = mask;
        rookMagicData[sq].magic = r_magic[sq];
        // iterate through each possible combination of squares 
        // that can be occupied and generate the attacks.
        for (uint64 occBits = 0; occBits < (1ULL)<<numSquares; occBits++) {
            Bitboard occ = generateOccupancy(mask,occBits);
            setRookAttacks(sq,occ,generateRookMoves(sq,occ));
            r_index++;
        }
        /**
           #ifdef _64BIT
           r_index += 1<<(64-r_shift[i]);
           #else
           r_index += 1<<(32-r_shift[i]);
           #endif
        **/
        if (r_index > 102400) cout << "error" << endl;
    }
}


void Attacks::init()
{
  for (int i = 0; i < 64; i++) {
      int j;
      for (j = 0; j < 64; j++)  {
         if (i == j) {
            directions[i][j] = 0;
            continue;
         }
         Square sq1 = i;
         Square sq2 = j;
         int offset;
         int abs = (sq2 > sq1) ? (int)sq2 - (int)sq1 : (int)sq1 - (int)sq2;
         if (File(sq1) == File(sq2))
	    offset = 8;
         else if (Rank(sq1,White) == Rank(sq2,White))
            offset = 1;
         else if (SquareColor(sq1) == SquareColor(sq2))
         {
            if (abs % 9 == 0)
	      offset = 9;
            else if (abs % 7 == 0)
	      offset = 7;
            else
            {
               directions[i][j] = 0;
               continue;
            }
         }
         else
         {
            directions[i][j] = 0;
            continue;
         }
         directions[i][j] = (sq2 > sq1) ? offset : -offset;
      }
  }
  rank7mask[White] = rank_mask[6];
  rank7mask[Black] = rank_mask[1];
  initMagicData();
}

