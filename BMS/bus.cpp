#include "bus.h"

bus::bus()
{
name =""; from = ""; to = "";date =""; time = ""; price = 0; busId = 0;
}
bus::bus(int id, QString n, QString f, QString t, QString d, QString ti, int p){
    busId = id;
    name = n;
    from = f;
    to = t;
    date = d;
    time = ti;
    price = p;
}
