/* MP1 by Joe Biggins for CS:3620 */
#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if ( ch != '\r' ) { putchar(ch); }
    }
    return 0;
}
