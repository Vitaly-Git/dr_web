#include <iostream>
#include <cstring>
#include <cassert>

void TrimRight(char *s);
void TrimRightTest();
char* createString(char * srcStr);
void strTrimCmpEqAssert(char* str1, char* str2);

int main(){
    TrimRightTest();
    return 0;
}

void TrimRight(char *s){
    int64_t i = strlen(s);
    while (i>0 && s[i-1]==' ')
        --i;
    s[i] = 0;
}

void TrimRightTest(){
    
    strTrimCmpEqAssert((char*)"123  ",(char*)"123");
    strTrimCmpEqAssert((char*)"",(char*)"");
    strTrimCmpEqAssert((char*)" ",(char*)"");
    strTrimCmpEqAssert((char*)"  ",(char*)"");
    strTrimCmpEqAssert((char*)"   ",(char*)"");
    strTrimCmpEqAssert((char*)"1",(char*)"1");
    strTrimCmpEqAssert((char*)" 1",(char*)" 1");
    strTrimCmpEqAssert((char*)"1 ",(char*)"1");
    strTrimCmpEqAssert((char*)" 1 ",(char*)" 1");
    strTrimCmpEqAssert((char*)"1234567 ",(char*)"1234567");
    strTrimCmpEqAssert((char*)" 1234567 ",(char*)" 1234567");
    strTrimCmpEqAssert((char*)" 12345 6 7 ",(char*)" 12345 6 7");

    std::cout << "OK TrimRightTest" << std::endl;
}

void strTrimCmpEqAssert(char* str1, char* str2){
    char *testStr = createString((char*)str1);
    
    TrimRight(testStr);
    assert(std::string(testStr) == str2);
    
    free(testStr);
}

char* createString(char * srcStr){
    char* resStr = (char* )calloc(strlen(srcStr),1);
    strcpy(resStr, srcStr);
    return resStr;
}
