void main()
{
	moveAlp("abcd");	
}

int moveAlp (char string [])
{

    char var0[1000];
    char lt0;
    int x=0;
    while (string[x])
    {
        lt0=string[x];
        if (lt0 == 'z')
        {
            var0[x]=(char)lt0-25;
        }
        else
        {
            var0[x]=(char)lt0+1;
        }
        x++;
    }
    printf("%s", var0);
}