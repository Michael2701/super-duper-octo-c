#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define N 2
#define D 3
#define MAX_NUM 300
#define MIN_NUM 100
#define MAX_YEAR 2019
#define MIN_YEAR 1917
#define TMP 25


typedef struct{
    unsigned long int number;
    int code;
    int year;
    double dist;
    char* color;
    int exidents;
    int* exid_year;
} car;

typedef struct{
    int code;
    char name[20];
    double price;
} degem;

void insert_cars(car c[], int size);
    void print_car(car* Car);
    unsigned long int get_number();
    int get_code();
    int get_year();
    double get_dist();
    void get_color(char** color);
    int get_exidentes();
    void get_exid_years(int* exid_years, int size);

void find_by_color(car cars[], int csize, degem Dgamim[], int dsize);
    degem* find_degem_by_code(degem Dgamim[], int size, int code);

double get_degem_price(car cars[], int csize, degem Dgamim[], int dsize);
    int calculate_price(int price, double dist, int exidents);

void main(){
    int i;
    car Cars[N] = {0};
    degem Dgamim[D] = {
        100, "Ford", 15099,
        101, "Reno", 11999,
        102, "Audi", 17049
    };

    insert_cars(Cars, N);
    find_by_color(Cars, N, Dgamim, D);
    get_degem_price(Cars, N, Dgamim, D);
}

double get_degem_price(car cars[], int csize, degem Dgamim[], int dsize){
    int i,degem_code,flag,calculate_car_price = 1;
    double price;
    degem* pdegem;
    
    printf("Let me calculate your car price\n");

    while(calculate_car_price){
        flag = 1;
        printf("Enter code degem: ");
        scanf("%d", &degem_code);
        printf("\n");

        for(i = 0; i < csize; i++){
            int code;
            if(cars[i].code == degem_code){
                flag = 0;
                printf("=>");
                pdegem = find_degem_by_code(Dgamim, dsize, cars[i].code);
                price = calculate_price(pdegem->price, cars[i].dist, cars[i].exidents);    

                printf("Price: %.2f\n", price);        
            }
        }
        if(flag) printf("Sorry we don't have degem %d\n",degem_code);
        printf("\n Press 1(one) to continue.");
        printf("\n To stop press 0(zero).\n");
        scanf("%d", &calculate_car_price);
        if(!calculate_car_price) printf("Buy...\n");
    }
}

int calculate_price(int price, double dist, int exidents){
    float index = 1;

    if(dist > 100000){
        index -= 0.1;
    }else{
        if(dist < 20000){
            index += 0,05; 
        }
    }

    if(exidents){
        index -= (0.01 * exidents);
    }

    return price*index;
};


void find_by_color(car cars[], int csize, degem Dgamim[], int dsize){
    int i,flag,find_my_car=1,rsize = 1;
    char tmp[TMP] = {0};
    degem* pdegem;
    
    printf("\nLet me find your car\n");

    while(find_my_car){
        flag = 1;
        printf("\nEnter car color: ");
        scanf("%s", tmp);
        printf("\n");

        for(i = 0; i < csize; i++){
            int code;
            if(!strcmp(cars[i].color, tmp)){
                flag = 0;
                printf("=>");
                pdegem = find_degem_by_code(Dgamim, dsize, cars[i].code);
                printf("car code: %i\n", pdegem->code);
                printf("car degem: %s\n", pdegem->name);
                printf("car year: %d \n",cars[i].year);
                printf("============================\n");
            }
        }
        if(flag) printf("Sorry we don't have %s cars\n",tmp);
        printf("\n Press 1(one) to continue.");
        printf("\n To stop press '0'(zero).\n");
        scanf("%d", &find_my_car);
        if(!find_my_car) printf("Buy...\n");
    }


};

degem* find_degem_by_code(degem Dgamim[], int size, int code){
    int i;
    degem* dg = {0};
    for(i = 0; i < size; i++){
        if(Dgamim[i].code == code){
            dg = &Dgamim[i];
        }
    }
    return dg;
}


void insert_cars(car cars[], int size){
    int i;

    for(i = 0; i < N; i++){
        cars[i].number     = get_number(); 
        cars[i].code       = get_code();
        cars[i].year       = get_year();
        cars[i].dist       = get_dist();
        cars[i].exidents   = get_exidentes();
    
        cars[i].exid_year  = (int*)malloc(cars[i].exidents * sizeof(int));
        get_exid_years(cars[i].exid_year, cars[i].exidents);
    
        get_color(&cars[i].color);
        
        print_car(&cars[i]);
    }
};

void print_car(car* Car){
    int j;
    printf("number: %lu\ncode: %d\nyear: %.2d\ndistance: %f\ncolor: %s\nexidents num:%d \n", 
        Car->number, 
        Car->code, 
        Car->year,
        Car->dist,
        Car->color,
        Car->exidents
    );
    printf("Exidents years: ");
    for(j = 0; j < Car->exidents; j++){
        printf(" %d", Car->exid_year[j]);
    }
    printf("\n");
}

unsigned long get_number(){
    unsigned long int number;
    do{
        printf("Enter car number:\n");
    }
    while( !scanf("%lu", &number) );

    return number;
}

int get_code(){
    int number;
    do{
        printf("Enter degem code(100-200):\n");
    }
    while( !scanf("%d", &number) || number > MAX_NUM || number < MIN_NUM);

    return number;
}

int get_year(){
    int year;
    do{
        printf("Enter car year:\n");
    }
    while( !scanf("%d", &year) || year < MIN_YEAR || year > MAX_YEAR );

    return year;
};

double get_dist(){
    int dist;
    do{
        printf("Enter car dist:\n");
    }
    while( !scanf("%d", &dist) );

    return dist;
};

void get_color(char** color){
    char tmp[TMP];

    do{
        printf("Enter car color:\n");
    }
    while(!scanf("%s", tmp) || strlen(tmp) < 3);

    *color = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
    strcpy(*color, tmp);
}

int get_exidentes(){
    int exident;
    do{
        printf("Enter number of road exidents:\n");
    }
    while( !scanf("%d", &exident) );

    return exident;   
};

void get_exid_years(int exid_years[], int size){
    int i;

    for(i = 0; i < size; i++){
        do{
            printf("Enter an exident year %d:\n", (i + 1));
        }
        while(!scanf("%d", &exid_years[i]) || (exid_years[i] < MIN_YEAR || exid_years[i] > MAX_YEAR));
    }  
};



