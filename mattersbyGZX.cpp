#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
const int maxn=15;
string tmp_ele_name,ele_kinds[maxn],names[maxn*2];
int in_num,out_num,mat_len,brac_times,times,kinds;
int deter[maxn][maxn],col,line;
struct matters
{
    string name;
    unordered_map<string,int> elements;
}in_matter[maxn],out_matter[maxn];
int judge(char given)
{
    if(given>='A'&&given<='Z')
    return 1;
    if(given>='a'&&given<='z')
    return 2;
    if(given>='0'&&given<='9')
    return 3;
    return 4;
}
bool exist(string given)
{
    for (int i=1;i<=kinds;i++)
        if (ele_kinds[i]==given) 
            return true;
    return false;
}
int main()
{
    cin>>in_num;
    for(int i=1;i<=in_num;i++)
        cin>>in_matter[i].name;
    cin>>out_num;
    for(int i=1;i<=out_num;i++)
        cin>>out_matter[i].name;
    for(int i=1;i<=in_num;i ++)
    {
        mat_len=in_matter[i].name.length();
        for (int j=0;j<mat_len;j++)
        {
            if (judge(in_matter[i].name[j])==1)
            {
                if (j!=0)
                {
                    in_matter[i].elements[tmp_ele_name]+=times;
                    if (!exist(tmp_ele_name)) 
                        ele_kinds[++kinds]=tmp_ele_name;
                }
                tmp_ele_name=in_matter[i].name[j];
                times=1;
                if(brac_times)
                    times*=brac_times;
            }
            else if(judge(in_matter[i].name[j])==2)
            {
                tmp_ele_name+=in_matter[i].name[j];
            }
            else if(judge(in_matter[i].name[j])==3) 
            {
                if(in_matter[i].name[j-1]==')')
                    continue;
                if(judge(in_matter[i].name[j-1])==3)
                {
                    times*=10;
                    times+=(int)(in_matter[i].name[j]-'0');
                }
                else
                    times=(int)(in_matter[i].name[j]-'0');
                if (brac_times)
                    times*=brac_times;
            }
            else 
            {
                if(in_matter[i].name[j]=='(')
                {
                    int flag=j+1;
                    while (in_matter[i].name[flag]!=')')
                        flag ++;
                    flag++; 
                    if(judge(in_matter[i].name[flag-1])==3)
                    {
                        brac_times*=10;
                        brac_times+=(int)(in_matter[i].name[flag] - '0');
                    }
                    else
                    brac_times=(int)(in_matter[i].name[flag]-'0');
                }
                else
                brac_times=0;
            }
        }
        in_matter[i].elements[tmp_ele_name]+=times;
        if(!exist(tmp_ele_name)) 
            ele_kinds[++ kinds]=tmp_ele_name;
    }
    for(int i=1;i<=out_num;i++)
    {
        mat_len=out_matter[i].name.length();
        for (int j=0;j<mat_len;j ++)
        {
            if (judge(out_matter[i].name[j])==1)
            {
                if (j!=0)
                {
                    out_matter[i].elements[tmp_ele_name]+=times;
                    if (!exist(tmp_ele_name)) 
                        ele_kinds[++ kinds]=tmp_ele_name;
                }
                tmp_ele_name=out_matter[i].name[j];
                times = 1;
                if (brac_times)
                    times*=brac_times;
            }
            else if(judge(out_matter[i].name[j]) == 2)
            {
                tmp_ele_name+=out_matter[i].name[j];
            }
            else if(judge(out_matter[i].name[j])==3)
            {
                if(out_matter[i].name[j-1]==')')
                    continue;
                if(judge(out_matter[i].name[j-1])==3)
                {
                    times*=10;
                    times+=(int)(out_matter[i].name[j]-'0');
                }
                else
                    times=(int)(out_matter[i].name[j]-'0');
                if(brac_times)
                    times*=brac_times;
            }
            else 
            {
                if(out_matter[i].name[j]=='(')
                {
                    int flag=j+1;
                    while(out_matter[i].name[flag]!=')')
                        flag++;
                    flag++; 
                    if(judge(out_matter[i].name[flag-1])==3)
                    {
                        brac_times*=10;
                        brac_times+=(int)(out_matter[i].name[flag]-'0');
                    }
                    else
                        brac_times=(int)(out_matter[i].name[flag]-'0');
                }
                else
                    brac_times=0;
            }
        }
        out_matter[i].elements[tmp_ele_name]+=times;
        if (!exist(tmp_ele_name))
            ele_kinds[++ kinds]=tmp_ele_name;
    }
    col=kinds;
    line=in_num+out_num;
    for (int i=1;i<=kinds;i++)
    {
        for(int j=1;j<=in_num;j++)
            deter[i][j]=in_matter[j].elements[ele_kinds[i]];
        for(int j=1;j<=out_num;j++)
            deter[i][in_num+j]=0-out_matter[j].elements[ele_kinds[i]];
    }
    for(int i=1;i<=in_num;i++)
        names[i]=in_matter[i].name;
    for (int i=1;i<=out_num;i++)
        names[in_num+i]=out_matter[i].name;
    // 下面是输出，大佬可以这部分删掉换成行列式处理的代码
    // 行列式用二维数组deter存储，化学式用names存储
    for(int i=1;i<=line;i++)
        cout<<names[i]<<' ';
    cout<<endl;
    for(int i=1;i<=col;i++)
    {
        for(int j=1;j<=line;j++)
        {
            cout<<deter[i][j]<<' ';
        }
        cout<<endl;
    }
    // Your code goes here
}
