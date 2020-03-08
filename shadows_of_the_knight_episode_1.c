#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void parseDirection(char batman_position[]);
int binarySearch(int beginning, int end, char direction);

int main()
{
    // width, height of the building.
    int W, H;
    scanf("%d%d", &W, &H);

    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);

    // Batman Position
    int x_bat_pos, y_bat_pos;
    scanf("%d%d", &x_bat_pos, &y_bat_pos);

    // game loop
    while (1)
    {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "W: %d | H: %d\n", W, H);
        fprintf(stderr, "Jumps: %d \n", N);
        fprintf(stderr, "Batman Location (%d,%d) \n", x_bat_pos, y_bat_pos);
        fprintf(stderr, "Bomb Location %s \n", bomb_dir);

        // the location of the next window Batman should jump to.
        printf("3 7\n");
    }

    return 0;
}

void parseDirection(char batman_position[])
{
    int i = 0;
    while (batman_position[i] != '\0')
    {
        // U D L R
        switch (batman_position[i])
        {
            // ama einai Up vres to akrivws Up tetragwno mexri telous
        case 'U':
            /* code */
            break;

            // ama einai Down vres to akrivws Down tetragwno mexri telous
        case 'D':
            /* code */
            break;

            // ama einai Left vres to akrivws Left tetragwno mexri telous
        case 'L':
            /* code */
            break;

            // ama einai Right vres to akrivws Right tetragwno mexri telous
        case 'R':
            /* code */
            break;

        default:
            break;
        }
    }
}

int binarySearch(int beginning, int end, char direction)
{
    if (end >= beginning)
    {
        int mid = beginning + (end - beginning) / 2;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (direction == 'L' || direction == 'U')
            return mid - 1;

        // Else the element can only be present
        // in right subarray
        return mid + 1;
    }

    // We reach here when element is not
    // present in array
    return -1;
}