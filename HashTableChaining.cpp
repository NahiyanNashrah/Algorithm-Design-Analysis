#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20

struct DataItem
{
    int data;
    int key;

};

struct DataItem *dataList[SIZE][SIZE];
struct DataItem *singleItem;
struct DataItem *item;

int getHashCode(int key)
{
    return key % SIZE;
}


struct DataItem *search(int key)
{
    int hashIndex = getHashCode(key);
    int i = 0;
    while(dataList[hashIndex][i] != NULL)
    {
        if(dataList[hashIndex][i] -> key == key)
            return dataList[hashIndex][i];
        i++;
        i %= SIZE;

    }
    return NULL;
};

void insert (int key,int data)
{
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = getHashCode(key);
    int i = 0;

    while(dataList[hashIndex][i] != NULL && dataList[hashIndex][i]->key != -1)
    {
        i++;
        i %= SIZE;
    }
    dataList[hashIndex][i] = item;
}

struct DataItem *del(struct DataItem *item)
{
    int i = 0;
    int key = item->key;

    int hashIndex = getHashCode(key);
    while(dataList[hashIndex][i] != NULL && dataList[hashIndex][i]-> key != -1)
    {
        if(dataList[hashIndex][i]->key == key)
        {
            struct DataItem* temp = dataList[hashIndex][i];

            dataList[hashIndex][i] = singleItem;
            return temp;
        }
        ++i;
        i %= SIZE;
    }
    return NULL;
};

void display(){
    int i = 0;
    for(i = 0; i<SIZE;i++){
        for(int j = 0; j < SIZE; j++)
            {
             if(dataList[i][j] != NULL)
                printf("(%d,%d)",dataList[i][j]->key,dataList[i][j]->data);
            else
                printf("--");
            }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    singleItem->data =-1;
    singleItem->key =-1;

    insert(1,50);
    insert(37,10);
    insert(85,15);
    insert(6,25);
    insert(5,80);
    insert(19,36);
    insert(17,15);
    insert(42,77);
    insert(33,65);
    insert(26,95);

    display();
    item = search(17);

    if(item != NULL)
        printf("Element found %d %d\n",item->key,item->data);
    else
        printf("Element not found\n");

    del(item);
    item = search(17);

    if(item != NULL)
        printf("Element found %d %d\n",item->key,item->data);
    else
        printf("Element not found\n");


    return 0;
}


