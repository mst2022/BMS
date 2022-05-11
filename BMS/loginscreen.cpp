#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>
#include <QSqlQuery>

void MainWindow::loginScreen()
{
    currentIndex = 4;
    QWidget *window = new QWidget(this);
       setCentralWidget(window);
       window->setStyleSheet("*{background:white;}");
           QVBoxLayout *layout =new QVBoxLayout();  //Defining Verticle Box Layour

               //Displays BMS Text At Center

               QLabel *titleLabel = new QLabel(window);
               titleLabel->setText("Booking Management System");
               titleLabel->setAlignment(Qt::AlignHCenter);
               QFont font("Sitka",45,QFont::Bold);


               titleLabel->setFont(font);
               titleLabel->setMaximumHeight(100);
//               titleLabel->setStyleSheet("*{background-color:red;}");
               titleLabel->show();

               //displays login text

               QLabel *loginLabel = new QLabel(window);
               QFont font2("Artifakt Element",45,QFont::Bold);
               loginLabel->setText("Login");
               loginLabel->setFont(font2);
               loginLabel->setAlignment(Qt::AlignHCenter);
               QFont loginFont("Artifakt Element",25,QFont::Bold);
               loginLabel->setFont(loginFont);
               loginLabel->setMaximumHeight(50);
               loginLabel->show();


               //Diaplays Login Form
               QWidget *loginForm = new QWidget(window);
               loginForm->setStyleSheet("*{}QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element} QLabel{font-weight:bold;font-size:18px;font-family:Artifakt Element; padding:15px;}");
               loginForm->setGeometry(400,400,200,200);
               QGridLayout *formLayout = new QGridLayout(); // Defines grid layout for loginform
               formLayout->setColumnMinimumWidth(1,170);

                   // Form Fields Start

                   //Hint Text

                   QLabel *emailHint = new QLabel("Email");

                   QLabel *passwordHint = new QLabel("Password");

                   // Input Forms

                   this->emailText = new QLineEdit();    //this refers to the MainWindow class
                   this->passwordText = new QLineEdit();
                   passwordText->setEchoMode(QLineEdit::Password);  //hides password while typing

                   // Additional Text Field Decoration
                   passwordText->setFixedHeight(45);
                   emailText->setFixedHeight(45);
                   passwordText->setClearButtonEnabled(true);
                   passwordText->setPlaceholderText("Password");
                   emailText->setPlaceholderText("Email");
                   emailText->setClearButtonEnabled(true);



                   // Login button
                   QPushButton *loginButton = new QPushButton(loginForm); // Displays Login Button
                   loginButton->setCursor(Qt::PointingHandCursor);
                   loginButton->setText("Login");
                   loginButton->setStyleSheet("*{color:white; background:#07b507 ;border:1px solid #07b507; border-radius:13%; font-size:22px; font-weight:bold; font-family:Artifakt Element;} :hover{color:#07b507; background:white}");


                   loginButton->setFixedSize(170,45);

                   QLabel *errorLabel = new QLabel(this);
                   errorLabel->setText("");


                    connect( loginButton, &QPushButton::clicked, [=](){
                            if(emailText->text().isEmpty() && passwordText->text().isEmpty()){

                                    errorLabel->setText("Email and Password fields are empty!");
                            }
                            else if(emailText->text().isEmpty()){
                                errorLabel->setText("Enter your email!");
                            }
                            else if(passwordText->text().isEmpty()){
                                errorLabel->setText("Enter your password!");
                            }
                            else{
                                if(db.loginUser(emailText->text(), passwordText->text(), user)){
                                    if(user.getAdminStatus()){
                                        adminDashboard();
                                    }else{
                                        dashBoard();
                                    }

                                }
                                else{
                                    errorLabel->setText("Incorrect email or password!");
                                }
                            }
                    });

                   //shows error while login in
                   errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
                   errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
                   errorLabel->setFixedHeight(40);

                   // Form Fields End


                   QHBoxLayout *registerLayout = new QHBoxLayout();
                   QLabel *registerLabel = new QLabel(this);
                   registerLabel->setStyleSheet("*{font-family: Artifakt Element; font-size: 18px}");
                   registerLabel->setText("Don't have an BMS account?");

                   QPushButton *registerButton = new QPushButton(this);
                   registerButton->setStyleSheet("*{border:none; color:blue; font-family: Artifakt Element; font-size:18px} :hover{text-decoration: underline}");
                   registerButton->setCursor(Qt::PointingHandCursor);
                   registerButton->setText("Sign Up");

                   registerLayout->addWidget(registerLabel);
                   registerLayout->addWidget(registerButton);
                   registerLayout->setAlignment(Qt::AlignHCenter |Qt::AlignTop);

                   connect(registerButton,SIGNAL(clicked(bool)),this,SLOT(registerScreen()));






               // Adding widgets in form layout previously defined
               formLayout->addWidget(emailHint,0,0);
               formLayout->addWidget(emailText,0,1,1,2);
               formLayout->addWidget(passwordHint,1,0);
               formLayout->addWidget(passwordText,1,1,1,2);
               formLayout->addWidget(loginButton,2,2);

               formLayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
               loginForm->setMaximumHeight(200);
               loginForm->setLayout(formLayout); // Set login form layout


           // Adding widgets in main layout

           layout->addWidget(titleLabel,1);
           layout->addWidget(loginLabel,1);
           layout->addWidget(loginForm,1);
           layout->addWidget(errorLabel,1);
           layout->addLayout(registerLayout,3);

       window->setLayout(layout); // Setting layout to main window


}
