#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Author: Thomas Besenski
Dec 12 2017

Problem: Write a function to find the longest common prefix string amongst an array of strings.
Input Parameters: char** strs = pointer to a series of pointers representing the strings to be analyzed
Output: a pointer to a malloc'd location in memory that represents the longest common prefix among the inputs


Algorithm Idea: Since the longest common prefix must be identical to every one of the strings, we can arbitrarily chose the 1st string 
                to compare the rest of the string's characters to, incrementally.

Runtime Analysis: 3ms, beating >30% of other submissions and existing in the 2-4ms bracket of highest performing submissions

Found on : https://leetcode.com/problems/longest-common-prefix/description/

*/
    

char* longestCommonPrefix(char** strs, int strsSize) {
    
    if (!*strs) return "";
    int check_index=0; int char_num; int prefix_num=0;
    
    int length = strlen(strs[0]);
    for(char_num; char_num<length; char_num++){
        int word_index=1;
        
        while(word_index<strsSize){
            if (strs[word_index][char_num] != strs[0][char_num])
            {
                break;
            }
            word_index++;
        }
        if (word_index == strsSize){
            prefix_num++;
        }
        else{
            
            char  * temp = (char *)malloc(sizeof(char)*length+1);
            memset(temp, '\0' , sizeof(char)*length+1);
            if (!temp) return;
            strncpy(temp, strs[0], prefix_num);
            return temp;
            free(temp);
        }
    }
   
    char * temp_ret = (char *)malloc(sizeof(char)*length +1);
    if (!temp_ret) return;
    memset(temp_ret, '\0', sizeof(char)*length+1);
    strncpy(temp_ret, *strs, prefix_num);
    //printf("%s", temp_ret);
    return temp_ret;
    free(temp_ret);
}
