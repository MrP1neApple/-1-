#include <stdio.h>

double stepen (double chis, int step){//функция возведения в степень
    double res = 1.0;
    if (step==0) return res;// что угодно **0 =1
    int n = step;
    if (n<0){// отрицатеьная степень
        chis = 1/chis;
        n = -n;
    }
    while (n>0){// положительная степень
        if (n%2==1){
            res*=chis;
            n = n - 1;
        }
        chis = chis*chis;
        n = n/2;
        
    }
    return res;
}

int spos1(){//спсоб 1
    double y,itog,x;
    int znk,p=1;
    itog = 0.0;
    printf("vvedite chislo znaov posle ,\n");
    scanf("%d", &znk); /// получаем число
    if (znk <= 0.0 || znk%1!=0){// некоректные данны => рестарт
        printf("vvedite chislo >0,\n");
        return spos1();
    }else{// коректные данные => считаем
        y = stepen(0.1,znk);
        printf("vvedite x prenadlezhshee [-1,1]\n");
        scanf("%lf", &x);
        if (x>=-1.0 && x<=1.0){
            while (stepen(x,p)>y) {
                itog -= (stepen(x,p)/p);
                p = p+1;
            }
        }else{
            printf("chitai normalno i vnimatelno, poehali zanovo (vvedi vernoe x)");
            return spos1();
        }
    }
    return printf("OTVET:%.*f",znk,itog);
}

int spos2(){
    double itog,x;
    int znk,p=1;
    itog = 0.0;
    printf("vvedite chislo elementov posledovatelnosti\n");
    scanf("%d", &znk); /// получаем число элементов
    if (znk <= 0.0 || znk%1!=0){// некоректные данны => рестарт
        printf("vvedite chislo >0,\n");
        return spos2();
    }else{// коректные данные => считаем
        printf("vvedite x prenadlezhashee [-1,1]\n");
        scanf("%lf", &x);
        if (x>=-1.0 && x<=1.0){
            for (0;(p<=znk);1){
                itog -= stepen(x,p)/p;
                p = p+1;
            }
        }else{
            printf("chitai normalno i vnimatelno, poehali zanovo (vvedi vernoe x)");
            return spos2();
        }
    }
    return printf("OTVET:%.10f",itog);
}

int main(){
    int sps;
    printf("1 - tochnost,\n2 - kol-vo simvolov\n");// выберме способ
    scanf("%d", &sps);
    if (sps == 1){//спсоб 1
        return spos1();
    }
    else if (sps == 2){//способ 2
        return spos2();
    }else{// неверные данные => рестрат
        return main();
    }

    return 0;
}