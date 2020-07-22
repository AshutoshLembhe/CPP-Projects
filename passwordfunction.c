#include<stdio.h>
int len(char pwd[20]);
int character(char pwd[20]);
int special(char pwd[20]);
int occ(char pwd[20]);
int main()
{
	char pwd[20];
	printf("\n enter password to validate:");
	scanf("%s",&pwd);
	if(len(pwd))
	{
		if(character(pwd))
		{
			if(occ(pwd))
			{
				if(special(pwd))
				{
					printf("\n password valid");
				}
				else
				{
					printf("\n password not valid");
				}
			}
			else
			{
				printf("\n password not valid");
			}
		}
		else
		{
			printf("\n password not valid");
		}
	}
	else 
	{
		printf("\n password not valid");
	}
}
int len(char pwd[20])
{
	int i;
	for(i=0;pwd[i]!='\0';i++);
	printf("\n %d",i);
	if(i>=8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int character(char pwd[20])
{
	if((pwd[0]>='a')&&(pwd[0]<='z'))
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
int occ(char pwd[20])
{
	int cnt=0,i,cnt1=0;
	for(i=0;pwd[i]!='\0';i++)
	{
		if((pwd[i]>='0')&&(pwd[i]<='9'))
		{
			cnt=cnt+1;
		}
	}
	if(cnt!=0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int special(char pwd[20])
{
	int i,cnt=0;
	for(i=0;pwd[i]!='\0';i++)
	{
		if((pwd[i]=='@')||(pwd[i]=='.'))
		{
			cnt=cnt+1;
		}
	}
	if(cnt>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
