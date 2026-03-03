/*
 *   File: FirstLinkedLists.c
 *   Description: First try to implement a linked list
 */


 #include <stdio.h>
 #include <stdlib.h>


 typedef struct ListElement
 {
    int Wert1;                  //Wert von ListElement
    struct ListElement *next;   // Next-Zeiger -- Pointer auf ein anderes Element
 } ListElement;


 typedef struct
 {
    ListElement *first;     // Erstes Element in der Liste
 } List;

 /*
 * @brief function to add new elements to the list
 * @param[in]  param1 Explain parameter 1 (Input)
 * @param[out] param2 Explain parameter 2 (Output/Pointer)
 * @return            Explanation of return value
 */
 
void insert_Element(ListElement *newElement, List *list)     // Rückgabewert unrelevant -> void
{
    ListElement *temp;      //temporäres Element
    temp = list->first;     // temp auf das erste Element gesetzt
    while(temp->next != NULL) // Liste durchlaufen, wenn ungleich Null, temp ein Element weiter, wenn Null: Liste zu ende
    {
        temp = temp->next;
    }
    temp->next = newElement; // Wenn temp->next auf Null zeigt, dann ist dieser gleich das neue Element
}

 /**
 * @brief function to delete elements from the list
 * @param[in]  param1 Explain parameter 1 (Input)
 * @param[out] param2 Explain parameter 2 (Output/Pointer)
 * @return            Explanation of return value
 */

void delete_Element(ListElement* delElement, List* list)
{
    ListElement *temp;
    ListElement *del;
    temp = list->first;

    if(temp == delElement)
    {
        list->first = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL)
    {
        if(temp->next == delElement)
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
        temp = temp->next;
    }
}



 void print_list(List *list)
    {
        ListElement *temp;
        temp = list->first;
        while(temp != NULL)
        {
            printf("%d\n", temp->Wert1);
            temp = temp->next;
        }
        printf("----------------\n");
    }

 int main()
 {
    List list;

    ListElement *a;
    a = malloc(sizeof *a);
    a->Wert1 = 10;
    a->next = NULL;

    list.first = a;

    ListElement *b;
    b = malloc(sizeof *b);
    b->Wert1 = 15;
    b->next =  NULL;

    ListElement *c;
    c = malloc(sizeof *c);
    c->Wert1 = 99;
    c->next =  NULL;

    insert_Element(b, &list); // Element b in die Liste hinzufügen

    insert_Element(c, &list);

    print_list(&list);
   
    delete_Element(b, &list);

    print_list(&list);
   


    return 0;
 }