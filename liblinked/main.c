#include "llinked.h"

#include <stdio.h>

typedef struct character_s Character;
typedef struct item_s Item;
typedef struct weapon_s Weapon;

struct item_s {
    char *name;
    int level;
    int number;
};

struct weapon_s {
    char *name;
    int level;
    int power;
    bool isEnchanted;
};

struct character_s {
    char *name;
    int age;
    int level;
    int health;
    int mana;
    int maxHealth;
    int maxMana;
    Item inventory[3];
    Weapon weapon;
};

int main(void)
{
    Character first = {"Kreain", 24, 100, 9854, 6523, 10000, 7000, {
        {"Health Potion", 5, 156},
        {"Mana Potion", 6, 140},
        {"Gold", 1, 9855421}
    }, {"Excalibur", 100, 897, true}};

    Character second = {"Jyst", 27, 85, 5621, 4578, 6500, 6800, {
        {"Health Potion", 4, 52},
        {"Mana Potion", 5, 35},
        {"Gold", 1, 78785}
    }, {"KrakenLish", 78, 741, false}};

    Character third = {"Samanthe", 22, 94, 3600, 15203, 3600, 20000, {
        {"Health Potion", 3, 45},
        {"Mana Potion", 7, 200},
        {"Gold", 1, 5421}
    }, {"RedLight", 85, 803, true}};

    llist *list = create_llist();

    list->insert_mult(list, 3, &first, &second, &third);

    list->swap_first(list, 1);
    printf("Swap FIRST\n");

    for (size_t i = 0; i < list->length; i++) {
        Character ch = *((Character *) list->get_index(list, i));
        printf("====================\n");
        printf("The character [%s] is %i years old, of level %i\n", ch.name, ch.age, ch.level);
        printf("====================\n");
    }

    list->swap_last(list, 1);
    printf("Swap LAST\n");

    for (size_t i = 0; i < list->length; i++) {
        Character ch = *((Character *) list->get_index(list, i));
        printf("====================\n");
        printf("The character [%s] is %i years old, of level %i\n", ch.name, ch.age, ch.level);
        printf("====================\n");
    }

    list->swap_index(list, 0, 1);
    printf("Swap INDEX 0, 1\n");

    for (size_t i = 0; i < list->length; i++) {
        Character ch = *((Character *) list->get_index(list, i));
        printf("====================\n");
        printf("The character [%s] is %i years old, of level %i\n", ch.name, ch.age, ch.level);
        printf("====================\n");
    }

    list->swap_index(list, 1, 2);
    printf("Swap INDEX 1, 2\n");

    for (size_t i = 0; i < list->length; i++) {
        Character ch = *((Character *) list->get_index(list, i));
        printf("====================\n");
        printf("The character [%s] is %i years old, of level %i\n", ch.name, ch.age, ch.level);
        printf("====================\n");
    }

    printf("List contains first character: %s\n", list->contains_data(list, &first) ? "true" : "false");
    list->clear(list);
    printf("List has been emptied: %s\n", list->is_empty ? "true" : "false");

    destroy_llist(list);

    return (0);
}