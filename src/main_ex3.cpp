#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include<locale>
#include <cstdlib>
#include "ScopedTimer.hpp"
#include<locale>

//tab entier aléatoire
void bubble_sort(std::vector<int> & vec){
    size_t n= (vec.size()); 
    for (size_t debut=1;debut<=n-1; debut++ )
    for ( size_t i=debut; i<=n-1; i++){
        if (vec[i-1]>vec[i]){
            std::swap(vec[i-1],vec[i]);
        }
       

    }
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
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
//tableaux
    setlocale(LC_ALL, ".utf8");
    std::vector<int> array1 = generate_random_vector(10000, 100);
    std::vector<int> array2 = array1;
    std::vector<int> array3 = array1; //copie pr comparer

{
    ScopedTimer timer1("Tri issu de la bibliothèque");
    std::sort(array1.begin(), array1.end());
}
{
    ScopedTimer timer2("Tri à bulles");
    bubble_sort(array2);
}
{
    ScopedTimer timer3("Tri Récursif");
    quick_sort(array3);
}
}