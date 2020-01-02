#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct{
    int id;
    char *title;
    char *content;
    char *created_at;
}NEWS;


int insert(sqlite3 *db,NEWS new){
    char *err;
    char sql[100];
    sprintf(sql,"INSERT INTO news(title,content,created_at) VALUES ('%s','%s','%s')",
    new.title,new.content,new.created_at);

    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}




int update(sqlite3 *db,NEWS new){
    char *err;
    char sql[100];
    sprintf(sql,"UPDATE news SET title = '%s' WHERE id = %d",new.title,new.id);
    if(SQLITE_OK != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int callback(void*para,int col_count,char **col_value,char **col_name){
    // for(int i = o; i < col_count; i++){
    //     printf("%s: %S \n",col_name[i],col_value[i]);
    // }
    printf("%s: %s \n",col_name[1],col_value[2]);
    printf("****************\n");
    return 0;
}


int select (sqlite3 *db){
    char *err;
    char sql[] = "SELETE * FROM news";
    if(0 != sqlite3_exec(db,sql,callback,NULL,&err)) {
        printf("%s\n",err);
    }
    return -1;
}


int delete (sqlite3 *db,int id){
    char *err;
    char sql[100];
    sprintf(sql,"DELETE FROM news WHERE id = %d",id);
    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}


int main()
{
    sqlite3 *db = NULL;
    int res = sqlite3_open("cms.db",&db);
    if(res != 0){
        printf("open db fail\n");
        return -1;
    }


    NEWS new = {0,"今日事件","c语言实操","2019-12-30"};
    insert(db,new);
　
    NEWS new2 = {3,"new title","new content","2019-12-30"};
    update(db,new);

    delete(db,3);
    select(db);

    sqlite3_close(db);
    return 0;

}