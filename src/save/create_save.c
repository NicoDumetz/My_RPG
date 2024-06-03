/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

int count_save(rpg_t *rpg)
{
    int count = 0;

    for (save_t *curr = rpg->save_list; curr; curr = curr->next)
        count++;
    return count;
}

bool create_file(save_data_t *save, rpg_t *rpg)
{
    int save_id = count_save(rpg);
    char *id_str = convert_int_to_str(save_id);
    char new_file[strlen("save_dir/save_") + strlen(id_str) + 1];
    FILE *file;

    strcpy(new_file, "save_dir/save_");
    strcat(new_file, id_str);
    free(id_str);
    file = fopen(new_file, "wr");
    save->time_last_save = time(NULL);
    if (file == NULL || fwrite(save, sizeof(save_data_t), 1, file) != 1) {
        fprintf(stderr, "Error when write save\n");
        return false;
    } else
        printf("Save Success %s\n", new_file);
    fclose(file);
    return true;
}

bool check_dir(void)
{
    struct stat st;

    if (stat("save_dir", &st) == -1) {
        if (mkdir("save_dir", 0700) == -1) {
            fprintf(stderr, "Error when create save_dir\n");
            return false;
        }
    }
    return true;
}

void create_save(rpg_t *rpg)
{
    save_data_t *new_save = malloc(sizeof(save_data_t));

    memset(new_save, 0, sizeof(save_data_t));
    write_data_in_save(new_save, rpg);
    if (check_dir()) {
        if (create_file(new_save, rpg))
            update_save_list(new_save, rpg);
        else
            free(new_save);
    }
}
