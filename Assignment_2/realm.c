// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by Celine Lin (z5311209)
// on 2020-07-20
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-08-04): Changed wording in advance_enemies comment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "realm.h"
///////////////////////////////////////////////////////////////////////

// `struct realm` represents a realm, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// locations, though you may want to add other fields to it.
//
// You may need to add fields to struct realm.
struct realm {
    struct location *castle;
    struct location *lair;
};

// `struct location` represents a location, which could be a land,
// a tower, or a castle. Each of those places has a different type
// of information that this struct will need to store.
//
// You will need to add fields to struct location.
struct location {
    char name[MAX_NAME_LENGTH];
    struct enemy *enemies;
    struct location *next;
    int power;
    int uses;
    int effect;
};

// `struct enemy` represents an enemy, which will move through the
// realm (to each location). Towers can deal damage to it, and
// it can deal damage to the Castle.
//
// You will need to add fields to struct enemy.
struct enemy {
    char name[MAX_NAME_LENGTH];
    int cur_hp;
    int max_hp;
    struct enemy *next;
};

// Add any other structs you define here.



///////////////////////////////////////////////////////////////////////

// Function prototypes for helper functions
static Location new_location(char *name);
static void print_tower(char *name, int power, int uses, Effect effect);
static void print_land(char *name);
static void print_castle(char *name, int defense);
static void print_enemy(char *name, int cur_hp, int max_hp);

// Add prototypes for any extra functions you create here.
int destroy_enemies(Realm realm, Location next_location);
///////////////////////////////////////////////////////////////////////

// You need to implement the following 9 functions.
// In other words, write code to make the function work as described 
// in realm.h.

// Create a new realm, and return a pointer to it.
// You may need to change this function in later stages.
Realm new_realm(void) {
    struct realm *realm = malloc(sizeof(struct realm));
    realm->castle = new_location("Castle");
    realm->lair = new_location("Lair");
    realm->lair->next = NULL;

    if (realm->castle != NULL && realm->lair != NULL) {
        realm->castle->next = realm->lair;
    }

    return realm;
}


// Return a new location created with malloc.
static Location new_location(char *name) {

    //make a memory in heap
    //the size of this memory is the same as the size of struct location
    Location new_location = (Location)malloc(sizeof(struct location));
    
    //put the input name in the name under the new_location
    //(new_location->name)
    strcpy(new_location->name, name);
    
    //set up the initial information for the new_location
    //it is a new location
    //there's no enemies or towers
    new_location->enemies = NULL;
    //information for towers
    new_location->power = 0;
    new_location->uses = 0;
    new_location->effect = EFFECT_NONE;
    new_location->next = NULL;
    
    //return the new_location with the input name
    return new_location;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new location to the realm, and return the total number of
// locations in the realm.
int add_location(Realm realm, char *name) {

    //run the new_location function to create a new location
    //set up two pointers, "cur_location" and "next_location"
    //cur_location starts at the castle
    //next_location starts at the next location
    Location add_location = new_location(name);
    Location cur_location = realm->castle;
    Location next_location = cur_location->next;
    
    //these are three realms
    //"Castle", "Lair" and the new location added above
    int num_realm = 3;    
    
    //keep looping until the next_location pointer 
    //points to the last realm (the "Lair")
    //and add one to the num_realm
    while(strcmp(next_location->name, "Lair") != 0) {
        cur_location = cur_location->next;
        next_location = next_location->next;
        num_realm++;
    }
    
    //let the next pointer in cur_location point to this_new_location
    //then let the next pointer in this_new_location pointer 
    //point to the next_location
    //this will put new_location in between the two locations
    cur_location->next = add_location;
    add_location->next = next_location;

    //return the number of realms in total
    return num_realm; 
}

// Print out the realm.
void print_realm(Realm realm) {

    //starts from the castle
    Location cur_location = realm->castle->next;
    
    //print out the castle
    print_castle(realm->castle->name, STARTING_CASTLE_HP);
    //if there's enemies under the castle
    //print out the enemies;
    if (realm->castle->enemies != NULL) {
        print_enemy(
            realm->castle->enemies->name,
            realm->castle->enemies->cur_hp, 
            realm->castle->enemies->max_hp
        );
    }
    //keep looping
    //until the next_location pointer 
    //points to NULL (nothing left)
    while(cur_location != NULL) {
    
        //print the realms
        if (
        cur_location->power != 0 && cur_location->uses != 0
        ) {//if there's power and uses, then it is a tower
            print_tower(
                cur_location->name,
                cur_location->power,
                cur_location->uses, 
                cur_location->effect
            );
        } else {//just a land
            print_land(cur_location->name);
        }
        
        //if there's enemies in the realms
        //print enemies
        if (cur_location->enemies != NULL) {
            Enemy cur_enemy = cur_location->enemies;
            if (cur_enemy->next == NULL) {//if there's only one enemy
                print_enemy(
                    cur_enemy->name,
                    cur_enemy->cur_hp, 
                    cur_enemy->max_hp
                );
                
            } else {//if there are enemies under the location
                //print out the enemies before the last
                while (cur_enemy->next != NULL) {
                    print_enemy(
                        cur_enemy->name,
                        cur_enemy->cur_hp, 
                        cur_enemy->max_hp
                    );
                    cur_enemy = cur_enemy->next;
                }
                //print out the last enemy
                print_enemy(
                    cur_enemy->name,
                    cur_enemy->cur_hp, 
                    cur_enemy->max_hp
                );
                
            }
        }
        //keep looping
        cur_location = cur_location->next;
    }
    
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add an enemy to the realm.
int new_enemy(Realm realm, char *location_name, char *name, int hp) {
    //create a location pointer starts at the castle
    Location cur_location = realm->castle;
    
    //if hp is less than one
    //return invalid stat.
    if (hp < 1) {
        return ERROR_INVALID_STAT;
    } else {
        //loop though all the locations
        while (cur_location != NULL) {
            //if cur_location is the enemy's location
            if (strcmp(cur_location->name, location_name) == 0) {
                //make a memory in heap
                Enemy new_enemy = (Enemy)malloc(sizeof(struct enemy));
                
                //set up the enemy's information
                strcpy(new_enemy->name, name);
                new_enemy->cur_hp = hp;
                new_enemy->max_hp = hp;
                
                //create a pointer points to the location
                //that should put in the enemy
                Enemy cur_enemy = cur_location->enemies;
                
                //if there's no enemy under this location
                //put the enemy inside this location
                if (cur_enemy == NULL) {
                    new_enemy->next = NULL;
                    cur_location->enemies = new_enemy;
                    return SUCCESS;
                } else {//if there are exist enemies under the location
                    //loop and find the last enemy
                    while (cur_enemy->next != NULL) {
                        cur_enemy = cur_enemy->next;
                    }
                    //put the enemy in the last of the enemy list
                    //and it's next is NULL
                    new_enemy->next = NULL;
                    cur_enemy->next = new_enemy;
                    return SUCCESS;
                }
            }
            cur_location = cur_location->next;
        }
        //if the input location does not exist
        //return there's no location
        return ERROR_NO_LOCATION;
    }
}

// Add a new tower to the realm.
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses) {
    //power should have power and uses
    //if not return ERROR_INVALID_STAT
    if (uses < 1 || power < 1) {
        return ERROR_INVALID_STAT;
    } else {
        //create two pointers
        //one starts from the castle
        //the other is one's next
        Location cur_location = realm->castle;
        Location next_location = cur_location->next;
        //keep looping until the location hits "Lair"
        while (strcmp(cur_location->name, "Lair") != 0) {
            //find the location(name) where the new_tower sits
            if (strcmp(cur_location->name, prev_name) == 0) {
                //set up the information of the tower
                Location new_tower = new_location(name);
                new_tower->power = power;
                new_tower->uses = uses;
                //put the tower after it's prev_location
                //and before the prev_location's next
                //i.e. in between
                cur_location->next = new_tower;
                new_tower->next = next_location;
                return SUCCESS;
            }
            //keep looping
            cur_location = cur_location->next;
            next_location = next_location->next;
        }
        //if no location match with the tower's location
        //return ERROR_NO_LOCATION
        return ERROR_NO_LOCATION;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Destroy the realm, and free any associated memory.
void destroy_realm(Realm realm) {
    Location cur_location = realm->castle;
    Location next_location = cur_location->next;
    //loop 
    while (cur_location != NULL) {
        //starts from the castle
       cur_location = realm->castle;
       //if nothing is after the castle
        if (next_location == NULL) {
            //check if there are enemies under the castle
            //if there are enemies under the castle
            //free the enemies first
            if (cur_location->enemies != NULL) {
                destroy_enemies(realm, cur_location);
            }
            //then free the castle
            //end the loop
            free(cur_location);
            cur_location = NULL;
        } else {
            //go to the last location
            while (next_location != NULL) {
                cur_location = cur_location->next;
                next_location = next_location->next;
            }
            //if there's enemies, free the enemies first
            if (cur_location->enemies != NULL) {
                destroy_enemies(realm, cur_location);
            }
            //free this location
            free(cur_location);
        }
    }
}
//destroy_enemies function
int destroy_enemies (Realm realm, Location location) {
    //set up two pointers
    Enemy cur_enemy = location->enemies;
    Enemy next_enemy = cur_enemy->next;
    
    int passed_castle = 0;
    
    //end the loop when there's no enemies under the location
    while (location->enemies != NULL) {
        cur_enemy = location->enemies;
        //if there's only one enemy under the location
        //free the enemy 
        //and there will be no/NULL enemy under this location
        if (next_enemy == NULL) {
            free(cur_enemy);
            location->enemies = NULL;
            passed_castle++;
        } else {
            //if there are enemies under this location
            //loop though the enemies to find the last enemy
            //free the last enemy
            //and there's no/NULL enemy under the location
            while (next_enemy != NULL) {
                cur_enemy = cur_enemy->next;
                next_enemy = cur_enemy->next;
                passed_castle++;
            }
            free(cur_enemy);
            location->enemies = NULL;
        }
    }
    return passed_castle;
}

// Advance enemies towards the castle.
int advance_enemies(Realm realm) {
    int passed_castle = 0;
    //create a location before castle
    //and set up it's information
    Location pass_castle = malloc(sizeof(struct location));
    pass_castle = new_location("pass_castle");
    pass_castle->enemies = NULL;
    pass_castle->next = realm->castle;
    
    //create two location pointers
    //starts before castle
    Location prev_location = pass_castle;
    Location cur_location = prev_location->next;
    //keep looping until there's no more location
    while (cur_location != NULL) {
        //if there are enemies under the current location
        if (cur_location->enemies != NULL) {
            //and if there only one enemy under the next location
            //put the enemy under the previous location
            //and this location will have no/NULL enemy
            if (cur_location->enemies->next == NULL) {
                prev_location->enemies = cur_location->enemies;
                cur_location->enemies = NULL;
            } else {//if there are many enemies
                //put the cur location enemy into the
                //prev_location enemies
                prev_location->enemies = cur_location->enemies;
                Enemy next_enemy = cur_location->enemies->next;
                cur_location->enemies = next_enemy;
                Enemy cur_enemy = cur_location->enemies->next;
                //keep looping until there's no more enemies
                while (cur_location->enemies != NULL) {
                    cur_enemy = cur_location->enemies;
                    next_enemy = cur_location->enemies->next;
                    cur_location->enemies = next_enemy;
                    cur_enemy = cur_enemy->next;
                }
                
            }
        }
        //keep looping
        prev_location = prev_location->next;
        cur_location = cur_location->next;
    
    }
    prev_location->enemies = NULL;
    //if there are enemies passed the castle
    //free the enemies
    if (pass_castle->enemies != NULL) {
        passed_castle = destroy_enemies(realm, pass_castle);
    }
    //return the number of enemies passed_castle
    return passed_castle;
}

// Apply damage to the enemies at each tower, and reduce the castle's
// defense.
int apply_damage(Realm realm) {
    //starts from the location after the castle
    Location cur_location = realm->castle->next;
    int num_hit = 0;
    //keep looping until there's no location
    while (cur_location != NULL) {
        //if it's a tower with enemies
        if (
            cur_location->power > 0 
            && cur_location->uses > 0 
            && cur_location->enemies != NULL
        ) {
            Enemy cur_enemy = cur_location->enemies;
            //if there's only one enemy
            //hit the enemy
            if (cur_enemy->next == NULL) {
                cur_location->uses = cur_location->uses - 1;
                cur_enemy->cur_hp = 
                cur_enemy->cur_hp - cur_location->power;
                num_hit++;
            } else {//if there are many enemies
                //the tower only used once
                cur_location->uses = cur_location->uses - 1;
                //keep looping until there's no enemy
                while (cur_enemy != NULL) {
                    cur_enemy->cur_hp = 
                    cur_enemy->cur_hp - cur_location->power;
                    num_hit++;
                    cur_enemy = cur_enemy->next;
                }
            }
            //if the enemy's hp is less than one
            //free the enemy
            if (cur_location->enemies->cur_hp < 1) {
                destroy_enemies(realm, cur_location);
            }
        }
        //keep looping
        cur_location = cur_location->next;
    }
    //return the num_hit
    return num_hit;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified buff to the relevant towers or enemies.
int apply_buff(Realm realm, char *search_term, Buff buff, int amount){
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified effect to each tower whose name matches the
// specified search term.
int apply_effect(Realm realm, char *search_term, Effect effect) {
    return 0;
}

////////////////////////////////////////////////////////////////////////

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.




////////////////////////////////////////////////////////////////////////
//                    Provided print functions                        //
//         NOTE: YOU SHOULD NOT MODIFY THE FOLLOWING FUNCTIONS        //
////////////////////////////////////////////////////////////////////////

void print_tower(char *name, int power, int uses, int effect) {
    printf(" ^ %32s [pow: %3d | uses: %3d]", name, power, uses);
    if (effect == EFFECT_NONE) printf(" {%c}", EFFECT_NONE_CHAR);
    if (effect == EFFECT_PORTAL) printf(" {%c}", EFFECT_PORTAL_CHAR);
    if (effect == EFFECT_ICE) printf(" {%c}", EFFECT_ICE_CHAR);
    printf("\n");
}

void print_land(char *name) {
    printf(" ^ %32s [____________________]\n", name);
}

void print_castle(char *name, int defense) {
    printf(" ^ %32s [Castle Defenses: %3d]\n", name, defense);
}

void print_enemy(char *name, int cur_hp, int max_hp) {
    printf(" ^ %40s [hp: %d/%d]\n", name, cur_hp, max_hp);
}

////////////////////////////////////////////////////////////////////////
//               End of provided print functions                      //
////////////////////////////////////////////////////////////////////////




