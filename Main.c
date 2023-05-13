#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void soal();
typedef struct registration
{
    char name[20];
    char job[20];
    char age[20];
    char hobby[50];
    char username[20];
    char password[20];
} regis;


int main(int manyArgument, char *argument[])
{
    if(manyArgument == 1){
        regis reg;
        printf("\n");
        printf("*************************************************************\n");
        printf("*****\t\tWellcome to our game quizz\t\t*****\n");
        printf("*************************************************************\n");
        printf("Silahkan registrasi terlebih dahulu sebelum memulai game quiz <3\n");
        printf("Nama\t\t: "); gets(reg.name);
        printf("Pekerjaan\t: "); gets(reg.job);
        printf("Hobby\t\t: "); gets(reg.hobby);
        printf("Umur\t\t: "); gets(reg.age);
        printf("\n");
        printf("\tLets create your account <3\n");
        printf("Username\t: "); gets(reg.username);
        printf("Password\t: "); gets(reg.password);
        printf("\nCreate account success !\n");
        printf("Lets login and enjoy the game <3 !\n");
        printf("Note cara login : ./FileProgramUtama Username Password (perhatikan huruf besar dan kecil ya <3!)\n\n");
        
        FILE *fpw = fopen("database/login.bin", "wb");

        char insl[3] = "#";
        strcat(reg.username, insl);
        strcat(reg.username, reg.password);

        fwrite(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpw);

        fclose(fpw);
    }

    if(manyArgument == 2){
        regis reg;
        FILE *fpr = fopen("database/login.bin", "rb");

        char add[3] = "#";
        strcat(reg.username, add);
        strcat(reg.username, reg.password);

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);
        
        char acc[0];
        printf("\nFail to login !\n");
        printf("Anda belum memasukkan password !\n");
        printf("See your account? (y/n) "); gets(acc);
        if (acc[0] == 'y')
        {
            fgets(reg.username, sizeof(reg.username), fpr);
            printf("Your account : %s\n", reg.username);
        }
        printf("Note cara login : ./FileProgramUtama Username Password (harap perhatikan huruf besar dan kecil ya <3!)\n\n");
    }

