#include <stdio.h>
#include <stdlib.h>
typedef  struct
{
    int id;
    char *name;
    int age;
    int sex;
    int tel;
} Member;
Member add() {
    Member u;
    u.name = malloc(sizeof(char));
    printf("请输入名字: ");
    scanf("%s",u.name);
    printf("请输出您的年龄:");    
    scanf("%d",&u.age);
    printf("请输出您的电话:");
    scanf("%d",&u.tel);
    printf("请输出您的性别:");
    scanf("%d",&u.sex);
    // printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",count+1,u.name,u.age,u.sex,u.tel);
    printf("恭喜新增成功\n");
    return u;
};

int menu()
 {
    printf("----主菜单----\n");
    printf("1.新增会员\n");
    printf("2.查看会员\n");
    printf("3.删除会员\n");
    printf("4.修改会员\n");
    printf("0.退出\n");
    printf("\n");
    printf("请输入: ");
}



void sel(int count,Member user[])
{
    for(int a=0;a<count;a++){
        if(user[a].id!=0){
         printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",user[a].id,user[a].name,user[a].age,user[a].sex,user[a].tel);  
        }
    }
}


void del(int count,Member user[])
{
     int x;
    printf("请您输入需要删除的id：");
    scanf("%d",&x);
    for(int i = 0; i < count;i++){
        if(user[i].id == x){
            user[i]  = user[i+1];
                        
        }
    }
}


void modify(int count,Member user[])
{

    int j;
    printf("请您输入需要修改的ID: ");
    scanf("%d",&j);
    for(int i = 0;i<count;i++){
        if(user[i].id==j){
            printf("请输入您的姓名：");
            scanf("%s",user[i].name);
            printf("请输入您的年龄：");
            scanf("%d",&user[i].age);
            printf("请输入您的性别：");
            scanf("%d",&user[i].sex);
            printf("请输入您的手机号码：");
            scanf("%d",&user[i].tel);
            printf("恭喜修改成功\n");
        }

    }
}


 int main(){
     int falg = 1;
     int i;
     int count = 0;
     Member a;
     Member user[1000];
     while(falg){
        menu();
        scanf("%d",&i);
        switch(i){
            case 1:
               a = add();
                user[count].id = count+1;
                user[count].name = a.name;
                user[count].age = a.age;
                user[count].sex = a.sex;
                user[count].tel = a.tel;
                count++;
                break;
            case 2:
                sel(count,user);
                break;

            case 3:
                del(count,user);
                break;
            case 4:
                modify(count,user);
                break;
            case 0:
                falg = 0;

        }
     }
 }
 