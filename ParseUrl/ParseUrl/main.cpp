#include <iostream>
#include <string>
using namespace std;

#define BUFF_SIZE 512
#define ARGS_SIZE 128

void ParseProtocol(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	char *paPtr = strstr(acSrc, "http://");
	if(paPtr)
	{
		paPtr += strlen("http://");
	}
	else
	{
		paPtr = strstr(acSrc, "https://");
		if(paPtr)
		{
			memcpy(acDest, "HTTPS", strlen("HTTPS"));
			paPtr += strlen("https://");
		}
		else
		{
			paPtr = acSrc;
		}
	}

	memcpy(acBuff, paPtr, strlen(paPtr));
	memset(acSrc, 0x0, BUFF_SIZE);
	memcpy(acSrc, acBuff, strlen(acBuff));
}

void parse_domain(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	char *paPtr = strstr(acSrc, "/");
	if(paPtr)
	{
		memcpy(acDest, acSrc, paPtr - acSrc); 

		memcpy(acBuff, paPtr, strlen(paPtr)); 
		memset(acSrc, 0x0, BUFF_SIZE);
		memcpy(acSrc, acBuff, strlen(acBuff));
	}
	else
	{
		memcpy(acDest, acSrc, strlen(acSrc));
		memset(acSrc, 0x0, BUFF_SIZE);
	}
}

void parse_port(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	if(strstr(acSrc, ":") != NULL)
	{
		char *paPtr = strstr(acSrc, ":");
		if(paPtr)
		{
			//檢查acPort是否全為數字
			bool flag = true;
			paPtr++;
			char tmp[5] = "\0";
			int len = strlen(paPtr) < 5 ? strlen(paPtr) : 5;
			memcpy(tmp, paPtr, len);
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
				memcpy(acDest, paPtr, strlen(paPtr));
				*--paPtr = '\0';
			}
		}
	}
}

void parse_ip(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	char *token[4] = {"\0", "\0", "\0", "\0"};
	memcpy(acBuff, acSrc, strlen(acSrc));

	//依據"."把各個字串分割後填入到token中
	char *tmp;
	char *paPtr = strtok_s(acBuff, ".", &tmp);
	int c = 0;
	if(paPtr)
	{
		for(; c < 4; ++c) 
		{
			token[c] = paPtr;
			paPtr = strtok_s(NULL, ".", &tmp);
			if(!paPtr)
				break;
		}
	}
	if(c == 3)	//acIp必為四組數字(也就是說上面的迴圈必須執行完不能中斷)
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
			sprintf_s(acDest, BUFF_SIZE, "%s.%s.%s.%s", token[0], token[1], token[2], token[3]);
	}
}

void parse_path(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	char *paPtr = strstr(acSrc, "/");

	//讓paPtr指到最後一個"/"
	while(paPtr != NULL)
	{
		if(strstr(paPtr+1, "/") != NULL)
			paPtr = strstr(paPtr+1, "/");
		else
			break;
	}

	if(paPtr != NULL)
	{
		memcpy(acDest, acSrc, paPtr - acSrc);
		memcpy(acBuff, paPtr+1, strlen(paPtr+1));
		memset(acSrc, 0x0, BUFF_SIZE);
		memcpy(acSrc, acBuff, strlen(acBuff));
	}
	else
	{
		memcpy(acBuff, acSrc, strlen(acSrc));
	}
}

void parse_file(char acDest[], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char acBuff[BUFF_SIZE] = "\0";
	char *paPtr = strstr(acSrc, "?");
	if(paPtr != NULL)
	{
		memcpy(acDest, acSrc, paPtr - acSrc);

		memcpy(acBuff, paPtr+1, strlen(paPtr+1));
		memset(acSrc, 0x0, BUFF_SIZE);
		memcpy(acSrc, acBuff, strlen(acBuff));
	}
}

void parse_args(char acDest[BUFF_SIZE][BUFF_SIZE], char acSrc[])
{
	if(!acDest || !acSrc)
		return;

	char *tmp;
	char *paPtr = strtok_s(acSrc, "&", &tmp);
	if(!paPtr)
	{
		memcpy(acDest[0], acSrc, strlen(acSrc));
	}
	else
	{
		for(int i = 0; i < ARGS_SIZE; ++i)
		{
			memcpy(acDest[i], paPtr, strlen(paPtr));
			paPtr = strtok_s(NULL, "&", &tmp);
			if(!paPtr)
				break;
		}
	}
}

void main()
{
	char acUrl[BUFF_SIZE] = "\0";
	cout<<"Input a acUrl:";
	cin>>acUrl;
	_strlwr_s(acUrl);//轉成全小寫


	char acProtocol[BUFF_SIZE] = "HTTP";
	char acDomain[BUFF_SIZE] = "\0";
	char acPort[BUFF_SIZE] = "\0";
	char acIp[BUFF_SIZE] = "\0";
	char acPath[BUFF_SIZE] = "\0";
	char acFile[BUFF_SIZE] = "\0";
	char acArgs[ARGS_SIZE][BUFF_SIZE];
	memset(acArgs, 0x0, ARGS_SIZE*BUFF_SIZE );

	ParseProtocol(acProtocol, acUrl);
	parse_domain(acDomain, acUrl);
	parse_port(acPort, acDomain);
	parse_ip(acIp, acDomain);
	parse_path(acPath, acUrl);
	parse_file(acFile, acUrl);
	parse_args(acArgs, acUrl);

	cout<<"acProtocol:"<<acProtocol<<endl;
	if(strlen(acIp) != 0)
		cout<<"acIp:"<<acIp<<endl;
	else
		cout<<"acDomain Name:"<<acDomain<<endl;
	if(strlen(acPort) != 0)
		cout<<"acPort:"<<acPort<<endl;
	cout<<"acPath:"<<acPath<<"/"<<acFile<<endl;
	for(int i = 0; i < ARGS_SIZE; ++i)
	{
		if(strlen(acArgs[i]) == 0)
			break;
		cout<<"Arguments:"<<acArgs[i]<<endl;
	}


	system("PAUSE");
}

