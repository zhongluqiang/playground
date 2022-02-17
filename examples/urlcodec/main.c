#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* @param decode_plus_ctl: if 1, we decode plus into space.  If 0, we don't.
*     If -1, when true we transform plus to space only after we've seen
*     a ?.  -1 is deprecated.
* @return the number of bytes written to 'ret'.
*/
int
evhttp_decode_uri_internal(
    const char *uri, size_t length, char *ret, int decode_plus_ctl)
{
    char c;
    int j;
    int decode_plus = (decode_plus_ctl == 1) ? 1: 0;
    unsigned i;


    for (i = j = 0; i < length; i++) {
        c = uri[i];
        if (c == '?') {
            if (decode_plus_ctl < 0)
                decode_plus = 1;
        } else if (c == '+' && decode_plus) {
            c = ' ';
        } else if ((i + 2) < length && c == '%' &&
            isxdigit(uri[i+1]) && isxdigit(uri[i+2])) {
            char tmp[3];
            tmp[0] = uri[i+1];
            tmp[1] = uri[i+2];
            tmp[2] = '\0';
            c = (char)strtol(tmp, NULL, 16);
            i += 2;
        }
        ret[j++] = c;
    }
    ret[j] = '\0';


    return (j);
}




int main()
{
    const char *uri = "https://www.google.com/search?q=url%E7%BC%96%E7%A0%81&oq=ur&aqs=chrome.1.69i57j69i59j69i60l3.11336j0j8&sourceid=chrome&ie=UTF-8";
    char ret[1024] = {0};
    int rt = evhttp_decode_uri_internal(uri, strlen(uri), ret, 0);
    printf("%s\n", ret);
    return 0;
}