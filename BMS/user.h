#ifndef USER_H
#define USER_H
#include <QString>


class User{
    int userId;
    QString fName;
    QString lName;
    int balance;
    QString email;
    QString phone;
    QString password;
    int isAdmin;
    QString joinedDate;
public:
    User(){}
    User(int id, QString fn, QString ln, int b, QString e, QString p, int a);
    QString getFName(){return fName;}
    QString getLName(){return lName;}
    int getBalance(){return balance;}
    QString getEmail(){return email;}
    QString getPhone(){return phone;}
    QString getPassword(){return password;}
    int getAdminStatus(){return isAdmin;}
    int getUserId(){return userId;}
    QString getJoinedDate(){return joinedDate;}
    void setFName(QString fn){fName = fn;}
    void setLName(QString ln){lName = ln;}
    void setEmail(QString em){email = em;}
    void setPhoneNo(QString pn){phone = pn;}
    void setBalance(int b){balance = b;}
    void setAdminStatus(int a) {isAdmin = a;}
    void setPassword(QString p){password = p;}
    void setUserId(int id){userId = id;}
    void setJoinedDate(QString date){joinedDate = date;}
};

#endif // USER_H
