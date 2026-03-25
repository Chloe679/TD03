#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include<locale>
#include <cstdlib>
#include<locale>

int search ( std::vector <int> vec, int val){
    int left=0;
    int right= vec.size();
    int middle= (right-left)/2;
    while (left<=right){
        if ( val>middle){
            left=middle;
            middle= left+(right-left)/2;
        }
        else if ( val<middle){
            right=middle;
            middle=right+(right-left)/2;
        }


        else if(val==middle){
            return middle;
        }
    }
    return -1;
}
int main(){
    std::cout << search({1, 2, 2, 3, 4, 8, 12}, 8) << std::endl;
    std::cout << search({1, 2, 3, 3, 6, 14, 12, 15}, 15) << std::endl;
    std::cout << search({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16) << std::endl;
    std::cout << search({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6) << std::endl;
    std::cout << search({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10) << std::endl;
    return 1;
}