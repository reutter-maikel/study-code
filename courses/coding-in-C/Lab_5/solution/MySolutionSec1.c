//Section 1

#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    **pp = 42;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p); // nur p dann wird die adresse ausgegeben
    printf("x via pp = %d\n", **pp);

    return 0;
}

/*
4. What are the types of the following expressions?
- x - integer
- p - pointer auf adresse von x -- integer pointer
- *p - pointer auf value von x - integer
- pp - pointer auf pointer von x - integer pointer
- *pp - poiinter auf adresse von pointer von x -- integer pointer
- **pp - pointer auf pointer auf value von x -- integer
*/