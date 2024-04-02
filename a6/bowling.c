#include <stdio.h>
#include <stdlib.h>

typedef struct frame
{
    int first_roll;
    int second_roll;
    int score;
    char *type;
} frame;

int read_rolls(int rolls[])
{
    int i = 0;

    int roll;
    while (scanf("%d", &roll) == 1)
    {
        if (roll < 0 || roll > 10)
        {
            printf("Invalid roll\n");
            exit(0);
        }

        rolls[i] = roll;
        i++;
    }

    if (i < 12)
    {
        printf("Too few rolls\n");
        exit(0);
    }

    if (i > 21)
    {
        printf("Too many rolls\n");
        exit(0);
    }

    return i;
}

int score_frames(struct frame frames[], int rolls[], int num_rolls)
{
    int i = 0;
    int frame = 0;

    while (i < num_rolls)
    {
        if (frame <= 8) // frame 1 - 9
        {

            if (rolls[i] == 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = 0;
                frames[frame].score = 10;
                frames[frame].type = "Strike";

                frames[frame].score += rolls[i + 1] + rolls[i + 2];
                i++;
            }
            else if (rolls[i] + rolls[i + 1] == 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = rolls[i + 1];
                frames[frame].score = 10;
                frames[frame].type = "Spare";

                frames[frame].score += rolls[i + 2];

                i += 2;
            }
            else if (rolls[i] + rolls[i + 1] < 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = rolls[i + 1];
                frames[frame].score = rolls[i] + rolls[i + 1];
                frames[frame].type = "Open";

                i += 2;
            }
            else if (rolls[i] + rolls[i + 1] >= 10)
            {
                printf("Invalid roll\n");
                exit(0);
            }

            frame++;
        }

        else if (frame == 9) // 10th frame
        {
            if (rolls[i] == 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = 0;
                frames[frame].score = 10;
                frames[frame].type = "Strike";

                if (num_rolls - (i + 1) < 2)
                {
                    printf("Too few rolls\n");
                    exit(0);
                }
                else if (num_rolls - (i + 1) > 2)
                {
                    printf("Too many rolls\n");
                    exit(0);
                }

                frames[frame + 1].first_roll = rolls[i + 1];
                frames[frame + 1].second_roll = rolls[i + 2];
                frames[frame + 1].score = rolls[i + 1] + rolls[i + 2];
                frames[frame + 1].type = "Open";

                frames[frame].score += rolls[i + 1] + rolls[i + 2];
                i++;
            }
            else if (rolls[i] + rolls[i + 1] == 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = rolls[i + 1];
                frames[frame].score = 10;
                frames[frame].type = "Spare";

                // +2 here bc we are looking past the second roll
                if (num_rolls - (i + 2) < 1)
                {
                    printf("Too few rolls\n");
                    exit(0);
                }
                else if (num_rolls - (i + 2) > 1)
                {
                    printf("Too many rolls\n");
                    exit(0);
                }

                frames[frame + 1].first_roll = rolls[i + 2];
                frames[frame + 1].second_roll = 0;
                frames[frame + 1].score = rolls[i + 2];
                frames[frame + 1].type = "Open";

                frames[frame].score += rolls[i + 2];

                i += 2;
            }
            else if (rolls[i] + rolls[i + 1] < 10)
            {
                frames[frame].first_roll = rolls[i];
                frames[frame].second_roll = rolls[i + 1];
                frames[frame].score = rolls[i] + rolls[i + 1];
                frames[frame].type = "Open";

                // +2 here bc we are looking past the second roll
                if (num_rolls - (i + 2) != 0)
                {
                    printf("Too many rolls\n");
                    exit(0);
                }

                i += 2;
            }
            else if (rolls[i] + rolls[i + 1] >= 10)
            {
                printf("Invalid roll\n");
                exit(0);
            }

            frame++;
        }

        else
            break;
    }

    // TODO: figure out what to return here once spec is updated
    return -1;
}

void print_frames(struct frame frames[])
{
    int totalScore = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Frame %2d: ", i + 1);

        int first_roll = frames[i].first_roll;
        printf("(%2d/", first_roll);

        int second_roll = frames[i].second_roll;
        if (first_roll == 10)
            printf(" -) ");
        else
            printf("%2d) ", second_roll);

        int score = frames[i].score;
        printf("%2d ", score);

        totalScore += score;
        printf("%3d ", totalScore);

        char *type = frames[i].type;
        printf("(%6s)", type);

        if (i == 9 && score >= 10)
        {
            if (first_roll == 10)
            {
                printf(" (+%d+%d)", frames[i + 1].first_roll, frames[i + 1].second_roll);
            }
            else
            {
                printf(" (+%d)", frames[i + 1].first_roll);
            }
        }

        printf("\n");
    }
}

int main()
{

    int rolls[21];

    int num_rolls = read_rolls(rolls);

    struct frame frames[11];
    score_frames(frames, rolls, num_rolls);

    print_frames(frames);
}