#include <stdio.h>
int h[1001][1001];
int temp[1001][1001];
int main()
{
    int n,m,r,i,j,k,l,high,low,count,mid,p,q;
    scanf("%d%d%d",&n,&m,&r);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    scanf("%d",&h[i][j]);
    for(i=0;i<r;i++) {
        scanf("%d%d",&k,&l);
        low = 0;
        high=10e7;
        count = k*l/2+1;
        k--;
        l--;
        while(low<high) {
            mid=(low+high+1)/2;
            for(p=1;p<=n;p++){
                for(q=1;q<=m;q++){
                    temp[p][q]=temp[p-1][q]+temp[p][q-1]-temp[p-1][q-1]+(h[p][q]>=mid?1:0);
                }
            }
            int found = 1;
            for(p=1;(p+k)<=n;p++){
                for(q=1;(q+l)<=m;q++){
                    if((temp[p+k][q+l]-temp[p-1][q+l]-temp[p+k][q-1]+temp[p-1][q-1])>=count)
                    {
                        low=mid;
                        found=0;
                        break;
                    }
                }
                if(!found)break;
            }
            if(found)high=mid-1;
        }
        printf("%d\n",low);
    }
    return 0;
}
