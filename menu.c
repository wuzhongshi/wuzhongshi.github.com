#include <stdio.h>
#include <stdlib.h>
typedef  struct
{
    int id;
    char name[100];
    int age;
    int sex;
    int tel;
} Member;

int i;
int count =0;
Member users[10];

int add(){
    printf("请输入您的姓名：");
    scanf("%s",users[count].name);
    printf("请输入您的年龄：");
    scanf("%d",&users[count].age);
    printf("请输入您的性别：");
    scanf("%d",&users[count].sex);
    printf("请输入您的手机号码：");
    scanf("%d",&users[count].tel);
    printf("恭喜新增成功\n");
    users[count].id = count+1;
    count++;
}
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


 int main()
 {
    int flag = 1;
    int x;
    int j;
     while(flag)
     {
         menu();
         scanf("%d",&i);
        switch(i)
        {
            case 1:
                add();
                break;
            case 2:
                for(int a = 0;a<count;a++){
                    if(users[a].id!=0){
                    printf("id:%d 姓名:%s 年龄:%d 性别%d 电话:%d\n",users[a].id,users[a].name,users[a].age,users[a].sex,users[a].tel);
                    }

                }
                break;
            case 3:
                printf("请您输入需要删除的id：");
                scanf("%d",&x);
                    for(int i = 0; i < count;i++){
                        if(users[i].id == x){
                            users[i]  = users[i+1];
                        
                        }
                    }
                    break;
            case 4:
                printf("请您输入需要修改的ID: ");
                scanf("%d",&j);
                for(int i = 0;i<count;i++){
                    if(users[i].id==j){
                    printf("请输入您的姓名：");
                    scanf("%s",users[i].name);
                    printf("请输入您的年龄：");
                    scanf("%d",&users[i].age);
                    printf("请输入您的性别：");
                    scanf("%d",&users[i].sex);
                    printf("请输入您的手机号码：");
                    scanf("%d",&users[i].tel);
                    printf("恭喜修改成功\n");
                    }

                }
                break;
            case 0:
                flag = 0;
        }
    }        

}     
 