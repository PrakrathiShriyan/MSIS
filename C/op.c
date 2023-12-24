#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

char upper_to_lower(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return ch+32;
    else
        return '!';
}