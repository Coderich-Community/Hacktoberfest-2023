#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node* xt;
    node* pr;
    node(int val){
        info = val;
        xt = NULL;
        pr = NULL;
    }
};

void inhead(node* &head, int val){
    node* n=new node(val);
    n->xt=head;
    if (head!=NULL)
        head->pr=n;
    head=n;
    
}

void intail(node* &head, int val){
    if(head==NULL){
        inhead(head, val);
        return;
    }
    node* n=new node(val);
    node* temp=head;

    while(temp->xt!=NULL)
        temp=temp->xt;

    temp->xt=n;
    n->pr=temp;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->xt;
    }
    cout<<endl;
}

void delhead(node* &head){
    node* todel=head;
    head=head->xt;
    head->pr=NULL;

    delete todel;
}

void del(node* &head,int pos){
    if (pos==1)
        delhead(head);

    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos){
        temp=temp->xt;
        count++;
        }
    temp->pr->xt=temp->xt;
    
    if (temp->xt!=NULL)
        temp->xt->pr=temp->pr;
    delete temp;
}

int main(){
    node* head=NULL;
    display(head);
    intail(head,1);
    display(head);
    intail(head,2);
    intail(head,3);
    intail(head,4);
    display(head);
    inhead(head,0);
    delhead(head);
    display(head);
    del(head,10);
    del(head,2);
    display(head);
    delhead(head);
    display(head);
    return 0;
}
