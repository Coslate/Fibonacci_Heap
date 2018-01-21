#ifndef _Fibonacci_HEAP_H_
#define _Fibonacci_HEAP_H_
#include <cstdlib>

class Fibonacci_Heap;

class FTNode{
        int key;
        int degree;
        FTNode* parent;
        FTNode* left_child;
        FTNode* right_sibling;
        FTNode* left_sibling;
    public : 
        FTNode() : key(0), degree(0), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        FTNode(const int value1, const int value2) : key(value1), degree(value2), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        FTNode(const int value) : key(value), degree(0), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        
        int GetKey(){return key;};
        friend class Fibonacci_Heap;
};

class Fibonacci_Heap{
        int root_list_size;
        FTNode* head_root_list;
        FTNode* min_pointer;

    protected : 
        void Merge(Fibonacci_Heap &H1, Fibonacci_Heap &H2, Fibonacci_Heap &H_merged);
        void Link(FTNode* y, FTNode* z);
        void ExchangeSatelliteInfo(FTNode* const x, FTNode* const y);//Now only has one satellite : key. The function is used in DecreasekeySatellite.
        void ExchangeNodePos(FTNode* const x, FTNode* const y);//Used in Decreasekey()
        void UpdateMinPtr();

    public : 
        Fibonacci_Heap() : root_list_size(0), head_root_list(NULL){};
        ~Fibonacci_Heap();
       
        bool    Delete(FTNode* const x);
        bool    DecreaseKey(FTNode* const x, const int changed_key);//Use the address as the index. Everytime the node bubble up, the node will exchange the position, and all the corresponding children will change the parent, which takes O(n).
        bool    DecreaseKeySatellite(FTNode* const x, const int changed_key);//Use the key as the index. DecreasekeySatellite needs to be used with Search(const int key), or the address of one parrent node may change, and afterward Decreasekey will decrease the wrong node with address.
        FTNode* Search(const int key); // Takes O(n).
        FTNode* ExtractMin();
        void    Traverse();
        int     FindMin();
        void    InsertArbitrary(const int key);
        void    InsertArbitrary(FTNode* const inserted_node);
        void    Union(Fibonacci_Heap &H_in);
        FTNode* GetHeadRootList(){return head_root_list;};
        int     GetRootListSize(){return root_list_size;};
};

#endif
