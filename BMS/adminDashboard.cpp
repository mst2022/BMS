#include "mainwindow.h"
#include<QTimer>
#include<QDateTime>

void MainWindow::adminDashboard(){

    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");

    //layout for admin dashboard
    QHBoxLayout *dash = new QHBoxLayout();


    QWidget *rightWindowWidget =new QWidget(window); //right window widget

    //Home page
    QWidget *home = new QWidget(rightWindowWidget);
    QVBoxLayout *homeLayout = new QVBoxLayout;
    //for name and date/time at the top
    QWidget *homeTopW = new QWidget(home);
    homeTopW->setMaximumHeight(200);
    QHBoxLayout *homeTopLayout = new QHBoxLayout();
    QFont font("Sitka", 30);
    QLabel *userLabel = new QLabel(home);
    userLabel->setText("Hello, " + user.getFName() + "(Admin)");
    userLabel->setAlignment(Qt::AlignLeft);
    userLabel->setFont(font);
    QVBoxLayout *dateTimeLayout = new QVBoxLayout();
    timeLabel= new QLabel(home);
    timeLabel->setStyleSheet("*{font-size: 25px; font-family: Roboto; font-weight:bold}");
   QTimer *timer = new QTimer(this);
   currentTime();
   connect(timer, SIGNAL(timeout()), this , SLOT (currentTime()));
   timer->start(1000);

   dateLabel = new QLabel(home);
   dateLabel->setStyleSheet("*{font-size: 23px; font-family: Roboto; font-weight:bold}");
   QDate date = QDate::currentDate();
   dateLabel->setText(date.toString());
   dateTimeLayout->addWidget(timeLabel);
   dateTimeLayout->addWidget(dateLabel);

    timeLabel->setAlignment(Qt::AlignRight);
    dateLabel->setAlignment(Qt::AlignRight);

    homeTopLayout->addWidget(userLabel);
    homeTopLayout->addLayout(dateTimeLayout);

    homeTopW->setLayout(homeTopLayout);


    QStackedWidget *bookingPages = new QStackedWidget(home);
    QWidget *addBusWidget = new QWidget(home);
    QWidget *addMovieWidget = new QWidget(home);
    QWidget *laodMoneyWidget = new QWidget(home);

    QWidget *bodyWidget = new QWidget(home);
    bodyWidget->setMaximumHeight(200);
    QGridLayout *bodyLayout = new QGridLayout();

    //******************Add bus Button start***********************
    QWidget *busAddButtonW = new QWidget(home);
    QVBoxLayout *busAddButtonLayout = new QVBoxLayout();
    busAddButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #25ec17, stop:1 #88f980); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
    busAddButtonW->setMaximumSize(228,100);
    QHBoxLayout *busBtnTopLayout = new QHBoxLayout();
    QWidget *busBtnTopW = new QWidget(busAddButtonW);

    QLabel *bus = new QLabel(busAddButtonW);
    bus->setText("Add a Bus");
    bus->setStyleSheet("*{font-size:20px;background-color:none}");

    QPushButton *addBusBtn = new QPushButton(busAddButtonW);
    addBusBtn->setCursor(Qt::PointingHandCursor);
    QPixmap a(":/images/arrow.png");
    addBusBtn->setIcon(a);
    addBusBtn->setIconSize(QSize(50,50));
    addBusBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
    connect( addBusBtn, &QPushButton::clicked, [=](){
       qDebug()<<"Bus BUtton clicked!";
       bookingPages->setCurrentIndex(1);

    });


    busBtnTopLayout->addWidget(bus);
    busBtnTopLayout->addWidget(addBusBtn);
    busBtnTopW->setLayout(busBtnTopLayout);

    busAddButtonLayout->addWidget(busBtnTopW);

    busAddButtonW->setLayout(busAddButtonLayout);
    //***********************bus ADD Button end************************

    //**********************fligh ADD button start**************************
//    QWidget *flightAddButtonW = new QWidget(home);
//    QVBoxLayout *flightAddButtonLayout = new QVBoxLayout();
//    flightAddButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #dfb60c, stop:1 #fcff87); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
//    flightAddButtonW->setMaximumSize(228,100);
//    QHBoxLayout *flightBtnTopLayout = new QHBoxLayout();
//    QWidget *flightBtnTopW = new QWidget(flightAddButtonW);

//    QLabel *flight = new QLabel(flightAddButtonW);
//    flight->setText("Add a Flight");
//    flight->setStyleSheet("*{font-size:20px;background-color:none}");

//    QPushButton *addFlightBtn = new QPushButton(flightAddButtonW);
//    addFlightBtn->setCursor(Qt::PointingHandCursor);
//    addFlightBtn->setIcon(a);
//    addFlightBtn->setIconSize(QSize(50,50));
//    addFlightBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
//    connect( addFlightBtn, &QPushButton::clicked, [=](){
//       qDebug()<<"Add Flight Button clicked!";
//       bookingPages->setCurrentIndex(2);

//    });


//    flightBtnTopLayout->addWidget(flight);
//    flightBtnTopLayout->addWidget(addFlightBtn);
//    flightBtnTopW->setLayout(flightBtnTopLayout);



//    flightAddButtonLayout->addWidget(flightBtnTopW);

//    flightAddButtonW->setLayout(flightAddButtonLayout);
    //**********************************flight ADD button end****************************


    //**********************************movie ADD button start***************************
    QWidget *movieAddButtonW = new QWidget(home);
    QVBoxLayout *movieAddButtonLayout = new QVBoxLayout();
    movieAddButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #b20cdf, stop:1 #bf96fb); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
    movieAddButtonW->setMaximumSize(228,100);
    QHBoxLayout *movieBtnTopLayout = new QHBoxLayout();
    QWidget *movieBtnTopW = new QWidget(movieAddButtonW);

    QLabel *movie = new QLabel(movieAddButtonW);
    movie->setText("Add a Movie");
    movie->setStyleSheet("*{font-size:20px;background-color:none}");

    QPushButton *bookMovieBtn = new QPushButton(movieAddButtonW);
    bookMovieBtn->setCursor(Qt::PointingHandCursor);
    bookMovieBtn->setIcon(a);
    bookMovieBtn->setIconSize(QSize(50,50));
    bookMovieBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
    connect( bookMovieBtn, &QPushButton::clicked, [=](){
       qDebug()<<"Movie BUtton clicked!";
       bookingPages->setCurrentIndex(2);

    });


    movieBtnTopLayout->addWidget(movie);
    movieBtnTopLayout->addWidget(bookMovieBtn);
    movieBtnTopW->setLayout(movieBtnTopLayout);



    movieAddButtonLayout->addWidget(movieBtnTopW);

    movieAddButtonW->setLayout(movieAddButtonLayout);
    //********************************movie add button end********************************



    //**********************************LOAD money button start***************************
    QWidget *loadMonetButtonW = new QWidget(home);
    QVBoxLayout *loadMoneyButtonLayout = new QVBoxLayout();
    loadMonetButtonW->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #fe8c21, stop:1 #fcbe7b); \nborder-radius: 15%; font-family:Sitka; font-size: 15px");
    loadMonetButtonW->setMaximumSize(228,100);
    QHBoxLayout *laodBtnTopLayout = new QHBoxLayout();
    QWidget *loadBtnTopW = new QWidget(loadMonetButtonW);

    QLabel *load = new QLabel(loadMonetButtonW);
    load->setText("Load Money");
    load->setStyleSheet("*{font-size:20px;background-color:none}");

    QPushButton *loadMoneyBtn = new QPushButton(loadMonetButtonW);
    loadMoneyBtn->setCursor(Qt::PointingHandCursor);
    loadMoneyBtn->setIcon(a);
    loadMoneyBtn->setIconSize(QSize(50,50));
    loadMoneyBtn->setStyleSheet("*{background-color:none;} QPushButton:hover{padding-left:30px}");
    connect( loadMoneyBtn, &QPushButton::clicked, [=](){
       qDebug()<<"Load money button clicked!";
       bookingPages->setCurrentIndex(3);

    });


    laodBtnTopLayout->addWidget(load);
    laodBtnTopLayout->addWidget(loadMoneyBtn);
    loadBtnTopW->setLayout(laodBtnTopLayout);



    loadMoneyButtonLayout->addWidget(loadBtnTopW);

    loadMonetButtonW->setLayout(loadMoneyButtonLayout);
    //********************************LOAD money button end********************************

    //adding the buttons to the gird layout
    bodyLayout->addWidget(busAddButtonW, 0,1);
    bodyLayout->addWidget(movieAddButtonW, 0,2);
    bodyLayout->addWidget(loadMonetButtonW, 0,3);

    //when buttons are clicked
    addBus(addBusWidget, bookingPages);
    addMovie(addMovieWidget, bookingPages);
    loadMoney(laodMoneyWidget, bookingPages);


    //adding wigets to stacked widget
    bookingPages->addWidget(bodyWidget);
    bookingPages->addWidget(addBusWidget);
    bookingPages->addWidget(addMovieWidget);
    bookingPages->addWidget(laodMoneyWidget);

    bodyWidget->setLayout(bodyLayout);
    homeLayout->addWidget(homeTopW);
    homeLayout->addWidget(bookingPages);


    home->setLayout(homeLayout);


    //nav bar
    QWidget *profile = new QWidget(rightWindowWidget);

    QStackedWidget *pages = new QStackedWidget(rightWindowWidget);
    pages->addWidget(home);
    pages->addWidget(profile);


    QWidget *leftWindowWidget = new QWidget(window); //left window widget
    leftWindowWidget->setStyleSheet("QPushButton{padding: 30px; font-size:20px; border:none; font-family: Artifakt Element} QPushButton:hover{color:red} *{border-right: 2px solid grey}");
    QVBoxLayout *nav = new QVBoxLayout();

    QLabel *logo = new QLabel(leftWindowWidget);
    logo->setStyleSheet("*{border:none}");
    QPixmap lo(":/images/BMSlogo.png");
    logo->setPixmap(lo.scaled(100,100));

    logo->setMaximumHeight(150);

    logo->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    QPushButton *homeButton = new QPushButton("Home", leftWindowWidget);
    QPushButton *profileButton = new QPushButton("Profile",leftWindowWidget);
    QPushButton *logoutButton = new QPushButton("Logout",leftWindowWidget);
    QPushButton *aboutButton = new QPushButton("About",leftWindowWidget);


    setActiveTab(homeButton, profileButton, aboutButton);

   homeButton->setCursor(Qt::PointingHandCursor);
   connect( homeButton, &QPushButton::clicked, [=](){
      setActiveTab(homeButton, profileButton, aboutButton);
      pages->setCurrentIndex(0);

   });


    myProfile(profile, rightWindowWidget);
   profileButton->setCursor(Qt::PointingHandCursor);
   connect( profileButton, &QPushButton::clicked, [=](){
       setActiveTab(profileButton, homeButton, aboutButton);

      pages->setCurrentIndex(1);
   });





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
           timer->stop();
           loginScreen();
       }


   });




   aboutButton->setCursor(Qt::PointingHandCursor);

   connect( aboutButton, &QPushButton::clicked, [=](){
       setActiveTab(aboutButton, profileButton, homeButton);
      QMessageBox about;
      QPixmap logo(":/images/BMSlogo.png");
      about.setIconPixmap(logo.scaled(200,200));
      about.setStyleSheet("QLabel{max-width:400px; max-height:500px}");
      about.setWindowTitle("About BMS");
      about.setText("Booking Management System 1.0\nversion: 1.0 \nThis is BMS");
      about.setStandardButtons(QMessageBox::Close);
      about.exec();
   });

   nav->addWidget(logo);
   nav->addWidget(homeButton);
   nav->addWidget(profileButton);
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
