#include<list>
#include<vector>
#include<numeric>
#include<iostream>
#include<algorithm>
#define M if
#define T int
#define Y max
#define v end
#define K list
#define D long
#define C size
#define L else 
#define x copy
#define c begin
#define X front
#define N while
#define W using
#define z vector
#define V return
#define m push_back
#define Z pop_front
#define R namespace
#define n accumulate
#define O max_element
#define b back_inserter
W R std;D D i,j,k,a;K<T>A,B;T solution(z<T>P,z<T>Q){x(P.c(),P.v(),b(A));x(Q.c(),Q.v(),b(B));i=n(A.c(),A.v(),0L);j=n(B.c(),B.v(),0L);k=(P.C()+Q.C());M((i+j)%2||Y(*O(A.c(),A.v()),*O(B.c(),B.v()))>(i+j)/2)V-1;N(i!=j){M(i>j){B.m(A.X());j+=A.X();i-=A.X();A.Z();}L{A.m(B.X());i+=B.X();j-=B.X();B.Z();}M(++a>k*10)V-1;}V a;}
