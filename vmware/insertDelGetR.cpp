#include <bits/stdc++.h>
using namespace std;


class RandomizedSet {
    vector<int>v;
    unordered_map<int,int>m;//val and idx
public:
    RandomizedSet() {
        //empty cons
    }
    //set can't have dupli eles
    bool insert(int x) {
        if(m.find(x)!=m.end())return false;//ele already present in set
        v.push_back(x);//insert
        m[x]=v.size()-1;//insert in map with pos
        return true;
    }
    
    bool remove(int x) {
        if(m.find(x)==m.end())return false;//ele not present in set
        auto i = m.find(x);//accessing ele in map, (i->first is key and i->sec is idx)
        v[i->second]=v.back();//replacing with last ele in vector
        v.pop_back();//removing last ele
        m[v[i->second]]=i->second;//storing in map with curr pos, last ele
        m.erase(x);//deleting  record in map for x
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
