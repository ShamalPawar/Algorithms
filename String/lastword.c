
/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
A word is a maximal substring consisting of non-space characters only.
*/
int lengthOfLastWord(char * s){
    int index,count =0, flag=0,spacecount=0, stringlen = strlen(s);
    
    if(s[0] == ' ' && stringlen == 1)
        return 0;
    
    if(s[stringlen - 1] == ' ')
    {
        index = stringlen - 1;

        while(index >= 0)
        {
            if(s[index] != ' ')
            {
                break;
            }
            else
                spacecount++;
            index--;
        }
    }
    stringlen = stringlen - spacecount;
    for(index = stringlen-1; index >= 0; index--)
    {
        if(s[index] == ' ')
        {
            flag = 1;
            break;
        }
        else
        {
            count++;
        }
    }
  
    return count;

}
