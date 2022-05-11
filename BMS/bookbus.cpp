#include "mainwindow.h"

void MainWindow::bookBus(QWidget *bookBusWidget, QStackedWidget *bookingPages)
{
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *topWidget = new QWidget(bookBusWidget);
    topWidget->setStyleSheet("*{background: #88f980; border-radius: 15%}");
    QHBoxLayout *topLayout = new QHBoxLayout();

    // back button
    QPushButton *backButton = new QPushButton(topWidget);
    backButton->setStyleSheet("QPushButton{border: none; padding-right:45px} QPushButton:hover{padding-right:70px}");
    backButton->setCursor(Qt::PointingHandCursor);
    QPixmap a(":/images/back-button.png");
    QIcon arrow(a);
    backButton->setIcon(a);
    backButton->setIconSize(QSize(25,25));

    connect( backButton, &QPushButton::clicked, [=](){
       bookingPages->setCurrentIndex(0);
    });

    QLabel *busLabel = new QLabel(bookBusWidget);
    busLabel->setText("Available Buses");
    busLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    busLabel->setFont(font);
    busLabel->setMaximumHeight(100);
    busLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(busLabel, 9);


    topWidget->setLayout(topLayout);

    //busTable is a data member of MainWindow class
    busTable = new QTableWidget(bookBusWidget);
    busTable->setStyleSheet("QHeaderView::section {background-color:#31bc86; border: none} QTableWidget{color: #454545; background-color:#ffffff; alternate-background-color:#e9eef5; selection-background-color:#cce3ff;selection-color: #03851a; border-radius: 15%; font-family:Artifakt Element; font-size:16px;}");
    //table properties
    busTable->setAlternatingRowColors(true);
    busTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    busTable->setColumnCount(6);
    busTable->setCornerButtonEnabled(false);
    // horizontal header(name, from, to, ...)
    busTable->horizontalHeader()->setVisible(true);
    busTable->horizontalHeader()->setDefaultSectionSize(170);
    busTable->horizontalHeader()->setStyleSheet("*{color:white ;font-family: Artifakt Element; font-size: 16px; font-weight:bold}");
    busTable->horizontalHeader()->setStretchLastSection(true);\
    busTable->horizontalHeader()->setFixedHeight(44);
    //hides vertical headers (indexing)
    busTable->verticalHeader()->setVisible(false);

    //makes text in cells non editable by the user
    busTable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QStringList hLabels;
    hLabels<<"Bus Name" <<"From"<<"To"<<"Date"<<"Departure Time"<<"Price(Rs.)";
    busTable->setHorizontalHeaderLabels(hLabels);
    bus *buses = new bus[20];

    //bus details from database
    int busCount = db.fillBus(buses);
    busTable->setRowCount(busCount);


    for(int i = 0; i<busCount;i++){
        QTableWidgetItem *busName = new QTableWidgetItem(buses[i].getName());
        QTableWidgetItem *busFrom = new QTableWidgetItem(buses[i].getFrom());
        QTableWidgetItem *busTo = new QTableWidgetItem(buses[i].getTo());
        QTableWidgetItem *busDate = new QTableWidgetItem(buses[i].getDate());
        QTableWidgetItem *busTime = new QTableWidgetItem(buses[i].getTime());
        QTableWidgetItem *busPrice = new QTableWidgetItem(QString::number(buses[i].getPrice()));
        busTable->setItem(i,0,busName);
        busTable->setItem(i,1,busFrom);
        busTable->setItem(i,2,busTo);
        busTable->setItem(i, 3, busDate);
        busTable->setItem(i,4,busTime);
        busTable->setItem(i,5,busPrice);
        busTable->setRowHeight(i, 44);
    }

    //when a cell/row of table is selected
    connect(busTable, SIGNAL(cellClicked(int,int)), SLOT(displayInfo(int,int)));


    //bus details and book now section
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QWidget *bottomWidget = new QWidget(bookBusWidget);

    bottomWidget->setStyleSheet("*{background-color: #dfe7f0; border-radius: 15%}");

    //bus details at the bottom
    //busDetails is a data member of MainWindow class
    busDetails= new QLabel(bottomWidget);
    busDetails->setStyleSheet("QLabel{font-family: Artifakt Element; font-size: 17px; font-weight:bold}");
    busDetails->setText("Select a bus to see the details");


    //bus seats
//    QWidget *nagarikBus = new QWidget(bookBusWidget);


    //Book now button
    bookNowButton = new QPushButton(bottomWidget);
    bookNowButton->setCursor(Qt::PointingHandCursor);
    bookNowButton->setStyleSheet("QPushButton{width: 50px; color:white; background:#07b507 ;border:1px solid #07b507; border-radius:13%; font-size:22px; font-weight:bold; font-family:Artifakt Element;} :hover{color:white; background:#088a08}");
    bookNowButton->setFixedSize(170, 70);
    bookNowButton->setText("Book Now");
    bookNowButton->setVisible(false);
    connect( bookNowButton, &QPushButton::clicked, [=](){
        qDebug()<<rowIndex <<"bus clicked";
        displayBus(buses, bookingPages, rowIndex);
    });

    bottomLayout->addWidget(busDetails,7);
    bottomLayout->addWidget(bookNowButton,3);
    bottomWidget->setLayout(bottomLayout);
    layout->addWidget(topWidget, 1);
    layout->addWidget(busTable, 6);
    layout->addWidget(bottomWidget,3);
    bookBusWidget->setLayout(layout);
}
