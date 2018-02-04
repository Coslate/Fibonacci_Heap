#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <Fibonacci_Heap.h>

void PrintArray(const int size, const int* arr, const std::string arr_name){
    std::cout<<arr_name<<" = [";
    for(int i=0;i<size;++i){
        if(i == 0){
            std::cout<<arr[i];
        }else if(i == size - 1){
            std::cout<<", "<<arr[i]<<"]"<<std::endl; 
        }else{
            std::cout<<", "<<arr[i];
        }
    }
}

int main(){
//    int *arr = new int [10]();
//    PrintArray(10, arr, "arr");
    Fibonacci_Heap H1;
    Fibonacci_Heap H2;
    Fibonacci_Heap H3;


    std::cout<<"=====================================H1========================================="<<std::endl;
    H1.Traverse(3, true);
    std::cout<<"=====================================H2========================================="<<std::endl;
    FTNode* new_10_node = new FTNode(10);
    FTNode* new_15_node = new FTNode(15);
    FTNode* new_33_node = new FTNode(33);
    H2.InsertArbitrary(new_10_node);
    H2.InsertArbitrary(new_15_node);
    H2.InsertArbitrary(new_33_node);
    H2.Traverse();



    return EXIT_SUCCESS;
}
