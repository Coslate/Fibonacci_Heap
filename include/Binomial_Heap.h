#ifndef _BINOMIAL_HEAP_H_
#define _BINOMIAL_HEAP_H_
#include <cstdlib>

class Binomial_Heap;

class BTNode{
        int key;
        int degree;
        BTNode* parent;
        BTNode* left_child;
        BTNode* right_sibling;
        BTNode* left_sibling;
    public : 
        BTNode() : key(0), degree(0), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        BTNode(const int value1, const int value2) : key(value1), degree(value2), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        BTNode(const int value) : key(value), degree(0), parent(NULL), left_child(NULL), right_sibling(NULL), left_sibling(NULL){};
        
        int GetKey(){return key;};
        friend class Binomial_Heap;
};

class Binomial_Heap{
        int root_list_size;
        BTNode* head_root_list;
        BTNode* min_pointer;

    protected : 
        void Merge(Binomial_Heap &H1, Binomial_Heap &H2, Binomial_Heap &H_merged);
        void Link(BTNode* y, BTNode* z);
        void ExchangeSatelliteInfo(BTNode* const x, BTNode* const y);//Now only has one satellite : key. The function is used in DecreasekeySatellite.
        void ExchangeNodePos(BTNode* const x, BTNode* const y);//Used in Decreasekey()
        void UpdateMinPtr();

    public : 
        Binomial_Heap() : root_list_size(0), head_root_list(NULL){};
        ~Binomial_Heap();
       
        bool    Delete(BTNode* const x);
        bool    DecreaseKey(BTNode* const x, const int changed_key);//Use the address as the index. Everytime the node bubble up, the node will exchange the position, and all the corresponding children will change the parent, which takes O(n).
        bool    DecreaseKeySatellite(BTNode* const x, const int changed_key);//Use the key as the index. DecreasekeySatellite needs to be used with Search(const int key), or the address of one parrent node may change, and afterward Decreasekey will decrease the wrong node with address.
        BTNode* Search(const int key); // Takes O(n).
        BTNode* ExtractMin();
        void    Traverse();
        int     FindMin();
        void    InsertArbitrary(const int key);
        void    InsertArbitrary(BTNode* const inserted_node);
        void    Union(Binomial_Heap &H_in);
        BTNode* GetHeadRootList(){return head_root_list;};
        int     GetRootListSize(){return root_list_size;};
};

#endif
