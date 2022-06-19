// =========================================================
// File: customer.h
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// =========================================================
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
#include <iomanip>
#include "bill.h"
#include "operator.h"
using namespace std;

class Customer {
private:
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage;
  string name;
  Operator* op;
  Bill* bill;

public:
  // Constructor Herencia de Operator
  Customer(int, string, int, Operator*, double);
  // Constructor Copia
  Customer(const Customer&);
  // Destructor
  ~Customer();

  // Getters
  int getId() const;
  int getAge() const;
  int getTotalSpentTalkingTime() const;
  int getTotalMessageSent() const;
  double getTotalInternetUsage() const;
  string getName() const;
  Operator* getOperator() const;
  Bill* getBill() const;

  // Setters
  void setOperator(Operator*);

  // Metodos y funciones
  void addTalkingTime(int);          
  void addTotalMessageSent(int);      
  void addTotalInternetUsage(double); 
  void talk (int, Customer&);
  void message(int,  Customer&);
  void connection(double);
  void pay(double);

  string toString() const;
};
// Constructor Señalizado
Customer::Customer(int id_, string name_, int age_, Operator *type_, double limit_){
  id= id_;
  name= name_;
  age=age_;
  op= type_;
  bill= new Bill(limit_);
  totalSpentTalkingTime = totalMessageSent = totalInternetUsage = 0;

}
// Constructor Copia
Customer::Customer(const Customer &CopiaCustomer){
  id=CopiaCustomer.id;
  name=CopiaCustomer.name;
  age=CopiaCustomer.age;
  op=CopiaCustomer.op;
  bill=CopiaCustomer.bill;

}
// Destructor
Customer::~Customer(){
  delete bill;
  op=NULL;
  bill=NULL;
}
// Getters
int Customer::getId() const{ return id; }
int Customer::getAge() const{return age; }
int Customer::getTotalSpentTalkingTime() const{ return totalSpentTalkingTime; }
int Customer::getTotalMessageSent() const{ return totalMessageSent; }
double Customer::getTotalInternetUsage() const{ return totalInternetUsage; }
string Customer::getName() const{ return name; }
// Apuntador a un objeto de la clase OPERATOR
Operator* Customer::getOperator() const{return op;}
// Apuntador a un objeto de la clase BILL
Bill* Customer::getBill() const{ return bill;}

// Setters
void Customer::setOperator(Operator *valor){
  op=valor;
}

// Metodos y funciones
void Customer::addTalkingTime(int minute)
{ 
  if (minute > 0)
  {                                  
    totalSpentTalkingTime += minute; 
  }                                  
} 
void Customer::addTotalMessageSent(int message)
{ 
  if (message > 0)
  {                         
    totalMessageSent += message; 
  }                         
} 
void Customer::addTotalInternetUsage(double amount)
{ 
  if (amount > 0)
  {                               
    totalInternetUsage += amount; 
  }                               
}
void Customer::talk(int minute, Customer &other){
  double total;
  bool check;
  if(minute>0 && id!=other.getId()){
    total= op->calculateTalkingCost(minute, age);
    check = bill->check(total);
    if (check == true)
    {
      bill->add(total);
      addTalkingTime(minute);
      op->addTalkingTime(minute);
      other.addTalkingTime(minute);
      if (op->getId() != other.op->getId())
      {
        other.op->addTalkingTime(minute);
      }
    }
  }else{
    total = 0;
  }
  
  
}

void Customer::message(int quantity, Customer &other){
  double total;
  bool check;
  
  if (quantity > 0 && id != other.getId()){
    total = op->calculateMessageCost(quantity, op->getId(), other.op->getId());
    check = bill->check(total);
    if (check == true)
    {
      bill->add(total);
      addTotalMessageSent(quantity);
      
      op->addTotalMessageSent(quantity);
      
    }
  } else {
    total=0;
  }
  
}
void Customer::connection(double amount){
  double total;
  bool check;
  if(amount > 0){
    total = op->calculateNetworkCost(amount);
    check = bill->check(total);
    if (check == true)
    {
      bill->add(total);
      addTotalInternetUsage(amount);
      op->addTotalInternetUsage(amount);

    }
  } else {
    total = 0;
  }
  
}
void Customer::pay(double amount){
  bill->pay(amount);
}
string Customer::toString() const{
  
  string datos;
  ostringstream resumen;
  resumen << fixed << setprecision(2) << "Customer " << id << ": " << bill->getTotalMoneySpent() << " " << bill->getCurrentDebt() << "\n";
  datos= resumen.str();

  return datos;
}
#endif
