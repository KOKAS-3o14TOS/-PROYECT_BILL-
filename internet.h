// =========================================================
// File: internet.h
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// =========================================================

#ifndef InternetOperator_H
#define InternetOperator_H

#include "operator.h"

class InternetOperator : public Operator {
private:
  const double LIMITGB = 10;

public:
  // Constructor Herencia de Operator
  InternetOperator(int, double, double, double, int, OperatorType);
  // Constructor Copia
  InternetOperator(const InternetOperator&);

  // Metodos y funciones
  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};
// Constructor Señalizado
InternetOperator::InternetOperator(int _Id, double _CostCall, double _CostSend, double _CostGB, int _Discount, OperatorType _type) : Operator(_Id, _CostCall, _CostSend, _CostGB, _Discount, _type) {}

// Constructor Copia
InternetOperator::InternetOperator(const InternetOperator & CopiaInternet):Operator(CopiaInternet){}

// Metodos y funciones
double InternetOperator::calculateTalkingCost(int minute, int age){
  double total;
  double descuento;
  if(minute>0 && age>0){
    total=minute*talkingCharge;
  }else{
    total=0;
  }
  if(minute<2 && minute>0){
    descuento = (discountRate * total) / 100;
    total -= descuento;
  }
  return total;
}
double InternetOperator::calculateMessageCost(int quantity,int thisOpId, int otherOpId){
  double total;
  double descuento;
  if (quantity > 0)
  {
    total = quantity * messageCost;
  }
  else
  {
    total = 0;
  }
  if(quantity<3 && quantity>0){
    descuento = (discountRate * total) / 100;
    total -= descuento;
  }
  return total;
}
double InternetOperator::calculateNetworkCost(double amount){
  double total;
  double descuento;
  if(totalInternetUsage>LIMITGB){
    total=amount*networkCharge;
  }else{
    total=0;
  }

  return total;
}
#endif
