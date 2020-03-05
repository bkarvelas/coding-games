#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
    int max, max_index, i;

    // game loop
    while (1)
    {
        max = 0;
        for (i = 0; i < 8; i++)
        {
            // represents the height of one mountain.
            int mountain_h;
            scanf("%d", &mountain_h);

            if (mountain_h > max)
            {
                max = mountain_h;
                max_index = i;
            }
        }

        printf("%d\n", max_index);
    }
    return 0;
}