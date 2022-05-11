#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QLayout>
#include <QBoxLayout>
#include <QLineEdit>
#include <QMovie>
#include <QtWidgets>
#include <QSizePolicy>
#include <QtSql/qtsqlglobal.h>
#include <QtSql/QSqlDatabase>
#include <QComboBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPixmap>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QTableView>
#include <sstream>
#include <string>
#include <vector>
#include <QHBoxLayout>
#include "database.h"
#include "user.h"
#include "bus.h"
#include "movie.h"
#include "busticketlist.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    // SLOTS
    private slots:
        void loginScreen();
        void dashBoard();
        void registerScreen();
        void displayInfo(int row, int col);
        void displayMovieInfo(int row,int col);
        void adminDashboard();
        void currentTime();

private:
        int currentIndex;
        User user;
        QLineEdit *emailText;
        QLineEdit *passwordText;
        database db;
        void bookBus(QWidget *bookBusWidget, QStackedWidget *bookingPages);
        void bookMovie(QWidget *bookMovieWidget, QStackedWidget *bookingPages);
        void loadMoney(QWidget *loadMoneyWidget, QStackedWidget *bookingPages);
        void addBus(QWidget *addBusWidget, QStackedWidget *bookingPages);
        void addMovie(QWidget *addMovieWidget, QStackedWidget *bookingPages);
        void displayBus(bus* b, QStackedWidget *bookingPages, int index);
        void displayMovie(movie *m, QStackedWidget *bookingPages, int index);
        void setActiveTab(QPushButton *active, QPushButton *inActive1, QPushButton *inActive2, QPushButton *inActive3 = NULL);
        void changeSeats();
        void changeMovieSeats();
        void bookedSeat(QPushButton *b);
        void downloadFinished(QNetworkReply *reply);
        void emailRegister(QString email, QString name);
        void emailCheckout(int bookingId, bus b, int total, QString seats);
        void emailMovieCheckout(int bookingId, movie m, int total, QString seats);

        void myBookings(QWidget *parentW, QStackedWidget *pages);
        void myProfile(QWidget *profileW, QWidget *parentW);
        void editProfile(QStackedWidget *profileStack);
        void changePassword(QStackedWidget *profileStack);
        void updateBookedBus();
        QLabel *busDetails;
        QLabel *movieDetails;
        QTableWidget *busTable;
        QTableWidget *movieTable;
        QPushButton *bookNowButton;
        QPushButton *bookNowButtonMoive;
        QLabel *timeLabel;
        QLabel *dateLabel;
        QLabel *balance;
        QLabel *profileBalance;
        QString serviceDesc;
        int rowIndex;
        int test;
        QTableWidget *bookedBus;
        busTicketList *busTickets;
        busTicketList *movieTickets;


            QPushButton *b1;
            QPushButton *b2;
            QPushButton *b3;
            QPushButton *b4;
            QPushButton *b5;
            QPushButton *b6;
            QPushButton *b7;
            QPushButton *b8;
            QPushButton *b9;
            QPushButton *b10;
            QPushButton *b11;
            QPushButton *b12;
            QPushButton *b13;
            QPushButton *b14;
            QPushButton *b15;
            QPushButton *b16;
            QPushButton *b17;

            bool totalSelected[17]={false};
            QString selectedSeatsNums[18];
            int total;
            QLabel *selectSeats;
            QLabel *totalAmt;

};



#endif // MAINWINDOW_H
