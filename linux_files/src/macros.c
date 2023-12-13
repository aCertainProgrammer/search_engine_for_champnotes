#include "macros.h"
#include "inputhandling.h"
#include <stdlib.h>
#include <stdio.h> 
void macroExecute(){
  sqlite3 * db;
 
  int db_status = sqlite3_open("macros.db", &db);
  dbStatusCheck(db_status, db);

  const char *select_sql = "SELECT Macro_contents FROM Macros WHERE Macro_name =?;";
  db_status = sqlite3_exec(db, select_sql, 0, 0, 0); 
  dbStatusCheck(db_status, db);

  char * macro_name = NULL;
  sqlite3_stmt *statement_to_execute;
  db_status = sqlite3_prepare_v2(db, select_sql, -1, &statement_to_execute, 0);
  
    if (dbStatusCheck(db_status, db) == 0)
  {
    userStringInput(&macro_name);
    sqlite3_bind_text(statement_to_execute, 1, macro_name, -1, SQLITE_STATIC);

    sqlite3_step(statement_to_execute);
    char * macro_contents = (char *)sqlite3_column_text(statement_to_execute, 0);
    printf("\n%s\n", macro_contents);
  }
  free(macro_name);
  return;
}

int dbStatusCheck(int db_status, sqlite3 * db)
{
  
  if (db_status != SQLITE_OK)
  {
    fprintf(stderr, "\nCant open db: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return db_status;
  }
  else {
  return 0;
  }
}
