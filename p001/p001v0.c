#include <stdio.h>

int two_elems_to_k(int* l, int l_len, int k){
    int ret = 0;
    for(int i = 0; i < l_len - 1; i++)
        for(int j = i+1; j < l_len; j++)
            if(l[i] + l[j] == k){
                ret = 1;
            }
    return ret;
}

/*
int main(){
    int x[] = {10, 15, 3, 7};
    int xlen = 4;
    int k = 17;
    int ret = 0;
    for(int i = 0; i < xlen - 1; i++)
        for(int j = i+1; j < xlen; j++)
            if(x[i] + x[j] == k){
                printf("True\n");
                ret = 1;
            }       
    if(ret == 0)
        printf("False\n");
    return 0;
}
*/

int main(){
    int x[] = {10, 15, 3, 7};
    int xlen = 4;
    int k = 17;
    int r;
    r = two_elems_to_k(x, xlen, k);
    if(r == 0)
        printf("False\n");
    else
        printf("True\n");
    
}