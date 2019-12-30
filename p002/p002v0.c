#include <stdio.h>


struct intArr{
    int len;
    int* s;
};

void printArr(struct intArr p){
    printf("[");
    for(int i = 0; i < p.len; i++){
        if(i + 1 < p.len) printf("%d, ", p.s[i]);
        else printf("%d]\n", p.s[i]);
    }
}

struct intArr p002(struct intArr in){
    int i;
    int p = 1;
    
    int out[in.len];

    for(i = 0; i < in.len; i++)
        p = p * in.s[i];

    for(i = 0; i < in.len; i++)
        out[i] = p / in.s[i];
    
    struct intArr fin = {in.len, out};
    return fin;
}

struct intArr p002_no_division(struct intArr in){
    int i,j;
    int p = 1;
    int out[in.len];

    for(i = 0; i < in.len; i++){
        for(j = 0; j < i; j++)
            out[j] = out[j] * in.s[i];
        out[i] = p;
        p = p * in.s[i];
    }

    struct intArr fin = {in.len, out};
    return fin;
}


int main(){
    // Unsure what the point of using the struct is when we need to
    // create and assign / insert the int array/ptr into the struct separately
    // anyways.

    int l[5] = {1,2,3,4,5};
    struct intArr i1 = {5, l};

    int m[3] = {3,2,1};
    struct intArr i2 = {3, m};

    printArr(i1);
    printArr(i2);

    printArr(p002(i1));
    printArr(p002(i2));

    printArr(p002_no_division(i1));
    printArr(p002_no_division(i2));

    return 0;
}