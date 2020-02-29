//michael silianov + evgeney golovachov
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 150
#define MIN 3
#define MONTH 12
#define DAY 31
#define ABC 26
#define CL 25
#define SL 55
#define B 100
#define YMIN 1939
#define YMAX 2002

typedef struct{
    int year;
    char month;
    int day;
} Birthdate;
typedef struct node {
	char fname[CL];
    char lname[CL];
    char street[SL];
    char city[CL];
    int housenum;
    Birthdate* birthdate;
	struct node* next;
} Node;

Node* makeNode(char* tmp); // make single node from text input
int charToNum(char* s); 
char numToChar(int num, char str[]);
void printNode(Node* p); // print single node
void printAll(Node* p); // print all linked list
int addNode(Node** h, Node* p, Node* t); // add node (for addNodeToList usege
int addNodeToList(Node** h, char* tmp); // add node in proper place
void setCharIndex(Node* h, Node* cp[]); // set pointers to beginning of char area
void findByFname(Node* h, Node* cp[], char search[]); // find worker by last name
void inputToString(Node** h, char cp[]); // convert input to coma separated string 
void saveToFile(Node* h); // save all linked list to file
void nodeToString(Node* p, char temp[]); // convert node data to string
void loadData(Node** h, Node* cp[]); // load all data from file to linked list
void freeAll(Node** h); // free all linked list including inner pointer(birthdate struct)

void main(){
    int allowed = 1, action = 0;
    char sh,l_name[CL]={0};
    Node* h = NULL;
    char tmp[MAX];
    Node* cp[ABC] = {0};
    loadData(&h, cp);// load date from file
    while(allowed){
        printf("Please choose option:\n");
        printf("> to reload workers list press 1\n");
        printf("> to print all list 2\n");
        printf("> to add new worker press 3\n");
        printf("> to save data to file press 4\n");
        printf("> to search by last name press 5\n");
        printf("> to quit press 6\n");
        scanf("%d", &action);
        switch(action){
            case 1:
                freeAll(&h); // free all prev loaded data
                loadData(&h, cp);// load date from file
                setCharIndex(h, cp);// set pointers to chars in LL
            break;
            case 2:
               printAll(h); // print all LL
            break;
            case 3:
                inputToString(&h,tmp); // create string from input data
                addNodeToList(&h,tmp); // create create and add new node from string to LL
        	    setCharIndex(h, cp); // set pointers to chars in LL
            break;
            case 4:
                saveToFile(h);	// save all LL to file 
            break;
            case 5:
               printf("\nPlease  enter last name ");
               scanf("%s", l_name);
               findByFname(h, cp, l_name); // search LL by lname and print found
            break;
            case 6:
                freeAll(&h); // free all prev loaded data
                printf("Buy buy )))\n");
                allowed = 0;
            break;
            default:
                printf("You choise do not match any option\n");
        }
    }
}
void saveToFile(Node* h){
    Node* p = NULL;
    FILE* fd = fopen("workers.txt", "w");
    char str[MAX];
    for(p = h; p; p = p->next){
        nodeToString(p,str); // convert node data to coma seprated string
        fputs(str, fd); // write created string to file
    }
    fclose(fd);
}
void loadData(Node** h, Node* cp[]){
    char tmp[MAX];
    FILE* fd = fopen("workers.txt", "r"); 
    if(fd){
        while(!feof(fd)){
            fgets(tmp, MAX, fd);
            addNodeToList(h, tmp); // create and add node to LL in proper place
        }
        fclose(fd);	
    }
}
void freeAll(Node** h){
    Node* p = *h;
    Node* p1;
    while(p) {
        p1 = p->next;
        free(p->birthdate); // free memory for Birthdate
        free(p); // free memory for Node
        p = p1;
    }
    *h = NULL;
}
int addNodeToList(Node** h, char* tmp){
	int num, f = 1, count = 0, flag = 1;
	Node* p = makeNode(tmp); // create node from string
    Node* p2 = NULL;
    if (!*h) { 
        *h = p;
        count++;
    }else{
        for(p2 = *h; p2 && f; p2 = p2->next){
            if( strcmp(p->lname, p2->lname) < 0 ){
                addNode(h, NULL, p); // add node to the beginning
                count++;
                f = 0;
            }else{
                if(p2->next){
                    if( strcmp(p->lname, p2->lname) > 0 &&
                        strcmp(p->lname, p2->next->lname) < 0 ){
                        addNode(h, p2, p);
                        count++;
                        f = 0;
                    }else{
                        if(strcmp(p->lname, p2->lname) < 0){
                            addNode(h, NULL, p);
                            count++;
                            f = 0;
                        }
                    }
                }else{
                    addNode(h, p2, p);
                    count++;
                    f = 0;
                }
            }
        }
    }
	return count;   
}
void findByFname(Node* h, Node* cp[], char search[]){
    Node* p1 = cp[search[0]-'A'];
    Node* p2 = p1+1;
    Node* result = NULL;
    int flag = 1, i = 0;

    for(; p1 && p1 != p2 && flag; p1 = p1->next, i++){ // loop from first occurance of lname[0] to the last one
        if( strcmp(p1->lname, search) == 0 ){
            result = p1;
            flag = 0;
        }
    } 
    if(result){
        printf("%d\n", i);
        printNode(result); // print found node data to console
    }else{
        printf("Not found\n");
    }
}
int addNode(Node** h, Node* p, Node* t){
    if (!p) {
        t->next = *h;
        *h = t;
    }else{
        t->next = p->next;
        p->next = t;
    }
}
void setCharIndex(Node* h, Node* cp[]){
    for(Node* p = h; p; p = p->next){
        if(cp[p->lname[0] - 'A'] == NULL){
            cp[p->lname[0] - 'A'] = p;
        }
    }
}
void addComa(char temp[], int* tmp_len){
    *tmp_len = strlen(temp); 
    temp[*tmp_len] = ',';
    temp[*tmp_len+1] = '\0';
}
void nodeToString(Node* p, char temp[]){
    char tmp[CL];
    int t, temp_len = 0;
    // first name input
    strcpy(temp, p->fname);
    addComa(temp, &temp_len);
    // last name input
    strcat(temp, p->lname);
    addComa(temp, &temp_len);
    // day input
    numToChar(p->birthdate->day, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // month input
    numToChar(p->birthdate->month, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // year input
    numToChar(p->birthdate->year, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // street name input
    strcat(temp, p->street);
    addComa(temp, &temp_len);
    // house input
    numToChar(p->housenum, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // city name input  
    strcat(temp, p->city);
    addComa(temp, &temp_len);

    temp[temp_len+1] = '\n';
    temp[temp_len+2] = '\0';
}
void inputToString(Node** h, char temp[]){
    char tmp[CL];
    int t, temp_len = 0;
    // first name input
    do{
        printf("Enter first name (3-25)");
        scanf("%s", tmp);
    }while(strlen(tmp) > CL || strlen(tmp) < MIN);
    strcpy(temp, tmp);
    addComa(temp, &temp_len);
    // last name input
    do{
        printf("Enter last name (3-25)");
        scanf("%s", tmp);
    }while(strlen(tmp) > CL || strlen(tmp) < MIN);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // day input
    do{
        printf("Enter your birthdate day of the month (1-31)");
        scanf("%d", &t);
    }while(t < 1 || t > DAY);
    numToChar(t, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // month input
    do{
        printf("Enter number of the month (1-12)");
        scanf("%d", &t);
    }while(t < 1 || t > MONTH);
    numToChar(t, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // year input
    do{
        printf("Enter enter year (%d-%d)", YMIN, YMAX);
        scanf("%d", &t);
    }while(t < YMIN || t > YMAX);
    numToChar(t, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // street name input
    do{
        printf("Enter street name (3-25)");
        scanf("%s", tmp);
    }while(strlen(tmp) > CL || strlen(tmp) < MIN);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // house input
    do{
        printf("Enter house (1-9999)");
        scanf("%d", &t);
    }while(t < 1|| t > 9999);
    numToChar(t, tmp);
    strcat(temp, tmp);
    addComa(temp, &temp_len);
    // city name input
    do{
        printf("Enter city name (3-25)");
        scanf("%s", tmp);
    }while(strlen(tmp) > CL || strlen(tmp) < MIN);    
    strcat(temp, tmp);
    addComa(temp, &temp_len);
}
Node* makeNode(char* tmp){
    int i = 0,j = 0;
    char t[MAX]={0};
    Node* p = NULL;
	p = (Node*)malloc(sizeof(Node));
    p->birthdate = (Birthdate*)malloc(sizeof(Birthdate)); 
    p->next = NULL;
    
    while(*tmp){
        if(*tmp != ','){
            t[i] = *tmp;
            i++;
        }else{
            t[i] = '\0';
            switch(j){
                case 0:
                    strcpy(p->fname, t);
                break;
                case 1:
                    strcpy(p->lname, t);
                break;
                case 2:
                    p->birthdate->day = charToNum(t);
                break;
                case 3:
                    p->birthdate->month = charToNum(t);
                break;
                case 4:
                    p->birthdate->year = charToNum(t);
                break;
                case 5:
                    strcpy(p->street, t);
                break;
                case 6:
                    p->housenum = charToNum(t);
                break;
                case 7:
                    strcpy(p->city, t);
            }
            i = 0;
            j++;
        }
        tmp++;
    }
    return p;
}
void printAll(Node* h){
    Node* t = h;
    printf("-------------------------------------");
    printf("-------------------------------------\n");
    for(; t->next ; t = t->next){
        printNode(t);   
        if( t->next && t->lname[0] != t->next->lname[0] ){
            printf("-------------------------------------");
            printf("-------------------------------------\n");
        }
    }
    printf("-------------------------------------");
    printf("-------------------------------------\n");
}
void printNode(Node* p){
    printf("%-15s",  p->lname);
    printf("%-15s",  p->fname);
    printf("%-2d/",  p->birthdate->day);
    printf("%-1d/",  p->birthdate->month);
    printf("%-7d",   p->birthdate->year);
    printf("%-15s",  p->street);
    printf("%-5d",   p->housenum);
    printf("%-15s\n",p->city);
}
int charToNum(char* s){
    int i = 0,num = 0;
    while (*(s+i)) {
        num = (num * 10) + (*(s+i) - '0');
        i++;
    }
    return num;
}
void reverse(char str[]){
    int i = 0, j = strlen(str)-1;
    char s;
    while(i < j){
        s = *(str+i);
        *(str+i) = *(str+j);
        *(str+j) = s;
        i++; j--;
    }
}
char numToChar(int num, char str[]){
    int i = 0;
    while(num){
        str[i] = num%10 + '0';
        num /= 10; i++;
    }
    str[i] = '\0';
    reverse(str);
}