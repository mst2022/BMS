#ifndef DATABASE_H
#define DATABASE_H

#include<QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include "user.h"
#include "bus.h"
#include "movie.h"
#include "busticketlist.h"

class database
{
private:
    QSqlDatabase db;
    User u;

public:

    database();
    bool connectDB();
    QSqlDatabase getDB();
    bool registerUser(QString fname,QString lname,QString number,QString email,QString password);
    bool loginUser(QString email,QString password, User &us);
    bool alreadyRegistred(QString email);
    bool loadMoney(QString email, int amount);
    bool addBus(QString name, QString from, QString to, QString date, QString time, int price, QString desc);
    bool addMovie(QString name, QString date, QString time, int price, QString desc);
    bool bookSeats(int type, int id, QString seatNo[]); // 1 - bus 2-flight 3-movie
    int fillBus(bus *b);
    int fillMovie(movie *m);
    int fillBusTickets(busTicketList *t, int uid);
    int fillMovieTickets(busTicketList *t, int uid);
    bool changePassword(int id , QString pw);
    bool editProfile(int id, QString name, QString lname, QString phone);
    bool deductMoney(int id, int balance);
    int insertBooking(int id, QString bname, QString from, QString to, QString seats, QString date, QString time, int price, int total);
    bool insertBookingMovies(int id, QString bname, QString seats,  QString date, QString time, int price, int total);
    int getBookingId(int tno, int id, QString  s);
};

#endif // DATABASE_H
