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
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            if (blogCount < M_SIZE)
            {
                printf("Введите данные для новой программы:\n");
                printf("Заголовок статьи: ");
                fgets(bloges[blogCount].title, sizeof(bloges->title), stdin);
                printf("Имя автора: ");
                fgets(bloges[blogCount].author, sizeof(bloges->author), stdin);
                printf("Категория статьи: ");
                fgets(bloges[blogCount].category, sizeof(bloges->category), stdin);
                printf("Дата публикации: ");
                fgets(bloges[blogCount].publication_date, sizeof(bloges->publication_date), stdin);
                printf("Количество комментариев: ");
                scanf("%d", &bloges[blogCount].comment);
                printf("Рейтинг: ");
                scanf("%lf", &bloges[blogCount].rating);
                blogCount++;
            }
            else {
                printf("База данных переполнена.\n");
            }
            break;
        case 2:
            if (blogCount == 0)
            {
                printf("Нет доступных блогов.\n");
            }
            else
            {
                char searchTitle[50];
                printf("Введите заголовок блога для поиска: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                int index = searchByTitle(bloges, blogCount, searchTitle);
                if (index != -1)
                {
                    printf("------------------------------------------------\n");
                    printf("Заголовок статьи: %s", bloges[index].title);
                    printf("Имя автора: %s", bloges[index].author);
                    printf("Категория статьи: %s", bloges[index].category);
                    printf("Дата публикации: %s", bloges[index].publication_date);
                    printf("Количество комментариев: %d\n", bloges[index].comment);
                    printf("Рейтинг: %.2lf\n", bloges[index].rating);
                    printf("------------------------------------------------\n");
                }
            }
            break;
        case 3:
            if (blogCount == 0)
            {   
                printf("Нет доступных блогов.\n");
            }
            else
            {
                char searchCategory[50];
                printf("Введите заголовок блога для поиска: ");
                fgets(searchCategory, sizeof(searchCategory), stdin);
                int index = searchByCategory(bloges, blogCount, searchCategory);
                if (index != -1)
                {
                    printf("------------------------------------------------\n");
                    printf("Заголовок статьи: %s", bloges[index].title);
                    printf("Имя автора: %s", bloges[index].author);
                    printf("Категория статьи: %s", bloges[index].category);
                    printf("Дата публикации: %s", bloges[index].publication_date);
                    printf("Количество комментариев: %d\n", bloges[index].comment);
                    printf("Рейтинг: %.2lf\n", bloges[index].rating);
                    printf("------------------------------------------------\n");
                }
            }
            break;
        case 4:
            if (blogCount > 0)
            {
                sortByRating(bloges, blogCount);
                printf("\nОтсортированные данные по рейтингу по убыванию:\n");
                for (int i = 0; i < blogCount; ++i)
                {
                    printf("Название: %s, Рейтинг: %.2lf\n", bloges[i].title, bloges[i].rating);
                }
            }
            else {
                printf("База данных пуста.\n");
            }
            break;
        case 5:
            if (blogCount > 0)
            {
                int res = writeToFile(bloges, blogCount);
                if (res == 0)
                {
                    printf("Данные успешно записаны в файл.\n");
                }
                else
                {
                    printf("Не удалось записать данные в файл.\n");
                }
            }
            else
            {
                printf("База данных пуста. Нечего записывать в файл.\n");
            }
            break;
        case 6:
            if (blogCount > 0)
            {
                int res = readToFile(bloges, blogCount);
                if (res == 0)
                {
                    printf("Данные успешно прочитаны из файла.\n");
                }
                else
                {
                    printf("Не удалось прочитать данные из файла.\n");
                }
            }
            else
            {
                printf("База данных пуста. Нечего читать из файла.\n");
            }
            break;
        }
    }
    while (choice != 7);
}
void display() 
{
    printf("Добро пожаловать в меню для управления блогами!\n");
    printf("-----------------------------------------------------------\n");
    printf("Меню:\n");
    printf("1. Добавить блог\n");
    printf("2. Поиск блога по заголовку статьи\n");
    printf("3. Поиск блога по категории статьи\n");
    printf("4. Сортировка по рейтингу\n");
    printf("5. Запись в файл\n");
    printf("6. Чтение файла\n");
    printf("7. Выйти из программы\n");
    printf("-----------------------------------------------------------\n");
}
int searchByTitle(struct Blog blog[], int size, char searchTitle[])
{
    printf("\nРезультаты поиска по названию \"%s\":\n", searchTitle);
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
    printf("\nРезультаты поиска по категории \"%s:\"\n", searchCategory);
    
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
        printf("Ошибка при открытии файла");
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
        printf("Не удалось открыть файл для записи.\n");
        return 0;
    }
    for (int i = 0; i < size; ++i)
    {
        fprintf(file, "Заголовок: %s\n", blog[i].title);
        fprintf(file, "Автор: %s\n", blog[i].author);
        fprintf(file, "Категория: %s\n", blog[i].category);
        fprintf(file, "Дата: %s\n", blog[i].publication_date);
        fprintf(file, "Количество комментариев: %d\n", blog[i].comment);
        fprintf(file, "Рейтинг: %.2f\n", blog[i].rating);
    }
    fclose(file);
    printf("Данные успешно записаны в файл.\n");
    return 1;
}