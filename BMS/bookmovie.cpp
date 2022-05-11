#include "mainwindow.h"

void MainWindow::bookMovie(QWidget *bookMovieWidget, QStackedWidget *bookingPages)
{
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *topWidget = new QWidget(bookMovieWidget);
    topWidget->setStyleSheet("*{background: #bf96fb; border-radius: 15%}");
    QHBoxLayout *topLayout = new QHBoxLayout();
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

    QLabel *bookMovieLabel = new QLabel(bookMovieWidget);
    bookMovieLabel->setText("Available Movies");
    bookMovieLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    bookMovieLabel->setFont(font);
    bookMovieLabel->setMaximumHeight(100);
    bookMovieLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(bookMovieLabel, 9);

    topWidget->setLayout(topLayout);

    //movieTable is a data member of MainWindow class
    movieTable = new QTableWidget(bookMovieWidget);
    movieTable->setStyleSheet("QHeaderView::section {background-color:#31bc86; border: none} QTableWidget{color: #454545; background-color:#ffffff; alternate-background-color:#e9eef5; selection-background-color:#cce3ff;selection-color: #03851a; border-radius: 15%; font-family:Artifakt Element; font-size:16px;}");
    //table properties
    movieTable->setAlternatingRowColors(true);
    movieTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    movieTable->setColumnCount(5);
    movieTable->setCornerButtonEnabled(false);
    // horizontal header(name, from, to, ...)
    movieTable->horizontalHeader()->setVisible(true);
    movieTable->horizontalHeader()->setDefaultSectionSize(202);
    movieTable->horizontalHeader()->setStyleSheet("*{color:white ;font-family: Artifakt Element; font-size: 16px; font-weight:bold}");
    movieTable->horizontalHeader()->setStretchLastSection(true);\
    movieTable->horizontalHeader()->setFixedHeight(44);
    //hides vertical headers (indexing)
    movieTable->verticalHeader()->setVisible(false);

    //makes text in cells non editable by the user
    movieTable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QStringList hLabels;
    hLabels<<"Movie Name" <<"Date"<<"Time" <<"Desctiption"<<"Price(Rs.)";
    movieTable->setHorizontalHeaderLabels(hLabels);
    movie *movies = new movie[20];

    //bus details from database
    int movieCount = db.fillMovie(movies);
    movieTable->setRowCount(movieCount);


    for(int i = 0; i<movieCount;i++){
        QTableWidgetItem *movieName = new QTableWidgetItem(movies[i].getName());
        QTableWidgetItem *movieDate = new QTableWidgetItem(movies[i].getDate());
        QTableWidgetItem *movieTime = new QTableWidgetItem(movies[i].getTime());
        QTableWidgetItem *movieDesc = new QTableWidgetItem(movies[i].getDesc());
        QTableWidgetItem *moviePrice = new QTableWidgetItem(QString::number(movies[i].getPrice()));
        movieTable->setItem(i,0,movieName);
        movieTable->setItem(i, 1, movieDate);
        movieTable->setItem(i,2,movieTime);
        movieTable->setItem(i, 3, movieDesc);
        movieTable->setItem(i,4,moviePrice);
        movieTable->setRowHeight(i, 44);
    }

    //when a cell/row of table is selected
    connect(movieTable, SIGNAL(cellClicked(int,int)), SLOT(displayMovieInfo(int,int)));
    //bus details and book now section
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QWidget *bottomWidget = new QWidget(bookMovieWidget);

    bottomWidget->setStyleSheet("*{background-color: #dfe7f0; border-radius: 15%}");

    //bus details at the bottom
    //busDetails is a data member of MainWindow class
    movieDetails= new QLabel(bottomWidget);
    movieDetails->setStyleSheet("QLabel{font-family: Artifakt Element; font-size: 17px; font-weight:bold}");
    movieDetails->setText("Select a movie to see the details");


    //Book now button
    bookNowButtonMoive = new QPushButton(bottomWidget);
    bookNowButtonMoive->setCursor(Qt::PointingHandCursor);
    bookNowButtonMoive->setStyleSheet("QPushButton{width: 50px; color:white; background:#07b507 ;border:1px solid #07b507; border-radius:13%; font-size:22px; font-weight:bold; font-family:Artifakt Element;} :hover{color:white; background:#088a08}");
    bookNowButtonMoive->setFixedSize(170, 70);
    bookNowButtonMoive->setText("Book Movie");
    bookNowButtonMoive->setVisible(false);
    connect( bookNowButtonMoive, &QPushButton::clicked, [=](){
        displayMovie(movies, bookingPages, rowIndex);
    });


    bottomLayout->addWidget(movieDetails,7);
    bottomLayout->addWidget(bookNowButtonMoive,3);
    bottomWidget->setLayout(bottomLayout);
    layout->addWidget(topWidget, 1);
    layout->addWidget(movieTable, 6);
    layout->addWidget(bottomWidget,3);

    bookMovieWidget->setLayout(layout);



}
