#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_TYPE_LENGTH 50

struct pet {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int age;
    int weight;
};

// function declarations, do not change these
void setup_pet(
    struct pet *my_pet,
    char *name, 
    char *type, 
    char *age, 
    char *weight
)
{
 int i;
 i=0;
 char *t;
 t=NULL;
 char tage[MAX_NAME_LENGTH]={0};
 char tweight[MAX_NAME_LENGTH]={0}; 
 while(*name!='\0')
 {
  my_pet->name[i]=*name;
  name++;
  i++;
 }
 my_pet->name[i]='\0';
 i=0;
 while(*type!='\0')
 {
  my_pet->type[i]=*type;
  type++;
  i++;
 }
 my_pet->type[i]='\0';
 i=0;
 while(*age!='\0')
 {
  tage[i]=*age;
  age++;
  i++;
 }
 i=0;
 while(*weight!='\0')
 {
  tweight[i]=*weight;
  weight++;
  i++;
 }
 my_pet->age=0;
 my_pet->weight=0;
 my_pet->age=strtol(tage,&t,10);
 my_pet->weight=strtol(tweight,&t,10);
}
void print_pet(struct pet *my_pet)
{
 printf("%s is a %s who is %d years old and weighs %dkg\n",my_pet->name,my_pet->type,my_pet->age,my_pet->weight);
}
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("%s should receive four extra command line arguments.\n", argv[0]);
        return 1;
    }
    struct pet new_pet;
    setup_pet(&new_pet, argv[1], argv[2], argv[3], argv[4]);
    print_pet(&new_pet);
    return 0;
}

// do not change any code in the main function
//int main(int argc, char *argv[]) {
//    char *name="BKT";
//    char *type="Edraron";
//    char *age="200";
//    char *weight="1000";
//    struct pet new_pet;
//    setup_pet(&new_pet, name, type, age, weight);
//    print_pet(&new_pet);
//    return 0;
//}

// A function that takes in four strings
// (given from the command line arguments in the main function)
// and stores their data in the pet struct.
//
// Note: you will need to convert the 'age' and 'weight' strings 
// to an integer before storing them in the struct.
