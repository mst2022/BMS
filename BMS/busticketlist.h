#ifndef BUSTICKETLIST_H
#define BUSTICKETLIST_H
#include <QString>
#include "bus.h"

class busTicketList:public bus
{
private:
    int bookingId;
    QString seatNo;
    int totalPrice;
public:
    busTicketList();
    void setBookingId(int id){
        bookingId = id;
    }
    void setSeatNo(QString s){
        seatNo = s;
    }
    void setTotalPrice(int t){
        totalPrice = t;
    }

    int getBookingId(){
        return bookingId;
    }
    QString getSeatNo(){
        return seatNo;
    }
    int getTotal(){
        return totalPrice;
    }
};

#endif // BUSTICKETLIST_H
