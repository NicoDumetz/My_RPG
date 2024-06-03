/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

bool check_file_content(save_t *save, char *path)
{
    struct stat st_file;
    time_t last_mod = 0;

    if (stat(path, &st_file) != 0) {
        fprintf(stderr, "Error to take file information\n");
        return false;
    }
    last_mod = st_file.st_mtime;
    if (last_mod != save->time_last_save || save->end_save != 42) {
        printf("Save file Corrupted\n");
        return false;
    }
    save->next = NULL;
    save->prev = NULL;
    return true;
}

save_t *copy_save_file(int fd, char *path)
{
    save_t *save = malloc(sizeof(save_t));

    memset(save, 0, sizeof(save_t));
    if (read(fd, save, sizeof(save_t)) != sizeof(save_t) ||
        !check_file_content(save, path)) {
        free(save);
        return NULL;
    }
    return (save);
}

save_t *open_save_file(struct dirent *entry)
{
    char path[strlen("save_dir/") + strlen(entry->d_name) + 1];
    int fd;
    save_t *save = NULL;
    struct stat st_file;

    strcpy(path, "save_dir/");
    strcat(path, entry->d_name);
    if (stat(path, &st_file) != 0 || !S_ISREG(st_file.st_mode)) {
        fprintf(stderr, "Error to take file information\n");
        return save;
    }
    fd = open(path, O_RDONLY);
    if (fd > 1)
        save = copy_save_file(fd, path);
    close(fd);
    return save;
}

void create_file_list(rpg_t *rpg)
{
    struct dirent *entry;
    DIR *dir = opendir("save_dir");
    save_t *save = NULL;

    if (dir == NULL) {
        closedir(dir);
        return;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        save = open_save_file(entry);
        if (save != NULL)
            update_save_list(save, rpg);
        entry = readdir(dir);
    }
    closedir(dir);
}
