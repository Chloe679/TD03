#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include<locale>
//fcp pr tester
bool is_sorted(std::vector<int> const& vec) 
{ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right){
    size_t pivot = right;  //on prend pivot= dernier ele
    //on trie
        size_t i= left; //début tab
        for (size_t j=i;j<right;j++){
            if (vec[j]<=vec[pivot]){ // alors à gauche du pivot
                std::swap(vec[j],vec[i]);
                i++; //on garde indice de dep + - grand
            }
        }
        std::swap(vec[i],vec[pivot]); //on place le pivot
        return i; //on retourne l'indice du pivot
}
//place pivot


void quick_sort(std::vector<int> & vec, size_t const left, size_t const right){
  
    if (left>=right){ //condition arrêt
    return;}

    //tab gauche
      size_t pivot= quick_sort_partition(vec,left,right); //on trie et on place le pivot
    if (pivot>=1){ //pr pas overflow
        quick_sort(vec,left, pivot-1);
    }
    //taab droite
        quick_sort(vec,pivot+1, right);
}


    void quick_sort(std::vector<int> & vec) {
        quick_sort(vec, 0, vec.size() - 1);
    }
    
    int main(){
    setlocale(LC_ALL, ".utf8");
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quick_sort(array);
if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
}
}


