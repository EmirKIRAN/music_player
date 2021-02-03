#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/**

// Bu projede Linked List veri yapisi kullanilmistir.
// Nedeni ise dizilere kiyasla eleman sayisini dinamik olarak belirleyebilmemizdir.
// Ayrica PlaySong() komutu içinde çok uygun bir veri yapisidir.
// Hafiza yönetimi bakimindan oldukça verimli bir veri yapisidir.
// Sonsuz sayida muzik olacagi dusunulurse en uygun veri yapisi Linked Listler olacaktir. Bu nedenle secilmistir.

*/

typedef int BOOLEAN;

struct MusicNode
{
    char music[50];
    BOOLEAN is_active;
    struct MusicNode* next;
};
typedef struct MusicNode Music;

void InsertTail(char _musicName[50], Music** root); //middle ware function
void InsertHead(char _musicName[50], Music** root); //middle ware function
void InsertSong(char state,char _musicName[50], Music** root); // main function
void InsertBefore(char _musinName[50], char _target[50],Music** root); //middle ware function
void InsertAfter(char _musicName[50], char _target[50], Music** root); //middle ware function
void MoveBefore(char _musicName[50], char _target[50], Music** root); //middle ware function
void MoveAfter(char _musicName[50], char _target[50], Music** root); //middle ware function
void MoveSong(char state,char _musicName[50], char _target[50], Music** root); // main function
void RemoveSong(char _target[50],Music** root); // main function
void PlaySong(char state,Music** root); // main function
void ReversePlaylist(Music** root); // main function
void printPlaylist(char state,Music** root); // main function
BOOLEAN is_in(char _musicName[50],Music* root); //middle ware function

int main()
{
    Music* musicPlayer = NULL;
    FILE* file;
    char command[255];

    if((file = fopen("input.txt","r"))!=NULL)
    {
       while(fgets(command,255,file))
       {
           char *piece = strtok(command,"\t");
           int counter = 0;
           while(piece != NULL)
           {
               if(counter == 0)
               {
                   if(strcmp(piece,"PlaySong")==0)
                   {
                       piece = strtok(NULL,"\t");
                       piece[strlen(piece)-1]='\0';
                       PlaySong(piece,&musicPlayer);
                   }
                   else if(strcmp(piece,"RemoveSong")==0)
                   {
                       piece = strtok(NULL,"\t");
                       piece[strlen(piece)-1]='\0';
                       RemoveSong(piece,&musicPlayer);
                   }
                   else if(strcmp(piece,"PrintPlaylist")==0)
                   {
                       piece = strtok(NULL,"\t");
                       piece[strlen(piece)-1]='\0';
                       if(strcmp(piece,"F")==0)
                            printPlaylist('F',&musicPlayer);
                       else
                            printPlaylist('R',&musicPlayer);
                   }
                   else if(strcmp(piece,"ReversePlaylist\n")==0)
                   {
                       ReversePlaylist(&musicPlayer);
                   }
                   else if(strcmp(piece,"InsertSong")==0)
                   {
                       piece = strtok(NULL,"\t");
                       char parameter1[50];
                       strcpy(parameter1,piece);
                       piece = strtok(NULL,"\t");
                       piece[strlen(piece)-1]='\0';
                       char parameter2[50];
                       strcpy(parameter2,piece);
                       InsertSong(parameter1,parameter2,&musicPlayer);
                   }
                   else
                   {
                       piece = strtok(NULL,"\t");
                       char parameter1[50];
                       strcpy(parameter1,piece);
                       piece = strtok(NULL,"\t");
                       char parameter2[50];
                       strcpy(parameter2,piece);
                       piece = strtok(NULL,"\t");
                       piece[strlen(piece)-1]='\0';
                       char parameter3[50];
                       strcpy(parameter3,piece);
                       MoveSong(parameter1,parameter2,parameter3,&musicPlayer);
                   }
               }

               piece = strtok(NULL,"\t");
               counter++;
           }
       }
    }
    else
    {
        perror("Unable to open file");
        exit(1);
    }

    fclose(file);
    return 0;
}

void InsertTail(char _musicName[50], Music** root)
{
    Music* new_music = (Music*) malloc(sizeof(Music));
    if(new_music == NULL)
        exit(1);

    new_music->next = NULL;
    strcpy(new_music->music,_musicName);
    new_music->is_active = FALSE;

    if(*root == NULL)
    {
        new_music->is_active = TRUE;
        *root = new_music;
        return;
    }
    Music* current = *root;

    while(current->next != NULL)
        current = current->next;
    current->next = new_music;
}

void InsertHead(char _musicName[50], Music** root)
{
    Music* new_music = malloc(sizeof(Music));
    if(new_music == NULL)
        return 3;
    strcpy(new_music->music,_musicName);
    if((*root) == NULL)
        new_music->is_active = TRUE;
    else
        new_music->is_active = FALSE;
    new_music->next = *root;
    *root = new_music;
}

BOOLEAN is_in(char _musicName[50],Music* root)
{
    BOOLEAN value = FALSE;
    while(root != NULL)
    {
        if(strcmp(_musicName,root->music) == 0)
        {
            value = TRUE;
            break;
        }
        root = root->next;
    }
    return value;
}

void InsertBefore(char _musicName[50], char _target[50],Music** root)
{
    Music* current = *root;
    Music* new_music = (Music*) malloc(sizeof(Music));
    strcpy(new_music->music,_musicName);
    new_music->is_active = FALSE;
    new_music->next = NULL;

    if(current->next == NULL)
        current->next = new_music;
    else
    {
        if(is_in(_target,*root))
        {
            while(strcmp(current->next->music,_target)!=0)
                current = current->next;
            Music* tempNode = current->next;
            current->next = new_music;
            new_music->next = tempNode;
        }
    }
}

void InsertAfter(char _musicName[50], char _target[50], Music** root)
{
    Music* current = *root;
    Music* new_music = (Music*) malloc(sizeof(Music));
    strcpy(new_music->music,_musicName);
    new_music->is_active = FALSE;
    if(current->next == NULL)
        current->next = new_music;
    else
    {
        if(is_in(_target,*root))
        {
            while(strcmp(current->music,_target)!=0)
                current = current->next;
            Music* tempNode = current->next;
            current->next = new_music;
            new_music->next = tempNode;
        }
    }
}

void InsertSong(char state,char _musicName[50], Music** root)
{
    if(state == 'H')
        InsertHead(_musicName,root);
    else
        InsertTail(_musicName,root);
}

void MoveBefore(char _musicName[50], char _target[50], Music** root)
{
    Music* current = *root;
    while(strcmp(current->music,_musicName)!=0)
        current = current->next;
    if(current->is_active == FALSE)
    {
        RemoveSong(_musicName,root);
        InsertBefore(_musicName,_target,root);
}
}

void MoveAfter(char _musicName[50], char _target[50], Music** root)
{
    Music* current = *root;
    while(strcmp(current->music,_musicName)!=0)
        current = current->next;
    if(current->is_active == FALSE)
    {
        RemoveSong(_musicName,root);
        InsertAfter(_musicName,_target,root);
    }

}

void MoveSong(char state,char _musicName[50], char _target[50], Music** root)
{
    if(state == 'B')
        MoveBefore(_musicName,_target,root);
    else
        MoveAfter(_musicName,_target,root);
}

void RemoveSong(char _target[50],Music** root)
{
    if(*root == NULL)
        return;
    if(strcmp((*root)->music,_target) == 0)
    {
        Music* to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }

    Music* current = *root;
    while(current->next != NULL)
    {
        if(strcmp(current->next->music,_target)==0)
        {
            if(current->next->is_active == FALSE)
            {
                Music* to_remove = current->next;
                current->next = current->next->next;
                free(to_remove);
                return;
            }
            else
            {
                FILE* file;
                if((file = fopen("output.txt","a"))!=NULL)
                    fprintf(file,"\nCannot Remove The Playing Song\n*****");
                fclose(file);
                return;
            }

        }
        current = current->next;
    }
}

void PlaySong(char state,Music** root)
{
    if((*root) == NULL)
    {
        FILE* file;
        if((file = fopen("output.txt","a"))!= NULL)
            fprintf(file,"\nNo Songs To Play\n*****");
        fclose(file);
    }
    else
    {
        FILE* file = fopen("output.txt","a");
        Music* current = *root;
        if(state == 'P')
        {
            if((*root)->is_active == TRUE)
            {
                (*root)->is_active = FALSE;
                while(current->next != NULL)
                    current = current->next;
                current->is_active = TRUE;
                fprintf(file,"\nPlaying\t%s\n*****",current->music);
            }
            else
            {
                while(current->next->is_active != TRUE)
                    current = current->next;
                current->next->is_active = FALSE;
                current->is_active = TRUE;
                fprintf(file,"\nPlaying\t%s\n*****",current->music);
            }
        }
        else
        {
            while(current->is_active != TRUE)
                current = current->next;
            if(current->next == NULL)
            {
                current->is_active = FALSE;
                (*root)->is_active = TRUE;
                fprintf(file,"\nPlaying\t%s\n*****",(*root)->music);
            }
            else
            {
                current->is_active = FALSE;
                current->next->is_active = TRUE;
                fprintf(file,"\nPlaying\t%s\n*****",current->next->music);
            }
        }
        fclose(file);
    }
}

void ReversePlaylist(Music** root)
{
    if((*root) == NULL)
        return;
    else
    {
        Music* previous = NULL;
        Music* current = *root;

        while(current != NULL)
        {
            Music* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        *root = previous;
    }
}

void printPlaylist(char state,Music** root)
{
    FILE* file;

    Music* current = *root;
    if(current == NULL)
    {
        if((file = fopen("output.txt","a"))!= NULL)
            fprintf(file,"\nNo Songs To Print\n*****");
        fclose(file);
    }
    else
    {
        if(state == 'F' && (file = fopen("output.txt","a"))!= NULL)
        {
            while(current != NULL)
            {
                fprintf(file,"\n%s",current->music);
                current = current->next;
            }
            fprintf(file,"\n*****");
        }
        if(state == 'R' && (file = fopen("output.txt","a"))!=NULL)
        {
            ReversePlaylist(root);
            current = *root;
            while(current != NULL)
            {
                fprintf(file,"\n%s",current->music);
                current = current->next;
            }
            fprintf(file,"\n*****");
            ReversePlaylist(root);
        }
        fclose(file);
    }
}

