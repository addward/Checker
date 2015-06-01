#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
   // square mass[8][8];
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:

    void on_radioButton_clicked();

    void on_pushButton_clicked();


    void on_c3_l_clicked();
    void on_c5_l_clicked();
    void on_c1_l_clicked();
    void on_c7_l_clicked();

    void on_d2_l_clicked();
    void on_d4_l_clicked();
    void on_d6_l_clicked();
    void on_d8_l_clicked();

    void on_e3_l_clicked();
    void on_e1_l_clicked();
    void on_e5_l_clicked();
    void on_e7_l_clicked();

    void on_f4_l_clicked();
    void on_f2_l_clicked();
    void on_f6_l_clicked();
    void on_f8_l_clicked();

    void on_b4_l_clicked();
    void on_b2_l_clicked();
    void on_b6_l_clicked();
    void on_b8_l_clicked();

    void on_h4_l_clicked();
    void on_h2_l_clicked();
    void on_h6_l_clicked();
    void on_h8_l_clicked();

    void on_g3_l_clicked();
    void on_g1_l_clicked();
    void on_g5_l_clicked();
    void on_g7_l_clicked();
    void on_a1_l_clicked();
    void on_a3_l_clicked();
    void on_a5_l_clicked();
    void on_a7_l_clicked();


    void on_radioButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
