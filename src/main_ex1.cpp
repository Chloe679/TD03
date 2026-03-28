#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

bool is_sorted(std::vector<int> const& vec) 
{ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

void bubble_sort(std::vector<int> & vec){
    size_t n= (vec.size()); 
    for (size_t debut=1;debut<=n-1; debut++ )
    for ( size_t i=debut; i<=n-1; i++){
        if (vec[i-1]>vec[i]){
            std::swap(vec[i-1],vec[i]);
        }
       

    }
}

int main(){
    setlocale(LC_ALL, ".utf8");
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
        bubble_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    }