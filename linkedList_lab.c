#include<stdio.h>
#include<stdlib.h>

void add_to_list (int data);
void traversal();
void insert_val(int data, int position);
void delete_val(int data);

struct list {
   int val;
   struct list *next;
};
typedef struct list node;

node *curr, *head=NULL, *ptr, *p, *q, *prev;

int main()
{
 int answer,value, end, position;
 do{
    printf("Choose an operation:\n");
	printf("1. Build linked list\n");
	printf("2. Show linked list\n");
	printf("3. Insert data at the specific location\n");
	printf("4. Delete specific data from linked list\n");
	printf("5. Exit\n");
	printf("-----------------------\n");
	printf("Enter your choice: ");
	scanf("%d",&answer);
	switch(answer)
	{
		case 1: printf("Enter a value to add in a linked list: ");
				scanf("%d",&value);
				add_to_list(value);
				break;
        case 2: traversal();break;
		case 3: printf("Enter a value to add in a linked list: ");
				scanf("%d",&value);
				printf("Enter a position: ");
				scanf("%d",&position);
                insert_val(value, position);
                break;
		case 4: printf("Enter a value to delete in a linked list: ");
				scanf("%d",&value);
				delete_val(value);
				break;
		case 5: end = 1;break;
	}
 }while(end!=1);
}
void add_to_list (int data)
{
   if(head==NULL)
    {
         head = (node *)malloc(sizeof(node));
		 head->val = data;
         head->next = NULL;
		 ptr = head;
    }else{
			curr = (node *)malloc(sizeof(node));
         	curr->val = data;
    		curr->next = NULL;
			ptr->next = curr;
			ptr=curr;
		}
}

void traversal()
{
  curr = head;
   while(curr) {
      printf("%d --> ", curr->val);
      curr = curr->next ;
   }
   printf("NULL\n");
}

void insert_val(int data, int position)
{
    curr = (node *)malloc(sizeof(node));
    curr->val = data;
    curr->next = NULL;
    ptr = head;
    while((ptr->next != NULL) && (ptr->val != position))
    {
        ptr = ptr->next;
    }
    curr->next = ptr->next;
    ptr->next = curr;
}

void delete_val(int data)
{
    ptr = head;
    while((ptr != NULL)&&(ptr->val != data))
    {
        prev=ptr;
        ptr=ptr->next;
    }
    curr=ptr;
    prev->next=ptr->next;
    free(curr);
}

