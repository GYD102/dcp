#include <iostream>
using namespace std;

class node{
    public:
    int value;
    uintptr_t both = 0;

    node(int v){
        value = v;
    }
    
    // link(): assumes this node is at the end of the xorll
        // node link(node& next){ // v1
        // node* link(node& next){ // v2
    node& link(node& next){ // v3
        next.both = next.both ^ (uintptr_t) this;
        both = both ^ (uintptr_t) &next;
        // return next; // v1
        // return &next; // v2
        return next; // v3

    }
/* Comments about link():
    v1 - doesns't work well. Returns a temporary object. Can't even take it's address.
    v2 - correctly returns a pointer to the original. Again, you can't take it's address,
        but at least you can print and store it somewhere useful.
    v3 - sucessfully returns object next. Can use it at will. Take it's address, and everything
            
    Overall. v1 seems pretty useless as a return value. Why do you want to make a copy of the node
    you just linked? v2 and v3 accomplish very similar things. Must be careful with v3 though.
    I can only really use v3 here because next wasn't created by (and therefore won't be deleted
    after) the function run. */
    
};

class xorll{
    public:
    node* first;
};

int test_link(){
    node a = node(1);
    node b = node(2);
    printf("Original address of a: %p\n"
        "Original value of a: %d\n"
        "Original both of a: %lu\n", &a, a.value, a.both);
    printf("Original address of b: %p\n"
        "Original value of b: %d\n"
        "Original both of b: %lu\n", &b, b.value, b.both);
    // a.link(b); // v1
    // printf("This is the returned address: %p\n", a.link(b)); // v2
    printf("This is the returned address: %p\n", &a.link(b)); // v3
    printf("New address of a: %p\n"
        "New value of a: %d\n"
        "New both of a: %p\n", &a, a.value, (void *) a.both);
    printf("New address of b: %p\n"
        "New value of b: %d\n"
        "New both of b: %p\n", &b, b.value, (void *) b.both);
}

int main(){
    // test_link();
    return 0;
}