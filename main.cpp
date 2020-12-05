#include<iostream>
#include<stdio.h>
using namespace std;
class car
{
private:
    int phone=0;
    char carNo[5]={'error'};
    public:
        car()
        {

        }
        car(const car& Car)
        {
            phone=Car.phone;
            for(int i=0;i<5;i++)
            {
             carNo[i]=Car.carNo[i];
            }
        }
    car(int phone1,char carNO1[])
    {
        phone=phone1;
       for(int i=0;i<5;i++)
       {
           carNo[i]=carNO1[i];
       }
    }
    int getphone()
    {
        return phone;
    }
    char *getcar()
    {
        return carNo;
    }
};
class sqstack
{
protected:
    int count=0;
    int maxsize=5;
    car elems[5];

public:
    int price=0;
    bool findcar(int Car)
    {
        for(int i=0;i<count;i++)
        {
            if(elems[i].getphone()==Car)
                return true;
        }
        return false;
    }
    bool full()
    {
        return count==maxsize;
    }
    Setp(int a)
    {
        price=a;
    }
    sqstack()
    {

    }
    int length()
    {
        return count;
    }
    bool Empty()
    {
        return count==0;
    }
        bool Push(car &e)
        {
            if(count==maxsize)
                return false;
            else
            {
             elems[count++]=e;
             return true;
            }
        }

        bool Pop(car &e)
        {
            if(Empty())
                return false;
            else{

                e=elems[count-1];
                count--;
                return true;
            }
        }
        void clean()
        {
            count=0;
        }
};
class Queue
{
protected:
    int front,rear;
    int count;
    int maxsize=10;
    car elem[10];
public:
    Queue()
    {
        rear=front=0;
        count=0;
    }
    int Length()
    {
        return count;
    }
    bool Empty()
    {
        return count==0;
    }
    bool outq(car &e)
    {
        if(!Empty())
        {
            e=elem[front];
            front=(front+1)%maxsize;
            count--;
            return true;

        }
        else
            return false;
    }
    bool inq(car &e)
    {
        if(count==maxsize)
        {
            return false;
        }
        else
        {
            elem[rear]=e;
            rear=(rear+1)%maxsize;
            count++;
            return true;
        }
    }
};
class Net
{
protected:

    int vNUm=6,eNum=5;
    int matrix[6][6];
    mutable bool tag[6];
    int infinity=9999;

    public:
         sqstack q0[6];
    sqstack q;//暂存
    Queue que[6];
    Net()
    {int money=6;
        for(int i=0;i<6;i++)
        {q0[i].Setp(money);
        money--;
            for(int j=0;j<6;j++)
            {
                matrix[i][j]=infinity;
            }
        }
        matrix[0][1]=10;
         matrix[0][2]=5;
          matrix[0][4]=20;
           matrix[2][3]=25;
            matrix[4][5]=15;


    };
    int getinfinity()
    {
        return infinity;
    }
    int getvNum()
    {
        return vNUm;
    };
    int firstV(int v)
    {
        for(int i=0;i<6;i++)
        {
            if(matrix[v][i]<infinity)
                return i;
                else if(i==5)
                    return -1;
        }

    }
    int nextV(int v1,int v2)
    {
        for(int i=v2+1;i<6;i++)
        {
            if(matrix[v1][i]<infinity)
                return i;
                else if(i==5)
                    return -1;
        }
        return -1;
    }
    int getweight(int v1,int v2)
    {

           // return matrix[v2-1][v1-1];
        return matrix[v1][v2];
    }
    bool gettag(int v)
    {
        return tag[v];
    }
    void settag(int v,bool val)
    {
        tag[v]=val;
    }

};
void shortpath( Net& net,int v0,int *path,int *dist)
{
    for( int v=0;v<net.getvNum();v++)
    {

        dist[v]=(v==v0)?0:net.getweight(v0,v);
        if(v0!=v&&dist[v]<net.getinfinity())
            path[v]=v0;
        else
            path[v]=-1;
        net.settag(v,false);
    }
    net.settag(v0,true);
    for(int u=1;u<net.getvNum();u++)//error!
    {
        int minval=net.getinfinity();
        int v1=v0;
        for(int w=0;w<net.getvNum();w++)
        {
            if(!net.gettag(w)&&dist[w]<minval)
               {

               v1=w;
            minval=dist[w];
            }
        }
        net.settag(v1,true);

        for(int v2=net.firstV(v1);v2!=-1;v2=net.nextV(v1,v2))
        {
            if(!net.gettag(v2)&&minval+net.getweight(v1,v2)<dist[v2])
            {
                dist[v2]=minval+net.getweight(v1,v2);
                path[v2]=v1;
            }
        }
    }
}
int Partition(int elem[],int low,int high)
{
    while(low<high)
    {
        while(low<high&&elem[high]>=elem[low])
        {
            high--;
        }
        swap(elem[low],elem[high]);
        while(low<high&&elem[low]<=elem[high])
        {
            low++;
        }
        swap(elem[low],elem[high]);
    }
    return low;
}
void help(int elem[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(elem,low,high);
        help(elem,low,pivot-1);
        help(elem,pivot+1,high);
    }
}
void Sort(int elem[],int n)
{
    help(elem,0,n-1);
}
 void run()
 {
     Net a;
   char name1[5]={'a','b','c','d','e'};
   char name2[5]={'a','b','c','d','f'};
   char name3[5]={'a','b','c','d','g'};
   char name4[5]={'a','b','c','d','h'};
   char name5[5]={'a','b','c','d','j'};
   char name6[5]={'a','s','f','g','d'};

  car c1(12345,name1);
   car c2(12346,name2);
    car c3(12347,name3);
     car c4(12348,name4);
      car c5(12349,name5);
      car c6(12398,name6);
      a.q0[0].Push(c1);
      a.q0[0].Push(c2);
      a.q0[0].Push(c3);
      a.q0[0].Push(c4);
      a.q0[0].Push(c5);
      a.q0[1].Push(c6);
      cout<<"欢迎光临停车场"<<endl;
      while(1)
      {
          cout<<"1.停车"<<endl;
          cout<<"2.取车"<<endl;
          int number1;
          cin>>number1;
          if(number1==1)
          {
int path[10]={0};
int dist[10]={0};
int dist1[10]={0};
shortpath(a,0,path,dist);
int price[10]={0},price0[10]={0};
for(int i=0;i<6;i++)
{
    dist1[i]=dist[i];
    price[i]=a.q0[i].price;
    price0[i]=price[i];
}
Sort(price,6);
Sort(dist1,6);
cout<<"1.按价格排序"<<endl;
cout<<"2.按距离排序"<<endl;
cout<<"3.正常排序"<<endl;
int number5;
cin>>number5;
if(number5==2)
{


for(int i=0;i<6;i++)
{int j=0;
    for(j=0;j<6;j++)
    {
        if(dist1[i]==dist[j])
            break;
    }

   cout<<"第"<<j+1<<"号停车场距离为："<<dist[j]<<endl;
}
}
else if(number5==1)
{


for(int i=0;i<6;i++)
{int j=0;
    for(j=0;j<6;j++)
    {
        if(price[i]==price0[j])
            break;
    }

   cout<<"第"<<j+1<<"号停车场价格为："<<price0[j]<<endl;
}
}
else if(number5==3)
{
    for(int i=0;i<6;i++){
    cout<<"第"<<i+1<<"号停车场距离为："<<dist[i]<<endl;
     cout<<"第"<<i+1<<"号停车场价格为："<<price0[i]<<endl;
    }
}
else
{cout<<"输入错误！"<<endl;
continue;}
cout<<"请选择停车场编号1-6"<<endl;
int number;
cin>>number;
if(number<1||number>6)
{cout<<"输入错误！"<<endl;
continue;}
else if(a.q0[number-1].full())
{
    cout<<"此停车场已满！请选择其他停车场或等待"<<endl;
    cout<<"1.离开"<<endl;
    cout<<"2.继续选择"<<endl;
    cout<<"3.等待"<<endl;
    int m;
    cin>>m;
    if(m==1)
    {

        cout<<"欢迎下次光临!"<<endl;
        continue;
    }

    else if(m==2)
        continue;
    else if(m==3)
    {
     cout<<"请输入手机号:"<<endl;
    int phone0;
    cin>>phone0;
    char car0[5];
    cout<<"请输入五位车牌号:"<<endl;
    cin>>car0;
    car person(phone0,car0);
    a.que[number-1].inq(person);
    }
    else
    {
        cout<<"输入错误！"<<endl;
        continue;
    }
    }
else
{
    cout<<"请输入手机号:"<<endl;
    int phone0;
    cin>>phone0;
    char car0[5];
    cout<<"请输入五位车牌号:"<<endl;
    cin>>car0;
    car person(phone0,car0);
    a.q0[number-1].Push(person);
    cout<<"您选择的停车场价格为:"<<a.q0[number-1].price<<endl;
    cout<<"距离为："<<dist[number-1]<<endl;
    cout<<"您的车已经存入成功！"<<endl;
    continue;
}
          }
          else if(number1==2)
          {
              cout<<"请输入存放地点："<<endl;
              int number2;
              cin>>number2;
              cout<<"请输入您的手机号:"<<endl;
              int Phone;
              cin>>Phone;
              if(a.q0[number2-1].findcar(Phone))
              {
                while(1)
                {
                    car car0;
                    a.q0[number2-1].Pop(car0);
                    if(car0.getphone()==Phone)
                    {
                        cout<<"障碍已经清空，请取走您的车！"<<endl;
                        if(!a.que[number2-1].Empty())
                        {
                             a.que[number2-1].outq(car0);
                              char *namee=car0.getcar();
                         printf("%s",namee);


                    cout<<"车主您的车可以进入停车场了"<<endl;
                             a.q0[number2-1].Push(car0);
                             cout<<"您的车已经成功进入停车场！"<<endl;
                        }
                        break;
                    }
                    cout<<"正在联系";

                        char *name0=car0.getcar();
                         printf("%s",name0);


                    cout<<"车主挪车"<<endl;
                    a.q.Push(car0);

               }
              }
              else
              {
                  cout<<"没有找到您的车！抱歉！"<<endl;
                  continue;
              }

          }
          else
          {cout<<"输入错误！"<<endl;
          continue;}
      }
 }
int main(int argc,char *argv[])
{
   run();
}