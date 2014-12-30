#include <iostream>
#include <string>
using namespace std;

#define BUFF_SIZE 512
#define ARGS_SIZE 128

void parse_protocol(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	char *ptr = strstr(src, "http://");
	if(ptr)
	{
		ptr += strlen("http://");
	}
	else
	{
		ptr = strstr(src, "https://");
		if(ptr)
		{
			memcpy(dest, "HTTPS", strlen("HTTPS"));
			ptr += strlen("https://");
		}
		else
		{
			ptr = src;
		}
	}

	memcpy(buff, ptr, strlen(ptr));
	memset(src, 0x0, BUFF_SIZE);
	memcpy(src, buff, strlen(buff));
}

void parse_domain(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	char *ptr = strstr(src, "/");
	if(ptr)
	{
		memcpy(dest, src, ptr - src); 

		memcpy(buff, ptr, strlen(ptr)); 
		memset(src, 0x0, BUFF_SIZE);
		memcpy(src, buff, strlen(buff));
	}
	else
	{
		memcpy(dest, src, strlen(src));
		memset(src, 0x0, BUFF_SIZE);
	}
}

void parse_port(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	if(strstr(src, ":") != NULL)
	{
		char *ptr = strstr(src, ":");
		if(ptr)
		{
			//檢查port是否全為數字
			bool flag = true;
			ptr++;
			char tmp[5] = "\0";
			int len = strlen(ptr) < 5 ? strlen(ptr) : 5;
			memcpy(tmp, ptr, len);
			for(int j = 0; j < len; ++j)
			{
				if(!isdigit(tmp[j]))
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				memcpy(dest, ptr, strlen(ptr));
				*--ptr = '\0';
			}
		}
	}
}

void parse_ip(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	char *token[4] = {"\0", "\0", "\0", "\0"};
	memcpy(buff, src, strlen(src));

	//依據"."把各個字串分割後填入到token中
	char *tmp;
	char *ptr = strtok_s(buff, ".", &tmp);
	int c = 0;
	if(ptr)
	{
		for(; c < 4; ++c) 
		{
			token[c] = ptr;
			ptr = strtok_s(NULL, ".", &tmp);
			if(!ptr)
				break;
		}
	}
	if(c == 3)	//IP必為四組數字(也就是說上面的迴圈必須執行完不能中斷)
	{
		bool flag = true;
		for(int i = 0; i < 4; ++i)
		{
			char tmp[4] = "\0";
			int len = strlen(token[i]) < 3 ? strlen(token[i]) : 3;
			memcpy(tmp, token[i], len);
			for(int j = 0; j < len; ++j)
			{
				if(isdigit(tmp[j]) == 0)
				{
					flag = false;
					break;
				}
			}
		}
		
		if(flag)
			sprintf_s(dest, BUFF_SIZE, "%s.%s.%s.%s", token[0], token[1], token[2], token[3]);
	}
}

void parse_path(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	char *ptr = strstr(src, "/");

	//讓ptr指到最後一個"/"
	while(ptr != NULL)
	{
		if(strstr(ptr+1, "/") != NULL)
			ptr = strstr(ptr+1, "/");
		else
			break;
	}

	if(ptr != NULL)
	{
		memcpy(dest, src, ptr - src);
		memcpy(buff, ptr+1, strlen(ptr+1));
		memset(src, 0x0, BUFF_SIZE);
		memcpy(src, buff, strlen(buff));
	}
	else
	{
		memcpy(buff, src, strlen(src));
	}
}

void parse_file(char dest[], char src[])
{
	if(!dest || !src)
		return;

	char buff[BUFF_SIZE] = "\0";
	char *ptr = strstr(src, "?");
	if(ptr != NULL)
	{
		memcpy(dest, src, ptr - src);

		memcpy(buff, ptr+1, strlen(ptr+1));
		memset(src, 0x0, BUFF_SIZE);
		memcpy(src, buff, strlen(buff));
	}
}

void parse_args(char dest[BUFF_SIZE][BUFF_SIZE], char src[])
{
	if(!dest || !src)
		return;

	char *tmp;
	char *ptr = strtok_s(src, "&", &tmp);
	if(!ptr)
	{
		memcpy(dest[0], src, strlen(src));
	}
	else
	{
		for(int i = 0; i < ARGS_SIZE; ++i)
		{
			memcpy(dest[i], ptr, strlen(ptr));
			ptr = strtok_s(NULL, "&", &tmp);
			if(!ptr)
				break;
		}
	}
}

void main()
{
	int pos = 0;
	char url[BUFF_SIZE] = "\0";
	cout<<"Input a url:";
	cin>>url;
	_strlwr_s(url);//轉成全小寫


	char protocol[BUFF_SIZE] = "HTTP";
	char domain[BUFF_SIZE] = "\0";
	char port[BUFF_SIZE] = "\0";
	char ip[BUFF_SIZE] = "\0";
	char path[BUFF_SIZE] = "\0";
	char file[BUFF_SIZE] = "\0";
	char args[ARGS_SIZE][BUFF_SIZE];
	memset(args, 0x0, ARGS_SIZE*BUFF_SIZE );

	parse_protocol(protocol, url);
	parse_domain(domain, url);
	parse_port(port, domain);
	parse_ip(ip, domain);
	parse_path(path, url);
	parse_file(file, url);
	parse_args(args, url);

	cout<<"protocol:"<<protocol<<endl;
	if(strlen(ip) != 0)
		cout<<"IP:"<<ip<<endl;
	else
		cout<<"Domain Name:"<<domain<<endl;
	if(strlen(port) != 0)
		cout<<"Port:"<<port<<endl;
	cout<<"Path:"<<path<<"/"<<file<<endl;
	for(int i = 0; i < ARGS_SIZE; ++i)
	{
		if(strlen(args[i]) == 0)
			break;
		cout<<"Arguments:"<<args[i]<<endl;
	}


	system("PAUSE");
}

