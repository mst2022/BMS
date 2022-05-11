#include "movie.h"

movie::movie()
{
name =""; date =""; time = ""; price = 0; movieId = 0;
}
movie::movie(int id, QString n, QString d, QString ti, int p){
    movieId = id;
    name = n;
    date = d;
    time = ti;
    price = p;
}
