#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* nodebaru = (struct node*)malloc(sizeof(struct node));
    nodebaru->data = data;
    nodebaru->next = NULL;
    return nodebaru;
}
void insertFirst(struct node** noderef, int new_data)
{
    struct node* nodebaru = newNode(new_data);
    nodebaru->next = (*noderef);
    (*noderef) = nodebaru;
}
struct node* SumLargeNumber(struct node* pertama, struct node* kedua)
{
    if(pertama->data == 0)
        return pertama;
    if(kedua->data == 0)
        return kedua;

    struct node* hasil = NULL;
    struct node *temp, *prev = NULL;
    int carry = 0, sum;
    while (pertama != NULL || kedua != NULL) {
        sum = carry + (pertama ? pertama->data : 0) + (kedua ? kedua->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        if (hasil == NULL)
            hasil = temp;
        else
            prev->next = temp;
        prev = temp;
        if (pertama)
            pertama = pertama->next;
        if (kedua)
            kedua = kedua->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);
    return hasil;
}

void printList(struct node* node)
{
    while (node != NULL) {
        printf("-> %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void BalikList(struct node* node){
    struct node* temp = node;
    printf("\nHasil penjumlahan : \n");
    while(temp)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    return;
}

int main(void)
{
    struct Node* pertama = NULL;
    insertFirst(&pertama, 1);
    insertFirst(&pertama, 2);
    insertFirst(&pertama, 5);
    insertFirst(&pertama, 3);
    insertFirst(&pertama, 2);
    insertFirst(&pertama, 9);
    insertFirst(&pertama, 1);
    insertFirst(&pertama, 9);
    insertFirst(&pertama, 1);
    insertFirst(&pertama, 2);

    printf("Baris L1 : \n ");
    printList(pertama);

    struct Node* kedua = NULL;
    insertFirst(&kedua, 5);
    insertFirst(&kedua, 3);
    insertFirst(&kedua, 1);
    insertFirst(&kedua, 3);
    insertFirst(&kedua, 1);
    insertFirst(&kedua, 2);
    insertFirst(&kedua, 6);
    insertFirst(&kedua, 8);
    insertFirst(&kedua, 1);
    insertFirst(&kedua, 1);

    struct Node* hasil = NULL;
    printf("Baris L2 : \n");
    printList(kedua);
    hasil = SumLargeNumber(pertama, kedua);
    printf("Hasil L1 + L2  : \n");
    printList(hasil);
    BalikList(hasil);

    printf("\n");

    return 0;
}

