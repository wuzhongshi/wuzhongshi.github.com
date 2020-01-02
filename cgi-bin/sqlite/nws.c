#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct{
    int id;
    char *title;
    char *content;
    char *created_at;
}news;

int insert(sqlite3 *db,news new){
    char *err;
    char sql[100];
    sqlite(sql,"INSERT INTO news(title,content,created_at) VALUEAS ('%s','%s','%s')",
    new.title,new.content,new.created_at);

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

    news new = {0,"今日事件","c语言实操","2019-12-30"};
    insert(db,new);
    news new2 = {3,"new title","new content","2019-12-30"};
    sqlite3_close(db);
    return 0;

}