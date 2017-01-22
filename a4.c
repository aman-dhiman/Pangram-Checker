/************************Assignment4**************************
Name: Aman Dhiman
ID:   0901912
Nov. 21, 2014
Cis 1500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1. I have read and understood the University policy on academic integrity;
2. I have completed the Computing with Integrity tutorial on Moodle; and
3. I have achieved at least 80% in the Computing and Integrity Self test.

I assert that this work is my own. I have appropriately acknowledged any 
and all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically 
for this course.
**************************************************************/

#include <stdio.h>
#include <ctype.h> // required for tolower() function

void check4Pangram (char string[], int length);
void missingLetters (char string[], int length);
void isTautogram (char string[], int length);

int main()
{
    char sentence[301]= {'\0'};
    char letter;
    char organized[301] = {'\0'};
    int i, current, next, oldCount, newCount, index;
    i = 0;
    oldCount = 0;
    newCount = 0;
    index = 0;
	
    printf("\nPlease enter the sentence:\n");
	fgets(sentence, 301, stdin);
	
    do
    {
        letter = sentence[oldCount];
        oldCount++;
    }
    while (letter != '\n');
    
    if (sentence[oldCount - 1] == '\n') 
    {
        sentence[oldCount - 1] = '\0';
    }
    
    while (i < (oldCount - 1))
    {
        current = sentence[i];
        next = sentence[i+1];
        
        while ((current < 65 || current > 90) && (current < 97 || current > 122)
                && (i < (oldCount - 1)))
        {
            if (current == 32)
            {
                while((next < 65 || next > 90) && (next < 97 || next > 122)
                      && (i < (oldCount - 1)))
                {
                    i++;
                    
                    current = sentence[i];
                    next = sentence[i+1];
                }
               
                organized[index] = ' ';
                
                if (next == '\0')
                {
                    organized[index] = '\0';
                }
                
                index++;
            }
            
            i++;
            
            current = sentence[i];
            next = sentence[i+1];
        }
        
        organized[index] = current;
        index++;
        i++;
    }
    
    do
    {
        letter = organized[newCount];
        newCount++;
    }
    while (letter != '\0');
    
    if (organized[0] == ' ')
    {
        for (int a = 0; a < newCount; a++)
        {
            organized[a] = organized[a+1];
        }
        
        newCount--;
    }
    
    printf("\nThe sentence is: \n");
    
    for (int a = 0; a < newCount; a++)
    {
        putchar(organized[a]);
    }
    
    printf("\n");
	
	check4Pangram(organized, newCount);
    missingLetters(organized, newCount);
    isTautogram(organized, newCount);
	
    return 0;
}
    
void check4Pangram (char string[], int length)
{
    int asci, exist, isPangram;
    isPangram = 1;
	
    for(int x = 65; x < 91; x++)
    // 65 <= x < 91 is the range of Uppercase letters.
    {
        exist = 0;
        int y;
        y = x + 32;
		// 97 <= y < 123 is the range for lowercase letters.
		 
        for(int i = 0; i < length; i++)
        {
            asci = string[i]; 
				
            if(asci == x || asci == y)
            {
                exist++;
            }
        }
			
        if (exist == 0)
        {
            printf("\nThe sentence:\n");
			
            for(int a = 0; a < length; a++)
            {
                putchar(string[a]);
            }
			
            printf("\nis not a pangram\n");
            isPangram = 0;
            break;
        }
    }
	
    if(isPangram)
    {
        printf("\nThe sentence:\n");
			
        for(int a = 0; a < length; a++)
        {
            putchar(string[a]);
        }
			
        printf("\nis a pangram\n");
    }
	
    return;
}

void missingLetters (char string[], int length)
{
    int i, x, y, z, asci, exist, index;
    index = 0;
	
    char missing[27] = {'\0'};
	
    for(x = 65; x < 91; x++)
    {
        exist = 0;
        y = x + 32;
			
        for(i = 0; i < length; i++)
        {
            asci = string[i];
				
            if(asci == x || asci == y)
            {
                exist++;
            }
        }
			
        if (exist == 0)
        {
            missing[index] = y;
            index++;
        }
    }
	
    if(index != 0)
    {
        printf("\nThe following %d letter(s) are missing: \n", index);
        for(z = 0; z <= index; z++)
        {
            putchar(missing[z]);
            printf(" ");
        }
    }
	
    printf("\n");
	
    return;
}

void isTautogram (char string[], int length)
{
    char alphabet = tolower(string[0]);
    int index;
    index = 0;
	
    while(index <= length)
    {
        if(string[index] == ' ')
        {
            if(alphabet != tolower(string[index + 1]))
            {
                break;
            }
        }
		
        index++;
    }	
	
    printf("\nThe sentence:\n");
			
    for(int a = 0; a < length; a++)
    {
        putchar(string[a]);
    }
	
    if(index <= length)
    {
        printf("\nis not a tautogram\n");
    }
    else
    {
        printf("\nis a tautogram\n");
    }
	
    return;
}