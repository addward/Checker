#include "widget.h"
#include "ui_widget.h"
#include "functions.h"

int a = 0;
int b = 1;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_clicked()
{a=1;b=0;
}

void Widget::on_pushButton_clicked()
{
    clear();
    start_positions();
    mass[0][1].lab=ui->a7;mass[0][3].lab=ui->a5;mass[0][5].lab=ui->a3;mass[0][7].lab=ui->a1;
    mass[1][0].lab=ui->b8;mass[1][2].lab=ui->b6;mass[1][4].lab=ui->b4;mass[1][6].lab=ui->b2;
    mass[2][1].lab=ui->c7;mass[2][3].lab=ui->c5;mass[2][5].lab=ui->c3;mass[2][7].lab=ui->c1;
    mass[3][0].lab=ui->d8;mass[3][2].lab=ui->d6;mass[3][4].lab=ui->d4;mass[3][6].lab=ui->d2;
    mass[4][1].lab=ui->e7;mass[4][3].lab=ui->e5;mass[4][5].lab=ui->e3;mass[4][7].lab=ui->e1;
    mass[5][0].lab=ui->f8;mass[5][2].lab=ui->f6;mass[5][4].lab=ui->f4;mass[5][6].lab=ui->f2;
    mass[6][1].lab=ui->g7;mass[6][3].lab=ui->g5;mass[6][5].lab=ui->g3;mass[6][7].lab=ui->g1;
    mass[7][0].lab=ui->h8;mass[7][2].lab=ui->h6;mass[7][4].lab=ui->h4;mass[7][6].lab=ui->h2;
    clear_tags();
    kill_pos=0;
    //mass[2][5].queen=1;
    all_print();
    hod=1;
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
}
/////////////////a//////////////////////
void Widget::on_a1_l_clicked()
{
    if (b==1)press_pc(&mass[0][7]);
    if (a==1)press(&mass[0][7]);
    all_print();
}
void Widget::on_a3_l_clicked()
{
    if (b==1) press_pc(&mass[0][5]);
    if (a==1) press(&mass[0][5]);
    all_print();
}
void Widget::on_a5_l_clicked()
{
    if (b==1) press_pc(&mass[0][3]);
    if (a==1) press(&mass[0][3]);
    all_print();
}
void Widget::on_a7_l_clicked()
{
    if (b==1) press_pc(&mass[0][1]);
    if (a==1) press(&mass[0][1]);
    all_print();
}
/////////////////b//////////////////////
void Widget::on_b4_l_clicked()
{
    if (b==1) press_pc(&mass[1][4]);
    if (a==1) press(&mass[1][4]);
    all_print();
}
void Widget::on_b8_l_clicked()
{
    if (b==1) press_pc(&mass[1][0]);
    if (a==1) press(&mass[1][0]);
    all_print();
}
void Widget::on_b6_l_clicked()
{
    if (b==1) press_pc(&mass[1][2]);
    if (a==1) press(&mass[1][2]);
    all_print();
}
void Widget::on_b2_l_clicked()
{
    if (b==1) press_pc(&mass[1][6]);
    if (a==1) press(&mass[1][6]);
    all_print();
}
/////////////////c//////////////////////
void Widget::on_c3_l_clicked()
{
    if (b==1) press_pc(&mass[2][5]);
    if (a==1) press(&mass[2][5]);
    all_print();
}
void Widget::on_c5_l_clicked()
{
    if (b==1) press_pc(&mass[2][3]);
    if (a==1) press(&mass[2][3]);
    all_print();
}
void Widget::on_c1_l_clicked()
{
    if (b==1) press_pc(&mass[2][7]);
    if (a==1) press(&mass[2][7]);
    all_print();
}
void Widget::on_c7_l_clicked()
{
    if (b==1) press_pc(&mass[2][1]);
    if (a==1) press(&mass[2][1]);
    all_print();
}
/////////////////d//////////////////////
void Widget::on_d4_l_clicked()
{   if (b==1) press_pc(&mass[3][4]);
    if (a==1) press(&mass[3][4]);
    all_print();
}
void Widget::on_d6_l_clicked()
{
    if (b==1) press_pc(&mass[3][2]);
    if (a==1) press(&mass[3][2]);
    all_print();
}
void Widget::on_d2_l_clicked()
{
    if (b==1) press_pc(&mass[3][6]);
    if (a==1) press(&mass[3][6]);
    all_print();
}
void Widget::on_d8_l_clicked()
{
    if (b==1) press_pc(&mass[3][0]);
    if (a==1) press(&mass[3][0]);
    all_print();
}
/////////////////e//////////////////////
void Widget::on_e3_l_clicked()
{
    if (b==1) press_pc(&mass[4][5]);
    if (a==1) press(&mass[4][5]);
    all_print();
}
void Widget::on_e1_l_clicked()
{
    if (b==1) press_pc(&mass[4][7]);
    if (a==1) press(&mass[4][7]);
    all_print();
}
void Widget::on_e5_l_clicked()
{
    if (b==1) press_pc(&mass[4][3]);
    if (a==1) press(&mass[4][3]);
    all_print();
}
void Widget::on_e7_l_clicked()
{
    if (b==1) press_pc(&mass[4][1]);
    if (a==1) press(&mass[4][1]);
    all_print();
}
/////////////////f//////////////////////
void Widget::on_f4_l_clicked()
{
    if (b==1) press_pc(&mass[5][4]);
    if (a==1) press(&mass[5][4]);
    all_print();
}
void Widget::on_f2_l_clicked()
{
    if (b==1) press_pc(&mass[5][6]);
    if (a==1) press(&mass[5][6]);
    all_print();
}
void Widget::on_f6_l_clicked()
{
    if (b==1) press_pc(&mass[5][2]);
    if (a==1) press(&mass[5][2]);
    all_print();
}
void Widget::on_f8_l_clicked()
{
    if (b==1) press_pc(&mass[5][0]);
    if (a==1) press(&mass[5][0]);
    all_print();
}
/////////////////g//////////////////////
void Widget::on_g3_l_clicked()
{
    if (b==1) press_pc(&mass[6][5]);
    if (a==1) press(&mass[6][5]);
    all_print();
}
void Widget::on_g1_l_clicked()
{
    if (b==1) press_pc(&mass[6][7]);
    if (a==1) press(&mass[6][7]);
    all_print();
}
void Widget::on_g5_l_clicked()
{
    if (b==1) press_pc(&mass[6][3]);
    if (a==1) press(&mass[6][3]);
    all_print();
}
void Widget::on_g7_l_clicked()
{
    if (b==1) press_pc(&mass[6][1]);
    if (a==1) press(&mass[6][1]);
    all_print();
}
/////////////////h//////////////////////
void Widget::on_h4_l_clicked()
{
    if (b==1) press_pc(&mass[7][4]);
    if (a==1) press(&mass[7][4]);
    all_print();
}
void Widget::on_h2_l_clicked()
{
    if (b==1) press_pc(&mass[7][6]);
    if (a==1) press(&mass[7][6]);
    all_print();
}
void Widget::on_h6_l_clicked()
{
    if (b==1) press_pc(&mass[7][2]);
    if (a==1) press(&mass[7][2]);
    all_print();
}
void Widget::on_h8_l_clicked()
{
    if (b==1) press_pc(&mass[7][0]);
    if (a==1) press(&mass[7][0]);
    all_print();
}
////////////////////////////////////////

void Widget::on_radioButton_2_clicked()
{b=1;a=0;
}

