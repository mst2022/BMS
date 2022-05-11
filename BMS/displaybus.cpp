
#include "mainwindow.h"

void MainWindow::displayBus(bus *b, QStackedWidget *bookingPages, int index){
    int busFare = b[index].getPrice();
    total = 0;
    int totalAvailableSeats = b[index].getTotalAvailableSeats();
    QWidget *displayBusWidget = new QWidget();
    bookingPages->addWidget(displayBusWidget);
    bookingPages->setCurrentIndex(currentIndex);

    QWidget *topWidget = new QWidget(displayBusWidget);
    topWidget->setStyleSheet("*{ border-radius: 15%}");
    QHBoxLayout *topLayout = new QHBoxLayout();
    QPushButton *backButton = new QPushButton(topWidget);
    backButton->setStyleSheet("QPushButton{border: none; padding-right:45px} QPushButton:hover{padding-right:70px}");
    backButton->setCursor(Qt::PointingHandCursor);
    QPixmap a(":/images/back-button.png");
    QIcon arrow(a);
    backButton->setIcon(a);
    backButton->setIconSize(QSize(25,25));

    connect( backButton, &QPushButton::clicked, [=](){
        bookingPages->removeWidget(displayBusWidget);
        for(int i=0;i<17;i++){

            totalSelected[i] = false;

        }

        delete displayBusWidget;
       bookingPages->setCurrentIndex(1);
    });

    QLabel *bookBusLabel = new QLabel(displayBusWidget);
    bookBusLabel->setText("Book Bus ticket");
    bookBusLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    bookBusLabel->setFont(font);
    bookBusLabel->setMaximumHeight(100);
    bookBusLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(bookBusLabel, 9);
    topWidget->setLayout(topLayout);


        QVBoxLayout *outer = new QVBoxLayout();
        outer->addWidget(topWidget,1);

            QHBoxLayout *layout = new QHBoxLayout(displayBusWidget);
            QWidget *outerWidget1 = new QWidget();
            outerWidget1->setStyleSheet("*{font-family:Artifakt Element; font-weight: bold; font-size: 16px; background-color:#4bb1fa; border-radius:12%}");
            outerWidget1->setFixedHeight(70);

            QLabel *label1 = new QLabel(outerWidget1);
              label1->setText("Operator(Bus Type)");

            QLabel *label2 = new QLabel(outerWidget1);
                    label2->setText("Dep. Time");

             QLabel *label3 = new QLabel(outerWidget1);
                       label3->setText("Seat Available");

                   QLabel *label4 = new QLabel(outerWidget1);
                          label4->setText("Fare");

                       layout->addWidget(label1);
                       layout->addWidget(label2);
                       layout->addWidget(label3);
                       layout->addWidget(label4);

                       outerWidget1->setLayout(layout);
                       outer->addWidget(outerWidget1,1);
                       outerWidget1->show();

                       // Second Horizontal layout
                       QHBoxLayout *layout2 = new QHBoxLayout(displayBusWidget);
                       QWidget *outerWidget2 = new QWidget();
                       outerWidget2->setStyleSheet("*{font-family:Artifakt Element; font-weight: bold; font-size: 16px; background-color:#c3c7c7; border-radius:12%}");
    outerWidget2->setFixedHeight(70);
                       QLabel *label5 = new QLabel(outerWidget2);

                         label5->setText(b[index].getName() + "\n" + b[index].getFrom() + "-" + b[index].getTo());
//label5->setStyleSheet("*{font-weight:bold;}");
                       QLabel *label6 = new QLabel(outerWidget2);
                               label6->setText(b[index].getTime());

                        QLabel *label7 = new QLabel(outerWidget2);
                                  label7->setText(QString::number(totalAvailableSeats));

                              QLabel *label8 = new QLabel(outerWidget2);
                                     label8->setText(QString::number(busFare));

                                  layout2->addWidget(label5);
                                  layout2->addWidget(label6);
                                  layout2->addWidget(label7);
                                  layout2->addWidget(label8);

                                  outerWidget2->setLayout(layout2);


                                 //Third  horizontal layout





                                   QWidget *outerWidget = new QWidget();
                                   QHBoxLayout *layout3 = new QHBoxLayout(outerWidget);

                                   outerWidget->setLayout(layout3);


                                   QWidget *outerWidget3 = new QWidget();
                                   outerWidget3->setStyleSheet("*{font-family:Artifakt Element; font-size: 16px;}");
                                   QVBoxLayout *layout5 = new QVBoxLayout(outerWidget3);



                                   QWidget *outerWidget4 = new QWidget();
                                   QHBoxLayout *layout4 = new QHBoxLayout(outerWidget4);


                                   QLabel *label9 = new QLabel(outerWidget4);
                                   label9->setText("               ");
                                   label9->setFixedSize(45,30);
                                   label9->setStyleSheet("*{background-color:silver;}");
                                   QLabel *label10 = new QLabel(outerWidget4);
                                   label10->setText("Available Seat(s)");
                                   QLabel *label11 = new QLabel(outerWidget4);
                                   label11->setText("               ");
                                   label11->setFixedSize(45,30);
                                   label11->setStyleSheet("*{background-color:#ed1f1f;}");
                                   QLabel *label12 = new QLabel(outerWidget4);
                                   label12->setText("Booked Seat(s)");
                                   QLabel *label13 = new QLabel(outerWidget4);
                                   label13->setText("                 ");
                                   label13->setFixedSize(45,30);

                                   label13->setStyleSheet("*{background-color:#354ef2;height:20px}");
                                   QLabel *label14 = new QLabel(outerWidget4);
                                   label14->setText("Selected Seat(s)");

                                   layout4->addWidget(label9);
                                   layout4->addWidget(label10);
                                   layout4->addWidget(label11);
                                   layout4->addWidget(label12);
                                   layout4->addWidget(label13);
                                   layout4->addWidget(label14);


                                   //button widget

                                   outerWidget3->setLayout(layout5);


                                   //Grid Button
                                   QWidget *gridWidget = new QWidget();
                                   gridWidget->setStyleSheet("QPushButton{border-radius: 8%; background-color: silver}");
                                   QGridLayout *gridLayout = new QGridLayout(gridWidget);
                                         gridLayout->setHorizontalSpacing(5);
                                         b1 = new QPushButton("A1");
                                         b1->setFixedSize(50,45);

                                         if(b[index].seats[0]){
                                             bookedSeat(b1);
                                         }
                                         else b1->setCursor(Qt::PointingHandCursor);

                                         b2 = new QPushButton("A2");
                                         b2->setFixedSize(50,45);

                                         if(b[index].seats[1]){
                                             bookedSeat(b2);
                                         }
                                         else b2->setCursor(Qt::PointingHandCursor);


                                         b3 = new QPushButton("A3");
                                         b3->setFixedSize(50,45);

                                         if(b[index].seats[2]){
                                             bookedSeat(b3);
                                         }
                                         else b3->setCursor(Qt::PointingHandCursor);

                                         b4 = new QPushButton("A4");
                                         b4->setFixedSize(50,45);
                                         if(b[index].seats[3]){
                                             bookedSeat(b4);
                                         }
                                         else b4->setCursor(Qt::PointingHandCursor);

                                         b5 = new QPushButton("B1");
                                         b5->setFixedSize(50,45);
                                         if(b[index].seats[4]){
                                             bookedSeat(b5);
                                         }
                                         else b5->setCursor(Qt::PointingHandCursor);

                                         b6 = new QPushButton("B2");
                                         b6->setFixedSize(50,45);
                                         if(b[index].seats[5]){
                                             bookedSeat(b6);
                                         }
                                         else b6->setCursor(Qt::PointingHandCursor);

                                         b7 = new QPushButton("B3");
                                         b7->setFixedSize(50,45);
                                         if(b[index].seats[6]){
                                             bookedSeat(b7);
                                         }
                                         else b7->setCursor(Qt::PointingHandCursor);

                                         b8 = new QPushButton("B4");
                                         b8->setFixedSize(50,45);
                                         if(b[index].seats[7]){
                                             bookedSeat(b8);
                                         }
                                         else b8->setCursor(Qt::PointingHandCursor);

                                         b9 = new QPushButton("C1");
                                         b9->setFixedSize(50,45);
                                         if(b[index].seats[8]){
                                             bookedSeat(b9);
                                         }
                                         else b9->setCursor(Qt::PointingHandCursor);

                                         b10 = new QPushButton("C2");
                                         b10->setFixedSize(50,45);
                                         if(b[index].seats[9]){
                                             bookedSeat(b10);
                                         }
                                         else b10->setCursor(Qt::PointingHandCursor);



                                         b11 = new QPushButton("C3");
                                         b11->setFixedSize(50,45);
                                         if(b[index].seats[10]){
                                             bookedSeat(b11);
                                         }
                                         else b11->setCursor(Qt::PointingHandCursor);


                                         b12 = new QPushButton("C4");
                                         b12->setFixedSize(50,45);
                                         if(b[index].seats[11]){
                                             bookedSeat(b12);
                                         }
                                         else b12->setCursor(Qt::PointingHandCursor);

                                         b13 = new QPushButton("D1");
                                         b13->setFixedSize(50,45);
                                         if(b[index].seats[12]){
                                             bookedSeat(b13);
                                         }
                                         else b13->setCursor(Qt::PointingHandCursor);

                                         b14 = new QPushButton("D2");
                                         b14->setFixedSize(50,45);
                                         if(b[index].seats[13]){
                                             bookedSeat(b14);
                                         }
                                         else b14->setCursor(Qt::PointingHandCursor);

                                         b15 = new QPushButton("D3");
                                         b15->setFixedSize(50,45);
                                         if(b[index].seats[14]){
                                             bookedSeat(b15);
                                         }
                                         else b15->setCursor(Qt::PointingHandCursor);

                                         b16 = new QPushButton("D4");
                                         b16->setFixedSize(50,45);
                                         if(b[index].seats[15]){
                                             bookedSeat(b16);
                                         }
                                         else b16->setCursor(Qt::PointingHandCursor);


                                         b17 = new QPushButton("D5");
                                         b17->setFixedSize(50,45);
                                         if(b[index].seats[16]){
                                             bookedSeat(b17);
                                         }
                                         else b17->setCursor(Qt::PointingHandCursor);


                                       gridLayout->addWidget(b1,0,0,1,1);
                                       gridLayout->addWidget(b2,0,1,1,1);
                                       gridLayout->addWidget(b3,0,3,1,1);
                                       gridLayout->addWidget(b4,0,4,1,1);

                                       gridLayout->addWidget(b5,1,0,1,1);
                                       gridLayout->addWidget(b6,1,1,1,1);
                                       gridLayout->addWidget(b7,1,3,1,1);
                                       gridLayout->addWidget(b8,1,4,1,1);



                                       gridLayout->addWidget(b9,2,0,1,1);
                                       gridLayout->addWidget(b10,2,1,1,1);
                                       gridLayout->addWidget(b11,2,3,1,1);
                                       gridLayout->addWidget(b12,2,4,1,1);

                                       gridLayout->addWidget(b13,3,0,1,1);
                                       gridLayout->addWidget(b14,3,1,1,1);
                                       gridLayout->addWidget(b15,3,2,1,1);
                                       gridLayout->addWidget(b16,3,3,1,1);
                                       gridLayout->addWidget(b17,3,4,1,1);

                                   layout5->addWidget(outerWidget4);

                                   layout5->addWidget(gridWidget);

                                   layout3->addWidget(outerWidget3,5);


                                    QWidget *selectedWidgets = new QWidget();
                                    selectedWidgets->setStyleSheet("*{font-weight: bold; font-family:Artifakt Element; font-size: 18px; border: 1px solid grey; border-radius: 10px}");
                                    QVBoxLayout *selectedVboxLayout = new QVBoxLayout(selectedWidgets);


                                    QWidget *selectedHboxWidgets = new QWidget();
                                    selectedHboxWidgets->setStyleSheet("*{border:none}");
                                    selectedHboxWidgets->setFixedHeight(140);
                                    QHBoxLayout *selectedSeats = new QHBoxLayout(selectedHboxWidgets);

                                    layout3->addWidget(selectedWidgets,5);

                                    QLabel *select = new QLabel("Selected seats");

                                    QWidget *totalWidget = new QWidget();
                                    totalWidget->setStyleSheet("*{border:none}");
                                    totalWidget->setFixedHeight(70);
                                    QHBoxLayout *totalLayout = new QHBoxLayout(totalWidget);
                                    QLabel *totalStr = new QLabel("Total");
                                    totalAmt = new QLabel("Rs. 0");

                                    //checkout button
                                    QPushButton *checkOut = new QPushButton("Check Out");
                                    checkOut->setCursor(Qt::PointingHandCursor);
                                    checkOut->setStyleSheet("QPushButton{color:white; background:#07b507 ;border:1px solid #07b507; border-radius:5%; font-size:22px; font-weight:bold; font-family:Artifakt Element;} :hover{color:white; background:#088a08}");
                                    checkOut->setFixedHeight(45);
                                    if(totalAvailableSeats == 0){
                                        checkOut->setStyleSheet("*{background-color: #c8cfca; color: white}");
                                        checkOut->setDisabled(true);
                                        select->setText("Sorry, All seats are <br> booked.");
                                        totalStr->setText("");
                                        totalAmt->setText("");
                                    }
                                    connect(checkOut,&QPushButton::clicked,[=](){
                                       qDebug() << "Total is" << total;

                                       if(total>user.getBalance()){
                                           QMessageBox msgBox;
                                           msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                                           msgBox.setWindowTitle("Error");
                                           msgBox.setText("Insufficient Balance");
                                           msgBox.setStandardButtons(QMessageBox::Ok);
                                           msgBox.exec();
                                       }
                                       else{
                                           //confirm bookin dialog box
                                           QString s ="";
                                           int i = 0;
                                           while(selectedSeatsNums[i] != ""){
                                               s+=""+selectedSeatsNums[i]+" ";
                                               i++;
                                           }

                                           QMessageBox msgBox;
                                           msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                                           msgBox.setDefaultButton(QMessageBox::No);
                                           //if no seats are selected bus detailes are not shown
                                           if(total==0) {
                                                msgBox.setText("No seats selected. <br>Please select a seat to book.");
                                           }
                                           else{
                                               msgBox.setWindowTitle("Confirm Booking");
                                               msgBox.setText("Are you sure you want to book the bus ticket?.");
                                               msgBox.setInformativeText("Booking Details: <br> "+b[index].getName()+" <br> "+b[index].getFrom()+"-"+b[index].getTo()+" <br> "+b[index].getDate()+" <br> "+s+" <br> Rs. "+QString::number(total)+"");
                                               msgBox.setStandardButtons(QMessageBox::No |QMessageBox::Yes);
                                           }



                                           int ans = msgBox.exec();
                                           if(ans == QMessageBox::Yes) {

                                               if(db.bookSeats(1, b[index].getBusId(),selectedSeatsNums)){
                                                   qDebug()<<"seats updated";


                                                   int leftBalance = user.getBalance()-total;
                                                   db.fillBus(b);
                                                   user.setBalance(leftBalance);
                                                   db.deductMoney(user.getUserId(), leftBalance);
                                                   db.insertBooking(user.getUserId(), b[index].getName(), b[index].getFrom(), b[index].getTo(),s,b[index].getDate(),b[index].getTime(), b[index].getPrice(), total);
                                                   for(int i=0;i<17;i++){

                                                   totalSelected[i] = false;


                                                   }
                                                   int bid = db.getBookingId(1, user.getUserId(), s);
                                                   qDebug() << s;
                                                   qDebug()<<"Booking id is "<<bid;
                                                   emailCheckout(bid, b[index],total, s);
                                                   balance->setText("Rs. "+QString::number(leftBalance));
                                                   bookingPages->removeWidget(displayBusWidget);
                                                   delete displayBusWidget;
                                                   bookingPages->setCurrentIndex(0);
                                               }

                                               else {
                                                   qDebug()<<"failed seats update";
                                               }
                                           }
                                           else if(ans == QMessageBox::No){

                                           }

                                       }
                                        });

                                    totalLayout->addWidget(totalStr);
                                    totalLayout->addWidget(totalAmt);

                                    selectSeats = new QLabel("");
                                    selectSeats->setFixedWidth(200);
                                    selectSeats->setWordWrap(true);
                                    selectedSeats->addWidget(select);
                                    selectedSeats->addWidget(selectSeats);

                                    selectedVboxLayout->addWidget(selectedHboxWidgets);
                                    selectedVboxLayout->addWidget(totalWidget);
                                    selectedVboxLayout->addWidget(checkOut);
                                   outer->addWidget(outerWidget2,1);
                                   outer->addWidget(outerWidget,7);

            displayBusWidget->setLayout(outer);

    displayBusWidget->show();

    connect(b1,&QPushButton::clicked,[=](){

        if(totalSelected[0]){
             b1->setStyleSheet("*{background-color:silver}");
    totalSelected[0]=false;
    total-=busFare;
    changeSeats();
        }
        else{
             b1->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[0]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b2,&QPushButton::clicked,[=](){

        if(totalSelected[1]){
             b2->setStyleSheet("*{background-color:silver}");
    totalSelected[1]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b2->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[1]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b3,&QPushButton::clicked,[=](){

        if(totalSelected[2]){
             b3->setStyleSheet("*{background-color:silver}");
    totalSelected[2]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b3->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[2]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b4,&QPushButton::clicked,[=](){

        if(totalSelected[3]){
             b4->setStyleSheet("*{background-color:silver}");
    totalSelected[3]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b4->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[3]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b5,&QPushButton::clicked,[=](){

        if(totalSelected[4]){
             b5->setStyleSheet("*{background-color:silver}");
    totalSelected[4]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b5->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[4]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b6,&QPushButton::clicked,[=](){

        if(totalSelected[5]){
             b6->setStyleSheet("*{background-color:silver}");
    totalSelected[5]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b6->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[5]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b7,&QPushButton::clicked,[=](){

        if(totalSelected[6]){
             b7->setStyleSheet("*{background-color:silver}");
    totalSelected[6]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b7->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[6]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b8,&QPushButton::clicked,[=](){

        if(totalSelected[7]){
             b8->setStyleSheet("*{background-color:silver}");
    totalSelected[7]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b8->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[7]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b9,&QPushButton::clicked,[=](){

        if(totalSelected[8]){
             b9->setStyleSheet("*{background-color:silver}");
    totalSelected[8]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b9->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[8]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b10,&QPushButton::clicked,[=](){

        if(totalSelected[9]){
             b10->setStyleSheet("*{background-color:silver}");
    totalSelected[9]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b10->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[9]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b11,&QPushButton::clicked,[=](){

        if(totalSelected[10]){
             b11->setStyleSheet("*{background-color:silver}");
    totalSelected[10]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b11->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[10]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b12,&QPushButton::clicked,[=](){

        if(totalSelected[11]){
             b12->setStyleSheet("*{background-color:silver}");
    totalSelected[11]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b12->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[11]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b13,&QPushButton::clicked,[=](){

        if(totalSelected[12]){
             b13->setStyleSheet("*{background-color:silver}");
    totalSelected[12]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b13->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[12]=true;
        total+=busFare;
        changeSeats();
        }
    });



    connect(b14,&QPushButton::clicked,[=](){

        if(totalSelected[13]){
             b14->setStyleSheet("*{background-color:silver}");
    totalSelected[13]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b14->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[13]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b15,&QPushButton::clicked,[=](){

        if(totalSelected[14]){
             b15->setStyleSheet("*{background-color:silver}");
    totalSelected[14]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b15->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[14]=true;
        total+=busFare;
        changeSeats();
        }
    });


    connect(b16,&QPushButton::clicked,[=](){

        if(totalSelected[15]){
             b16->setStyleSheet("*{background-color:silver}");
    totalSelected[15]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b16->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[15]=true;
        total+=busFare;
        changeSeats();
        }
    });

    connect(b17,&QPushButton::clicked,[=](){

        if(totalSelected[16]){
             b17->setStyleSheet("*{background-color:silver}");
    totalSelected[16]=false;
    total-=busFare;
    changeSeats();
        }
        else{
        b17->setStyleSheet("*{background-color:#354ef2; color: white}");
        totalSelected[16]=true;
        total+=busFare;
        changeSeats();
        }
    });


    }


