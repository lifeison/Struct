#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;

typedef struct tab
{
	string Key;
	string znach;
	bool none;
} tab;

class Hash
{
public:
	tab xesh[50];
	void AddKeyValue (string x, string y);
	void DelKey (string x);
	string GetKey (string x);
	Hash ();
	~Hash ();
};

Hash::Hash()
{
}
Hash::~Hash()
{
}




uint_least32_t Crc32(unsigned char *buf, size_t len)
{
    uint_least32_t crc_table[256];
    uint_least32_t crc; int i, j;
 
    for (i = 0; i < 256; i++)
    {
        crc = i;
        for (j = 0; j < 8; j++)
            crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
 
        crc_table[i] = crc;
    };
 
    crc = 0xFFFFFFFFUL;
 
    while (len--) 
        crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
 
    return crc ^ 0xFFFFFFFFUL;
}

void Hash::AddKeyValue (string x, string y)
{
	int i,s,m;
	i=Crc32 ((unsigned char *)x.c_str(), x.size());
	i=i%50;
	s=i;
	m=50;
	for (;i<m;i++)
	{
		if (xesh[i].none==true)
		{
			xesh[i].Key=x;
			xesh[i].znach=y;
			xesh[i].none=false;
			return;
		}
		if (i==50-1)
		{
			m=s;
			i=0;
		}
	}
}

void Hash::DelKey(string x)
{
	int i,s,m;
	i=Crc32 ((unsigned char *)x.c_str(),x.size());
	i=i%50;
	s=i;
	m=50;
	for (;i<m;i++)
	{
		if (xesh[i].Key==x)
		{
			xesh[i].none=true;
			return;
		}
		if (i==50-1)
		{
			m=s;
			i=0;
		}
	}
}

string Hash::GetKey(string x)
{
	int i,m,s;
	i=Crc32((unsigned char *)x.c_str(), x.size());
	i=i%50;
	s=i;
	m=50;
	for (;i<m;i++)
	{
		if (xesh[i].Key==x)
			return xesh[i].znach;
		if (i==50-1)
		{
			m=s;
			i=0;
		}
	}
	return "no such key";
}
int main ()
{
	Hash x;
	x.AddKeyValue("semen", "one");
	//x.AddKeyValue("sem", "two");
	//x.AddKeyValue("semya", "three");
	cout<<x.GetKey("semen");
	scanf("%*c");
	return 0;

}
