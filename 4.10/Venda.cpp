#include "Venda.hpp"

Venda::Venda(Data data, Produto *prod, int qnt, vector<Lote> LotesComprados, Estoque estoque) {
this->data = data;
this->produto = *prod;
this->quantidade = qnt;
this->LotesComprados = LotesComprados;
this->estoque = estoque;

 }

void Venda::ImprimeOrdem() {
if(estoque.getEstoqueTotal() < produto.getEstoque_min()){
  Lote produto (this->data,"ordem de produção", this->produto.getEstoque_min(), 20, this->produto);
  estoque.inserir(produto);
}
}

bool Venda::ValidaQuantidade(int qnt) {
  //Validar disponibilidade (qnt < qnt em estoque)
   if (qnt > this->estoque.getEstoqueTotal() ) {
     return 0;
   } else {
     return 1;
   }
  }


void Venda::AtualizaEstoque(){
  if (this->ValidaQuantidade(this->quantidade) == 1){
    // lote[1] =30 
    // lote[2] = 20
    // lote 3 = 45
    // quantidade = 40
    for(int i = 0; i<this->estoque.getLotesAtuais().size(); i++)
    {
      if (quantidade>this->estoque.getLotesAtuais().front().getQntAtual())
      {
        estoque.getLotesAtuais().front().setQntAtual(0);
        estoque.getLotesAtuais().erase(estoque.getLotesAtuais().begin());

      }else {
        int quantidadeFinal=estoque.getLotesAtuais().front().getQntAtual() - quantidade;
        estoque.getLotesAtuais().front().setQntAtual(quantidadeFinal);
      }
    }
      if(this->estoque.getEstoqueTotal() - this->quantidade < this->produto.getEstoque_min()){
          this->ImprimeOrdem();
      }
  }
}
