	#include <cs50.h>
	#include <stdio.h>

	int main(int argc, string argv[])
	{
        string w = "abc";

		if (argc ==2)
		{
            printf("Hello, %s\n", w);
            w = argv[1];
			printf("Hello, %s\n", w);
		}
		else
		{
			printf("error\n");
		}
}