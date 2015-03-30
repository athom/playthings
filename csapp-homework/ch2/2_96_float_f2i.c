#include <stdio.h>
typedef unsigned float_bits;

int float_f2i(float_bits f)
{
	unsigned sign=f>>31;
	unsigned exp = (f>>23)&0xff;
	unsigned frac = f&0x7fffff;

	if(exp == 0)
	    return 0;
	if(exp == 0xff)
		return 0x80000000;
	unsigned m = frac+0x800000;
	int e =exp-127;
	if(e<0)
		return 0;
	else if(e>31)
		return 0x80000000;
	else if(e<23)
		m>>(23-e);
	else
		m<<(e-23);
	return sign<<31|m;
}

int main()
{
	int i;
	unsigned u;
	float f;
	for(u=0;u<=0xffffffff;u++)
	{
		f=*((float*)&u);
		i=float_f2i(u);
		if((int)f == i)
			printf("%u ok\n",u);
		else
		{
			printf("%u err:%d %d\n",u,(int)f,i);
			return -1;
		}
	}
}

