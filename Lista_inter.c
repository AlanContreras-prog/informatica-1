#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//despliega la lista
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
//inicia desde el principio
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//inserta un enlace a la primer ubicacion
void insertFirst(int key, int data) {
   //crea un enlace
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //lo apunta al primer nodo inicial antiguo
   link->next = head;
	
   //apunta el primero al nuevo primer nodo
   head = link;
}

//borra el primer elemento
struct node* deleteFirst() {

   //salva la referencia al primer enlace
   struct node *tempLink = head;
	
   //marca el siguiente paso al primer enlace como primero 
   head = head->next;
	
   //regresa el enlace borrado
   return tempLink;
}
//verifica si la lista esta vacia
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//encuentra un enlace con una clave dada
struct node* find(int key) {

   //inicia desde el primer enlace
   struct node* current = head;

   //si la lista esta vacia
   if(head == NULL) {
      return NULL;
   }

   //se navega a traves de la lista
   while(current->key != key) {
	
      //si se ubica en el ultimo nodo
      if(current->next == NULL) {
         return NULL;
      } else {
         //va al siguiente enlace
         current = current->next;
      }
   }
//si encuentra un dato, se regresa al enlace donde se ubica
   return current;
}

//elimina un enlace con la clave dada
struct node* delete(int key) {

   //inicia desde el primer enlace
   struct node* current = head;
   struct node* previous = NULL;
	
   //verifica si la lista esta vacia
   if(head == NULL) {
      return NULL;
   }

   //navega a traves de la lista
   while(current->key != key) {

      //si esta es el ultimo nodo
      if(current->next == NULL) {
         return NULL;
      } else {
         //almacena la referencia al enlace donde se ubica
         previous = current;
         //se mueve al siguiente enlace
         current = current->next;
      }
   }

   //encuentra una coincidencia, actualiza el enlace
   if(current == head) {
      //cambia el primero para apuntar al siguiente enlace
      head = head->next;
   } else {
      //desvia el enlace actual
      previous->next = current->next;
   }    
	
   return current;
}
void sort() {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}
void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}
void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("La Lista Original es : "); 
	
   //se imprime la lista
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nSe elimina el valor:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nSe muestra la Lista despues de borrar todos los elementos : ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nSe Restaura la Lista : ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Se Encuentra el Elemento : ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Elemento no encontrado.");
   }
delete(4);
   printf("Se muestra la Lista despues de borrar un elemento : ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Se encuentra el Elemento : ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("No se encontro el Elemento.");
   }
	
   printf("\n");
   sort();
	
   printf("Se muestra la Lista despues de un ordenamiento de datos: ");
   printList();
	
   reverse(&head);
   printf("\nSe muestra la Lista despues de regresar el dato : ");
   printList();
}

