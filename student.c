#include<stdio.h>
#include<string.h>

struct student{
    int id;
    char name[50];   
    float marks;
};

struct student s[100];
int count = 0;

void addStudent(){  
    printf("enter student id: ");
    scanf("%d",&s[count].id);

    printf("enter name: ");
    scanf(" %[^\n]", s[count].name);   

    printf("enter marks: ");   
    scanf("%f",&s[count].marks);

    count++;
    printf("student added successfully\n");
}

void viewStudents() {   
    if(count==0){
        printf("no student found.\n");
        return;
    }

    for(int i=0; i<count; i++){   
        printf("\nid:%d",s[i].id);
        printf("\nname :%s",s[i].name);
        printf("\nmark:%.2f\n",s[i].marks);   
    }
}

void searchStudent(){   
    int id,found=0;
    printf("enter id to search:");
    scanf("%d",&id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("\nStudent Found!");
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}