#include"mainwindow.h"

void MainWindow::myBookings(QWidget *parentW, QStackedWidget *pages)
{
    qDebug()<<"my bookings";
    QWidget *bookings = new QWidget(parentW);

    pages->addWidget(bookings);
    pages->setCurrentIndex(2);

    QVBoxLayout *myBookingsLayout = new QVBoxLayout();
    QLabel *bookinglab = new QLabel(bookings);

    bookinglab->setText("My Bookings");
    bookinglab->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    bookinglab->setFont(font);
    bookinglab->setMaximumHeight(100);

    QLabel *bookedBusL = new QLabel(bookings);

    bookedBusL->setText("Bus");
    QFont font1("Sitka",20,QFont::Bold);
    bookedBusL->setFont(font);
    bookedBusL->setMaximumHeight(80);

    QLabel *bookedMovL = new QLabel(bookings);

    bookedMovL->setText("Movie");
    bookedMovL->setFont(font);
    bookedMovL->setMaximumHeight(80);




//    BOOKED BUS TABLE
//    bookedBus = new QTableWidget(bookings);
//    bookedBus->setStyleSheet("QHeaderView::section {background-color:#31bc86; border: none} QTableWidget{color: #454545; background-color:#ffffff; alternate-background-color:#e9eef5; selection-background-color:#cce3ff;selection-color: #03851a; border-radius: 15%; font-family:Artifakt Element; font-size:16px;}");
//    //table properties
//    bookedBus->setAlternatingRowColors(true);
//    bookedBus->setSelectionBehavior(QAbstractItemView::SelectRows);

//    bookedBus->setColumnCount(8);
//    bookedBus->setCornerButtonEnabled(false);
//    // horizontal header(name, from, to, ...)
//    bookedBus->horizontalHeader()->setVisible(true);
//    bookedBus->horizontalHeader()->setDefaultSectionSize(128);
//    bookedBus->horizontalHeader()->setStyleSheet("*{color:white ;font-family: Artifakt Element; font-size: 16px; font-weight:bold}");
//    bookedBus->horizontalHeader()->setStretchLastSection(true);\
//    bookedBus->horizontalHeader()->setFixedHeight(44);
//    //hides vertical headers (indexing)
//    bookedBus->verticalHeader()->setVisible(false);

//    //makes text in cells non editable by the user
//    bookedBus->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    QStringList hLabels;
//    hLabels<<"Booking Id"<<"Bus Name" <<"From-To"<<"Date"<<"Departure Time"<<"Seats"<<"Price"<<"Total";
//    bookedBus->setHorizontalHeaderLabels(hLabels);




    //    BOOKED MOVIES TABLE
        QTableWidget *bookedBus = new QTableWidget(bookings);
        bookedBus->setStyleSheet("QHeaderView::section {background-color:#31bc86; border: none} QTableWidget{color: #454545; background-color:#ffffff; alternate-background-color:#e9eef5; selection-background-color:#cce3ff;selection-color: #03851a; border-radius: 15%; font-family:Artifakt Element; font-size:16px;}");
        //table properties
        bookedBus->setAlternatingRowColors(true);
        bookedBus->setSelectionBehavior(QAbstractItemView::SelectRows);

        bookedBus->setColumnCount(8);
        bookedBus->setCornerButtonEnabled(false);
        // horizontal header(name, date, time, ...)
        bookedBus->horizontalHeader()->setVisible(true);
        bookedBus->horizontalHeader()->setDefaultSectionSize(128);
        bookedBus->horizontalHeader()->setStyleSheet("*{color:white ;font-family: Artifakt Element; font-size: 16px; font-weight:bold}");
        bookedBus->horizontalHeader()->setStretchLastSection(true);\
        bookedBus->horizontalHeader()->setFixedHeight(44);
        //hides vertical headers (indexing)
        bookedBus->verticalHeader()->setVisible(false);

        //makes text in cells non editable by the user
        bookedBus->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QStringList hLabels;
        hLabels<<"Booking Id"<<"Bus Name" <<"From-To"<<"Date"<<"Departure Time"<<"Seats"<<"Price"<<"Total";
        bookedBus->setHorizontalHeaderLabels(hLabels);

        busTickets = new busTicketList[50];

        int  bticketCnt = db.fillBusTickets(busTickets, user.getUserId());
        bookedBus->setRowCount(bticketCnt);

        for(int i = 0; i<bticketCnt;i++){
            QTableWidgetItem *bookingId = new QTableWidgetItem(QString::number(busTickets[i].getBookingId()));
            QTableWidgetItem *busName = new QTableWidgetItem(busTickets[i].getName());
            QTableWidgetItem *busFromTo = new QTableWidgetItem(busTickets[i].getFrom() + " - " + busTickets[i].getTo());
            QTableWidgetItem *busDate = new QTableWidgetItem(busTickets[i].getDate());
            QTableWidgetItem *busTime = new QTableWidgetItem(busTickets[i].getTime());
            QTableWidgetItem *busSeats = new QTableWidgetItem(busTickets[i].getSeatNo());
            QTableWidgetItem *price = new QTableWidgetItem(QString::number(busTickets[i].getPrice()));
            QTableWidgetItem *totalPrice = new QTableWidgetItem(QString::number(busTickets[i].getTotal()));
            bookedBus->setItem(i,0,bookingId);
            bookedBus->setItem(i,1,busName);
            bookedBus->setItem(i,2,busFromTo);
            bookedBus->setItem(i, 3, busDate);
            bookedBus->setItem(i,4,busTime);
            bookedBus->setItem(i,5,busSeats);
            bookedBus->setItem(i,6,price);
            bookedBus->setItem(i,7,totalPrice);
            bookedBus->setRowHeight(i, 44);
        }







    //    BOOKED MOVIES TABLE
        QTableWidget *bookedMov = new QTableWidget(bookings);
        bookedMov->setStyleSheet("QHeaderView::section {background-color:#31bc86; border: none} QTableWidget{color: #454545; background-color:#ffffff; alternate-background-color:#e9eef5; selection-background-color:#cce3ff;selection-color: #03851a; border-radius: 15%; font-family:Artifakt Element; font-size:16px;}");
        //table properties
        bookedMov->setAlternatingRowColors(true);
        bookedMov->setSelectionBehavior(QAbstractItemView::SelectRows);

        bookedMov->setColumnCount(7);
        bookedMov->setCornerButtonEnabled(false);
        // horizontal header(name, date, time, ...)
        bookedMov->horizontalHeader()->setVisible(true);
        bookedMov->horizontalHeader()->setDefaultSectionSize(140);
        bookedMov->horizontalHeader()->setStyleSheet("*{color:white ;font-family: Artifakt Element; font-size: 16px; font-weight:bold}");
        bookedMov->horizontalHeader()->setStretchLastSection(true);\
        bookedMov->horizontalHeader()->setFixedHeight(44);
        //hides vertical headers (indexing)
        bookedMov->verticalHeader()->setVisible(false);

        //makes text in cells non editable by the user
        bookedMov->setEditTriggers(QAbstractItemView::NoEditTriggers);

        QStringList hLabelsMove;
        hLabelsMove<<"Booking Id"<<"Movie Name" <<"Date"<<"Show Time"<<"Seats"<<"Price"<<"Total";
        bookedMov->setHorizontalHeaderLabels(hLabelsMove);

        movieTickets = new busTicketList[50];

        int  mticketCnt = db.fillMovieTickets(movieTickets, user.getUserId());
        qDebug()<<"Ticket count movie"<<mticketCnt;
        bookedMov->setRowCount(mticketCnt);

        for(int i = 0; i<mticketCnt;i++){
            QTableWidgetItem *bookingId = new QTableWidgetItem(QString::number(movieTickets[i].getBookingId()));
            QTableWidgetItem *busName = new QTableWidgetItem(movieTickets[i].getName());
            QTableWidgetItem *busDate = new QTableWidgetItem(movieTickets[i].getDate());
            QTableWidgetItem *busTime = new QTableWidgetItem(movieTickets[i].getTime());
            QTableWidgetItem *busSeats = new QTableWidgetItem(movieTickets[i].getSeatNo());
            QTableWidgetItem *price = new QTableWidgetItem(QString::number(movieTickets[i].getPrice()));
            QTableWidgetItem *totalPrice = new QTableWidgetItem(QString::number(movieTickets[i].getTotal()));
            bookedMov->setItem(i,0,bookingId);
            bookedMov->setItem(i,1,busName);
            bookedMov->setItem(i, 2, busDate);
            bookedMov->setItem(i,3,busTime);
            bookedMov->setItem(i,4,busSeats);
            bookedMov->setItem(i,5,price);
            bookedMov->setItem(i,6,totalPrice);
            bookedMov->setRowHeight(i, 44);
        }




    myBookingsLayout->addWidget(bookinglab,1);
    myBookingsLayout->addWidget(bookedBusL,1);
    myBookingsLayout->addWidget(bookedBus,4);
    myBookingsLayout->addWidget(bookedMovL,1);
    myBookingsLayout->addWidget(bookedMov,3);
    bookings->setLayout(myBookingsLayout);

}


