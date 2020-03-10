#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// Data
struct rect_beginning
{
    int x;
    int y;
} rect_beg;

struct rect_ending
{
    int x;
    int y;
} rect_end;

struct general_building
{
    int W;
    int H;
} building;

struct batman_position
{
    int x;
    int y;
} bat_pos;

struct previews_batman_position
{
    int x;
    int y;
} prev_bat_pos;

// N = maximum number of turns before game over.
bool start_of_game = true;

void parse_direction(char bomb_direction[], bool start_of_game, struct rect_beginning *rect_b, struct rect_ending *rect_e);
int binary_search_2d(int beginning, int end, char direction);

int main()
{

    // width, height of the building.
    scanf("%d%d", &building.W, &building.H);

    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);

    // Batman Position
    scanf("%d%d", &bat_pos.x, &bat_pos.y);

    // initialize previews Batman position with current Batman position
    prev_bat_pos.x = bat_pos.x;
    prev_bat_pos.y = bat_pos.y;

    // game loop
    while (1)
    {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        parse_direction(bomb_dir, start_of_game, &rect_beg, &rect_end);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "W: %d | H: %d\n", building.W, building.H);
        fprintf(stderr, "Jumps: %d \n", N);
        fprintf(stderr, "Batman Location (%d,%d) \n", bat_pos.x, bat_pos.y);
        fprintf(stderr, "Bomb Location %s \n", bomb_dir);

        // the location of the next window Batman should jump to.
        // printf("3 7\n");
        start_of_game = false;
    }

    return 0;
}

void parse_direction(char bomb_direction[], bool start_of_game, struct rect_beginning *rect_b, struct rect_ending *rect_e)
{
    // y_bat_b, x_bat_b is the begining of the search rectangle area (y_bat_pos + 1, x_bat_pos + 1)
    int i = 0;
    while (bomb_direction[i] != '\0')
    {
        // Initial batman position, direction

        // U D L R
        switch (bomb_direction[i])
        {
            // ama einai Up vres to akrivws Up tetragwno mexri telous
        case 'U':
            // if it is the first move
            if (start_of_game)
            {
                // search-rectangle beginning
                rect_b->y = 0;
            }
            else if (prev_bat_pos.y + 1 < bat_pos.y - 1)
            {
                // search-rectangle beginning
                rect_b->y = prev_bat_pos.y + 1;
            }

            // search-rectangle end
            rect_e->y = bat_pos.y - 1;
            break;

            // ama einai Down vres to akrivws Down tetragwno mexri telous
        case 'D':
            // search-rectangle beginning
            rect_b->y = bat_pos.y + 1;

            // if it is the first move
            if (start_of_game)
            {
                // search-rectangle end
                rect_e->y = building.H - 1;
            }
            else if (prev_bat_pos.y - 1 > bat_pos.y + 1)
            {
                // search-rectangle end
                rect_e->y = prev_bat_pos.y - 1;
            }
            break;

            // ama einai Left vres to akrivws Left tetragwno mexri telous
        case 'L':
            // if it is the first move
            if (start_of_game)
            {
                // search-rectangle beginning
                rect_b->x = 0;
            }
            else if (prev_bat_pos.x + 1 < bat_pos.x - 1)
            {
                // search-rectangle beginning
                rect_b->x = prev_bat_pos.x - 1;
            }

            // search-rectangle end
            rect_e->x = bat_pos.x - 1;
            break;

            // ama einai Right vres to akrivws Right tetragwno mexri telous
        case 'R':
            // search-rectangle beginning
            rect_b->x = bat_pos.x + 1;

            // if it is the first move
            if (start_of_game)
            {
                // search-rectangle end
                rect_e->x = building.W - 1;
            }
            else if (prev_bat_pos.x - 1 > bat_pos.x + 1)
            {
                // search-rectangle end
                rect_e->x = prev_bat_pos.x - 1;
            }
            break;

        default:
            break;
        }
    }
}

int binary_search_2d(int beginning, int end, char direction)
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