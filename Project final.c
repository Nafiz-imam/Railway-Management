#include<stdio.h>
#include<string.h>
#include <windows.h>
#define max 50

char username[max],passworad[max],gender[max],email[max],phone_number[max];
char log_username[max],log_password[max];
char dhaka [5] = "Dhaka";
char chittagong [11] = "Chittagong";
char khulna [7] = "Khulna";
char sylhet [7] = "Sylhet";
char shonar_bangla [15] = "Shonar Bangla";
char mahanagar [18] = "Mahanagar Express";
char paharika [17] = "Paharika Express";
char chitra [16] = "Chitra Express";
char parabat [16] = "Parabat Express";
char sundarban [18] = "Sundarban Express";
char jayantika [18] = "Jayantika Express";
char first_class [11] = "First Class";
char secend_class [13] = "Secend Class";
int dhaka_2=1, chittagong_2=2, khulna_2=3, sylhe_2=4;
int from, to;
char error[5]="Error";
char friday [6] = "Friday";
char saturday[9] = "Saturday";
char sunday[7] = "Sunday";
char monday[7] = "Monday";
char tuesday [7] = "Tuesday";
char wednesday [10] = "Wednesday";
char thursday [9] = "Thursday";
int time_1 = 8;
int time_2 = 9;
int time_3 = 10;
int time_4 = 12;
int time_5 = 16;
int time_6 = 20;
int time_7 = 22;
int time;


///--------------------------------------Structure Start------------------------------///
struct review{
    char review[200];
}review_1;

struct admin_log_in{
    int admin_user_name;
    int admin_password;
}admin_1;
///--------------------------------------Structure Finish------------------------------///

///--------------------------------------Admin Start------------------------------///
void admin(){
    char read[1000];
    int select;
    system("cls");
    fflush(stdin);
    printf("Name : ");
    scanf("%d",  &admin_1.admin_user_name);
    printf("\nPassword : ");
    scanf("%d",  &admin_1.admin_password);

    if(admin_1.admin_user_name == 1234 && admin_1.admin_password == 1234){
        system("cls");
        printf("\n1. Ticket List.");
        printf("\n2. Account list List.");
        printf("\nSelect : ");
        scanf("%d", &select);
        if (select == 1)
        {
            FILE * file_1;
            file_1 = fopen("ticket.txt", "r");
            while (!feof(file_1))
            {
            fgets(read,1000,file_1);
            printf("%s\n", read);
            }
        fclose(file_1);
        }
        else if (select == 2)
        {
            FILE * file_2;
            file_2 = fopen("account information.txt", "r");
            while (!feof(file_2))
            {
            fgets(read,1000,file_2);
            printf("%s\n", read);
            }
            fclose(file_2);
        }  
    }
}
///--------------------------------------Admin Finish------------------------------///

///--------------------------------------Select station Start------------------------------///
void  select_station(){
    char no1, no2;
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");
    fflush(stdin);

    printf("Select station\nFrom :");
    printf("\na. Dhaka.");
    printf("\nb. Chittagong.");
    printf("\nc. Khulna");
    printf("\nd. Sylhet");
    printf("\nSelect NO :");
    scanf("%c", &no1);
    switch(no1)
    {
    case'a':
        printf("\n%s\n", dhaka);
        from = dhaka_2;
        break;
    case'b':
        printf("\n%s\n", chittagong);
        from = chittagong_2;
        break;
    case'c':
        printf("\n%s\n", khulna);
        from = khulna_2;
        break;
    case'd':
        printf("\n%s\n", sylhet);
        from = sylhe_2;
        break;
    default:
        printf("error\n");
    }

    fflush(stdin);

    printf("\nSelect station\nTo :");
    printf("\na. Dhaka.");
    printf("\nb. Chittagong.");
    printf("\nc. Khulna");
    printf("\nd. Sylhet");
    printf("\nSelect NO :");
    scanf("%c", &no2);
    switch(no2)
    {
    case'a':
        printf("\n%s\n", dhaka);
        to = dhaka_2;
        break;
    case'b':
        printf("\n%s\n", chittagong);
        to = chittagong_2;
        break;
    case'c':
        printf("\n%s\n", khulna);
        to = khulna_2;
        break;
    case'd':
        printf("\n%s\n", sylhet);
        to = sylhe_2;
        break;
    default:
        printf("\nerror\n");
    }

    if((from==1&&to==2) || (from==2&&to==1)){//Dhaka to Chittahong
        if(from==1&&to==2){
            printf("%s to %s\nTrain Name : %s", dhaka, chittagong,shonar_bangla);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", dhaka, chittagong,shonar_bangla);
        }
        else{
            printf("%s to %s\nTrain Name : %s",chittagong, dhaka, mahanagar);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", chittagong, dhaka, mahanagar);
        }
    }
    else if ((from==1&&to==3) || (from==3&&to==1)){//Dhaka to khulna
       if(from==1&&to==3){
            printf("%s to %s\nTrain Name : %s", dhaka, khulna, chitra);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", dhaka, khulna, chitra);
        }
        else{
            printf("%s to %s\nTrain Name : %s", khulna, dhaka, sundarban);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", khulna, dhaka, sundarban);
        }
    }
    else if ((from==1&&to==4) || (from==4&&to==1)){//Dhaka to sylhat
        if(from==1&&to==4){
            printf("%s to %s\nTrain Name : %s", dhaka, sylhet, parabat);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", dhaka, sylhet, parabat);
        }
        else{
            printf("%s to %s\nTrain Name : %s", sylhet, dhaka, jayantika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", sylhet, dhaka, jayantika);
        }
    }
    else if ((from==2&&to==4) || (from==4&&to==2)){//Chittahong to sylhat
        if(from==2&&to==4){
            printf("%s to %s\nTrain Name : %s", chittagong, sylhet, paharika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s", chittagong, sylhet, paharika);
        }
        else{
            printf("%s to %s\nTrain Name : %s", sylhet, chittagong, paharika);
            fprintf(ticket,"\n%s\t\t\t%s\t\t\t%s",sylhet, chittagong, paharika);
        }
    }
    else{
        printf("Error");
    }
    fclose(ticket);
}
///--------------------------------------Select station Finish------------------------------///

///--------------------------------------Select seat Start------------------------------///
void seat_class()
{
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");
    int no1;
    fflush(stdin);
    system("cls");
    printf("Select Seat Class:");
    printf("\n1. First Class.");
    printf("\n2. Secend Class.");
    printf("\nSelect NO :");
    scanf("%d", &no1);
    
    if(no1 == 1){
        printf("\n%s", first_class);
        fprintf(ticket,"\t\t\t%s", first_class);
        fclose(ticket);
        back_in();
    }
    else if(no1 == 2){
        printf("\n%s", secend_class);
        fprintf(ticket,"\t\t\t%s", secend_class);
        fclose(ticket);
    }
    else
    {
        printf("\nerroe");
    }
}
///--------------------------------------Select seat Finish------------------------------///

///---------------------------------------Select Day Start-------------------------------///
void  select_day(){
    char no1, no2;
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");
    ///fseek(ticket,0,SEEK_END);
    fflush(stdin);
    station_1:
    printf("Select Day :");
    printf("\na. %s.", friday);
    printf("\nb. %s.", saturday);
    printf("\nc. %s.", sunday);
    printf("\nd. %s.", monday);
    printf("\ne. %s.", tuesday);
    printf("\nf. %s.", wednesday);
    printf("\ng. %s.", thursday);
    printf("\nSelect NO :");
    scanf("%c", &no1);
    switch(no1)
    {
    case'a':
        printf("\n%s\n", friday);
        fprintf(ticket,"\t\t\t%s", friday);
        fclose(ticket);
        break;
    case'b':
        printf("\n%s\n", saturday);
        fprintf(ticket,"\t\t\t%s", saturday);
        fclose(ticket);
        break;
    case'c':
        printf("\n%s\n", sunday);
        fprintf(ticket,"\t\t\t%s", sunday);
        fclose(ticket);
        break;
    case'd':
        printf("\n%s\n", monday);
        fprintf(ticket,"\t\t\t%s", monday);
        fclose(ticket);
        break;
    case'e':
        printf("\n%s\n", tuesday);
        fprintf(ticket,"\t\t\t%s", tuesday);
        fclose(ticket);
        break;
    case'f':
        printf("\n%s\n", wednesday);
        fprintf(ticket,"\t\t\t%s", wednesday);
        fclose(ticket);
        break;
    case'g':
        printf("\n%s\n", thursday);
        fprintf(ticket,"\t\t\t%s", thursday);
        fclose(ticket);
        break;
    default:
        printf("error\n");
        goto station_1;
    }
    system("cls");
}
///-------------------------------------Select Day Finish-------------------------------///

///---------------------------------------Select Time Start-------------------------------///
void  select_time(){
    char no2;
    system("cls");
    FILE* ticket;
    ticket = fopen("ticket.txt", "a");
    //fseek(ticket,0,SEEK_END);
    fflush(stdin);
    station_2:
    printf("Select Day :");
    printf("\na. %d.", time_1);
    printf("\nb. %d.", time_2);
    printf("\nc. %d.", time_3);
    printf("\nd. %d.", time_4);
    printf("\ne. %d.", time_5);
    printf("\nf. %d.", time_6);
    printf("\ng. %d.", time_7);
    printf("\nSelect NO :");
    scanf("%c", &no2);
    switch(no2)
    {
    case'a':
        printf("\n%d\n", time_1);
        time=time_1;

        break;
    case'b':
        printf("\n%d\n", time_2);
        time=time_2;
        break;
    case'c':
        printf("\n%d\n", time_3);
        time=time_3;
        break;
    case'd':
        printf("\n%d\n", time_4);
        time=time_4;
        break;
    case'e':
        printf("\n%d\n", time_5);
        time=time_5;
        break;
    case'f':
        printf("\n%d\n", time_6);
        time=time_6;
        break;
    case'g':
        printf("\n%d\n", time_7);
        time=time_7;
        break;
    default:
        printf("error\n");
        goto station_2;
    }

    fprintf(ticket,"\t\t\t%d\n", time);
    fclose(ticket);
    back_in();
}
///---------------------------------------Select Time Finish-------------------------------///

///------------------------------------Purches ticket Start----------------------------///
void purcher_ticket(){
    select_station();
    seat_class();
    select_day();
    select_time();
    back_in();
}
///------------------------------------Purches ticket Start----------------------------///

///------------------------------------Create account Start----------------------------///
void registration(char usernme[],char passworad[],char email[],char gender[])
{   
    system("cls");
    FILE* create_account;
    create_account = fopen("account information.txt", "a");

    printf("\t\t\t                   MD. Nafiz Imam Zilani\n\t\t\t                   ID : 193-35-2923\n\t\t\t                   SEC : C\n\t\t\t                   \t\t\t                   COPYRIGHT Nafiz");
	printf("\n\t\t\t******************Create Account******************\n");
	printf("\n\t\t\tusername  :  ");
	gets(username);
	printf("\n\t\t\tNew password  :  ");
	gets(passworad);
	printf("\n\t\t\tE-mail    :  ");
	gets(email);
    printf("\n\t\t\tPhone Number  :  +880");
	gets(phone_number);
	printf("\n\t\t\tGender    :  ");
	gets(gender);

    fprintf(create_account,"Name : %s\nPhone No. : +880%s\nE-mail : %s\nGender : %s\n----------------------------------------------------------------\n", username, phone_number, email, gender);
    fclose(create_account);

}
///------------------------------------Create account Finish----------------------------///

///-------------------------------------Sine In Start------------------------------///
void login(char usernme[],char passworad[],char log_username[],char log_password[])
{
	system("cls");
	printf("\n\t\t\t******************LOG IN******************\n");
	printf("\n\tusernane: ");
	gets(log_username);
	printf("\tPassword: ");
	gets(log_password);
	if(strcmp(username,log_username)==0 && strcmp(passworad,log_password)==0)
	{
		printf("\n\t\tLogin Succeful");
        back_in();
	}
	else
	{
		printf("\n\tusername & Password incorrect!");
	}
}
///--------------------------------------Sine In Finish------------------------------///

///--------------------------------------Food Info Start------------------------------///
void food_info(){///which train sarve which food
    int dastination_chack;
    system("cls");
    food_info:
    printf("\nWhich dastination you want to chack : ");
    printf("\n1. Dhaka To Chittagong.");
    printf("\n2. Dhaka To Sylhet.");
    printf("\n3. Dhaka To Rajshi.");
    printf("\n4. Dhaka To Khulna.");
    printf("\nPress 1-4 to select : ");
    scanf("%d", &dastination_chack);


    if(dastination_chack == 1){
        system("cls");
        printf("Box (1 fruit, 2 chicken Fry, 1 150ml water , sauce) (Included on Suborna Train only with ticket)\nBurger 60/=\nCutlet 60/=\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack == 2){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack == 3){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else if(dastination_chack ==4){
        system("cls");
        printf("Beriny 120/=\nCutlet\nWater 15/=\nTea 10/=\nCoffee 20/=");
    }
    else
    {
        system("cls");
        printf("Didn't enter currect switch");
        goto food_info;
    }
    
}
///--------------------------------------Food Info Finish------------------------------///

///----------------------------------------Track Start---------------------------------///
void sylhet_station(){///Sylhet station
    printf("Sylhet :\nSylhet Railway Station\n|\nKulaura Railway Station\n|\nSreemangal Railway station\n|\nShaistaganj Railway Station");
}

void dhaka_station(){///Dhaka station
    printf("Dhaka :\nKamalapur Railway Station\n|\nDhaka Airport Railway Station\n|\nNarayanganj Railway Station||Gazipur Railway Station\n|\nTangail Railway Station\n|\nGopalganj Railway Station\n|\nBhairab Bazar Railway Station\n|\nFaridpur Railway Station\n|\nNarsingdi Railway Station\n|\nTongi Railway Station\n|\nTejgaon Railway Station\n|\nJoydebpur Railway Station\n|\nB.B. East Railway Station\n|\nKishoreganj Railway Station\n|\nRajbari Railway Station");
}

void chittagong_station(){///Chittagong station
    printf("Chittagong :\nChittagong Railway Station\n|\nAkhaura Railway Station\n|\nAshuganj Railway Station\n|\nChandpur Railway Station\n|\nComilla Railway Station\n|\nFeni Railway Station\n|\nNabinagar Railway Station\n|\nBrahmanbaria Railway Station\n|\nChittagong Railway Station\n|\nLaksam Railway Station");
}

void khulna_station(){///khulna station
    printf("Khulna :\nKhulna Railway Station\n|\nJessore Railway Station\n|\nPhultala Railway Station\n|\nDarshana Railway Station\n|\nMirpur Railway Station\n|\nKustia Railway Station\n|\nChuadanga Railway Station\n|\nDaulatpur Railway Station\n|\nNoapara Railway Station\n|\nPoradha Railway Station\n|\nBheramara Railway Station\n|\nPakshi Railway Station");
}

void rajshi_station(){///Rajshi station
    printf("Rajshi :Akkelpur Railway Station\n|\nJoypurhat Railway Station\n|\nSonatola Railway Station\n|\nNatore Railway Station\n|\nPabna Railway Station\n|\nUllapara Railway Station\n|\nSantahar Railway Station\n|\nPanchbibi Railway Station\n|\nBogra Railway Station\n|\nRaninagar Railway Station\n|\nSingra Railway Station\n|\nFaridpur Railway Station\n|\nSirajganj Railway Station\n|\nRajshahi Railway Station\n|\nAhsanganj Railway Station\n|\nAmnura Railway Station");
}
void track(){//Compleat
    system("cls");
    dhaka_station();
    printf("\n-------------------\n");
    chittagong_station();
    printf("\n-------------------\n");
    khulna_station();
    printf("\n-------------------\n");
    sylhet_station();
    printf("\n-------------------\n");
    rajshi_station();
}

///----------------------------------------Track Finish---------------------------------///

///----------------------------------------Contect Start--------------------------------///
int contect(){//Compleat

    system("cls");
    printf("Website                       =     https://railway.portal.gov.bd\n\n");
    printf("Main offce                    =     Bangladesh Railway Bhaban, 16 Abdul Gani Rd, Dhaka 1000\n\n");
    printf("Dhaka Station                 =     9358634\n");
    printf("Dhaka Cantonment Station      =     9112007\n");
    printf("Dhaka Airport Station         =     8924239\n");
    printf("Chittagong Station            =     635162\n");
    printf("Sylhet Station                =     716061\n");
    printf("Khukna Station                =     760691\n");
    printf("Rajshi Station                =     774122\n");
}
///----------------------------------------Contect Finish--------------------------------///

///--------------------------------------Review Start------------------------------///
void review(){
    system("cls");
    FILE * review;
    review = fopen("review.txt", "a");

    if(review == NULL){
        printf("File does't exist");
    }
    else{
        fflush(stdin);
        printf("Give your feedback (Max 200 latter) : ");
        gets(review_1.review);
        fprintf(review,"Review : \n%s\n", review_1.review);
        fclose(review);
    }

}
///--------------------------------------Review Finish------------------------------///

int back_in(){
    char select_option,log;
    system("cls");
    printf("Function\n");
    printf("a. Purcher Ticket\n");
    printf("b. Food Info\n");
    printf("c. Track\n");
    printf("d. Contect\n");
    printf("e. Review\n");
    printf("f. Admin log in\n");

    printf("Enter charecter : ");
    scanf("%c", &select_option);
    system("cls");

    switch(select_option)
    {
    case'a':
        purcher_ticket();
        break;
    case'b':
        food_info();
        break;
    case'c':
        track();
        break;
    case'd':
        contect();
        break;
    case'e':
        review();
        break;
    case'f':
        admin();
        break;
    default:
        printf("\n%s", error);
    }
}

int main()
{
    registration(username,passworad,email,gender);
	login(username,passworad,log_username,log_password);
    return 0;
}