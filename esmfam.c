#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
//-------------------------------------------------------
void RandomElementMaker(char arr[],char word[],int line)
{
    int len = strlen(arr);
    int count = 0;
    for(int j =0;j < len;j++)
    {
        if(arr[j] == '\n')
        {
            count++;
        }
        if(line == count + 1 && line != 1)
        {
            int k = 0;
            while(arr[j + 1 + k] != '\n')
            {
                word[k] = arr[k + j + 1];
                k++;
            }
            break;
        }
        else if(line == count + 1 && line == 1)
        {
            int k = 0;
            while(arr[j + 1 + k] != '\n')
            {
                word[k] = arr[k + j];
                k++;
            }
            word[k] = arr[k + j];
            break;
        }
    }
}
//-------------------------------------------------------
void TeachTocom(char a[],char b[],FILE* pointer)
{
    int compare1 = strcmp(a,b);
    char endl[] = "\n";
    int len = strlen(a);
    char blank[] = "blank";
    int compare2 = strcmp(blank,a);
    if(compare2 == 0)
    {
        return;
    }
    if(compare1 != 0)
    {
        fputs(a,pointer);
        if(a[len - 1] != '\n')
        {
            fputs(endl,pointer);
        }
    }
}
//-------------------------------------------------------
int main(void)
{
    int randomNumber;
    char letter;
    char currentCharacter;
    char inputName[15];
    char inputCity[15];
    int randomLineName;
    int randomLineCity;
    int repeatChoice = 1;
    srand(time(NULL));
    while(repeatChoice == 1)
    {
       printf("Salam,khosh omadi,berim esm famil bazi konim!\n");
       randomNumber = rand() % 4;
       switch(randomNumber)
       {
           case 0: letter = 'A'; printf("Harf entekhabi: %c\n",letter); break;
           case 1: letter = 'B'; printf("Harf entekhabi: %c\n",letter); break;
           case 2: letter = 'C'; printf("Harf entekhabi: %c\n",letter); break;
           case 3: letter = 'D'; printf("Harf entekhabi: %c\n",letter); break;
       }
    //----------------------------------------------------------------
    int i = 0;
    int comScore = 0;
    int userScore = 0;
    char allNameData[1000];
    char allCityData[1000];
    char ourChosenName[100];
    char ourChosenCity[100];
    char temp[5];
    char blank[] = "blank";
    //----------------------------------------------------------------
    if(letter == 'A')
    {
        FILE * filePointer1;
        FILE * filePointer5;
        FILE * filePointer9;
        FILE * filePointer10;
        filePointer1 = fopen("Aname.txt","r");
        filePointer5 = fopen("Acity.txt","r");
        int lines1 = 0;
        int lines5 = 0;
        printf("Nam ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputName);
        printf("Shahr ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"" )\n");
        scanf("%s",&inputCity);
        while((currentCharacter = fgetc(filePointer1)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines1++;
            }
        }
        while((currentCharacter = fgetc(filePointer1)) != EOF)
        {
            allNameData[i] = currentCharacter;
            i++;
        }
        randomLineName = rand() % lines1 + 1;
        RandomElementMaker(allNameData,ourChosenName,randomLineName);
        int compare1 = strcmp(inputName,ourChosenName);
        int compare3 = strcmp(inputName,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare1 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        while((currentCharacter = fgetc(filePointer5)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines5++;
            }
        }
        while((currentCharacter = fgetc(filePointer5)) != EOF)
        {
            allCityData[i] = currentCharacter;
            i++;
        }
        randomLineCity = rand() % lines5 + 1;
        RandomElementMaker(allCityData,ourChosenCity,randomLineName);
        int compare2 = strcmp(inputCity,ourChosenName);
        compare3 = strcmp(inputCity,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare2 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        printf("iinam emtiazamoon   ");
        printf("user: %d  com: %d\n",userScore,comScore);
        if(userScore == comScore)
        {
            printf("mosavi shodim\n");
        }
        else if(userScore > comScore)
        {
            printf("bashe baba to khobi,to bordi\n");
        }
        else if(userScore < comScore)
        {
            printf("man bordam.iin bache bazia chie baba!!\n");
        }
        fclose(filePointer1);
        fclose(filePointer5);
        filePointer9 = fopen("Aname.txt","a");
        filePointer10 = fopen("Acity.txt","a");
        TeachTocom(inputName,ourChosenName,filePointer9);
        TeachTocom(inputCity,ourChosenCity,filePointer10);
        fclose(filePointer9);
        fclose(filePointer10);
    }
    else if(letter == 'B')
    {
        FILE * filePointer2;
        FILE * filePointer6;
        FILE * filePointer11;
        FILE * filePointer12;
        filePointer2 = fopen("Bname.txt","r");
        filePointer6 = fopen("Bcity.txt","r");
        int lines2 = 0;
        int lines6 = 0;
        printf("Nam ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputName);
        printf("Shahr ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputCity);
        while((currentCharacter = fgetc(filePointer2)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines2++;
            }
        }
        while((currentCharacter = fgetc(filePointer2)) != EOF)
        {
            allNameData[i] = currentCharacter;
            i++;
        }
        randomLineName = rand() % lines2 + 1;
        RandomElementMaker(allNameData,ourChosenName,randomLineName);
        int compare1 = strcmp(inputName,ourChosenName);
        int compare3 = strcmp(inputName,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare1 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        while((currentCharacter = fgetc(filePointer6)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines6++;
            }
        }
        while((currentCharacter = fgetc(filePointer6)) != EOF)
        {
            allCityData[i] = currentCharacter;
            i++;
        }
        randomLineCity = rand() % lines6 + 1;
        RandomElementMaker(allCityData,ourChosenCity,randomLineName);
        int compare2 = strcmp(inputCity,ourChosenName);
        compare3 = strcmp(inputCity,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare2 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        printf("iinam emtiazamoon   ");
        printf("user: %d  com: %d\n",userScore,comScore);
        if(userScore == comScore)
        {
            printf("mosavi shodim\n");
        }
        else if(userScore > comScore)
        {
            printf("bashe baba to khobi,to bordi\n");
        }
        else if(userScore < comScore)
        {
            printf("man bordam.iin bache bazia chie baba!!\n");
        }
        fclose(filePointer2);
        fclose(filePointer6);
        filePointer11 = fopen("Bname.txt","a");
        filePointer12 = fopen("Bcity.txt","a");
        TeachTocom(inputName,ourChosenName,filePointer11);
        TeachTocom(inputCity,ourChosenCity,filePointer12);
        fclose(filePointer11);
        fclose(filePointer12);
    }
    else if(letter == 'C')
    {  
        FILE * filePointer3;
        FILE * filePointer7;
        FILE * filePointer13;
        FILE * filePointer14;
        filePointer3 = fopen("Cname.txt","r");
        filePointer7 = fopen("Ccity.txt","r");
        int lines3 = 0;
        int lines7 = 0;
        printf("Nam ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputName);
        printf("Shahr ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputCity);
        while((currentCharacter = fgetc(filePointer3)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines3++;
            }
        }
        while((currentCharacter = fgetc(filePointer3)) != EOF)
        {
            allNameData[i] = currentCharacter;
            i++;
        }
        randomLineName = rand() % lines3 + 1;
        RandomElementMaker(allNameData,ourChosenName,randomLineName);
        int compare1 = strcmp(inputName,ourChosenName);
        int compare3 = strcmp(inputName,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare1 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        while((currentCharacter = fgetc(filePointer7)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines7++;
            }
        }
        while((currentCharacter = fgetc(filePointer7)) != EOF)
        {
            allCityData[i] = currentCharacter;
            i++;
        }
        randomLineCity = rand() % lines7 + 1;
        RandomElementMaker(allCityData,ourChosenCity,randomLineName);
        int compare2 = strcmp(inputCity,ourChosenName);
        compare3 = strcmp(inputCity,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare2 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        printf("iinam emtiazamoon   ");
        printf("user: %d  com: %d\n",userScore,comScore);
        if(userScore == comScore)
        {
            printf("mosavi shodim\n");
        }
        else if(userScore > comScore)
        {
            printf("bashe baba to khobi,to bordi\n");
        }
        else if(userScore < comScore)
        {
            printf("man bordam.iin bache bazia chie baba!!\n");
        }
        fclose(filePointer3);
        fclose(filePointer7);
        filePointer13 = fopen("Cname.txt","a");
        filePointer14 = fopen("Ccity.txt","a");
        TeachTocom(inputName,ourChosenName,filePointer13);
        TeachTocom(inputCity,ourChosenCity,filePointer14);
        fclose(filePointer13);
        fclose(filePointer14);
    }
    else if(letter == 'D')
    {
        FILE * filePointer4;
        FILE * filePointer8;
        FILE * filePointer15;
        FILE * filePointer16;
        filePointer4 = fopen("Dname.txt","r");
        filePointer8 = fopen("Dcity.txt","r");
        int lines4 = 0;
        int lines8 = 0;
        printf("Nam ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputName);
        printf("Shahr ro type kon va Enter ro bezan(harf avval bozorg va baghie kochik bayad bashan zemnan age balad nisti bezan ""blank"")\n");
        scanf("%s",&inputCity);
        while((currentCharacter = fgetc(filePointer4)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines4++;
            }
        }
        while((currentCharacter = fgetc(filePointer4)) != EOF)
        {
            allNameData[i] = currentCharacter;
            i++;
        }
        randomLineName = rand() % lines4 + 1;
        RandomElementMaker(allNameData,ourChosenName,randomLineName);
        int compare1 = strcmp(inputName,ourChosenName);
        int compare3 = strcmp(inputName,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare1 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        while((currentCharacter = fgetc(filePointer8)) != EOF)
        {
            temp[0] = currentCharacter;
            if(temp[0] == '\n')
            {
                lines8++;
            }
        }
        while((currentCharacter = fgetc(filePointer8)) != EOF)
        {
            allCityData[i] = currentCharacter;
            i++;
        }
        randomLineCity = rand() % lines8 + 1;
        RandomElementMaker(allCityData,ourChosenCity,randomLineName);
        int compare2 = strcmp(inputCity,ourChosenName);
        compare3 = strcmp(inputCity,blank);
        if(compare3 == 0)
        {
           comScore += 10;
        }
        else if(compare2 == 0)
        {
            userScore += 5;
            comScore += 5;
        }
        else
        {
            userScore += 10;
            comScore += 10;
        }
        printf("iinam emtiazamoon   ");
        printf("user: %d  com: %d\n",userScore,comScore);
        if(userScore == comScore)
        {
            printf("mosavi shodim\n");
        }
        else if(userScore > comScore)
        {
            printf("bashe baba to khobi,to bordi\n");
        }
        else if(userScore < comScore)
        {
            printf("man bordam.iin bache bazia chie baba!!\n");
        }
        fclose(filePointer4);
        fclose(filePointer8);
        filePointer15 = fopen("Dname.txt","a");
        filePointer16 = fopen("Dcity.txt","a");
        TeachTocom(inputName,ourChosenName,filePointer15);
        TeachTocom(inputCity,ourChosenCity,filePointer16);
        fclose(filePointer15);
        fclose(filePointer16);
    }
        //--------------------------------------------------
        printf("Ye dast dige bezanim?(are = 1 /na = 0)\n");
        scanf("%d",&repeatChoice);
    }
    printf("Boro tamrin kon ta dafe baad.felan bye :)\n");
    return 0;
} 
//-------------------------------------------------------