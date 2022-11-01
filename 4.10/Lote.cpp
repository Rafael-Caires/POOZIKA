#include "Lote.hpp"
#include <iostream>

Lote::Lote(){
  //Criar construtor
}

Lote::Lote (Data data_, string identificador_, int QntMin_, int QntAtual_, Produto produto_) {

  //Conferindo se o lote produz a quantidade suficiente
  if(QntAtual_ < QntMin_) return;

  this->data = data_;
  this->identificador = identificador_;
  this-> produto = produto_;
  this-> QntMin = QntMin_;
  this -> QntAtual = QntAtual_;
}

  Data Lote::getData() {
    return this->data;
  }

  string Lote::getId() {
    return identificador;
  }

  Produto& Lote::getProduto() {
    return produto;
  }

int Lote::getQntAtual()
{
  return this -> QntAtual;
}

int Lote::getQntMin()
{
  return this->QntMin;
}

void Lote::setQntMin(int _qntMin)
{
  this->QntMin = _qntMin;
}

void Lote::setQntAtual(int _qntAtual)
{
  this->QntAtual = _qntAtual;
}

Lote& Lote::operator=(Lote& segundo) {

  data = segundo.getData();
  identificador = segundo.getId();
  QntMin = segundo.getQntMin();
  QntAtual = segundo.getQntAtual();
  produto = segundo.getProduto();

  return *this;
}

void Lote::imprimeLote() {

  //   Data data;
  // string identificador;
  // int QntMin;
  // int QntAtual;
  // Produto produto;

  cout << "+ Data: " << data.getData() << endl;
  cout << "+ ID: " << this->getId() << endl;
  cout << "+ Quantidade atual: " << this->getQntAtual() << endl;
  cout << "+ Quantidade min.: " << this->getQntMin() << endl;


}