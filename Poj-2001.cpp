#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node
{
    int endmark;
    node *next[27];
    node()
    {
        endmark=0;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
}*root;
void insert (string S,int Len)
{
    node *curr=root;int id;
    for(int i=0;i<Len;i++)
    {
        id=S[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
 curr->endmark+=1;
    }

}
int search(string S,int Len)
{
    node *curr=root;int id;
    for(int i=0;i<Len;i++)
    {
        id=S[i]-'a';
        if(curr->next[id]==NULL)
           return false;
        curr=curr->next[id];
        if(curr->endmark==1) {
//                cout<<curr->endmark<<endl;
            return i+1;}
    }
    return Len;
}
int main()
{
    root=new node();
    vector<string>A;
    string s;
    while(cin>>s)
    {
        A.push_back(s);
        insert(s,s.size());
    }
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        int m=search(A[i],A[i].size());
        string ss;
        ss.append(A[i].begin(),A[i].begin()+m);
        cout<<A[i]<<" "<<ss<<endl;
    }
}
