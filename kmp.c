#include<stdio.h>
//the peseudo - code of the kmp
//kmp compare
int own_kmp(mainstring,substring,next[]){
        if(next == NULL || substring == NULL)
                return -1;
        int i = 0;//i remmber the mainstring location
        int j = 0;//j remmber the substring location
        while(i != mainstring.len && j != substring.len){
                if(mainstring.ch[i] == substring.ch[j]){
                        i++;
                        j++;
                }else{
                        //if j != -1 shows the main string do not move. move the substring to the next[j]
                        //location
                        j = next[j];
                        //if j == -1 shows need to find next location in main string to compare
                        if(-1 == j){
                                j = 0; 
                                ++i;
                        }

                }


        }
        //return the offset in the main-string
        if(j == substring.len){
                return i-substring.len;
        }
        else
                return -1;


        return 0;
}



//the next arr
int get_next(substring,next[]){
        if(next == NULL || substring == NULL)
                return -1;
        //see the substring as the two couple
        //the i remmber the index of the last-common-substring last location
        //the j remmber the index of the pre-common-substring last location
        int i = 0;
        int j = -1;
        //next[k] shows the index of the j. when next[k] shows the pre-common-substring do not exist
        next[0] = -1;
        while(i < substring.len){
                if(j == -1 || substring.ch[i] == substring.ch[j]){
                        //there when the last char compared have the next[j+1] = next[j] + 1;
                        ++i;
                        ++j;
                        next[i] = j;
                }else
                        //if there the last char does not compared have the next[j+1]=next[k] + 1;
                        //look back to find the pre-common-substring last location if
                        //j == -1 means did not find the location 
                        j = next[j];
        }

        return 0;
}
