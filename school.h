#ifndef SCHOOL_H
#define SCHOOL_H

#define      TRUE                1
#define      FALSE               0
#define      HIGH                1
#define      LOW                 0
#define      MAX_SIZE            30
#define      SIZE_DATE           12

typedef struct Student student;


void MAIN_MENU(void);
void ADD_NEW_STUDENT(void);
void SHOW_STUDENT_LIST(void);
void DELETE_STUDENT(void);
void STUDENT_EDIT(void);
void STUDENT_SCORE(void);
void  RANK_STUDENT(void);
void SORT_LIST_NAME(void);
void SORT_LIST_SCORE(void);



#endif