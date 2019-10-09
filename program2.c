/* Peter Mitzel
 * CSCI 112
 * Program 2
 * 4/27/2018
 */

//Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Data Structure
typedef struct{
  char name[20];
  int cost;
  int aisle;
  char category;
}masterlist_t;

//Add function
void add(masterlist_t list[], int* total_items){
  char name;
  int cost;
  int aisle;
  char category;
  printf("Enter the name of the item: \n");
  scanf("%c", &name);
  strcpy(list[*total_items].name, &name);
  printf("Enter the cost of the item in cents: \n");
  scanf("%d", &cost);
  list[*total_items].cost = cost;
  printf("Enter the aisle number: \n");
  scanf("%d", &aisle);
  list[*total_items].aisle = aisle;
  printf("Enter the category letter (M, P, D or C): \n");
  scanf("%c", &category);
  list[*total_items].category = category;
}

//Prints how many items are in a selected category
void printcatnumber(masterlist_t list[], int* total_items){
  char select = ' ';
  char nl = ' ';
  int sum = 0;
  char cat1 = 'M';
  char cat2 = 'P';
  char cat3 = 'D';
  char cat4 = 'C';
  printf("Select a category(M, P, D or C): \n");
  scanf("%c", &select);
  scanf("%c", &nl);
  switch(select){
  case 'M':
  case 'm':;
    for(int i = 0; i < *total_items; i++){
      if(list[i].category == cat1){
        sum += 1;
      }
    }
    printf("There are %d items in this category.\n", sum);
    break;
  case 'P':
  case 'p':
    for(int i = 0; i < *total_items; i++){
      if(list[i].category == cat2){
        sum += 1;
      }
    }
    printf("There are %d items in this category.\n", sum);
    break;
  case 'D':
  case 'd':
    for(int i = 0; i < *total_items; i++){
      if(list[i].category == cat3){
        sum += 1;
      }
    }
    printf("There are %d items in this category.\n", sum);
    break;
  case 'C':
  case 'c':
    for(int i = 0; i < *total_items; i++){
      if(list[i].category == cat4){
        sum += 1;
      }
    }
    printf("There are %d items in this category.\n", sum);
    break;
  default:
    printf("This category does not exist.\n");
    break;
  }
}

//Prints all of the items sorted by category
void printlist(masterlist_t list[], int* total_items){
  printf("\nMeats\n");
  for (int i = 0; i < *total_items; i++){
    if (list[i].category == 'M'){
      printf("Name: %s, || Cost: %d cents || Aisle: %d.\n", list[i].name, list[i].cost, list[i].aisle);
    }
  }
  printf("\nProduce\n");
  for (int i = 0; i < *total_items; i++){
    if (list[i].category == 'P'){
      printf("Name: %s, || Cost: %d cents || Aisle: %d.\n", list[i].name, list[i].cost, list[i].aisle);
    }
  }
  printf("\nDairy\n");
  for (int i = 0; i < *total_items; i++){
    if (list[i].category == 'D'){
      printf("Name: %s, || Cost: %d cents || Aisle: %d.\n", list[i].name, list[i].cost, list[i].aisle);
    }
  }
  printf("\nCanned Foods\n");
  for (int i = 0; i < *total_items; i++){
    if (list[i].category == 'C'){
      printf("Name: %s, || Cost: %d cents || Aisle: %d.\n", list[i].name, list[i].cost, list[i].aisle);
    }
  }
}
  
//Function that handles the menu system
void UserInterface(masterlist_t list[], int* total_items){
  char select = ' ';
  char nl = ' ';
  while(select != 'x' && select != 'X'){
    printf("\nPress 'A' to add to list, 'N' for the number of items, 'L' to list all items or 'X' to exit\n");
    scanf("%c",&select);
    scanf("%c",&nl);
    switch(select){
    case 'A':
    case 'a':
      add(list, total_items);
      break;
    case 'L':
    case 'l':
      printlist(list, total_items);
      break;
    case 'N':
    case 'n':
      printcatnumber(list, total_items);
      break;
    case 'X':
    case 'x':
      printf("goodbye!\n");
      break;
    default:
      printf("We do not recognize that input\n");
      break;
    }
  }
}

//Main function
int main(){
  masterlist_t list[100];
  FILE* file = fopen("output.bin", "rb");
  int total_items = fread(&list, sizeof(masterlist_t), 100, file);
  fclose(file);
  UserInterface(list, &total_items);
  return(0);
}
