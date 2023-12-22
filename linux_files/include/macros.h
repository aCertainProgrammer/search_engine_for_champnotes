#ifndef MACROS

#include <sqlite3.h>

void macroExecuteIterator(char * macro_elements_array[], int iterator_variable, int macro_size_variable);
int dbStatusCheck(int db_status, sqlite3* db);
void macroCreate();
void macroEdit();
void macroDelete();
void macroSelect();
void macroExecute(char *macro_to_execute);
#endif // !MACROS

