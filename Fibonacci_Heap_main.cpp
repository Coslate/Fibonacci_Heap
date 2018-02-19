#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <Fibonacci_Heap.h>

int main(){
    Fibonacci_Heap H1;
    Fibonacci_Heap H2;
    Fibonacci_Heap H3;
    Fibonacci_Heap H4;
    Fibonacci_Heap H5;
    Fibonacci_Heap H6;

    std::cout<<"=====================================H1========================================="<<std::endl;
    H1.Traverse(3, true);
    std::cout<<"H1.total_node_num = "<<H1.GetTotalNodeNum()<<std::endl;
    std::cout<<"H1.root_list_size = "<<H1.GetRootListSize()<<std::endl;
    std::cout<<"H1.head = "<<"("<<H1.GetHeadRootList()->GetKey()<<", "<<H1.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H1.tail = "<<"("<<H1.GetTailRootList()->GetKey()<<", "<<H1.GetTailRootList()<<")"<<std::endl;
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
    std::cout<<"H2.head = "<<"("<<H2.GetHeadRootList()->GetKey()<<", "<<H2.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H2.tail = "<<"("<<H2.GetTailRootList()->GetKey()<<", "<<H2.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2.Union(H3)========================================="<<std::endl;
    H2.Union(H3);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<"("<<H2.GetHeadRootList()->GetKey()<<", "<<H2.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H2.tail = "<<"("<<H2.GetTailRootList()->GetKey()<<", "<<H2.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H3========================================="<<std::endl;
    H3.InsertArbitrary(1);
    H3.InsertArbitrary(2);
    H3.InsertArbitrary(99);
    H3.Traverse();
    std::cout<<"H3.total_node_num = "<<H3.GetTotalNodeNum()<<std::endl;
    std::cout<<"H3.root_list_size = "<<H3.GetRootListSize()<<std::endl;
    std::cout<<"H3.head = "<<"("<<H3.GetHeadRootList()->GetKey()<<", "<<H3.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H3.tail = "<<"("<<H3.GetTailRootList()->GetKey()<<", "<<H3.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H3.min_pointer = "<<"("<<H3.FindMin()->GetKey()<<", "<<H3.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2.Union(H3)========================================="<<std::endl;
    H2.Union(H3);
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<"("<<H2.GetHeadRootList()->GetKey()<<", "<<H2.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H2.tail = "<<"("<<H2.GetTailRootList()->GetKey()<<", "<<H2.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H2.ExtractMin()========================================="<<std::endl;
    FTNode* extracted_min = NULL;
    extracted_min = H2.ExtractMin();
    H2.Traverse();
    std::cout<<"H2.total_node_num = "<<H2.GetTotalNodeNum()<<std::endl;
    std::cout<<"H2.root_list_size = "<<H2.GetRootListSize()<<std::endl;
    std::cout<<"H2.head = "<<"("<<H2.GetHeadRootList()->GetKey()<<", "<<H2.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H2.tail = "<<"("<<H2.GetTailRootList()->GetKey()<<", "<<H2.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H2.min_pointer = "<<"("<<H2.FindMin()->GetKey()<<", "<<H2.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;
    std::cout<<"=====================================H4========================================="<<std::endl;
    FTNode* new_200_node = new FTNode(200);
    H4.InsertArbitrary(new_200_node);
    H4.Traverse();
    std::cout<<"H4.total_node_num = "<<H4.GetTotalNodeNum()<<std::endl;
    std::cout<<"H4.root_list_size = "<<H4.GetRootListSize()<<std::endl;
    std::cout<<"H4.head = "<<"("<<H4.GetHeadRootList()->GetKey()<<", "<<H4.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H4.tail = "<<"("<<H4.GetTailRootList()->GetKey()<<", "<<H4.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H4.min_pointer = "<<"("<<H4.FindMin()->GetKey()<<", "<<H4.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H4.Union(H3)========================================="<<std::endl;
    H4.Union(H3);
    H4.Traverse();
    std::cout<<"H4.total_node_num = "<<H4.GetTotalNodeNum()<<std::endl;
    std::cout<<"H4.root_list_size = "<<H4.GetRootListSize()<<std::endl;
    std::cout<<"H4.head = "<<"("<<H4.GetHeadRootList()->GetKey()<<", "<<H4.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H4.tail = "<<"("<<H4.GetTailRootList()->GetKey()<<", "<<H4.GetTailRootList()<<")"<<std::endl;
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
    std::cout<<"H5.head = "<<"("<<H5.GetHeadRootList()->GetKey()<<", "<<H5.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H5.tail = "<<"("<<H5.GetTailRootList()->GetKey()<<", "<<H5.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;

    std::cout<<"=====================================H5.Union(H2)========================================="<<std::endl;
    H5.Union(H2);
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<"("<<H5.GetHeadRootList()->GetKey()<<", "<<H5.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H5.tail = "<<"("<<H5.GetTailRootList()->GetKey()<<", "<<H5.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H5.ExtractMin()========================================="<<std::endl;
    extracted_min = H5.ExtractMin();
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<"("<<H5.GetHeadRootList()->GetKey()<<", "<<H5.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H5.tail = "<<"("<<H5.GetTailRootList()->GetKey()<<", "<<H5.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;
    std::cout<<"=====================================H5.DecreaseKey(200, 1)========================================="<<std::endl;
    if(!H5.DecreaseKey(new_200_node, 1)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<"("<<H5.GetHeadRootList()->GetKey()<<", "<<H5.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H5.tail = "<<"("<<H5.GetTailRootList()->GetKey()<<", "<<H5.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H5.min_pointer = "<<"("<<H5.FindMin()->GetKey()<<", "<<H5.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H5.Delete(new_15_node)========================================="<<std::endl;
    if(!H5.Delete(new_15_node)){
        std::cout<<"Error : Delete fails."<<std::endl;
    }
    H5.Traverse();
    std::cout<<"H5.total_node_num = "<<H5.GetTotalNodeNum()<<std::endl;
    std::cout<<"H5.root_list_size = "<<H5.GetRootListSize()<<std::endl;
    std::cout<<"H5.head = "<<"("<<H5.GetHeadRootList()->GetKey()<<", "<<H5.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H5.tail = "<<"("<<H5.GetTailRootList()->GetKey()<<", "<<H5.GetTailRootList()<<")"<<std::endl;
    std::cout<<"=====================================H6.InsertArbitrary()========================================="<<std::endl;
    FTNode* new_1000_node = new FTNode(1000);
    FTNode* new_2000_node = new FTNode(2000);
    FTNode* new_3000_node = new FTNode(3000);
    FTNode* new_4000_node = new FTNode(4000);
    FTNode* new_5000_node = new FTNode(5000);
    FTNode* new_6000_node = new FTNode(6000);
    FTNode* new_7000_node = new FTNode(7000);
    FTNode* new_8000_node = new FTNode(8000);
    FTNode* new_9000_node = new FTNode(9000);
    FTNode* new_10000_node = new FTNode(10000);
    FTNode* new_11000_node = new FTNode(11000);
    FTNode* new_12000_node = new FTNode(12000);
    FTNode* new_13000_node = new FTNode(13000);
    FTNode* new_14000_node = new FTNode(14000);
    FTNode* new_15000_node = new FTNode(15000);
    FTNode* new_16000_node = new FTNode(16000);
    FTNode* new_17000_node = new FTNode(17000);
    H6.InsertArbitrary(new_1000_node);
    H6.InsertArbitrary(new_2000_node);
    H6.InsertArbitrary(new_3000_node);
    H6.InsertArbitrary(new_4000_node);
    H6.InsertArbitrary(new_5000_node);
    H6.InsertArbitrary(new_6000_node);
    H6.InsertArbitrary(new_7000_node);
    H6.InsertArbitrary(new_8000_node);
    H6.InsertArbitrary(new_9000_node);
    H6.InsertArbitrary(new_10000_node);
    H6.InsertArbitrary(new_11000_node);
    H6.InsertArbitrary(new_12000_node);
    H6.InsertArbitrary(new_13000_node);
    H6.InsertArbitrary(new_14000_node);
    H6.InsertArbitrary(new_15000_node);
    H6.InsertArbitrary(new_16000_node);
    H6.InsertArbitrary(new_17000_node);
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.ExtractMin()========================================="<<std::endl;
    extracted_min = NULL;
    extracted_min = H6.ExtractMin();
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"extracted_min = "<<"("<<extracted_min->GetKey()<<", "<<extracted_min<<")"<<std::endl;
    std::cout<<"=====================================H6.DecreaseKey(7000, 50)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_7000_node, 50)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(9000, 60)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_9000_node, 60)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(8000, 20)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_8000_node, 20)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(11000, 98)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_11000_node, 98)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(15000, 95)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_15000_node, 95)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(17000, 32)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_17000_node, 32)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;   
    std::cout<<"=====================================H6.DecreaseKey(16000, 6)========================================="<<std::endl;
    if(!H6.DecreaseKey(new_16000_node, 6)){
        std::cout<<"Error : DecreaseKey fails."<<std::endl;
    }
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;
    std::cout<<"=====================================H6.Search(5000)========================================="<<std::endl;
    FTNode* searched_node = H6.Search(5000);
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;
    if(searched_node != NULL){
        std::cout<<"searched_node = "<<"("<<searched_node->GetKey()<<", "<<searched_node<<")"<<std::endl;
    }else{
        std::cout<<"Error : Search not found."<<std::endl;
    }
    std::cout<<"=====================================H6.InsertArbitrary(5000) & Search(5000)========================================="<<std::endl;
    FTNode* new_5000_node2 = new FTNode(5000);
    H6.InsertArbitrary(new_5000_node2);
    searched_node = H6.Search(5000);
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;
    if(searched_node != NULL){
        std::cout<<"searched_node = "<<"("<<searched_node->GetKey()<<", "<<searched_node<<")"<<std::endl;
    }else{
        std::cout<<"Error : Search not found."<<std::endl;
    }
    std::cout<<"=====================================H6.Delete(5000) & Search(5000)========================================="<<std::endl;
    if(!H6.Delete(new_5000_node2)){
        std::cout<<"Error : Delete fails."<<std::endl;
    }
    searched_node = H6.Search(5000);
    H6.Traverse(6);
    std::cout<<"H6.total_node_num = "<<H6.GetTotalNodeNum()<<std::endl;
    std::cout<<"H6.root_list_size = "<<H6.GetRootListSize()<<std::endl;
    std::cout<<"H6.head = "<<"("<<H6.GetHeadRootList()->GetKey()<<", "<<H6.GetHeadRootList()<<")"<<std::endl;
    std::cout<<"H6.tail = "<<"("<<H6.GetTailRootList()->GetKey()<<", "<<H6.GetTailRootList()<<")"<<std::endl;
    std::cout<<"H6.min_pointer = "<<"("<<H6.FindMin()->GetKey()<<", "<<H6.FindMin()<<")"<<std::endl;
    if(searched_node != NULL){
        std::cout<<"searched_node = "<<"("<<searched_node->GetKey()<<", "<<searched_node<<")"<<std::endl;
    }else{
        std::cout<<"Error : Search not found."<<std::endl;
    }
    return EXIT_SUCCESS;
}
