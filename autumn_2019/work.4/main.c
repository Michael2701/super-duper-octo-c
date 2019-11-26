//michael silianov + evgeney golovachov

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)
int main() {
    char **name; 
    char tmp[100];
    int *count;
    int i = 0,j = 1 ,flag = 1,len;
    name = (char **)malloc(sizeof(char *)); // creating to dynamic arrys to charr and int arry
    count = (int *)malloc(sizeof(int));
    FILE* fd = fopen("names.txt","r");//create an pointer that will point to the file
    if (fd)
    {
        while (!feof(fd))
        {
            len = fgets(tmp, 100, fd);
            if (i == 0) // chaeck if we enter fiorst time if true put a string in names
            {
                name[i] =(char *) malloc ((strlen(tmp) + 1) * sizeof(char));
                if (name)
                {
                    strcpy(name[i], tmp);
                    count[i] = 0;
                }
                else
                {
                    printf("Couldn't allocate an array!\n");
                    exit(1);
                }
            }
			if (len) 
			{ // check that we got string from fgets
				for (i = j - 1; i >= 0; i--)// check if the string that we got is in our arry if true count at his index +1
				{

					if (!strcmp(name[i], tmp))
					{
						count[i]++;
						flag = 0;//put the flag to zero that we will know that the string is elresy exist
					}
				}

				if (flag) { // if it new name realloc the arry to a new size
					j++;
					name = (char**)realloc(name, j * sizeof(char*));
					name[j - 1] = (char*)malloc((strlen(tmp) + 1) * sizeof(char)); // enter the new string *j-1 becose the size and the last index is always index = size - 1
					if (name[j - 1])
					{
						strcpy(name[j - 1], tmp);
						count = (int*)realloc(count, j * sizeof(int));
						if (count)
						{
							count[j - 1] = 0;
							count[j - 1]++;
						}
						else
						{
							printf("Couldn't allocate an array!\n");
							exit(1);
						}
					}
					else
					{
						printf("Couldn't allocate an array!\n");
						exit(1);
					}
				}
				i = j; // put in same position as j
				flag = 1; // puts flag to one becose by default the new name from the file is dont exist in our arry
				}
			}
        }
    
    for (i = 0; i < j; i++)
        printf("%s:%d\n", name[i],count[i]); //prints the names and there counters
    free(name);
    free(count);
}
