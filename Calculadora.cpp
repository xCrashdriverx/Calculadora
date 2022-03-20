#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// 
}

double getDouble()
{
    while (true) // Função verdadeira se o usuário entrar com os dígitos pedidos na operação a seguir.
    {
        std::cout << "Entre com um valor numerico qualquer: ";
        double x{};
        std::cin >> x;

        // Verifica se há letras ou outros caracteres que nao sejam números ?
        if (std::cin.fail()) 
        {
            // Se sim , então  corrigir. 
            std::cin.clear(); // resetar operação apagando qualquer valor inválido guardado na memória da máquina.
            ignoreLine(); // e remover os dígitos inválidos 
            std::cerr << "Oops,opcao invalida.  Tente novamente.\n"; // retorna a operação para o inicio da função "while" (loop).
        }
        else
        {
            ignoreLine(); //   remover qualquer carácter que não sejam números e ficar apenas com os números. Prossegir a operação normalmente
            return x;
        }
    }
}

char getOperator()
{
    while (true) // Função verdadeira se o usuário entrar com os dígitos pedidos na operação a seguir.
    {
        std::cout << "Escolha uma das operacoes: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine(); // // e remover os dígitos inválidos 

        
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; 
        default: // retorna a operação para o inicio da função.
            std::cerr << "Oops,opcao invalida.  Tente novamente.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Verifica parâmetros e argumentos garantindo que a função passe os operadores aritiméticos esperados.   
        std::cerr << "Falha no resultado final. printResult() recebeu um operador inválido.\n";
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}