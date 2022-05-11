#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>

void MainWindow::registerScreen(){
    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
    QLabel *BMSLabel = new QLabel(window);
    BMSLabel->setText("Booking Management System");
    BMSLabel->setAlignment(Qt::AlignHCenter);
    QFont font("Sitka",45,QFont::Bold);
    BMSLabel->setFont(font);
    BMSLabel->setMaximumHeight(100);
//    BMSLabel->setStyleSheet("*{background-color:red;}");
    BMSLabel->show();

    QLabel *signUpLabel = new QLabel(window);
    signUpLabel->setText("SIGN UP");
    signUpLabel->setAlignment(Qt::AlignHCenter);
    QFont signUpFont("Artifakt Element",25,QFont::Bold);
    signUpLabel->setFont(signUpFont);
    signUpLabel->setMaximumHeight(50);
//    signUpLabel->setStyleSheet("*{height:0px; border: 2px solid black;}");
    signUpLabel->show();



    QWidget *signUpForm = new QWidget(window);
    signUpForm->setStyleSheet("QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    //for error message
    QLabel *errorLabel = new QLabel();
//    errorLabel->setVisible(false);


    QGridLayout *signUpFormLayout = new QGridLayout();
    signUpFormLayout->setColumnMinimumWidth(1,300);

    QLabel *firstNameLabel = new QLabel(signUpForm);
    firstNameLabel->setText("First Name");
    QLineEdit *firstNameLineEdit = new QLineEdit();
    firstNameLineEdit->setPlaceholderText("First Name");
    firstNameLineEdit->setFixedHeight(45);

    QLabel *lastNameLabel = new QLabel(signUpForm);
    lastNameLabel->setText("Last Name");
    QLineEdit *lastNameLineEdit = new QLineEdit();
    lastNameLineEdit->setPlaceholderText("Last Name");
    lastNameLineEdit->setFixedHeight(45);

    QLabel *emailLabel = new QLabel(signUpForm);
    emailLabel->setText("Email");
    QLineEdit *emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("Email");
    emailLineEdit->setFixedHeight(45);

    QLabel *phoneNumberLabel = new QLabel(signUpForm);
    phoneNumberLabel->setText("Phone no.");
    QLineEdit *phoneNumberLineEdit = new QLineEdit();
    phoneNumberLineEdit->setPlaceholderText("Phone number");
    phoneNumberLineEdit->setFixedHeight(45);

    QLabel *passwordLabel = new QLabel(signUpForm);
    passwordLabel->setText("Password");
    QLineEdit *passwordLineEdit = new QLineEdit();
    passwordLineEdit->setPlaceholderText("Passowrd");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setFixedHeight(45);

    QLabel *rePasswordLabel = new QLabel(signUpForm);
    rePasswordLabel->setText("Confirm Password");
    QLineEdit *rePasswordLineEdit = new QLineEdit();
    rePasswordLineEdit->setPlaceholderText("Re-enter Password");
    rePasswordLineEdit->setEchoMode(QLineEdit::Password);
    rePasswordLineEdit->setFixedHeight(45);

    QPushButton *cancelButton = new QPushButton();
    cancelButton->setCursor(Qt::PointingHandCursor);
    cancelButton->setFixedSize(200,45);
    cancelButton->setStyleSheet("*{font-weight:bold; background:white; color: blue; border: 1px solid blue; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:blue; color:white; border:none}");
    cancelButton->setText("Cancel");
    connect( cancelButton, &QPushButton::clicked, [=](){
       loginScreen();

    });

    QPushButton *signUpButton = new QPushButton();
    signUpButton->setFixedSize(200,45);
    signUpButton->setCursor(Qt::PointingHandCursor);
    signUpButton->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");

    signUpButton->setText("Sign Up");
    connect( signUpButton, &QPushButton::clicked, [=](){
        //error message if condition
        if(firstNameLineEdit->text().isEmpty() || lastNameLineEdit->text().isEmpty() || emailLineEdit->text().isEmpty() || phoneNumberLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty() || rePasswordLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields");
        }
        else if(passwordLineEdit->text() != rePasswordLineEdit->text()){
            errorLabel->setText("Passwords did not match!");
        }
        else if(db.alreadyRegistred(emailLineEdit->text())){
            errorLabel->setText("Email already registred!");
        }
        else{

            //storing in database
            QString fName= firstNameLineEdit->text();
            QString lName= lastNameLineEdit->text();
            QString email = emailLineEdit->text();
            QString number = phoneNumberLineEdit->text() ;
            QString password = passwordLineEdit->text();
            if(db.registerUser(fName, lName, number, email, password)){
                emailRegister(email, fName);
                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Signed Up");
                msgBox.setText("Sign Up Successful");
                msgBox.setInformativeText("You Have Been Signed Up To BMS");
                QAbstractButton *login = msgBox.addButton(tr("Login"), QMessageBox::YesRole);

                msgBox.exec();
                if(msgBox.clickedButton() == login){
                    loginScreen();
                }

            }
            else{
                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Error");
                msgBox.setText("Unable to register");
                msgBox.setInformativeText("We are unable to register you!!");
                QAbstractButton *retry = msgBox.addButton(tr("Retry"), QMessageBox::YesRole);

                msgBox.exec();
                if(msgBox.clickedButton() == retry){
                    registerScreen();
                }

            }
        }

    });



    signUpFormLayout->addWidget(firstNameLabel, 0, 0);
    signUpFormLayout->addWidget(lastNameLabel, 1, 0);
    signUpFormLayout->addWidget(emailLabel, 2, 0);
    signUpFormLayout->addWidget(phoneNumberLabel, 3, 0);
    signUpFormLayout->addWidget(passwordLabel, 4, 0);
    signUpFormLayout->addWidget(rePasswordLabel, 5, 0);



    signUpFormLayout->addWidget(firstNameLineEdit, 0, 1,1,2);
    signUpFormLayout->addWidget(lastNameLineEdit, 1, 1,1,2);
    signUpFormLayout->addWidget(emailLineEdit, 2, 1,1,2);
    signUpFormLayout->addWidget(phoneNumberLineEdit, 3, 1,1,2);
    signUpFormLayout->addWidget(passwordLineEdit, 4, 1,1,2);
    signUpFormLayout->addWidget(rePasswordLineEdit, 5, 1,1,2);

    signUpFormLayout->addWidget(cancelButton, 6,1);
    signUpFormLayout->addWidget(signUpButton, 6,2);

    signUpFormLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);


    signUpForm->setLayout(signUpFormLayout);

    //error message properties
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setText("");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);


    QVBoxLayout *registerScreenLayout = new QVBoxLayout();
    registerScreenLayout->addWidget(BMSLabel);
    registerScreenLayout->addWidget(signUpLabel);
    registerScreenLayout->addWidget(errorLabel);
    registerScreenLayout->addWidget(signUpForm);


//    registerScreenLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    window->setLayout(registerScreenLayout);






}
