#include <stdio.h>
#include <math.h>
// 3.00a calculate_sum_odd
int calculate_sum_odd(int n){
    if(n==1){
        return 1;
    }
    int total = 0;
    for(int i=1;i<n;i+=2){
        total+=i;
    }
    return total;
}

// 3.00b alternating
float alternating(int n){
    float add=0;
    float sub=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            float down=1+i;
            float temp=1/down;
            add+=temp;
        }
        else{
            float down=1+i;
            float temp=1/down;
            sub-=temp;
        }
    }
    float total=add+sub;
    return total;
}

//3.01a compound_interest
float compound_interest(int deposit, float rate, int months){
    float monthlyinc = rate/12;
    float inc = 1+monthlyinc;
    float value = deposit*inc;
    for(int i=1;i<months;i++){
        value*=inc;
    }
    return value;
}

//3.01b regular_savings
float regular_savings(int deposit, float rate, int months){
    float total=0;
    float inc = 1+(rate/12);
    for(int i=0;i<months;i++){
        total+=100;
        total*=inc;
    }
    return total;
}

//3.02 sum_of_series
float sum_of_series(int n){
    if(n<1){
        return 0;
    }

    float total=0;

    for(int i=1;i<n+1;i++){
        total+=1.00/((i)*(i));
    }
    return total;
}


//3.03 is_prime
int is_prime(long long x){
    //to skip 2 for the even skips
    if(x==2){
        return 1;
    }
    //check if even number or is 1 and below - not primes
    if(x>2 && x%2==0 || x<2){
        return -1;
    }
    // sqrt long long should be a long at most right?
    long endval = sqrt(x);
    // start at 3 check all odd primes until sqrt
    for(long i=3;i<=endval;i+=2){
        if(x%i==0){
            printf("failed modulo %d\n",i);
            return -1;
        }
    }
    return 1;
}

//3.04 number of terms required
float fraction_of_pisq(float s){
    return ((6.0*s)/(pow(M_PI,2.0)));
}

int terms_required(float p){
    int terms = 0;
    while (fraction_of_pisq(sum_of_series(terms))<p){
        terms++;
    }
    return terms;
}

//3.05a calculate_sum_even
int calculate_sum_even(int n){
    int total=0;
    int i=0;
    while(i<n){
        total+=i;
        i+=2;
    }
    return total;
}

//3.05b alternating_while
float int_abs(float x){
    if(x<0){
        return -1*x;
    }
    else{
        return x;
    }
}

float alternating_while(float stop){
    float total=0;
    int n = 1;
    float term = 1.0;
    while(int_abs(term)>stop){
        total+=term;
        n++;
        if(n%2==0){
            term = -1.0*(1.0/n);
        }
        else{
            term = 1.0/n;
        }
    }
    return total;
}



int main(int argc, char** argv){
//    //3.00a calculate_sum_odd
//    printf("%d\n",calculate_sum_odd(0));
//
//    // 3.00b alternating
//    printf("%f\n",alternating(10));
//
//    //3.01a compound_interest
//    printf("%.2f\n",compound_interest(100,0.05,6));
//
//    //3.01b regular_savings
//    printf("%.2f\n",regular_savings(100,0.05,6));
//
//    //3.02 sum_of_series
//    printf("%f\n",sum_of_series(10));

    //3.03 is_prime
//    int pp;
//    scanf("%d\n",pp);
//    printf("%d\n",pp);
    //printf("%d\n",is_prime(49));

//    printf("%f\n", sum_of_series(6));
//    printf("%f\n", fraction_of_pisq(1.5));
//    printf("%d\n", terms_required(0.9));

//    printf("%d\n", calculate_sum_even(11));
//    printf("%d\n", calculate_sum_even(12));
//    printf("%d\n", calculate_sum_even(13));

    printf("%f\n", alternating_while(0.249));
    printf("%f\n", alternating_while(0.199));


    return 0;

}
