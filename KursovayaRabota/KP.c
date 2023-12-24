#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#define M_SIZE 100
struct  Blog 
{
    char title[100];
    char author[50];
    char category[50];
    char publication_date[20];
    int comment;
    double rating;
};
void display();
int searchByTitle(struct Blog blog[], int size, char searchTitle[]);
int searchByCategory(struct Blog blog[], int size, char searchCategory[]);
void sortByRating(struct Blog blog[], int size);
int writeToFile(struct Blog blog[], int size);
int readToFile(struct Blog blog[], int size);
int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
    struct Blog bloges[M_SIZE];
    int blogCount = 0;
    int choice;
    do
    {
        display();
        printf("������� ��� �����: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            if (blogCount < M_SIZE)
            {
                printf("������� ������ ��� ����� ���������:\n");
                printf("��������� ������: ");
                fgets(bloges[blogCount].title, sizeof(bloges->title), stdin);
                printf("��� ������: ");
                fgets(bloges[blogCount].author, sizeof(bloges->author), stdin);
                printf("��������� ������: ");
                fgets(bloges[blogCount].category, sizeof(bloges->category), stdin);
                printf("���� ����������: ");
                fgets(bloges[blogCount].publication_date, sizeof(bloges->publication_date), stdin);
                printf("���������� ������������: ");
                scanf("%d", &bloges[blogCount].comment);
                printf("�������: ");
                scanf("%lf", &bloges[blogCount].rating);
                blogCount++;
            }
            else {
                printf("���� ������ �����������.\n");
            }
            break;
        case 2:
            if (blogCount == 0)
            {
                printf("��� ��������� ������.\n");
            }
            else
            {
                char searchTitle[50];
                printf("������� ��������� ����� ��� ������: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                int index = searchByTitle(bloges, blogCount, searchTitle);
                if (index != -1)
                {
                    printf("------------------------------------------------\n");
                    printf("��������� ������: %s", bloges[index].title);
                    printf("��� ������: %s", bloges[index].author);
                    printf("��������� ������: %s", bloges[index].category);
                    printf("���� ����������: %s", bloges[index].publication_date);
                    printf("���������� ������������: %d\n", bloges[index].comment);
                    printf("�������: %.2lf\n", bloges[index].rating);
                    printf("------------------------------------------------\n");
                }
            }
            break;
        case 3:
            if (blogCount == 0)
            {   
                printf("��� ��������� ������.\n");
            }
            else
            {
                char searchCategory[50];
                printf("������� ��������� ����� ��� ������: ");
                fgets(searchCategory, sizeof(searchCategory), stdin);
                int index = searchByCategory(bloges, blogCount, searchCategory);
                if (index != -1)
                {
                    printf("------------------------------------------------\n");
                    printf("��������� ������: %s", bloges[index].title);
                    printf("��� ������: %s", bloges[index].author);
                    printf("��������� ������: %s", bloges[index].category);
                    printf("���� ����������: %s", bloges[index].publication_date);
                    printf("���������� ������������: %d\n", bloges[index].comment);
                    printf("�������: %.2lf\n", bloges[index].rating);
                    printf("------------------------------------------------\n");
                }
            }
            break;
        case 4:
            if (blogCount > 0)
            {
                sortByRating(bloges, blogCount);
                printf("\n��������������� ������ �� �������� �� ��������:\n");
                for (int i = 0; i < blogCount; ++i)
                {
                    printf("��������: %s, �������: %.2lf\n", bloges[i].title, bloges[i].rating);
                }
            }
            else {
                printf("���� ������ �����.\n");
            }
            break;
        case 5:
            if (blogCount > 0)
            {
                int res = writeToFile(bloges, blogCount);
                if (res == 0)
                {
                    printf("������ ������� �������� � ����.\n");
                }
                else
                {
                    printf("�� ������� �������� ������ � ����.\n");
                }
            }
            else
            {
                printf("���� ������ �����. ������ ���������� � ����.\n");
            }
            break;
        case 6:
            if (blogCount > 0)
            {
                int res = readToFile(bloges, blogCount);
                if (res == 0)
                {
                    printf("������ ������� ��������� �� �����.\n");
                }
                else
                {
                    printf("�� ������� ��������� ������ �� �����.\n");
                }
            }
            else
            {
                printf("���� ������ �����. ������ ������ �� �����.\n");
            }
            break;
        }
    }
    while (choice != 7);
}
void display() 
{
    printf("����� ���������� � ���� ��� ���������� �������!\n");
    printf("-----------------------------------------------------------\n");
    printf("����:\n");
    printf("1. �������� ����\n");
    printf("2. ����� ����� �� ��������� ������\n");
    printf("3. ����� ����� �� ��������� ������\n");
    printf("4. ���������� �� ��������\n");
    printf("5. ������ � ����\n");
    printf("6. ������ �����\n");
    printf("7. ����� �� ���������\n");
    printf("-----------------------------------------------------------\n");
}
int searchByTitle(struct Blog blog[], int size, char searchTitle[])
{
    printf("\n���������� ������ �� �������� \"%s\":\n", searchTitle);
    for (int i = 0; i < size; ++i)
    {
        if (strstr(blog[i].title, searchTitle) != NULL)
        {
            printf("------------------------------------------------\n");
            return i;
            printf("------------------------------------------------\n");
        }
    }
    return -1;
}
int searchByCategory(struct Blog blog[], int size, char searchCategory[])
{
    printf("\n���������� ������ �� ��������� \"%s:\"\n", searchCategory);
    
    for (int i = 0; i < size; ++i) {
        if (strstr(blog[i].category, searchCategory) != NULL)
        {
            printf("------------------------------------------------\n");
            return i;
            printf("------------------------------------------------\n");
        }
    }
    
    return -1;
}
void sortByRating(struct Blog blog[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)

        {
            if (blog[j].rating < blog[j + 1].rating)
            {
                struct Blog temp = blog[j];
                blog[j] = blog[j + 1];
                blog[j + 1] = temp;
            }
            
        }
    }
    
}
int readToFile(struct Blog blog[], int size)
{
    FILE* file;
    char filename[] = "blog.txt";
    char buf[1000];
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("������ ��� �������� �����");
        return 1;
    }
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        printf("%s", buf);
    }
    fclose(file);
    return 0;
}

int writeToFile(struct Blog blog[], int size)
{
    FILE* file = fopen("blog.txt", "w");
    if (file == NULL)
    {
        printf("�� ������� ������� ���� ��� ������.\n");
        return 0;
    }
    for (int i = 0; i < size; ++i)
    {
        fprintf(file, "���������: %s\n", blog[i].title);
        fprintf(file, "�����: %s\n", blog[i].author);
        fprintf(file, "���������: %s\n", blog[i].category);
        fprintf(file, "����: %s\n", blog[i].publication_date);
        fprintf(file, "���������� ������������: %d\n", blog[i].comment);
        fprintf(file, "�������: %.2f\n", blog[i].rating);
    }
    fclose(file);
    printf("������ ������� �������� � ����.\n");
    return 1;
}