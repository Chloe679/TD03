#include <iostream>
#include <string>
#include <sstream>
#include <stack>

float npi() {
    std::string ligne;
    std::getline(std::cin, ligne);

    std::stringstream ss(ligne);
    std::string token;

    std::stack<float> pile;

    while (ss >> token) {

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            
            float b = pile.top();
            pile.pop();
            float a = pile.top();
            pile.pop();

            float resultat;

            if (token == "+") resultat = a + b;
            if (token == "-") resultat = a - b;
            if (token == "*") resultat = a * b;
            if (token == "/") resultat = a / b;

            pile.push(resultat);
        }
        else {
            pile.push(std::stof(token));
        }
    }

    return pile.top();
}

int main() {
    std::cout << "Entrez une expression en NPI : ";
    float result = npi();
    std::cout << "Résultat : " << result << std::endl;
}
