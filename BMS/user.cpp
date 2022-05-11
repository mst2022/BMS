#include "user.h"

User::User(int id, QString fn, QString ln, int b, QString e, QString p, int a = 0){
    userId = id;
    fName = fn;
    lName = ln;
    balance = b;
    email = e;
    phone = p;
    isAdmin = a;
}
