#include "avl.hpp"
#include <iostream>
#include <stack>

using namespace std;

avl::avl() {
    root = nullptr;
}

avl::node::node(int input) {
    val = input;
    left = nullptr;
    right = nullptr;
} 

avl::node* avl::insert(int input) {
    node* n1 = new node(input);

    /* Here, we insert a node according to the rules of insertion for a binary tree
     * If the tree is empty (i.e root = nullptr), we reassign root = n1 and assign n1's 
     * parent to be null
    */
    if (root == nullptr) {
        root = n1;
        n1->parent = nullptr;

    } else {

        node* current = root, *prev;

        while (current != nullptr) {

            if (current->val == input) {
                // Only unique values are accepted. We must reject this insert
                cout << "Can't insert duplicates" << endl;
                return nullptr;
            }
            else if (current->val < input) {
                prev = current;
                current = current->right;
            }
            else if (current->val > input) {
                prev = current;
                current = current->left;
            }
        }

        // prev now has the node which is supposed to be the parent of the new node

        if (prev->val > input) {
            prev->left = n1;
        } else {
            prev->right = n1;
        }

        n1->parent = prev;
    }

    /* Insertion done. Now, we must start from the inserted node and backtrack parents to check if any 
     * imbalance has occured.
    */

    node *current, *parent;
    current = n1;

    do {
        parent = current->parent;
        // cout << current->val << " " << current->balance_factor() << endl;
        /* Logic:
         * If the node is left heavy, and its left node is also left heavy => right rotation
         * If the node is right heavy, and its right node is also right heavy => right rotation
         * If the node is left heavy, but its left node is right heavy => Right-left rotation
         * If the node is right heavy, but its right node is left heavy => Left-right rotation
        */
        if (current->balance_factor() == -2) {
            if (current->left->balance_factor() == -1) {
                // left heavy
                right_rotate(current);
            }
            else // current->left->balance_factor() == +1
            {
                left_rotate(current->left);
                right_rotate(current);
            }
        }
        else if (current->balance_factor() == 2) {
            if (current->right->balance_factor() == 1) {
                // right heavy
                left_rotate(current);
            }
            else // current->right->balance_factor() == -1
            {
                right_rotate(current->right);
                left_rotate(current);
            }
        }

        // cout << current->val << " " << current->balance_factor() << endl;

        current = parent;
    } while(parent != nullptr);

    cout << n1->val << " inserted succesfully!" << endl;
    return n1;
    
}

int avl::node::balance_factor() {
    // returns the height of right tree - left tree;
    // here, we're ensuring we don't dereference null pointers
    if (right == nullptr && left == nullptr) {
        return 0;
    }
    else if (right == nullptr) {
        return -left->height();
    }
    else if (left == nullptr) {
        return right->height();
    }
    else {
        return right->height() - left->height();
    }
}

int avl::node::height() {
    int leftHeight, rightHeight, maxLeftRightHeight, finalHeight;

    if (left == nullptr) {
        leftHeight = -1;
    }
    else {
        leftHeight = left->height();
    }

    if (right == nullptr) {
        rightHeight = -1;
    }
    else {
        rightHeight = right->height();
    }

    // ternary operator that assigns the maximum among leftHeight and rightHeight to this variable
    maxLeftRightHeight = leftHeight > rightHeight ? leftHeight : rightHeight;

    finalHeight = 1 + maxLeftRightHeight;

    return finalHeight;
}

void avl::left_rotate(node *a) {
    /* Left rotate is called on nodes which are right imbalanced.
     * Picture a structure like this:
     *      a
     *       \
     *        b
     *         \
     *          c
     *  Now, assume leftRotate() is called on node A. Here's what has to be done:
     *  1. b must become the parent node
     *  2. a takes b's left children as its own right children
     *  3. b takes a as its left child
     */

    // first, let's initialise variables that correspond to the above nodes
    node *b;
    b = a->right;

    // 1. b must become the parent node
    node *subtree_root;
    subtree_root = a->parent;

    /* There are 3 cases:
     * 1. a is the root node, in which case a->parent == nullptr
     *  In this case, we need to set b->parent = nullptr, and set the tree's root to b
     *  (remember, inserting a node consists of telling the node's parents who their
     *  child is, and also telling child who its parent is)
     * 2. a is the right node of its parent
     * 3. a is the left node of its parent
     *  In the above two cases, we'll compare root's left and right nodes with a to confirm
     *  which case it is, and accordingly set root's left/right child to b, in addition to
     *  setting b's parent to the root
     */

    // common to all subcases
    b->parent = subtree_root;

    if (subtree_root == nullptr) {
        // subcase 1.1
        root = b;
    }

    else if (a == subtree_root->right)
    {
        // subcase 1.2
        subtree_root->right = b;
    }

    else // (a == subtree_root->left)
    {
        // subcase 1.3
        subtree_root->left = b;
    }

    // 2. a takes b's left children as its own right children

    node *b_left_child;
    b_left_child = b->left;

    a->right = b_left_child;
    // to avoid dereferencing a nullptr
    if (b_left_child != nullptr)
        b_left_child->parent = a;
    
    // 3. b takes a as its left child

    b->left = a;
    a->parent = b;

    // The left rotation is finally complete!
}

void avl::right_rotate(node *c) {


    /* Note: rotate is better documented than right_rotate
     * A left imbalanced tree looks like this:
     *     c
     *    /
     *   b
     *  /
     * a
     * We've got to do three things:
     * 1. Make b the parent node
     * 2. Transfer b's right children to become c's left children
     * 3. Make c b's right child
    */

    // declaring variables to easily refer to the above nodes
    node *subtree_root, *b;
    subtree_root = c->parent;
    b = c->left;

    // Doing step 1

    // Telling the child its parent
    b->parent = subtree_root;

    // Telling the parent its child
    if (subtree_root == nullptr) {
        // c was the root node, so b should be the root node now
        root = b;
    }

    else if (subtree_root->right == c)
    {
        subtree_root->right = b;
    }

    else // (subtree_root->left == c)
    {
        subtree_root->left = b;
    }

    // Doing step 2

    node *b_right_child;
    b_right_child = b->right;

    c->left = b_right_child;

    // to avoid dereferencing a nullptr
    if (b_right_child != nullptr)
        b_right_child->parent = c;

    // Step 3
    b->right = c;
    c->parent = b;

}

/* Notes to future self: What you got to do is
 * 1. DONE: finish right rotate
 * 2. DONE: iterate over the chain of parents all the way till you get parent = null
 *  (note: take care to ensure you're looking at the parents as identified before performing
 *  rotations, because rotating part of your tree will change the parent to a node within the subtree)
 * 3. DONE: Check if the balancing factor is a legal value [-1, 0, 1]. If not, perform the appropriate rotations
 * 4. DONE: Done! Your insert is done! All you gotta do is the traversal (easy) and deletion (possibly)
*/ 

void avl::inorder_traverse() {
    if (root != nullptr) {
        root->inorder_traverse();
    }
}

void avl::node::inorder_traverse() {
    if (left != nullptr) {
        left->inorder_traverse();
    }

    cout << val << " Height: " << height() << endl;

    if (right != nullptr) {
        right->inorder_traverse();
    }
}

int avl::height() {
    if (root == nullptr) {
        return -1;
    }
    else {
        return root->height();
    }
}