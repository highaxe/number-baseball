#include <stdio.h>
#include <stdbool.h>

#ifndef YELLOW
    #define YELLOW "\x1b[38;2;250;250;70m"
#endif
#ifndef BLUE
    #define BLUE "\x1b[38;2;14;100;237m"
#endif
#ifndef RED
    #define RED "\x1b[38;2;250;70;70m"
#endif
#ifndef GRAY
    #define GRAY "\033[90m"
#endif
#ifndef RESET
    #define RESET "\033[0m"
#endif