#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int Permutation()
{
    char result[100]="\0",temp[10],output[100]="\0";
    int key[100];
    cout<<"请输入明文:";
    cin>>result;
    gets(temp);
    int l=strlen(result);
    int len=l;
    for(int i=0;i<l;i++)
    {
        if(result[i]<'a'||result[i]>'z')
        {
            printf("请输入小写字符串\n");
            return 0;
        }
    }
    cout<<"明文长度是:"<<l<<endl;
    cout<<"请输入密钥，要求是5位数字"<<endl;
    for(int j=0;j<4;j++)
        scanf("%d,",&key[j]);
    scanf("%d",&key[4]);
    for(;l%5!=0;l++)
    {
        result[l]='x';
    }
    for(int i=0;i<l;i++)
    {
        output[i/5*5+key[i%5]]=result[i]+'A'-'a';
    }
    printf("输出密文:%s\n解密后明文:",output);
    for(int i=0;i<l;i++)
    {
        result[i]=output[i/5*5+key[i%5]]+'a'-'A';
    }
    for(int i=0;i<len;i++)
        printf("%c",result[i]);
    printf("\n");

}

int shift()
{
    int k=0;
    int choose;
    char result[20];
    cout<<"***** please choose *****"<<endl;
    cout << "移位加密——0，解密——1："<<endl;
    cin>>choose;
    if(choose!=0&&choose!=1)
    {
        cout<<"0/1,no other choice!"<<endl;
        return 0;
    }
    cout<<"请设置密钥（1<=k<=25），k=" << endl;
    cin>>k;
    if(k>25||k<1)
    {
        cout<<"要求输入[1,25]范围内的数字！\n"<<endl;
        return 0;
    }
    cout<<"请输入明文（加密）/密文（解密）：\n"<<endl;
    cin>>result;
    //cout<<result;
    if(choose==0)
        for(int i=0;i<strlen(result);i++)
        {
            //cout<<result[i];
            if(result[i]<'a'||result[i]>'z')
            {
                cout<<"请输入小写字符串"<<endl;
                return 0;
            }
            result[i]-='a';
            result[i]=result[i]+k;
            if(result[i]>26)
                result[i]-=26;
            result[i]+='A';
        }
    else if(choose==1)
        for(int i=0;i<strlen(result);i++)
        {
            if(result[i]<'A'||result[i]>'Z')
            {
                cout<<"请输入大写字符串"<<endl;
                return 0;
            }
            //cout<<result[i];
            result[i]-='A';
            result[i]=result[i]-k;
            if(result[i]<0)
                result[i]+=26;
            result[i]+='a';
        }
    cout<<result;
    return 0;
}
int vigenere()
{
    char choose=' ';
    char result[100]="\0",c[100]="\0";
    char key[100],temp[100];
    bool flag;
    gets(temp);
    while(true)
    {
        cout<<"***** please choose *****"<<endl;
        cout << "input:v(begin)/h(help)/e(exit):"<<endl;
        scanf("%c",&choose);
        gets(temp);
        if(choose=='e')
        {
            cout<<"EXIT!";
            return 0;
        }
        else if(choose=='h')
        {
            cout<<"Vigenere密码加密算法： ek(x1, x2,…, xm)=(x1+k1, x2+k2,…, xm+ km)"<<endl;
            cout<<"Vigenere密码解密算法： dk(y1, y2,…, ym)=(y1-k1, y2-k2,…, ym- km)"<<endl;
        }
        else if(choose=='v')
        {
            cout<<"请设置密钥:" << endl;
            while(true)
            {
                flag=true;
                cin>>key;
                gets(temp);
                for(int i=0;i<strlen(key);i++)
                {
                    if(key[i]>'z'||key[i]<'a')
                    {
                        cout<<"请输入小写串——"<<endl;
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                    break;
            }
            int l=strlen(key);
            while(true)
            {
                flag=true;
                cout<<"请输入明文:"<<endl;
                cin>>result;
                gets(temp);
                for(int i=0;i<strlen(result);i++)
                {
                    if(result[i]<'a'||result[i]>'z')
                    {
                        cout<<"请输小写串——"<<endl;
                        flag=false;
                        break;
                    }
                    result[i]-='a';
                    result[i]=result[i]+(key[i%l]-'a');
                    if(result[i]>26)
                        result[i]-=26;
                    result[i]+='A';
                    c[i]=result[i]-'A';
                    c[i]=c[i]-(key[i%l]-'a');
                    if(c[i]<0)
                        c[i]+=26;
                    c[i]+='a';
                }
                if(flag==false)
                    continue;
                break;
            }
            cout<<result<<endl;
            cout<<c<<endl;
        }
        else
        {
            //cout<<choose<<endl;
            cout<<"invalid input!"<<endl;
        }
        gets(temp);
    }
}

int affine()
{
    int k1,k2,k3;
    char result[100],output[100]="\0";
    printf("输入密钥k1:");
    scanf("%d",&k1);
    if(k1<=0||k1>=26)
    {
        printf("要求k的取值范围是0到26(不含边界值)\n");
        return 0;
    }
    if(k1%2==0||k1%13==0)
    {
        printf("要求k1与26互素\n");
        return 0;
    }
    printf("输入密钥k2:");
    scanf("%d",&k2);
    if(k2<=0||k2>=26)
    {
        printf("要求k的取值范围是0到26(不含边界值)\n");
        return 0;
    }
    printf("输入明文:");
    cin>>result;
    int l=strlen(result);
    for(int i=0;i<l;i++)
    {
        if(result[i]<'a'||result[i]>'z')
        {
            printf("请输入小写字符串\n");
            return 0;
        }
    }
    for(int i=0;i<l;i++)
    {
        output[i]=((k1)*(result[i]-'a')+k2)%26+'A';
    }
    printf("输出密文%s\n",output);
    for(k3=0;k3<26;k3++)
        if((k3*k1)%26==1)
        break;
    printf("输出解密密钥:k1=%d,k2=%d\n",k3,k2);
    for(int i=0;i<l;i++)
    {
        result[i]=(k3*((output[i]-'A')-k2)+26)%26+'a';
    }
    printf("解密后的明文:%s\n",result);
}

int main()
{
    int choose;
    printf("#menu#\n1.permutation;\n2.shift;\n3.vigenere;\n4.affine;\nplease choose:");
    scanf("%d",&choose);
    if(choose==1)
        Permutation();
    else if(choose==2)
        shift();
    else if(choose==3)
        vigenere();
    else if(choose==4)
        affine();
    else
    {
        printf("error choice!\n");
        return 0;
    }
}
