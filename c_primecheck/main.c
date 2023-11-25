#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_prime(long long x){
    if(x==2){
        return 1;
    }

    if(x>2 && x%2==0){
        return 0;
    }

    long endval = sqrt(x)+1;

    for(long i=3;i<endval;i+=2){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("%d",check_prime(3671));

    return 0;
}


