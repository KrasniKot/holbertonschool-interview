#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - performs the addition of two sandpiles:
 * @grid1: first sandpile,
 * @grid2: second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, fspile[3][3];

	(void)grid1;
	(void)grid2;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			fspile[i][j] = grid1[i][j] + grid2[i][j];

	stability_check(fspile);
}

/**
 * stability_check - checks for a sandpile to be stable,
 *                   and performs the pertinent additions:
 * @spile: sandpile to check.
 */
void stability_check(int spile[3][3])
{
	int i, j;
	int stable = 1;

	print_grid(spile);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (spile[i][j] > 3)
			{
				if (i - 1 >= 0)
					spile[i - 1][j] += 1;
				if (i + 1 < 3)
					spile[i + 1][j] += 1;

				if (j + 1 < 3)
					spile[i][j + 1] += 1;
				if (j - 1 >= 0)
					spile[i][j - 1] += 1;

				spile[i][j] -= 4;
				stable = 0;
			}
	}
	if (!stable)
		stability_check(spile);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
