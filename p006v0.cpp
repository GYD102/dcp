#include <iostream>
#include <cstdint>
using namespace std;

//Warmup
// I've been working on this for a long time, but still haven't figured out how
// to traverse a data structure using pointers. Because returning objects is
// funky with referencing, dereferencing, returning as value,
// returning as reference, etc. etc. So instead, I'll start with a
// singly-linked list of integers.

class sll_node_v1;

class sll_node_v1{
    public:
    int value;
    uintptr_t ptrNext_int = 0;
    //sll_node_v1 ptrNext_obj; <- this does not work, can't recursively define object
    sll_node_v1* ptrNext_ptr = 0;


    sll_node_v1* self_addr(){
        printf("the address of node w/ value %d is %p\n", value, this);
        return this;
    }

    //The below definition works for some reason though
    sll_node_v1 next_obj(){
        return *ptrNext_ptr;
    }

    sll_node_v1* next_ptr(){
        return ptrNext_ptr;
    }

    sll_node_v1& next_ref(){
        return *ptrNext_ptr;
    }

    uintptr_t next_int(){
        return ptrNext_int;
    }

    sll_node_v1(int v = 0){
        value = v;
        printf("Created new node: ");
        self_addr();
    }

    void link_obj(sll_node_v1 next){
        next.self_addr();
        ptrNext_int = (uintptr_t) &next;
        ptrNext_ptr = &next;
        printf("ptrNext_int set to %lu\n"
            "ptrNext_ptr set to %p\n\n", ptrNext_int, ptrNext_ptr);
    }

    void link_ptr(sll_node_v1* next){
        (*next).self_addr();
        ptrNext_int = (uintptr_t) next;
        ptrNext_ptr = next;
        printf("ptrNext_int set to %lu\n"
            "ptrNext_ptr set to %p\n\n", ptrNext_int, ptrNext_ptr);
    }

    void link_ref(sll_node_v1 next){
        next.self_addr();
        ptrNext_int = (uintptr_t) &next;
        ptrNext_ptr = &next;
        printf("ptrNext_int set to %lu\n"
            "ptrNext_ptr set to %p\n\n", ptrNext_int, ptrNext_ptr);
    }

    void link_int(uintptr_t next){
        (*((sll_node_v1*) next)).self_addr();
        ptrNext_int = next;
        ptrNext_ptr = (sll_node_v1*) next;
        printf("ptrNext_int set to %lu\n"
            "ptrNext_ptr set to %p\n\n", ptrNext_int, ptrNext_ptr);
    }
    
};

class sll_v1{
    public:
    uintptr_t ptrFirst_int;
    sll_node_v1 ptrFirst_obj;
    sll_node_v1* ptrFirst_ptr;

    sll_v1(int val){
        ptrFirst_obj = sll_node_v1(val);
        ptrFirst_ptr = &ptrFirst_obj;
        ptrFirst_int = (uintptr_t) ptrFirst_ptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    sll_v1(uintptr_t intptr){
        ptrFirst_int = intptr;
        ptrFirst_ptr = (sll_node_v1*) intptr;
        ptrFirst_obj = *ptrFirst_ptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    sll_v1(sll_node_v1 objptr){
        ptrFirst_ptr = &objptr;
        ptrFirst_int = (uintptr_t) &ptrFirst_ptr;
        ptrFirst_obj = objptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    sll_v1(sll_node_v1* ptrptr){
        ptrFirst_ptr = ptrptr;
        ptrFirst_obj = *ptrptr;
        ptrFirst_int = (uintptr_t) ptrptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }
};

class sll_v2{
    public:
    uintptr_t ptrFirst_int;
    sll_node_v1 ptrFirst_obj;
    sll_node_v1* ptrFirst_ptr;

    sll_v2(int val){
        ptrFirst_obj = sll_node_v1(val);
        ptrFirst_ptr = &ptrFirst_obj;
        ptrFirst_int = (uintptr_t) ptrFirst_ptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    sll_v2(uintptr_t intptr){
        ptrFirst_int = intptr;
        ptrFirst_ptr = (sll_node_v1*) intptr;
        ptrFirst_obj = *ptrFirst_ptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    // Only difference between sll_v1 and sll_v2 is the following method.
    sll_v2(sll_node_v1& objptr){
        ptrFirst_ptr = &objptr;
        ptrFirst_int = (uintptr_t) &ptrFirst_ptr;
        ptrFirst_obj = objptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }

    sll_v2(sll_node_v1* ptrptr){
        ptrFirst_ptr = ptrptr;
        ptrFirst_obj = *ptrptr;
        ptrFirst_int = (uintptr_t) ptrptr;
        printf("Created singly linked list.\n"
            "ptrFirst_obj.value = %d\n"
            "ptrFirst_ptr = %p\n"
            "ptrFirst_int = %lu\n-------------------\n",
            ptrFirst_obj.value, ptrFirst_ptr, ptrFirst_int);
    }
};

int main(){
    sll_node_v1 n0_obj, n0_ptr, n0_ref, n0_int;
    sll_node_v1* n0_obj_initptr = &n0_obj;
    sll_node_v1* n0_ptr_initptr = &n0_ptr;
    sll_node_v1* n0_ref_initptr = &n0_ref;
    sll_node_v1* n0_int_initptr = &n0_int;
    // https://stackoverflow.com/questions/10897799/temporary-objects-when-are-they-created-how-do-you-recognise-them-in-code
    // Below two lines create "error: taking address of temporary [-fpermissive]"
    // sll_node_v1* creation_space = &sll_node_v1(1);
    // printf("Creation space is at address %p\n", creation_space);
    n0_obj = sll_node_v1(1);
    n0_ptr = sll_node_v1(2);
    n0_ref = sll_node_v1(3);
    n0_int = sll_node_v1(4);

    printf("\n =================== \n");

    printf("Attempting to access initialized n0_obj variable w/ address %p\n", n0_obj_initptr);
    printf("Value at n0_obj_intptr = %d\n", (*n0_obj_initptr).value);
    printf("From the outside, &n0_obj = %p\n", &n0_obj);
    printf("------------------------\n");

    printf("Attempting to access initialized n0_ptr variable w/ address %p\n", n0_ptr_initptr);
    printf("Value at n0_ptr_intptr = %d\n", (*n0_ptr_initptr).value);
    printf("From the outside, &n0_ptr = %p\n", &n0_ptr);
    printf("------------------------\n");

    printf("Attempting to access initialized n0_ref variable w/ address %p\n", n0_ref_initptr);
    printf("Value at n0_ref_intptr = %d\n", (*n0_ref_initptr).value);
    printf("From the outside, &n0_ref = %p\n", &n0_ref);
    printf("------------------------\n");

    printf("Attempting to access initialized n0_int variable w/ address %p\n", n0_int_initptr);
    printf("Value at n0_int_intptr = %d\n", (*n0_int_initptr).value);
    printf("From the outside, &n0_int = %p\n", &n0_int);
    printf("------------------------\n");

    printf("\n =================== \n");

    // In the below code, ptrFirst_ptr is the same for every single value.
    // this is why: https://stackoverflow.com/questions/2139224/how-to-pass-objects-to-functions-in-c

    // sll_v1 sll_obj = sll_v1(n0_obj);
    // sll_v1 sll_ptr = sll_v1(n0_ptr);
    // sll_v1 sll_ref = sll_v1(n0_ref);
    // sll_v1 sll_int = sll_v1(n0_int);

    sll_v1 sll_obj = sll_v1(n0_obj);
    sll_v1 sll_ptr = sll_v1(&n0_ptr);
    sll_v2 sll_ref = sll_v2(n0_ref);
    sll_v1 sll_int = sll_v1((uintptr_t) &n0_int);


    return 0;
}

// Below was my first attempt at doing p006. After constantly hitting dead-ends, I decided to
// start with something simpler (the above code for sll) to figure out what I was doing wrong.
// Ultimately, it was my failure to fully internalize the pass-by-value nature of C/C++ and
// my misunderstanding of how objects were generated (temporary first, etc).

/* // Xor linked list node object
class xorll_node{
    public:
    uintptr_t both;
    int value;
    
    xorll_node(int v = 0, uintptr_t prev = 0){
        both = prev;
        value = v;
        printf("Created new node with \"both\" equal to %lu and \"value\" equal to %d\n", both, value);
    }

    xorll_node next(uintptr_t prev){
        return *((xorll_node*) (prev ^ both));
    }

    xorll_node prev(uintptr_t next){
        return *((xorll_node*) (next ^ both));
    }

    // have to make sure the below function is only used on the LAST node
    xorll_node link(xorll_node next){
        next.both = (uintptr_t) this;
        printf("next.both = %lu\n", next.both);
        printf("Setting both to: %lu\n", ((uintptr_t) &next) ^ both);
        both = ((uintptr_t) &next) ^ both;
        return next;
    }
};

// Xor linked list object
class xorll{
    public:
    xorll_node first;

    xorll(int val){
        first = xorll_node(val);
    }

    xorll_node& last(){
        if (first.both == 0)
            // printf("First = last; it's address is: %lu\n", (uintptr_t) &first);
            return first;
        uintptr_t addr_previous = (uintptr_t) &first, temp_addr = (uintptr_t) &first;
        xorll_node current_node = first.next(0);
        printf("Testing to see addresses of current_node = %p and first.next(0) = %p", &current_node, &first.next(0));
        // printf("finding segfault checkpoint 01\n");
        // printf("Here should be the second node\n"
        //     "addr_previous should equal current_node.both skipping while loop\n"
        //     "addr_previous = %lu; current_node.both = %lu\n", addr_previous, current_node.both);
        // printf("temp_addr = %lu\n", temp_addr);
        while (current_node.both != addr_previous){
            // printf("finding segfault checkpoint 02\n");
            addr_previous = (uintptr_t) &current_node;
            // printf("finding segfault checkpoint 03\n");
            current_node = current_node.next(temp_addr);
            // printf("finding segfault checkpoint 04\n");
            temp_addr = addr_previous;
            // printf("finding segfault checkpoint 05\n");
        }
        // printf("finding segfault checkpoint 06\n");
        return current_node;
    }

    // have to make sure the below function is only used on the LAST node
    // xorll_node link(xorll_node next){
    //     next.both = (uintptr_t) this;
    //     printf("next.both = %lu\n", next.both);
    //     printf("Setting both to: %lu\n", ((uintptr_t) &next) ^ both);
    //     both = ((uintptr_t) &next) ^ both;
    //     return next;
    // }

    void add(int val){
        xorll_node new_node = xorll_node(val);
        new_node.both = (uintptr_t) &last();
        printf("new_node.both = %lu\n", new_node.both);
        printf("old last().both = %lu\n", last().both);
        printf("xoring %lu to last().both\n", ((uintptr_t) &new_node));
        printf("this should equal %lu\n", last().both ^ ((uintptr_t) &new_node));
        last().both = last().both ^ ((uintptr_t) &new_node);
        printf("last().both = %lu\n", last().both);
    }
};

int main(){
    xorll test = xorll(10);
    printf("First value = %d\n", test.first.value);
    printf("First both address = %lu\n", test.first.both);
    printf("First node address = %lu\n", (uintptr_t) &test.first);
    printf("Last value = %d\n", test.last().value);
    printf("Last both = %lu\n", test.last().both);
    // printf("Last node address = %p\n", &test.last());
    
    test.add(20);
    printf("Last value = %d\n", test.last().value);
    printf("First both address = %lu\n", test.first.both);

    // int x = 5;
    // int* ptr_x = &x;

    // int y = 8;
    // int* ptr_y = &y;

    // printf("value %d stored at %p aka %lu\n", x, ptr_x, (uintptr_t) ptr_x);
    // printf("value %d stored at %p aka %lu\n", y, ptr_y, (uintptr_t) ptr_y);
    // printf("xor of the two addresses: %p\n", (void *) ((uintptr_t) ptr_x ^ (uintptr_t) ptr_y));
    // return 0;
} */