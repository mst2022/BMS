#ifndef BUS_H
#define BUS_H
#include<QString>


class bus
{
private:
    QString desc;
protected:
    int busId;
    QString name;
    QString from;
    QString to;
    QString date;
    QString time;
    int price;


public:
    bool seats[17];
    bus();
    bus(int busId, QString n, QString f, QString t, QString d, QString ti, int p);
    void setBusId(int id) {busId = id;}
    void setName(QString n){name = n;}
    void setFrom(QString f) {from = f;}
    void setTo(QString t){to = t;}
    void setDate(QString d){date = d;}
    void setTime(QString t) {time = t;}
    void setPrice(int p) {price = p;}
    void setDesc(QString d) {desc = d;}

    int getBusId() {return busId;}
    QString getName(){return name;}
    QString getFrom(){return from;}
    QString getTo(){return to;}
    QString getDate(){return date;}
    QString getTime(){return time;}
    QString getDesc(){return desc;}
    int getPrice(){return price;}
    int getTotalAvailableSeats(){
        int cnt = 0;
        for(int i = 0; i<17; i++){
            if(!seats[i]) cnt++;
        }
        return cnt;
    }

};

#endif // BUS_H
