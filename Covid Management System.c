#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[100];
    int age;
    char gender[10];
    char nid[10];
    char username[100];
    char password[100];
    char vacname[100];
    int dose;

}person[500];




int i=0,new_age=18;

void fillStructure()
{

         int x;
         printf("____VACCINE REGISTRATION____\n");
         fflush(stdin);

         printf("NAME:");
         gets(person[i].name);
         fflush(stdin);

         printf("AGE(MINIMUM %d):", new_age);
         scanf("%d", &person[i].age);

         if(person[i].age< new_age)
         {
         printf("SORRY! REGISTRATION WITHOUT NID IS NOT AVAILABLE YET!");
         exit(1);
         }

         fflush(stdin);

         printf("GENDER(MALE/FEMALE):");
         gets(person[i].gender);
         fflush(stdin);

         do
         {
           printf("NID(MUST BE 7 DIGIT!):");
           gets(person[i].nid);
           x = strlen(person[i].nid);
         }while(x<7 || x >7);


    fflush(stdin);

    printf("CREATE A USERNAME TO LOGIN LATER:");
    gets(person[i].username);

    printf("CREATE A PASSWORD TO LOGIN LATER:");
    gets(person[i].password);

    printf("REGISTRATION COMPLETE!\n");

    printf("\n");

    i=i+1;

}












void modifyStructure()
{


    char check[10];

    char input_nid[10];
    char username[100], password[100];

    int x,j, flag=0, count = 3;

    printf("____CORRECTION MENU____\n");
    fflush(stdin);
    printf("7 DIGIT NID NO:");
    gets(input_nid);

    for(j=0; j<i; j++)
    {
        if(strcmp(person[j].nid , input_nid)==0)
        {
            flag = 1;

            while(count!=0)
            {
                printf("YOU HAVE %d CHANCES TO GET YOUR PASSWORD CORRECT\n", count);

                fflush(stdin);
                printf("USER NAME:");
                gets(username);

                printf("PASSWORD:");
                gets(password);


                if(strcmp(person[j].username, username)==0 && strcmp(person[j].password, password)==0 )
                {


                     fflush(stdin);
                     printf("WRITE THE NAME OF THE FIELD(UPPER CASE) TO MODIFY(NAME/AGE/GENDER/NID):");
                     gets(check);

                     if(strcmp(check , "NAME")==0)
                     {
                         printf("NEW NAME:");
                         gets(person[j].name);
                     }

                    if(strcmp(check , "AGE")==0)
                    {
                       printf("NEW AGE:");
                       scanf("%d", &person[j].age);
                    }

                    if(strcmp(check , "GENDER")==0)
                    {
                       printf("NEW GENDER:");
                       gets(person[j].gender);
                    }

                    if(strcmp(check , "NID")==0)
                    {
                           do
                           {
                              printf("NEW NID(7 DIGIT):");
                              gets(person[j].nid);
                              x= strlen(person[j].nid);
                           }while(x<7 || x>7);

                    }


                    printf("CHANGED SUCCESSFULLY\n\n");
                  break;
                }

                      else
                      {
                         printf("WRONG USER NAME/PASSWORD");
                         printf("\n\n");

                      }

                     count-=1;

            }


        }

    }

        if(flag == 0)
        {
            printf("SORRY! NOT FOUND!");
            printf("\n");
        }




   printf("\n");
}












void printStructure()
{

                printf("\n\t%d NUMBER PATIENT STATUS\n",i);
                printf("\n\tNAME:%s", person[i-1].name);
                printf("\n\tAGE:%d", person[i-1].age);
                printf("\n\tGENDER:%s", person[i-1].gender);
                printf("\n\tNID:%s", person[i-1].nid);
                printf("\n");



}













void adminlogin()
{


    char admin_user[100] = "admin";
        char admin_pass[100] = "adminpass";
           int input;


            char user[100], pass[100];
              printf("\n\t____ADMIN LOGIN____");

              printf("\n\tUSER NAME:");
              scanf("%s",user);
              printf("\n\tPASSWORD:");
              scanf("%s",pass);
           printf("\n");

                    if (strcmp(user, admin_user) ==0 && strcmp(pass, admin_pass) == 0)
                      {
                           printf("\n\tACCESS GRANTED!\n ");
                              while(1)
                              {


                                   printf("\n\t____COVID-19 MANAGEMENT SYSTEM____" );
                                   printf("\n\t           SUROKKHA \\^/ " );
		                           printf("\n\t____ADMIN MENU____" );
                                   printf("\n\t1. VIEW ALL REGISTRATION INFORMATION" );
		                           printf("\n\t2. VIEW ALL REGISTRATION INFORMATION WITH GIVEN VACCINE" );
		                           printf("\n\t3. UPDATE INFORMATION ABOUT GIVEN VACCINE NAME AND DOSE" );
		                           printf("\n\t0. MAIN MENU" );

                                   printf("\n\tINSERT CHOICE(0/1/2/3):");
                                   scanf("%d", &input);

                                   if(input == 0)
                                   {
                                       break;
                                   }

                                   switch(input)
                                   {
                                   case 1:
                                    adminview();
                                    break;

                                   case 2:
                                    vacdetails();
                                    break;

                                   case 3:
                                     vaccupdate();
                                     break;
                                   }

                                   printf("\nPRESS ENTER KEY TO CONTINUE");
                                   getch();

                              }
                      }

                      else
                      {
                          printf("\nACCESS DENIED\n");

                      }


}













void adminview()
{

    int j;

    printf("\n\t____VIEWING %d REGISTRATION____\n",i);

    printf("\n\n");
    for(j=0; j<i; j++)
    {
                printf("\tNAME:%s\n", person[j].name);

                printf("\tAGE:%d\n", person[j].age);

                printf("\tGENDER:%s\n", person[j].gender);

                printf("\tNID:%s", person[j].nid);

                printf("\n");

    }
}







void vaccupdate()
{
    printf("\n\t____VACCINE NAME & DOSE NUMBER UPDATE MENU____");
    int x;
    printf("\n\tPATIENT NUMBER:");
    fflush(stdin);
    scanf("%d",&x);
    x=x-1;

    struct data preson[500];
    printf("\n\tVACCINE NAME(AstraZeneca/Pfizer/Sinopharm/Moderna):");
    fflush(stdin);
    gets(person[x].vacname);


    printf("\n\tGIVEN DOSE:");
    scanf("%d", &person[x].dose);

}








void vacdetails()
{

   int j;

    printf("\n\t____VIEWING %d REGISTRATION____\n",i);

    printf("\n\n");
    for(j=0; j<i; j++)
    {
                printf("\tNAME:%s\n", person[j].name);

                printf("\tAGE:%d\n", person[j].age);

                printf("\tGENDER:%s\n", person[j].gender);

                printf("\tNID:%s\n", person[j].nid);

                printf("\tVACCINE NAME:%s\n", person[j].vacname);

                printf("\tGIVEN DOSE:%d\n", person[j].dose);

                printf("\n");

    }
}














void userlogin()
{
    int input;


    while(1)
    {



        printf("\n\t____COVID-19 MANAGEMENT SYSTEM____" );
        printf("\n\t           SUROKKHA \\^/ " );
		printf("\n\t____USER MENU____" );
		printf("\n\t1. REGISTRATION STATUS" );
		printf("\n\t2. CORRECTION" );
		printf("\n\t0. RETURN TO MAIN MENU" );
        printf("\n\t" );
        printf("\n\tINSERT YOUR CHOICE(0/1/2):");
        scanf("%d", &input);


        if(input == 0)
        {
            break;
        }

        switch(input)
        {
        case 1: viewform();
        printf("\n\nPRESS ENTER KEY TO CONTINUE\n");
        getch();

        break;

        case 2: modifyStructure();
        printf("\n\nPRESS ENTER KEY TO CONTINUE\n");
        getch();
        break;




        }

    }


}












void viewform()
{
    char input_nid[100], user[100], pass[100];
    int j, found =0;

    printf("VIEW YOUR RESGISTRATION FORM\n");

       fflush(stdin);
       printf("NID:");
       gets(input_nid);

            for(j=0; j<i; j++)
            {
                if(strcmp(person[j].nid , input_nid)==0)
                {
                    found = 1;
                    printf("USERNAME:");
                    gets(user);

                    printf("PASSWORD:");
                    gets(pass);

                    if(strcmp(person[j].username , user)==0 && strcmp(person[j].password, pass)==0)
                    {
                        printf("\n");
                        printf("YOUR RESGISTRATION FORM\n");
                        printf("NAME:%s\n", person[j].name);
                        printf("AGE:%d\n", person[j].age);
                        printf("GENDER:>%s\n", person[j].gender);
                        printf("NID:>%s\n", person[j].nid);
                        printf("\n");

                    }

                    else{printf("WRONG USERNAME OR PASSWORD\n");}

                }
            }

            if(found == 0)
            {
                printf("NOT REGISTERED!");
            }

}














void hotline()
{
 printf("\n\t____COVID-19 MANAGEMENT SYSTEM____" );
 printf("\n\t           SUROKKHA \\^/ " );
 printf("\n\t___HOTLINE___\n\t333 National Call Center \n\t16263 Health Portal \n\t10655 IEDCR \n\t09666777222 Covid-19 Telehealth\n\t" );
}

















int main()
{
    int input, in;

    while(1)
    {
        system("COLOR 3F");
        printf("\n\t____COVID-19 MANAGEMENT SYSTEM____" );
		printf("\n\t           SUROKKHA \\^/ " );
		printf("\n\t1. VACCINE REGISTRATION" );
		printf("\n\t2. USER LOGIN" );
		printf("\n\t3. ADMIN LOGIN" );
		printf("\n\t4. HOTLINE");
		printf("\n\t0. TO LOGOUT" );
        printf("\n\t___DEVELOPED BY___\n\tMd. Shakhawat Hossain\a" );
        printf("\n\tCHOOSE YOUR OPTION(0/1/2/3/4):");
        scanf("%d", &input);

        switch(input)
        {

          case 1:

              if(input == 1 && i<500)
              {
                  fillStructure();


               while(1)
               {


                  printf("\n\t____COVID-19 MANAGEMENT SYSTEM____" );
		          printf("\n\t           SUROKKHA \\^/ " );
                  printf("\n\t2.REGISTRATION STATUS");
                  printf("\n\t3.CORRECTION");
                  printf("\n\t0.MAIN MENU");


                  printf("\n\tCHOOSE YOUR OPTION(2/3/0):");
                  scanf("%d", &in);

                  if(in == 2)
                  {

                     printf("\n\n");
                     printStructure();
                     printf("PRESS ENTER KEY TO CONTINUE");
                     getch();
                  }

                  if(in == 3)
                  {

                      modifyStructure();
                      printf("\n\nPRESS ENTER KEY TO CONTINUE");
                      getch();

                  }
                  if(in == 0)
                  {
                      break;
                  }
              }

              break;

              }

           case 2:
               userlogin();
               break;


           case 3:

                adminlogin();
                printf("PRESS ENTER KEY TO CONTINUE");
                getch();
           break;

           case 4:

                hotline();
                printf("PRESS ENTER KEY TO CONTINUE");
                getch();
             break;

           case 0: {exit(1);}
                break;

           default:
            printf("\nINVALID!\n");
            getch();
            break;

        }

    }

    return 0;
}

