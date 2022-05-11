#include "mainwindow.h"

void MainWindow::addBus(QWidget *addBusWidget, QStackedWidget *bookingPages){
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *topWidget = new QWidget(addBusWidget);
    topWidget->setStyleSheet("*{background: #88f980; border-radius: 15%}");
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

    QLabel *loadLabel = new QLabel(addBusWidget);
    loadLabel->setText("Add a Bus");
    loadLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    loadLabel->setFont(font);
    loadLabel->setMaximumHeight(100);
    loadLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(loadLabel, 9);

    topWidget->setLayout(topLayout);


    QWidget *signUpForm = new QWidget(addBusWidget);
    signUpForm->setStyleSheet("*{background:white; border-radius:15%} QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    //for error message
    QLabel *errorLabel = new QLabel(signUpForm);


    QGridLayout *addBusFormLayout = new QGridLayout();
    addBusFormLayout->setColumnMinimumWidth(1,300);

    QLabel *busNameLabel = new QLabel(signUpForm);
    busNameLabel->setText("Bus Name");
    QLineEdit *busNameLineEdit = new QLineEdit();
    busNameLineEdit->setPlaceholderText("Bus Name");
    busNameLineEdit->setFixedHeight(45);

    QLabel *fromLabel = new QLabel(signUpForm);
    fromLabel->setText("From");
    QLineEdit *fromLineEdit = new QLineEdit();
    fromLineEdit->setPlaceholderText("From");
    fromLineEdit->setFixedHeight(45);

    QLabel *toLabel = new QLabel(signUpForm);
    toLabel->setText("To");
    QLineEdit *toLineEdit = new QLineEdit();
    toLineEdit->setPlaceholderText("To");
    toLineEdit->setFixedHeight(45);

    QLabel *dateLabel = new QLabel(signUpForm);
    dateLabel->setText("Date");
    QLineEdit *dateLineEdit = new QLineEdit();
    dateLineEdit->setPlaceholderText("YYYY-MM-DD");
    dateLineEdit->setFixedHeight(45);

    QLabel *departureTimeLabel = new QLabel(signUpForm);
    departureTimeLabel->setText("Time");
    QLineEdit *departureTimeLineEdit = new QLineEdit();
    departureTimeLineEdit->setPlaceholderText("HH:MM");
    departureTimeLineEdit->setFixedHeight(45);



    QLabel *ticketPriceLabel = new QLabel(signUpForm);
    ticketPriceLabel->setText("Ticket Price");
    QLineEdit *ticketPriceLineEdit = new QLineEdit();
    ticketPriceLineEdit->setPlaceholderText("Price");
    ticketPriceLineEdit->setFixedHeight(45);

    QLabel *descriptionLabel = new QLabel(signUpForm);
    descriptionLabel->setText("Bus Description");
    QLineEdit *descriptionLineEdit = new QLineEdit();
    descriptionLineEdit->setPlaceholderText("Descrition");
    descriptionLineEdit->setFixedHeight(45);

    QPushButton *addBusButton = new QPushButton();
    addBusButton->setFixedSize(200,45);
    addBusButton->setCursor(Qt::PointingHandCursor);
    addBusButton->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");

    addBusButton->setText("Add Bus");
    connect( addBusButton, &QPushButton::clicked, [=](){
        //error message if condition
        if(busNameLineEdit->text().isEmpty() || fromLineEdit->text().isEmpty() || toLineEdit->text().isEmpty() || dateLineEdit->text().isEmpty() || departureTimeLineEdit->text().isEmpty() || ticketPriceLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields");
        }
        else{
            //storing in database
            qDebug()<< busNameLineEdit->text() <<" Bus added";
            if(db.addBus(busNameLineEdit->text(), fromLineEdit->text(), toLineEdit->text(), dateLineEdit->text(), departureTimeLineEdit->text(), ticketPriceLineEdit->text().toInt(),  descriptionLineEdit->text())){

                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Loading Successful");
                msgBox.setText("Successfully add "+busNameLineEdit->text()+".");
                msgBox.exec();

                //clearing the fields
                errorLabel->setText("");
                busNameLineEdit->setText("");
                fromLineEdit->setText("");
                toLineEdit->setText("");
                dateLineEdit->setText("");
                departureTimeLineEdit->setText("");
                ticketPriceLineEdit->setText("");
                descriptionLineEdit->setText("");
            }
            else{
                errorLabel->setText("Could not add the bus.");
            }

        }

    });



    addBusFormLayout->addWidget(busNameLabel, 0, 0);
    addBusFormLayout->addWidget(fromLabel, 1, 0);
    addBusFormLayout->addWidget(toLabel, 2, 0);
    addBusFormLayout->addWidget(dateLabel, 3, 0);
    addBusFormLayout->addWidget(departureTimeLabel, 4, 0);
    addBusFormLayout->addWidget(ticketPriceLabel, 5, 0);
    addBusFormLayout->addWidget(descriptionLabel, 6, 0);



    addBusFormLayout->addWidget(busNameLineEdit, 0, 1,1,2);
    addBusFormLayout->addWidget(fromLineEdit, 1, 1,1,2);
    addBusFormLayout->addWidget(toLineEdit, 2, 1,1,2);
    addBusFormLayout->addWidget(dateLineEdit, 3, 1,1,2);
    addBusFormLayout->addWidget(departureTimeLineEdit, 4, 1,1,2);
    addBusFormLayout->addWidget(ticketPriceLineEdit, 5, 1,1,2);
    addBusFormLayout->addWidget(descriptionLineEdit, 6, 1, 1, 2);

    addBusFormLayout->addWidget(addBusButton, 7,2);

    addBusFormLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);

    signUpForm->setLayout(addBusFormLayout);

    //error message properties
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setText("");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);



    layout->addWidget(topWidget, 1);
    layout->addWidget(errorLabel, 1);
    layout->addWidget(signUpForm, 8);
    addBusWidget->setLayout(layout);
}
