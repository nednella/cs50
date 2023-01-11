#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {

char a = get_char("Character: ");

if(isalpha(a) != 0)
printf("true");

else
printf("false");

}