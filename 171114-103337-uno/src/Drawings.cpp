#include "Drawings.hpp"
MI0283QT9 lcd;

//Bitmap for bomb
const uint8_t bomb[441] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 3
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY1, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______RED2, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE}; // 21

//Bitmap for wick long wick
const uint8_t wick1[25] PROGMEM =
    {
        //1         2           3           4           5
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE,  // 1
        ______NONE, ______NONE, ______RED1, _____GREY1, ______RED1,  // 2
        ______NONE, _____GREY2, _____GREY1, _____GREY1, ______NONE,  // 3
        _____GREY2, _____GREY1, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE}; // 5

//Bitmap for wick shorter wick
const uint8_t wick2[25] PROGMEM =
    {
        //1         2           3           4           5
        ______RED1, ______RED1, ______NONE, ______RED1, ______RED1,  // 1
        ______NONE, ______NONE, ______RED1, ______NONE, ______NONE,  // 2
        ______NONE, ______RED1, _____GREY1, ______RED1, ______RED1,  // 3
        _____GREY2, _____GREY1, ______RED1, ______RED1, ______NONE,  // 4
        ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE}; // 5

//Bitmap for if bomb is exploding
const uint8_t bombExplosion1[441] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 3
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ______RED1, ______RED1, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ___YELLOW2, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, ___YELLOW2, ___YELLOW2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ___YELLOW2, _____WHITE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____WHITE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, _____GREY2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ______RED1, _____WHITE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, _____WHITE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, ___YELLOW2, _____WHITE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____WHITE, ___YELLOW1, _____WHITE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______NONE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, _____GREY2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, _____WHITE, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ___YELLOW2, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, _____WHITE, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, _____GREY2, _____GREY2, ___YELLOW2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ______RED1, ______RED1, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE}; // 21

//Bitmap for if bomb is exploding on the sides
const uint8_t bombExplosion2[588] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE,  // 3
        ______NONE, ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW1, ___YELLOW1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ______RED1, ___YELLOW2, _____GREY2, ______RED1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, ______RED1, _____GREY2, ______RED1, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ___YELLOW2, _____GREY2, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ___YELLOW2, ___YELLOW1, ______RED1, ______RED1, ______RED1, _____GREY2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ___YELLOW1, ___YELLOW2, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______RED1, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ___YELLOW2, ___YELLOW2, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______RED1, ______NONE, ______NONE, ______RED1, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, _____GREY2, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ___YELLOW2, ___YELLOW1, ___YELLOW2, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ___YELLOW1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 21
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, _____GREY2, ______RED1, ______NONE, ______NONE, ______NONE,  // 22
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ______NONE, ______NONE, ______NONE,  // 23
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 24
        ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 25
        ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 26
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE,  // 27
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE}; //28

// Front, walking upwards
const uint8_t player3[294] PROGMEM = {
    ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, 0b10000000, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10000000, ______NONE,
    ______NONE, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, 0b10110001, 0b10111000, 0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110001, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, 0b10110001, 0b10111000, 0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110001, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, 0b10110001, 0b10111000, 0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110001, _____WHITE, 0b10101010,
    ______NONE, 0b10000000, _____WHITE, _____WHITE, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, _____WHITE, 0b10101010, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10000000, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, 0b10000000, _____WHITE, 0b10000111, 0b10001011, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000111, ______NONE, 0b10000000, ______NONE,
    ______NONE, 0b10000000, ______NONE, 0b10000000, 0b10000111, _____WHITE, 0b10011111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000000, ______NONE, 0b10000000,
    0b10000000, 0b10110001, 0b10110001, 0b10000000, 0b10000000, 0b10000000, 0b10111000, 0b10111000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10110001,
    0b10000000, 0b10110001, 0b10100000, 0b10000000, 0b10000111, 0b10011111, 0b10011111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000000, 0b10110001, 0b10100000,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000111, 0b10000111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000111, 0b10000000, 0b10000000, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, _____WHITE, _____WHITE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, 0b10000000, 0b10000000, ______NONE,
    ______NONE, 0b10000000, 0b10000000, 0b10100000, 0b10111011, 0b10110001, 0b10000000, 0b10000000, 0b10100000, 0b10111011, 0b10110001, 0b10100000, 0b10000000, 0b10000000,
    ______NONE, 0b10000000, 0b10100000, 0b10111011, 0b10110001, 0b10110001, 0b10000000, 0b10000000, 0b10100000, 0b10110001, 0b10110001, 0b10100000, 0b10100000, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE};

// Back, walking downwards
const uint8_t player1[294] PROGMEM = {
    ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10110001, 0b10100000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10100000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10000000, ______NONE,
    ______NONE, ______NONE, _____WHITE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, 0b10000000, _____WHITE, 0b10000111, 0b10001011, 0b10011111, 0b10001011, 0b10000111, 0b10000111, 0b10000111, _____WHITE, 0b10000000, ______NONE,
    ______NONE, 0b10000000, _____WHITE, 0b10000000, 0b10000111, _____WHITE, 0b10011111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000000, _____WHITE, 0b10000000,
    0b10000000, 0b10110001, 0b10110001, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10110001,
    0b10000000, 0b10110001, 0b10100000, 0b10000000, 0b10000111, 0b10011111, 0b10011111, 0b10011111, 0b10001011, 0b10000111, 0b10000111, 0b10000000, 0b10110001, 0b10100000,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000111, 0b10000111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000111, 0b10000000, 0b10000000, 0b10000000,
    ______NONE, _____WHITE, 0b10000000, 0b10000000, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10101010, _____WHITE, _____WHITE, 0b10000000, 0b10000000, ______NONE,
    ______NONE, 0b10000000, 0b10000000, 0b10100000, 0b10110001, 0b10110001, 0b10100000, 0b10000000, 0b10100000, 0b10110001, 0b10110001, 0b10100000, 0b10000000, 0b10000000,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10100000, 0b10110001, 0b10100000, 0b10000000, 0b10100000, 0b10110001, 0b10100000, 0b10000000, 0b10000000, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE};

// Left
const uint8_t player4[294] PROGMEM = {
    ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10111011, 0b10110001, 0b10100000, 0b10000000,
    ______NONE, ______NONE, _____WHITE, _____WHITE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10100000, 0b10100000, 0b10000000,
    ______NONE, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, ______NONE,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10110001, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10111000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10111000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, 0b10111000, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10111000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, _____WHITE, 0b10000000, 0b10000111, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, 0b10000000, 0b10111011, 0b10110001, 0b10100000, 0b10000000, 0b10000111, 0b10000111, 0b10000111, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, 0b10000000, 0b10110001, 0b10110001, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000111, 0b10000111, 0b10000111, 0b10000111, 0b10000000, ______NONE, ______NONE, ______NONE,
    0b10000000, 0b10100000, 0b10000000, 0b10000000, 0b10000111, 0b10001011, 0b10001011, 0b10000111, 0b10000111, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, 0b10000000, 0b10100000, 0b10100000, 0b10100000, 0b10000000, 0b10000000, _____WHITE, 0b10100000, 0b10100000, 0b10000000, 0b10000000, 0b10000000, ______NONE,
    ______NONE, 0b10000000, 0b10000000, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10110001, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10000000,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE};

// Right
const uint8_t player2[294] PROGMEM = {
    ______NONE, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,
    0b10000000, 0b10111011, 0b10110001, 0b10100000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,
    0b10000000, 0b10100000, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE, ______NONE,
    ______NONE, 0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, ______NONE,
    0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10110001, 0b10110001, 0b10110001, 0b10110001, 0b10100000, 0b10100000, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110100, 0b10110100, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110100, 0b10110100, 0b10000000,
    0b10000000, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110100, 0b10110100, 0b10000000,
    0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10111000, 0b10111000, 0b10000000, 0b10111000, 0b10110100, 0b10110100, 0b10000000,
    ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10101010, _____WHITE, _____WHITE, _____WHITE, _____WHITE, 0b10101010, 0b10000000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10001011, 0b10000000, _____WHITE, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10001011, _____WHITE, 0b10011111, 0b10000000, 0b10111011, 0b10110001, 0b10100000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10110001, 0b10100000, 0b10000000, ______NONE, ______NONE,
    ______NONE, ______NONE, ______NONE, 0b10000000, 0b10001011, 0b10011111, 0b10001011, 0b10000111, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE,
    ______NONE, ______NONE, ______NONE, ______NONE, 0b10000000, 0b10000111, 0b10001011, 0b10000111, 0b10000111, 0b10000111, 0b10000000, 0b10000000, 0b10100000, 0b10000000,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10111011, 0b10110001, _____WHITE, 0b10000000, 0b10000000, 0b10100000, 0b10100000, 0b10100000, 0b10000000, ______NONE,
    0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10110001, 0b10110001, 0b10110001, 0b10000000, 0b10000000, 0b10000000, 0b10100000, 0b10000000, 0b10000000, ______NONE,
    0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10100000, 0b10100000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE,
    ______NONE, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, ______NONE, ______NONE};

//Void to draw player, if map is zero, it is drawed in the map, else on the x, y location
void drawPlayer(uint16_t x, uint16_t y, uint8_t side, uint8_t player, uint8_t map)
{

    if (map)
    {
        drawPlayerOnScreen((21 * x + 110), (21 * y + 25), side, player);
    }
    else
    {
        drawPlayerOnScreen(x, y, side, player);
    }
}

// Void to draw player
void drawPlayerOnScreen(uint16_t xForDraw, uint16_t yforDraw, uint8_t side, uint8_t player)
{

    //Number to remember which pixel to draw
    uint16_t number = 0;
    xForDraw += 3;

    // Colors
    uint8_t red = 0, green = 0, blue = 0;

    // Loop trough y
    for (uint8_t i = 0; i < 21; i++)
    {
        // Loop trough x
        for (uint8_t j = 3; j < 17; j++)
        {

            // If player is walking left
            if (side == 4)
            {

                // Check for pixel to draw
                uint8_t draw = ((pgm_read_word_near(player4 + number) & 192) >> 7);
                if (draw)
                {
                    // RGB values
                    red = (((pgm_read_word_near(player4 + number) & 48) >> 4));
                    red *= 85;
                    green = (((pgm_read_word_near(player4 + number) & 12) >> 2));
                    green *= 85;
                    blue = ((pgm_read_word_near(player4 + number) & 3));
                    blue *= 85;

                    // Check which player to draw
                    if (player == 1)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(red, green, blue));
                    }
                    else if (player == 2)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(green, blue, red));
                    }
                }
            }

            // If player walkes downwards
            else if (side == 3)
            {
                // CHeck if player must be drawed
                uint8_t draw = ((pgm_read_word_near(player3 + number) & 192) >> 7);
                if (draw)
                {
                    // RGB values
                    red = (((pgm_read_word_near(player3 + number) & 48) >> 4));
                    red *= 85;
                    green = (((pgm_read_word_near(player3 + number) & 12) >> 2));
                    green *= 85;
                    blue = ((pgm_read_word_near(player3 + number) & 3));
                    blue *= 85;

                    // Check which player needs to draw
                    if (player == 1)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(red, green, blue));
                    }
                    else if (player == 2)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(green, blue, red));
                    }
                }
            }
            // If player walkes to the right
            else if (side == 2)
            {
                // Check if pixel needs to draw
                uint8_t draw = ((pgm_read_word_near(player2 + number) & 192) >> 7);
                if (draw)
                {
                    // RGB values
                    red = (((pgm_read_word_near(player2 + number) & 48) >> 4));
                    red *= 85;
                    green = (((pgm_read_word_near(player2 + number) & 12) >> 2));
                    green *= 85;
                    blue = ((pgm_read_word_near(player2 + number) & 3));
                    blue *= 85;

                    // Check which player needs to draw
                    if (player == 1)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(red, green, blue));
                    }
                    else if (player == 2)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(green, blue, red));
                    }
                }
            }
            // If player walkes upwards
            else
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(player1 + number) & 192) >> 7);
                if (draw)
                {
                    // RGB
                    red = (((pgm_read_word_near(player1 + number) & 48) >> 4));
                    red *= 85;
                    green = (((pgm_read_word_near(player1 + number) & 12) >> 2));
                    green *= 85;
                    blue = ((pgm_read_word_near(player1 + number) & 3));
                    blue *= 85;
                    // Check which player
                    if (player == 1)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(red, green, blue));
                    }
                    else if (player == 2)
                    {
                        lcd.drawPixel(xForDraw, yforDraw, RGB(green, blue, red));
                    }
                }
            }
            // New pixel to draw, new x location to draw
            number++;
            xForDraw++;
        }
        // New x, y position to draw
        yforDraw++;
        xForDraw -= 14;
    }
}

// Void to delete player
void deletePlayer(uint8_t x, uint8_t y)
{
    // Convert x, y position to positions on the screen
    uint16_t xForDraw = 21 * x + 110;
    uint16_t yForDraw = 21 * y + 25;

    // Loop trough y location
    for (uint8_t i = 0; i < 21; i++)
    {
        // Loop trough x location
        for (uint8_t j = 0; j < 21; j++)
        {
            // Draw grass
            lcd.drawPixel(xForDraw, yForDraw, RGB(29, 79, 22));
            // New x location
            xForDraw++;
        }
        // New x, y location
        yForDraw++;
        xForDraw -= 21;
    }
}

// Mthod to add bomb to screen
void drawBombAdSCreen(uint16_t x, uint16_t y)
{
    // Next pixel to draw
    uint16_t number = 0;

    // Loop trough y locations
    for (uint8_t i = 0; i < 21; i++)
    {
        // Loop trough x locations
        for (uint8_t j = 0; j < 21; j++)
        {
            // CHeck if pixel needs to draw
            uint8_t draw = ((pgm_read_word_near(bomb + number) & 192) >> 7);

            if (draw)
            {
                // RGB values
                uint8_t red = (((pgm_read_word_near(bomb + number) & 48) >> 4));
                red *= 85;
                uint8_t green = (((pgm_read_word_near(bomb + number) & 12) >> 2));
                green *= 85;
                uint8_t blue = ((pgm_read_word_near(bomb + number) & 3));
                blue *= 85;

                // draw pixel
                lcd.drawPixel(x, y, RGB(red, green, blue));
            }

            number++;
            x++;
        }
        y++;
        x -= 21;
    }
}

void updateWick(uint16_t x, uint16_t y, uint32_t bombTime)
{
    // Convert to x, y location
    x = 21 * x + 121;
    y = 21 * y + 29;

    // numer is location of wick, number Old is location of bomb
    uint16_t number = 0, numberOld = 73;

    // Loop trough y locations
    for (uint8_t i = 0; i < 5; i++)
    {
        // Loop trough x locations
        for (uint8_t j = 0; j < 5; j++)
        {
            // If time is between ....
            // if ((bombTime > 15000) && (bombTime < 20000))
            if (bombTime & (1 << 11))
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(wick1 + number) & 192) >> 7);
                if (draw)
                {
                    // draw pixel and get RGB
                    lcd.drawPixel(x, y, RGB((((pgm_read_word_near(wick1 + number) & 48) >> 4) * 85), (((pgm_read_word_near(wick1 + number) & 12) >> 2) * 85), ((pgm_read_word_near(wick1 + number) & 3) * 85)));
                }
                else
                {
                    // Draw old pixel, pixel of bomb
                    if (pgm_read_word_near(bomb + numberOld) != ______NONE)
                    {
                        lcd.drawPixel(x, y, RGB((((pgm_read_word_near(bomb + numberOld) & 48) >> 4) * 85), (((pgm_read_word_near(bomb + numberOld) & 12) >> 2) * 85), ((pgm_read_word_near(bomb + numberOld) & 3) * 85)));
                    }
                    else
                    {
                        // If nothing needs to draw, draw grass
                        lcd.drawPixel(x, y, RGB(29, 79, 22));
                    }
                }
            }
            // Second bomb time, same story as first
            else
            {
                uint8_t draw = ((pgm_read_word_near(wick2 + number) & 192) >> 7);
                if (draw)
                {
                    lcd.drawPixel(x, y, RGB((((pgm_read_word_near(wick2 + number) & 48) >> 4) * 85), (((pgm_read_word_near(wick2 + number) & 12) >> 2) * 85), ((pgm_read_word_near(wick2 + number) & 3) * 85)));
                }
                else
                {
                    if (pgm_read_word_near(bomb + numberOld) != ______NONE)
                    {
                        lcd.drawPixel(x, y, RGB((((pgm_read_word_near(bomb + numberOld) & 48) >> 4) * 85), (((pgm_read_word_near(bomb + numberOld) & 12) >> 2) * 85), ((pgm_read_word_near(bomb + numberOld) & 3) * 85)));
                    }
                    else
                    {
                        lcd.drawPixel(x, y, RGB(29, 79, 22));
                    }
                }
            }

            // New pixels to draw
            numberOld++;
            number++;
            // New x location to draw
            x++;
        }

        // New pixel to draw
        numberOld += 16;
        // New x, y location
        y++;
        x -= 5;
    }
}

// Method to delete bomb from screen
void deleteBombFromScreen(uint16_t x, uint16_t y, uint8_t barrels[9][9])
{
    // Next pixel to draw, x, y locations
    uint16_t number = 0;
    uint16_t xforDraw = 110 + (x * 21);
    uint16_t yforDraw = 25 + (y * 21);

    // Y location to draw, delete Explosion
    for (uint8_t i = 0; i < 21; i++)
    {
        // X location to draw
        for (uint8_t j = 0; j < 21; j++)
        {
            // Draw pixel if nessersery
            uint8_t draw = ((pgm_read_word_near(bombExplosion1 + number) & 192) >> 7);
            if (draw)
            {
                lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
            }

            // New pixel, new x to draw
            number++;
            xforDraw++;
        }
        // New location to draw
        yforDraw++;
        xforDraw -= 21;
    }

    // First above
    if ((barrels[x][y - 1] != 2) && (y != 0))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 1) + 34;

        // Number to remember wich pixel to send next
        number = 0;
        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // CHeck to draw new pixel
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Draw grass color
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }
                // New x, new pixel
                number++;
                xforDraw++;
            }
            // New location
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // Second above
    if ((barrels[x][y - 1] != 2) && (y != 0) && ((y - 1) != 0))
    {
        // X and y location, pixel to draw
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 2) + 34;
        number = 0;
        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // CHeck for drqw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Draw grass
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                // New pixel, new x
                number++;
                xforDraw++;
            }
            // New location
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // First under
    if ((barrels[x][y + 1] != 2) && (y != 8))
    {
        // New location to draw, pixel to draw
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 1) + 16;
        number = 587;

        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Delete pixel/ Draw grass
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                // New bit, new x
                number--;
                xforDraw++;
            }
            // New locaton
            yforDraw++;
            xforDraw -= 21;
        }
    }
    // Second under
    if ((barrels[x][y + 1] != 2) && (y != 8) && ((y + 1) != 8))
    {
        // New location on screen, pixel to draw
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 2) + 16;
        number = 587;

        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Delete pixel/draw grass
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                // New pixel, new x
                number--;
                xforDraw++;
            }
            // New locations
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // One left
    if ((barrels[x - 1][y] != 2) && (x != 0))
    {
        // x and y for draw, pixel
        xforDraw = 21 * (x - 1) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        // Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                // delete pixel/ draw grass
                if (draw)
                {
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                // New pixel, new x
                number += 21;
                xforDraw++;
            }
            // New lcoation, new pixel
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x - 1][y] != 2) && (x != 0) && ((x - 1) != 0))
    {
        // x, Y ON SCReen pixel
        xforDraw = 21 * (x - 2) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        /// Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                // Draw is nessercery
                if (draw)
                {
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }
                // New pixel/new x
                number += 21;
                xforDraw++;
            }
            // New pixel, new location
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // One right
    if ((barrels[x + 1][y] != 2) && (x != 8))
    {
        // X, y location for draw, pixel
        xforDraw = 21 * (x + 1) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        // loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                // Delete pixel/draw grass
                if (draw)
                {
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                // New x, new pixel
                number -= 21;
                xforDraw++;
            }
            // New pixel, new location
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second right
    if ((barrels[x + 1][y] != 2) && (x != 8) && ((x + 1) != 8))
    {
        // X and y location, pixel
        xforDraw = 21 * (x + 2) + 102;
        yforDraw = 21 * y + 26;
        number = 567;
        // Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                // Draw pixel/ draw grass
                if (draw)
                {
                    lcd.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }
                //New pixel , new x
                number -= 21;
                xforDraw++;
            }
            // New pixel, new locatino
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }
}

// Void to draw bomb explosion
void explodeBomb(uint16_t x, uint16_t y, uint32_t bombTime, uint8_t barrels[9][9])
{
    // X, y location of explosion
    uint16_t xforDraw = 21 * x + 110;
    uint16_t yforDraw = 21 * y + 26;

    // Number for pixel
    uint16_t number = 0;

    // Loop trough y
    for (uint8_t i = 0; i < 21; i++)
    {
        // Loop trough x
        for (uint8_t j = 0; j < 21; j++)
        {
            // CHeck for draw
            uint8_t draw = ((pgm_read_word_near(bombExplosion1 + number) & 192) >> 7);

            // Draw is draw is one
            if (draw)
            {
                // Get RGB
                uint8_t red = (((pgm_read_word_near(bombExplosion1 + number) & 48) >> 4));
                red *= 85;
                uint8_t green = (((pgm_read_word_near(bombExplosion1 + number) & 12) >> 2));
                green *= 85;
                uint8_t blue = ((pgm_read_word_near(bombExplosion1 + number) & 3));
                blue *= 85;

                // Draw pixel
                lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
            }
            // New pixel, new x
            number++;
            xforDraw++;
        }
        // New location
        yforDraw++;
        xforDraw -= 21;
    }

    // First above
    if ((barrels[x][y - 1] != 2) && (y != 0))
    {
        // Get x, y position, get number for pixel
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 1) + 34;

        number = 0;
        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Get RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    // DRaw pixel
                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                // New pixel, new x
                number++;
                xforDraw++;
            }
            // New locations
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // Second above
    if ((barrels[x][y - 1] != 2) && (y != 0) && ((y - 1) != 0))
    {
        // X, Y, Number
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 2) + 34;
        number = 0;

        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough X
            for (uint8_t j = 0; j < 21; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Get RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    // Draw Pixel
                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                // New number, new x
                number++;
                xforDraw++;
            }
            // New location
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // First under
    if ((barrels[x][y + 1] != 2) && (y != 8))
    {
        // X, y position, number for pixel
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 1) + 16;
        number = 587;

        // Loop trough y
        for (uint8_t i = 0; i < 28; i++)
        {
            //Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                // NEw pixel, new x
                number--;
                xforDraw++;
            }
            // New location
            yforDraw++;
            xforDraw -= 21;
        }
    }
    // Second under
    if ((barrels[x][y + 1] != 2) && (y != 8) && ((y + 1) != 8))
    {
        // Get x, y , number for pixel to draw
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 2) + 16;
        number = 587;

        // Loop torugh y
        for (uint8_t i = 0; i < 28; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 21; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Get RGB1
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                //New pixel to draw
                number--;
                xforDraw++;
            }
            // New location
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // One left
    if ((barrels[x - 1][y] != 2) && (x != 0))
    {
        // X, y location
        xforDraw = 21 * (x - 1) + 118;
        yforDraw = 21 * y + 26;

        number = 20;

        // Loop torugh y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop troygg x
            for (uint8_t j = 0; j < 28; j++)
            {
                /// CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    // DRaw pixel
                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }
                // New pixel, new number
                number += 21;
                xforDraw++;
            }
            // New number, new location
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x - 1][y] != 2) && (x != 0) && ((x - 1) != 0))
    {
        // X, y location
        xforDraw = 21 * (x - 2) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        // Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // Get rgb
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    // DRaw pixel
                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }
                // New number new x
                number += 21;
                xforDraw++;
            }
            // New number, new x, y
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // One right
    if ((barrels[x + 1][y] != 2) && (x != 8))
    {
        // X, y for draw
        xforDraw = 21 * (x + 1) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        // Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // CHeck for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    // Draw pixel
                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                // New pixel, new x
                number -= 21;
                xforDraw++;
            }
            // New pixel, new location
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x + 1][y] != 2) && (x != 8) && ((x + 1) != 8))
    {
        // X, y for draing
        xforDraw = 21 * (x + 2) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        // Loop trough y
        for (uint8_t i = 0; i < 21; i++)
        {
            // Loop trough x
            for (uint8_t j = 0; j < 28; j++)
            {
                // Check for draw
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    // RGB
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcd.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                // New pixel, new x
                number -= 21;
                xforDraw++;
            }
            // New pixel, newlocation
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }
}
