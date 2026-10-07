/*
Uma zoológico está criando habitats para os animais, um para animais
aquáticos, um para terrestres e um para voadores e contratou você para
desenvolver o sistema que irão utilizar. Cada habitat terá 5 animais,
cada animal tendo como informações seu nome, tipo de alimentação,
pais de origem e idade. O programa deverá possuir um menu de
opções que permita ao gestor cadastrar um novo animal no seu
respectivo habitat, consultar os animais cadastrados, buscar um animal
pelo nome e remover um animal do habitat. O sistema também deverá
permitir visualizar os animais de cada habitat separadamente. Também
deve ter opções de deletar e buscar um animal. Utilize Singly Linked
List para resolver a questão.
*/

#include <iostream>
#include <string>
using namespace std;

struct animal {
    string nome;
    string comida;
    string pais;
    int idade;
    animal* proximo;
};

animal* inicio[3] = {0, 0, 0};
int quantidade[3] = {0, 0, 0};
string habitat[3] = {"Aquaticos", "Terrestres", "Voadores"};


bool cadastrar(int indiceHabitat, string nome, string comida, string pais, int idade) {
   
    if (quantidade[indiceHabitat] >= 5) {
   
        return false;
    }

    animal* novo = new animal{nome, comida, pais, idade, 0};

    if (!inicio[indiceHabitat]) {
   
        inicio[indiceHabitat] = novo;
   
    } else {
   
        animal* atual = inicio[indiceHabitat];
   
        while (atual->proximo) {
   
            atual = atual->proximo;
   
        }
   
        atual->proximo = novo;
    }


    quantidade[indiceHabitat]++;

    return true;

}



void listar(int indiceHabitat) {

    cout << "\n" << habitat[indiceHabitat] << " (" << quantidade[indiceHabitat] << "/5)\n";

    if (!inicio[indiceHabitat]) {

        cout << "Vazio.\n"<<endl;

        return;

    }

    int numero = 1;

    for (animal* atual = inicio[indiceHabitat]; atual; atual = atual->proximo) {

        cout << numero << ") " << atual->nome << " | " << atual->comida << " | "
             << atual->pais << " | " << atual->idade << "\n";

        numero++;

    }
}



animal* buscar(int indiceHabitat, string nome) {

    for (animal* atual = inicio[indiceHabitat]; atual; atual = atual->proximo) {

        if (atual->nome == nome) {


            return atual;

        }

    }

    return 0;

}



bool remover(int indiceHabitat, string nome) {

    if (!inicio[indiceHabitat]) {

        return false;

    }


    if (inicio[indiceHabitat]->nome == nome) {

        animal* apagar = inicio[indiceHabitat];
        inicio[indiceHabitat] = inicio[indiceHabitat]->proximo;
        delete apagar;
        quantidade[indiceHabitat]--;

        return true;

    }

    animal* atual = inicio[indiceHabitat];
    while (atual->proximo && atual->proximo->nome != nome) {

        atual = atual->proximo;

    }

    if (!atual->proximo) {

        return false;

    }

    animal* apagar = atual->proximo;
    atual->proximo = apagar->proximo;
    delete apagar;
    quantidade[indiceHabitat]--;

    return true;

}

string lerTexto(string pergunta) {

    cout << pergunta;
    string resposta;
    getline(cin, resposta);

    return resposta;

}

int lerNumero(string pergunta) {
   
    cout << pergunta;
    int numero;
    cin >> numero;
    cin.ignore();
    return numero;
    
}


int escolherHabitat() {

    cout << "1 Aquatico  2 Terrestre  3 Voador\n";

    int escolha = lerNumero("Habitat: ");

    if (escolha < 1 || escolha > 3) {

        cout << "Invalido.\n";

        return -1;

    }

    return escolha - 1;

}



int main() {

    int opcao;

    do {

		cout<< "\nDigite";
        cout << "\n1 Para cadastrar animal;\n2 Para ver todos;\n3 Um habitat\n4 Buscar\n5 Remover aniaml\n0 Sair\n";
        opcao = lerNumero("Opcao: ");

        if (opcao == 1) {

            int indiceHabitat = escolherHabitat();

            if (indiceHabitat < 0) {

                continue;
            }

            if (quantidade[indiceHabitat] >= 5) {

                cout << "Cheio.\n";
                continue;

            }

            string nome = lerTexto("Nome/especie: ");
            string comida = lerTexto("Alimentacao: ");
            string pais = lerTexto("Pais: ");
            int idade = lerNumero("Idade: ");
            cadastrar(indiceHabitat, nome, comida, pais, idade);
            cout << "Ok.\n";

        } else if (opcao == 2) {

            for (int i = 0; i < 3; i++) {
                listar(i);

            }

        } else if (opcao == 3) {

            int indiceHabitat = escolherHabitat();

            if (indiceHabitat >= 0) {

                listar(indiceHabitat);

            }

        } else if (opcao == 4) {

            string nome = lerTexto("Nome: ");

            bool achou = false;

            for (int i = 0; i < 3; i++) {

                animal* encontrado = buscar(i, nome);

                if (encontrado) {

                    cout << habitat[i] << ": " << encontrado->nome << " | " << encontrado->comida

                         << " | " << encontrado->pais << " | " << encontrado->idade << "\n";

                    achou = true;

                    break;

                }

            }

            if (!achou) {

                cout << "Nao achou.\n";

            }

        } else if (opcao == 5) {

            string nome = lerTexto("Nome: ");
            bool achou = false;

            for (int i = 0; i < 3; i++) {

                if (remover(i, nome)) {

                    cout << "Removido de " << habitat[i] << ".\n";
                    achou = true;

                    break;

                }

            }

            if (!achou) {

                cout << "Nao achou.\n";

            }

        }


    } while (opcao != 0);





    return 0;




}