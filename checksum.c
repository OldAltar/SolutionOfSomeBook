#include <stdio.h>
#include <stdlib.h>

/*
    Write 21 program that reads characters from the standard input and writes them
    to the standard output. It should also compute a checksum and write it out
    after the characters.
    The checksum is computed in a signed char variable that is initialized
    to ¡ª1. As each character is read from the standard input, it is added to the
    checksum. Any overflow from aha checksum variable is ignored. When all of
    the characters have-, been written, the checksum is then written as a decimal
    integer, which may be negative. Be sure to follow the checksum with a new-
    line.
    On computers that use ASCII, running your program on a file containing
    the words "Hello world!" followed by a newline should produce the following
    output:
    Hello world!
    102
*/
int main( void )
{
    int c;
    char sum = -1;
    while( (c = getchar()) != EOF ){//when you are going to stop inputting ,print Ctrl+Z and then Enter
        putchar( c );
        sum += c;
    }
    printf( "%d\n", sum );
    return EXIT_SUCCESS;
}
