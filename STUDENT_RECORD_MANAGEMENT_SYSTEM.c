// STUDENT RECORD MANAGEMENT SYSTEM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int student_id;
    char student_name[50];
    int student_age;
    float student_cgpa;
    char student_branch[10];
    struct student *next;
};

// Function declarations 
int check_duplicates(struct student *head, int id);
void save_to_file(struct student *head);
struct student *load_from_file(struct student *head);

// ADD STUDENT
struct student *create_student_record(struct student *head)
{
    struct student *newnode, *temp;
    int choice;
    do
    {
        newnode = (struct student *)malloc(sizeof(struct student));
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("\nEnter student ID: ");
        scanf("%d", &newnode->student_id);
        if(check_duplicates(head, newnode->student_id))
        {
            printf("Student ID already exists\n");
            free(newnode);
            return head;
        }
        printf("Enter student name: ");
        scanf("%s", newnode->student_name);
        printf("Enter student age: ");
        scanf("%d", &newnode->student_age);
        printf("Enter student CGPA: ");
        scanf("%f", &newnode->student_cgpa);
        printf("Enter student branch: ");
        scanf("%s", newnode->student_branch);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf("\nDo you want to create another student record?");
        printf("\n1. Yes");
        printf("\n0. No");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
    } while(choice == 1);
    return head;
}

//CHECK DUPLICATE ID
int check_duplicates(struct student *head, int id)
{
    struct student *temp = head;
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

/* PRINT ONE STUDENT */
void print_student(struct student *temp)
{
    printf("\n-----------------------");
    printf("\nSTUDENT ID: %d", temp->student_id);
    printf("\nSTUDENT NAME: %s", temp->student_name);
    printf("\nSTUDENT AGE: %d", temp->student_age);
    printf("\nSTUDENT CGPA: %.2f", temp->student_cgpa);
    printf("\nSTUDENT BRANCH: %s", temp->student_branch);
    printf("\n-----------------------\n");
}

/* DISPLAY STUDENTS */
void display_student_record(struct student *head)
{
    struct student *temp;
    if(head == NULL)
    {
        printf("\nStudent Record list is empty\n");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        print_student(temp);
        temp = temp->next;
    }
}

/* SEARCH STUDENT */
struct student *search_student_details(struct student *head)
{
    struct student *temp = head;
    int id;
    if(head == NULL)
    {
        printf("\nStudent record list is empty\n");
        return NULL;
    }
    printf("\nEnter student ID to search: ");
    scanf("%d", &id);
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

/* UPDATE STUDENT */
void update_student_details(struct student *head)
{
    struct student *temp = head;
    int id;
    if(head == NULL)
    {
        printf("\nStudent record list is empty\n");
        return;
    }
    printf("\nEnter student ID: ");
    scanf("%d", &id);
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            printf("Enter new name: ");
            scanf("%s", temp->student_name);
            printf("Enter new age: ");
            scanf("%d", &temp->student_age);
            printf("Enter new CGPA: ");
            scanf("%f", &temp->student_cgpa);
            printf("Enter new branch: ");
            scanf("%s", temp->student_branch);
            printf("\nStudent updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("\nStudent not found\n");
}

/* DELETE STUDENT */
struct student *delete_student_details(struct student *head)
{
    struct student *temp = head;
    struct student *prev = NULL;
    int id;
    if(head == NULL)
    {
        printf("\nStudent record list is empty\n");
        return head;
    }
    printf("\nEnter student ID to delete: ");
    scanf("%d", &id);
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            if(prev == NULL)
            {
                head = head->next;
                free(temp);
                printf("\nStudent deleted successfully\n");
                return head;
            }
            prev->next = temp->next;
            free(temp);
            printf("\nStudent deleted successfully\n");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nStudent ID not found\n");
    return head;
}

/* COUNT STUDENTS */
int count_number_of_students(struct student *head)
{
    struct student *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/* SORT STUDENTS */
void sort_students(struct student *head)
{
    struct student *i;
    struct student *j;
    int temp_id;
    char temp_name[50];
    int temp_age;
    float temp_cgpa;
    char temp_branch[10];
    if(head == NULL)
    {
        printf("\nStudent record list is empty\n");
        return;
    }
    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->student_id > j->student_id)
            {
                /* Swap ID */
                temp_id = i->student_id;
                i->student_id = j->student_id;
                j->student_id = temp_id;
                /* Swap name */
                strcpy(temp_name, i->student_name);
                strcpy(i->student_name, j->student_name);
                strcpy(j->student_name, temp_name);
                /* Swap age */
                temp_age = i->student_age;
                i->student_age = j->student_age;
                j->student_age = temp_age;
                /* Swap CGPA */
                temp_cgpa = i->student_cgpa;
                i->student_cgpa = j->student_cgpa;
                j->student_cgpa = temp_cgpa;
                /* Swap branch */
                strcpy(temp_branch, i->student_branch);
                strcpy(i->student_branch, j->student_branch);
                strcpy(j->student_branch, temp_branch);
            }
        }
    }
    printf("\nStudents sorted successfully\n");
}

/* SAVE LINKED LIST INTO FILE */
void save_to_file(struct student *head)
{
    FILE *fp;
    struct student *temp;
    fp = fopen("students.txt", "w");
    if(fp == NULL)
    {
        printf("\nError opening students.txt\n");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        fprintf(fp, "%d %s %d %.2f %s\n",
                temp->student_id,
                temp->student_name,
                temp->student_age,
                temp->student_cgpa,
                temp->student_branch);

        temp = temp->next;
    }
    fclose(fp);
    printf("\nData saved to students.txt successfully\n");
}

/* LOAD DATA FROM FILE INTO LINKED LIST */
struct student *load_from_file(struct student *head)
{
    FILE *fp;
    struct student *newnode;
    struct student *temp;
    fp = fopen("students.txt", "r");
    if(fp == NULL)
    {
        printf("\nNo previous student records found\n");
        return head;
    }
    while(1)
    {
        newnode = (struct student *)malloc(sizeof(struct student));
        if(newnode == NULL)
        {
            printf("\nMemory allocation failed\n");
            fclose(fp);
            return head;
        }
        if(fscanf(fp, "%d %s %d %f %s",
                  &newnode->student_id,
                  newnode->student_name,
                  &newnode->student_age,
                  &newnode->student_cgpa,
                  newnode->student_branch) != 5)
        {
            free(newnode);
            break;
        }
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    fclose(fp);
    printf("\nPrevious student records loaded successfully\n");
    return head;
}

/* MAIN */
int main()
{
    struct student *head = NULL;
    int choice;
    head = load_from_file(head);

    do
    {
        printf("\n\n========== STUDENT RECORD MANAGEMENT SYSTEM ==========\n");
        printf("\n1. Add student");
        printf("\n2. Display students");
        printf("\n3. Search student");
        printf("\n4. Update student");
        printf("\n5. Delete student");
        printf("\n6. Count students");
        printf("\n7. Sort students");
        printf("\n8. Exit");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                head = create_student_record(head);
                save_to_file(head);
                break;
            case 2:
                display_student_record(head);
                break;
            case 3:
            {
                struct student *result;
                result = search_student_details(head);
                if(result != NULL)
                {
                    printf("\nStudent found\n");

                    print_student(result);
                }
                else
                {
                    printf("\nStudent not found\n");
                }
                break;
            }
            case 4:
                update_student_details(head);
                save_to_file(head);
                display_student_record(head);
                break;
            case 5:
                head = delete_student_details(head);
                save_to_file(head);
                display_student_record(head);
                break;
            case 6:
                printf("\nTotal number of students: %d\n",
                    count_number_of_students(head));
                break;
            case 7:
                sort_students(head);
                save_to_file(head);
                display_student_record(head);
                break;
            case 8:
                save_to_file(head);
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while(choice != 8);
    return 0;
}