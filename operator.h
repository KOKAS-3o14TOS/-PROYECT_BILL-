// =========================================================
// File: operator.h
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// =========================================================

#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

typedef enum{VOX, INTERNET} OperatorType;

class Operator {
protected:
  
  int id, discountRate;
  double talkingCharge, messageCost, networkCharge, totalInternetUsage;
  int totalSpentTalkingTime, totalMessageSent;
  OperatorType type;

public:
// Constructor Parametrizado
  Operator(int, double, double, double, int , OperatorType);
  // Constructor Copia
  Operator(const Operator&);

// Getters
  int getId() const;
  int getDiscountRate() const;
  double getTalkingChage() const;
  double getMessageCost() const;
  double getNetworkCharge() const;
  int getTotalSpentTalkingTime() const;
  int getTotalMessageSent() const;
  double getTotalInternetUsage() const;
  OperatorType getType() const;

// Metodos
  void addTalkingTime(int);
  void addTotalMessageSent(int);
  void addTotalInternetUsage(double);

  string toString() const;

  virtual double calculateTalkingCost(int, int) = 0;
  virtual double calculateMessageCost(int, int, int) = 0;
  virtual double calculateNetworkCost(double) = 0;
};

// Constructor Señalizado
Operator::Operator(int _Id, double _CostCall, double _CostSend, double _CostGB, int _Discount  , OperatorType _type){
  id=_Id; 
  discountRate=_Discount;
  talkingCharge=_CostCall;
  messageCost=_CostSend;
  networkCharge=_CostGB;
  totalInternetUsage=0;
  totalSpentTalkingTime=0;
  totalMessageSent=0;
  type=_type;
  
}
// Constructor Copia
Operator::Operator(const Operator &CopiaOperator){
  id=CopiaOperator.id;
  discountRate= CopiaOperator.discountRate;
  talkingCharge = CopiaOperator.talkingCharge;
  messageCost = CopiaOperator.messageCost;
  networkCharge = CopiaOperator.networkCharge;
  totalMessageSent = CopiaOperator.totalMessageSent;
  totalSpentTalkingTime = CopiaOperator.totalSpentTalkingTime;
  totalInternetUsage = CopiaOperator.totalInternetUsage;
  type= CopiaOperator.type;
}
// Getters
int Operator::getId() const{return id;}
int Operator::getDiscountRate() const{return discountRate;}
double Operator::getTalkingChage() const{return talkingCharge;}
double Operator::getMessageCost() const{return messageCost;}
double Operator::getNetworkCharge() const{return networkCharge;}
int Operator::getTotalSpentTalkingTime() const{return totalSpentTalkingTime;}
int Operator::getTotalMessageSent() const{return totalMessageSent;}
double Operator::getTotalInternetUsage() const{return totalInternetUsage;}
OperatorType Operator::getType() const{return type;}

// Metodos y funciones
void Operator::addTalkingTime( int minute){
  if(minute>0){
    totalSpentTalkingTime += minute;
  }else{
    totalSpentTalkingTime = 0;
  }
}
void Operator::addTotalMessageSent( int quantity){
  if(quantity>0){
    totalMessageSent += quantity;
  }else{
    totalMessageSent=0;
  }
}
void Operator::addTotalInternetUsage( double amount){
  if(amount>0){
    totalInternetUsage += amount;
  }else{
    totalInternetUsage = 0;
  }
}
string Operator::toString() const{
  string data;
  ostringstream resume;
  // resume ="Operator #id:"+to_string(id)+" "+to_string(totalSpentTalkingTime)+" "+to_string(totalMessageSent)+" "+to_string(totalInternetUsage);
  resume << fixed << setprecision(2) << "Operator " << id <<":"<< " " << totalSpentTalkingTime << " " << totalMessageSent << " " << totalInternetUsage;
  data = resume.str();
  
  return data;
}


#endif

