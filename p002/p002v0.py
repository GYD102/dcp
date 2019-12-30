#!/usr/bin/env python3

def p002(l):
    pi = 1
    for m in l:
        pi *= m
    return [pi / i for i in l]

def p002_without_division(l):
    p = 1
    out = []
    for m in l:
        for i in range(len(out)):
            out[i] *= m
        # out = [m * x for x in out]
        out.append(p)
        p *= m
    return out

if __name__ == "__main__":
    print(p002([1,2,3,4,5]))
    print(p002([3,2,1]))
    print(p002_without_division([1,2,3,4,5]))
    print(p002_without_division([3,2,1]))