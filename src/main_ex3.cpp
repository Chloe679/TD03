#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
//EX PRECEDENT
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
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
        else if (w == "(") {
        token.push_back(make_token(Operator::OPEN_PAREN));
        }
        else if (w == ")") {
        token.push_back(make_token(Operator::CLOSE_PAREN));
        }
        else{
            float value =std::stof(w);
            token.push_back(make_token(value));
        }
        
    }
    return token; 
}







int operator_precedence(Operator const op){
    if( op == Operator::MUL || op== Operator::DIV){
        return 2;
    }
       if (op == Operator::ADD || op == Operator::SUB)
        return 1;
    return 0;

}

std::vector<Token> infix_to_npi_tokens(std::string const& expression){
    //std::stack<float> pile; //pile nbr
    std::stack<Token> oppile; //pile opérateur
    std::vector<Token> sortie;
    std::vector<std::string> mot=split_string(expression); //on sépare chaque ele
    std::vector<Token> tokens=tokenize(mot); //
    for ( Token const& w : tokens) 
    {
        if( w.type == TokenType::OPERAND){//c une val
            sortie.push_back(w);
        }
        else if (w.type== TokenType::OPERATOR){
             //c'ets un op
            if  (w.op == Operator::OPEN_PAREN){
                oppile.push(w); //on empile
            }
            else if(w.op == Operator::CLOSE_PAREN){ //si ) on dépile jusq'à )
                while (!oppile.empty() && oppile.top().op != Operator::OPEN_PAREN ) {
                    //on dépile
                    sortie.push_back(oppile.top()); //empile sortie
                    oppile.pop(); //on dépile op pile

                }
                oppile.pop(); // on enleve )
            }
            else {
                //op prio 
                while (!oppile.empty() && operator_precedence(oppile.top().op) >= operator_precedence(w.op)){ // prio dessus
                        sortie.push_back(oppile.top());
                        oppile.pop();
                }
                oppile.push(w); //on ajoute op à la sortie et on arrête
            }
        }
    }
            //on vide tout mtn
            while (!oppile.empty()){
                sortie.push_back(oppile.top());
                oppile.pop();
            }
            return sortie;
                }



float npi(std::string ligne) {
    //std::string ligne;
    //std::getline(std::cin, ligne);

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

std::string token_to_string(std::vector<Token> tokens){
       std::string result;

    for (const Token& t : tokens) {
        if (t.type == TokenType::OPERAND) {
            result += std::to_string(t.value) + " ";
        } else {
            switch (t.op) {
                case Operator::ADD: result += "+ "; break;
                case Operator::SUB: result += "- "; break;
                case Operator::MUL: result += "* "; break;
                case Operator::DIV: result += "/ "; break;
                default: break;
            }
        }
    }

    return result;
}


int main() { 
    std::cout<< "écrire un calcul:";
    std::string expression;
    std::getline(std::cin,expression);
//infixe en NPI
    std::vector<Token> tokens =infix_to_npi_tokens(expression);
//Tokens en string
std::string npi_string= token_to_string(tokens);
 std::cout << "NPI: " << npi_string << std::endl;

    // 3. Calcul
    float result = npi(npi_string);

    std::cout << "Résultat: " << result << std::endl;

    return 0;
}