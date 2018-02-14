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
    Fibonacci_Heap H4;
    Fibonacci_Heap H5;


    std::cout<<"=====================================H1========================================="<<std::endl;
    H1.Traverse(3, true);
    std::cout<<"H1.total_node_num = "<<H1.GetTotalNodeNum()<<std::endl;
    std::cout<<"H1.root_list_size = "<<H1.GetRootListSize()<<std::endl;
    std::cout<<"H1.head = "<<H1.GetHeadRootList()<<std::endl;
    std::cout<<"H1.tail = "<<H1.GetTailRootList()<<std::endl;
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
    std::cout<<"H2.head = "<<H2.GetHeadRootList()<<std::endl;
    std::cout<<"H2.tail = "<<H2.GetTailRootList()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2.Union(H3)========================================="<<std::endl;
    H2.Union(H3);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<H2.GetHeadRootList()<<std::endl;
    std::cout<<"H2.tail = "<<H2.GetTailRootList()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H3========================================="<<std::endl;
    H3.InsertArbitrary(1);
    H3.InsertArbitrary(2);
    H3.InsertArbitrary(99);
    H3.Traverse();
    std::cout<<"H3.total_node_num = "<<H3.GetTotalNodeNum()<<std::endl;
    std::cout<<"H3.root_list_size = "<<H3.GetRootListSize()<<std::endl;
    std::cout<<"H3.head = "<<H3.GetHeadRootList()<<std::endl;
    std::cout<<"H3.tail = "<<H3.GetTailRootList()<<std::endl;
    std::cout<<"H3.min_pointer = "<<"("<<H3.FindMin()->GetKey()<<", "<<H3.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H2.Union(H3)========================================="<<std::endl;
    H2.Union(H3);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<H2.GetHeadRootList()<<std::endl;
    std::cout<<"H2.tail = "<<H2.GetTailRootList()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2.ExtractMin()========================================="<<std::endl;
    FTNode* extracted_min = NULL;
    extracted_min = H2.ExtractMin();
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<H2.GetHeadRootList()<<std::endl;
    std::cout<<"H2.tail = "<<H2.GetTailRootList()<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;


    std::cout<<"=====================================H4========================================="<<std::endl;
    FTNode* new_200_node = new FTNode(200);
    H4.InsertArbitrary(new_200_node);
    H4.Traverse();
    std::cout<<"H4.total_node_num = "<<H4.GetTotalNodeNum()<<std::endl;
    std::cout<<"H4.root_list_size = "<<H4.GetRootListSize()<<std::endl;
    std::cout<<"H4.head = "<<H4.GetHeadRootList()<<std::endl;
    std::cout<<"H4.tail = "<<H4.GetTailRootList()<<std::endl;
    std::cout<<"H4.min_pointer = "<<"("<<H4.FindMin()->GetKey()<<", "<<H4.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H4.Union(H3)========================================="<<std::endl;
    H4.Union(H3);
    H4.Traverse();
    std::cout<<"H4.total_node_num = "<<H4.GetTotalNodeNum()<<std::endl;
    std::cout<<"H4.root_list_size = "<<H4.GetRootListSize()<<std::endl;
    std::cout<<"H4.head = "<<H4.GetHeadRootList()<<std::endl;
    std::cout<<"H4.tail = "<<H4.GetTailRootList()<<std::endl;
    std::cout<<"H4.min_pointer = "<<"("<<H4.FindMin()->GetKey()<<", "<<H4.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H4.ExtractMin()========================================="<<std::endl;
    extracted_min = H4.ExtractMin();
    H4.Traverse();
    std::cout<<"H4.total_node_num = "<<H4.GetTotalNodeNum()<<std::endl;
    std::cout<<"H4.root_list_size = "<<H4.GetRootListSize()<<std::endl;
    std::cout<<"H4.head = "<<H4.GetHeadRootList()<<std::endl;
    std::cout<<"H4.tail = "<<H4.GetTailRootList()<<std::endl;
//    std::cout<<"H4.min_pointer = "<<"("<<H4.FindMin()->GetKey()<<", "<<H4.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;

    std::cout<<"=====================================H5========================================="<<std::endl;
    H5.InsertArbitrary(extracted_min);
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<H5.GetHeadRootList()<<std::endl;
    std::cout<<"H5.tail = "<<H5.GetTailRootList()<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H5.Union(H2)========================================="<<std::endl;
    H5.Union(H2);
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<H5.GetHeadRootList()<<std::endl;
    std::cout<<"H5.tail = "<<H5.GetTailRootList()<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H5.ExtractMin()========================================="<<std::endl;
    extracted_min = H5.ExtractMin();
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<H5.GetHeadRootList()<<std::endl;
    std::cout<<"H5.tail = "<<H5.GetTailRootList()<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;
    return EXIT_SUCCESS;
}
