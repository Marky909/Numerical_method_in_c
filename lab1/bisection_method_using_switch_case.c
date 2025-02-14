#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x-4*x-5)
#define e 0.0001

int main(){
    int i=0,choice;
    float x0,x1,x2,f0,f1,f2;
//taking initial guess from the user
do{
    printf("enter the value of x0 and x1: ");
    scanf("%f%f",&x0,&x1);

f0=f(x0);
f1=f(x1);
    if(f0*f1>0){
        printf("\a");
        printf("the initial guess made by the user is incorrect!\n");
        printf("1. renter the guess: \n");
        printf("2.exit from the program: \n");
        printf("enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            //just break the switch case and go back to do while loop
            break;
            
            case 2:
            printf("exiting from the program execution!");
            return 1;

            default:
            printf("error choice! please make the correct choice(1 or 2): ");
            break;
        }

            }
            else {
                //you have made the correct choice
                break;
            }

}while(1);

do{
    //bisection method
    x2=(x0+x1)/2;
    f2=f(x2);
    if (f0*f2==0){
        printf("the root is %f",x2);
        return 1;
    }
    else if(f0*f2<0){
        x1=x2;
    }
    else
    {
        x0=x2;
    }
    i++;

    printf("Iteration:%d\n",i);
    printf("intermediate root:%f\n",x2);
    printf("check for tolearnce:%f\n",f2);

}while(fabs(f2)>e);

printf("\n\n\n");
printf("the approximate root is %.6f\n",x2);
return 0;
}
