#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    auto todays_time = std::chrono::system_clock::now();

    std::time_t today = std::chrono::system_clock::to_time_t(todays_time);

    std::string time = std::ctime(&today);

    QString labeltext = QString::fromStdString(time);
    ui->currentDateTime->setText(labeltext);


    connect(ui->loginButton,&QPushButton::pressed,this,&Widget::echo);
    connect(ui->loginButton,&QPushButton::released,this, &Widget::Noecho);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::echo()
{
   ui->password->setEchoMode(QLineEdit::Normal);
}

void Widget::Noecho()
{
     ui->password->setEchoMode(QLineEdit::Password);
}
