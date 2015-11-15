#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
typedef struct student{
    	int ID;
	char MIS[20];
    	char name[20];
   	char add[20];
   	char parname[20];
   	int age;
	char sex[10];
    	int class;
    	char phone_no[200];
	int attend;
	int msub1,msub2,msub3,msub4,msub5;
}student;
student student1;
int option,choice,a;
int at[SIZE];
int id[SIZE];
int count;
int s1[SIZE],s2[SIZE],s3[SIZE],s4[SIZE],s5[SIZE];
int total[SIZE];
char name[SIZE][SIZE];
char user[20];
char pwd[20];
FILE *fp,*fr;
void login();
void staff_login();
void student_login();
void remov();
void menu1();
void menu2();
void addstudent();
void deletestudent();
void displayinfo();
void updatestudent();
void search();
void sort();
void stud_attend();
void stud_marks();
void par_stud_marks();
void count1();
int main(){
	while(1){
	printf("LOGIN\n");
	printf("1.staff\n 2.student\n 3.exit\n");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			staff_login();
			break;
		case 2:
			student_login();
			break;
		case 3:
                        exit(1);
        default :
              printf("Wrong choice\n");
              break;

		}
	}
}
void menu1(){
	while(1){
	printf("=========================================================STAFF MENU===================================================================\n");
	printf("[1].Add student\n");
	printf("[2].Delete student\n");
	printf("[3].Display student\n");
	printf("[4].Update student\n");
	printf("[5].Search student\n");
	printf("[6].sort information\n");
	printf("[7].student attendance\n");
	printf("[8].student marks\n");
	printf("[9].particular student marks\n");
	printf("[10].remove file\n");
	printf("[11].total number of student\n");
	printf("[12].Exit\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			addstudent();
			count++;
			break;
		case 2:
			deletestudent();
			break;
		case 3:
			displayinfo();
			break;
		case 4:
			updatestudent();
			break;
		case 5:
			search();
			break;		
		case 6:
			sort();
			break;
	
		case 7:
			stud_attend();
			break;
		case 8:
			stud_marks();
			break;
		case 9:
			par_stud_marks();
			break;
		case 10:
			remov();
			break;
		case 11:
			count1();
			break;
		case 12:
			printf("enter your choice\n");
			scanf("%d",&a);
			if(a==1){
				printf("==========================================STAFF LOGIN===============================================\n");
				staff_login();
			}
			else if(a==2){
				printf("=============================================STUDENT LOGIN===========================================\n");
				student_login();
			}
			else{
				exit(1);
			}
			default :
				printf("Wrong choice\n");
				break;
		}
	}
}
void menu2(){
	while(1){
		printf("=====================================================STUDENT MENU=======================================================\n");
     	   	printf("[1].view information\n");
        	printf("[2].Search student\n");
		printf("[3].sort information\n");
     		printf("[4].Exit\n");
        	scanf("%d", &option);
       		switch(option){
			case 1:
				displayinfo();
                       		 break;
               		case 2:
				search();
                        	break;
			case 3:
				sort();
				break;
                	case 4:
                        	printf("enter your choice\n");
                        	scanf("%d",&a);
                        	if(a==1){
					printf("==============================================STAFF LOGIN===========================================================\n");
          				staff_login();
				}
                        	else if(a==2){
                          	      printf("===================================================STUDENT LOGIN=========================================================\n");
                               	      student_login();
                        	}
                        	else{
                                	exit(1);
                        	}
                	default :
                       	  	printf("Wrong choice\n");
                       	 	break;
		}
        }
}

/* function */
void staff_login() {
	char fname[20]="staff";
	printf("Enter username and password for staff login\n");
	scanf("%s %s", user,pwd);
	if(strcmp(user,fname)==0) {
		if(strcmp(pwd,fname)==0){
			menu1();
		}
		else {
			printf("please enter correct username and password\n");
		}
	}	
}

void student_login() {
        fp=fopen("st111.dat","r");
        printf("Enter username and password for student login\n");
        scanf("%s %s",user,pwd);
	 while(fread(&student1,sizeof(student1),1,fp)==1){
         	if(strcmp(user,student1.MIS)==0) {
                	if(strcmp(pwd,student1.MIS)==0){
               			 menu2();
        		}
		}
	}
	printf("enter correct username and password\n");
}
void remov(){
   	int status;
   	char file_name[25];
	printf("Enter the name of file you wish to delete\n");
   	scanf("%s",file_name);
 	status = remove(file_name);
 	if( status == 0 )
     		 printf("%s file deleted successfully.\n",file_name);
   	else
   	{
      		printf("Unable to delete the file\n");
      		perror("Error\n");
   	}
 }
void addstudent() {
	int i, n;
	fp =  fopen("st111.dat","a+");
	if(fp ==NULL) {
		printf("file doesn't exist\n");
		return;
	}
	printf("enter how many student you i have to add\n");
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		printf("\n**************ADDING DATA***************\n");
 		printf("\nEnter ID : ");
		scanf("%d",&student1.ID);
		printf("Enter MIS : ");
		scanf("%s",student1.MIS);
    		printf("Enter Name : ");
     		scanf("%s",student1.name);
     		printf("Enter age : "); 
		scanf("%d",&student1.age);
                printf("Enter Sex : ");	   
		scanf("%s",student1.sex);
                printf("Enter address : ");
                scanf("%s",student1.add);
		printf("Enter parents name : ");
                scanf("%s",student1.parname);
		printf("Enter standard:");
		scanf("%d",&student1.class);
		printf("Enter mobile number :");
                scanf("%s",student1.phone_no);
		printf("enter the attendance\n");
		scanf("%d",&student1.attend);
		printf("Enter the marks obtain in subject\n");
       		scanf("%d %d %d %d %d",&student1.msub1,&student1.msub2,&student1.msub3,&student1.msub3,&student1.msub4,&student1.msub5);
		fwrite(&student1,sizeof(student1),1,fp);
	}	
	fclose(fp);
}
void deletestudent() {
	char name[20];
	printf("enter name student you have to delete\n");
        scanf("%s", name);
	fp=fopen("temp.dat","wb");
	fr=fopen("st111.dat","rb+");
	while(fread(&student1,sizeof(student1),1,fr)==1){
		if(strcmp(student1.name,name)!=0)
		fwrite(&student1,sizeof(student1),1,fp);
	}
	fclose(fr);
	fclose(fp);
	remove("st111.dat");
	rename("temp.dat","st111.dat");
	fr=fopen("st111.dat","rb+");
}
void displayinfo(){
	        printf("\n\t\t====================================================================\n\t\tINFORMATION OF STUDENT\n\t\t==========================================================================\n");
        	fp = fopen("st111.dat", "r");
		    if(fp ==NULL) {
                	printf("file doesn't exist\n");
                }
		    printf("|ID  |MIS\t|NAME\t|AGE  |SEX  |ADDRESS  |PARENTS NAME   |CLASS  |PHONE_NO.  |ATTENDANCE  |SUB1  |SUB2  |SUB3  |SUB4  |SUB5   |\n");
       		while(fread(&student1,sizeof(student1),1,fp)==1)
       			printf("|%-3d| %-8s| %-8s| %-4d| %-4s| %-8s| %-14s| %-5d| %-12s| %-12d| %-5d| %-5d| %-5d| %-5d| %-5d|\n", student1.ID,student1.MIS,student1.name,student1.age,student1.sex,student1.add,student1.parname,student1.class,student1.phone_no,student1.attend,student1.msub1,student1.msub1,student1.msub2,student1.msub3,student1.msub4,student1.msub5);
   		        fclose(fp);
	}
void updatestudent() {
		int records=0;
		fp=fopen("st111.dat","rb+");
		char studname[20];
		printf("Enter the student fname to modify: ");
        scanf("%s", studname);
        rewind(fp);
        while(fread(&student1,sizeof(student1),1,fp)==1){
			if(strcmp(student1.name,studname) == 0){ 
                		printf("\nEnter new MIS,  name,   age,   sex,   address,     parents name,   class,  phone_no, attendance,  marks  :\n ");
				        scanf("%s%s%d%s%s%s%d%s%d%d%d%d%d%d",student1.MIS,student1.name,&student1.age,student1.sex,student1.add ,student1.parname ,&student1.class,student1.phone_no,&student1.attend,&student1.msub1,&student1.msub2,&student1.msub3,&student1.msub4,&student1.msub5);
				        fseek(fp,sizeof(student1)*records,SEEK_SET);             /// move the cursor 1 step back from current position
	 	       		    fwrite(&student1,sizeof(student1),1,fp);                 /// override the record
                 }
		records++;
         }
}

void search(){
	char sname[20];
	int mtotal;
	fp=fopen("st111.dat","rb");
	printf("Search student\n");
                printf("Write name to search: \n");
		        scanf("%s",sname);
                    while(fread(&student1,sizeof(student1),1,fp)){
			              if(strcmp(sname,student1.name)==0){
       			                printf("\nRECORD EXISTS DETAILS ARE :\n");
			                    printf("|%-3d| %-8s| %-8s| %-4d| %-4s| %-8s| %-14s| %-5d| %-12s| %-12d| %-5d| %-5d| %-5d| %-5d| %-5d|\n", student1.ID,student1.MIS,student1.name,student1.age,student1.sex,student1.add,student1.parname,student1.class,student1.phone_no,student1.attend,student1.msub1,student1.msub1,student1.msub2,student1.msub3,student1.msub4,student1.msub5);
			}
	}
	
 	if(strcmp(sname,student1.name)!=0)
   	{
      		printf("\n RECORD NOT EXISTS\n");
        	fclose(fp);
 	}

}

void sort(){
	    int a[20], count=0,i,j,t,c;
        fp=fopen("st111.dat","r");
        while(fread(&student1,sizeof(student1),1,fp))
        {
            a[count]=student1.ID;
            count++;
        }
        c=count;
        for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++)
            	{
                	if(a[i]>a[j])
                	{
                   	 	t=a[i];
                    	a[i]=a[j];
                    	a[j]=t;
                	}
            	}
        }
        printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SORTED_DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("|ID  |MIS\t|NAME\t|AGE  |SEX  |ADDRESS  |PARENTS NAME   |CLASS  |PHONE_NO.  |ATTENDANCE  |SUB1  |SUB2  |SUB3  |SUB4  |SUB5   |\n");
	    count=c;
        for(i=0;i<count;i++){
		rewind(fp);
            	    while(fread(&student1,sizeof(student1),1,fp)==1){
                	if(a[i]==student1.ID)
			        printf("|%-3d| %-8s| %-8s| %-4d| %-4s| %-8s| %-14s| %-5d| %-12s| %-12d| %-5d| %-5d| %-5d| %-5d| %-5d|\n", student1.ID,student1.MIS,student1.name,student1.age,student1.sex,student1.add,student1.parname,student1.class,student1.phone_no,student1.attend,student1.msub1,student1.msub1,student1.msub2,student1.msub3,student1.msub4,student1.msub5);

	       	}

	}
}
void stud_attend(){
	int i;
	fp=fopen("st111.dat","r");
	printf("Attendance of student:\n");
	while(fread(&student1,sizeof(student1),1,fp))
	{
		i=1;
		id[i]=student1.ID;
		strcpy(name[i],student1.name);	
		at[i]=student1.attend;
		printf("%d\t%s\t%d\n",id[i],name[i],at[i]);
		if(at[i]<75)
			printf("%s is not able to attain exam\n",name[i]);
		else
			printf("%s is able to attain exam\n",name[i]);
		i++;
	}

}
void stud_marks() {
	int i;
	float avg[SIZE];
	fp = fopen("st111.dat","rb");
	printf("Marks of student\n");
	  while(fread(&student1,sizeof(student1),1,fp))
        {
             i=1;
             id[i]=student1.ID;
             strcpy(name[i],student1.name);
             s1[i]=student1.msub1;
		     s2[i]=student1.msub2;
		     s3[i]=student1.msub3;
		     s4[i]=student1.msub4;
		     s5[i]=student1.msub5;
		     total[i]=student1.msub1+student1.msub2+student1.msub3+student1.msub4+student1.msub5;
		     avg[i]=total[i]/5.0;
             printf("%d\t %s\t %d\t %d\t %d\t %d\t %d\t %d\t  %f\n",id[i],name[i],s1[i],s2[i],s3[i],s4[i],s5[i],total[i],avg[i]);
             i++;
        }
}
void par_stud_marks() {
	int id,total;
	float avg;
    fp=fopen("st111.dat","rb");
	if(fp==NULL)
    {
		printf("\nError opening empty file\n");
        exit (1);
     }
    printf("enter id of student to calculate  marks\n");
    scanf("%d",&id);
    while(fread(&student1,sizeof(student1),1,fp)){
	if(id==student1.ID){
    total=student1.msub1+student1.msub2+student1.msub3+student1.msub4+student1.msub5;
	avg=total/5;
    printf("|ID  |MIS    |NAME      |SUB1\t|SUB2\t|SUB3\t  |SUB4\t  |SUB5\t   |TOTAL\t  |AVG\t|\n");
	printf("|%-3d|%-8s|%-8s|%-8d|%-8d|%-8d|%-8d|%-8d|%-8d|%-8f|\n",student1.ID,student1.MIS,student1.name, student1.msub1,student1.msub2,student1.msub3,student1.msub4,student1.msub5,total,avg);
    avg=total/5;
	if(avg>=35 || avg == 50)
        printf("%s is pass\n",student1.name);
	else if(avg>=50 || avg==70)
      	printf("%s is pass with second class\n",student1.name);
   	else if(avg>=70 || avg==100)
      	printf("%s pass with first class\n",student1.name);
   	else
       	printf("%s is fail\n",student1.name);
				

		 	}
		}
      	if(id!=student1.ID)
            printf("\n STUDENT OF SUCH ID  DOESNOT EXISTS\n");
}
void count1() {
	printf("Total no. of student%d\n",count);
	int row,col;
	char c;
	row = col = 0;
	fp = fopen("st111.dat","rb");
	if(fp == NULL) {
		printf("\nError\n");
	}
	while((c = getc(fp))!=EOF){
		if((c == '\n') || (c == ' '))
			col++;
		if(c == '\n')
			row++;
	}
	printf("no of student%d\n",row);
}	




