#include "videosData.h"

node_t * head = NULL;

void printList()
{

    node_t *ptemp = head;

    if(head==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (ptemp != NULL)
    {
        printVideo(&ptemp->video_data);
        ptemp = ptemp->next;
    }
}
void printListComment(node_comment_t *head)
{
    node_comment_t *ptemp = head;
    while (ptemp != NULL)
    {
        printComment(&ptemp->comment_data);
        ptemp = ptemp->next;
    }

}

node_t* CreateElement()
{
    node_t * tempP = (node_t*)malloc(sizeof(node_t));
    if (tempP == NULL)
    {
        printf("\nError!");
        exit(1);
    }

    tempP->next = NULL;

    return tempP;
}

node_comment_t* CreateComment()
{
    node_comment_t * tempP = (node_comment_t*)malloc(sizeof(node_comment_t));
    if (tempP == NULL)
    {
        printf("\nError!");
        exit(1);
    }

    tempP->next = NULL;

    return tempP;
}

void AddElementAtEnd(video_data_t* pVideo)
{
    node_t * pnewElement = CreateElement();
    node_t * ptemp = head;

    pnewElement->video_data = *pVideo;

    //If list is empty
    if (head == NULL)
    {
        head = pnewElement;
        return;
    }

    while (ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }

    ptemp->next = pnewElement;
}

void AddCommentAtEnd(comment_data_t* pComment, video_data_t* video_data)
{
    node_comment_t * pnewElement = CreateComment();
    node_comment_t * ptemp = video_data->head;

    pnewElement->comment_data = *pComment;

    //If list is empty
    if (video_data->head == NULL)
    {
        video_data->head = pnewElement;
        return;
    }

    while (ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }

    ptemp->next = pnewElement;
}

void EnterVideoData(video_data_t* pVideo)
{
    fflush(stdin);
    printf("Enter link:\n");
    scanf("%s", pVideo->link);
    fflush(stdin);
    printf("Enter name of the video:\n");
    gets(pVideo->name);
    fflush(stdin);
   while(1)
   {
    fflush(stdin);
    printf("Enter day:\n");
    scanf("%d", &pVideo->day);
      if(pVideo->day>0 && pVideo->day<=31)
         break;
    };
    while(1)
    {
        fflush(stdin);
        printf("Enter month:\n");
        scanf("%d", &pVideo->month);
        if(pVideo->month>0 && pVideo->month<=12)
        {
            break;
        }
    }
    while(1)
    {
        fflush(stdin);
        printf("Enter year:\n");
        scanf("%d", &pVideo->year);
        if(pVideo->year>2004 && pVideo->year<=2020)
        {
            break;
        }
    }
    while(1)
    {
      fflush(stdin);
      printf("Enter rating (1-10):\n");
      scanf("%d", &pVideo->rating);
      if(pVideo->rating>0 && pVideo->rating<=10)
      {
          break;
      };
    }

    fflush(stdin);
    printf("Enter likes:\n");
    scanf("%d", &pVideo->likes);
    fflush(stdin);
    printf("Enter dislikes:\n");
    scanf("%d", &pVideo->dislikes);
    printf("\n\n");
    pVideo->head = NULL;
}

void EnterCommentData()
{
    char video[50];
    fflush(stdin);
    printf("Choose video to add comment to:");
    gets(video);
    video_data_t* pVideo;

    node_t *ptemp = head;

    while (ptemp != NULL)
    {
        int res = strcmp(video, ptemp->video_data.name);
        if (res == 0)
        {
            pVideo = &ptemp->video_data; //sochi kum mqstoto v pametta kudeto ima tezi danni
            comment_data_t comment;
            fflush(stdin);
            printf("Enter user:\n");
            gets(comment.user);
            fflush(stdin);
            printf("Enter comment:\n");
            gets(comment.text);
            fflush(stdin);

            while(1)
             {
                  fflush(stdin);
                  printf("Enter day:\n");
                  scanf("%d", &comment.day);
                  if(comment.day>0 && comment.day<=31)
                           break;
              }
             while(1)
             {
                fflush(stdin);
                printf("Enter month:\n");
                scanf("%d", &comment.month);
                if(comment.month>0 && comment.month<=12)
                 {
                    break;
                 }
             }
             while(1)
             {
                  fflush(stdin);
                  printf("Enter year:\n");
                  scanf("%d", &comment.year);
                  if(comment.year>2004 && comment.year<=2020)
                  {
                     break;
                  }
              }

            if(comment.year<pVideo->year)
            {
                 printf("The date you have entered is not a valid date. It is earlier than the date when the video was added!\n");
                 enterDate();
            }
            else if(comment.year==pVideo->year && comment.month==pVideo->month && comment.day<pVideo->day)
            {
                 printf("The date you have entered is not a valid date. It is earlier than the date when the video was added!\n");
                 enterDate();
            }
            else if(comment.year==pVideo->year && comment.month<pVideo->month)
            {
                printf("The date you have entered is not a valid date. It is earlier than the date when the video was added!\n");
                enterDate();
            }


            fflush(stdin);
            printf("Enter likes:\n");
            scanf("%d", &comment.likes);
            fflush(stdin);
            printf("Enter dislikes:\n");
            scanf("%d", &comment.dislikes);
            printf("\n\n");
            AddCommentAtEnd(&comment, &ptemp->video_data);
        }
        ptemp = ptemp->next;
    }
}

void printVideo(video_data_t* pVideo)
{
    printf("Leading link:              %s\n", pVideo->link);
    printf("Name:                      %s\n", pVideo->name);
    printf("Rating:                    %d/10\n",pVideo->rating);
    printf("Date added:                %d.%d.%d\n", pVideo->day, pVideo->month, pVideo->year);
    printf("Likes:                     %d\n", pVideo->likes);
    printf("Dislikes:                  %d\n\n", pVideo->dislikes);
    printf("   Comments: \n");
    printListComment(pVideo->head);
    printf("\n\n");
}

void printComment(comment_data_t* pComment)
{
    printf("          Username:            %s\n", pComment->user);
    printf("          Text:                %s\n", pComment->text);
    printf("          Date added:          %d.%d.%d\n", pComment->day, pComment->month, pComment->year);
    printf("          Likes/Dislikes:      %d/%d\n\n", pComment->likes, pComment->dislikes);
}
void DeleteListComments(node_comment_t * head)
{
    node_comment_t * temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        printf("\nDeleting %s's comment\n", temp->comment_data.user);
        free(temp);
    }
}

void DeleteListVideos(void)
{
    node_t * temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        printf("\nDeleting %s", temp->video_data.link);
        DeleteListComments(temp->video_data.head);
        free(temp);
    }
}

void enterDate()
{
    comment_data_t comment;

     while(1)
             {
                  fflush(stdin);
                  printf("Enter day:\n");
                  scanf("%d", &comment.day);
                  if(comment.day>0 && comment.day<=31)
                           break;
              }
             while(1)
             {
                fflush(stdin);
                printf("Enter month:\n");
                scanf("%d", &comment.month);
                if(comment.month>0 && comment.month<=12)
                 {
                    break;
                 }
             }
             while(1)
             {
                  fflush(stdin);
                  printf("Enter year:\n");
                  scanf("%d", &comment.year);
                  if(comment.year>2004 && comment.year<=2020)
                  {
                     break;
                  }
              }
}


void deleteVideosLD()
{

    double div;
    node_t* prev_item = head;
    node_t* curr_item = head;
    node_t* temp = NULL;
    while (curr_item != NULL)
    {
        div = ((double)curr_item->video_data.likes) / ((double)curr_item->video_data.dislikes);
        if (div < 0.5)
        {
            node_t* temp = curr_item;
            if (curr_item == head)
            {
                head = head->next;
                prev_item = head;
                curr_item = head;
            }
            else
            {
                prev_item->next = curr_item->next;
                curr_item = curr_item->next;
            }
            DeleteListComments(temp->video_data.head);
            free(temp);
        }else
        {
           prev_item = curr_item;
           curr_item = curr_item->next;
        }
    }
}

void deleteDirtyComments()
{
    node_t *curr_video = head;
    while (curr_video != NULL)
    {
        node_comment_t* prev_item = curr_video->video_data.head;
        node_comment_t* curr_item = curr_video->video_data.head;
        node_comment_t* temp = NULL;
        while (curr_item != NULL)
        {
            if (strstr(curr_item->comment_data.text, "fuck")||strstr(curr_item->comment_data.text,"bitch")||strstr(curr_item->comment_data.text,"shit")||strstr(curr_item->comment_data.text, "idiot"))
            {
                node_comment_t* temp = curr_item;
                if (curr_item == curr_video->video_data.head)
                {
                    curr_video->video_data.head = curr_video->video_data.head->next;
                    prev_item = curr_video->video_data.head;
                    curr_item = curr_video->video_data.head;
                }
                else
                {
                    prev_item->next = curr_item->next;
                    curr_item = curr_item->next;
                }
                free(temp);
            }
            else
            {  //izmestvame vsichko s edna poziciq napred
                prev_item = curr_item;
                curr_item = curr_item->next;
            }
        }
        curr_video = curr_video->next; //kato se izvurti celiqt cikul premestvame videoto napred
    }
}


void SaveDataInBinFile()
{
    if (head == NULL)
    {
        printf("The video list is empty!");
        return;
    }

    char filename[50];
    printf("Enter file name:\n");
    scanf("%s", &filename);
    FILE *fp = NULL;
    fp = fopen(filename, "wb");
    if ((fp == NULL))
    {
        printf("Error opening the file");
        return;
    }

    node_t* tempV = head;
    while (tempV != NULL)
    {
        if (fwrite(&tempV->video_data, sizeof(video_data_t), 1, fp) != 1)
        {
            printf("Error occured while writing on the file.\n");
            exit(1);
        }
        node_comment_t* tempC = tempV->video_data.head;
        while (tempC != NULL)
        {
            if (fwrite(tempC, sizeof(node_comment_t), 1, fp) != 1)
            {
                printf("Error occured while writing on the file.\n");
                exit(1);
            }
            tempC = tempC->next;
        }

        tempV = tempV->next;
    }

    if (fclose(fp) == EOF)
    {
        printf("Error. Cannot close the file.");
        exit(3);
    };

    printf("Info saved successfully to the file.\n");
}

void ReadDataFromBinFile()
{
   //DeleteListVideos();
    FILE *fp;
    video_data_t video;

    char filename[50];
    printf("\nEnter file name to load:\n");
    scanf("%s", &filename);
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error reading the file.It is not found.");
        exit(2);
    }

    while (!feof(fp))
    {
        if (fread(&video, sizeof(video_data_t), 1, fp) != 1)
        {
            return;
        }
        else
        {
            if (video.head != NULL)
            {
                node_comment_t node_comment;
                video.head = NULL;

                if (fread(&node_comment, sizeof(node_comment_t), 1, fp) != 1)
                {
                    return;
                }
                else
                {
                    AddCommentAtEnd(&node_comment.comment_data, &video);
                }

                while (!feof(fp) && node_comment.next != NULL)
                {
                    if (fread(&node_comment, sizeof(node_comment_t), 1, fp) != 1)
                    {
                        return;
                    }
                    else
                    {
                        AddCommentAtEnd(&node_comment.comment_data, &video);
                    }
                }
            }
            AddElementAtEnd(&video);
        }
    }
}
