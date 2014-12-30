/*
 * In The Name Of God
 * ========================================
 * [] File Name : fs.h
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Wed 31 Dec 2014 12:47:48 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef FS_H
#define FS_H

#include "FAT.h"

/*
 * Set file descriptor for fs handler
*/
void init_fs(int dev);

/*
 * Find part of path in a directory and return it's address
 * if path not found it return NULL
 * you shoud free directory list and store returned address
 * elsewhere.
*/
struct fat_dir_layout *search(const struct fat_dir_layout *root_dir,
		const char *term, int size);

/*
 * Find path in filesystem tree.
 * please free returned address.
*/
struct fat_dir_layout *find(const char *path);

/*
 * Returne parent path for
 * given path, for example
 * $$$/A/B ==> $$$/A/
*/
char *get_parent_path(const char *path);

/*
 * Change first character after last '/'
 * to 0xE5 because user cannot enter 0xE5 !!
 * so we enter it for him !!!
 * note that it set character c to character
 * it changed.
*/
char *fix_deleted_char(const char *path, char *c);

/*
 * Read disk label and store it on string and
 * return it's address
*/
char *get_label(void);

/*
 * Parse directory and set dir_size to entry number and
 * set entry itself in fat_dir_layout*
*/
struct fat_dir_layout *parse_dir(struct fat_dir_layout dir, int *dir_size);

/*
 * Write entries at first cluster of dir
*/
void write_dir(struct fat_dir_layout dir,
		const struct fat_dir_layout *entries, int dir_size);

#endif
