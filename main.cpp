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
    sqstack q;//�ݴ�
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
      cout<<"��ӭ����ͣ����"<<endl;
      while(1)
      {
          cout<<"1.ͣ��"<<endl;
          cout<<"2.ȡ��"<<endl;
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
cout<<"1.���۸�����"<<endl;
cout<<"2.����������"<<endl;
cout<<"3.��������"<<endl;
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

   cout<<"��"<<j+1<<"��ͣ��������Ϊ��"<<dist[j]<<endl;
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

   cout<<"��"<<j+1<<"��ͣ�����۸�Ϊ��"<<price0[j]<<endl;
}
}
else if(number5==3)
{
    for(int i=0;i<6;i++){
    cout<<"��"<<i+1<<"��ͣ��������Ϊ��"<<dist[i]<<endl;
     cout<<"��"<<i+1<<"��ͣ�����۸�Ϊ��"<<price0[i]<<endl;
    }
}
else
{cout<<"�������"<<endl;
continue;}
cout<<"��ѡ��ͣ�������1-6"<<endl;
int number;
cin>>number;
if(number<1||number>6)
{cout<<"�������"<<endl;
continue;}
else if(a.q0[number-1].full())
{
    cout<<"��ͣ������������ѡ������ͣ������ȴ�"<<endl;
    cout<<"1.�뿪"<<endl;
    cout<<"2.����ѡ��"<<endl;
    cout<<"3.�ȴ�"<<endl;
    int m;
    cin>>m;
    if(m==1)
    {

        cout<<"��ӭ�´ι���!"<<endl;
        continue;
    }

    else if(m==2)
        continue;
    else if(m==3)
    {
     cout<<"�������ֻ���:"<<endl;
    int phone0;
    cin>>phone0;
    char car0[5];
    cout<<"��������λ���ƺ�:"<<endl;
    cin>>car0;
    car person(phone0,car0);
    a.que[number-1].inq(person);
    }
    else
    {
        cout<<"�������"<<endl;
        continue;
    }
    }
else
{
    cout<<"�������ֻ���:"<<endl;
    int phone0;
    cin>>phone0;
    char car0[5];
    cout<<"��������λ���ƺ�:"<<endl;
    cin>>car0;
    car person(phone0,car0);
    a.q0[number-1].Push(person);
    cout<<"��ѡ���ͣ�����۸�Ϊ:"<<a.q0[number-1].price<<endl;
    cout<<"����Ϊ��"<<dist[number-1]<<endl;
    cout<<"���ĳ��Ѿ�����ɹ���"<<endl;
    continue;
}
          }
          else if(number1==2)
          {
              cout<<"�������ŵص㣺"<<endl;
              int number2;
              cin>>number2;
              cout<<"�����������ֻ���:"<<endl;
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
                        cout<<"�ϰ��Ѿ���գ���ȡ�����ĳ���"<<endl;
                        if(!a.que[number2-1].Empty())
                        {
                             a.que[number2-1].outq(car0);
                              char *namee=car0.getcar();
                         printf("%s",namee);


                    cout<<"�������ĳ����Խ���ͣ������"<<endl;
                             a.q0[number2-1].Push(car0);
                             cout<<"���ĳ��Ѿ��ɹ�����ͣ������"<<endl;
                        }
                        break;
                    }
                    cout<<"������ϵ";

                        char *name0=car0.getcar();
                         printf("%s",name0);


                    cout<<"����Ų��"<<endl;
                    a.q.Push(car0);

               }
              }
              else
              {
                  cout<<"û���ҵ����ĳ�����Ǹ��"<<endl;
                  continue;
              }

          }
          else
          {cout<<"�������"<<endl;
          continue;}
      }
 }
int main(int argc,char *argv[])
{
   run();
}