#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void) {

    // store the entered key from the CLI
    string abc = "hello";
    printf("%s\n", abc);
    printf("%c\n", abc[0]);
    printf("%c\n", abc[1]);
    printf("%c\n", abc[2]);

    string def = "bye";

    abc[0] = def[0];


}

