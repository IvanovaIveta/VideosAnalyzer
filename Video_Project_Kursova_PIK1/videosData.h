#ifndef VIDEOS_H_INCLUDED
#define VIDEOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct
{
    char user[50];
    char text[150];
    int day, month, year;
    int likes;
    int dislikes;
} comment_data_t;

typedef struct node_comment_s
{
    comment_data_t comment_data;
    struct node_comment_s *next;
}node_comment_t;

typedef struct
{
    char link[150];
    char name[50];
    int rating;
    int day, month, year;
    int likes;
    int dislikes;
    node_comment_t *head;
} video_data_t;

typedef struct node_s
{
   video_data_t video_data;
   struct node_s *next;
}node_t;


node_t* CreateElement();
void AddElementAtEnd(video_data_t* pVideo);
void printVideo(video_data_t* pVideo);
void EnterVideoData(video_data_t* pVideo);
void printList();
void EnterCommentData();
void AddCommentAtEnd(comment_data_t* pComment, video_data_t* video_data);
void printListComment(node_comment_t *head);
void printComment(comment_data_t * pComment);
void DeleteListComments(node_comment_t * head);
void DeleteListVideos(void);
void enterDate();
void deleteVideosLD();
void deleteDirtyComments();
node_comment_t* CreateComment();
void SaveDataInBinFile();
void ReadDataFromBinFile();
#endif // VIDEOS_H_INCLUDED


