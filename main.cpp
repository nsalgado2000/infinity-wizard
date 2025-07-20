#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string initialState = "\n> ";

void showHelp()
{
    cout << "Comandos disponíveis:\n"
         << "add: soma os dois números\n"
         << "sub: subtrai o segundo número do primeiro\n"
         << "mult: multiplica os dois números\n"
         << "div: divide o primeiro número pelo segundo\n"
         << "sintaxe: você digitará o comando, e logo em seguida, na mesma linha, ambos os números"
         << endl
         << initialState;
};

void executeOperation(string &comando, float a, float b)
{
    if (comando == "add")
        cout << "Resposta: " << a + b << endl
             << initialState;
    else if (comando == "mult")
        cout << "Resposta: " << a * b << endl
             << initialState;
    else if (comando == "div")
    {
        if (b == 0)
            cout << "Impossível dividir por 0, resultado indeterminado" << endl
                 << initialState;
        else
            cout << "Resposta: " << a / b << endl
                 << initialState;
    }
    else if (comando == "sub")
        cout << "Resposta: " << a - b << endl
             << initialState;
}

int main()
{

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    string comando;
    float primeiroDigito, segundoDigito;

    cout << "Digite o comando, e, em seguida, os dois números. Conheça os comandos disponivéis inserindo \"help\"." << endl
         << initialState;

    while (true)
    {
        cin >> comando;
        if (comando == "help")
        {
            showHelp();
        }
        else if (comando == "add" || comando == "mult" || comando == "sub" || comando == "div")
        {
            cin >> primeiroDigito >> segundoDigito;
            executeOperation(comando, primeiroDigito, segundoDigito);
        }
        else if (comando == "exit")
        {
            break;
        }
        else
        {
            cout << "Insira um comando válido. Consulte-os em 'help'" << endl
                 << initialState;
        }
    }
    return 0;
}