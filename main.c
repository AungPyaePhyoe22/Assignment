#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
struct Worker {

    int age;
    char name[50];
    char email[50];
    char password[50];


};

struct Worker Info[30];
void collectdata();
void Printingalldata();
void lobby();
int charcounting(char tocount[50]);
void Strcmp(char userinput[50]);
void Strcmp1(char userinput[50]);
void passcheck(char pass[50] , int Index);
void passcheck1(char pass[50]);
int found = -1;
int efound = -1;
int pfound = -1;
int p1found = -1;
int z = 0;
int NV = 0;
int globalIndex = 0;
void gmailvalid(char gmail[50]);
void Email();
void Register();
void recordingAllDataToFile();
void loadingAllDataFromFile();
void userActionSector();
int main(){

    //collectdata();
    loadingAllDataFromFile();
    Printingalldata();
    lobby();





}

void collectdata(){

    for( z =0; z<SIZE; z++){
        printf("Enter your name -");
        scanf("%s", &Info[z].name );

        printf("Enter your age -");
        scanf(" %d", &Info[z].age);

        Email();

        printf("Enter your password -");
        scanf(" %s", &Info[z].password);


    }
}

void Printingalldata(){
    for(int j = 0; j<globalIndex ; j++){

        printf("name: %s \nage: %d \nemail: %s \npassword: %s\n",Info[j].name,Info[j].age,Info[j].email,Info[j].password);
    }

}

void lobby(){
    char loginemail[50];
    char loginpass[50];
    printf("Welcome this is login\nPlease enter your email:");
    scanf(" %s",&loginemail);
    gmailvalid(loginemail);
    if(NV == 1){
        lobby();
    }
    found = -1;
    Strcmp(loginemail);
    printf("Enter your password:");
    scanf("%s",&loginpass);
    pfound = -1;
    passcheck(loginpass , found);
    if(found != -1 && pfound == 1){
        userActionSector();
    }




}

void Strcmp(char userinput[50]){
    int s1 = 0;
    int s2 = 0;

    int second = charcounting(userinput);
    for (int i = 0; i <SIZE ; i++) {
         s1 = 0;
        int first = charcounting(Info[i].email);
        if (first == second){

            for (int j =0; j<first ; j++){
                if(Info[i].email[j]!=userinput[j]){

                    break;

                }else{
                    s1++;
                }
            }
        }

        if(second == s1) {
            found = i;
            break;
        }else{
            s2++;
        }
        if(s2==SIZE){
            printf("Invalid email \n");
            lobby();
        }
    }

}

void Strcmp1(char userinput[50]){

    int i = 0;
    int s2 = 0;

    int second = charcounting(userinput);
    for ( i = 0; i <globalIndex ; i++){
        int s1 = 0;

        int first = charcounting(Info[i].email);
        if (first == second){


            for (int j =0; j<first ; j++){
                if(Info[i].email[j]!=userinput[j]){
                    break;

                }else{
                    s1++;
                }
            }
        }
        if(second == s1) {
           printf("email already exist\n");
           Register();
        }else {

            s2++;
        }
        if (s2 == globalIndex) {

            efound = 0;
            break;
        }
    }

    }



int charcounting(char tocount[50]){
    int count =0;
    for (int i=0 ; i<50 ; i++){
        if(tocount[i] == '\0'){
            break;

        }else{

            count++;
        }
    }
  return count;
}
void gmailvalid(char gmail[50]){

    int here = 0;
    int v1 = 0;
    int v2 = 0;
    char fgmail[10] = {'@','g','m','a','i','l','.','c','o','m'};

    int i =0;
    for ( i =0; i<50; i++){
        if(gmail[i]==fgmail[0]){
            here = i;
            break;
        }
    }
    for ( int j = 0; j<10 ; j++){


        if(gmail[here+j]==fgmail[j]){
            v1++;
        }else{
            v2++;
        }
    }

    if (v1 == 10 && gmail[here+10]=='\0'){

        NV = 0;
  }else{
        printf("invalid\n");
        NV = 1;

    }

}


void Register(){

    printf("this is register!\n");
    printf("enter your email:");
    scanf("%s", &Info[globalIndex].email);
    gmailvalid(Info[globalIndex].email);
    if(NV == 1){
        Register();
    }

    efound = -1;
    Strcmp1(Info[globalIndex].email);
    if(efound != 0){
        Register();
    }else{

        printf("Enter your name -");
        scanf("%s", &Info[globalIndex].name );

        printf("Enter your age -");
        scanf(" %d", &Info[globalIndex].age);


        printf("Enter your password -");
        scanf(" %s", &Info[globalIndex].password);
        p1found = -1;
        passcheck1(Info[globalIndex].password);


        if (p1found == 1) {
            printf("Registeration Success!\n");
            globalIndex++;
            userActionSector();
        }


    }

}

void Email(){
    printf("Enter your email -");
    scanf("%s", &Info[z].email);
    gmailvalid(Info[z].email);
    if(NV == 1){
        Email();
    }
}


void passcheck1(char pass[50]) {
    int i = 0;
    int passcount = charcounting(pass);
    int notsame = 0;

    for (int j = 0; j<globalIndex; j++) {
        int same = 0;

        int Infopasscount = charcounting(Info[j].password);
        if (passcount == Infopasscount) {
            for (i = 0; i < passcount; i++) {

                if (pass[i] != Info[j].password[i]) {

                    break;
                } else {
                    same++;
                }

            }

        }
        if(same == passcount){
            printf("Password already taken\n");
            Register();
        }else {
            notsame++;
        }
        if(notsame == globalIndex){
            p1found = 1;
            break;
        }
    }


}

void passcheck(char pass[50] , int Index) {

    int passcount = charcounting(pass);
    int Infopasscount = charcounting(Info[Index].password);
    int same = 0;
    if (passcount == Infopasscount) {
        for (int i = 0; i < passcount; i++) {

            if (pass[i] == Info[Index].password[i]) {

                same++;
            }else{
                break;
            }

        }


    }
    if(same == passcount){
        pfound = 1;
    }else {
        printf("Invalid email or password\n");
        lobby();
    }
}

void loadingAllDataFromFile(){

    FILE *fptr = fopen("dipDB.txt","r");

    if(fptr == NULL){
        printf("Error at loading!\n");
    } else{

        for(int gcc=0; gcc<SIZE ; gcc++){

            fscanf(fptr ,"%d%s%s%s", &Info[gcc].age, Info[gcc].name,Info[gcc].email,Info[gcc].password);

            if(Info[gcc].name[0] == '\0'){
                break;
            }
            globalIndex++;

        }

    }



}
void recordingAllDataToFile(){

    FILE *fptr = fopen("dipDB.txt","w");

    if(fptr == NULL){
        printf("Error at recordingAllDataToFile fun():\n");
    } else{

        for(int gcc=0; gcc<globalIndex; gcc++){


            fprintf(fptr ,  "%d %s %s %s\n", Info[gcc].age , Info[gcc].name , Info[gcc].email  , Info[gcc].password);


        }
        printf("Recording all data to dipDB.txt is complete!\n");
    }

    fclose(fptr);
    exit(1);

}

void userActionSector(){

    int userAction=0;

    printf("Welcome Sir: %s\n",Info[found].name);
    printf("Press 1 to User Action Sector:\n");
    printf("Press 2 to Home:\n");
    printf("Press 3 to Exit:");
    scanf(" %d",&userAction);

    if(userAction == 1){
        printf("this is user action sector:\n");
        recordingAllDataToFile();
        exit(0);

    } else if( userAction == 2){
        Register();
    } else if(userAction == 3){
        recordingAllDataToFile();
    } else{
        printf("Invalid Option!\n");
        userActionSector();
    }
}
