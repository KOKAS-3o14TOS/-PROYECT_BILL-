// =========================================================
// File: main.cpp
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// To compile: g++ -std=c++11 main.cpp -o app
// To execute: ./app input_file output_file
// =========================================================
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bill.h"
#include "operator.h"
#include "vox.h"
#include "internet.h"
#include "customer.h"

using namespace std;

int main(int argc, char* argv[]) {
/*
// ---- CLASE BILL ----
cout <<" CLASE BILL "<< endl;
Bill b(100.0);
cout <<" ---- CONSTRUCTOR ----"<< endl;
cout << "LimitAmout " << b.getLimitAmount() << endl;
cout << "CurrentDebt " << b.getCurrentDebt() << endl; 
cout << "TotalMoneySpent "<< b.getTotalMoneySpent() << endl;
cout << " ---- CHECK ----" << endl;
cout << " Check 50 " << b.check(50)<<endl;
cout << " Check 150 " << b.check(150) << endl;
cout << " ---- ADD-PAY ----" << endl;
Bill bb(100);
bb.add(50);
bb.pay(20);
cout << "CurrentDebt " << bb.getCurrentDebt() << endl;
cout << "TotalMoneySpent " << bb.getTotalMoneySpent() << endl;
bb.pay(-10);
cout << "CurrentDebt " << bb.getCurrentDebt() << endl;
cout << "TotalMoneySpent " << bb.getTotalMoneySpent() << endl; 
bb.pay(100);
cout << "CurrentDebt " << bb.getCurrentDebt() << endl;
cout << "TotalMoneySpent " << bb.getTotalMoneySpent() << endl;
cout << " ---- COPY CONSTRUCTOR ----" << endl;

// ---- COPIA CONSTRUCTOR ----
cout<<"---- Constructor copia ----"<< endl;
Bill copiaBill(bb);
cout << "LimitAmout " << copiaBill.getLimitAmount() << endl;
cout << "CurrentDebt " << copiaBill.getCurrentDebt() << endl;
cout << "TotalMoneySpent " << copiaBill.getTotalMoneySpent() << endl;

cout << endl;
cout << endl;
cout << endl;
// ---- CLASE OPERATOR VOX ----
cout << " CLASE OPERATOR VOX " << endl;
VoxOperator v(1, 10.0, 10.0, 10.0, 10.0, VOX);
cout <<" ---- CONSTRUCTOR ----"<< endl;
cout <<"Id " <<v.getId() << endl;
cout <<"DiscountRate "<< v.getDiscountRate() << endl;
cout <<"TalkingChage "<< v.getTalkingChage() << endl;
cout <<"MessageCost "<< v.getMessageCost() << endl;
cout <<"NetworkCharge "<< v.getNetworkCharge() << endl;
cout <<"TotalTalkingChage " << v.getTotalSpentTalkingTime() << endl;
cout <<"TotalMessageSent "<< v.getTotalMessageSent() << endl;
cout <<"TotalInternetUsage "<< v.getTotalInternetUsage() << endl;
cout <<"Type "<< v.getType() << endl;
cout << " ---- ADD ----" << endl;
v.addTalkingTime(10);
v.addTotalMessageSent(10);
v.addTotalInternetUsage(10);
cout << "TotalTalkingChage " << v.getTotalSpentTalkingTime() << endl;
cout << "TotalMessageSent " << v.getTotalMessageSent() << endl;
cout << "TotalInternetUsage " << v.getTotalInternetUsage() << endl;
cout << " ---- CALCULATE ----" << endl;
cout << "-TalkingCost-" << endl;
cout << v.calculateTalkingCost(10, 15) << endl;
cout << "TotalTalkingChage " << v.getTotalSpentTalkingTime() << endl;
cout << v.calculateTalkingCost(-10, 15) << endl;
cout << "TotalTalkingChage " << v.getTotalSpentTalkingTime() << endl;
cout << "-MessageCost-" << endl;
cout << v.calculateMessageCost(-10, 1, 3) << endl;
cout << "TotalMessageSent " << v.getTotalMessageSent() << endl;
cout << v.calculateMessageCost(10, 1, 3) << endl;
cout << "TotalMessageSent " << v.getTotalMessageSent() << endl;
cout << v.calculateMessageCost(10, 1, 1) << endl;
cout << "TotalMessageSent " << v.getTotalMessageSent() << endl;
cout << "-NetworkCost-" << endl;
cout << v.calculateNetworkCost(-10) << endl;
cout << "TotalInternetUsage " << v.getTotalInternetUsage() << endl;
cout << v.calculateNetworkCost(10) << endl;
cout << "TotalInternetUsage " << v.getTotalInternetUsage() << endl;

// ---- COPIA CONSTRUCTOR ----
cout << "---- Constructor copia ----" << endl;
VoxOperator vox_(1, 10.00, 10.00, 10.00, 10, VOX);
vox_.addTotalMessageSent(10);
vox_.addTalkingTime(200);
vox_.addTotalInternetUsage(53);

VoxOperator copiaVox(vox_);
cout << "Id " << copiaVox.getId() << endl;
cout << "DiscountRate " << copiaVox.getDiscountRate() << endl;
cout << "TalkingChage " << copiaVox.getTalkingChage() << endl;
cout << "MessageCost " << copiaVox.getMessageCost() << endl;
cout << "NetworkCharge " << copiaVox.getNetworkCharge() << endl;
cout << "TotalTalkingChage " << copiaVox.getTotalSpentTalkingTime() << endl;
cout << "TotalMessageSent " << copiaVox.getTotalMessageSent() << endl;
cout << "TotalInternetUsage " << copiaVox.getTotalInternetUsage() << endl;
cout << "Type " << copiaVox.getType() << endl;
cout << endl;
cout << endl;
cout << endl;
// ---- CLASE OPERATOR INTERNET ----
cout << " CLASS-INTERNET " << endl;
InternetOperator internet(1, 10.0, 10.0, 10.0, 10, INTERNET);
cout << " ---- CONSTRUCTOR ----" << endl;
cout << "Id " << internet.getId() << endl;
cout << "DiscountRate " << internet.getDiscountRate() << endl;
cout << "TalkingChage " << internet.getTalkingChage() << endl;
cout << "MessageCost " << internet.getMessageCost() << endl;
cout << "NetworkCharge " << internet.getNetworkCharge() << endl;
cout << "TotalTalkingChage " << internet.getTotalSpentTalkingTime() << endl;
cout << "TotalMessageSent " << internet.getTotalMessageSent() << endl;
cout << "TotalNetworkCharge " << internet.getTotalInternetUsage() << endl;
cout << "Type " << internet.getType() << endl;
// METODOS ADD
cout << " ---- ADD ----" << endl;
internet.addTalkingTime(-10);
cout << "TotalTalkingTime " << internet.getTotalSpentTalkingTime() << endl;
internet.addTalkingTime(10);
cout << "TotalTalkingTime " << internet.getTotalSpentTalkingTime() << endl;

internet.addTotalMessageSent(-10);
cout << "TotalMessageCost" << internet.getMessageCost() << endl;
internet.addTotalMessageSent(10);
cout << "TotalMessageCost" << internet.getMessageCost() << endl;

internet.addTotalInternetUsage(-10);
cout << "TotalInternetUsage " << internet.getTotalInternetUsage() << endl;
internet.addTotalInternetUsage(10);
cout << "TotalInternetUsage " << internet.getTotalInternetUsage() << endl;
// METODOS CALCULAR
cout << "----CALCULATE----" << endl;
cout << "calculateTalkingCost " << internet.calculateTalkingCost(-10, 40) << endl;
cout << "calculateTalkingCost " << internet.calculateTalkingCost(10, 40) << endl;
cout << "calculateTalkingCost " << internet.calculateTalkingCost(1, 15) << endl;
cout << endl;
cout << "calculateMessageCost " << internet.calculateMessageCost(-10, 1, 3) << endl;
cout << "calculateMessageCost " << internet.calculateMessageCost(10, 1, 3) << endl;
cout << "calculateMessageCost " << internet.calculateMessageCost(2, 1, 1) << endl;
cout << endl;
cout << "calculateNetworkCost " << internet.calculateNetworkCost(-10) << endl;
cout << "calculateNetworkCost " << internet.calculateNetworkCost(10) << endl;
internet.addTotalInternetUsage(10);
cout << "TotalNetworkCharge " << internet.getTotalInternetUsage() << endl;
cout << "calculateNetworkCost " << internet.calculateNetworkCost(10) << endl;
// ---- COPIA CONSTRUCTOR ----
cout << "---- Constructor copia ----" << endl;
InternetOperator op(1, 10.00, 10.00, 10.00, 10, INTERNET);
op.addTotalMessageSent(10);
op.addTalkingTime(200);
op.addTotalInternetUsage(53);

InternetOperator copiaInternet(op);
cout << "Getters-COPIA" << endl;
cout << "Id " << copiaInternet.getId() << endl;
cout << "DiscountRate " << copiaInternet.getDiscountRate() << endl;
cout << "TalkingChage " << copiaInternet.getTalkingChage() << endl;
cout << "MessageCost " << copiaInternet.getMessageCost() << endl;
cout << "NetworkCharge " << copiaInternet.getNetworkCharge() << endl;
cout << "TotalTalkingChage " << copiaInternet.getTotalSpentTalkingTime() << endl;
cout << "TotalMessageSent " << copiaInternet.getTotalMessageSent() << endl;
cout << "TotalNetworkCharge " << copiaInternet.getTotalInternetUsage() << endl;
cout << "Type " << copiaInternet.getType() << endl;
cout << endl;
cout << endl;
cout << endl;
// ---- CLASE COSTUMBER ----
cout << " CLASE COSTUMBER " << endl;
VoxOperator *vox = new VoxOperator(1, 10.00, 10.00, 10.00, 10, VOX);
Customer c1a(1, "juan", 40, vox, 100.0);
Customer c2a(2, "pedro", 15, vox, 100.0);
cout << " ---- CONSTRUCTOR ----" << endl;
cout<<"Id "<<c1a.getId()<< endl;
cout << "Name " << c1a.getName() << endl;
cout << "Age " << c1a.getAge() << endl;
cout << "TotalSepentTalkingTime " << c1a.getTotalSpentTalkingTime() << endl;
cout << "TotalMessageSent " << c1a.getTotalMessageSent() << endl;
cout << "TotalinternetUsage " << c1a.getTotalInternetUsage() << endl;
cout << "Operator " << c1a.getOperator() << endl;
cout << "GetOperator Id " << c1a.getOperator()->getId() << endl;
cout << "Bill " << c1a.getBill() << endl;
cout << "Bill getLimitAmout " << c1a.getBill()->getLimitAmount() << endl;

cout << " ---- TALK ----" << endl;
VoxOperator *v1 = new VoxOperator(1, 10.00, 10.00, 10.00, 10, VOX);
VoxOperator *v2 = new VoxOperator(2, 10.00, 10.00, 10.00, 10, VOX);
Customer c1(1, "juan", 40, v1, 1000.0);
Customer c2(2, "pedro", 15, v1, 1000.0);
Customer c3(2, "luis", 40, v2, 10.0);
c1.talk(-10, c2);
cout << "CurrentDebt " << c1.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "getOperator C2 " << c2.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c1.getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C2 " << c2.getTotalSpentTalkingTime() << endl;
c1.talk(10, c1);
cout << "CurrentDebt " << c1.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c1.getTotalSpentTalkingTime() << endl;
c1.talk(10000, c2);
cout << "CurrentDebt " << c1.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "getOperator C2 " << c2.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c1.getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C2 " << c2.getTotalSpentTalkingTime() << endl;
c1.talk(10, c2);
cout << "CurrentDebt " << c1.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "getOperator C2 " << c2.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c1.getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C2 " << c2.getTotalSpentTalkingTime() << endl;
c2.talk(10, c1);
cout << "CurrentDebt " << c2.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c2.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "getOperator C2 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c2.getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C2 " << c1.getTotalSpentTalkingTime() << endl;
c1.talk(10, c3);
cout << "CurrentDebt " << c1.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "getOperator C3 " << c3.getOperator()->getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C1 " << c1.getTotalSpentTalkingTime() << endl;
cout << "totalSpentTalkingTime C3 " << c3.getTotalSpentTalkingTime() << endl;

cout << " ---- MESSAGE ----" << endl;
VoxOperator *v1_ = new VoxOperator(1, 10.00, 10.00, 10.00, 10, VOX);
VoxOperator *v2_ = new VoxOperator(2, 10.00, 10.00, 10.00, 10, VOX);
Customer c1_(1, "juan", 40, v1_, 1000.0);
Customer c2_(2, "pedro", 15, v1_, 1000.0);
Customer c3_(3, "luis", 40, v2_, 10.0);
c1_.message(-10, c2_);
cout << "CurrentDebt " << c1_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
cout << "totalMessageSent " << c2_.getTotalMessageSent() << endl;
c1_.message(10, c1_);
cout << "CurrentDebt " << c1_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
c1_.message(10000, c2_);
cout << "CurrentDebt " << c1_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "getOperator C2 " << c2_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
cout << "totalMessageSent " << c2_.getTotalMessageSent() << endl;
c1_.message(10, c2_);
cout << "CurrentDebt " << c1_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "getOperator C2 " << c2_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
cout << "totalMessageSent " << c2_.getTotalMessageSent() << endl;
c2_.message(10, c1_);
cout << "CurrentDebt " << c2_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c2_.getOperator()->getTotalMessageSent() << endl;
cout << "getOperator C2 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c2_.getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
c1_.message(10, c3_);
cout << "CurrentDebt " << c1_.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1_.getOperator()->getTotalMessageSent() << endl;
cout << "getOperator C3 " << c3_.getOperator()->getTotalMessageSent() << endl;
cout << "totalMessageSent " << c1_.getTotalMessageSent() << endl;
cout << "totalMessageSent " << c3_.getTotalMessageSent() << endl;
VoxOperator *v1__ = new VoxOperator(1, 10.00, 10.00, 10.00, 10, VOX);
Customer c1__(1, "juan", 40, v1__, 1000.0);
c1__.connection(-10);
cout << "CurrentDebt " << c1__.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1__.getOperator()->getTotalInternetUsage() << endl;
cout << "totalMessageSent " << c1__.getTotalInternetUsage() << endl;
c1__.connection(1000);
cout << "CurrentDebt " << c1__.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1__.getOperator()->getTotalInternetUsage() << endl;
cout << "totalMessageSent " << c1__.getTotalInternetUsage() << endl;
c1__.connection(10);
cout << "CurrentDebt " << c1__.getBill()->getCurrentDebt() << endl;
cout << "getOperator C1 " << c1__.getOperator()->getTotalInternetUsage() << endl;
cout << "totalMessageSent " << c1__.getTotalInternetUsage() << endl;
cout << " ---- toString ----" << endl;
cout << c1__.toString() << endl;
*/
// --- MAIN ----
// Definir la el nombre para lectura de archivos
  ifstream inputFile; // input
  ofstream outputFile; // output

// ---- VARIABLES ----

// Case varaibles
  string name;
  int customerCount =0, operatorCount = 0;
  int age, idOperator, caso, type, idCustomer1, idCustomer2, minute, quantity, amount;
  double limitAmount, talkingCharge, messageCost, networkCharge, discountRate;
  int C,O,N;

// Vectores
  vector<Customer *> customers(C); // 
  vector<Operator *> operators(O);
  customers.resize(C);
  operators.resize(O);

// Abre archivo 
  inputFile.open(argv[1]); // input
  outputFile.open(argv[2]); // output
  inputFile >> C >> O >> N; // Guarda C,O,N del archivos input

// Maximo Talk
  int max_id_talking=0;
  int max_minutes=0;
// Maximo Message
  int max_id_messaging = 0;
  int max_messages = 0;
// Maximo Internet
  int max_id_internet = 0;
  int max_internet = 0;

// ---- SECCION UNO ----
  // Argumentos diferentes 3
  if (argc != 3)
  {
    cout << "Archivo usando: " << argv[0] << "Entrada Salida"<< "\n";
  }

// Archivo si no existe
  if (inputFile.fail() || outputFile.fail())
  {
    cout <<"Uno de los dos archivos no se pudo encontrar";
    return -1;
  }
// ---- SECCION DOS ----

// Selecciona el caso a cumplir 
  for (int i = 0; i < N; i++)
  {
    inputFile >> caso;
    switch (caso)
    {
    case 1: // Creando un nuevo cliente.
      inputFile >> type >> name >> age >> idOperator >> limitAmount;
      customers[customerCount] = new Customer(customerCount, name, age, operators[idOperator], limitAmount);
      customerCount++;
      break;
    case 2: // Creando un nuevo operador.
      inputFile >> type >> talkingCharge >> messageCost >> networkCharge >> discountRate;
      if (type == 1)
      {
        operators[operatorCount] = new VoxOperator(operatorCount, talkingCharge, messageCost, networkCharge, discountRate, VOX);
        operatorCount++;
      }
      else if (type == 2)
      {
        operators[operatorCount] = new InternetOperator(operatorCount, talkingCharge, messageCost, networkCharge, discountRate, INTERNET);
        operatorCount++;
      }
      break;
    case 3: // Un cliente puede hablar con otro cliente.
      inputFile >> type >> idCustomer1 >> idCustomer2 >> minute;
      customers[idCustomer1]->talk(minute,*customers[idCustomer2]);
      break;
    case 4: // Un cliente puede enviar un mensaje a otro cliente.
      inputFile >> type >> idCustomer1 >> idCustomer2 >> quantity;
      customers[idCustomer1]->message(quantity,*customers[idCustomer2]);
      break;
    case 5: // Un cliente puede conectarse a Internet.
      inputFile >> type >> idCustomer1 >> amount;
      customers[idCustomer1]->connection(amount);
      break;
    case 6: // Un cliente puede pagar sus facturas.
      inputFile >> type >> idCustomer1 >> amount;
      customers[idCustomer1]->pay(amount);
      break;
    case 7: // Un cliente puede cambiar de operador.
      inputFile >> type >> idCustomer1 >> idOperator;
      customers[idCustomer1]->setOperator(operators[idOperator]);
      break;
    case 8: // Un cliente puede cambiar su límite de Factura.
      inputFile >> type >> idCustomer1 >> limitAmount;
      customers[idCustomer1]->getBill()->changeTheLimit(limitAmount);
      break;
    }
  }
// ---- SECCION TRES ----
  //vector<Operator *>::iterator itr_op; FORMA DIFERENTES
// Muestra los elementos del vector operator
  for (int i=0;i<operators.size();i++) 
  {
    outputFile << operators[i]->toString();
  }
// Muestra los elementos del vector customers
  for (int i = 0; i < customers.size(); i++)
  {
    outputFile << customers[i]->toString();
  }

// ---- SECCION CUATRO ----
// Calcular el mayor de los id con más Talk
  for (int i = 0; i < customers.size(); i++){
    if(customers[i]->getTotalSpentTalkingTime()>max_minutes){
      max_id_talking=customers[i]->getId();
      max_minutes=customers[i]->getTotalSpentTalkingTime();
    }
    else if (customers[i]->getTotalSpentTalkingTime() == max_minutes){
      if(customers[i]->getId()<max_id_talking){
        max_id_talking = customers[i]->getId();
        max_minutes = customers[i]->getTotalSpentTalkingTime();
      }
    }
  }
// Calcular el mayor de los id con más Menssage
  for (int i = 0; i < customers.size(); i++)
  {
    if (customers[i]->getTotalMessageSent() > max_messages)
    {
      max_id_messaging = customers[i]->getId();
      max_messages = customers[i]->getTotalMessageSent();
    }
    else if (customers[i]->getTotalMessageSent() == max_messages)
    {
      if (customers[i]->getId() < max_id_messaging)
      {
        max_id_messaging = customers[i]->getId();
        max_messages = customers[i]->getTotalMessageSent();
      }
    }
  }
// Calcular el mayor de los id con más Internet
  for (int i = 0; i < customers.size(); i++)
  {
    if (customers[i]->getTotalInternetUsage() > max_internet)
    {
      max_id_internet = customers[i]->getId();
      max_internet = customers[i]->getTotalSpentTalkingTime();
    }
    else if (customers[i]->getTotalSpentTalkingTime() == max_internet)
    {
      if (customers[i]->getId() < max_id_internet)
      {
        max_id_internet = customers[i]->getId();
        max_internet = customers[i]->getTotalSpentTalkingTime();
      }
    }
  }

// ---- SECCION CINCIO ----
// Escribe los valores de la seccion cuatro
  outputFile << customers[max_id_talking]->getName() << ": "<< customers[max_id_talking]->getTotalSpentTalkingTime() << endl;

  outputFile << fixed << setprecision(2) << customers[max_id_messaging]->getName() << ": "<< customers[max_id_messaging]->getTotalMessageSent() << endl;

  outputFile << fixed << setprecision(2) << customers[max_id_internet]->getName() << ": "<< customers[max_id_internet]->getTotalInternetUsage() << endl;

// ---- SECCION SEIS ----
// Cierra todos los terminos 
  inputFile.close();
  outputFile.close();

  for (int i = 0; i < customers.size(); ++i)
  {
    delete customers[i];
  }

  // Deconstruct operators
  for (int i = 0; i < operators.size(); ++i)
  {
    delete operators[i];
  }

  return 0;
}
