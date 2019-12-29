#include <stdio.h>
int main()
{
    int i,n,max=-9999999,min=9999999999,a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&a[i]);
        if(a[i]>max)max=a[i];
        if(a[i]<min)min=a[i];
    }
    printf("最大值是：%d\最小值是：%d\n",max,min);
    return 0;
}
