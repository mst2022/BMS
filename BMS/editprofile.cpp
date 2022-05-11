#include "mainwindow.h"

void MainWindow::editProfile(QStackedWidget *profileStack)
{
    QWidget *editProfileW = new QWidget();
    QVBoxLayout *editProfileLayout = new QVBoxLayout();
    profileStack->addWidget(editProfileW);
    profileStack->setCurrentIndex(1);

    QWidget *topWidget = new QWidget(editProfileW);
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
        profileStack->removeWidget(editProfileW);
        delete editProfileW;
       profileStack->setCurrentIndex(0);
    });

    QLabel *editProfileLabel = new QLabel(editProfileW);
    editProfileLabel->setText("Edit Profile");
    editProfileLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    editProfileLabel->setFont(font);
    editProfileLabel->setMaximumHeight(100);
    editProfileLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(editProfileLabel, 9);
    topWidget->setLayout(topLayout);


    QWidget *editProfileForm = new QWidget(editProfileW);
    editProfileForm->setStyleSheet("*{background:white; border-radius:15%} QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    //for error message
    QLabel *errorLabel = new QLabel(editProfileForm);
    //error message properties
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setText("");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);


    QGridLayout *editProfileFormLayout = new QGridLayout();
    editProfileFormLayout->setColumnMinimumWidth(1,300);

    QLabel *firstNameLabel = new QLabel(editProfileW);
    firstNameLabel->setText("First Name");
    QLineEdit *firstNameLineEdit = new QLineEdit();
    firstNameLineEdit->setPlaceholderText(user.getFName());
    firstNameLineEdit->setFixedHeight(45);


    QLabel *lastNameLabel = new QLabel(editProfileW);
    lastNameLabel->setText("Last Name");
    QLineEdit *lastNameLineEdit = new QLineEdit();
    lastNameLineEdit->setPlaceholderText(user.getLName());
    lastNameLineEdit->setFixedHeight(45);


    QLabel *phoneLabel = new QLabel(editProfileW);
    phoneLabel->setText("Phone no.");
    QLineEdit *phoneLineEdit = new QLineEdit();
    phoneLineEdit->setPlaceholderText(user.getPhone());
    phoneLineEdit->setFixedHeight(45);

    QLabel *currentPWLabel = new QLabel(editProfileW);
    currentPWLabel->setText("Password");
    QLineEdit *currentPWLineEdit = new QLineEdit();
    currentPWLineEdit->setPlaceholderText("Your Password");
    currentPWLineEdit->setFixedHeight(45);
    currentPWLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton *editProfilebtn = new QPushButton();
    editProfilebtn->setFixedSize(150,45);
    editProfilebtn->setCursor(Qt::PointingHandCursor);
    editProfilebtn->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");

    editProfilebtn->setText("Save");
    connect( editProfilebtn, &QPushButton::clicked, [=](){
        if(firstNameLineEdit->text().isEmpty() || lastNameLineEdit->text().isEmpty() || phoneLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields");
        }
        else{

            if(user.getPassword() != currentPWLineEdit->text()){
                errorLabel->setText("Incorrect password!");
            }
            else if(db.editProfile(user.getUserId(), firstNameLineEdit->text(), lastNameLineEdit->text(), phoneLineEdit->text())){
                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Profile Edited");
                msgBox.setText("Successfully Edited your profile");
                msgBox.setInformativeText("Your profile has been edited please login to continue.");
                QAbstractButton *login = msgBox.addButton(tr("Login"), QMessageBox::YesRole);
                msgBox.exec();
                if(msgBox.clickedButton() == login){
                    loginScreen();
                }
            }
            else{
                errorLabel->setText("Could not change the password!");
            }
        }
    });





    editProfileFormLayout->addWidget(firstNameLabel, 0, 0);
    editProfileFormLayout->addWidget(lastNameLabel, 1, 0);
    editProfileFormLayout->addWidget(phoneLabel, 2, 0);
    editProfileFormLayout->addWidget(currentPWLabel, 3, 0);

    editProfileFormLayout->addWidget(firstNameLineEdit, 0, 1,1,2);
    editProfileFormLayout->addWidget(lastNameLineEdit, 1, 1,1,2);
    editProfileFormLayout->addWidget(phoneLineEdit, 2, 1,1,2);
    editProfileFormLayout->addWidget(currentPWLineEdit, 3, 1,1,2);

    editProfileFormLayout->addWidget(editProfilebtn, 4, 2);

    editProfileFormLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);

    editProfileForm->setLayout(editProfileFormLayout);

    editProfileLayout->addWidget(topWidget, 1);
    editProfileLayout->addWidget(errorLabel, 1);
    editProfileLayout->addWidget(editProfileForm, 8);
    editProfileW->setLayout(editProfileLayout);



}


