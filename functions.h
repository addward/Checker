#ifndef FUNCTIONS
#define FUNCTIONS
#include "widget.h"
#include "qlabel"
#include "ui_widget.h"

#include <stdlib.h>

int hod = 1; // show us which player should move checkers 1 - white 2 -black
int kill_pos = 0; // if kill=1 player can kill one or more enemy checkers
int killed = 0;



struct square
{
    int x;
    int y;
    int col; // 0 - no checker , 1 - white , 2 -black
    int queen; // 0 - not queen , 1 - this checker is queen
    int move;  // 0 - you can't move checker in this square , 1 - you can
    int kill;  // 0 - you can't kill checker in this square , 1 - you can
    struct square * moved; // 0 - you can't move this checker in possible square , 1 - you can
    QLabel* lab;
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
                mass[2*b][i].x = 2 * b;
                mass[2*b][i].y = i;
                mass[2*b][i].queen = 0;
                mass[2*b][i].kill = 0;
                mass[2*b][i].move = 0;
                mass[2*b][i].moved = NULL;
                if (i <= 2) mass[2*b][i].col = 2;
                else if (i <= 4) mass[2*b][i].col = 0;
                else if (i <= 7) mass[2*b][i].col = 1;
            }

            if (i % 2 == 0)
            {   mass[2*b+1][i].queen = 0;
                mass[2*b+1][i].kill = 0;
                mass[2*b+1][i].move = 0;
                mass[2*b+1][i].moved = NULL;
                mass[2*b+1][i].x = (2 * b) + 1;
                mass[2*b+1][i].y = i;
                if (i <= 2) mass[2*b+1][i].col = 2;
                else if (i <= 4) mass[2*b+1][i].col = 0;
                else if (i <= 7) mass[2*b+1][i].col = 1;
            }
        }
    }

}

int check_kill(square* sq, square* mv)  //check can checker sq kill enemy between sq and mv
{
    int posx=(sq->x+mv->x)/2, posy=(sq->y+mv->y)/2;
    if ((mass[posx][posy].col!=hod)&&(mass[posx][posy].col!=0)&&(mv->col==0))
    {
        mv->kill = 1;
        mv->moved = sq;
        return 1;
    }
    else return 0;
}

int check_kill_queen(square* kill,square* sq, square* mv)  //check can checker sq kill enemy between sq and mv
{
    int posx=(sq->x+mv->x)/2, posy=(sq->y+mv->y)/2;
    if ((mass[posx][posy].col!=hod)&&(mass[posx][posy].col!=0)&&(mv->col==0))
    {
        mv->kill = 1;
        mv->moved = kill;
        return 1;
    }
    else return 0;
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

int check_all_kills() //check can all checkers kill anyone.
{
    int i, k, a = 0;
    for (i = 0; i < 8; i++)
    {
        for (k = 0; k < 8; k++)
        {
            if (mass[k][i].col == hod && mass[k][i].queen == 0)
            {
                if ((k + 2 < 8) && (i + 2 < 8)) a = a + check_kill(&(mass[k][i]), &(mass[k+2][i+2]));
                if ((k + 2 < 8) && (i - 2 > 0)) a = a + check_kill(&(mass[k][i]), &(mass[k+2][i-2]));
                if ((k - 2 > 0) && (i + 2 < 8)) a = a + check_kill(&(mass[k][i]), &(mass[k-2][i+2]));
                if ((k - 2 > 0) && (i - 2 > 0)) a = a + check_kill(&(mass[k][i]), &(mass[k-2][i-2]));
            }
            else if (mass[k][i].col == hod && mass[k][i].queen == 1)
            {int x1=0,x2=0,x3=0,x4=0,m;
                for (m=0;m<=7;m++)
                {   if ((k + 2 + m < 8) && (i + 2 + m < 8) && (x1==0))
                        {x1 = x1 + check_kill_queen(&(mass[k][i]), &(mass[k+m][i+m]), &(mass[k+2+m][i+2+m]));
                        a=a+x1;
                        }
                    if ((k + 2 + m < 8) && (i - 2 - m > 0) && (x2==0))
                        {x2 = x2 + check_kill_queen(&(mass[k][i]), &(mass[k+m][i-m]), &(mass[k+2+m][i-2-m]));
                        a=a+x2;
                        }
                    if ((k - 2 - m > 0) && (i + 2 + m < 8) && (x3==0))
                        {x3 = x3 + check_kill_queen(&(mass[k][i]), &(mass[k-m][i+m]), &(mass[k-2-m][i+2+m]));
                        a=a+x3;
                        }
                    if ((k - 2 - m > 0) && (i - 2 + m > 0) && (x4==0))
                        {x4 = x4 + check_kill_queen(&(mass[k][i]), &(mass[k-m][i-m]), &(mass[k-2-m][i-2-m]));
                        a=a+x4;
                        }

                }
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
        {if ((mass[i][k].move != 0)||(mass[i][k].kill != 0))
            {
                mass[i][k].move = 0;
                mass[i][k].kill = 0;
                mass[i][k].moved = NULL;
                mass[i][k].lab->setPixmap(QPixmap(":new/null_1.png"));
            }
        }

    }
}

void move(square* sq)
{
    if (sq->move != 1) return;
    else
    {
        sq->col = sq->moved->col;
        sq->moved->col=0;
        sq->moved->lab->setPixmap(QPixmap(":new/null_1.png"));
        sq->queen = sq->moved->queen;
        sq->moved->queen = 0;
        clear_tags();
        if ((sq->y == 0 && sq->col == 1) || (sq->y == 7 && sq->col == 2)) sq->queen=1;
    }
}

void kill(square* sq)
{
    int posx, posy;
    if ((*sq).kill != 1) return;
    else
    {   if(sq->moved->queen == 1)
            {sq->col = sq->moved->col;
             sq->moved->col = 0;
             sq->queen = sq->moved->queen;
             sq->moved->queen = 0;
             if (sq->x > sq->moved->x) (posx = sq->x - 1);
             if (sq->x < sq->moved->x) (posx = sq->x + 1);
             if (sq->y > sq->moved->y) (posy = sq->y - 1);
             if (sq->y < sq->moved->y) (posy = sq->y + 1);
             mass[posx][posy].col = 0;
             mass[posx][posy].queen = 0;
             clear_tags();
             return;
            }
        else
            {(*sq).col = (*((*sq).moved)).col;
            (*((*sq).moved)).col = 0;
            (*sq).queen = (*((*sq).moved)).queen;
            (*((*sq).moved)).queen = 0;
            posx = (sq->x + sq->moved->x) / 2;
            posy = (sq->y + sq->moved->y) / 2;
            mass[posx][posy].col = 0;
            mass[posx][posy].queen = 0;
            clear_tags();
            return;
            }
    }

}

void check_hod(square* sq)
{
    int posx = sq->x, posy = sq->y - 1;
    if ((sq->col != hod) || (sq->col == 0)) return;
    if ((sq->col == 1)&&(sq->queen == 0))
        {
        if (posy < 0) return;
        else if ((posx - 1 < 0) && (mass[posx+1][posy].col != 0)) return;
        else if ((posx + 1 > 7) && (mass[posx-1][posy].col != 0)) return;
        if ((mass[posx+1][posy].col == 0) && (posx+1<=7))
            {
                mass[posx+1][posy].move = 1;
                mass[posx+1][posy].moved = sq;
            }
        if ((mass[posx-1][posy].col == 0) && (posx-1>=0))
            {
                mass[posx-1][posy].move = 1;
                mass[posx-1][posy].moved = sq;
            }
        }
    posy = posy + 2;
    if ((sq->col == 2)&&(sq->queen == 0))
        {
            if (posy >7) return;
            else if ((posx - 1 < 0) && (mass[posx+1][posy].col != 0)) return;
            else if ((posx + 1 > 7) && (mass[posx-1][posy].col != 0)) return;
            if ((mass[posx+1][posy].col == 0) && (posx + 1<=7))
            {
                mass[posx+1][posy].move = 1;
                mass[posx+1][posy].moved = (sq);
            }
            if ((mass[posx-1][posy].col == 0) && (posx - 1>=0))
            {
                mass[posx-1][posy].move = 1;
                mass[posx-1][posy].moved = (sq);
            }
        }
    posy = posy - 1;
    if (sq->queen == 1)
        {
        int i;
        for (i=0;i<7;i++)
            {if ((i+posx<8) && (i+posy<8) && (mass[posx+i][posy+i].col==0))
                {
                    mass[posx+i][posy+i].move = 1;
                    mass[posx+i][posy+i].moved = (sq);
                }
            if ((i+posx<8) && (posy-i>=0) && (mass[posx+i][posy-i].col==0))
                {
                    mass[posx+i][posy-i].move = 1;
                    mass[posx+i][posy-i].moved = (sq);
                }
            if ((posx-i>=0) && (posy+i<8) && (mass[posx-i][posy+i].col==0))
                {
                    mass[posx-i][posy+i].move = 1;
                    mass[posx-i][posy+i].moved = (sq);
                }
            if ((posx-i>=0) && (posy-i>=0) && (mass[posx-i][posy-i].col==0))
                {
                    mass[posx-i][posy-i].move = 1;
                    mass[posx-i][posy-i].moved = (sq);
                }

            }

        }

}

void press(square* sq)
{   if ((sq->col != hod)&&(sq->move != 1)&&(sq->kill != 1)) return;
    if (kill_pos!=0)
    {
        if (sq->kill == 1)
        {
            kill(sq);
            killed++;
            kill_pos=0;
            clear_tags();
            press(sq);
        }
        else return;
    }
    else (kill_pos=check_all_kills());
    if (kill_pos!=0) return;
    else if (killed!=0)
        {
            if (hod==1) hod=2;
            else hod=1;
            killed=0;
        }
    else if (sq->move == 1)
        {
            move(sq);
            if (hod==1) hod=2;
            else hod=1;
        }

    if ((sq->move != 1) && (sq->kill != 1)) clear_tags();
    if ((sq->move != 1) && (sq->kill != 1) && (sq->col == 0)) return;

    check_hod(sq);
}

void my_print(square sq)
{
    if (sq.col==1 && sq.queen==1) (sq.lab->setPixmap(QPixmap(":new/white_q.png")));
    else if (sq.col==2 && sq.queen==1) (sq.lab->setPixmap(QPixmap(":new/black_q.png")));
    else if (sq.move==1) (sq.lab->setPixmap(QPixmap(":new/move.png")));
    else if (sq.kill==1) (sq.lab->setPixmap(QPixmap(":new/kill.png")));
    else if (sq.col==2) (sq.lab->setPixmap(QPixmap(":new/black.png")));
    else if (sq.col==1) (sq.lab->setPixmap(QPixmap(":new/white.png")));
    else (sq.lab->setPixmap(QPixmap(":new/null_1.png")));
}

void all_print()
{int i, k;
    for(i=0;i<=7;i++)
    {
        for(k=0;k<=7;k++)
        {
            if(((i%2==0)&&(k%2!=0))||((i%2!=0)&&(k%2==0)))
            my_print(mass[k][i]);
        }
    }
}
#endif // FUNCTIONS


