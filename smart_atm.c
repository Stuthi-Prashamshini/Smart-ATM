

#include<stdlib.h>
#include<stdio.h>
char a[20];
int pin,balance;
long acc_no;
int trans_arr[100],transcount=0,amount,recacc_no,otp,trans_arr1[100],transcount1=0;

int login(){
    printf("\n\n=======================\n");
    printf("LOGIN PAGE\n");
    printf("=======================\n");
    long user_acc;
    int pin1;
    printf("\nEnter the account no : ");
    scanf("%ld",&user_acc);
    printf("\nEnter your pin : ");
    scanf("%d",&pin1);
    if(user_acc==acc_no && pin1==pin){
        printf("\n\nLogin Successful!!");
        printf("\n----------------------------------------");
        return 1;
    }
    else{
        printf("\n\nInavlid Credentials..");
        return 0;
    }
}



void checkBalance(){
   
    printf("\nBalance Ammount : %d",balance);
}


void Deposit(){
    printf("\nEnter the amount you wanna deposit : ");
    scanf("%d",&amount);
    balance=balance+amount;
    trans_arr[transcount]=+amount;
    transcount++;
    printf("\nAmount Deposited Successfully!!");
    return;
   
}

void withdraw(){
    printf("\nEnter the amount you wanna Withdraw : ");
    scanf("%d",&amount);
    if(amount<=balance){
        balance=balance-amount;
        trans_arr[transcount]=-amount;
        transcount++;
        printf("\nAmount withdrawn Successfully!!");
    }
    else{
        printf("\nNo sufficient balance\n");
    }
    return;
   
}

void transfer(){
    int user_otp,transamount;
    printf("\nEnter the reciever Account number : ");
    scanf("%d",&recacc_no);
    otp=rand()%9000+1000;
    printf("\nGenerated OTP : %d",otp);
    printf("\n\nEnter the OTP : ");
    scanf("%d",&user_otp);
    printf("\nenter the amount you wanna transfer : ");
    scanf("%d",&transamount);
    if(transamount<=balance){
        if(user_otp==otp ){
           
            balance-=transamount;
            trans_arr1[transcount1]=transamount;
            transcount1++;
            printf("\nAmount transfered succesfully!!");
        }
        else{
            printf("\nIncorrect OTP...TRY AGAIN\n");
        }
    }
    else{
        printf("\nInvalid Transaction amount!!...\n");
    }
    return;
}

void changePin(){
    int oldpin;
    printf("Enter your old PIN : ");
    scanf("%d",&oldpin);
    if(oldpin==pin){
        printf("Enter your new PIN :");
        scanf("%d",&pin);
        printf("\nPIN changed successfully!!..\n");
    }
    return;
}

void miniStatement(){
    printf("\n*****Mini Statement*****\n");
    printf("\n----------------------------------------");
    for(int i=0;i<transcount;i++){
        if(trans_arr[i]>0){
            printf("\nDeposit         ---> %d\n",trans_arr[i]);
        }
        else{
            printf("\nwithdraw        ---> %d\n",trans_arr[i]);
        }
    }
    for(int i=0;i<transcount1;i++){
        printf("\ntransaction history ---> %d\n",trans_arr1[i]);
       
    }
    return;
}

void accountDetails(){
    printf("\nACCOUNT DETAILS\n");
    printf("\nAccount Holder Name : %s",a);
    printf("\nAccount Number      : %ld",acc_no);
    printf("\nBalance Amount      : %d",balance);
    return;
}

int main()
{
    printf("=======================\n");
    printf("Create Account\n");
    printf("=======================\n");
   
    printf("Enter your name : ");
    scanf("%s",&a);
    printf("\nenter the pin : ");
    scanf("%d",&pin);
    printf("\nEnter initial balance : ");
    scanf("%d",&balance);
    acc_no = rand()%900000+100000;
    printf("\nYour New account number : %ld",acc_no);
    printf("\n\nAccount Created Successfully!!!");
    printf("\n----------------------------------------");
    int result=login();
    if(result){
        int ch;
        do{
            printf("\n\n");
            printf("\n=======================\n");
            printf("SMART ATM MENU\n");
            printf("=======================\n");
            printf("1.Check Balance.\n2.Deposit.\n3.Withdraw.\n4.Transfer.\n5.Change Pin.\n6.Mini Statement.\n7.Account Details.\n8.Exit.\n\n");
            printf("Enter your choice : ");
            scanf("%d",&ch);
            switch(ch){
                case 1:
                    checkBalance();
                    break;
                case 2:
                    Deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    transfer();
                    break;
                case 5:
                    changePin();
                    break;
                case 6:
                   miniStatement();
                    break;
                case 7:
                    accountDetails();
                    break;
                case 8:
                    printf("\nTHANK YOU FOR USING SMART ATM!!!!\n");
                    exit(0);
                default:
                    printf("Invalid choice\n");
            }
        }while(ch<=8);
    }
    return 0;
}