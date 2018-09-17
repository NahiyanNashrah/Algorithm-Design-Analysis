#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define size 10

struct Info
{
    char name[10];
    int age;
    double salary;
};

struct data
{
    int key;
    struct Info i;
};

struct data *list[size][size];
struct data *singleItem;
struct data *item;

int getHashCode(int key)
{
    return key % size;
}

void insert(int key,char name[],int age,double salary)
{
    struct data *item = (struct data*)malloc(sizeof(struct data));

    item ->key = key;
    strcpy(item ->i.name,name);
    item -> i.age = age;
    item ->i.salary = salary;

    int index = getHashCode(key);
    int i = 0;

    while(list[index][i] != NULL)
    {
        i++;
        i %= size;
    }
    list[index][i] = item;

}

struct data *search(int key)
{
    int index = getHashCode(key);
    int i = 0;

    while(list[index][i] != NULL)
    {
        if(list[index][i] -> key == key)
            return list[index][i];

        i++;
        i %= size;

    }
    return NULL;
};

struct data *del(struct data *item)
{
    int key = item -> key;
    int index = getHashCode(key);
    int i = 0;

    while(list[index][i] != NULL)
    {
        if(list[index][i] -> key == key)
            {
                struct data *temp = list[index][i];
                list[index][i] = singleItem;
                return temp;
            }

             i++;
            i %= size;

    }
    return NULL;
};

void display()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(list[i][j] != NULL)
                {
                    printf("(%d : %s, %d, %lf)",list[i][j]->key,list[i][j]->i.name,list[i][j]->i.age,list[i][j]->i.salary);
                }
            else
                printf(".....");
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    singleItem = (struct data*)malloc(sizeof(struct data));
    singleItem ->key = -1;

    insert(5,"mim",26,25000.0);
    insert(9,"tuli",28,30000.0);
    insert(2,"apu",30,55000.0);
    insert(4,"tapan",35,60000.0);
    insert(6,"ali",32,55000.0);


    display();
    item = search(6);

    if(item != NULL)
        printf("Element found\n %d, %s, %d, %lf\n\n",item->key,item->i.name,item->i.age,item->i.salary);
    else
        printf("Not found\n");

    del(item);
    item = search(6);

    if(item != NULL)
        printf("Element found\n %d, %s, %d, %lf\n\n",item->key,item->i.name,item->i.age,item->i.salary);
    else
        printf("Not found\n");

    return 0;
}





