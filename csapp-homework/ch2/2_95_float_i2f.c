#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;
float_bits float_i2f(int i)
{
	unsigned u = (unsigned)i;
	if(!u)
		return 0u;

	unsigned sign = u>>31;
	unsigned exp,frac,f;

	if(sign)
		u=(~u)+1;
	unsigned j,leftmost_one;
	for(j=0;j<32;j++)
	{
	leftmost_one=u&(0x80000000>>j);
		if(leftmost_one)
			break;
	}
	exp = 158u-j;
	f = u<<j<<1;

	unsigned last_bit=(f&0x200)>>9;
	unsigned truncation = f&0x1ff;
	if(truncation<0x100)
		frac = f >> 9;
	else if(truncation >0x100)
		frac= (f>>9)+1;
	else
	{
		if(last_bit)
			frac = (f>>9)+1;
		else
			frac=f>>9;
	}
	if(frac >>23)
	{
		++exp;
		frac=0;
	}
	return (sign<<31)|(exp<<23)|frac;

}

int main()
{
	int i;
	unsigned r;
	float f,fr;
	for(i=INT_MIN;i<=INT_MAX;i++)
	{
		r=float_i2f(i);
		fr=*((float*)&r);
		f=(float)i;
		if(fr == f)
			printf("%d:ok\n",i);
		else
		{
			printf("%d: %f %f error\n",i,f,fr);
			return -1;
		}

	}
}

