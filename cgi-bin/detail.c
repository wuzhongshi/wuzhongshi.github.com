#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int callback(void *para,int col_count,char **col_value,char **col_name){
    printf("<div class='item'>");
    printf("<div class='title'>%s</div>\n",col_value[1]);
    printf("<div class='time'>%s</div>\n",col_value[3]);

    printf("<div class='content'>%s</div>\n",col_value[2]);
    printf("</div>\n");

    return  0;
}



int select(sqlite3 *db){
    char *id = getenv("QUERY_STRING");
    char *err;
    char sql[100];;
    sprintf(sql,"SELECT * FROM news WHERE id=%d",atoi(id));
    // sqlite3(sql,"SELECT * FROM news WHERE id =2");
     if(0 != sqlite3_exec(db,sql,callback,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

int main(){
    printf("Content-Type:text/html\n\n");
    char *header = "<!doctype html>"\
                    "<html>"\
                    "<head>"\
                    "<meta charset='UTF-8'>"\
                    "<title>新闻中心</title>"\
                    "</head>"\
                    "<body>";
     printf("%s\n",header);
      printf("<style>"
            "a{color:#333;}"\
            "</style>");
    printf("<style>"
            "a{color:red;font-size:30px;text-decoration: none;}"\
            "</style>");
    printf("<style>"
            "ul{width:500px;height:450px;background-color:LightCyan;margin: 0 auto;}"\
            "</style>"
                    );
    printf("<style>"
            ".title{list-style:none;margin:10px;font-size:34px;color:red;}"\
            "</style>"
                    );
    printf("<div style='width:600px;height:500px;color:black;background-color:pink;text-align:center;font-size:30px;'></div>");

    sqlite3 *db  = NULL;
    int res = sqlite3_open("cms.db",&db);
    if (res != 0)
    {
        printf("open db fail\n");
        return -1;

    }
    select(db);
    sqlite3_close(db);
    printf("</body></html>");
    return 0;
}