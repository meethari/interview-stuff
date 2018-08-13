class avl {

private:
    class node {
    
    private:


    node *root;

    public:
        // let's worry about the problem of caching heights later on, if it makes the program too slow 
        int val;
        node *left, *right, *parent;

        node(int input);

        int height();
        int balance_factor();
        void inorder_traverse();

    };
    node *root;

public:
    avl();
    void right_rotate(node* a);
    void left_rotate(node* a);
    node* insert(int input);
    void inorder_traverse();
    int height();
};

/*
 * Functions to implement:
 * Node:
 *  search(): finds the given value and returns the corresponding node
 *  insert(): insert node, return node
 *  height(): obvious
 *  traverse():
 * AVL:
 *  traverse(): void, just traverse in order and print
*/