#include<bits/stdc++.h>
using namespace std;
#define MAXNUM 999999999
#define BASE 1000000000
#define MAXBIT 30
struct bignum
{
	long val[MAXBIT];
	long len;

};

void add(bignum &a,bignum &b,bignum &sum)
{
	long tmp;
	long n=0;
	if(a.len>b.len)
		tmp=b.len;
	else
		tmp=a.len;
	long i;
	long carry=0;
	for(i=0;i<tmp;i++)
	{
		sum.val[i]=a.val[i]+b.val[i]+carry;
		if(sum.val[i]>MAXNUM)
		{
			sum.val[i]-=MAXNUM+1;
			carry=1;
		}
		else
			carry=0;
	}
	n=tmp;
	for(;i<a.len;i++)
	{
		sum.val[i]=a.val[i]+carry;
		if(sum.val[i]>MAXNUM)
		{
			sum.val[i]-=MAXNUM+1;
			carry=1;
		}
		else
		{
			carry=0;
		}
		n++;
	}
	for(;i<b.len;i++)
	{
		sum.val[i]=b.val[i]+carry;
		if(sum.val[i]>MAXNUM)
		{
			sum.val[i]-=MAXNUM+1;
			carry=1;
		}
		else
		{
			carry=0;
		}
		n++;
	}
	if(carry==1)
	{
		sum.val[i]=1;
		n++;
	}
	sum.len=n;

}
///////////////////////////////////////////
//            assume a>b
//////////////////////////////////////////
void sub(bignum &a,bignum &b,bignum &sub)
{
	long tmp;
	long n=0;
	if(a.len>b.len)
		tmp=b.len;
	else
		tmp=a.len;
	long i;
	long carry=0;
	for(i=0;i<tmp;i++)
	{
		sub.val[i]=a.val[i]-b.val[i]-carry;
		if(sub.val[i]<0)
		{
			sub.val[i]+=BASE;
			carry=1;
		}
		else
			carry=0;
	}
	n=tmp;
	for(;i<a.len;i++)
	{
		sub.val[i]=a.val[i]-carry;
		if(sub.val[i]<0)
		{
			sub.val[i]+=BASE;
			carry=1;
		}
		else
		{
			carry=0;
		}
		n++;
	}
	for(;i<b.len;i++)
	{
		sub.val[i]=b.val[i]-carry;
		if(sub.val[i]<0)
		{
			sub.val[i]+=BASE;
			carry=1;
		}
		else
		{
			carry=0;
		}
		n++;
	}
	if(carry==1)
	{
		sub.val[i]=1;
		n++;
	}
	sub.len=n;

}
///////////////////////////////////////
void mul(bignum &a,bignum &b,bignum &r)
{
	long an=a.len;
	long bn=b.len;
	long i,j;
	long m_carry,a_carry;
	long long tmp;
	for(i=0;i<MAXBIT;i++)
		r.val[i]=0;
	for(i=0;i<an;i++)
	{
		m_carry=0;
		a_carry=0;
		for(j=0;j<bn;j++)
		{
			tmp=(long long)(a.val[i])*(long long)(b.val[j])+m_carry;
			r.val[i+j]+=tmp%BASE+a_carry;
			if(r.val[i+j]>=BASE)
			{
				r.val[i+j]-=BASE;
				a_carry=1;
			}
			else
			{
				a_carry=0;
			}
			m_carry=tmp/BASE;
		}
		r.val[i+j]+=m_carry+a_carry;
	}
	for(i=MAXBIT-1;i>=0;i--)
		if(r.val[i]!=0)
			break;
	if(i>=0)
		r.len=i+1;
	else
		r.len=1;
}

void printNum(bignum &n)
{
	long i=n.len-1;
	printf("%d",n.val[i]);
	for(--i;i>=0;i--)
		printf("%09d",n.val[i]);
}

void convert(char *s,long len,bignum &r)
{
	long tab[10]={1,10,100,1000,10000,100000,1000000,
		10000000,100000000,1000000000};
	long i,j,k;
	long tmp;
	r.len=(len-1)/9+1;
	for(i=0;i<r.len;i++)
	{
		tmp=0;
		for(j=len-i*9-1,k=0;j>len-1-(i+1)*9&&j>=0;j--,k++)
		{

			tmp+=tab[k]*(s[j]-'0');
		}
		r.val[i]=tmp;


	}

}
long compare(bignum &a,bignum &b)
{
	//a==b return 0;
	//a>b return 1;
	//a<b return -1;
	long i;
	if(a.len>b.len)
		return 1;
	else
	{
		if(a.len<b.len)
			return -1;
		else
		{
			for(i=a.len-1;i>=0;i--)
			{
				if(a.val[i]>b.val[i])
					return 1;
				else
					if(a.val[i]<b.val[i])
						return -1;
			}
			return 0;
		}
	}

}

void setVal(bignum &a,long v)
{
    a.val[0]=v;
    a.len=1;
}

bignum r[129][101];
bignum s[129][101];
int main()
{

    bignum t1,t2;
    int b,n;
    for(b=4;b<=64;b++)
    {

  	    setVal(r[b][1],b);
  	    setVal(r[b][2],b*(b-1)-1);
  	    setVal(s[b][1],b);
  	    setVal(s[b][2],b*b-1);
  	}

  	for(b=4;b<=64;b++)
  	{

  	    for(n=3;n<=100;n++)
  	    {
  	        setVal(t1,b-1);
  	        mul(t1,s[b][n-1],t2);
  	        sub(t2,s[b][n-2],r[b][n]);
  	        add(s[b][n-1],r[b][n],s[b][n]);

  	    }
    }

    scanf("%d %d",&b,&n);
    while(n!=0)
    {
        if(n==1)
        	printf("%d",b-1);
       	else
        	printNum(r[b][n]);
        printf("\n");
        scanf("%d %d",&b,&n);
    }
    return 0;
}



