#include <stdio.h>
#include<stdlib.h>

#define require(e) if (!(e)) fprintf(stderr, "FAILED line %d        %s: %s       %s\n", __LINE__, __FILE__, __func__, #e)

int strlen(char *str){
	int i = 0;
	for(; str[i]; i++);
	return i;
}

char* strcpy(char* dest, char* src){
	char* start = dest;
	while(*dest++ = *src++);
	return start;
}

char* strcat(char *dest, char *src){
	char *start = dest;
	while(*start)
		start++;
	strcpy(start, src);
	return dest;
}

int strcmp(char *str1, char *str2){
	while(*str1&&*str1){
		int c1 = *str1;
		int c2 = *str2;
		if(c1 < c2) return -1;
		else if(c1 > c2) return 1;
		str1++;
		str2++;
	}
	if(*str1 && !*str2)
		return 1;
	if(!*str1 && *str2)
		return -1;
	return 0;
}

int strncmp(char *str1, char *str2, int n){
	int i = 0;
	while(str1[i] && str2[i] && str1[i] == str2[i]){
		if (i == n-1) break;
		i += 1; 
	}

	if(str1[i] && !str2[i])
		return 1;
	if(!str1[i] && str2[i])
		return -1;
	return str1[i]-str2[i];
}

char* strchr(char c, char* src){
    for(int i = 0; src[i]; ++i){
        if(src[i] == c)
            return src+i;
    }
    return NULL;
}

char *strpbrk(char *str1, char *str2){
	for(int i = 0; str2[i]; i++){
		if(strchr(str2[i], str1))
			return str1+i;
	}
	return NULL;
}

char *strstr(char *haystack, char *needle){
	int len = strlen(needle);
	char* p = haystack;
	while(p){
		if(strncmp(p, needle, len) == 0) return p;
		else p++;
	}
	return NULL;
}

int strspn(char *str1, char *str2){
    char *p1 = str1;
    char *p2;
    int count = 0;

    for (; *p1; ++p1) {
        for (p2 = str2; *p2 != '\0'; ++p2) {
            if (*p1 == *p2)
                break;
        }
        if (!(*p2))
            return count;
        ++count;
    }
    return count;
}

char *strtok(char *str, char *delim){
    static char *last;
    int c;
 
    if (str == 0) str = last;
    do {
		if ((c = *str++) == '\0')
	    	return 0;
    } while (strchr(c, delim));
    --str;

    for(int i = 0; str[i]; i++){
    	if(strchr(str[i], delim)){
    		last = str+i;
    		break;
    	}else if(!str[i+1])
    		last = str+i+1;
    }
    if (*last != 0){
		*last = '\0';
		last++;
    }
	return str;
}

void test_strlen()
{
    require(strlen("") == 0);
    require(strlen("hello") == 5);
    require(strlen("helloabc") == 8);
}

void test_strcmp()
{
    char r[] = "hello", s[] = "hello", t[] = "he";
    require(strcmp(r,s) == 0);
    require(strcmp(t,r) < 0);
    require(strcmp(s,t) > 0);
}

void test_strcpy()
{
	char dest[6];
	char src[] = "abcd";
	char src1[] = "abcdfg";
	char src2[] = "a";
    require(strcmp(strcpy(dest, src), "abcd") == 0);
    require(strcmp(strcpy(dest, src1), "abcdfg") == 0);
    require(strlen(strcpy(dest, src2)) == 1);
}

void test_strcat()
{
    char r[11] = "hello";
    char s[] = "hello", t[] = "he";
    require(strcmp(strcat(r,s), "hellohello") == 0);
    char rr[11] = "hello";
    require(strcmp(strcat(rr,t), "hellohe") == 0);
    char rrr[11] = "hello";
    require(strcmp(strcat(rrr,""), "hello") == 0);
}

void test_strncmp()
{
    char r[] = "hello", s[] = "hello", t[]= "hea";
    require(strncmp(r,s, 3) == 0);
    require(strncmp(r,t, 1) == 0);
    require(strncmp(r,t, 3) > 0);
}

void test_strchr()
{
	char str[15] = "1234abcd89";
    require(strchr('a', str)[0] == 'a');
    require(strchr('b', str)[0] == 'b');
    require(strchr('8', str)[0] == '8');
}

void test_strpbrk()
{
    char r[] = "hello", s[] = "hello", t[] = "he";
    require(strpbrk(r,t)[0] == 'h');
    require(strlen(strpbrk(r,t)) == 5);
    require(strcmp(strpbrk(r,t), "hello") == 0);
}

void test_strspn()
{
    char r[] = "abc", s[] = "bcd", t[] = "dasabc";
    require(strspn(r, s) == 0);
    require(strspn(r, t) == 3);
    require(strspn("", s) == 0);
}

void test_strstr()
{
	char haystack[15] = "123adfbadsf321";
	char needle[] = "dfb";
    require(strstr(haystack, needle)[0] == 'd');
    require(strstr(haystack, needle)[1] == 'f');
    require(strstr(haystack, needle)[2] == 'b');
}


void test_strtok()
{
    char r[] = "he l+lo", s[] = " ", t[] = " +";
    require(strtok(r,s)[0] == 'h');
    require(strcmp(strtok(NULL,t), "l") == 0);
    char str[] = "he+o lo";
    require(strcmp(strtok(str,t), "he") == 0);
}

int main(int argc, char** argv){
	test_strlen();
	printf("test_strlen pass\n");
	test_strcmp();
	printf("test_strcmp pass\n");
	test_strncmp();
	printf("test_strncmp pass\n");
	test_strcpy();
	printf("test_strcpy pass\n");
	test_strcat();
	printf("test_strcat pass\n");
	test_strchr();
	printf("test_strchr pass\n");
	test_strpbrk();
	printf("test_strpbrk pass\n");
	test_strspn();
	printf("test_strspn pass\n");
	test_strstr();
	printf("test_strstr pass\n");
	test_strtok();
	printf("test_strtok pass\n");
}