#include "mainwindow.h"
void MainWindow::addMovie(QWidget *addMovieWidget, QStackedWidget *bookingPages){
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *topWidget = new QWidget(addMovieWidget);
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

    QLabel *loadLabel = new QLabel(addMovieWidget);
    loadLabel->setText("Add a Movie");
    loadLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    loadLabel->setFont(font);
    loadLabel->setMaximumHeight(100);
    loadLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(loadLabel, 9);

    topWidget->setLayout(topLayout);

    QWidget *signUpForm = new QWidget(addMovieWidget);
    signUpForm->setStyleSheet("*{background:white; border-radius:15%} QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    //for error message
    QLabel *errorLabel = new QLabel(signUpForm);


    QGridLayout *addMovieFormLayout = new QGridLayout();
    addMovieFormLayout->setColumnMinimumWidth(1,300);

    QLabel *movieNameLabel = new QLabel(signUpForm);
    movieNameLabel->setText("Movie Name");
    QLineEdit *movieNameLineEdit = new QLineEdit();
    movieNameLineEdit->setPlaceholderText("Movie Name");
    movieNameLineEdit->setFixedHeight(45);


    QLabel *dateLabel = new QLabel(signUpForm);
    dateLabel->setText("Date");
    QLineEdit *dateLineEdit = new QLineEdit();
    dateLineEdit->setPlaceholderText("YYYY-MM-DD");
    dateLineEdit->setFixedHeight(45);

    QLabel *showTimeLabel = new QLabel(signUpForm);
    showTimeLabel->setText("Show Time");
    QLineEdit *showTimeLineEdit = new QLineEdit();
    showTimeLineEdit->setPlaceholderText("HH:MM");
    showTimeLineEdit->setFixedHeight(45);



    QLabel *ticketPriceLabel = new QLabel(signUpForm);
    ticketPriceLabel->setText("Ticket Price");
    QLineEdit *ticketPriceLineEdit = new QLineEdit();
    ticketPriceLineEdit->setPlaceholderText("Price");
    ticketPriceLineEdit->setFixedHeight(45);

    QLabel *descriptionLabel = new QLabel(signUpForm);
    descriptionLabel->setText("Movie Description");
    QLineEdit *descriptionLineEdit = new QLineEdit();
    descriptionLineEdit->setPlaceholderText("Descrition");
    descriptionLineEdit->setFixedHeight(45);

    QPushButton *addMovieButton = new QPushButton();
    addMovieButton->setFixedSize(200,45);
    addMovieButton->setCursor(Qt::PointingHandCursor);
    addMovieButton->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");

    addMovieButton->setText("Add Movie");
    connect( addMovieButton, &QPushButton::clicked, [=](){
        //error message if condition
        if(movieNameLineEdit->text().isEmpty() || dateLineEdit->text().isEmpty() || showTimeLineEdit->text().isEmpty() || ticketPriceLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields");
        }
        else{
            //storing in database
            qDebug()<< movieNameLineEdit->text() <<" Bus added";
            if(db.addMovie(movieNameLineEdit->text(), dateLineEdit->text(), showTimeLineEdit->text(), ticketPriceLineEdit->text().toInt(),  descriptionLineEdit->text())){

                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Loading Successful");
                msgBox.setText("Successfully add "+movieNameLineEdit->text()+".");
                msgBox.exec();

                //clearing
                errorLabel->setText("");
                movieNameLineEdit->setText("");
                dateLineEdit->setText("");
                showTimeLineEdit->setText("");
                ticketPriceLineEdit->setText("");
                descriptionLineEdit->setText("");
            }
            else{
                errorLabel->setText("Could not add the movie.");
            }

        }

    });



    addMovieFormLayout->addWidget(movieNameLabel, 0, 0);
    addMovieFormLayout->addWidget(dateLabel, 1, 0);
    addMovieFormLayout->addWidget(showTimeLabel, 2, 0);
    addMovieFormLayout->addWidget(ticketPriceLabel, 3, 0);
    addMovieFormLayout->addWidget(descriptionLabel, 4, 0);



    addMovieFormLayout->addWidget(movieNameLineEdit, 0, 1,1,2);
    addMovieFormLayout->addWidget(dateLineEdit, 1, 1,1,2);
    addMovieFormLayout->addWidget(showTimeLineEdit, 2, 1,1,2);
    addMovieFormLayout->addWidget(ticketPriceLineEdit, 3, 1,1,2);
    addMovieFormLayout->addWidget(descriptionLineEdit, 4, 1, 1, 2);

    addMovieFormLayout->addWidget(addMovieButton, 7,2);

    addMovieFormLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);

    signUpForm->setLayout(addMovieFormLayout);

    //error message properties
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setText("");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);



    layout->addWidget(topWidget, 1);
    layout->addWidget(errorLabel, 1);
    layout->addWidget(signUpForm, 8);
    addMovieWidget->setLayout(layout);
}
