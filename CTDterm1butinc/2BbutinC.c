#include <stdio.h>
#include <math.h>

float compound_interest(float amount, float rate, int periods, int time){
    float inside_calc = 1+(rate/periods);
    float ptimest = periods * time;
    float power_eqn = pow(inside_calc,ptimest);
    float result = amount * power_eqn;
    return result;
}

struct Area_Vol{
    float area, volume;
};

struct Area_Vol area_vol_cylinder(float radius, float length){
    struct Area_Vol AV;
    AV.area = M_PI*radius*radius;
    AV.volume = AV.area * length;
    return AV;
}

struct HHMMSS{
    int HH,MM,SS;
};

struct HHMMSS seconds_to_hours(int seconds){
    const int SECONDS_PER_HOUR = 60*60;
    const int SECONDS_PER_MIN = 60;
    struct HHMMSS HMS;
    HMS.HH = seconds/SECONDS_PER_HOUR;
    HMS.MM = (seconds - HMS.HH*SECONDS_PER_HOUR)/SECONDS_PER_MIN;
    HMS.SS = seconds - (HMS.HH*SECONDS_PER_HOUR) - (HMS.MM*SECONDS_PER_MIN);
    return HMS;
};

float fahrenheit_to_celcius(f){
    const float ABSOLUTE_ZERO = -273.15;
    float superior_unit = (f-32)*5/9;
    return superior_unit>=ABSOLUTE_ZERO?superior_unit:-1;
}

float sequence(float n){
    if(n>=-3 && n<-0.5){
        return -1;
    }
    float upper = 2*n +1;
    float lower = n+3;
    float sol = pow((upper/lower),0.5);
    return sol;
}

int maxi_return(int n1, int n2){
    return n1>n2?n1:n2;
}

int check_value(int n1, int n2, int n3, int x){
    return (x>maxi_return(n1,n2) && x<n3)?1:0;
}

int main(int argv, char** argc){
    // 2.11 compound interest
    printf("%.3f\n",compound_interest(1, 0.03, 1, 1));
    printf("%.3f\n",compound_interest(1, 0.12 ,12,1));
    printf("%.3f\n",compound_interest(1, 1 ,1000, 1));

    // 2.12 area_vol_cylinder
    struct Area_Vol AVsol1 = area_vol_cylinder(1.0,2.0);
    float AVsol1_Area = AVsol1.area;
    float AVsol1_Vol = AVsol1.volume;
    printf("(%.2f, %.2f)\n",AVsol1_Area,AVsol1_Vol);

    struct Area_Vol AVsol2 = area_vol_cylinder(2.0,2.3);
    float AVsol2_Area = AVsol2.area;
    float AVsol2_Vol = AVsol2.volume;
    printf("(%.2f, %.2f)\n",AVsol2_Area,AVsol2_Vol);

    struct Area_Vol AVsol3 = area_vol_cylinder(1.5,4);
    float AVsol3_Area = AVsol3.area;
    float AVsol3_Vol = AVsol3.volume;
    printf("(%.2f, %.2f)\n",AVsol3_Area,AVsol3_Vol);

    struct Area_Vol AVsol4 = area_vol_cylinder(2.2,5.0);
    float AVsol4_Area = AVsol4.area;
    float AVsol4_Vol = AVsol4.volume;
    printf("(%.2f, %.2f)\n",AVsol4_Area,AVsol4_Vol);

    // 2.13 seconds_to_hours
    struct HHMMSS HMS_sol1 = seconds_to_hours(29500);
    int H1 = HMS_sol1.HH;
    int M1 = HMS_sol1.MM;
    int S1 = HMS_sol1.SS;
    printf("(%d, %d, %d)\n", H1,M1,S1);

    struct HHMMSS HMS_sol2 = seconds_to_hours(7210);
    int H2 = HMS_sol2.HH;
    int M2 = HMS_sol2.MM;
    int S2 = HMS_sol2.SS;
    printf("(%d, %d, %d)\n", H2,M2,S2);

    // 2.14 fahrenheit_to_celcius
    printf("%.2f\n",fahrenheit_to_celcius(-500));
    printf("%.2f\n",fahrenheit_to_celcius(32));
    printf("%.2f\n",fahrenheit_to_celcius(99));
    printf("%.2f\n",fahrenheit_to_celcius(212));

    // 2.15 sequence
    printf("%f\n",sequence(-4.0));
    printf("%f\n",sequence(-2.0));
    printf("%f\n",sequence(0.0));
    printf("%f\n",sequence(2.0));

    // 2.16 check_value
    printf("%d\n", check_value(1,4,8,7));
    printf("%d\n", check_value(10,4,8,7));
    printf("%d\n", check_value(1,10,8,7));
    printf("%d\n", check_value(1,4,5,7));

    return 0;
}
