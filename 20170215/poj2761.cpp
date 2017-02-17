#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
template<class Data_Type>
struct Treap_node {
    Treap_node *son[2];
    Data_Type value, size;
    int rnd, repeat;
    Treap_node(){son[0] = son[1] = 0, value = 0, repeat = size = 1; rnd = rand();}
};
template<class Data_Type>
class Treap {
public:
inline void insert(Data_Type value){__insert(root, value);}
inline void del(Data_Type value){__del(root, value);}
inline Data_Type rank(Data_Type value){return __rank(root, value);}
inline Data_Type pre(Data_Type value){return __pre(root,value);}
inline Data_Type suc(Data_Type value){return __suc(root,value);}
inline Data_Type find(int rank){return __find(boot,rank);}
private:
#define sons(x) (k->son[0]->x + k->son[1]->x)
#define hturn (k->value < _value)
#define nturn (k->son[hturn]->rnd < k->rnd)
Treap_node<Data_Type> *root;
inline void pushup(Treap_node<Data_Type> * &k){
    k->size = sons(size) + k->repeat;
}

inline void turn(Treap_node<Data_Type> * &k, bool sign){
    Treap_node<Data_Type> *t = k->son[sign];
    k->son[sign] = t->son[sign ^ 1];
    t->son[sign ^ 1] = k;
    t->size = k->size;
    pushup(k);
    k = t;
}

inline void __insert(Treap_node<Data_Type> * &k, Data_Type _value){
    if (!k) {
        k = new Treap_node<Data_Type>();
        k->value = _value;
        return;
    }
    if (k->value == _value) k->repeat++;
    else {
        __insert(k->son[hturn], _value);
        if (nturn) turn(k, hturn ^ 1);
    }
}

inline void __del(Treap_node<Data_Type> * &k, Data_Type _value){
    if (k->value == _value) {
        if (k->repeat > 1) {
            k->repeat--; k->size--;
        } else //if (((k->son[0]) & (k->son[1])) == 0) delete(k),k = (k->son[0]) + (k->son[1]);
        if(k->son[0]==0||k->son[1]==0){
            //delete(k);
            Treap_node<Data_Type>*t = k;
            k=k->son[0]==0?k->son[1]:k->son[0];
            delete(t);
        }
        else
            turn(k, k->son[0]->rnd < k->son[1]->rnd); __del(k, _value);
        return;
    }
    k->size--;
    __del(k->son[k->value < _value], _value);
}
inline int __rank(Treap_node<Data_Type> * &k,Data_Type _value){
    if(!k)return 0;
    if(k->value==_value){
        return k->son[0]->size;
    }
    return (k->son[0]->size+k->repeat)*(_value>k->value)+__rank(k->son[_value<k->value],_value);
}
inline Data_Type __pre(Treap_node<Data_Type> *&k,Data_Type _value){
    if(!k) return -INF;
    int t=__pre(k->son[_value>k->value],_value);
    return t==-INF?k->value:t;
}
inline Data_Type __suc(Treap_node<Data_Type> *&k,Data_Type _value){
    if(!k) return INF;
    int t=__suc(k->son[_value>k->value],_value);
    return t==INF?k->value:t;
}
inline Data_Type __find(Treap_node<Data_Type> *&k,Data_Type _rank){
    if(k->son[0]->size<_rank&&k->son[0]->size+k->repeat>=_rank)return k->value;
    else if(k->son[0]->size>=_rank)return __find(k->son[0],_rank);
    else return __find(k->son[1],_rank-k->son[0]->size-k->repeat);
}
};
int n,t,t1;
Treap<int> T;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>t1;
        switch (t) {
            case 1:T.insert(t1);break;
            case 2:T.del(t1);break;
            case 3:cout<<T.rank(t1)<<endl;break;
            case 4:cout<<T.find(t1)<<endl;break;
            case 5:cout<<T.pre(t1)<<endl;break;
            case 6:cout<<T.suc(t1)<<endl;break;
        }
    }
}