#include "macros.h"
#include "champnotesfilesearch.h"
#include "draftnotessearch.h"
#include "inputhandling.h"
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include "menu.h"
#include "constants.h"
#include "validation.h"
#include <sqlite3.h>
void macroSelect(){
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

    db_status = sqlite3_step(statement_to_execute);

      char * macro_contents = (char *)sqlite3_column_text(statement_to_execute, 0);
      printf("\n%s\n", macro_contents);

      macroExecute(macro_contents);
  }


  free(macro_name);
  sqlite3_finalize(statement_to_execute);
  sqlite3_close(db);
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

void macroCreate()
{
  sqlite3 * db;
  int db_status = sqlite3_open("macros.db", &db);
  dbStatusCheck(db_status, db);
  
  const char * create_sql_statement = "INSERT INTO Macros (Macro_name, Macro_contents) VALUES (?, ?)";
  sqlite3_stmt * data_insertion_statement;
  db_status = sqlite3_prepare(db, create_sql_statement, -1, &data_insertion_statement, 0);

  char * macro_contents_to_add = NULL;
  char * macro_name_to_add = NULL;
  if (db_status == SQLITE_OK)
  {
    printf("\nNew macro name: ");
    userStringInput(&macro_name_to_add);

    printf("\nNew macros contents: ");
    
    macro_contents_to_add = malloc(MAX_MACRO_LENGHT * sizeof(char));
    if (macro_contents_to_add == NULL) memoryFail();

    int buffer_cleaner;
    while((buffer_cleaner = getchar()) != '\n');

    if (fgets(macro_contents_to_add, MAX_MACRO_LENGHT, stdin) != NULL)
    {
      size_t current_macro_lenght = strlen(macro_contents_to_add);
      if(current_macro_lenght > 0 && macro_contents_to_add[current_macro_lenght-1] == '\n')
      {
        macro_contents_to_add[current_macro_lenght - 1] = '\0';
      }
    }

    sqlite3_bind_text(data_insertion_statement, 1, macro_name_to_add, -1, SQLITE_STATIC);
    sqlite3_bind_text(data_insertion_statement, 2, macro_contents_to_add, -1, SQLITE_STATIC);

    if ((db_status = sqlite3_step(data_insertion_statement)) == SQLITE_DONE)
    {
      printf("\nMacro added\n"); 
    }
    else 
    {
      fprintf(stderr, "Error inserting :%s\n", sqlite3_errmsg(db)); 
    }
  }

  sqlite3_close(db);
  free(macro_name_to_add);
  free(macro_contents_to_add);
  mainMenu();
  return;
}

void macroExecute(char * macro_to_execute)
{
  char * macro_elements[100];
  char * token = strtok(macro_to_execute, " ");

  int macro_size = 0;
  for (int i = 0; token != NULL; i++) {
    macro_elements[i] = token;
    token = strtok(NULL, " ");
    macro_size++;
  }
  int macro_iterator = 0;
  macroExecuteIterator(macro_elements, macro_iterator, macro_size);
  mainMenu();
  return;
}


void macroExecuteIterator(char * macro_elements_array[], int iterator_variable, int macro_size_variable){

  if (iterator_variable >= macro_size_variable) {
    return;
  }
  if (strcmp(macro_elements_array[iterator_variable], "search") == 0) {
    championNotesSearch(macro_elements_array[iterator_variable+1], macro_elements_array[iterator_variable+2], macro_elements_array[iterator_variable+3], 1);
      iterator_variable = iterator_variable + 4;
      macroExecuteIterator(macro_elements_array, iterator_variable, macro_size_variable);
      }
  else if (strcmp(macro_elements_array[iterator_variable], "draft") == 0) {
      draftSearchManager(macro_elements_array[iterator_variable+1], macro_elements_array[iterator_variable+2], macro_elements_array[iterator_variable+3], 1);
      iterator_variable = iterator_variable + 4;
      macroExecuteIterator(macro_elements_array, iterator_variable, macro_size_variable);
    }
  else if (strcmp(macro_elements_array[iterator_variable], "quit") == 0) {
      exit(EXIT_SUCCESS);
    }
  else {
      iterator_variable++;
    }

 
  }
 
 void macroDelete(){
  sqlite3 * db;
 
  int db_status = sqlite3_open("macros.db", &db);
  dbStatusCheck(db_status, db);

  const char *delete_sql= "DELETE FROM Macros WHERE macro_name = ?";
  db_status = sqlite3_exec(db, delete_sql, 0, 0, 0); 
  dbStatusCheck(db_status, db);

  char * macro_name = NULL;
  sqlite3_stmt *statement_to_execute;
  db_status = sqlite3_prepare_v2(db, delete_sql, -1, &statement_to_execute, 0);
  
    if (dbStatusCheck(db_status, db) == 0)
  {
    printf("\nWhich macro to delete?: ");
    userStringInput(&macro_name);
    sqlite3_bind_text(statement_to_execute, 1, macro_name, -1, SQLITE_STATIC);

    db_status = sqlite3_step(statement_to_execute);

  }


  free(macro_name);
  sqlite3_finalize(statement_to_execute);
  sqlite3_close(db);
  mainMenu();
  return;
}
