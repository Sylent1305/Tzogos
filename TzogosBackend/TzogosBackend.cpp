#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "Player.h"
#include "Game.h"

static void initConsoleForUtf8AndAnsi() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        if (GetConsoleMode(hOut, &mode)) {
            SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        }
    }
}

static const char* COL_RED     = "\x1b[38;2;255;0;0m";      // hearts
static const char* COL_LBLUE   = "\x1b[38;2;173;216;230m";  // diamonds (light blue)
static const char* COL_LIME    = "\x1b[38;2;0;255;0m";      // clubs (lime)
static const char* COL_ORANGE  = "\x1b[38;2;255;165;0m";    // spades (orange)
static const char* COL_MAGENTA = "\x1b[38;2;255;0;255m";    // joker
static const char* RESET       = "\x1b[0m";

static const char* colorForSuit(int suit, bool isJoker) {
    if (isJoker) return COL_MAGENTA;
    switch (suit) {
        case HEARTS:   return COL_RED;
        case DIAMONDS: return COL_LBLUE;
        case CLUBS:    return COL_LIME;
        case SPADES:   return COL_ORANGE;
        default:       return RESET;
    }
}

static void printCardColored(const Card& c) {
    std::string s = c.toString();
    std::cout << colorForSuit(c.getSuit(), c.isJoker()) << s << RESET;
}

int main()
{
    initConsoleForUtf8AndAnsi();

    Player a("Alice","123");
    Player b("Bob","123");
    std::list<Player> ps{a,b};
    Game g(1, ps);
    g.setAnte(5);
    g.startGame();
    std::cout << "Game started with " << g.getPlayers().size() << " players" << std::endl;
}