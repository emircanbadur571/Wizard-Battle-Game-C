#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_SPELLS 50
#define WIZARD_SPELLS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char magic_class[MAX_NAME_LENGTH];
    int min_damage;
    int max_damage;
    int min_mana;
    int max_mana;
} Spell;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char magic_class[MAX_NAME_LENGTH];
    Spell spells[WIZARD_SPELLS];
    int hp;
    int mana;
    int alive;
    int total_damage_dealt;
    int total_mana_spent;
    int recoveries;
} Wizard;

Spell spellbook[MAX_SPELLS];
int total_spells = 0;

void load_spells() {
    FILE *file = fopen("spellbook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open spellbook.txt\n");
        exit(1);
    }
    
    char line[200];
    while (fgets(line, sizeof(line), file) && total_spells < MAX_SPELLS) {
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(spellbook[total_spells].name, token);
            
            token = strtok(NULL, ",");
            strcpy(spellbook[total_spells].magic_class, token);
            
            token = strtok(NULL, ",");
            spellbook[total_spells].min_damage = atoi(token);
            
            token = strtok(NULL, ",");
            spellbook[total_spells].max_damage = atoi(token);
            
            token = strtok(NULL, ",");
            spellbook[total_spells].min_mana = atoi(token);
            
            token = strtok(NULL, ",");
            spellbook[total_spells].max_mana = atoi(token);
            
            total_spells++;
        }
    }
    fclose(file);
}

void initialize_wizard(Wizard *wizard, char *name, char *magic_class) {
    strcpy(wizard->name, name);
    strcpy(wizard->magic_class, magic_class);
    wizard->hp = 100;
    wizard->mana = 100;
    wizard->alive = 1;
    wizard->total_damage_dealt = 0;
    wizard->total_mana_spent = 0;
    wizard->recoveries = 0;
    
    /* Randomly assign 3 spells */
    int i;
    for (i = 0; i < WIZARD_SPELLS; i++) {
        int random_spell = rand() % total_spells;
        wizard->spells[i] = spellbook[random_spell];
    }
}

int calculate_score(int stats[], int n) {
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return stats[0] * 2; /* damage * 2 */
    } else if (n == 2) {
        return stats[0] * 2 + stats[1] * 1; /* damage * 2 + mana * 1 */
    } else {
        return stats[0] * 2 + stats[1] * 1 - stats[2] * 3; /* damage * 2 + mana * 1 - recoveries * 3 */
    }
}

void duel(Wizard* attacker, Wizard* defender) {
    if (!attacker->alive || !defender->alive) {
        return;
    }
    
    /* Attacker chooses a random spell */
    int spell_index = rand() % WIZARD_SPELLS;
    Spell chosen_spell = attacker->spells[spell_index];
    
    /* Calculate random damage and mana cost */
    int damage = chosen_spell.min_damage + (rand() % (chosen_spell.max_damage - chosen_spell.min_damage + 1));
    int mana_cost = chosen_spell.min_mana + (rand() % (chosen_spell.max_mana - chosen_spell.min_mana + 1));
    
    /* Check if attacker has enough mana */
    if (attacker->mana < mana_cost) {
        /* Recover mana */
        int recovery = 10 + (rand() % 11); /* 10-20 */
        attacker->mana += recovery;
        attacker->recoveries++;
        
        printf("%s is low on mana and meditates...\n", attacker->name);
        printf("%s recovers %d mana. Current mana: %d\n", attacker->name, recovery, attacker->mana);
        
        /* Try again recursively */
        duel(attacker, defender);
        return;
    }
    
    /* Cast the spell */
    printf("%s casts %s on %s!\n", attacker->name, chosen_spell.name, defender->name);
    
    /* Apply class bonus */
    if (strcmp(attacker->magic_class, chosen_spell.magic_class) == 0) {
        damage += 5;
    }
    
    /* Apply damage and deduct mana */
    defender->hp -= damage;
    attacker->mana -= mana_cost;
    attacker->total_damage_dealt += damage;
    attacker->total_mana_spent += mana_cost;
    
    printf("Damage: %d | %s's HP: %d | %s's Mana: %d\n", 
           damage, defender->name, defender->hp, attacker->name, attacker->mana);
    printf("-------------------------------------------------\n");
    
    /* Check if defender is defeated */
    if (defender->hp <= 0) {
        defender->alive = 0;
        return;
    }
    
    /* Continue duel with roles swapped */
    duel(defender, attacker);
}

int main() {
    srand(time(NULL));
    
    /* Load spells from file */
    load_spells();
    
    /* Get wizard names and classes from user */
    char wizard1_name[MAX_NAME_LENGTH], wizard1_class[MAX_NAME_LENGTH];
    char wizard2_name[MAX_NAME_LENGTH], wizard2_class[MAX_NAME_LENGTH];
    
    printf("Enter first wizard's name: ");
    scanf("%s", wizard1_name);
    
    /* Validate first wizard's class */
    printf("Enter first wizard's magic class (fire/ice): ");
    scanf("%s", wizard1_class);
    while (strcmp(wizard1_class, "fire") != 0 && strcmp(wizard1_class, "ice") != 0) {
        printf("Invalid class! Please enter 'fire' or 'ice'.\n");
        printf("Enter first wizard's magic class (fire/ice): ");
        scanf("%s", wizard1_class);
    }
    
    printf("Enter second wizard's name: ");
    scanf("%s", wizard2_name);
    
    /* Validate second wizard's class */
    printf("Enter second wizard's magic class (fire/ice): ");
    scanf("%s", wizard2_class);
    while (strcmp(wizard2_class, "fire") != 0 && strcmp(wizard2_class, "ice") != 0) {
        printf("Invalid class! Please enter 'fire' or 'ice'.\n");
        printf("Enter second wizard's magic class (fire/ice): ");
        scanf("%s", wizard2_class);
    }
    
    /* Initialize wizards */
    Wizard wizard1, wizard2;
    initialize_wizard(&wizard1, wizard1_name, wizard1_class);
    initialize_wizard(&wizard2, wizard2_name, wizard2_class);
    
    printf("\nWizard Duel Begins: %s vs %s!\n", wizard1.name, wizard2.name);
    printf("-------------------------------------------------\n");
    
    /* Start the duel */
    duel(&wizard1, &wizard2);
    
    /* Determine winner */
    if (wizard1.alive) {
        printf("Winner: %s the %s Wizard!\n", wizard1.name, wizard1.magic_class);
    } else {
        printf("Winner: %s the %s Wizard!\n", wizard2.name, wizard2.magic_class);
    }
    
    /* Calculate scores */
    int wizard1_stats[3] = {wizard1.total_damage_dealt, wizard1.total_mana_spent, wizard1.recoveries};
    int wizard2_stats[3] = {wizard2.total_damage_dealt, wizard2.total_mana_spent, wizard2.recoveries};
    
    int wizard1_score = calculate_score(wizard1_stats, 3);
    int wizard2_score = calculate_score(wizard2_stats, 3);
    
    printf("Battle Summary:\n");
    printf("%s - Damage: %d Mana Spent: %d Recoveries: %d Score: %d\n", 
           wizard1.name, wizard1.total_damage_dealt, wizard1.total_mana_spent, wizard1.recoveries, wizard1_score);
    printf("%s - Damage: %d Mana Spent: %d Recoveries: %d Score: %d\n", 
           wizard2.name, wizard2.total_damage_dealt, wizard2.total_mana_spent, wizard2.recoveries, wizard2_score);
    
    return 0;
}
