// =========================================================
// File: bill.h
// Author: Jorge Martínez López
// Date:18/06/22
// Description:Proyecto final
// =========================================================

#ifndef BILL_H
#define BILL_H

class Bill {
private:
// Inicializar  
  double limitAmount, currentDebt, totalMoneySpent;

public:
// Constructor Parametrizado
  Bill(double);


// Constructor Copia
  Bill(const Bill&);



// Getters
  double getLimitAmount() const;
  double getCurrentDebt() const;
  double getTotalMoneySpent() const;

// Metodo
  void add(double amount);
  void pay(double amount);
  void changeTheLimit(double amount);

  bool check(double amount) const;
};

// Constructor Señalizdo
Bill::Bill(double _limitAmount)
{
  if(_limitAmount>0){
    limitAmount = _limitAmount;
    currentDebt = totalMoneySpent = 0;
  }else{
    limitAmount = currentDebt = totalMoneySpent = 0;
  }
  
}

// Contructor copia 
Bill::Bill(const Bill &copia){
  limitAmount = copia.limitAmount;
  currentDebt = copia.currentDebt;
  totalMoneySpent = copia.totalMoneySpent;
}


// Getters
double Bill::getLimitAmount() const{return limitAmount;}
double Bill::getCurrentDebt() const{return currentDebt;}
double Bill::getTotalMoneySpent() const{return totalMoneySpent;}

// Metodos y funciones
void Bill::add(double amount) 
{
  
  if(amount > 0){
    currentDebt +=amount;
  }
}
void Bill::pay(double amount)
{
  if (amount > 0)
  {
    if(currentDebt<amount){
      amount = currentDebt;
    }
    currentDebt -= amount;
    totalMoneySpent+=amount;
  }
}
void Bill::changeTheLimit(double amount)
{ 
  if(!(currentDebt>=amount || amount<=0)){
    limitAmount = amount;
  } 
}

bool Bill::check(double amount) const
{
  double total;
  total=amount+currentDebt;
  if(total<limitAmount){
    return true;
  }else{
    return false;
  }
}

#endif
