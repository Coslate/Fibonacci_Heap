//master
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <Binomial_Heap.h>

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
    Binomial_Heap H1;
    Binomial_Heap H2;
    Binomial_Heap H3;

    BTNode* min_ptr;
    BTNode* ans_node = NULL;


//    H1.InsertArbitrary(41);
    BTNode* new_node = new BTNode(41);
    H1.InsertArbitrary(new_node);
    std::cout<<"<<<<<<<<<<<<<<<H1 Insert 41>>>>>>>>>>>>>>>>"<<std::endl;

    //H1.InsertArbitrary(28);
    BTNode* new_node3 = new BTNode(28);
    H1.InsertArbitrary(new_node3);
    std::cout<<"<<<<<<<<<<<<<<<H1 Insert 28>>>>>>>>>>>>>>>>"<<std::endl;

    H1.InsertArbitrary(33);
    std::cout<<"<<<<<<<<<<<<<<<H1 Insert 33>>>>>>>>>>>>>>>>"<<std::endl;

//    H1.InsertArbitrary(15);
    BTNode* new_node2 = new BTNode(15);
    H1.InsertArbitrary(new_node2);
    std::cout<<"<<<<<<<<<<<<<<<H1 Insert 15>>>>>>>>>>>>>>>>"<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H1 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H1.Traverse();
    std::cout<<"H1 min = "<<H1.FindMin()<<std::endl;
    std::cout<<"H1 root_list_size = "<<H1.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H1.Search(15)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H1.Search(15);
    std::cout<<"Search(15) = "<<ans_node<<std::endl;


    H2.InsertArbitrary(7);
    std::cout<<"<<<<<<<<<<<<<<<H2 Insert 7>>>>>>>>>>>>>>>>"<<std::endl;

    BTNode* new_node4 = new BTNode(25);
    H2.InsertArbitrary(new_node4);
    std::cout<<"<<<<<<<<<<<<<<<H2 Insert 25>>>>>>>>>>>>>>>>"<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H2 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H2.Traverse();
    std::cout<<"H2 min = "<<H2.FindMin()<<std::endl;
    std::cout<<"H2 root_list_size = "<<H2.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H1.Union(H2)>>>>>>>>>>>>>>>>"<<std::endl;
    H1.Union(H2);
    std::cout<<"<<<<<<<<<<<<<<<H1 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H1.Traverse();
    std::cout<<"H1 min = "<<H1.FindMin()<<std::endl;
    std::cout<<"H1 root_list_size = "<<H1.GetRootListSize()<<std::endl;

    H3.InsertArbitrary(12);
    std::cout<<"<<<<<<<<<<<<<<<H3 Insert 12>>>>>>>>>>>>>>>>"<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Union(H1)>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Union(H1);
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Search(49)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(49);
    std::cout<<"Search(49) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(28)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(28);
    std::cout<<"Search(28) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(25)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(25);
    std::cout<<"Search(25) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(12)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(12);
    std::cout<<"Search(12) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(7)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(7);
    std::cout<<"Search(7) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(15)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(15);
    std::cout<<"Search(15) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(33)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(33);
    std::cout<<"Search(33) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3.Search(41)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(41);
    std::cout<<"Search(41) = "<<ans_node<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.ExtractMin>>>>>>>>>>>>>>>>"<<std::endl;
    min_ptr = H3.ExtractMin();
    std::cout<<"min_ptr->key = "<<min_ptr->GetKey()<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.ExtractMin>>>>>>>>>>>>>>>>"<<std::endl;
    min_ptr = H3.ExtractMin();
    std::cout<<"min_ptr->key = "<<min_ptr->GetKey()<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.DecreaseKey(41 -> 3)>>>>>>>>>>>>>>>>"<<std::endl;
//    std::cout<<"<<<<<<<<<<<<<<<H3.DecreaseKeySatellite(0xa50030 41 -> 3)>>>>>>>>>>>>>>>>"<<std::endl;
    BTNode* x = new_node;
    std::cout<<"x = "<<x<<std::endl;
    std::cout<<"H3.DecreaseKey(x, 3)"<<std::endl;
//    if(!H3.DecreaseKeySatellite(x, 3)){
    if(!H3.DecreaseKey(x, 3)){
        std::cout<<"Error : plese check Binomial_Heap::DecreaseKey."<<std::endl;
        return -1;
    }
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.DecreaseKey(28 -> 14)>>>>>>>>>>>>>>>>"<<std::endl;
//    std::cout<<"<<<<<<<<<<<<<<<H3.DecreaseKeySatellite(0x1bb6060 28 -> 14)>>>>>>>>>>>>>>>>"<<std::endl;
    BTNode* y = new_node3;
    std::cout<<"y = "<<y<<std::endl;
    std::cout<<"H3.DecreaseKey(y, 14)"<<std::endl;
//    if(!H3.DecreaseKeySatellite(y, 14)){
    if(!H3.DecreaseKey(y, 14)){
        std::cout<<"Error : plese check Binomial_Heap::DecreaseKey."<<std::endl;
        return -1;
    }
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Delete(25)>>>>>>>>>>>>>>>>"<<std::endl;
    BTNode* z = new_node4;
    std::cout<<"z = "<<z<<std::endl;
    std::cout<<"H3.Delete(z)"<<std::endl;
    H3.Delete(z);
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Delete(3)>>>>>>>>>>>>>>>>"<<std::endl;
    z = new_node;
    std::cout<<"z = "<<z<<std::endl;
    std::cout<<"H3.Delete(z)"<<std::endl;
    H3.Delete(z);
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Delete(15)>>>>>>>>>>>>>>>>"<<std::endl;
    z = new_node2;
    std::cout<<"z = "<<z<<std::endl;
    std::cout<<"H3.Delete(z)"<<std::endl;
    H3.Delete(z);
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    std::cout<<"<<<<<<<<<<<<<<<H3.Search(33)>>>>>>>>>>>>>>>>"<<std::endl;
    ans_node = H3.Search(33);
    std::cout<<"Search(33) = "<<ans_node<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<H3 Traverse>>>>>>>>>>>>>>>>"<<std::endl;
    H3.Traverse();
    std::cout<<"H3 min = "<<H3.FindMin()<<std::endl;
    std::cout<<"H3 root_list_size = "<<H3.GetRootListSize()<<std::endl;

    return EXIT_SUCCESS;
}
