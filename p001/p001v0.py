#!/usr/bin/env python3

def two_sum_to_k(l, k):
    for i in range(len(l)-1):
        s = k - l[i]
        if s in l[i+1:]:
            return True
    return False

if __name__ == "__main__":
    print(two_sum_to_k([10, 15, 3, 7], 17))






