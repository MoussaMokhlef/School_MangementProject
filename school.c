/***************************************************///********************************************************/
/***************************************************///********************************************************/
/* Project name/ school management system          *///*                                                      */
/* Author/Moussa Mokhlef                           *///*         school management system                     */
/* Created data/20/3/2023                          *///*         using double linked list                     */
/*                                                 *///*                                                      */
/***************************************************///********************************************************/
/***************************************************///********************************************************/
#include<stdio.h>
#include"STD_Types.h"
#include<stdlib.h>               
#include<string.h>
//#include <ctype.h>
#include"school.h"
struct Student                         /*  creat struct */
{                                       
	struct Student* back;            
	u8 name_student[MAX_SIZE];
	u8 addrese_student[MAX_SIZE];
	u8 date_birth[SIZE_DATE];
	u32 phone_number;
	u32 I_D;
	u8  Score;
	struct Student* next;
	
};
student * head=NULL;             //global variable Head
student *last=NULL;              //gloabl variablr Last

void MAIN_MENU(void)                 //main menu to show your choise
{
	u8 choise;
	
	while(1)
	{
	printf("******************************************\n");
	printf("   ____________Welcome sir_____________ \n ");
	printf("******************************************\n");
	printf(" ___________what to you want to do___________  \n");
	printf("--------------------------------------------\n");
	printf("1: _____________ADD NEW_STUDENT_____________ \n");
	printf("--------------------------------------------\n");
	printf("2: _____________DELETE_STUDENT______________\n");
	printf("--------------------------------------------\n");
	printf("3: ___________SHOW STUDENT_LIST_____________\n");
	printf("--------------------------------------------\n");
	printf("4: ______________STUDENT_EDIT_______________\n");
	printf("--------------------------------------------\n");
	printf("5: ______________RANK_STUDENT_______________\n");
	printf("--------------------------------------------\n");
	printf("6: ______________STUDENT_SCORE______________\n");
	printf("--------------------------------------------\n");
	printf("7:_____________exit from program____________\n");
	printf("--------------------------------------------\n");
	printf("Your choise is -> ");
	scanf(" %c",&choise);
	printf("%c",choise);
	switch(choise)
	{
		case('1'):                     //ADD NEW_STUDENT FUNCTION
		        ADD_NEW_STUDENT();
				break;
		case('2'):                     //DELETE_STUDENT FUNCTION
		        DELETE_STUDENT();
				break;
		case('3'):                     //SHOW STUDENT_LIST FUNCTION
                SHOW_STUDENT_LIST();
                break;
        case('4'):                    //STUDENT_EDIT FUNCTION
                STUDENT_EDIT();
                break;
        case('5'):                    //RANK_STUDENT FUNCTION
                RANK_STUDENT();
				break;
        case('6'):                    //STUDENT_SCORE FUNCTION
                STUDENT_SCORE();
				break;
		case('7'):                     //Exit from program
		        printf("......GodBye......\n");
				return ;
		        break;
        default:
		        printf("Invalid choice...\n");
				break;
		
	}
	}
	
		

	
	
}
/*******************************************************************************************************************/

void ADD_NEW_STUDENT(void)            //funtion to add new student sorted in list
{
	student* new=(student*)malloc(sizeof(student));
	printf("please entre name of new student         : ");
	fflush(stdin);
	gets(new->name_student);
	printf("please entre addrese of new student      : ");
	gets(new->addrese_student);
	printf("please entre date of birth of new student: ");
	gets(new->date_birth);
	printf("please enter phone number of new student : ");
	fflush(stdin);
	scanf("%d",&(new->phone_number));
	printf("enter I_D of new student                 : ");
	scanf("%d",&(new->I_D));
	printf("enter Score of new student               : ");
	scanf("%d",&(new->Score));
	
	
    if(head==NULL)
    {
        new->next=NULL;
        new->back=NULL;
        head=new;
		last=new;
    }
    else
    {
        new->next=head;
        head->back=new;
        new->back=NULL;
        head=new;
    }
	
	
}
/**************************************************************************************************************/
void SHOW_STUDENT_LIST(void)                              //show sort list of student
{
    SORT_LIST_NAME();                                          //sort fuction name
	
	student* temp=head;
	while(temp !=NULL){                                                  //Display after sorted
		printf("\n*****************************\n");
		printf("\nname student: \t\t %s",temp->name_student);
		printf("\nAddrese of student:\t%s",temp->addrese_student);
		printf("\nDate of birth: \t\t %s",temp->date_birth);
		printf("\nStudent Number: \t %d",temp->phone_number);
		printf("\nStudent ID: \t\t  %d",temp->I_D);
		printf("\nStudent Score:\t\t %d",temp->Score);
		temp=temp->next;
		printf("\n*****************************\n");
	}
	
	
}
/*********************************************************************************************************************/
void DELETE_STUDENT(void)
{
	
	fflush(stdin);
	u8 flag=FALSE;
	u8 arr[MAX_SIZE];
	printf("\nplease enter name student to Deleted->\n");
	gets(arr);
	fflush(stdin);
	if(head==NULL)
	{
		printf(".....school is empty.....\n");
		flag=TRUE;
	}
	else if((strcmp((head->name_student),arr))==LOW)
	{
		head=head->next;
		head->back=NULL;
		flag=TRUE;
		
	}
	else if((strcmp((last->name_student),arr))==LOW)
	{
		last=last->back;
		last->next=NULL;
		flag=TRUE;
	}
	else
	{
		student* temp=head;
	while(head!=NULL)
	{
		if((strcmp((head->name_student),arr))==LOW)
		{
			head->back->next=head->next;
			head->next->back=head->back;
			free(head);
			flag=TRUE;
			break;
		}
		head=head->next;
	}
	    head=temp;
	}
	
	if(flag==FALSE)
	{
		printf("NOT FOUNDED....\n");
	}
	
	
	}
	/****************************************************************************************************/
	
void STUDENT_EDIT(void)         //function to edit elements of student using name
{
	if(head==NULL)              //chick if school is empty
		{
			printf("empty school...\n");
		
		}
	else                        //
	{
		u8 arr3[MAX_SIZE];
	u8 flag=FALSE;
	student* temp=head;
	printf("Enter name of student to edit: ");
	fflush(stdin);
	gets(arr3);
	fflush(stdin);
	while(temp!=NULL)
	{
       
			if(strcmp((temp->name_student),(arr3))==LOW)  //check to found the student to edit
		{
			printf("*********************************\n");
			printf("please entre new name of student: ");
	        fflush(stdin);
         	gets(temp->name_student);
	        printf("please entre new addrese of student: ");
        	gets(temp->addrese_student);
        	printf("please entre new date of birth of student: ");
        	gets(temp->date_birth);
	        printf("please enter new phone number of student: ");
	        fflush(stdin);
	        scanf("%d",&(temp->phone_number));
	        printf("enter new I_D of student: ");
	        scanf("%d",&(temp->I_D));
	        printf("enter new Score of student: ");
	        scanf("%d",&(temp->Score));
			flag=TRUE;
		
		}
		temp=temp->next;
	}
	if(flag==FALSE)
	{
		printf("Invalid Name...\n");
	}
	

	}
	
}
/**********************************************************************************************************/

void STUDENT_SCORE(void)                    //function to edit score of students
{
	if(head==NULL)
		{
			printf("empty school...\n");
			MAIN_MENU();
		}
	else
	{
		student* temp=last;
	while(temp!=NULL)
	{
		printf("%s score= %d\n",temp->name_student,temp->Score);
		printf("please enter new score");
		scanf("%d",&(temp->Score));
		temp=temp->back;
		printf("\n*****************************\n");
	}
	}
	
}
/************************************************************************************************************/
void  RANK_STUDENT(void)                          //function to Display linked of student by score student
{
	SORT_LIST_SCORE();                            //function to sort by score
	student* temp=head;
	while(temp !=NULL){
		printf("\n*****************************\n");
		printf("\nname student: \t\t %s",temp->name_student);
		printf("\nAddrese of student:\t%s",temp->addrese_student);
		printf("\nDate of birth: \t\t %s",temp->date_birth);
		printf("\nStudent Number: \t %d",temp->phone_number);
		printf("\nStudent ID: \t\t  %d",temp->I_D);
		printf("\nStudent Score:\t\t %d",temp->Score);
		temp=temp->next;
		printf("\n*****************************\n");
	}
	
	
}
/*******************************************************************************************************************/
void SORT_LIST_NAME(void)        //function to sort linked list by name_student 
{  
    student *current = NULL;
	student *index = NULL;  
    u32 temp;   
	u8 arr[MAX_SIZE];
	if(head==NULL)
		{
			printf("\n*****************************\n");
			printf("empty school...\n");
			printf("\n*****************************\n");
		}
	else
	{
		  for(current = head; current->next != NULL; current = current->next)
	    {  
 
        for(index = current->next; index != NULL; index = index->next)
			{ 
                                                                        //check between name of student to swap between element of struct
            if(strcmp((current->name_student),(index->name_student))==1)
				{  
                    strcpy(arr,current->name_student);                   //swap between name of student
                    strcpy(current->name_student,index->name_student);
                    strcpy(index->name_student,arr);

                    strcpy(arr,current->addrese_student);                 //swap between addrese_student 
                    strcpy(current->addrese_student,index->addrese_student);
                    strcpy(index->addrese_student,arr);

					strcpy(arr,current->date_birth);                        //swap between date_birth 
                    strcpy(current->date_birth,index->date_birth);
                    strcpy(index->date_birth,arr);
					
					temp=current->phone_number;                            //swap between phone_number of students 
					current->phone_number=index->phone_number;
					index->phone_number=temp;
					
					temp=current->I_D;                                     //swap between I_D of students
					current->I_D=index->I_D;
					index->I_D=temp;
					
					temp=current->Score;                                    //swap between Score of students
					current->Score=index->Score;
					index->Score=temp;
                }  
            }  
        }
	}
       
                                                                               
    
      
}
/*****************************************************************************************************/
void SORT_LIST_SCORE(void)
{  
    student *current = head;
	student *index = NULL;  
    u32 temp;   
	u8 arr[MAX_SIZE];
	if(head==NULL)
		{
			printf("\n*****************************\n");
			printf("empty school...\n");
			printf("\n*****************************\n");
			MAIN_MENU();
		}
	else
	{
		  for(current = head; current->next != NULL; current = current->next)
	    {  
                                                                           //Index will point to student next to current  
        for(index = current->next; index != NULL; index = index->next)
			{ 
               				                                                                     
            if(current->Score<index->Score)        //check between element to swap between element of struct
				{  
                    strcpy(arr,current->name_student);         //swap between name of student
                    strcpy(current->name_student,index->name_student);
                    strcpy(index->name_student,arr);

                    strcpy(arr,current->addrese_student);         //swap between addrese_student 
                    strcpy(current->addrese_student,index->addrese_student);
                    strcpy(index->addrese_student,arr);

					strcpy(arr,current->date_birth);               //swap between date_birth 
                    strcpy(current->date_birth,index->date_birth);
                    strcpy(index->date_birth,arr);
					
					temp=current->phone_number;                   //swap between phone_number of students 
					current->phone_number=index->phone_number;
					index->phone_number=temp;
					
					temp=current->I_D;                              //swap between I_D of students
					current->I_D=index->I_D;
					index->I_D=temp;
					
					temp=current->Score;                       //swap between Score of students
					current->Score=index->Score;
					index->Score=temp;
                }  
            }  
        }
	}
       
                                                                               
    
      
}





