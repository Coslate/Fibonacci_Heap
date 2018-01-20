#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <climits>
#include <Fibonacci_Heap.h>

Fibonacci_Heap::~Fibonacci_Heap(){
    BTNode* current_root_node = head_root_list;
    std::queue<BTNode*> child_root_queue;

    while(current_root_node != NULL){
        BTNode* current_left_child = current_root_node->left_child;
        while(current_left_child != NULL){
            child_root_queue.push(current_left_child);
            current_left_child = current_left_child->left_child;
        }

        while(!child_root_queue.empty()){
            BTNode* current_child_node = child_root_queue.front();
            while(current_child_node != NULL){
                BTNode* tmp_child_node = current_child_node;
                current_child_node = current_child_node->right_sibling;
                delete tmp_child_node;
            }
            child_root_queue.pop();
        }
        BTNode* tmp_node = current_root_node;
        current_root_node = current_root_node->right_sibling;
        delete tmp_node;
    }
}

void Fibonacci_Heap::Merge(Fibonacci_Heap &H1, Fibonacci_Heap &H2, Fibonacci_Heap &H_merged){
    BTNode* ret_head = NULL;
    
    if(H1.root_list_size == 0){
        ret_head = H2.head_root_list;
        H_merged.root_list_size = H2.root_list_size;
    }else if(H2.root_list_size == 0){
        ret_head = H1.GetHeadRootList();
        H_merged.root_list_size = H1.root_list_size;
    }else{
        BTNode* current_h1_node = H1.GetHeadRootList();
        BTNode* current_h2_node = H2.GetHeadRootList();
        BTNode** fin_root_node_arr = new BTNode* [H1.root_list_size+H2.root_list_size]();
        int i_fin = 0;

        while((current_h1_node != NULL) && (current_h2_node != NULL)){
            if(current_h1_node->degree < current_h2_node->degree){
                fin_root_node_arr[i_fin] = current_h1_node;
                current_h1_node = current_h1_node->right_sibling;
            }else{
                fin_root_node_arr[i_fin] = current_h2_node;
                current_h2_node = current_h2_node->right_sibling;
            }
            ++i_fin;
        }

        if(current_h1_node == NULL){
            while(current_h2_node != NULL){
                fin_root_node_arr[i_fin] = current_h2_node;
                current_h2_node = current_h2_node->right_sibling;
                ++i_fin;
            }
        }else if(current_h2_node == NULL){
             while(current_h1_node != NULL){
                fin_root_node_arr[i_fin] = current_h1_node;
                current_h1_node = current_h1_node->right_sibling;
                ++i_fin;
            }
        }

        //connect all the BTNode in the array, fin_root_node_arr.
        for(int i=0;i<i_fin;++i){
            if(i==i_fin-1){
                fin_root_node_arr[i]->right_sibling = NULL;
                fin_root_node_arr[i]->left_sibling = fin_root_node_arr[i-1];
            }else if(i==0){
                fin_root_node_arr[i]->right_sibling = fin_root_node_arr[i+1];
                fin_root_node_arr[i]->left_sibling = NULL;
            }else{
                fin_root_node_arr[i]->right_sibling = fin_root_node_arr[i+1];
                fin_root_node_arr[i]->left_sibling = fin_root_node_arr[i-1];
            }
        }
        ret_head = fin_root_node_arr[0];
        H_merged.root_list_size = i_fin;
        delete [] fin_root_node_arr; 
    }
    //free H2
    H2.head_root_list = NULL;
    H2.root_list_size = 0;

    //H_merged
    H_merged.head_root_list = ret_head;
}

void Fibonacci_Heap::Union(Fibonacci_Heap &H_in){
    Merge(*this, H_in, *this);
   
    if(this->root_list_size == 0){
        //Update the min_pointer;
        UpdateMinPtr();
        return;
    }else{
        BTNode* prev_x = NULL;
        BTNode* x      = this->head_root_list;
        BTNode* next_x = x->right_sibling;

        while(next_x != NULL){
            if((x->degree != next_x->degree) || ((next_x->right_sibling != NULL) && (next_x->right_sibling->degree == x->degree))){
                prev_x = x;
                x = next_x;
            }else if(x->key <= next_x->key){
                x->right_sibling = next_x->right_sibling;
                if(next_x->right_sibling != NULL){
                    next_x->right_sibling->left_sibling = x;
                }
                Link(next_x, x);
            }else{
                if(prev_x == NULL){
                    this->head_root_list = next_x;
                    next_x->left_sibling = NULL;
                }else{
                    prev_x->right_sibling = next_x;
                    next_x->left_sibling = prev_x;
                }
                Link(x, next_x);
                x = next_x;
            }
            next_x = x->right_sibling; 
        }
    }
    
    //Update the min_pointer;
    UpdateMinPtr();
}

void Fibonacci_Heap::UpdateMinPtr(){
    BTNode* root_list = head_root_list;
    min_pointer = root_list;
    while(root_list != NULL){
        if(root_list->key < min_pointer->key){
            min_pointer = root_list;
        }
        root_list = root_list->right_sibling;
    }
}

void Fibonacci_Heap::Link(BTNode* y, BTNode* z){
    y->parent = z;
    y->right_sibling = z->left_child;
    y->left_sibling = NULL;
    if(z->left_child != NULL){
        z->left_child->left_sibling = y;
    }
    z->left_child = y;
    z->degree += 1;
    root_list_size -= 1;
}

void Fibonacci_Heap::Traverse(){
    BTNode* current_root_node = head_root_list;
    std::queue<BTNode*> child_root_queue;
    int count_root = 0;

    while(current_root_node != NULL){
        BTNode* current_left_child = current_root_node->left_child;
        while(current_left_child != NULL){
            child_root_queue.push(current_left_child);
            current_left_child = current_left_child->left_child;
        }

        //print
        std::cout<<"##################################"<<std::endl;
        std::cout<<"#########      B"<<count_root<<"      ###########"<<std::endl;
        std::cout<<"##################################"<<std::endl;
        std::cout<<"("<<current_root_node->key<<", "<<current_root_node<<", "<<current_root_node->degree<<")"<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        while(!child_root_queue.empty()){
            BTNode* current_child_node = child_root_queue.front();
            while(current_child_node != NULL){
                if(current_child_node->right_sibling == NULL){
                    std::cout<<"("<<current_child_node->key<<", "<<current_child_node<<", "<<current_child_node->degree<<")"<<std::endl;
                }else{
                    std::cout<<"("<<current_child_node->key<<", "<<current_child_node<<", "<<current_child_node->degree<<"), ";
                }               
                current_child_node = current_child_node->right_sibling;
            }
            child_root_queue.pop();
            if(!child_root_queue.empty()){
                std::cout<<"-----------------------"<<std::endl;
            }
        }
        current_root_node = current_root_node->right_sibling;
        ++count_root;
    }
}

void Fibonacci_Heap::InsertArbitrary(const int key){
    Fibonacci_Heap* H_inserted = new Fibonacci_Heap();
    BTNode* inserted_node = new BTNode(key, 0);
    H_inserted->root_list_size += 1;
    H_inserted->head_root_list = inserted_node;
    
    Union(*H_inserted);
    delete H_inserted;
}

void Fibonacci_Heap::InsertArbitrary(BTNode* const inserted_node){
    if(inserted_node->right_sibling != NULL){
        std::cout<<"Error : The inserted_node should be the single node."<<std::endl;
        return;
    }

    Fibonacci_Heap* H_inserted = new Fibonacci_Heap();
    H_inserted->root_list_size += 1;
    H_inserted->head_root_list = inserted_node;

    Union(*H_inserted);
    delete H_inserted;
}

BTNode* Fibonacci_Heap::ExtractMin(){
    if(head_root_list == NULL){
        std::cout<<"Error : The Fibonacci_Heap is already empty."<<std::endl;
        return NULL;
    }

    BTNode* min_child = min_pointer->left_child;
    BTNode* current_child = min_pointer->left_child;
    BTNode* child_new_head = NULL;
    BTNode* last_node = NULL;
    BTNode* min_ptr = min_pointer;
    std::stack<BTNode*> child_list_stack;
    int index_cnt = 0;

    //Extract the min from the original root_list.
    if(min_pointer->left_sibling == NULL){
        head_root_list = min_pointer->right_sibling;
        if(min_pointer->right_sibling != NULL){
            min_pointer->right_sibling->left_sibling = NULL;
        }
    }else{
        min_pointer->left_sibling->right_sibling = min_pointer->right_sibling;
         if(min_pointer->right_sibling != NULL){
            min_pointer->right_sibling->left_sibling = min_pointer->left_sibling;
        }       
    }

    min_ptr->right_sibling = NULL;
    if(min_child != NULL){
        min_child->parent = NULL;
    }
    --root_list_size;

    //Reverse the min_child list to construct the new Fibonacci_Heap.
    while(current_child != NULL){
        child_list_stack.push(current_child);
        current_child = current_child->right_sibling;
    }

    int child_size = child_list_stack.size();
    while(!child_list_stack.empty()){
        if(index_cnt == 0){
            last_node = child_list_stack.top(); 
            child_new_head = last_node;
            child_new_head->left_sibling = NULL;
        }else{
            BTNode* current_node = child_list_stack.top();
            last_node->right_sibling = current_node;
            current_node->left_sibling = last_node;
            last_node = current_node;

            if(index_cnt == (child_size - 1)){
                last_node->right_sibling = NULL;
            }
        }
        child_list_stack.pop();
        ++index_cnt;
    }

    Fibonacci_Heap* tmp_Heap = new Fibonacci_Heap();
    tmp_Heap->root_list_size = index_cnt;
    tmp_Heap->head_root_list = child_new_head;
    Union(*tmp_Heap);
    delete tmp_Heap;

    return min_ptr;
}

BTNode* Fibonacci_Heap::Search(const int key){
    if(key < min_pointer->key){
        std::cout<<"Search("<<key<<") not found."<<std::endl;
        return NULL;
    }else if(key == min_pointer->key){
        return min_pointer;
    }

    BTNode* ans_node = NULL;
    BTNode* current_root_node = head_root_list;
    std::queue<BTNode*> child_root_queue;
    child_root_queue.push(current_root_node);

    while(!child_root_queue.empty()){
        BTNode* examinate_node = child_root_queue.front();
        child_root_queue.pop();

        BTNode* current_node = examinate_node;
        while(current_node != NULL){
            if(current_node->key == key){
                ans_node = current_node;
                break;
            }else if((current_node->key < key) && (current_node->left_child != NULL)){
                child_root_queue.push(current_node->left_child);
            }
                
            current_node = current_node->right_sibling;
        }

        if(ans_node != NULL){
            break;
        }
    }
    
    if(ans_node == NULL){
        std::cout<<"Search("<<key<<") not found."<<std::endl;
    }

    return ans_node;
}

void Fibonacci_Heap::ExchangeSatelliteInfo(BTNode* const x, BTNode* const y){
    BTNode* tmp = new BTNode();
    tmp->key = x->key;
    x->key = y->key;
    y->key = tmp->key;
    delete tmp;
}

void Fibonacci_Heap::ExchangeNodePos(BTNode* const x, BTNode* const y){
    BTNode* tmp = new BTNode();
    tmp->parent = y->parent;
    tmp->left_child = y->left_child;
    tmp->left_sibling = y->left_sibling;
    tmp->right_sibling = y->right_sibling;
    tmp->degree = y->degree;

    //Replace x with y. x is the parent of y
    if(x->parent != NULL){
        if(x->parent->left_child == x){
            x->parent->left_child = y;
        }   
    }
    if(x->right_sibling != NULL){
        x->right_sibling->left_sibling = y;
    }
    if(x->left_sibling != NULL){
        x->left_sibling->right_sibling = y;
    }
    if(x->left_child == y){
        y->left_child = x;
    }else{
        y->left_child = x->left_child;
    }
    y->right_sibling = x->right_sibling;
    y->left_sibling = x->left_sibling;
    y->parent = x->parent;
    y->degree = x->degree;

    //Replace y with x. y is one of the children of x.
    if(tmp->right_sibling != NULL){
        tmp->right_sibling->left_sibling = x;
    }
    if(tmp->left_sibling != NULL){
        tmp->left_sibling->right_sibling = x;
    }
    if(tmp->left_child != NULL){
        BTNode* current_tmp_child = tmp->left_child;
        while(current_tmp_child != NULL){
            current_tmp_child->parent = x;
            current_tmp_child = current_tmp_child->right_sibling;
        }
    }
    x->left_child = tmp->left_child;
    x->right_sibling = tmp->right_sibling;
    x->left_sibling = tmp->left_sibling;
    x->degree = tmp->degree;

    BTNode* current_y_child = y->left_child;
    while(current_y_child != NULL){
        current_y_child->parent = y;
        current_y_child = current_y_child->right_sibling;
    }

    delete tmp;
}

bool Fibonacci_Heap::DecreaseKey(BTNode* const x, const int changed_key){
    if(x == NULL){
        std::cout<<"Error : The input BTNode x is "<<x<<std::endl;
        return false;
    }

    if(changed_key > x->key){
        std::cout<<"Error : New key is greater than current key at the node with address "<<x<<std::endl;
        return false;
    }

    x->key = changed_key;
    BTNode* y = x;
    BTNode* z = x->parent;

    while((z != NULL) && (y->key < z->key)){
        ExchangeNodePos(z, y);
        z = y->parent;
    }

    if(z == NULL){
        UpdateMinPtr();
    }
    return true;
}

bool Fibonacci_Heap::DecreaseKeySatellite(BTNode* const x, const int changed_key){
    if(x == NULL){
        std::cout<<"Error : The input BTNode x is "<<x<<std::endl;
        return false;
    }

    if(changed_key > x->key){
        std::cout<<"Error : New key is greater than current key at the node with address "<<x<<std::endl;
        return false;
    }

    x->key = changed_key;
    BTNode* y = x;
    BTNode* z = x->parent;

    while((z != NULL) && (y->key < z->key)){
        ExchangeSatelliteInfo(z, y);
        y = z;
        z = y->parent;
    }

    if(z == NULL){
        UpdateMinPtr();
    }
    return true;
}

int Fibonacci_Heap::FindMin(){
    if(min_pointer != NULL){
        return min_pointer->key;
    }else{
        std::cout<<"Error : The Fibonacci_Heap is empty."<<std::endl;
        return -1;
    }
}

bool Fibonacci_Heap::Delete(BTNode* const x){
    if(DecreaseKey(x, -INT_MAX)){
        ExtractMin();
        return true;
    }else{
        return false;
    }
}
