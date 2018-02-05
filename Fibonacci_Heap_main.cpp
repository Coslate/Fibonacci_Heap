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
    std::cout<<"H1.total_node_num = "<<H1.GetTotalNodeNum()<<std::endl;
    std::cout<<"H1.root_list_size = "<<H1.GetRootListSize()<<std::endl;
    std::cout<<"H1.min_pointer = "<<"("<<H1.FindMin()->GetKey()<<", "<<H1.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2========================================="<<std::endl;
    FTNode* new_10_node = new FTNode(10);
    FTNode* new_15_node = new FTNode(15);
    FTNode* new_33_node = new FTNode(33);
    H2.InsertArbitrary(new_10_node);
    H2.InsertArbitrary(new_15_node);
    H2.InsertArbitrary(new_33_node);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H3========================================="<<std::endl;
    H3.InsertArbitrary(1);
    H3.InsertArbitrary(2);
    H3.InsertArbitrary(99);
    H3.Traverse();
    std::cout<<"H3.total_node_num = "<<H3.GetTotalNodeNum()<<std::endl;
    std::cout<<"H3.root_list_size = "<<H3.GetRootListSize()<<std::endl;
    std::cout<<"H3.min_pointer = "<<"("<<H3.FindMin()->GetKey()<<", "<<H3.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H2.Union(H3)========================================="<<std::endl;
    H2.Union(H3);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;

    return EXIT_SUCCESS;
}
