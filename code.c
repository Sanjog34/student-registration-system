#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<string.h>
void registeration();
void attendance(); 
void check(); 
int facualty(); 
int year(); 
void change();
void add();
void print(int a,int b);
int Count(int a,int b);
void printstd(int a,int b);
void kick();
struct student{ 
 char name[100][50]; 
 int count[100]; 
 int phn_no[100]; 
 int day;
}stu[10][10]; 


int main(){ 
 int a;
 printf(" ______________________________________________________________________________\n");
 printf("|                        student Registeration/attendance                      |\n");
 printf("|______________________________________________________________________________|\n");
 printf("|                                 select option                                |\n"); 
 printf("|______________________________________________________________________________|\n");
 printf("|1.               Registeration                                                |\n"); 
 printf("|2.               attendance                                                   |\n"); 
 printf("|3.               check attendance                                             |\n"); 
 printf("|4.               edit                                                         |\n");
 printf("|______________________________________________________________________________|\n");
 scanf("%d",&a); 
 switch(a){
 case 1: 
 registeration(); 
 break; 
 case 2: 
 attendance();  
 break; 
 case 3: 
 check(); 
 break; 
   case 4: 
    system("cls");
     printf("1. rename\n");
     printf("2. add student\n"); 
     printf("3. remove\n");
     scanf("%d",&a); 
     switch(a){
     case 1: 
     change(); 
     break; 
     case 2: 
     add();  
     break; 
     case 3: 
     kick(); 
     break;
 } 
 break; 
 default :
 	printf("invalid");
 	getch();
 	system("cls");
 	main();
 	break;
 } 
} 
int facualty(){ 
 system("cls"); 
 int a; 
 printf(" select facualty\n");  
 printf("1. BEI\n"); 
 printf("2. BEL\n"); 
 printf("3. BCE\n"); 
 printf("4. BCT\n"); 
 printf("5. BGE\n"); 
 printf("6. BME\n"); 
 printf("7. BAME\n");
 scanf("%d",&a); 
 return(a);  
} 
int year(){  
 int a; 
 printf(" select year\n");  
 printf("1. 1st\n"); 
 printf("2. 2nd\n"); 
 printf("3. 3rd\n"); 
 printf("4. 4th\n");  
 scanf("%d",&a); 
 system("cls"); 
 return(a); 
}


void registeration(){ 
 int a,b,c,l=0; 
 a=facualty(); 
 b=year();
 printf("enter no. of students: "); 
 scanf("%d",&c); 
printf("\n\n"); 
print(a,b); 
 for( int i=1;i<=c;i++){ 
 printf("roll no %d\n",i);
 fflush(stdin);
 printf("name: "); 
 gets(stu[a][b].name[i]);
}
printf("registeration completed!!\n");
 getch(); 
system("cls"); 
main(); 
} 
void check(){ 
 int a,b,c,i,count,p; 
 a=facualty(); 
 b=year(); 
print(a,b);
 	count=Count(a,b);
  if(count!=0){
  		printf("total classes %d :\n",stu[a][b].day);
 printf(" ___________________________________________________________________________________________________________ \n"); 
 printf("|roll no.|      student's name                                          |attendance  |     att.percentage   |\n"); 
 printf("|________|______________________________________________________________|____________|______________________|\n"); 
for( int i =1;i<=48;i++){ 
 if(strlen(stu[a][b].name[i])!=0){
 	if(stu[a][b].day==0){
 		printf("attendance not taken yet\n");
 		getch();
 		system("cls");
 		main();
	 }
	 else{
	 
 	p=(stu[a][b].count[i]*100)/stu[a][b].day;
 	 printf("| %d\t | ",i); 
 printf("\t%-50s\t| \t%-5d|      \t\t%-4d|",stu[a][b].name[i],stu[a][b].count[i],p);  
 printf("\n");
 printf("|        |                                                              |            |                      |");   
 printf("\n");
}
 }
}
 printf("|________|______________________________________________________________|____________|______________________|\n"); 
 getch(); 
system("cls");
main(); 
} 
else{
	printf("students not registered yet.");
	getch();
	main();
}
}
void attendance(){
int a,b,rollno,opt,count; 
 a=facualty(); 
 b=year();
  	count=Count(a,b);
  if(count!=0){ 
  stu[a][b].day++;
  printf("day %d\n",stu[a][b].day);
  print(a,b);
printstd(a,b); 
 printf("enter roll no. of present students and press 0 to end attendance\n");
  do{ 
scanf("%d",&rollno); 
if(strlen(stu[a][b].name[rollno])!=0){

 stu[a][b].count[rollno]++; 
 }
} 
while(rollno!=0); 
printf("attendance completed!!\n");

 getch(); 
 system("cls");
main(); 
}
else  {
	 print(a,b);
	printf("students not registered yet.\n\n\t\tpress 1 to take attendance and 0 to return to main menu.\n");
	scanf("%d",&opt);
	if(opt==1){
		attendance();
	}
	else {
	system("cls");
	main();
}
}
}
void print(int a,int b){
	printf("\n\n"); 
printf(" ______________________________\n"); 
 switch(a){ 
 case 1: 
printf("|        facualty=BEI          |\n"); 
 break; 
 case 2: 
printf("|        facualty=BEL          |\n"); 
 break; 
 case 3: 
printf("|        facualty=BCE          |\n"); 
 break;  
 case 4: 
printf("|        facualty=BCT          |\n"); 
 break; 
 case 5: 
printf("|        facualty=BGE          |\n"); 
 break; 
 case 6: 
printf("|        facualty=BME          |\n"); 
 break; 
 case 7: 
printf("|        facualty=BAME         |\n");
 break; 
 } 
 switch(b){ 
 case 1: 
printf("|          year=1st            |\n"); 
 break; 
 case 2: 
printf("|          year=2nd            |\n"); 
 break; 
 case 3: 
printf("|          year=3rd            |\n"); 
 break;  
 case 4: 
printf("|          year=4th            |\n"); 
 break; 
 default: 
printf("invalid\n"); 
  
} 
printf("|______________________________|\n");
printf("\n\n\n");
}
void change(){
	int a,b,rollno,count;
	int opt; 
 a=facualty(); 
 b=year();
 	count=Count(a,b);
  if(count!=0){
 label :
printstd(a,b);
 label2 :
 printf("enter roll no:");
 scanf("%d",&rollno);
 if(strlen(stu[a][b].name[rollno])!=0){
  printf("\n\nname to be edited :%s",stu[a][b].name[rollno]);
  printf("\nnew name :");
  fflush(stdin);
  gets(stu[a][b].name[rollno]);
  printf("\nchanged successfully.\n\npress 1 to rename student or press 0 to return to main menu\n");
  scanf("%d",&opt);
  if(opt==1){
  	system("cls");
 goto label;
  }
  else {
  system("cls");
  main();
}
}
else {
printf("student not registered for roll no %d\ntry another roll no.\n",rollno);	
goto label2;
}
}
else {
	 print(a,b);
printf ("\n\nstudents not registered yet\n");
getch();
system("cls");
main();
 } 
}
void add(){
		int a,b,rollno,opt,count;
	up : 
 a=facualty(); 
 b=year();
  	count=Count(a,b);
  if(count!=0){
    down :
printf("enter the roll no:");
scanf("%d",&rollno);
if(strlen(stu[a][b].name[rollno])==0){

printf("enter the name of student :");
fflush(stdin);
gets(stu[a][b].name[rollno]);
printf("enter contact number :");
scanf("%d",&stu[a][b].phn_no[rollno]); 
printf("student added successfully.\npress 1 to add students again and 0 to go back to main menu.:");
scanf("%d",&opt);
if(opt==1){
	printf("\n\ndo you want to add student in:\n 1.same class\n2.different class\n");
	scanf("%d",&opt);
	if(opt==1){
		system("cls");
		goto down;
	}
	else {	
		system("cls");
	goto up;
}
}
else main();
}
else {
	printf("student already exists with name %s",stu[a][b].name[rollno]);
	getch();
		system("cls");
		goto down;	
}
}
else {
	 print(a,b);
	printf("\n\nstudents not registered yet.\n");
	getch();
	system("cls");
	main();
}
}
int Count(int a,int b){
	int count=0;
	for(int i=1;i<=48;i++){
		if(strlen(stu[a][b].name[i])!=0){
			count++;
		}
	}
	return count;	
}
void printstd(int a,int b){
 printf(" ________________________________________________________________________\n"); 
 printf("|roll no.       student's name                                           |\n"); 
 printf("|________________________________________________________________________|\n"); 
for( int i =1;i<=48;i++){ 

 if(strlen(stu[a][b].name[i])!=0){
 printf("| %d\t ",i); 
 printf("\t%-50s\t |",stu[a][b].name[i]);  
 printf("\n");
 printf("|                                                                        |");   
 printf("\n");
} 
}
 printf("|________________________________________________________________________|\n\n"); 
}
void kick(){
	int a,b,rollno,count;
	int opt; 
 a=facualty(); 
 b=year();
 	count=Count(a,b);
  if(count!=0){
 label3 :
printstd(a,b);
 label4 :
 printf("enter roll no:");
 scanf("%d",&rollno);
 if(strlen(stu[a][b].name[rollno])!=0){
strcpy(stu[a][b].name[rollno],stu[a][b].name[49]);
 stu[a][b].count[rollno]=stu[a][b].count[49];
 
  printf("\ndeleted successfully.\n\npress 1 to delete student or press 0 to return to main menu\n");
  scanf("%d",&opt);
  if(opt==1){
  	system("cls");
 goto label3;
  }
  else {
  system("cls");
  main();
}
}
else {
printf("student not registered for roll no %d\ntry another roll no.\n",rollno);	
goto label4;
}
}
else {
	 print(a,b);
printf ("\n\nstudents not registered yet\n");
getch();
system("cls");
main();
 } 
}
	
	
	

