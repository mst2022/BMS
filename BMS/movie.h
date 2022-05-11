#ifndef MOVIE_H
#define MOVIE_H
#include <QString>

class movie
{
    int movieId;
    QString name;
    QString date;
    QString time;
    int price;
    QString desc;

public:
    bool seats[17];
    movie();
    movie(int id, QString n, QString d, QString ti, int p);
    void setMovieId(int id) {movieId = id;}
    void setName(QString n){name = n;}
    void setDate(QString d){date = d;}
    void setTime(QString t) {time = t;}
    void setPrice(int p) {price = p;}
    void setDesc(QString d) {desc = d;}

    int getMovieId() {return movieId;}
    QString getName(){return name;}
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

#endif // MOVIE_H
