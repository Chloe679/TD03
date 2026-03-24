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
    int temp=0;
    int  n=static_cast<int> (vec.size()); //
    for (int debut=1;debut<=n-1; debut++ )
    for ( int i=debut; i<=n-1; i++){
        if (vec[i-1]>vec[i]){
            temp=vec[i-1];
            vec[i-1]=vec[i];
            vec[i]=temp;
        }
       

    }
}

int main(){
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bubble_sort(array);
if (is_sorted(array)) {
    std::cout << "Le tableau est trié" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trié" << std::endl;
}
}