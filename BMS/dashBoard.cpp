#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QIcon>

void MainWindow::dashBoard(){
    //main dashboard widget
       QWidget *window = new QWidget(this);
       setCentralWidget(window);
       window->setStyleSheet("*{background:white;}");
       QLabel *label = new QLabel(window);
       label->setText("test");

       //Horizontal layout in the main dashboard
       QHBoxLayout * dash = new QHBoxLayout();

       QWidget *rightWindowWidget =new QWidget(window); //right window widget


       QWidget *home = new QWidget(rightWindowWidget);
       QVBoxLayout *homeLayout = new QVBoxLayout;


       QWidget *homeTopW = new QWidget(home);
       homeTopW->setMaximumHeight(200);
       QHBoxLayout *homeTopLayout = new QHBoxLayout();
       QFont font("Sitka", 30);
       QLabel *userLabel = new QLabel(home);
       userLabel->setText("Hello, " + user.getFName());
       userLabel->setAlignment(Qt::AlignLeft);
       userLabel->setFont(font);
       balance = new QLabel(home);
       balance->setText("Rs. " + QString::number(user.getBalance()));
       balance->setAlignment(Qt::AlignRight);
       balance->setFont(font);


       homeTopLayout->addWidget(userLabel);
       homeTopLayout->addWidget(balance);

       homeTopW->setLayout(homeTopLayout);


       QStackedWidget *bookingPages = new QStackedWidget(home);
       QWidget *bookBusWidget = new QWidget(home);
       QWidget *bookFlightWidget = new QWidget(home);
       QWidget *bookMovieWidget = new QWidget(home);


       QWidget *bodyWidget = new QWidget(home);
       bodyWidget->setMaximumHeight(200);
       QGridLayout *bodyLayout = new QGridLayout();

       //************************* bus Book Button start *********************************
       QWidget *busBookButtonW = new QWidget(home);
       QVBoxLayout *busBookButtonLayout = new QVBoxLayout();
       busBookButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #25ec17, stop:1 #88f980); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
       busBookButtonW->setMaximumSize(225,125);
       QHBoxLayout *busBtnTopLayout = new QHBoxLayout();
       QWidget *busBtnTopW = new QWidget(busBookButtonW);

       QLabel *bus = new QLabel(busBookButtonW);
       bus->setText("Book Bus\nTicket");
       bus->setStyleSheet("*{font-size:20px;background-color:none}");

       QPushButton *bookBusBtn = new QPushButton(busBookButtonW);
       bookBusBtn->setCursor(Qt::PointingHandCursor);
       QPixmap a(":/images/arrow.png");
       QIcon arrow(a);
       bookBusBtn->setIcon(a);
       bookBusBtn->setIconSize(QSize(50,50));
       bookBusBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
       connect( bookBusBtn, &QPushButton::clicked, [=](){
          qDebug()<<"Bus BUtton clicked!";
          bookingPages->setCurrentIndex(1);

       });
       QLabel *busDisc = new QLabel(busBookButtonW);
       busDisc->setText("Book bus tickets to travel\n to your desired destination");

       busBtnTopLayout->addWidget(bus);
       busBtnTopLayout->addWidget(bookBusBtn);
       busBtnTopW->setLayout(busBtnTopLayout);



       busBookButtonLayout->addWidget(busBtnTopW);
       busBookButtonLayout->addWidget(busDisc);

       busBookButtonW->setLayout(busBookButtonLayout);
       //************************************* bus Book Button end *******************************



       // ************************************* movie book button start ******************************
       QWidget *movieBookButtonW = new QWidget(home);
       QVBoxLayout *movieBookButtonLayout = new QVBoxLayout();
       movieBookButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #b20cdf, stop:1 #bf96fb); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
       movieBookButtonW->setMaximumSize(225,125);
       QHBoxLayout *movieBtnTopLayout = new QHBoxLayout();
       QWidget *movieBtnTopW = new QWidget(movieBookButtonW);

       QLabel *movie = new QLabel(movieBookButtonW);
       movie->setText("Book Movie\nTicket");
       movie->setStyleSheet("*{font-size:20px;background-color:none}");

       QPushButton *bookMovieBtn = new QPushButton(movieBookButtonW);
       bookMovieBtn->setCursor(Qt::PointingHandCursor);
       bookMovieBtn->setIcon(a);
       bookMovieBtn->setIconSize(QSize(50,50));
       bookMovieBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
       connect( bookMovieBtn, &QPushButton::clicked, [=](){
          qDebug()<<"Movie BUtton clicked!";
          bookingPages->setCurrentIndex(3);

       });
       QLabel *movieDisc = new QLabel(movieBookButtonW);
       movieDisc->setText("Book movie tickets of\ncurrently showing movies");

       movieBtnTopLayout->addWidget(movie);
       movieBtnTopLayout->addWidget(bookMovieBtn);
       movieBtnTopW->setLayout(movieBtnTopLayout);



       movieBookButtonLayout->addWidget(movieBtnTopW);
       movieBookButtonLayout->addWidget(movieDisc);

       movieBookButtonW->setLayout(movieBookButtonLayout);
       // ********************************** movie book button end *********************************


       bodyLayout->addWidget(busBookButtonW, 0,1);
       bodyLayout->addWidget(movieBookButtonW, 0,2);

       //when buttons are clicked these widget are shown
       bookBus(bookBusWidget, bookingPages);
       bookMovie(bookMovieWidget, bookingPages);


       bookingPages->addWidget(bodyWidget);
       bookingPages->addWidget(bookBusWidget);
       bookingPages->addWidget(bookFlightWidget);
       bookingPages->addWidget(bookMovieWidget);

       bodyWidget->setLayout(bodyLayout);
       homeLayout->addWidget(homeTopW);
       homeLayout->addWidget(bookingPages);


       home->setLayout(homeLayout);



       QWidget *profile = new QWidget(rightWindowWidget);


       QStackedWidget *pages = new QStackedWidget(rightWindowWidget);
       pages->addWidget(home);
       pages->addWidget(profile);


       QWidget *leftWindowWidget = new QWidget(window); //left window widget
       leftWindowWidget->setStyleSheet("QPushButton{padding: 30px; font-size:20px; border:none; font-family: Artifakt Element} QPushButton:hover{color:red} *{border-right: 2px solid grey}");
       QVBoxLayout *nav = new QVBoxLayout();

       QLabel *logo = new QLabel(leftWindowWidget);
       logo->setStyleSheet("*{border: none}");
       QPixmap lo(":/images/BMSlogo.png");
       logo->setPixmap(lo.scaled(100,100));

       logo->setMaximumHeight(150);

       logo->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

      QPushButton *homeButton = new QPushButton("Home", leftWindowWidget);
      QPushButton *profileButton = new QPushButton("Profile",leftWindowWidget);
      QPushButton *myBookingsButton = new QPushButton("My Bookings",leftWindowWidget);
      QPushButton *aboutButton = new QPushButton("About",leftWindowWidget);
      setActiveTab(homeButton, profileButton, myBookingsButton, aboutButton);

      homeButton->setCursor(Qt::PointingHandCursor);
      connect( homeButton, &QPushButton::clicked, [=](){
         pages->setCurrentIndex(0);
         setActiveTab(homeButton, profileButton, myBookingsButton, aboutButton);
      });

      myProfile(profile, rightWindowWidget);

      profileButton->setCursor(Qt::PointingHandCursor);
      connect( profileButton, &QPushButton::clicked, [=](){
         pages->setCurrentIndex(1);         
         setActiveTab(profileButton, homeButton, myBookingsButton, aboutButton);
         profileBalance->setText(balance->text());
      });

      myBookingsButton->setCursor(Qt::PointingHandCursor);
      connect( myBookingsButton, &QPushButton::clicked, [=](){

         myBookings(rightWindowWidget, pages);
         setActiveTab(myBookingsButton, homeButton, profileButton, aboutButton);

      });


      QPushButton *logoutButton = new QPushButton("Logout",leftWindowWidget);
      logoutButton->setCursor(Qt::PointingHandCursor);

      connect( logoutButton, &QPushButton::clicked, [=](){
          QMessageBox msgBox;
          msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
          msgBox.setWindowTitle("Logout");
          msgBox.setText("You are about to be logged out.");
          msgBox.setInformativeText("Are you sure you want to logout?");

          msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
          msgBox.setDefaultButton(QMessageBox::Cancel);
          int ret = msgBox.exec();
          if(ret == QMessageBox::Yes){
              loginScreen();
          }


      });




      aboutButton->setCursor(Qt::PointingHandCursor);

      connect( aboutButton, &QPushButton::clicked, [=](){
//         pages->setCurrentIndex(3);
          setActiveTab( aboutButton, myBookingsButton, homeButton, profileButton);
         QMessageBox about;
         QPixmap logo(":/images/BMSlogo.png");
         about.setIconPixmap(logo.scaled(200,200));
         about.setStyleSheet("QLabel{max-width:400px; max-height:500px}");
         about.setWindowTitle("About BMS");
         about.setText("Booking Management System 1.0\nversion: 1.0 \nPrajwal Gaire\nShishir Raj Giri\nRohit Raj Karki\nMohit Shahi");
         about.setStandardButtons(QMessageBox::Close);
         about.exec();
      });

      nav->addWidget(logo);
      nav->addWidget(homeButton);
      nav->addWidget(profileButton);
      nav->addWidget(myBookingsButton);
      nav->addWidget(logoutButton);
      nav->addWidget(aboutButton);



//       leftWindowWidget->setFixedWidth(250);
       leftWindowWidget->setLayout(nav);
//       leftWindowWidget->setStyleSheet("*{border:2px solid black;}");

       dash->addWidget(leftWindowWidget,2);
       dash->addWidget(pages,8);
//       dash->addWidget(rightWindowWidget,8);


       window->setLayout(dash);


}
