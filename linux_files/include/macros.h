#ifndef MACROS

#include "sqlite3.h"
void macroExecute(char * macro_to_execute);
int dbStatusCheck(int db_status, sqlite3* db);
void macroCreate();
void macroEdit();
void macroDelete();
void macroSelect();

#endif // !MACROS

