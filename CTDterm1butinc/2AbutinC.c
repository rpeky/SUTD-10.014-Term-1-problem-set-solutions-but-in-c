#include <stdio.h>
#include <math.h>

float calculate_bmi(float weight, float height){
    float heightincm = height/100;
    float result = weight/(pow(heightincm,2));
    return result;
}

struct positionvelocity{
    float position,velocity;
};


struct positionvelocity position_velocity(float vo, float time){
    struct positionvelocity pv;
    float g = 9.81;
    pv.position = vo*time - 0.5*g*pow(time,2);
    pv.velocity = vo-g*time;
    return pv;
}

double decay(double a, double t){
    return pow(M_E,-1*a*t)*cos(a*t);
}

void describe_bmi(float bmi){
    if(bmi>=27.5){
        printf("high risk\n");
    }
    else if(bmi>=23){
        printf("moderate risk\n");
    }
    else if(bmi>=18.5){
        printf("low risk\n");
    }
    else{
        printf("nutritional deficiency\n");
    }
}

int is_positive_even(int n){
    if(n>=0 && n%2==0){
        return "True\n";
    }
    else{
        return "False\n";
    }
}

char letter_grade(int grade){
    char res;
    if(grade>100){
        return '\0';
    }
    else if(grade>=90){
        res = 'A';
        return res;
    }
    else if(grade>=80){
        res = 'B';
        return res;
    }
    else if(grade>=70){
        res = 'C';
        return res;
    }
    else if(grade>=60){
        res = 'D';
        return res;
    }
    else if(grade>=0){
        res = 'E';
        return res;
    }
    else{
        return '\0';
    }
}

float find_max(float num1, float num2){
    return num1>num2?num1:num2;
}

float largest_area(float s, float u, float v){
    if(s<0 || u<0 || v<0 || u>s || v>s){
        return 0;
    }
    else{
        float sv = s-v;
        float su = s-u;
        float area_res = find_max(v,sv)*find_max(u,su);
        return area_res;
    }
}

int main(int argv, char** argc){
    //calculate_bmi testcase
    float a = calculate_bmi(2.5,50);
    float b = calculate_bmi(50,150);
    float c = calculate_bmi(43.5,142.3);
    printf("%.1f\n",a);
    printf("%.1f\n",b);
    printf("%.1f\n",c);

    //position_velocity
    struct positionvelocity aa = position_velocity(5.0,0);
    struct positionvelocity bb = position_velocity(10.0,1);
    struct positionvelocity cc = position_velocity(5.886,0.3);
    printf("%.3f, %.3f\n",aa.position,aa.velocity);
    printf("%.3f, %.3f\n",bb.position,bb.velocity);
    printf("%.3f, %.3f\n",cc.position,cc.velocity);

    printf("%f\n",decay(2,0.5));

    describe_bmi(27.5);

    printf(is_positive_even(10));

    printf("%c\n", letter_grade(85));

    printf("%f\n",largest_area(10,3,4));

    return 0;
}
