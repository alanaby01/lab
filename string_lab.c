#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void str_length(char * string1)
{ 
    int i;  
    scanf("%s", string1);
    for (i = 0; string1[i] != '\0'; ++i); 
    printf("Length of string is %d", i);
} 
void strconcat(char * s1)
{
    char s2[100], i, j;
    
    printf("Enter second string: ");
    scanf("%s", s2);
    // calculate the length of string s1
    // and store it in i
    for(i = 0; s1[i] != '\0'; ++i);
    for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    printf("After concatenation: %s", s1);
}
void strcopy(char * s1,char * s2)
{
    char i;
    for(i = 0; s1[i] != '\0'; ++i)
    {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
    printf(" Copied String s2: %s", s2);
}
void strcomp(char *Str1)
{
  	char Str2[100];
  	int result, i;
  	printf("\n Please Enter the Second String :  ");
  	scanf("%s",Str2);
  	for(i = 0; Str1[i] == Str2[i] && Str1[i] == '\0'; i++);
  	if(Str1[i] < Str2[i])
   	{
   		printf("\n str1 is Less than str2");
	}
	else if(Str1[i] > Str2[i])
   	{
   		printf("\n str2 is Less than str1");
	}
	else
   	{
   		printf("\n str1 is Equal to str2");
	}
}
char *replaceWord(const char *s, const char *oldW, 
                                 const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 
  
// Driver Program 

void count_str(char *s)
{
     
    int i,vowels=0,consonants=0,words=1;
    for(i=0;s[i]!='\0';i++)  
    {
    	if((s[i]>=65 && s[i]<=90)|| (s[i]>=97 && s[i]<=122))
    	{
		
            if(s[i]=='a'|| s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O' ||s[i]=='U')
		        vowels++;
            else
                consonants++;
        }
        else if(s[i]==' '&&s[i-1]!=' ')
            words++;
    }
    printf("vowels = %d\n",vowels);
    printf("consonants = %d\nwords=%d\n",consonants,words);
}
int main() 
{ 
    char s1[100],str_cpy[100],str3[100],str4[100];
    char * result;
    int choice;
    printf("Enter the main string\n");
    scanf(" %[^\n]%*c",s1);
    
    printf("Enter your choice:\n1.String Length\n2.String Concatenetion\n3.String Copy\n4.String Compare\n5.Replace Word\n6.Count of string");
    scanf("%d",&choice);
    if(choice==1)
    {
        str_length(s1);
    }
    if(choice==2)
    {
        strconcat(s1);
    }
    if(choice==3)
    {
        strcopy(s1,str_cpy);
    }
    if(choice==4)
    {
        strcomp(s1);
    }
    if(choice==5)
    {
        printf("Enter the substring to be replaced:\n");
        scanf("%s",str3);
        printf("Enter the word to replace with:\n");
        scanf("%s",str4);
        result = replaceWord(s1, str3, str4); 
        printf("New String: %s\n", result); 
    }
    if(choice==6)
    {
        count_str(s1);
    }

} 