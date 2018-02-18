#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <iomanip>
#include <cmath>
#include <Fibonacci_Heap.h>

Fibonacci_Heap::~Fibonacci_Heap(){
    std::cout<<"It is destructor."<<std::endl;
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
            printf("(%-*d, %-p, %-*d, %-*s)\n", print_width,  current_traverse_node->key, current_traverse_node, print_width, current_traverse_node->degree, print_width, current_traverse_node->mark ? "True":"False");
        }else{
            printf("(%-*d, %-p, %-*d, %-*s)--", print_width,  current_traverse_node->key, current_traverse_node, print_width, current_traverse_node->degree, print_width, current_traverse_node->mark ? "True":"False");
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
        printf("(%-*d, %-p, %-*d, %-*s)\n", print_width,  node_map[0][i]->key, node_map[0][i], print_width, node_map[0][i]->degree, print_width, node_map[0][i]->mark ? "True":"False");

        parent_queue.push(node_map[0][i]);
        while(!parent_queue.empty()){
            FTNode* current_parent = parent_queue.front();
                
            if(current_parent->child != NULL){
                if((current_parent->child->level - depth_grad) >= 2){
                    std::cout<<"-------------------------------------"<<std::endl;
                    ++depth_grad;
                }
                printf("(%-*d, %-p, %-*d, %-*s)--> ", print_width,  current_parent->key, current_parent, print_width, current_parent->degree, print_width, current_parent->mark ? "True":"False");
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
        FTNode* next_node = current_traverse_node->right_sibling;
        FTNode* min_left_node = min_pointer->left_sibling;
        FTNode* inserted_node = current_traverse_node;
        inserted_node->left_sibling = min_left_node;
        inserted_node->right_sibling = min_pointer;
        min_left_node->right_sibling = inserted_node;
        min_pointer->left_sibling = inserted_node;

        if(start_pt == 0){
            ++start_pt;
        }
        current_traverse_node = next_node;
    }
    min_pointer->child = NULL;
}

void Fibonacci_Heap::HeapLink(FTNode* &y, FTNode* &x){
    //Remove y from the root list
    y->right_sibling->left_sibling = y->left_sibling;
    y->left_sibling->right_sibling = y->right_sibling;
    //Make y a child of x
    if(x->child == NULL){
        x->child = y;
        y->parent = x;
        y->right_sibling = y;
        y->left_sibling = y;
        y->mark = false;
        x->degree += 1;
    }else{
        FTNode* x_child = x->child;
        x_child->left_sibling->right_sibling = y;
        y->left_sibling = x_child->left_sibling;
        x_child->left_sibling = y;
        y->right_sibling = x_child;
        y->mark = false;
        y->parent = x;
        x->degree += 1;
    }

}

void Fibonacci_Heap::Consolidate(){
    int size_of_arr = (log(total_node_num)/log(2)) + 1;
    FTNode** adjust_arr = new FTNode* [size_of_arr];
    FTNode* current_traverse_node = min_pointer;
    int start_pt = 0;
    
    //Initialization of adjust_arr
    for(int i=0;i<size_of_arr;++i){
        adjust_arr[i] = NULL;
    }

    //Consolidate each element of the root list
    while(((current_traverse_node != min_pointer) || (start_pt == 0)) && (current_traverse_node != NULL)){
        FTNode* x_node = current_traverse_node;
        int degree = x_node->degree;
        
        while(adjust_arr[degree] != NULL){
            FTNode* y_node = adjust_arr[degree];

            if(x_node->key > y_node->key){
                ExchangeNode(x_node, y_node);
            }
            if(y_node == min_pointer){
                min_pointer = y_node->right_sibling;
            }
            HeapLink(y_node, x_node);
            adjust_arr[degree] = NULL;
            ++degree;
        }
        adjust_arr[degree] = x_node;
        
        if(start_pt == 0){
            ++start_pt;
        }
        current_traverse_node = x_node->right_sibling;
    }

    //Update min_pointer, head_root_list, and tail_root_list
    head_root_list = NULL;
    tail_root_list = NULL;
    root_list_size = 0;
    for(int i=0;i<size_of_arr;++i){
        if(adjust_arr[i] != NULL){
            ++root_list_size;
            if(adjust_arr[i]->key < min_pointer->key){
                min_pointer = adjust_arr[i];
            }

            if(head_root_list == NULL){
                head_root_list = adjust_arr[i];
                tail_root_list = head_root_list->left_sibling;
            }
        }
    }
}

FTNode* Fibonacci_Heap::ExtractMin(){
    if(head_root_list == NULL){
        std::cout<<"Error : The Fibonacci_Heap is already empty."<<std::endl;
        return NULL;
    }

    FTNode* ret_ptr = min_pointer;
    //Step1. Add child of min_pointer to the root list
    AddChildToRootList();

    //Step2. Remove min_pointer from the root list
    if(min_pointer->right_sibling == min_pointer){
        min_pointer = NULL;
        head_root_list = NULL;
        tail_root_list = NULL;
        total_node_num = 0;
        root_list_size = 0;
        ret_ptr->child = NULL;
    }else{
    //Step3. If there are two(or more) elements in the root list -> Consolidate
        min_pointer->left_sibling->right_sibling = min_pointer->right_sibling;
        min_pointer->right_sibling->left_sibling = min_pointer->left_sibling;
        min_pointer = min_pointer->right_sibling;
        --total_node_num;
        Consolidate();

        ret_ptr->right_sibling = ret_ptr;
        ret_ptr->left_sibling = ret_ptr;
        ret_ptr->child = NULL; 
    }
    return ret_ptr;
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

void Fibonacci_Heap::CascadeCut(FTNode* const y){
    FTNode* z = y->parent;
    if(z != NULL){
        if(y->mark == false){
            y->mark = true;
        }else{
            Cut(y);
            CascadeCut(z);
        }
    }    
}

void Fibonacci_Heap::Cut(FTNode* const x){
    //Remove x from x.parent
    if(x == x->parent->child){
        if(x->parent->degree <= 1){
            x->parent->child = NULL;
        }else{
            x->parent->child = x->right_sibling;
        }
    }
    x->left_sibling->right_sibling = x->right_sibling;
    x->right_sibling->left_sibling = x->left_sibling;
    x->parent->degree -= 1;

    //update head_root_list
    if((min_pointer->right_sibling == min_pointer) || (min_pointer == head_root_list)){
        head_root_list = x;
    }

    //Add x to the root list
    x->left_sibling = min_pointer->left_sibling;
    x->right_sibling = min_pointer;
    x->parent = NULL;
    x->mark = false;

    min_pointer->left_sibling->right_sibling = x;
    min_pointer->left_sibling = x;
    ++root_list_size;
}

bool Fibonacci_Heap::DecreaseKey(FTNode* const x, const int changed_key){
    if(min_pointer == NULL){
        std::cout<<"Error : There is no node in the Fibonacci_Heap."<<x<<std::endl;
        return false;
    }

    if(x == NULL){
        std::cout<<"Error : The input FTNode x is "<<x<<std::endl;
        return false;
    }

    if(changed_key > x->key){
        std::cout<<"Error : New key is greater than current key at the node with address "<<x<<std::endl;
        return false;
    }

    x->key = changed_key;
    FTNode* y = x->parent;

    if((y != NULL) && (x->key < y->key)){
        Cut(x);
        CascadeCut(y);
    }

    if(x->key < min_pointer->key){
        min_pointer = x;
    }
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
