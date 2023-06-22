#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next=NULL;
	}
};
Node* Createlinklist(){
	int data;
	cin>>data;
	Node* head=NULL;
	Node* temp=NULL;
	while(data!=-1){
		Node* newn=new Node(data);
		if(head==NULL) {
			head=newn;
			temp=head;
		}else{
			temp->next=newn;
			temp=newn;
		}
		cin>>data;
	}
	return head; 
}
void prints(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node* reverses(Node* head){
	Node* curr=head;
	Node* temp;
	Node* pre=NULL;
	while(curr!=NULL){
		temp=curr->next;
		curr->next=pre;
		pre=curr;
		curr=temp;
	}
	head=pre;
	return head;
}
//Recursive
Node* revre(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* smlhead=revre(head->next);
	Node* temp=smlhead;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return smlhead;
}
//recursion in O(n)
Node* rev(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
}
int main(){
	Node* head=Createlinklist();
	cout<<"linkedList->";
	cout<<endl;
	prints(head);
	cout<<endl;
	head=reverses(head);
	cout<<"REverse through itreation"<<endl;
	prints(head);
	cout<<endl;
	head=revre(head);
	cout<<"Reverse Through Recursion On2"<<endl;
	prints(head);
	cout<<endl;
	head=rev(head);
	cout<<"Reverse Through Recursion O(n)"<<endl;
	prints(head);
return 0;
}

