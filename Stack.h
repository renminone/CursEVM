#pragma once
class stack
{
public:
    int st[5];
    int sp = -1;
    int data1;
    int data2;

    void set() { st[++sp] = data1; }
    void take() { data2 = st[--sp]; }
    int empty_sp() { return sp == -1 ? 1 : 0; }
    int full_sp() { return sp == 5 ? 1 : 0; }
};
