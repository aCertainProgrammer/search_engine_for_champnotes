#ifndef MACROS

#include <sqlite3.h>
void macroExecuteIterator(char * token_to_iterate_through, int iterator_variable);
int dbStatusCheck(int db_status, sqlite3* db);
void macroCreate();
void macroEdit();
void macroDelete();
void macroSelect();
void macroExecute(char *macro_to_execute);
#endif // !MACROS

