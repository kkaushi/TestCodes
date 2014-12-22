// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
// USE OF string HEADER FILE IS NOT ALLOWED
#include<stdio.h>
#include<stdlib.h>

//returns length
int ret_length(char * wrd)
{
    int i=0,len=0;
    if(wrd[0]==0)
        return 0;
    for(i=0;wrd[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

//concats word with itself
char * concat_itself(char *wrd)
{
    int i=0,len=0,j=0;
    char * new_wrd;
    len=ret_length(wrd);
    if(len==0)
        return NULL;
    j=2*len;
    new_wrd=(char*)malloc(sizeof(char)*j);
    for(i=0;i<len;i++)
    {
        new_wrd[i]=wrd[i];
    }
    for(i=len;i<j;i++)
    {
        new_wrd[i]=wrd[i-len];
    }
    new_wrd[j]=0;
    return new_wrd;
    
    
}

//checks if str1 is substring of str2
int is_substring(char * str1, char * str2)
{
    int len2=0,len1=0,i=0,j=0;
    len1=ret_length(str1);
    len2=ret_length(str2);
    if(len1==0)
        return 0;
    if(len2==0)
        return 0;
    if(len1>len2)
        return 0;
    for(i=0;i<len1;i++)
    {
        if(str2[i]==0)
        {
            return 0;
        }
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1;
}


int isSameReflection(char* word1, char* word2){
    // Check whether word1 and word2 have same reflection.
    // Return 1 or -1
    // WRITE YOUR CODE HERE
    int i=0,j=0,len1=0,len2=0,len3=0,flag=0;
    char *word3;
	if(*word1==0)
		return -1;
	if(*word2==0)
		return -1;
    len1=ret_length(word1);
    len2=ret_length(word2);
    word3=concat_itself(word1);
    len3=ret_length(word3);
    for(i=0;i<len3;i++)
    {
        flag=is_substring(word2,word3+i);
        if(flag==1)
            return 1;
    }
    return -1;
}
// FUNCTION SIGNATURE ENDS

// DO NOT IMPLEMENT THE main( ) METHOD
int main(){
    // DO NOT CHANGE ANY CODE IN THIS FUNCTION
    //char word1[100], word2[100];
	//char word1[]="";
	//char word2[]="";
	char *word1,*word2;
    int result;
    // ASSUME INPUT HAVE ALREADY BEEN TAKEN
    result = isSameReflection(word1,word2);
    printf("%d",result);
    return 0;
}