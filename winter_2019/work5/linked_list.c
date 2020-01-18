//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int info;
	struct node* next;
} Node;

Node* create(int x); // create one node with pointer to NULL
int add(Node** h, Node* p, int x); // add node after 'p'
int make_sorted(Node** h); // add's nodes in increasing order
void free_llist(Node* p); // free all list elements
void print(Node* p); // print's all linked list to terminal


void main() {
	int num, flag = 1, count = 0;
	Node* p = NULL;

	count = make_sorted(&p);
	printf("List has %d nodes\n", count);
	
	printf("List values are: ");
	print(p);

	free_llist(p);

}

int make_sorted(Node** p){
	int f, num, count = 0, flag = 1;
	Node* p2 = NULL;

	while (flag) {
		printf("Please enter a number\n");
		scanf("%d", &num);
		f = 1;

		// stop input if num == -1
		if (num == -1) { 
			flag = 0;
		}
		else 
        {
			// if list not created yet
			if (!*p) { 
				*p = create(num);
				count++;
			}
			else 
            {
				// loop though all linked list
				for (p2 = *p; p2 && f; p2 = p2->next) 
                {	
					// case if first element is smaller then num
					if(num > p2->info){ 
						add(p, NULL, num);
						count++;
						f = 0;
					}
					else
					{
						// if it isn't last element
						if(p2->next) 
						{
							// if num is smaller/equal then current and bigger then next
							if(num <= p2->info && num > p2->next->info) { 
								add(p, p2, num);
								count++;
								f = 0;
							}
						}
						// if there is only one node and it's bigger/equal then num 
						//or it's last element and it's bigger/equal then num 
						else 
						{
							if(num <= p2->info){ 
								add(p, p2, num);
								count++;
								f = 0;
							}
						}
					}
				}
			}
		}
	}
	return count;	
}

void print(Node* p) {
	Node* n;
	for (n = p; n; n = n->next)
		printf("%d ", n->info);
	printf("\n");
}

void free_llist(Node* p){
	Node* p2;
	int c = 0;
	for(; p; p = p2){
		p2 = p->next;
		free(p);
		c++;
	}
	printf("Free %d nodes\n", c);
}

int add(Node** h, Node* p, int x) {
	Node* t = create(x);
	if (t) {
		if (!p) {
			t->next = *h;
			*h = t;
		}
		else {
			t->next = p->next;
			p->next = t;
		}
		return 1;
	}
	else {
		return 0;
	}
}

Node* create(int x) {
	Node* p = NULL;
	p = (Node*)malloc(sizeof(Node));
	if (p) {
		p->info = x;
		p->next = NULL;
	}
	return p;
}