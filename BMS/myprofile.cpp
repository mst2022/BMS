#include"mainwindow.h"

void MainWindow::myProfile(QWidget *profileW, QWidget *parentW)
{

    QStackedWidget *profileStack = new QStackedWidget(profileW);
    QLabel *profilelab = new QLabel(profileW);
    QVBoxLayout *profileLayout = new QVBoxLayout();
    profilelab->setText("My Profile");
    profilelab->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont font("Sitka",25,QFont::Bold);
    profilelab->setFont(font);
    profilelab->setMaximumHeight(100);


    QWidget *infoWidget = new QWidget(profileW);
    QVBoxLayout *infoVLayout = new QVBoxLayout();
    profileStack->addWidget(infoWidget);
    infoWidget->setStyleSheet("QLabel{padding:16px;font-weight:bold; font-size:18px; font-family:Artifakt Element}");

    QLabel *profilePic = new QLabel(infoWidget);
    profilePic->setStyleSheet("*{border: none}");
    QPixmap lo(":/images/defaultprofile.jpg");
    profilePic->setPixmap(lo.scaled(100,100));
    profilePic->setMaximumHeight(170);
    profilePic->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    QGridLayout *infoGrid = new QGridLayout();
    infoVLayout->addWidget(profilePic);
    infoVLayout->addLayout(infoGrid);
    infoWidget->setLayout(infoVLayout);


    QLabel *nameLabel = new QLabel(profilelab);
    nameLabel->setText("Name: ");
    QLabel *name = new QLabel(profileW);
    name->setText(user.getFName() + " " + user.getLName());

    QLabel *profileBalanceLabel = new QLabel(profilelab);
    if(user.getAdminStatus()){
        profileBalanceLabel->setText("Status: ");
    }
    else{
        profileBalanceLabel->setText("Current Balance: ");
    }

    profileBalance = new QLabel(profileW);
    if(user.getAdminStatus()){
        profileBalance->setText("ADMIN");
    }
    else{
        profileBalance->setText(balance->text());
    }


    QLabel *emailLabel = new QLabel(profilelab);
    emailLabel->setText("Email: ");
    QLabel *email = new QLabel(profileW);
    email->setText(user.getEmail());

    QLabel *numberLabel = new QLabel(profilelab);
    numberLabel->setText("Number: ");
    QLabel *number = new QLabel(profileW);
    number->setText(user.getPhone());

    QLabel *joinedLabel = new QLabel(profilelab);
    joinedLabel->setText("Joined On: ");
    QLabel *joined = new QLabel(profileW);
    joined->setText(user.getJoinedDate());



    QPushButton *editInfoBtn = new QPushButton(infoWidget);
    editInfoBtn->setText("Edit Profile");
    editInfoBtn->setFixedSize(160,45);
    editInfoBtn->setCursor(Qt::PointingHandCursor);
    editInfoBtn->setStyleSheet("*{font-weight:bold; color: grey; border: 1px solid grey; border-radius:7%; font-size: 18px; font-family:Artifakt Element} :hover{background:grey; color:white}");
    connect( editInfoBtn, &QPushButton::clicked, [=](){
       editProfile(profileStack);

    });

    QPushButton *changePasswordBtn = new QPushButton(infoWidget);
    changePasswordBtn->setText("Change Password");
    changePasswordBtn->setFixedSize(160,45);
    changePasswordBtn->setCursor(Qt::PointingHandCursor);
    changePasswordBtn->setStyleSheet("*{font-weight:bold; color: grey; border: 1px solid grey; border-radius:7%; font-size: 18px; font-family:Artifakt Element} :hover{background:grey; color:white}");
    connect(changePasswordBtn, &QPushButton::clicked, [=](){
       changePassword(profileStack);

    });


    infoGrid->addWidget(nameLabel, 0, 0);
    infoGrid->addWidget(profileBalanceLabel, 1, 0);
    infoGrid->addWidget(emailLabel, 2, 0);
    infoGrid->addWidget(numberLabel, 3, 0);
    infoGrid->addWidget(joinedLabel,4, 0);
    infoGrid->addWidget(changePasswordBtn, 5, 0);

    infoGrid->addWidget(name, 0, 1);
    infoGrid->addWidget(profileBalance, 1, 1);
    infoGrid->addWidget(email, 2, 1);
    infoGrid->addWidget(number, 3, 1);
    infoGrid->addWidget(joined,4, 1);
    infoGrid->addWidget(editInfoBtn, 5, 1);


    infoGrid->setAlignment(Qt::AlignHCenter| Qt::AlignTop);



    profileLayout->addWidget(profilelab,1);
    profileLayout->addWidget(profileStack);
    profileW->setLayout(profileLayout);
}


