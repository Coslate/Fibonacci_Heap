#ifndef _FIBONACCI_HEAP_H_
#define _FIBONACCI_HEAP_H_
#include <cstdlib>
#include <vector>
#include <queue>

class Fibonacci_Heap;

class FTNode{
        int key;
        int degree;
        int mark;
        int level;
        FTNode* parent;
        FTNode* child;
        FTNode* right_sibling;
        FTNode* left_sibling;
    public : 
        FTNode() : key(0), degree(0), mark(0), level(0), parent(NULL), child(NULL), right_sibling(this), left_sibling(this){};
        FTNode(const int value1, const int value2, const int value3, const int value4) : key(value1), degree(value2), mark(value3), level(value4), parent(NULL), child(NULL), right_sibling(this), left_sibling(this){};
        FTNode(const int value) : key(value), degree(0), mark(0), level(0), parent(NULL), child(NULL), right_sibling(this), left_sibling(this){};
        
        inline int GetKey(){return key;};
        friend class Fibonacci_Heap;
};

class Fibonacci_Heap{
        int root_list_size;
        int total_node_num;
        FTNode* head_root_list;
        FTNode* tail_root_list;
        FTNode* min_pointer;

    protected : 
        void Merge(Fibonacci_Heap &H1, Fibonacci_Heap &H2, Fibonacci_Heap &H_merged);
        void Link(FTNode* y, FTNode* z);
        void ExchangeSatelliteInfo(FTNode* const x, FTNode* const y);//Now only has one satellite : key. The function is used in DecreasekeySatellite.
        void ExchangeNodePos(FTNode* const x, FTNode* const y);//Used in Decreasekey()
        void UpdateMinPtr(Fibonacci_Heap &H_in);
        int  CalculateDepth(FTNode* const current_child_node, const int depth);
        void SetNodeMap(FTNode* const current_child_node, const int depth, std::vector<FTNode*>* &node_map);
        void BuildTestExample();
        void PrintList(FTNode* const head_ptr, const int print_width, std::queue<FTNode*> &parent_queue);
        void ConcatenateRootList(Fibonacci_Heap &H_in);
        void AddChildToRootList();

    public : 
        Fibonacci_Heap() : root_list_size(0), total_node_num(0), head_root_list(NULL), tail_root_list(NULL), min_pointer(NULL){};
        ~Fibonacci_Heap();
       
        bool           Delete(FTNode* const x);
        bool           DecreaseKey(FTNode* const x, const int changed_key);//Use the address as the index. Everytime the node bubble up, the node will exchange the position, and all the corresponding children will change the parent, which takes O(n).
        bool           DecreaseKeySatellite(FTNode* const x, const int changed_key);//Use the key as the index. DecreasekeySatellite needs to be used with Search(const int key), or the address of one parrent node may change, and afterward Decreasekey will decrease the wrong node with address.
        FTNode*        Search(const int key); // Takes O(n).
        FTNode*        ExtractMin();
        void           Traverse(const int print_width = 3, const bool debug = false);
        inline FTNode* FindMin(){if(min_pointer != NULL){return min_pointer;}else{std::cout<<"Error : The Fibonacci_Heap is empty."<<std::endl;return NULL;}};
        void           InsertArbitrary(const int key);
        void           InsertArbitrary(FTNode* const inserted_node);
        void           Union(Fibonacci_Heap &H_in);
        inline FTNode* GetHeadRootList(){return head_root_list;};
        inline FTNode* GetTailRootList(){return tail_root_list;};
        inline int     GetRootListSize(){return root_list_size;};
        inline int     GetTotalNodeNum(){return total_node_num;};
};

#endif
