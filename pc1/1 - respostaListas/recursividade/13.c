#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int ULI;

ULI mdc(ULI a0, ULI b0){
    ULI res = a0 % b0;
    return (res == 0 ? b0 : mdc(b0, res));
}

int main(int argc, char* argv[]) {
    
    if (argc != 3){
        puts("error");
        return 1;
    }

    ULI vet[2];
    for (int i = 0; i < 2; i++) {
        vet[i] = (ULI)atof(argv[i + 1]);
    }
    printf("mdc(%s,%s) = %ld\n",argv[1],argv[2],mdc(vet[0],vet[1]));

    return 0;
}