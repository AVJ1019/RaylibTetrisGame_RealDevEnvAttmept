#include "colorFactory.h"

Color colorFactory(int c)
{
    switch (c)
    {
    case (1):
        return SKYBLUE;
    case (2):
        return YELLOW;
    case (3):
        return PURPLE;
    case (4):
        return ORANGE;
    case (5):
        return BLUE;
    case (6):
        return GREEN;
    case (7):
        return RED;
    default:
        return WHITE;
    }
}