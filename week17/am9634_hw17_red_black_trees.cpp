// Given the attached AVL implementation, implement a red black tree.
//You do not have to implement the removal functions, only insertions will be performed.
#include <iostream>
#include <ctime>
#include <queue>
#define RED 0
#define BLACK 1

using namespace std;

template <class T>
class RB;

template <class T>
T& max(T& left, T& right){
    if (left > right)
        return left;
    else
        return right;
}
template <class T>
T max(const T& left, const T& right){
    if (left > right)
        return left;
    else
        return right;
    
}

template <class T>
class RBNode {
    RBNode<T>* parent, *left, *right;
    int height;
    T data;
    bool color;
    
public:
    friend class RB<T>;
    RBNode(const T& newdata = T(),
           RBNode<T>* newparent = nullptr,
           RBNode<T>* newleft = nullptr,
           RBNode<T>* newright = nullptr) :
    data(newdata),
    parent(newparent),
    left(newleft),
    right(newright) {
        calcHeight();
    }
    void calcHeight(){
        int leftHeight = -1;
        int rightHeight = -1;
        if (left != nullptr)
            leftHeight = left->height;
        if (right != nullptr)
            rightHeight = right->height;
        height = max(leftHeight, rightHeight) + 1;
        if (parent)
            parent->calcHeight();
    }
    void printInOrder()const{
        if (left != nullptr)
            left->printInOrder();
        cout << data <<"\t"<<height<< endl;
        if (right != nullptr)
            right->printInOrder();
    }
    void printPostOrder()const;
    int size()const {
        int leftSize = 0;
        int rightSize = 0;
        if (left != nullptr)
            leftSize = left->size();
        if (right != nullptr)
            rightSize = right->size();
        return 1 + leftSize + rightSize;
    }
    int depth() const{
        int parentDepth = -1;
        if (parent != nullptr)
            parentDepth = parent->depth();
        return 1 + parentDepth;
    }
};

template <class T>
class RB {
    RBNode<T>* root;
    int size;
    int heightDiff(RBNode<T>* point);
    void doRotation(RBNode<T>* point);
    void rotate_left(RBNode<T>*& root, RBNode<T>*& point);
    void rotate_right(RBNode<T>*& root, RBNode<T>*& point);
    void fix(RBNode<T>*& root, RBNode<T>*& point);
    RBNode<T>* first_insert(RBNode<T>* root, RBNode<T>* point);
    void recalculate(RBNode<T>* p);
public:
    RB() :size(0){ root = nullptr; }
    virtual ~RB(){ clear(); }
    RB& operator=(const RB<T>& rhs);
    bool isInTree(const T& toFind) const{ return find(toFind) != nullptr; }
    bool isEmpty()const{ return root == nullptr; }
    int getSize()const { return size; }
    
    void remove(const T& toRemove){
        RBNode<T>* item = find(toRemove);
        if (item != nullptr)
            remove(item);
    }
    
    void insert(const T&);
    void remove(RBNode<T>*);
    RBNode<T>* find(const T& toFind) const;
    void clear(){ while (!isEmpty()) remove(root); }
    void printInOrder()const{ root->printInOrder(); }
    void printPostOrder()const{ root->printPostOrder(); }
    void printLevelOrder()const;
};

template <class T>
void RB<T>::printLevelOrder() const {
    queue<RBNode<T>*> q;
    q.push(root);
    while (!q.empty()){
        RBNode<T>* front = q.front();
        cout << front->data << "\t" << front->height << endl;
        if (front->left!=nullptr)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
        q.pop();
    }
}

template <class T>
RBNode<T>* RB<T>::first_insert(RBNode<T>* root, RBNode<T>* point)
{
    if (root == nullptr)
        return point;
    if (point->data < root->data)
    {
        root->left  = first_insert(root->left, point);
        root->left->parent = root;
    }
    else
        if (point->data > root->data)
        {
            root->right = first_insert(root->right, point);
            root->right->parent = root;
        }
    return root;
}

template <class T>
void RB<T>::rotate_left(RBNode<T>*& root, RBNode<T>*& point)
{
    RBNode<T> *pr = point->right;
    point->right = pr->left;
    if (point->right != nullptr)
        point->right->parent = point;
    pr->parent = point->parent;
    if (point->parent == nullptr)
        root = pr;
    else
        if (point == point->parent->left)
            point->parent->left = pr;
        else
            point->parent->right = pr;
    pr->left = point;
    point->parent = pr;
}

template <class T>
void RB<T>::rotate_right(RBNode<T>*& root, RBNode<T>*& point)
{
    RBNode<T> *pl = point->left;
    point->left = pl->right;
    if (point->left != nullptr)
        point->left->parent = point;
    pl->parent = point->parent;
    if (point->parent == nullptr)
        root = pl;
    else
        if (point == point->parent->left)
            point->parent->left = pl;
        else
            point->parent->right = pl;
    pl->right = point;
    point->parent = pl;
}

template <class T>
void RB<T>::fix(RBNode<T>*& root, RBNode<T>*& point)
{
    RBNode<T> *parent = nullptr;
    RBNode<T> *grand_parent = nullptr;
    
    while ((point != root) && (point->color != BLACK) &&
           (point->parent->color == RED))
    {
        parent = point->parent;
        grand_parent = point->parent->parent;
        if (parent == grand_parent->left)
        {
            RBNode<T> *uncle = grand_parent->right;
            if (uncle != nullptr && uncle->color == RED)
            {
                grand_parent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                point = grand_parent;
            }
            else {
                if (point == parent->right)
                {
                    rotate_left(root, parent);
                    point = parent;
                    parent = point->parent;
                }
                rotate_right(root, grand_parent);
                swap(parent->color, grand_parent->color);
                point = parent;
            }
        }
        else {
            RBNode<T> *uncle = grand_parent->left;
            if ((uncle != nullptr) && (uncle->color == RED))
            {
                grand_parent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                point = grand_parent;
            }
            else
            {
                if (point == parent->left)
                {
                    rotate_right(root, parent);
                    point = parent;
                    parent = point->parent;
                }
                rotate_left(root, grand_parent);
                bool temp = parent->color;
                parent->color = grand_parent->color;
                grand_parent->color = temp;
                point = parent;
            }
        }
    }
    root->color = BLACK;
}

template <class T>
void RB<T>::insert(const T& data)
{
    RBNode<T>* p = new RBNode<T>(data);
    root = first_insert(root, p);
    fix(root, p);
    recalculate(root);
}

template <class T>
void RB<T>::remove(RBNode<T>* toRemove){
    if (root == nullptr)
        return;
    if (toRemove->left == nullptr && toRemove->right == nullptr){
        if (toRemove->parent == nullptr){
            root = nullptr;
        }
        else if (toRemove == toRemove->parent->left)
            toRemove->parent->left = nullptr;
        else
            toRemove->parent->right = nullptr;
        delete toRemove;
        size--;
    }
    else if (toRemove->right == nullptr){
        if (toRemove->parent == nullptr){
            root = toRemove->left;
            root->parent = nullptr;
        }
        else if (toRemove == toRemove->parent->left){
            toRemove->parent->left = toRemove->left;
            toRemove->left->parent = toRemove->parent;
        }
        else{
            toRemove->parent->right = toRemove->left;
            toRemove->left->parent = toRemove->parent;
        }
        delete toRemove;
        size--;
    }
    else if (toRemove->left == nullptr){
        if (toRemove->parent == nullptr){
            root = toRemove->right;
            root->parent = nullptr;
        }
        else if (toRemove == toRemove->parent->left){
            toRemove->parent->left = toRemove->right;
            toRemove->right->parent = toRemove->parent;
        }
        else{
            toRemove->parent->right = toRemove->right;
            toRemove->right->parent = toRemove->parent;
        }
        delete toRemove;
        size--;
    }
    else{
        RBNode<T>* temp = toRemove->right;
        while (temp->left != nullptr)
            temp = temp->left;
        toRemove->data = temp->data;
        remove(temp);
    }
    
}

template <class T>
void RB<T>::recalculate(RBNode<T>* p)
{
    if (p != nullptr) {
        if (p->left != nullptr)
            recalculate(p->left);
        p->calcHeight();
        if (p->right != nullptr)
            recalculate(p->right);
    }
}

int main(){
    
    RB<int> b;
    srand(time(nullptr));
    for (int i = 0; i < 10; i++){
        int val = rand() % 1000;
        cout << val << endl;
        b.insert(val);
    }
    cout << endl;
    b.printLevelOrder();
}

