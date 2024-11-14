#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next;
};

struct node * createNode(){
	int n;
	struct node * temp = malloc(sizeof(struct node));
	printf("Enter the value of the node : ");
	scanf("%d",&n);
	temp->data = n;
	temp->next = NULL;
	return temp;
}
struct node * insert(struct node * head){
	struct node * temp=createNode();
	struct node * ptr = head;
	
	if (ptr==NULL){
		head=temp;
		return head;
	}
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = temp;
	return head;
}
void display(struct node * head){
	struct node * ptr = head;
	while(ptr!=NULL){
		printf("| %d |",ptr->data);
		if(ptr->next!=NULL)
		printf("->");
		ptr=ptr->next;
	}
	printf("\n");
}
struct node * insertBegin(struct node * head){
	struct node * temp=createNode();
	struct node * ptr = head;
	temp->next=ptr;
	head=temp;
	printf("Head initialised\n");
	return head;
}
struct node * insertMid(struct node * head){
	struct node * temp=createNode();
	struct node * ptr = head;
	int pos,i;
	printf("Enter the position of the node : ");
	scanf("%d",&pos);
	
	if (ptr==NULL){
		head=temp;
		printf("Head initialised Instead\n");
		return head;
	}
	for(i=2;i<pos;i++){
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next = temp;
	return head;
}
struct node * deleteBegin(struct node * head){
	struct node * ptr = head;
	head = head->next;
	free(ptr);
	return head;
}
struct node * deleteMid(struct node * head){
	struct node * ptr = head;
	struct node * _ptr;
	int pos,i;
	printf("Enter the position of the node : ");
	scanf("%d",&pos);
	
	for(i=2;i<pos;i++){
		ptr=ptr->next;
	}
	_ptr=ptr->next;
	ptr->next = ptr->next->next;
	free(_ptr);
	return head;
}
struct node * deleteEnd(struct node * head){
	struct node * ptr = head;
	struct node * _ptr;
	
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	_ptr=ptr->next;
	ptr->next=NULL;
	free(_ptr);
	return head;
}

struct node * head = NULL;

int main(){
	int choice,inchoice;
	while(choice!=5){
		printf("AVAILABLE OPTIONS \n1) Link List\n) ");
		printf("\nINPUT : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				while(1){
					printf("AVAILABLE OPTIONS \n1)Create Node\n2)Display\n3)Insert at beginning\n4)Insert in middle\n5)Insert at the end\n6)Delete at beginning\n7)Delete in middle8)Delete at the end\n9)Back\n ");
					printf("\nINPUT : ");
					scanf("%d",&inchoice);
					if(inchoice==1){
						head=insert(head);
						display(head);
					}
					else if(inchoice==2){
						display(head);
					}
					else if(inchoice==3){
						head=insertBegin(head);
						display(head);
					}
					else if(inchoice==4){
						head=insertMid(head);
						display(head);
					}
					else if(inchoice==5){
						head=insert(head);
						display(head);
					}
					else if(inchoice==6){
						head=deleteBegin(head);
						display(head);
					}
					else if(inchoice==7){
						head=deleteMid(head);
						display(head);
					}
					else if(inchoice==8){
						head=deleteEnd(head);
						display(head);
					}
					else if(inchoice==9){
						break;
					}
			}
			break;
			case 2:
				
				break;
			default:
				printf("INVALID INPUT\n\n");
		}
	}
	return 0;
}
