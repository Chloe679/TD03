#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>


enum class Operator { ADD, SUB, MUL, DIV};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value){
    Token token;
    token.type=TokenType::OPERAND;
    token.value=value;
    return token;

}

Token make_token(Operator op){
     Token token;
    token.type=TokenType::OPERATOR;
    token.op=op;
    return token;

}

std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> token; //le resultat
    for (std::string const& w : words){ //énumérer comme l'autre ex en fct des op
        if (w=="+"){
            token.push_back(make_token(Operator::ADD));
        }
        else if (w=="-"){
            token.push_back(make_token(Operator::SUB));
        }
        else if (w=="*"){
            token.push_back(make_token(Operator::MUL));
        }
        else if (w=="/"){
            token.push_back(make_token(Operator::DIV));
        }
        else{
            float value =std::stof(w);
            token.push_back(make_token(value));
        }
        
    }
return token; }

float npi_evaluate( std::vector<Token> const& tokens);

int main (){
    return 0;
}




/*4️ Fonction npi_evaluate
float npi_evaluate(const std::vector<Token>& tokens) {
    std::stack<float> s;

    for (const Token& t : tokens) {
        if (t.type == TokenType::OPERAND) {
            s.push(t.value);
        } else {
            // On suppose qu'il y a toujours au moins 2 éléments
            float b = s.top(); s.pop();
            float a = s.top(); s.pop();
            float result;

            switch (t.op) {
                case Operator::ADD: result = a + b; break;
                case Operator::SUB: result = a - b; break;
                case Operator::MUL: result = a * b; break;
                case Operator::DIV: result = a / b; break;
            }

            s.push(result);
        }
    }

    return s.top();
}

// 5️ Exemple d'utilisation
int main() {
    std::vector<std::string> words = {"3", "4", "+", "2", "*", "7", "/"};
    std::vector<Token> tokens = tokenize(words);

    float result = npi_evaluate(tokens);
    std::cout << "Résultat: " << result << std::endl;

    return 0;
}
*/