#include<iostream>
using namespace std;

/*  Program to create a queue from two stacks   */

//1711140

class node{                 //this is to create the node
	public:
	float data; 
	node* next;
};
class stackll               //this is the stack 1
{   
	public:
	node* bottom, *top; 
	stackll(){
		bottom = NULL;
		top = NULL;
	}
	void push(float data);
	void pop();
	void show();
	void mkqu(node* bottom);   // create stack 2 from stack 1 where the top element becomes the bottom most element
	void dlt();
};
class queue{
	stackll stack1, stack2;
	public:
	void push();
	void pop();
	void show();
};

//1711140


int main(){                       //Main function to push, show, pop, show 
	queue one;
	cout<<"This is to implement queue using two stack"<<endl;
	one.push();
	one.show();
	one.pop();
	one.show();
	return 0; 
}

//1711140
 
void stackll::push(float data)     //function to push the data into the stack
{    
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (bottom ==NULL){
		bottom =temp ;
		top =temp;
	}	
	else {
		temp->next=bottom;
		bottom =temp;
	}
}

//1711140

void stackll::pop(){         //function to pop the data from the stack
	if (bottom==NULL){
		cout<<"This stack is empty you can't pop any more"<<endl;
	}
	else if(bottom==top){
		node* temp =bottom;
		delete temp;
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		bottom=bottom->next;
		delete temp;
	}
}

//1711140 

void stackll::show(){                        //for displaying the nodes
	node* temp =bottom;
	if(bottom==NULL){
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=top){
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
		cout<<temp->data<<endl;
	}
}

//1711140

void stackll::mkqu(node* bottom){ 
		node* temp =bottom;
		if(bottom!=NULL){
			while(temp->next!=NULL){
				push(temp->data);
				temp=temp->next;
			}
			push(temp->data);
		}
}	
void stackll::dlt(){                           //to delete the elements from the stack
	while(bottom!=NULL){
		pop();
	}	
}

//1711140

void queue::push(){                            //asks user the no. of data to be pushed and makes the stack2 from it 
	cout<<"Number of data"<<endl;
	int num,data;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<":";
		cin>>data;
		stack1.push(data);
	}
	stack2.dlt();
	stack2.mkqu(stack1.bottom);
}

//1711140

void queue::pop(){                                       //asks the user the number of data to be deleted
	cout<<"Number of data you want to delete:"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		stack2.pop();
	}
	stack1.dlt();
	stack1.mkqu(stack2.bottom);
}	
void queue::show(){
	stack1.show();
}
