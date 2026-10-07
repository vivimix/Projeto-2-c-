/*
Uma empresa de shows precisa de um sistema para organizar os
compradores de seus ingressos. Cada participante deverá possuir como
informações seu nome, idade, cidade e ingresso (Para qual show ele
vai assistir). O programa deverá conter um menu para que o
responsável possa cadastrar novos compradores, buscar um
comprador, excluir um comprador e visualizar todos os compradores
cadastrados. O sistema também deverá permitir visualizar os
compradores na ordem de cadastro e na ordem inversa, utilizando os
dois sentidos de ligação da estrutura. Utilize uma Doubly Linked List
para resolver a questão.
*/


#include <iostream>
#include <string>
using namespace std;

struct Comprador {

    string nome, cidade, show;
    int idade;

    Comprador *ant, *prox;

};

Comprador *inicio = nullptr;
Comprador *fim = nullptr;


void cadastrar() {

    Comprador *novo = new Comprador;
    novo->ant = novo->prox = nullptr;

    cout << "Nome: ";

    getline(cin, novo->nome);

    cout << "Idade: ";
    cin >> novo->idade;
    cin.ignore();

    cout << "Cidade: ";

    getline(cin, novo->cidade);

    cout << "Show: ";
    getline(cin, novo->show);

    if (!inicio) {

        inicio = fim = novo;

    } else {

        fim->prox = novo;
        novo->ant = fim;
        fim = novo;

    }

    cout << "Cadastrou.\n";

}

Comprador* achar(string nome) {

    Comprador *p = inicio;

    while (p) {

        if (p->nome == nome) return p;
        p = p->prox;

    }

    return nullptr;


}


void buscar() {

    string nome;

    cout << "Nome: ";
    getline(cin, nome);
    Comprador *p = achar(nome);

    if (!p) {

        cout << "Nao achei.\n";

        return;

    }

    cout << p->nome << ", " << p->idade << " anos, " << p->cidade
         << ", ingresso: " << p->show << "\n";
}


void excluir() {

    string nome;

    cout << "Nome: ";
    getline(cin, nome);
    Comprador *p = achar(nome);

    if (!p) {

        cout << "Nao achei.\n";
        return;

    }

    if (p->ant) p->ant->prox = p->prox;

    else inicio = p->prox;

    if (p->prox) p->prox->ant = p->ant;

    else fim = p->ant;

    delete p;

    cout << "Excluiu.\n";
}


void listar() {

    if (!inicio) {

        cout << "Lista vazia.\n";
        return;

    }

    int op;

    cout << "1 - ordem de cadastro\n2 - ordem inversa\nOpcao: ";

    cin >> op;

    cin.ignore();

    if (op == 1) {

        Comprador *p = inicio;

        while (p) {

            cout << p->nome << " | " << p->idade << " | " << p->cidade

                 << " | " << p->show << "\n";

            p = p->prox;

        }

    } else if (op == 2) {

        Comprador *p = fim;

        while (p) {

            cout << p->nome << " | " << p->idade << " | " << p->cidade
                 << " | " << p->show << "\n";
            p = p->ant;

        }

    } else {

        cout << "Opcao invalida.\n";

    }
}

int main() {

    int op = -1;

    do {
    	
    	cout << "Registros de show's";
        cout << "\n1 cadastrar\n2 buscar\n3 excluir\n4 listar\n0 sair\n> ";
        cin >> op;
        cin.ignore();

        if (op == 1) cadastrar();

        else if (op == 2) buscar();

        else if (op == 3) excluir();

        else if (op == 4) listar();

        else if (op != 0) cout << "Opcao invalida.\n";

    } while (op != 0);


    return 0;


}