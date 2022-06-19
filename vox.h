// =========================================================
// File: vox.h
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// =========================================================
#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"

class VoxOperator : public Operator {
public:
// Constructor Herencia de Operator 
  VoxOperator(int, double, double, double, int, OperatorType);
// Constructor Copia
  VoxOperator(const VoxOperator&);

// Metodos y funciones
  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};

// Constructor Señalizado 
VoxOperator::VoxOperator(int _Id, double _CostCall, double _CostSend, double _CostGB, int _Discount, OperatorType _type) : Operator( _Id,  _CostCall,  _CostSend,  _CostGB,  _Discount, _type){}

// Constructor Copia
VoxOperator::VoxOperator(const VoxOperator &CopiaVox):Operator(CopiaVox){}

// Metodos
double VoxOperator::calculateTalkingCost(int minute, int age)
{
  double total;
  double descuento;
  
  if(minute>0 && age>0){
    total=minute*talkingCharge;
  }else{
    total = 0;
  }
  if(age<=18 || age>=65){
    descuento = (discountRate * total) / 100 ;
    total-=descuento;
  } 
  return total;
}
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId)
{
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
  if (thisOpId == otherOpId)
  {
    descuento = (discountRate * total) / 100;
    total -= descuento;
  }
  
  return total;
}
double VoxOperator::calculateNetworkCost( double amount ){
  double total;
  
  if (amount > 0)
  {
    total = amount * networkCharge;
  }
  else
  {
    total = 0;
  }
  return total;
}
#endif
