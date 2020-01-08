#include <iostream>
using namespace std;


// Start by creating a node for a singly-linked list.


// Node_object illegal: incomplete type is not allowed.
/* class Node_object{
    public:
        int val;
        Node_object next;
}; */

class Node{
    public:
        int val;
        Node* nxt = NULL;

        // Default constructor.
        Node(int v, Node* n = NULL){
            val = v;
            nxt = n;
        };

        Node(int v, Node n){
            val = v;
            nxt = new Node(n.val, n.nxt);
        };

        Node next(){
            return *nxt;
        };
};

int test0(){
    printf("int i = 5;\n");
    int i = 5;
    printf("int& j = i;\n");
    int& j = i;
    printf("&i = %p\n", &i);
    printf("&j = %p\n", &j);
    printf("\n");
    return 0;
}

int test1_inner(int i = 5){
    printf("i = %d\n&i = %p\n", i, &i);
    printf("\n");
    return 0;
}

int test1(){
    int i = 10;
    printf("i = %d\n&i = %p\n", i, &i);
    test1_inner(i);
    test1_inner();
}

int main(){
    Node node = Node(0, Node(1, Node(2)));
    printf("1st Node = %d; Next address = %p\n", node.val, node.nxt);
    printf("2nd Node = %d; Next address = %p\n", node.next().val, node.next().nxt);
    printf("3rd Node = %d; Next address = %p\n", node.next().next().val, node.next().next().nxt);
    // test0();
    // test1();
    
    return 0;
}
