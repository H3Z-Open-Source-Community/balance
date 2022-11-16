#include<iostream>
#include<cstring>
using namespace std;
int reanum,pronum;//反应物和生成物数量
int at_totnum=1;
int deter[40][40];//行列式
int judge(char m)
{
    if(m<=90&&m>=65)
        return 1;//大写
    else if(m<=122&&m>=97)
        return 2;//小写
    else if(m<=57&&m>=48)
        return 3;//数字
    else if(m=='(')
        return 4;
    else if(m==')')
        return 5;
    else
        return 114514+1919810;
}
int bucket[40][30][30]={0};//使用桶进行元素判重
int listx[40],listy[40];
struct matter//定义每一个化合物为结构体(这里的化合物)
{
    string name;
    string at_name[20];
    int at_num[20];
    int beg,end;
    bool if_bra;//是否存在括号
    int bra_num;
    int at_rank;//元素排行榜
};
matter rea[21];//反应物reactant
matter pro[21];//生成物product
int main()
{
    cin>>reanum;
    for(int i=1;i<=reanum;i++)
    {
        cin>>rea[i].name;
    }
    cin>>pronum;
    for(int i=1;i<=pronum;i++)
    {
        cin>>pro[i].name;
    }
    for(int r=1;r<=reanum;r++)//对反应物进行处理
    {
        rea[r].if_bra=false;
        rea[r].at_rank=1;
        rea[r].name+=')';
        int len=rea[r].name.size();
        for(int i=0;i<len;i++)//记录物质中的元素名称
        {
            if(judge(rea[r].name[i])==1)
            {
                if(judge(rea[r].name[i+1])!=2)//如果下一位不是小写字母
                {
                    rea[r].at_name[rea[r].at_rank]+=rea[r].name[i];
                    rea[r].at_rank++;
                }
                if(judge(rea[r].name[i+1])==2)
                {
                   rea[r].at_name[rea[r].at_rank]+=rea[r].name[i];
                   rea[r].at_name[rea[r].at_rank]+=rea[r].name[i+1];
                   i++;
                   rea[r].at_rank++;
               }
            }
        }
        rea[r].at_rank=1;//初始化
        for(int i=0;i<len;i++)//记录每个元素的个数
        {
            if(judge(rea[r].name[i])==1)
            {
                if(judge(rea[r].name[i+1])==1||judge(rea[r].name[i+1])==4||judge(rea[r].name[i+1])==5)//如果下一位也是大写字母或者前括号或者后括号
                {
                    rea[r].at_num[rea[r].at_rank]=1;
                    rea[r].at_rank++;
                    continue;
                }
                if(judge(rea[r].name[i+1])==3)//如果是数字
                {
                    if(judge(rea[r].name[i+2])!=3)//如果该数字只有一位
                    {
                        rea[r].at_num[rea[r].at_rank]=int(rea[r].name[i+1])-48;
                        rea[r].at_rank++;
                        continue;
                    }
                    if(judge(rea[r].name[i+2])==3)//如果该数字有两位
                    {
                        rea[r].at_num[rea[r].at_rank]=(int(rea[r].name[i+1])-48)*10+int(rea[r].name[i+2])-48;
                        i++;
                        rea[r].at_rank++;
                        continue;
                    }
                }
                if(judge(rea[r].name[i+1])==2)//如果下一位是小写字母
                {
                    if(judge(rea[r].name[i+2])==1||judge(rea[r].name[i+2])==4||judge(rea[r].name[i+2])==5)
                    {
                        rea[r].at_num[rea[r].at_rank]=1;
                        rea[r].at_rank++;
                        i++;
                        continue;
                    }
                    if(judge(rea[r].name[i+2])==3)
                    {
                        if(judge(rea[r].name[i+3])!=3)
                        {
                            rea[r].at_num[rea[r].at_rank]=int(rea[r].name[i+2])-48;
                            rea[r].at_rank++;
                            i++;
                            continue;
                        }
                        if(judge(rea[r].name[i+3])==3)
                        {
                            rea[r].at_num[rea[r].at_rank]=(int(rea[r].name[i+2])-48)*10+int(rea[r].name[i+3])-48;
                            rea[r].at_rank++;
                            i+=2;
                            continue;
                        }
                    }
                }
            }
            if(judge(rea[r].name[i])==4)//如果是前括号
            {
                rea[r].beg=rea[r].at_rank;
                rea[r].if_bra=true;
            }
            if(judge(rea[r].name[i])==5&&i!=len-1)
            {
                rea[r].end=rea[r].at_rank-1;
                if(judge(rea[r].name[i+2])!=3)
                    rea[r].bra_num=int(rea[r].name[i+1])-48;
                else
                {
                    rea[r].bra_num=(int(rea[r].name[i+1])-48)*10+int(rea[r].name[i+2])-48;
                }
            }
        }
        if(rea[r].if_bra==true)//将括号中的元素数乘上括号数
        {
            for(int i=rea[r].beg;i<=rea[r].end;i++)
            {
                rea[r].at_num[i]=rea[r].at_num[i]*rea[r].bra_num;
            }
        }
        len--;
    }
    for(int r=1;r<=pronum;r++)//对生成物进行处理
    {
        pro[r].name+=')';
        pro[r].at_rank=1;
        int len=pro[r].name.size();
        for(int i=0;i<len;i++)//记录物质中的元素名称
        {
            if(judge(pro[r].name[i])==1)
            {
                if(judge(pro[r].name[i+1])!=2)//如果下一位不是小写字母
                {
                    pro[r].at_name[pro[r].at_rank]+=pro[r].name[i];
                    pro[r].at_rank++;
                }
                if(judge(pro[r].name[i+1])==2)
                {
                    pro[r].at_name[pro[r].at_rank]+=pro[r].name[i];
                    pro[r].at_name[pro[r].at_rank]+=pro[r].name[i+1];
                    i++;
                    pro[r].at_rank++;
                }
            }
        }
        pro[r].at_rank=1;//初始化
        for(int i=0;i<len;i++)//记录每个元素的个数
        {
            if(judge(pro[r].name[i])==1)
            {
                if(judge(pro[r].name[i+1])==1||judge(pro[r].name[i+1])==4||judge(pro[r].name[i+1])==5)//如果下一位也是大写字母或者前括号或者后括号
                {
                    pro[r].at_num[pro[r].at_rank]=1;
                    pro[r].at_rank++;
                    continue;
                }
                if(judge(pro[r].name[i+1])==3)//如果是数字
                {
                    if(judge(pro[r].name[i+2])!=3)//如果该数字只有一位
                    {
                        pro[r].at_num[pro[r].at_rank]=int(pro[r].name[i+1])-48;
                        pro[r].at_rank++;
                        continue;
                    }
                    if(judge(pro[r].name[i+2])==3)//如果该数字有两位
                    {
                        pro[r].at_num[pro[r].at_rank]=(int(pro[r].name[i+1])-48)*10+int(pro[r].name[i+2])-48;
                        i++;
                        pro[r].at_rank++;
                        continue;
                    }
                }
                if(judge(pro[r].name[i+1])==2)//如果下一位是小写字母
                {
                    if(judge(pro[r].name[i+2])==1||judge(pro[r].name[i+2])==4||judge(pro[r].name[i+2])==5)
                    {
                        pro[r].at_num[pro[r].at_rank]=1;
                        pro[r].at_rank++;
                        i++;
                        continue;
                    }
                    if(judge(pro[r].name[i+2])==3)
                    {
                        if(judge(pro[r].name[i+3])!=3)
                        {
                            pro[r].at_num[pro[r].at_rank]=int(pro[r].name[i+2])-48;
                            pro[r].at_rank++;
                            i++;
                            continue;
                        }
                        if(judge(pro[r].name[i+3])==3)
                        {
                            pro[r].at_num[pro[r].at_rank]=(int(pro[r].name[i+2])-48)*10+int(pro[r].name[i+3])-48;
                            pro[r].at_rank++;
                            i+=2;
                            continue;
                        }
                    }
                }
            }
            if(judge(pro[r].name[i])==4)//如果是前括号
            {
                pro[r].beg=pro[r].at_rank;
                pro[r].if_bra=true;
            }
            if(judge(pro[r].name[i])==5&&i!=len-1)
            {
                pro[r].end=pro[r].at_rank-1;
                if(judge(pro[r].name[i+2])!=3)
                    pro[r].bra_num=int(pro[r].name[i+1])-48;
                else
                {
                    pro[r].bra_num=(int(pro[r].name[i+1])-48)*10+int(pro[r].name[i+2])-48;
                }
            }
        }
        if(pro[r].if_bra==true)//将括号中的元素数乘上括号数
        {
            for(int i=pro[r].beg;i<=pro[r].end;i++)
            {
                pro[r].at_num[i]=pro[r].at_num[i]*pro[r].bra_num;
            }
        }
    }
    for(int i=1;i<=reanum;i++)//处理反应物
    {
        for(int j=1;j<=rea[i].at_rank-1;j++)//将每一个元素存入桶中
        {
            if(rea[i].at_name[j].size()==1)
            {
                bucket[i][rea[i].at_name[j][0]-'A'+1][0]+=rea[i].at_num[j];
                bool if_rep=false;
                for(int k=1;k<=j;k++)//循环判重
                {
                    if(listx[k]==rea[i].at_name[j][0]-'A'+1&&listy[k]==0)//若发现重复
                    {
                        if_rep=true;
                        break;
                    }
                }
                if(if_rep==false)//若不重复，则将元素存入list中
                {
                    listx[at_totnum]=rea[i].at_name[j][0]-'A'+1;
                    listy[at_totnum]=0;
                    at_totnum++;
                }
            }
            else if(rea[i].at_name[j].size()==2)
            {
                bucket[i][rea[i].at_name[j][0]-'A'+1][rea[i].at_name[j][1]-'a'+1]+=rea[i].at_num[j];
                bool if_rep=false;
                for(int k=1;k<=j;k++)
                {
                    if(listx[k]==rea[i].at_name[j][0]-'A'+1&&listy[k]==rea[i].at_name[j][1]-'a'+1)
                    {
                        if_rep=true;
                        break;
                    }
                }
                if(if_rep==false)
                {
                    listx[at_totnum]=rea[i].at_name[j][0]-'A'+1;
                    listy[at_totnum]=rea[i].at_name[j][1]-'a'+1;
                    at_totnum++;
                }
            }
        }
    }
    for(int i=1;i<=pronum;i++)//处理生成物
    {
        for(int j=1;j<=pro[i].at_rank-1;j++)//将每一个元素存入桶中
        {
            if(pro[i].at_name[j].size()==1)
            {
                bucket[i+reanum][pro[i].at_name[j][0]-'A'+1][0]+=pro[i].at_num[j];
            }
            else if(pro[i].at_name[j].size()==2)
            {
                bucket[i+reanum][pro[i].at_name[j][0]-'A'+1][pro[i].at_name[j][1]-'a'+1]+=pro[i].at_num[j];
            }
        }
    }
    at_totnum=at_totnum-1;
    for(int i=1;i<=reanum;i++)//将bucket中数据整理到deter中
    {
        for(int j=1;j<=at_totnum;j++)
        {
            deter[j][i]=bucket[i][listx[j]][listy[j]];
        }
    }
    for(int i=reanum+1;i<=reanum+pronum;i++)
    {
        for(int j=1;j<=at_totnum;j++)
        {
            deter[j][i]=-1*bucket[i][listx[j]][listy[j]];
        }
    }
}   
