#include "videosFunc.c"



int main()
{

   int ch;
   while(1)
   {
        system("pause");
        system("cls");

       video_data_t video;

       printf("*******************|| MENU ||********************\n");
       printf("* 1. Print all the videos.                      *\n");
       printf("* 2. Add new video.                             *\n");
       printf("* 3. Add new comment to a video.                *\n");
       printf("* 4. Delete all comments with dirty words.      *\n");
       printf("* 5. Delete all videos if Likes/Dislikes<0.5    *\n");
       printf("* 6. Save data in new binary file.              *\n");
       printf("* 7. Load data from an existing binary file.    *\n");
       printf("* 8. Exit.                                      *\n");
       printf("*************************************************\n");
       fflush(stdin);
       printf("Choose option:\n");
       scanf("%d", &ch);

       switch(ch)
       {
           case 1:
              printList();
              break;
           case 2:
              EnterVideoData(&video);
              AddElementAtEnd(&video);
              break;
           case 3:
              EnterCommentData();
              break;
           case 4:
              deleteDirtyComments();
              break;
           case 5:
              deleteVideosLD();
              break;
           case 6:
              SaveDataInBinFile();
              break;
           case 7:
              ReadDataFromBinFile();
              break;
           case 8:
              exit(1);

       }

   }

}
