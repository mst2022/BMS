#include "database.h"
#include <QDebug>
#include <QMessageBox>

database::database()
{
    db = QSqlDatabase::addDatabase("QMYSQL"); // Initializing Database, QMYSQL is MySQL database driver for QT.
    db.setHostName("localhost");              // Setting hostname
    db.setPort(3306);                         // setting port
    db.setDatabaseName("BMSdb");              // setting database name
    db.setUserName("");                       // setting username
    db.setPassword("");                       // setting password
}
bool database::connectDB()
{
    if (db.open())
    {
        qDebug() << db;
        return true;
    }
    else
    { // If database connection is not established
        return false;
    }
}
QSqlDatabase database::getDB()
{
    return db;
}

bool database::registerUser(QString fname, QString lname, QString number, QString email, QString password)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO users(firstname, lastname, email, password, phone, balance, datejoined) VALUES(:firstname, :lastname, :email, :password, :phone, :balance, NOW())");
    qry.bindValue(":firstname", fname);
    qry.bindValue(":lastname", lname);
    qry.bindValue(":email", email);
    qry.bindValue(":password", password);
    qry.bindValue(":phone", number);
    qry.bindValue(":balance", 0);
    if (qry.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool database::loginUser(QString email, QString password, User &us)
{
    QSqlQuery query;
    bool qryExc = query.exec("SELECT * FROM users WHERE email='" + email + "' AND BINARY password='" + password + "';");

    if (qryExc)
    {
        if (query.next())
        { // condition is true if user exists
            us.setUserId(query.value(0).toInt());
            us.setPhoneNo(query.value(2).toString());
            us.setEmail(query.value(1).toString());
            us.setFName(query.value(3).toString());
            us.setLName(query.value(4).toString());
            us.setPassword(query.value(5).toString());
            us.setBalance(query.value(6).toInt());
            us.setAdminStatus(query.value(7).toInt());
            us.setJoinedDate(query.value(8).toString());
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        throw "ConnectionError";
    }
    //    return false;
}

bool database::alreadyRegistred(QString email)
{
    QSqlQuery qry;
    qry.exec("SELECT * FROM users WHERE email='" + email + "';");
    if (qry.next())
    {
        return true;
    }
    else
    {

        return false;
    }
}

bool database::loadMoney(QString email, int amount)
{
    int bal;
    QSqlQuery qry;
    qry.exec("SELECT balance FROM users WHERE email = '" + email + "'");
    if (qry.next())
    {
        bal = qry.value(0).toInt() + amount;
        qry.prepare("UPDATE users SET balance = :amt WHERE email = '" + email + "'");
        qry.bindValue(":amt", bal);
        qry.exec();
        return true;
    }
    else
    {
        return false;
    }
}

bool database::addBus(QString name, QString from, QString to, QString d, QString t, int price, QString desc)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO buses(`busname`, `from`, `to`, `price`, `date`, `time`, `description`) VALUES('" + name + "', '" + from + "', '" + to + "', :price, '" + d + "', '" + t + "', '" + desc + "')");

    qry.bindValue(":price", price);

    if (qry.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool database::addMovie(QString name, QString date, QString time, int price, QString desc)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO movies(`name`, `date`, `time`, `price`, `desc`) VALUES('" + name + "', '" + date + "', '" + time + "', :price, '" + desc + "')");

    qry.bindValue(":price", price);

    if (qry.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool database::bookSeats(int type, int id, QString seatNo[])
{
    int i = 0;

    while (!seatNo[i].isEmpty())
    {
        QSqlQuery qry;
        switch (type)
        {
        case 1:
            qry.prepare("UPDATE buses set " + seatNo[i] + " = :true where id = :bid");
            break;
        case 2:
            qry.prepare("UPDATE flight set " + seatNo[i] + " = :true where id = :bid");
            break;

        case 3:
            qry.prepare("UPDATE movies set " + seatNo[i] + " = :true where id = :bid");
            break;
        }

        qry.bindValue(":bid", id);
        qry.bindValue(":true", 1);
        if (!qry.exec())
        {
            qry.lastError();
            return false;
        }
        i++;
    }
    return true;
}

int database::fillBus(bus *b)
{
    int busCnt;
    QSqlQuery qry;
    qry.exec("SELECT COUNT(*) FROM buses");
    while (qry.next())
    {
        busCnt = qry.value(0).toInt();
    }

    QSqlQuery query;

    bool qryExc = query.exec("SELECT * FROM buses");
    if (qryExc)
    {

        for (int i = 0; i < busCnt; i++)
        {
            int a = 0;
            if (query.next())
            { // condition is true if user exists
                b[i].setBusId(query.value(a++).toInt());
                b[i].setName(query.value(a++).toString());
                b[i].setFrom(query.value(a++).toString());
                b[i].setTo(query.value(a++).toString());
                b[i].setDate(query.value(a++).toString());
                b[i].setTime(query.value(a++).toString());
                b[i].setPrice(query.value(a++).toInt());
                b[i].setDesc(query.value(a++).toString());
                for (int j = 0; j < 17; j++)
                {
                    b[i].seats[j] = query.value(a++).toInt();
                }
            }
        }
    }

    else
    {
        qDebug() << "FAILED LOADING BUSES";
    }
    return busCnt;
}

int database::fillMovie(movie *m)
{
    int busCnt;
    QSqlQuery qry;
    qry.exec("SELECT COUNT(*) FROM movies");
    while (qry.next())
    {
        busCnt = qry.value(0).toInt();
    }

    QSqlQuery query;

    bool qryExc = query.exec("SELECT * FROM movies");
    if (qryExc)
    {

        for (int i = 0; i < busCnt; i++)
        {
            int a = 0;
            if (query.next())
            { // condition is true if user exists
                m[i].setMovieId(query.value(a++).toInt());
                m[i].setName(query.value(a++).toString());
                m[i].setDate(query.value(a++).toString());
                m[i].setTime(query.value(a++).toString());
                m[i].setPrice(query.value(a++).toInt());
                m[i].setDesc(query.value(a++).toString());
                for (int j = 0; j < 17; j++)
                {
                    m[i].seats[j] = query.value(a++).toInt();
                }
            }
        }
    }

    else
    {
        qDebug() << "FAILED LOADING MOVIES";
    }
    return busCnt;
}

int database::fillBusTickets(busTicketList *t, int uid)
{
    int tktCnt = 0;
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM bookings WHERE userid = :id");
    qry.bindValue(":id", uid);
    qry.exec();
    while (qry.next())
    {
        tktCnt = qry.value(0).toInt();
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM bookings WHERE userid = :id");
    query.bindValue(":id", uid);
    bool qryExc = query.exec();
    if (qryExc)
    {
        for (int i = 0; i < tktCnt; i++)
        {
            if (query.next())
            { // condition is true if user exists
                t[i].setBookingId(query.value(0).toInt());
                t[i].setName(query.value(2).toString());
                t[i].setFrom(query.value(3).toString());
                t[i].setTo(query.value(4).toString());
                t[i].setTime(query.value(5).toString());
                t[i].setDate(query.value(6).toString());
                t[i].setSeatNo(query.value(7).toString());
                t[i].setPrice(query.value(8).toInt());
                t[i].setTotalPrice(query.value(9).toInt());
            }
        }
    }

    else
    {
        qDebug() << "FAILED LOADING BUS TICKETS";
    }

    return tktCnt;
}

int database::fillMovieTickets(busTicketList *t, int uid)
{
    int tktCnt = 0;
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM bookingsmovies where userid = :id");
    qry.bindValue(":id", uid);
    qry.exec();
    while (qry.next())
    {
        tktCnt = qry.value(0).toInt();
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM bookingsmovies WHERE userid = :id");
    query.bindValue(":id", uid);
    bool qryExc = query.exec();
    if (qryExc)
    {
        for (int i = 0; i < tktCnt; i++)
        {
            if (query.next())
            { // condition is true if user exists
                t[i].setBookingId(query.value(0).toInt());
                t[i].setName(query.value(2).toString());
                t[i].setDate(query.value(3).toString());
                t[i].setTime(query.value(4).toString());
                t[i].setSeatNo(query.value(5).toString());
                t[i].setPrice(query.value(6).toInt());
                t[i].setTotalPrice(query.value(7).toInt());
            }
        }
    }

    else
    {
        qDebug() << "FAILED LOADING BUS TICKETS";
    }

    return tktCnt;
}

bool database::changePassword(int id, QString pw)
{
    QSqlQuery qry;
    qry.prepare("UPDATE users set password = '" + pw + "' where id = :id");
    qry.bindValue(":id", id);

    if (qry.exec())
        return true;
    else
        return false;
}

bool database::editProfile(int id, QString name, QString lname, QString phone)
{
    QSqlQuery qry;
    qry.prepare("UPDATE users set firstname = '" + name + "', lastname = '" + lname + "', phone = '" + phone + "' where id = :id");
    qry.bindValue(":id", id);

    if (qry.exec())
        return true;
    else
        return false;
}

bool database::deductMoney(int id, int balance)
{
    QSqlQuery qry;
    qry.prepare("UPDATE users set balance = :balance where id = :id");
    qry.bindValue(":id", id);
    qry.bindValue(":balance", balance);
    if (qry.exec())
        return true;
    else
        return false;
}

int database::insertBooking(int id, QString bname, QString from, QString to, QString s, QString date, QString time, int price, int total)
{
    qDebug() << id << bname << from << to << date << time << price << total;
    QSqlQuery qry;
    qry.prepare("INSERT INTO `testdb`.`bookings` (`userid`, `Name`, `From`, `To`, `Seats`, `Time`, `Date`, `Price`, `Total`) VALUES (:id, '" + bname + "', '" + from + "', '" + to + "', '" + s + "' , '" + time + "', '" + date + "', :price, :total)");
    qry.bindValue(":id", id);
    qry.bindValue(":price", price);
    qry.bindValue(":total", total);
    if (qry.exec())
    {
        qDebug() << "Booking Success";
    }
    else
    {
        qDebug() << "Booking Failed";
    }
}

bool database::insertBookingMovies(int id, QString mname, QString s, QString date, QString time, int price, int total)
{
    qDebug() << id << mname << date << time << s << price << total;
    QSqlQuery qry;
    qry.prepare("INSERT INTO `testdb`.`bookingsmovies` (`userid`, `Name`, `Date`, `Time`, `Seats`, `Price`, `Total`) VALUES (:id, '" + mname + "', '" + date + "' , '" + time + "', '" + s + "', :price, :total)");
    qry.bindValue(":id", id);
    qry.bindValue(":price", price);
    qry.bindValue(":total", total);
    if (qry.exec())
    {
        qDebug() << "Booking Success";
    }
    else
    {
        qDebug() << "Booking Failed";
    }
}

int database::getBookingId(int tno, int id, QString s)
{
    QSqlQuery qry;
    if (tno == 1)
    {
        qry.prepare("SELECT id FROM bookings WHERE userid = :id AND Seats = '" + s + "'");
    }
    else if (tno == 2)
    {
        qry.prepare("SELECT id FROM bookingsmovies WHERE userid = :id AND Seats = '" + s + "'");
    }

    qry.bindValue(":id", id);
    qry.exec();
    int bid = 0;
    while (qry.next())
    {
        bid = qry.value(0).toInt();
    }
    return bid;
}
