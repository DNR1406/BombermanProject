#include "Drawings.hpp"
#include <Arduino.h>
MI0283QT9 lcdTEST;

const uint8_t bomb[441] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 3
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY1, _____BLACK, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______RED2, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______NONE, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____BLACK, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE}; // 21

const uint8_t wick1[25] PROGMEM =
    {
        //1         2           3           4           5
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE,  // 1
        ______NONE, ______NONE, ______RED1, _____GREY1, ______RED1,  // 2
        ______NONE, _____GREY2, _____GREY1, ______RED1, ______NONE,  // 3
        _____GREY2, _____GREY1, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE}; // 5

const uint8_t wick2[25] PROGMEM =
    {
        //1         2           3           4           5
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______RED1, ______NONE, ______NONE,  // 2
        ______NONE, ______RED1, _____GREY1, ______RED1, ______NONE,  // 3
        _____GREY2, _____GREY1, ______RED1, ______RED1, ______NONE,  // 4
        ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE}; // 5

const uint8_t wick3[25] PROGMEM =
    {
        //1         2           3           4           5
        ______NONE, ______RED1, ______NONE, ______NONE, ______RED1,  // 1
        ______NONE, ______NONE, ______RED1, ______NONE, ______NONE,  // 2
        ______NONE, ______RED1, ______NONE, ______RED1, ______NONE,  // 3
        ______RED1, _____GREY1, ______RED1, ______NONE, ______NONE,  // 4
        ______NONE, ______RED1, ______NONE, ______RED1, ______RED1}; // 5

const uint8_t bombExplosion1[441] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 3
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ______RED1, ______RED1, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ___YELLOW2, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, ___YELLOW2, ___YELLOW2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ___YELLOW2, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____WHITE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, _____GREY2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, _____WHITE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____WHITE, ___YELLOW1, _____WHITE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______NONE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, _____GREY2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____WHITE, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, _____GREY2, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, ___YELLOW2, ___YELLOW2, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, _____WHITE, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, _____GREY2, _____GREY2, ___YELLOW2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, _____GREY2, _____GREY2, ______RED1, ______RED1, _____GREY2, _____GREY2, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE}; // 21

const uint8_t bombExplosion2[588] PROGMEM =
    {
        //1         2           3           4           5          6            7           8           9           10          11    *     12          13          14          15   *      16          17          18          19          20          21
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 1
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 2
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE,  // 3
        ______NONE, ______NONE, _____GREY2, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 4
        ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW1, ___YELLOW1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE,  // 5
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 6
        ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE,  // 7
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 8
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 9
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 10
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW1, ______RED1, ___YELLOW2, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 11
        ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 12
        ______NONE, ______NONE, ______NONE, ______RED1, _____GREY2, ______RED1, ___YELLOW1, ___YELLOW1, ______RED1, ______RED1, ___YELLOW2, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 13
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 14
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ______RED1, ______RED1, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 15
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW1, ______RED1, ______RED1, ______RED1, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 16
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ___YELLOW1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 17
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW2, ___YELLOW1, ___YELLOW1, ___YELLOW1, ___YELLOW2, _____GREY2, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 18
        ______NONE, ______RED1, ______NONE, ______RED1, ______RED1, ______RED1, ___YELLOW1, ______RED1, ______RED1, ______RED1, ___YELLOW2, ___YELLOW2, ___YELLOW1, ______RED1, _____GREY2, ______RED1, ______RED1, ______RED1, ______NONE, ______RED1, ______NONE,  // 19
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, _____GREY2, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, ______RED1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 20
        ______NONE, ______NONE, ______NONE, ______RED1, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ___YELLOW2, ___YELLOW1, ___YELLOW2, ___YELLOW1, ______RED1, ___YELLOW1, _____GREY2, ___YELLOW1, ______RED1, ______RED1, ______NONE, ______NONE, ______NONE,  // 21
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW1, ___YELLOW2, ___YELLOW2, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, _____GREY2, _____GREY2, _____GREY2, ______RED1, ______NONE, ______NONE, ______NONE,  // 22
        ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW2, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ______NONE, ______NONE, ______NONE,  // 23
        ______NONE, ______NONE, ______NONE, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______RED1, ___YELLOW1, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 24
        ______NONE, ______NONE, ______NONE, ___YELLOW1, ___YELLOW2, ______RED1, ___YELLOW1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ___YELLOW2, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 25
        ______NONE, ______NONE, ______NONE, ___YELLOW2, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ___YELLOW2, ______NONE, ______NONE, ______NONE,  // 26
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE,  // 27
        ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______NONE, ______RED1, ______NONE, ______NONE, ______NONE}; //28

void drawBombAdSCreen(uint16_t x, uint16_t y)
{
    uint16_t number = 0;

    for (uint8_t i = 0; i < 21; i++)
    {
        for (uint8_t j = 0; j < 21; j++)
        {
            uint8_t draw = ((pgm_read_word_near(bomb + number) & 192) >> 7);

            if (draw)
            {
                uint8_t red = (((pgm_read_word_near(bomb + number) & 48) >> 4));
                red *= 85;
                uint8_t green = (((pgm_read_word_near(bomb + number) & 12) >> 2));
                green *= 85;
                uint8_t blue = ((pgm_read_word_near(bomb + number) & 3));
                blue *= 85;

                lcdTEST.drawPixel(x, y, RGB(red, green, blue));
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
    x = 21 * x + 121;
    y = 21 * y + 29;

    uint16_t number = 0, numberOld = 73, counter = 0;

    for (uint8_t i = 0; i < 5; i++)
    {
        for (uint8_t j = 0; j < 5; j++)
        {
            if ((bombTime > 15000) && (bombTime < 20000))
            {
                uint8_t draw = ((pgm_read_word_near(wick1 + number) & 192) >> 7);
                if (draw)
                {
                    lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(wick1 + number) & 48) >> 4) * 85), (((pgm_read_word_near(wick1 + number) & 12) >> 2) * 85), ((pgm_read_word_near(wick1 + number) & 3) * 85)));
                }
                else
                {
                    if (pgm_read_word_near(bomb + numberOld) != ______NONE)
                    {
                        lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(bomb + numberOld) & 48) >> 4) * 85), (((pgm_read_word_near(bomb + numberOld) & 12) >> 2) * 85), ((pgm_read_word_near(bomb + numberOld) & 3) * 85)));
                    }
                    else
                    {
                        lcdTEST.drawPixel(x, y, RGB(29, 79, 22));
                    }
                }
            }
            else if ((bombTime > 10000) && (bombTime < 15000))
            {
                uint8_t draw = ((pgm_read_word_near(wick2 + number) & 192) >> 7);
                if (draw)
                {
                    lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(wick2 + number) & 48) >> 4) * 85), (((pgm_read_word_near(wick2 + number) & 12) >> 2) * 85), ((pgm_read_word_near(wick2 + number) & 3) * 85)));
                }
                else
                {
                    if (pgm_read_word_near(bomb + numberOld) != ______NONE)
                    {
                        lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(bomb + numberOld) & 48) >> 4) * 85), (((pgm_read_word_near(bomb + numberOld) & 12) >> 2) * 85), ((pgm_read_word_near(bomb + numberOld) & 3) * 85)));
                    }
                    else
                    {
                        lcdTEST.drawPixel(x, y, RGB(29, 79, 22));
                    }
                }
            }
            else if ((bombTime > 5000) && (bombTime < 10000))
            {
                uint8_t draw = ((pgm_read_word_near(wick3 + number) & 192) >> 7);
                if (draw)
                {
                    lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(wick3 + number) & 48) >> 4) * 85), (((pgm_read_word_near(wick3 + number) & 12) >> 2) * 85), ((pgm_read_word_near(wick3 + number) & 3) * 85)));
                }
                else
                {
                    counter++;
                    if (pgm_read_word_near(bomb + numberOld) != ______NONE)
                    {
                        lcdTEST.drawPixel(x, y, RGB((((pgm_read_word_near(bomb + numberOld) & 48) >> 4) * 85), (((pgm_read_word_near(bomb + numberOld) & 12) >> 2) * 85), ((pgm_read_word_near(bomb + numberOld) & 3) * 85)));
                    }
                    else
                    {
                        lcdTEST.drawPixel(x, y, RGB(29, 79, 22));
                    }
                }
            }

            numberOld++;
            number++;
            x++;
        }

        numberOld += 16;
        y++;
        x -= 5;
    }
}

void deleteBombFromScreen(uint16_t x, uint16_t y, uint8_t barrels[9][9])
{
    uint16_t number = 0;

    uint16_t xforDraw = 110 + (x * 21);
    uint16_t yforDraw = 25 + (y * 21);

    for (uint8_t i = 0; i < 21; i++)
    {
        for (uint8_t j = 0; j < 21; j++)
        {
            uint8_t draw = ((pgm_read_word_near(bombExplosion1 + number) & 192) >> 7);

            if (draw)
            {
                lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
            }

            number++;
            xforDraw++;
        }
        yforDraw++;
        xforDraw -= 21;
    }

    // First above
    if ((barrels[x][y - 1] != 2) && (y != 0))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 1) + 34;

        number = 0;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number++;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // Second above
    if ((barrels[x][y - 1] != 2) && (y != 0) && ((y - 1) != 0))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 2) + 34;
        number = 0;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number++;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // First under
    if ((barrels[x][y + 1] != 2) && (y != 8))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 1) + 16;
        number = 587;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number--;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }
    // Second under
    if ((barrels[x][y + 1] != 2) && (y != 8) && ((y + 1) != 8))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 2) + 16;
        number = 587;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number--;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // One left
    if ((barrels[x - 1][y] != 2) && (x != 0))
    {
        xforDraw = 21 * (x - 1) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number += 21;
                xforDraw++;
            }
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x - 1][y] != 2) && (x != 0) && ((x - 1) != 0))
    {
        xforDraw = 21 * (x - 2) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number += 21;
                xforDraw++;
            }
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // One right
    if ((barrels[x + 1][y] != 2) && (x != 8))
    {
        xforDraw = 21 * (x + 1) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number -= 21;
                xforDraw++;
            }
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second right
    if ((barrels[x + 1][y] != 2) && (x != 8) && ((x + 1) != 8))
    {
        xforDraw = 21 * (x + 2) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(29, 79, 22));
                }

                number -= 21;
                xforDraw++;
            }
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }
}

void explodeBomb(uint16_t x, uint16_t y, uint32_t bombTime, uint8_t barrels[9][9])
{
    uint16_t xforDraw = 21 * x + 110;
    uint16_t yforDraw = 21 * y + 26;

    uint16_t number = 0;

    for (uint8_t i = 0; i < 21; i++)
    {
        for (uint8_t j = 0; j < 21; j++)
        {
            uint8_t draw = ((pgm_read_word_near(bombExplosion1 + number) & 192) >> 7);

            if (draw)
            {
                uint8_t red = (((pgm_read_word_near(bombExplosion1 + number) & 48) >> 4));
                red *= 85;
                uint8_t green = (((pgm_read_word_near(bombExplosion1 + number) & 12) >> 2));
                green *= 85;
                uint8_t blue = ((pgm_read_word_near(bombExplosion1 + number) & 3));
                blue *= 85;

                lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
            }

            number++;
            xforDraw++;
        }
        yforDraw++;
        xforDraw -= 21;
    }

    // First above
    if ((barrels[x][y - 1] != 2) && (y != 0))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 1) + 34;

        number = 0;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number++;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // Second above
    if ((barrels[x][y - 1] != 2) && (y != 0) && ((y - 1) != 0))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y - 2) + 34;
        number = 0;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number++;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // First under
    if ((barrels[x][y + 1] != 2) && (y != 8))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 1) + 16;
        number = 587;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number--;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }
    // Second under
    if ((barrels[x][y + 1] != 2) && (y != 8) && ((y + 1) != 8))
    {
        xforDraw = 21 * x + 110;
        yforDraw = 21 * (y + 2) + 16;
        number = 587;
        for (uint8_t i = 0; i < 28; i++)
        {
            for (uint8_t j = 0; j < 21; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number--;
                xforDraw++;
            }
            yforDraw++;
            xforDraw -= 21;
        }
    }

    // One left
    if ((barrels[x - 1][y] != 2) && (x != 0))
    {
        xforDraw = 21 * (x - 1) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number += 21;
                xforDraw++;
            }
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x - 1][y] != 2) && (x != 0) && ((x - 1) != 0))
    {
        xforDraw = 21 * (x - 2) + 118;
        yforDraw = 21 * y + 26;

        number = 20;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number += 21;
                xforDraw++;
            }
            number -= 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // One right
    if ((barrels[x + 1][y] != 2) && (x != 8))
    {
        xforDraw = 21 * (x + 1) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number -= 21;
                xforDraw++;
            }
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }

    // Second left
    if ((barrels[x + 1][y] != 2) && (x != 8) && ((x + 1) != 8))
    {
        xforDraw = 21 * (x + 2) + 102;
        yforDraw = 21 * y + 26;

        number = 567;
        for (uint8_t i = 0; i < 21; i++)
        {
            for (uint8_t j = 0; j < 28; j++)
            {
                uint8_t draw = ((pgm_read_word_near(bombExplosion2 + number) & 192) >> 7);

                if (draw)
                {
                    uint8_t red = (((pgm_read_word_near(bombExplosion2 + number) & 48) >> 4));
                    red *= 85;
                    uint8_t green = (((pgm_read_word_near(bombExplosion2 + number) & 12) >> 2));
                    green *= 85;
                    uint8_t blue = ((pgm_read_word_near(bombExplosion2 + number) & 3));
                    blue *= 85;

                    lcdTEST.drawPixel(xforDraw, yforDraw, RGB(red, green, blue));
                }

                number -= 21;
                xforDraw++;
            }
            number += 589;
            yforDraw++;
            xforDraw -= 28;
        }
    }
}
