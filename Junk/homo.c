#include<cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Are you gay? ");
    printf("%s? No way, you're definitely gay\n", answer);
}