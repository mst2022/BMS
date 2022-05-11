#include "mainwindow.h"
#include <QLabel>
#include <database.h>
#include <string>
#include <QHeaderView>
#include <QDateTime>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPixmap>
#include <QJsonObject>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowTitle("Booking Management System");
        if(db.connectDB()){

            loginScreen();  // TO Display Home Screen

        }
        else{ // If database connection is not established
        QMessageBox::critical(this,"Error Connection","Error connecting to Database"); //Displays a popup warning message
        loginScreen();
        }

}




void MainWindow::currentTime()
{
    QTime time = QTime::currentTime();
    timeLabel->setText(time.toString("hh:mm"));
}

void MainWindow::displayInfo(int row, int col){

        busDetails->setText("Bus Name:        " + busTable->item(row, 0)->text() + "<br>" +
                            "From:            " + busTable->item(row, 1)->text() + "<br>" +
                            "To:              " + busTable->item(row, 2)->text() + "<br>" +
                            "Date:              " + busTable->item(row, 3)->text() + "<br>" +
                            "Departure Time:  " + busTable->item(row, 4)->text() + "<br>" +
                            "Price:           Rs." + busTable->item(row, 5)->text()
                            );
        bookNowButton->setVisible(true);
        rowIndex = row;
}

void MainWindow::displayMovieInfo(int row, int col)
{
    movieDetails->setText("Movie Name:        " + movieTable->item(row, 0)->text() + "<br>" +
                        "Date:              " + movieTable->item(row, 1)->text() + "<br>" +
                        "Show Time:  " + movieTable->item(row, 2)->text() + "<br>" +
                        "Description: " + movieTable->item(row, 3)->text() + "<br>" +
                        "Price:           Rs." + movieTable->item(row, 4)->text()
                        );
    bookNowButtonMoive->setVisible(true);
    rowIndex = row;

}

void MainWindow::changeSeats(){
    QString temp="";
    int j = 0;
    for(int i=0;i<17;i++){
        if(totalSelected[i]){
            switch (i){
            case 0:{
                selectedSeatsNums[j++] ="A1";
                temp+="A1 ";
                break;
            }
            case 1:{
                selectedSeatsNums[j++] ="A2";
                temp+="A2 ";
                break;
            }
            case 2:{
                selectedSeatsNums[j++] ="A3";
                temp+="A3 ";
                break;
            }
            case 3:{
                selectedSeatsNums[j++] ="A4";
                temp+="A4 ";
                break;
            }
            case 4:{
                selectedSeatsNums[j++] ="B1";
                temp+="B1 ";
                break;
            }
            case 5:{
                selectedSeatsNums[j++] ="B2";
                temp+="B2 ";
                break;
            }
            case 6:{
                selectedSeatsNums[j++] ="B3";
                temp+="B3 ";
                break;
            }
            case 7:{
                selectedSeatsNums[j++] ="B4";
                temp+="B4 ";
                break;
            }
            case 8:{
                selectedSeatsNums[j++] ="C1";
                temp+="C1 ";
                break;
            }
            case 9:{
                selectedSeatsNums[j++] ="C2";
                temp+="C2 ";
                break;
            }
            case 10:{
                selectedSeatsNums[j++] ="C3";
                temp+="C3 ";
                break;
            }
            case 11:{
                selectedSeatsNums[j++] ="C4";
                temp+="C4 ";
                break;
            }
            case 12:{
                selectedSeatsNums[j++] ="D1";
                temp+="D1 ";
                break;
            }
            case 13:{
                selectedSeatsNums[j++] ="D2";
                temp+="D2 ";
                break;
            }
            case 14:{
                selectedSeatsNums[j++] ="D3";
                temp+="D3 ";
                break;
            }
            case 15:{
                selectedSeatsNums[j++] ="D4";
                temp+="D4 ";
                break;
            }
            case 16:{
                selectedSeatsNums[j++] ="D5";
                temp+="D5 ";
                break;
            }

               default:break;

            }
        }
    }

    selectedSeatsNums[j++] = "";
    selectSeats->setText(temp);
    totalAmt->setText("Rs. " + QString::number(total));
}



void MainWindow::changeMovieSeats(){
    QString temp="";
    int j = 0;
    for(int i=0;i<17;i++){
        if(totalSelected[i]){
            switch (i){
            case 0:{
                selectedSeatsNums[j++] ="A1";
                temp+="A1 ";
                break;
            }
            case 1:{
                selectedSeatsNums[j++] ="A2";
                temp+="A2 ";
                break;
            }
            case 2:{
                selectedSeatsNums[j++] ="B1";
                temp+="B1 ";
                break;
            }
            case 3:{
                selectedSeatsNums[j++] ="B2";
                temp+="B2 ";
                break;
            }
            case 4:{
                selectedSeatsNums[j++] ="B3";
                temp+="B3 ";
                break;
            }
            case 5:{
                selectedSeatsNums[j++] ="B4";
                temp+="B4 ";
                break;
            }
            case 6:{
                selectedSeatsNums[j++] ="B5";
                temp+="B5 ";
                break;
            }
            case 7:{
                selectedSeatsNums[j++] ="C1";
                temp+="C2 ";
                break;
            }
            case 8:{
                selectedSeatsNums[j++] ="C2";
                temp+="C2 ";
                break;
            }
            case 9:{
                selectedSeatsNums[j++] ="C3";
                temp+="C3 ";
                break;
            }
            case 10:{
                selectedSeatsNums[j++] ="C4";
                temp+="C4 ";
                break;
            }
            case 11:{
                selectedSeatsNums[j++] ="C5";
                temp+="C5 ";
                break;
            }
            case 12:{
                selectedSeatsNums[j++] ="D1";
                temp+="D1 ";
                break;
            }
            case 13:{
                selectedSeatsNums[j++] ="D2";
                temp+="D2 ";
                break;
            }
            case 14:{
                selectedSeatsNums[j++] ="D3";
                temp+="D3 ";
                break;
            }
            case 15:{
                selectedSeatsNums[j++] ="D4";
                temp+="D4 ";
                break;
            }
            case 16:{
                selectedSeatsNums[j++] ="D5";
                temp+="D5 ";
                break;
            }

               default:break;

            }
        }
    }

    selectedSeatsNums[j++] = "";
    selectSeats->setText(temp);
    totalAmt->setText("Rs. " + QString::number(total));
}



void MainWindow::bookedSeat(QPushButton *b)
{
        b->setDisabled(true);
        b->setStyleSheet("*{background-color:#ed1f1f; color: white}");
}




void MainWindow::setActiveTab(QPushButton *active, QPushButton *inActive1, QPushButton *inActive2, QPushButton *inActive3)
{
    active->setStyleSheet("*{color: red; font-weight: bold}");
    inActive1->setStyleSheet("*{color: black; font-weight: none :hover{color: red}}");
    inActive2->setStyleSheet("*{color: black; font-weight: none} :hover{color: red}");
    if(inActive3 != NULL){
        inActive3->setStyleSheet("*{color: black; font-weight: none} :hover{color: red}");
    }


}

void MainWindow::downloadFinished(QNetworkReply *reply){
   QByteArray bts = reply->readAll();
      QString str(bts);
      qDebug() << "Reply:"<<str;
}

void MainWindow:: emailRegister(QString email, QString name)
{
       QJsonObject mainObject;
      mainObject.insert("name", name);
      mainObject.insert("toEmail", email);


      QJsonDocument jsonDoc;
         jsonDoc.setObject(mainObject);
         QByteArray data = jsonDoc.toJson();
   QNetworkAccessManager *man = new QNetworkAccessManager(this);
   connect(man,&QNetworkAccessManager::finished,this,&MainWindow::downloadFinished);
   QString registerUrl= "http://localhost:3000/register";
   const QUrl myurl = QUrl(registerUrl);
   QNetworkRequest request(myurl);
   request.setRawHeader("Content-Type", "application/json");
       man->post(request, data);


}

void MainWindow::emailCheckout(int bookingId, bus b, int total, QString s){

   QJsonObject mainObject;
   mainObject.insert("totalSeats", s);
  mainObject.insert("name", user.getFName() );
  mainObject.insert("from", b.getName() );
  mainObject.insert("to", b.getTo());
  mainObject.insert("date", b.getDate());
  mainObject.insert("time",b.getTime());
  mainObject.insert("Bid",bookingId );
  mainObject.insert("price",b.getPrice());
  mainObject.insert("totalPrice", total);
  mainObject.insert("busName", b.getName());
  mainObject.insert("name", user.getFName());
  mainObject.insert("toEmail", user.getEmail());


  QJsonDocument jsonDoc;
     jsonDoc.setObject(mainObject);
     QByteArray data = jsonDoc.toJson();
QNetworkAccessManager *man = new QNetworkAccessManager(this);
QString checkoutUrl = "http://localhost:3000/checkout/bus";
connect(man,&QNetworkAccessManager::finished,this,&MainWindow::downloadFinished);
const QUrl myurl = QUrl(checkoutUrl);
QNetworkRequest request(myurl);
request.setRawHeader("Content-Type", "application/json");
man->post(request, data);
}

void MainWindow::emailMovieCheckout(int bookingId, movie m, int total, QString s)
{


  QJsonObject mainObject;
  mainObject.insert("totalSeats", s);
 mainObject.insert("name", user.getFName() );
 mainObject.insert("showTime", m.getTime() );

 mainObject.insert("date", m.getDate());

 mainObject.insert("Bid",bookingId );
 mainObject.insert("price",m.getPrice());
 mainObject.insert("totalPrice", total);
 mainObject.insert("movieName", m.getName());
 mainObject.insert("toEmail", user.getEmail());

 QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);
    QByteArray data = jsonDoc.toJson();
QNetworkAccessManager *man = new QNetworkAccessManager(this);
QString checkoutUrl = "http://localhost:3000/checkout/movies";
connect(man,&QNetworkAccessManager::finished,this,&MainWindow::downloadFinished);
const QUrl myurl = QUrl(checkoutUrl);
QNetworkRequest request(myurl);
request.setRawHeader("Content-Type", "application/json");
man->post(request, data);
}





MainWindow::~MainWindow()
{

}

