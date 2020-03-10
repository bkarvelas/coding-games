#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// search-rectangle beginning
struct rect_beginning
{
    int x;
    int y;
} rect_beg;

// search-rectangle ending
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

// current batman position
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

// is the beginning of the game?
bool start_of_game = true;

void parse_direction(char bomb_direction[], bool start_of_game, struct rect_beginning *rect_b, struct rect_ending *rect_e);
int binary_search_2d(int beginning, int end);

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

        bat_pos.x = binary_search_2d(rect_beg.x, rect_end.x);
        bat_pos.y = binary_search_2d(rect_beg.y, rect_end.y);

        printf("%d %d\n", bat_pos.x, bat_pos.y);

        // the location of the next window Batman should jump to.
        prev_bat_pos.x = bat_pos.x;
        prev_bat_pos.y = bat_pos.y;

        if (start_of_game == true)
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
        // direction
        switch (bomb_direction[i++])
        {
        case 'U':
            // if it is the first move
            if (start_of_game == true)
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

        case 'D':
            // search-rectangle beginning
            rect_b->y = bat_pos.y + 1;

            // if it is the first move
            if (start_of_game == true)
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

        case 'L':
            // if it is the first move
            if (start_of_game == true)
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

        case 'R':
            // search-rectangle beginning
            rect_b->x = bat_pos.x + 1;

            // if it is the first move
            if (start_of_game == true)
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

int binary_search_2d(int beginning, int end)
{
    return (beginning + end) / 2;
}