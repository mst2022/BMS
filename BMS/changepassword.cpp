#include "mainwindow.h"

void MainWindow::changePassword(QStackedWidget *profileStack)
{
    QWidget *changePasswordW = new QWidget();
    QVBoxLayout *changePasswordLayout = new QVBoxLayout();
    profileStack->addWidget(changePasswordW);
    profileStack->setCurrentIndex(1);

    QWidget *topWidget = new QWidget(changePasswordW);
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
        profileStack->removeWidget(changePasswordW);
        delete changePasswordW;
       profileStack->setCurrentIndex(0);
    });

    QLabel *changePasswordLabel = new QLabel(changePasswordW);
    changePasswordLabel->setText("Change Password");
    changePasswordLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    changePasswordLabel->setFont(font);
    changePasswordLabel->setMaximumHeight(100);
    changePasswordLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(changePasswordLabel, 9);
    topWidget->setLayout(topLayout);

    QWidget *changePWform = new QWidget(changePasswordW);
    changePWform->setStyleSheet("*{background:white; border-radius:15%} QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    //for error message
    QLabel *errorLabel = new QLabel(changePWform);
    //error message properties
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setText("");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);


    QGridLayout *changePasswordFormLayout = new QGridLayout();
    changePasswordFormLayout->setColumnMinimumWidth(1,300);

    QLabel *currentPWLabel = new QLabel(changePasswordW);
    currentPWLabel->setText("Current Password");
    QLineEdit *currentPWLineEdit = new QLineEdit();
    currentPWLineEdit->setPlaceholderText("Current Password");
    currentPWLineEdit->setFixedHeight(45);
    currentPWLineEdit->setEchoMode(QLineEdit::Password);


    QLabel *newPWLabel = new QLabel(changePasswordW);
    newPWLabel->setText("New Password");
    QLineEdit *newPWLineEdit = new QLineEdit();
    newPWLineEdit->setPlaceholderText("Password");
    newPWLineEdit->setFixedHeight(45);
    newPWLineEdit->setEchoMode(QLineEdit::Password);

    QLabel *reNewPWLabel = new QLabel(changePasswordW);
    reNewPWLabel->setText("Confirm Password");
    QLineEdit *reNewPWLabelLineEdit = new QLineEdit();
    reNewPWLabelLineEdit->setPlaceholderText("Confirm Password");
    reNewPWLabelLineEdit->setFixedHeight(45);
    reNewPWLabelLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton *changePWbtn = new QPushButton();
    changePWbtn->setFixedSize(200,45);
    changePWbtn->setCursor(Qt::PointingHandCursor);
    changePWbtn->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");

    changePWbtn->setText("Change Password");
    connect( changePWbtn, &QPushButton::clicked, [=](){
        if(currentPWLineEdit->text().isEmpty() || newPWLineEdit->text().isEmpty() || reNewPWLabelLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields");
        }
        else if(newPWLineEdit->text() != reNewPWLabelLineEdit->text()){
            errorLabel->setText("Password did not match!");
        }
        else{

            if(user.getPassword() != currentPWLineEdit->text()){
                errorLabel->setText("Incorrect password!");
            }
            else if(db.changePassword(user.getUserId(), newPWLineEdit->text())){
                QMessageBox msgBox;
                msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                msgBox.setWindowTitle("Password Changed");
                msgBox.setText("Successfully Changed Password");
                msgBox.setInformativeText("Your password has been changed please login to continue.");
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





    changePasswordFormLayout->addWidget(currentPWLabel, 0, 0);
    changePasswordFormLayout->addWidget(newPWLabel, 1, 0);
    changePasswordFormLayout->addWidget(reNewPWLabel, 2, 0);

    changePasswordFormLayout->addWidget(currentPWLineEdit, 0, 1,1,2);
    changePasswordFormLayout->addWidget(newPWLineEdit, 1, 1,1,2);
    changePasswordFormLayout->addWidget(reNewPWLabelLineEdit, 2, 1,1,2);

    changePasswordFormLayout->addWidget(changePWbtn, 3, 2);

    changePasswordFormLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);

    changePWform->setLayout(changePasswordFormLayout);

    changePasswordLayout->addWidget(topWidget, 1);
    changePasswordLayout->addWidget(errorLabel, 1);
    changePasswordLayout->addWidget(changePWform, 8);
    changePasswordW->setLayout(changePasswordLayout);

}
