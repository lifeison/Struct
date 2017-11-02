#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "stackdbio.h"
DBFile* initialize(const char *db_file_name) {
    //TODO
    DBFile *db_file = (DBFile *) malloc(sizeof(DBFile));
    db_file->file_ptr = NULL;
    strncpy(db_file->file_name, db_file_name, FILE_NAME_MAX_LEN);
    return db_file;
}

void open_db(DBFile *db) {
    //TODO
    db->file_ptr = fopen(db->file_name, "ab+");
}

void close_db(DBFile *db) {
    //TODO
    fclose(db->file_ptr);
}

void save_node_to_db(DBFile *db, node *data) {
    //TODO
    fwrite(data, sizeof(node), 1, db->file_ptr);
}

void read_from_db(DBFile *db, node *data) {
	//TODO
	fread(data, sizeof(node), 1, db->file_ptr);
}

void free_db(DBFile *db) {
    free(db);
}
