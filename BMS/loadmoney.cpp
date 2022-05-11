#include"mainwindow.h"
void MainWindow::loadMoney(QWidget *loadMoneyWidget, QStackedWidget *bookingPages)
{
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *topWidget = new QWidget(loadMoneyWidget);
    topWidget->setStyleSheet("*{background: #fcbe7b; border-radius: 15%}");
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

    QLabel *loadLabel = new QLabel(loadMoneyWidget);
    loadLabel->setText("Load Money");
    loadLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    loadLabel->setFont(font);
    loadLabel->setMaximumHeight(100);
    loadLabel->show();
    topLayout->addWidget(backButton, 1);
    topLayout->addWidget(loadLabel, 9);

    topWidget->setLayout(topLayout);
    QLabel *errorLabel = new QLabel(loadMoneyWidget);
    errorLabel->setText("");
    errorLabel->setStyleSheet("*{color:red;font-family:Artifakt Element;font-size:17px}");
    errorLabel->setAlignment(Qt::AlignHCenter| Qt::AlignTop);
    errorLabel->setFixedHeight(30);


    QWidget *formWidget = new QWidget(loadMoneyWidget);
    formWidget->setStyleSheet("QLineEdit{border:1px solid grey;border-radius:15%; padding-left:10px; font-size:18px; font-family:Artifakt Element; width:400px} QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");
    QGridLayout *loadFormGLayout = new QGridLayout();

    QLabel *emailLabel = new QLabel(loadMoneyWidget);
    emailLabel->setText("User Email");
    QLineEdit *emailLineEdit = new QLineEdit(loadMoneyWidget);
    emailLineEdit->setPlaceholderText("Email");
    emailLineEdit->setFixedHeight(45);

    QLabel *amountLabel = new QLabel(loadMoneyWidget);
    amountLabel->setText("Amount");
    QLineEdit *amountLineEdit = new QLineEdit(loadMoneyWidget);
    amountLineEdit->setPlaceholderText("Amount");
    amountLineEdit->setValidator( new QIntValidator(1, 10000, this));
    amountLineEdit->setFixedHeight(45);

    QLabel *adminPasswordLabel = new QLabel(loadMoneyWidget);
    adminPasswordLabel->setText("Your Password");
    QLineEdit *adminPasswordLineEdit = new QLineEdit(loadMoneyWidget);
    adminPasswordLineEdit->setPlaceholderText("Admin Password");
    adminPasswordLineEdit->setEchoMode(QLineEdit::Password);
    adminPasswordLineEdit->setFixedHeight(45);

    QPushButton *loadButton = new QPushButton();
    loadButton->setFixedSize(200,45);
    loadButton->setCursor(Qt::PointingHandCursor);
    loadButton->setStyleSheet("*{font-weight:bold; background:blue; color: white; border: none ; border-radius:10%; font-size: 18px; font-family:Artifakt Element} :hover{background:white; color:blue; border:1px solid blue}");
    loadButton->setFixedHeight(60);
    loadButton->setText("Load Money");
    connect( loadButton, &QPushButton::clicked, [=](){

        if(emailLineEdit->text().isEmpty() || amountLineEdit->text().isEmpty() || adminPasswordLineEdit->text().isEmpty()){
            errorLabel->setText("Please fill all the fields.");
        }
        else if(user.getPassword() == adminPasswordLineEdit->text()){


            if(db.alreadyRegistred(emailLineEdit->text())){
                if(db.loadMoney(emailLineEdit->text(), amountLineEdit->text().toInt())){

                    QMessageBox msgBox;
                    msgBox.setStyleSheet("QLabel{min-width:300 px; font-size: 14px;} QPushButton{ width:90px; font-size: 14px; }");
                    msgBox.setWindowTitle("Loading Successful");
                    msgBox.setText("Successfully loaded Rs."+amountLineEdit->text()+" on\n"+emailLineEdit->text()+"'s account.");
                    msgBox.exec();

                    //clearing the form
                    errorLabel->setText("");
                    emailLineEdit->setText("");
                    adminPasswordLineEdit->setText("");
                    amountLineEdit->setText("");

                }
                else {
                    errorLabel->setText("Unable to load money");
                }
            }

            else {
               errorLabel->setText("User not found");
            }
        }
        else {
            errorLabel->setText("Password Incorrect");
        }

    });
    loadFormGLayout->addWidget(emailLabel, 0, 0);
    loadFormGLayout->addWidget(emailLineEdit, 0, 1,1,2);
    loadFormGLayout->addWidget(amountLabel, 1, 0);
    loadFormGLayout->addWidget(amountLineEdit, 1, 1,1,2);
    loadFormGLayout->addWidget(adminPasswordLabel, 2, 0);
    loadFormGLayout->addWidget(adminPasswordLineEdit, 2, 1,1,2);
    loadFormGLayout->addWidget(loadButton, 3, 2);
    loadFormGLayout->setAlignment(Qt::AlignHCenter| Qt::AlignTop);

    formWidget->setLayout(loadFormGLayout);

    layout->addWidget(topWidget, 1);
    layout->addWidget(errorLabel,1);
    layout->addWidget(formWidget,8);
    loadMoneyWidget->setLayout(layout);
}
