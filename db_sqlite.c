/*
*****************************************************************
requisite:
apt-get -y install sqlite3 libsqlite3-dev

you need a database (sql):
$ sqlite3
sqlite>  create table people (
        id              integer,
        firstname       varchar(20),
        lastname        varchar(20),
        phonenumber     char(10)
);

sqlite> insert into people (id, firstname, lastname, phonenumber) values (1, 'fulano', 'full', '123456789');
sqlite> insert into people (id, firstname, lastname, phonenumber) values (2, 'ciclano', 'clien', '321654987');
sqlite> insert into people (id, firstname, lastname, phonenumber) values(3, 'beltrano', 'mendes', '987456123');
sqlite> .exit

*****************************************************************


				      /~\
			             |oo )        what plans ?
			             _\=/_
		    ___          #  /  _  \
		   /() \         \\//|/.\|\\
	         _|_____|_        \/  \_/  ||
	        | | === | |          |\ /| ||
	        |_|  O  |_|          \_ _/  #
		 ||  O  ||           | | |
		 ||__*__||           | | |
		|~ \___/ ~|          []|[]
                /=\ /=\ /=\          | | |
________________[_]_[_]_[_]_________/_]_[_\_______________________

 compile: gcc -o db db_sqlite.c -lsqlite3; ./db
 by d3lf0
*/
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **colName) {
 int i;
 fprintf(stderr, "%s: ", (const char*)data);
 printf("size row: %d\n",argc);
 for(i=0;i<argc;i++) {
  printf("%s = %s\n",colName[i],argv[i] ? argv[i] : "NULL" );
 }
 printf("\n");
 return 0;
}

void select_db(sqlite3 *db, char *sql) {
 const char *data = "Callback function called";
 char *msgError = 0;
 int error = 0;
 error = sqlite3_exec(db,sql,callback, (void*)data,&msgError);
 if(error != SQLITE_OK ) {
  fprintf(stderr, "SQL error: %s\n", msgError);
  sqlite3_free(msgError);
 } else {
  fprintf(stdout, "Operation done sucessfully\n");
 }
}

int main(int argc, char *argv[]) {
 sqlite3 *db;
 int rc,op=0;
 char *sql = "select * from people";

 rc = sqliite3_open("test.sl3",&db);
 if(rc) {
  fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
  return 0;
 } else {
  fprintf(stderr,"Opened database sucessfully\n");

  printf("\n1 - select");
  printf("\n2 - insert");
  printf("\n3 - update");
  printf("\n4 - delete\n--> ");
  scanf("%d",&op);
  switch(op) {
   case 1:
     select_db(db,"select * from people;");
     break;
   case 2:
     select_db(db,"insert into people (id,firstname,lastname,phonenumber) values (4,'john','maddog','852741963');");
     break;
   case 3:
     select_db(db,"update people set firstname = 'xXx', lastname = 'xXx' where id = '2';");
     break;
   case 4:
     select_db(db,"delete from people where id = '1';");
     break;
  }
 }
 sqlite3_close(db);
 return 0;
}
