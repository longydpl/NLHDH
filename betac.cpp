#include<bits/stdc++.h>
#include<conio.h>

using namespace std;
int n, m;
void nhapmatran(int *a,int n, int m)
{
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
          cout << "Nhap gia tri tai vi tri [" << i << "," << j << "]: " ;
          cin >> a[i*n+j];
        }
}
void xuatmatran(int *a, int n, int m)
{
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout << a[i*n+j] << " ";
        cout << endl;
    }
}
void nhapmang(int *a, int n)
{
    for(int i=0 ;i<n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}
void xuatmang(int *a , int n)
{
    for(int i =0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void trumatran(int *a, int *b,int *c, int n, int m)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
            c[i*n+j] = a[i*n+j] - b[i*n+j];
    }
}
int ktra(int *a, int *b,int x,int n, int m)
{
    for(int i=x*n;i<x*n+m;i++)
    {
        if(a[i] > b[i]) return 0;
        else return 1;
    }
}

void cong(int *a,int *b,int  x, int n, int m)
{
    for (int i=x*n;i<x*+m;i++)
    {
        a[i] += b[i];
    }
}
void tru(int *a,int *b,int  x, int n, int m)
{
    for (int i=x*n;i<x*+m;i++)
    {
        a[i] -= b[i];
    }
}
void dukienphanbo(int *a, int *b, int *c,int *d,int *e, int *f int n, int m)
{
    // a: req ,b: need, c: avai, d:alloca e:work f:finish
    int *wait = (int *)malloc(n*sizeof(int));
    int *er = (int *)malloc(n*sizeof(int));
    int *done = (int *)malloc(n*sizeof(int));
    int sw = 0;
    int se = 0;
    int sd = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(ktra(a,b,i,n,m) == 0)
        {
             cout << "Tien trinh P" << i << " yeu cau tai nguyen vuot qua quy dinh.\n";
             er[se] = i;
             ++se;
             continue;
        }
         else
         {
             cout << "Request[" << i << "] <= Need [" << i << "] => " << "Thoa man\n";
         }
        if(ktra(a,c,i,n,m) == 0)
        {
            cout << "Khong du tai nguyen phan bo cho tien trinh P" << i << " \n";
            wait[sw] = i;
            sw ++;
            continue;
        }
         else
         {
             cout << "Request[" << i << "] <= Available [" << i << "] => " << "Thoa man\n";
         }
        tru(c,a,i,n,m);
        cong(d,a,i,n,m);
        tru(b,a,i,n,m);

    }
}
int ktraf(int *a, int n)
{
    for (int i=0;i<n;i++)
    {
        if (a[i] == 0) return 0;
        else continue;
    }
    return 1;
}

void xetantoan(int *a, int *b, int *c,int *d,int *e, int *f int n, int m)
{
    // a: req ,b: need, c: avai, d:alloca e:work f:finish
    int i;
    int dem=0;
    int *dl = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        e[i] = c[i];
        f[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        if(ktra(b,e,i,n,m) == 0)
        {
            cout << "Sai !\n";
            dl[dem] = i;
            ++dem;
        }
        else
        {
            cout << "Need [" << i << "] <= Work => Thoa man \n";
            cong(e,d,i,n,m);
            tru(d,d,i,n,m);
            f[i] = 1;
        }
    }
}


int main()
{
    int *alloca = (int *)malloc(n*m*sizeof(int));
    int *need = (int *)malloc(n*m*sizeof(int));
    int *Max = (int *)malloc(n*m*sizeof(int));
    int *req = (int *)malloc(n*m*sizeof(int));
    int *avai = (int *)malloc(m*sizeof(int));
    int *work = (int *)malloc(m*sizeof(int));
    int *fin = (int *) malloc(n*sizeof(int));
    int i;
    cout << "Nhap  so tien trinh : ";
    cin >> n;
    cout << "Nhap so kieu tai nguyen:";
    cin >> m;
    cout << "====Nhap Allocation:====== \n";
    nhapmatran(alloca,n,m);
    cout << "====Nhap Max:====== \n";
    nhapmatran(Max,n,m);
    cout << "====Nhap Available:====== \n";
    nhapmang(avai,m);
    cout << "====Nhap Request:====== \n";
    nhapmatran(req,n,m);
    cout << "====Allocation====\n";
    xuatmatran(alloca,n,m);
    cout << "====Max====\n";
    xuatmatran(Max,n,m);
    cout << "====Available====\n";
    xuatmang(avai,n);
    cout << "====Request====\n";
    xuatmatran(req,n,m);
    trumatran(Max,alloca,need,n,m);
    cout << "====Need====\n";
    xuatmatran(need,n,m);
   dukienphanbo(req,need,avai,alloca,n,m);
   free(alloca);
   free(need);
   free(Max);
   free(req);
   free(avai);
   free(work);
   free(fin);
   return 0;
}

