#include <stdlib.h>

int hod = 1; // show us which player should move checkers 1 - white 2 -black
int kill_pos = 0; // if kill=1 player can kill one or more enemy checkers

struct square
{
	int x;
	int y;
	int col = 0; // 0 - no checker , 1 - white , 2 -black
	int queen = 0; // 0 - not queen , 1 - this checker is queen
	int move = 0;  // 0 - you can't move checker in this square , 1 - you can
	int kill = 0;  // 0 - you can't kill checker in this square , 1 - you can
	struct square * moved = NULL; // 0 - you can't move this checker in possible square , 1 - you can
};

square mass[8][8];

void start_positions() //put checkers in start positions
{
	int i=0,b=0;
	for (i = 0; i <= 7; i++)
	{
		for (b = 0; b <= 3; b++)
		{
			if (i % 2 != 0)
			{
				mass[i][2 * b].x = 2 * b;
				mass[i][2 * b].y = i;
				if (i <= 2) mass[i][2 * b].col = 2;
				else if (i <= 4) mass[i][2 * b].col = 0;
				else if (i <= 7) mass[i][2 * b].col = 1;
			}
			
			if (i % 2 == 0)
			{
				mass[i][(2 * b) + 1].x = (2 * b) + 1;
				mass[i][(2 * b) + 1].y = i;
				if (i <= 2) mass[i][b].col = 2;
				else if (i <= 4) mass[i][(2 * b) + 1].col = 0;
				else if (i <= 7) mass[i][(2 * b) + 1].col = 1;
			}
		}
	}

} 

int check_kill(square* sq, square* mv)  //check can checker sq kill enemy between sq and mv
{
	int posx=((*sq).x)/2+((*mv).x)/2, posy=((*sq).y)/2+((*mv).y)/2;
	if (((*sq).col == mass[posx][posy].col)||(mass[posx][posy].col==0)||((*mv).col!=0)) return 0;
	else
	{
		(*mv).kill = 1;
		(*mv).moved = sq;
		return 1;
	}

}

void check_move(square* sq, square* mv) //check can checcker sq move to square mv
{
	if ((*mv).col != 0) return;
	else
	{
		(*mv).move = 1;
		(*mv).moved = sq;
		return;
	}
}

int check_all_kills() //check can all checkers kill anyone
{
	int i, k, a = 0;
	for (i = 0; i < 8; i++)
	{
		for (k = 0; k < 8; k++)
		{	
			if (mass[k][i].col = hod)
			{
				if ((k + 2 < 8) || (i + 2 < 8)) a = a + check_kill(&(mass[k][i]), &(mass[k + 2][i + 2]));
				if ((k + 2 < 8) || (i - 2 > 0)) a = a + check_kill(&(mass[k][i]), &(mass[k + 2][i - 2]));
				if ((k - 2 > 0) || (i + 2 < 8)) a = a + check_kill(&(mass[k][i]), &(mass[k - 2][i + 2]));
				if ((k - 2 > 0) || (i - 2 > 0)) a = a + check_kill(&(mass[k][i]), &(mass[k - 2][i - 2]));
			}
		}
	}
	return a;
}

void clear_tags()
{
	int i, k;
	for (i = 0; i < 8; i++)
	{
		for (k = 0; k < 8; k++)
		{
			mass[i][k].move = 0;
			mass[i][k].kill = 0;
			mass[i][k].moved = NULL;
		}

	}
}

void move(square* sq)
{
	if ((*sq).move != 1) return;
	else
	{
		(*sq).col = (*((*sq).moved)).col;
		(*((*sq).moved)).col=0;
		(*sq).queen = (*((*sq).moved)).queen;
		(*((*sq).moved)).queen = 0;
		clear_tags();
	}
}

void kill(square* sq)
{
	int posx, posy;
	if ((*sq).kill != 1) return;
	else
	{
		(*sq).col = (*((*sq).moved)).col;
		(*((*sq).moved)).col = 0;
		(*sq).queen = (*((*sq).moved)).queen;
		(*((*sq).moved)).queen = 0;
		posx = ((*sq).x) / 2 + (*((*sq).moved)).x / 2;
		posy = ((*sq).y) / 2 + (*((*sq).moved)).y / 2;
		mass[posx][posy].col = 0;
		mass[posx][posy].queen = 0;
		clear_tags();
	}

}

/*void check_hod(square* sq)
{
	int posx = (*sq).x, posy = (*sq).y - 1;
	if (((*sq).col != hod) || ((*sq).col == 0)) return;
	if ((*sq).col == 1)
		{
		if (posy < 0) return;
		else if ((mass[posx + 1][posy].col != 0) && (mass[posx - 1][posy].col != 0)) return;
		else if (mass[posx + 1][posy].col == 0)
			{
				mass[posx + 1][posy].move = 1;
				mass[posx + 1][posy].moved = sq;
			}
		else if (mass[posx - 1][posy].col == 0)
			{
				mass[posx - 1][posy].move = 1;
				mass[posx - 1][posy].moved = sq;
			}
		}
	posy = posy + 2;
	if ((*sq).col == 2)
		{
		if ((posy < 0) || (posx + 1>7) || (posx - 1<0)) return;
		if ((mass[posx + 1][posy].col != 0) && (mass[posx - 1][posy].col != 0)) return;
		else if ((mass[posx + 1][posy].col != 0) && (mass[posx - 1][posy].col != 0)) return;
		else if (mass[posx + 1][posy].col == 0)
			{
				mass[posx + 1][posy].move = 1;
				mass[posx + 1][posy].moved = sq;
			}
		else if (mass[posx - 1][posy].col == 0)
			{
				mass[posx - 1][posy].move = 1;
				mass[posx - 1][posy].moved = sq;
			}
		}

}
*/

void press(square sq)
{
	int a;
	if (sq.col != hod) return;
	else a=check_all_kills();
	if (a == 0)
	{
		check_hod(&sq);
	}
	if (sq.move == 1) move(&sq);
	if (sq.kill == 1) kill(&sq);
	if ((sq.move != 1) && (sq.kill != 1) && (sq.col == 0)) return;
}

int main()
{
	
}
