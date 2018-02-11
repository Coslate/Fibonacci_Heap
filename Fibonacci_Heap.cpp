#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <iomanip>
#include <Fibonacci_Heap.h>

Fibonacci_Heap::~Fibonacci_Heap(){
    std::cout<<"It is destructor."<<std::endl;
}

void Fibonacci_Heap::Merge(Fibonacci_Heap &H1, Fibonacci_Heap &H2, Fibonacci_Heap &H_merged){
    FTNode* ret_head = NULL;
    
    if(H1.root_list_size == 0){
        ret_head = H2.head_root_list;
        H_merged.root_list_size = H2.root_list_size;
    }else if(H2.root_list_size == 0){
        ret_head = H1.GetHeadRootList();
        H_merged.root_list_size = H1.root_list_size;
    }else{
        FTNode* current_h1_node = H1.GetHeadRootList();
        FTNode* current_h2_node = H2.GetHeadRootList();
        FTNode** fin_root_node_arr = new FTNode* [H1.root_list_size+H2.root_list_size]();
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

        //connect all the FTNode in the array, fin_root_node_arr.
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

void Fibonacci_Heap::ConcatenateRootList(Fibonacci_Heap &H_in){
    if(H_in.total_node_num == 0){
        return;
    }

    if(total_node_num == 0){
        min_pointer = H_in.min_pointer;
        root_list_size = H_in.root_list_size;
        total_node_num = H_in.total_node_num;
        head_root_list = H_in.head_root_list;
        tail_root_list = H_in.tail_root_list;
        return;
    } 

    tail_root_list->right_sibling = H_in.head_root_list;
    H_in.head_root_list->left_sibling = tail_root_list;

    H_in.tail_root_list->right_sibling = head_root_list;
    head_root_list->left_sibling = H_in.tail_root_list;
    total_node_num += H_in.total_node_num;
    root_list_size += H_in.root_list_size;
    tail_root_list = H_in.tail_root_list;
}

void Fibonacci_Heap::Union(Fibonacci_Heap &H_in){
    ConcatenateRootList(H_in);
    //Update the min_pointer;
    UpdateMinPtr(H_in);
    //Release H_in
    H_in.total_node_num = 0;
    H_in.root_list_size = 0;
    H_in.head_root_list = NULL;
    H_in.tail_root_list = NULL;
    H_in.min_pointer = NULL;
}

void Fibonacci_Heap::UpdateMinPtr(Fibonacci_Heap &H_in){
    if(H_in.total_node_num == 0){
        return;
    }else if(total_node_num == 0){
        min_pointer = H_in.min_pointer;
    }else if(H_in.min_pointer->key < min_pointer->key){
        min_pointer = H_in.min_pointer;
    }
}

void Fibonacci_Heap::Link(FTNode* y, FTNode* z){
    y->parent = z;
    y->right_sibling = z->child;
    y->left_sibling = NULL;
    if(z->child != NULL){
        z->child->left_sibling = y;
    }
    z->child = y;
    z->degree += 1;
    root_list_size -= 1;
}

int Fibonacci_Heap::CalculateDepth(FTNode* const current_child_node, const int depth){
    FTNode* current_traverse_node = current_child_node;
    int start_pt = 0;
    int find_depth = depth;
    int find_depth_max = find_depth;

    while(((current_traverse_node != current_child_node) || (start_pt == 0)) && (current_traverse_node != NULL)){
        if(current_traverse_node->child != NULL){
            find_depth = CalculateDepth(current_traverse_node->child, depth+1);
            if(find_depth > find_depth_max){
                find_depth_max = find_depth;
            }
        }

        if(start_pt == 0){
            ++start_pt;
        }
        current_traverse_node = current_traverse_node->right_sibling;
    }

    return find_depth_max;
}

void Fibonacci_Heap::SetNodeMap(FTNode* const current_child_node, const int depth, std::vector<FTNode*>* &node_map){
    FTNode* current_traverse_node = current_child_node;
    int start_pt = 0;

    while(((current_traverse_node != current_child_node) || (start_pt == 0)) && (current_traverse_node != NULL)){
        node_map[depth].push_back(current_traverse_node);
        current_traverse_node->level = depth;
        if(current_traverse_node->child != NULL){
            SetNodeMap(current_traverse_node->child, depth+1, node_map);
        }

        if(start_pt == 0){
            ++start_pt;
        }
        current_traverse_node = current_traverse_node->right_sibling;
    }
}

void Fibonacci_Heap::BuildTestExample(){
    FTNode* seven_node = new FTNode(7);
    FTNode* seventeen_node = new FTNode(17);
    FTNode* thirty_node = new FTNode(30);
    FTNode* three_node = new FTNode(3);
    FTNode* eighteen_node = new FTNode(18);
    FTNode* fifty_two_node = new FTNode(52);
    FTNode* thirty_eight_node = new FTNode(38);
    FTNode* thirty_nine_node = new FTNode(39);
    FTNode* forty_one_node = new FTNode(41);
    FTNode* forty_two_node = new FTNode(42);
    FTNode* forty_three_node = new FTNode(43);
    FTNode* forty_four_node = new FTNode(44);
    FTNode* sixty_nine_node = new FTNode(69);
    FTNode* twenty_four_node = new FTNode(24);
    FTNode* twenty_six_node = new FTNode(26);
    FTNode* forty_six_node = new FTNode(46);
    FTNode* thirty_five_node = new FTNode(35);
   
    std::cout<<"("<<seven_node->key<<", "<<seven_node<<")"<<std::endl;
    std::cout<<"("<<seventeen_node->key<<", "<<seventeen_node<<")"<<std::endl;
    std::cout<<"("<<thirty_node->key<<", "<<thirty_node<<")"<<std::endl;
    std::cout<<"("<<three_node->key<<", "<<three_node<<")"<<std::endl;
    std::cout<<"("<<eighteen_node->key<<", "<<eighteen_node<<")"<<std::endl;
    std::cout<<"("<<fifty_two_node->key<<", "<<fifty_two_node<<")"<<std::endl;
    std::cout<<"("<<thirty_eight_node->key<<", "<<thirty_eight_node<<")"<<std::endl;
    std::cout<<"("<<thirty_nine_node->key<<", "<<thirty_nine_node<<")"<<std::endl;
    std::cout<<"("<<forty_one_node->key<<", "<<forty_one_node<<")"<<std::endl;
    std::cout<<"("<<forty_two_node->key<<", "<<forty_two_node<<")"<<std::endl;
    std::cout<<"("<<forty_three_node->key<<", "<<forty_three_node<<")"<<std::endl;
    std::cout<<"("<<forty_four_node->key<<", "<<forty_four_node<<")"<<std::endl;
    std::cout<<"("<<sixty_nine_node->key<<", "<<sixty_nine_node<<")"<<std::endl;

    three_node->child = fifty_two_node;
    three_node->right_sibling = seventeen_node;
    three_node->left_sibling = seven_node;
    three_node->degree = 3;

    seven_node->right_sibling = three_node;
    seven_node->left_sibling = seventeen_node;

    seventeen_node->child = thirty_node;
    seventeen_node->right_sibling = twenty_four_node;
    seventeen_node->left_sibling = three_node;
    seventeen_node->degree = 1;

    thirty_node->parent = seventeen_node;
    thirty_node->right_sibling = thirty_node;
    thirty_node->left_sibling = thirty_node;

    twenty_four_node->child = twenty_six_node;
    twenty_four_node->right_sibling = seven_node;
    twenty_four_node->left_sibling = seventeen_node;
    twenty_four_node->degree = 2;

    twenty_six_node->parent = twenty_four_node;
    twenty_six_node->child = thirty_five_node;
    twenty_six_node->right_sibling = forty_six_node;
    twenty_six_node->left_sibling = forty_six_node;
    twenty_six_node->degree = 1;

    forty_six_node->parent = twenty_four_node;
    forty_six_node->right_sibling = twenty_six_node;
    forty_six_node->left_sibling = twenty_six_node;

    thirty_five_node->parent = twenty_six_node;
    thirty_five_node->right_sibling = thirty_five_node;
    thirty_five_node->left_sibling = thirty_five_node;

    eighteen_node->parent = three_node;
    eighteen_node->child = thirty_nine_node;
    eighteen_node->right_sibling = fifty_two_node;
    eighteen_node->left_sibling = thirty_eight_node;
    eighteen_node->degree = 1;

    fifty_two_node->parent = three_node;
    fifty_two_node->right_sibling = thirty_eight_node;
    fifty_two_node->left_sibling = eighteen_node;

    thirty_eight_node->parent = three_node;
    thirty_eight_node->child = forty_one_node;
    thirty_eight_node->right_sibling = eighteen_node;
    thirty_eight_node->left_sibling = fifty_two_node;
    thirty_eight_node->degree = 1;

    forty_one_node->parent = thirty_eight_node;
    forty_one_node->child = forty_two_node;
    forty_one_node->right_sibling = forty_one_node;
    forty_one_node->left_sibling = forty_one_node;
    forty_one_node->degree = 1;

    forty_two_node->parent = forty_one_node;
    forty_two_node->child = forty_three_node;
    forty_two_node->left_sibling = forty_two_node;
    forty_two_node->right_sibling = forty_two_node;
    forty_two_node->degree = 1;

    forty_three_node->parent = forty_two_node;
    forty_three_node->child = forty_four_node;
    forty_three_node->left_sibling = forty_three_node;
    forty_three_node->right_sibling = forty_three_node;
    forty_three_node->degree = 1;
    
    forty_four_node->parent = forty_three_node;
    forty_four_node->left_sibling = forty_four_node;
    forty_four_node->right_sibling = forty_four_node;
    
    thirty_nine_node->parent = eighteen_node;
    thirty_nine_node->child = sixty_nine_node;
    thirty_nine_node->right_sibling = thirty_nine_node;
    thirty_nine_node->left_sibling = thirty_nine_node;
    thirty_nine_node->degree = 1;

    sixty_nine_node->parent = thirty_nine_node;
    sixty_nine_node->right_sibling = sixty_nine_node;
    sixty_nine_node->left_sibling = sixty_nine_node;

    head_root_list = seven_node;
    tail_root_list = twenty_four_node;
    min_pointer = three_node;
    root_list_size = 4;
    total_node_num = 17;
}

void Fibonacci_Heap::PrintList(FTNode* const head_ptr, const int print_width, std::queue<FTNode*> &parent_queue){
    FTNode* current_traverse_node = head_ptr;
    int start_pt = 0;

    while(((current_traverse_node != head_ptr) || (start_pt == 0)) && (head_ptr != NULL)){
        if(current_traverse_node->right_sibling == head_ptr){
            printf("(%*d, %-p, %*d)\n", print_width,  current_traverse_node->key, current_traverse_node, print_width, current_traverse_node->degree);
        }else{
            printf("(%*d, %-p, %*d)--", print_width,  current_traverse_node->key, current_traverse_node, print_width, current_traverse_node->degree);
        }

        if(start_pt == 0){
            ++start_pt;
        }
        parent_queue.push(current_traverse_node);
        current_traverse_node = current_traverse_node->right_sibling;
    }
}

void Fibonacci_Heap::Traverse(const int print_width, const bool debug){
    int depth_max = 0;
    
    if(debug){
        BuildTestExample();
    }

    depth_max = CalculateDepth(head_root_list, 0);
    std::vector<FTNode*>* node_map = new std::vector<FTNode*> [depth_max+1];
    SetNodeMap(head_root_list, 0, node_map);

    for(size_t i=0;i<node_map[0].size();++i){
        std::queue<FTNode*> parent_queue;
        int depth_grad = -1;

        std::cout<<"##################################"<<std::endl;
        std::cout<<"#########      F"<<i<<"      ###########"<<std::endl;
        std::cout<<"##################################"<<std::endl;
        printf("(%*d, %-p, %*d)\n", print_width,  node_map[0][i]->key, node_map[0][i], print_width, node_map[0][i]->degree);

        parent_queue.push(node_map[0][i]);
        while(!parent_queue.empty()){
            FTNode* current_parent = parent_queue.front();
                
            if(current_parent->child != NULL){
                if((current_parent->child->level - depth_grad) >= 2){
                    std::cout<<"-------------------------------------"<<std::endl;
                    ++depth_grad;
                }
                printf("(%*d, %-p, %*d)--> ", print_width,  current_parent->key, current_parent, print_width, current_parent->degree);
                PrintList(current_parent->child, print_width, parent_queue);
            }
            parent_queue.pop();
        }
    }
}

void Fibonacci_Heap::InsertArbitrary(const int key){
    FTNode* inserted_node = new FTNode(key);
    if(min_pointer == NULL){
        min_pointer = inserted_node;
        min_pointer->right_sibling = min_pointer;
        min_pointer->left_sibling = min_pointer;
        head_root_list = inserted_node;
        tail_root_list = inserted_node;
    }else{
        FTNode* min_left_node = min_pointer->left_sibling;
        inserted_node->left_sibling = min_left_node;
        inserted_node->right_sibling = min_pointer;
        min_left_node->right_sibling = inserted_node;
        min_pointer->left_sibling = inserted_node;

        if(min_left_node == min_pointer){
            head_root_list = inserted_node;
        }

        if(min_pointer->key > inserted_node->key){
            min_pointer = inserted_node;
        }
    }
    ++root_list_size;
    ++total_node_num;
}

void Fibonacci_Heap::InsertArbitrary(FTNode* const inserted_node){
    if(inserted_node->right_sibling != inserted_node){
        std::cout<<"Error : The inserted_node should be the single node."<<std::endl;
        return;
    }

    if(min_pointer == NULL){
        min_pointer = inserted_node;
        min_pointer->right_sibling = min_pointer;
        min_pointer->left_sibling = min_pointer;
        head_root_list = inserted_node;
        tail_root_list = inserted_node;
    }else{
        FTNode* min_left_node = min_pointer->left_sibling;
        inserted_node->left_sibling = min_left_node;
        inserted_node->right_sibling = min_pointer;
        min_left_node->right_sibling = inserted_node;
        min_pointer->left_sibling = inserted_node;

        if(min_left_node == min_pointer){
            head_root_list = inserted_node;
        }

        if(min_pointer->key > inserted_node->key){
            min_pointer = inserted_node;
        }
    }
    ++root_list_size;
    ++total_node_num;
}

void Fibonacci_Heap::AddChildToRootList(){
    FTNode* min_child = min_pointer->child;
    FTNode* current_traverse_node = min_child;
    int start_pt = 0;

    while(((current_traverse_node != min_child) || (start_pt == 0)) && (current_traverse_node != NULL)){
        FTNode* min_left_node = min_pointer->left_sibling;
        FTNode* inserted_node = current_traverse_node;
        inserted_node->left_sibling = min_left_node;
        inserted_node->right_sibling = min_pointer;
        min_left_node->right_sibling = inserted_node;
        min_pointer->left_sibling = inserted_node;

        if(start_pt == 0){
            ++start_pt;
        }
        current_traverse_node = current_traverse_node->right_sibling;
    }
}

FTNode* Fibonacci_Heap::ExtractMin(){
    if(head_root_list == NULL){
        std::cout<<"Error : The Fibonacci_Heap is already empty."<<std::endl;
        return NULL;
    }
    AddChildToRootList();
    return NULL;
}

FTNode* Fibonacci_Heap::Search(const int key){
    if(key < min_pointer->key){
        std::cout<<"Search("<<key<<") not found."<<std::endl;
        return NULL;
    }else if(key == min_pointer->key){
        return min_pointer;
    }

    FTNode* ans_node = NULL;
    FTNode* current_root_node = head_root_list;
    std::queue<FTNode*> child_root_queue;
    child_root_queue.push(current_root_node);

    while(!child_root_queue.empty()){
        FTNode* examinate_node = child_root_queue.front();
        child_root_queue.pop();

        FTNode* current_node = examinate_node;
        while(current_node != NULL){
            if(current_node->key == key){
                ans_node = current_node;
                break;
            }else if((current_node->key < key) && (current_node->child != NULL)){
                child_root_queue.push(current_node->child);
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

void Fibonacci_Heap::ExchangeSatelliteInfo(FTNode* const x, FTNode* const y){
    FTNode* tmp = new FTNode();
    tmp->key = x->key;
    x->key = y->key;
    y->key = tmp->key;
    delete tmp;
}

void Fibonacci_Heap::ExchangeNodePos(FTNode* const x, FTNode* const y){
    FTNode* tmp = new FTNode();
    tmp->parent = y->parent;
    tmp->child = y->child;
    tmp->left_sibling = y->left_sibling;
    tmp->right_sibling = y->right_sibling;
    tmp->degree = y->degree;

    //Replace x with y. x is the parent of y
    if(x->parent != NULL){
        if(x->parent->child == x){
            x->parent->child = y;
        }   
    }
    if(x->right_sibling != NULL){
        x->right_sibling->left_sibling = y;
    }
    if(x->left_sibling != NULL){
        x->left_sibling->right_sibling = y;
    }
    if(x->child == y){
        y->child = x;
    }else{
        y->child = x->child;
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
    if(tmp->child != NULL){
        FTNode* current_tmp_child = tmp->child;
        while(current_tmp_child != NULL){
            current_tmp_child->parent = x;
            current_tmp_child = current_tmp_child->right_sibling;
        }
    }
    x->child = tmp->child;
    x->right_sibling = tmp->right_sibling;
    x->left_sibling = tmp->left_sibling;
    x->degree = tmp->degree;

    FTNode* current_y_child = y->child;
    while(current_y_child != NULL){
        current_y_child->parent = y;
        current_y_child = current_y_child->right_sibling;
    }

    delete tmp;
}

bool Fibonacci_Heap::DecreaseKey(FTNode* const x, const int changed_key){
    //To-do
    return true;
}

bool Fibonacci_Heap::DecreaseKeySatellite(FTNode* const x, const int changed_key){
    //To-do
    return true;
}

bool Fibonacci_Heap::Delete(FTNode* const x){
    if(DecreaseKey(x, -INT_MAX)){
        ExtractMin();
        return true;
    }else{
        return false;
    }
}
