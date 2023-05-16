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

  if(manyArgument == 3){
        regis reg;

        char usernameInput[10], passwordInput[10];
        strcpy(usernameInput, argument[1]);
        strcpy(passwordInput, argument[2]);
        
        FILE *fpr = fopen("database/login.bin", "rb");

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);

        char *string[3];
        char username[20], password[20];
        int ctrl = 0;

        string[0] = strtok(reg.username, "#");
        while (string[ctrl++] != NULL){
            string[ctrl] = strtok(NULL, "#");
        }

        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if( (strcmp(usernameInput, username) != 0 ) && (strcmp(passwordInput, password) != 0)) {
            printf("Anda Gagal login !\n");
            exit(1);
        } 
        else{
            printf("Login berhasil!");
            printf("\n\n\t\t\t\tSelamat datang di \"UANG KAGET\"");
            printf("\n\n\t\t\t\tJadilah jutawan dengan hanya menjawab beberapa pertanyaan!!!");
            printf("\n\t\t\t\tTekan \"ENTER\" untuk memulai permainan!\n\n");
            getchar();
            soal();
        }

    }
    return 0;
}
void soal(){
    int hadiah=0; 
    char jawaban;

    //soal pertama   
    printf("\n\nHadiah untuk pertanyaan pertama = Rp200.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju ke soal pertama!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\tApakah kepanjangan dari library \"stdio\" pada bahasa C?\n\n");
    printf("\t\t\t\tA. Standar Input Output\n");
    printf("\t\t\t\tB. Standar Initial Output\n");
    printf("\t\t\t\tC. Standar Input Online\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='A'){
        printf("\n\nSelamat jawaban anda benar!");
        hadiah+=200000;
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
}
