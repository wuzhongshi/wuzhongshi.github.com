#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
typedef  struct
{
    int id;
    char *title;
    char *content;
    char *created_at;
} NEWS;


int insert(sqlite3 *db,NEWS new){
    char *err;
    char sql[100];
    new.title = malloc(sizeof(char));
    new.content = malloc(sizeof(char));
    new.created_at= malloc(sizeof(char));
    printf("请输入标题: ");
    scanf("%s",new.title);
    printf("请输出内容:");    
    scanf("%s",new.content);
    printf("请输出时间:");
    scanf("%s",new.created_at);
    // printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",count+1,u.name,u.age,u.sex,u.tel);
    printf("恭喜新增成功\n");

   sprintf(sql,"INSERT INTO news(title,content,created_at) VALUES ('%s','%s','%s')",
    new.title,new.content,new.created_at);

    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
};





int update(sqlite3 *db,NEWS new){
    char *err;
    char sql[100];
    new.title = malloc(sizeof(char));
    new.content = malloc(sizeof(char));
    new.created_at= malloc(sizeof(char));
    printf("请输入需要更新的ID： ");
    scanf("%d",&new.id);
    printf("请输入标题: ");
    scanf("%s",new.title);
    printf("请输出内容:");    
    scanf("%s",new.content);
    printf("请输出时间:");
    scanf("%s",new.created_at);
    // printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",count+1,u.name,u.age,u.sex,u.tel);
    printf("恭喜更新成功\n");

   sprintf(sql,"UPDATE news SET title = '%s',content = '%s',created_at = '%s' WHERE id = %d",new.title,new.content,new.created_at,new.id);
    if(SQLITE_OK != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
};


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
    char sql[] = "SELECT * FROM news";
    if(0 != sqlite3_exec(db,sql,callback,NULL,&err)) {
        printf("%s\n",err);
    }
    return -1;
}




int delete (sqlite3 *db,NEWS new){
    char *err;
    char sql[100];
     printf("请输入需要更新的ID： ");
    scanf("%d",&new.id);
    printf("恭喜删除成功\n");

    sprintf(sql,"DELETE FROM news WHERE id = %d",new.id);
    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}


int menu()
 {
    printf("----主菜单----\n");
    printf("1.新增新闻\n");
    printf("2.查看新闻\n");
    printf("3.删除新闻\n");
    printf("4.修改新闻\n");
    printf("0.退出\n");
    printf("\n");
    printf("请输入: ");
}



// void sel(int count,Member user[])
// {
//     for(int a=0;a<count;a++){
//         if(user[a].id!=0){
//          printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",user[a].id,user[a].name,user[a].age,user[a].sex,user[a].tel);  
//         }
//     }
// }


// void del(int count,Member user[])
// {
//      int x;
//     printf("请您输入需要删除的id：");
//     scanf("%d",&x);
//     for(int i = 0; i < count;i++){
//         if(user[i].id == x){
//             user[i]  = user[i+1];
                        
//         }
//     }
// }


// void modify(int count,Member user[])
// {

//     int j;
//     printf("请您输入需要修改的ID: ");
//     scanf("%d",&j);
//     for(int i = 0;i<count;i++){
//         if(user[i].id==j){
//             printf("请输入您的姓名：");
//             scanf("%s",user[i].name);
//             printf("请输入您的年龄：");
//             scanf("%d",&user[i].age);
//             printf("请输入您的性别：");
//             scanf("%d",&user[i].sex);
//             printf("请输入您的手机号码：");
//             scanf("%d",&user[i].tel);
//             printf("恭喜修改成功\n");
//         }

//     }
// }


 int main(){
    sqlite3 *db = NULL;
    int res = sqlite3_open("cms.db",&db);
    if(res != 0){
        printf("open db fail\n");
        return -1;
    }


     NEWS user[1000];
     int falg = 1;
     int i;
     int count = 0;
     NEWS a;
     while(falg){
        menu();
        scanf("%d",&i);
        switch(i){
            case 1:
               insert(db,user[count]);
                break;
            case 2:
                select(db);
                break;
            case 3:
                delete(db,user[count]);
                break;
            case 4:
               update(db,user[count]);
                break;
            case 0:
                falg = 0;

        }
     }
 }
 