#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <SDL_image.h>

#include "ecrire.h"

int main ( int argc, char** argv )
{
    SDL_Surface *ecran = NULL, *fond = NULL, *carac[50] = {0};
    SDL_Event event;
    SDL_Rect position;

    srand(time(NULL));

    int continuer = 1, taille = 0, bad=0, i=0;
    int caracB[10]={0};

    char BAD[50]={0}, FOR[50]={0}, CON[50]={0}, POU[50]={0}, DEX[50]={0}, APP[50]={0}, TAI[50]={0}, INT[50]={0}, EDU[50]={0}, SAN[50]={0}, Idee[50]={0}, Chance[50]={0}, Connaissance[50]={0}, PDV[50]={0}, Magie[50]={0};

    SDL_Init(SDL_INIT_VIDEO);

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    ecran = SDL_SetVideoMode(1439, 489, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Perso Cthulhu", NULL);
    SDL_WM_SetIcon(IMG_Load("ressources\\Cthulhu2.png"), NULL);

    fond = IMG_Load("ressources\\Capture.png");
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
    for(i=0;i<5;i++)
    {
        caracB[i]=(rand()%6 + rand()%6 + rand()%6)+3; //FOR,CON,POU,DEX,APP
    }
    caracB[5]=(rand()%6 + rand()%6)+8;//TAI
    caracB[6]=(rand()%6 + rand()%6)+8;//INT
    caracB[7]=(rand()%6 + rand()%6 + rand()%6)+6;//EDU
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        for(i=0;i<5;i++)
                        {
                            caracB[i]=(rand()%6 + rand()%6 + rand()%6)+3; //FOR,CON,POU,DEX,APP
                        }
                        caracB[5]=(rand()%6 + rand()%6)+8;//TAI
                        caracB[6]=(rand()%6 + rand()%6)+8;//INT
                        caracB[7]=(rand()%6 + rand()%6 + rand()%6)+6;//EDU
                        break;
                }

        }
/////////////////////////////////////////////////////////////////////////////////////////
            sprintf(FOR, "%d",caracB[0]);
            sprintf(CON, "%d",caracB[1]);
            sprintf(POU, "%d",caracB[2]);
            sprintf(DEX, "%d",caracB[3]);
            sprintf(APP, "%d",caracB[4]);
            sprintf(TAI, "%d",caracB[5]);
            sprintf(INT, "%d",caracB[6]);
            sprintf(EDU, "%d",caracB[7]);
            sprintf(SAN, "%d",caracB[2]*5);
            sprintf(PDV, "%d",(caracB[1]+caracB[5])/2);

            sprintf(Idee, "%d",caracB[6]*5);
            sprintf(Chance, "%d",caracB[2]*5);
            sprintf(Connaissance, "%d",caracB[7]*5);
            bad = caracB[0] + caracB[5];

            if(bad>1 && bad<13)
                sprintf(BAD,"-1D6");
            else if(bad>12 && bad<17)
                sprintf(BAD,"-1D4");
            else if(bad>16 && bad<25)
                sprintf(BAD,"aucun");
            else if(bad>24 && bad<33)
                sprintf(BAD,"+1D4");
            else
                sprintf(BAD,"+1D6");

            carac[0]=ecrire(FOR, 62);
            carac[1]=ecrire(CON, 62);
            carac[2]=ecrire(POU, 62);
            carac[3]=ecrire(DEX, 62);
            carac[4]=ecrire(APP, 62);
            carac[5]=ecrire(TAI, 62);
            carac[6]=ecrire(INT, 62);
            carac[7]=ecrire(EDU, 62);
            carac[8]=ecrire(SAN, 62);
            carac[9]=ecrire(PDV, 62);
            carac[10]=ecrire(Idee, 62);
            carac[11]=ecrire(Chance, 62);
            carac[12]=ecrire(Connaissance, 62);
            carac[13]=ecrire(BAD, 62);
            carac[14]=ecrire("99", 62);
            carac[15]=ecrire(POU, 62);
/////////////////////////////////////////////////////////////////////////////////////////
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    position.x=0;
    position.y=0;
    SDL_BlitSurface(fond, NULL, ecran, &position);

    position.x = 200-carac[0]->w/2;
    position.y = 80-carac[0]->h/2;
    SDL_BlitSurface(carac[0], NULL, ecran, &position);//FOR

    position.x = 200-carac[1]->w/2;
    position.y = 160-carac[1]->h/2;
    SDL_BlitSurface(carac[1], NULL, ecran, &position);//CON

    position.x = 718-carac[2]->w/2;
    position.y = 160-carac[2]->h/2;
    SDL_BlitSurface(carac[2], NULL, ecran, &position);//POU

    position.x = 455-carac[3]->w/2;
    position.y = 80-carac[3]->h/2;
    SDL_BlitSurface(carac[3], NULL, ecran, &position);//DEX

    position.x = 455-carac[4]->w/2;
    position.y = 160-carac[4]->h/2;
    SDL_BlitSurface(carac[4], NULL, ecran, &position);//APP

    position.x = 200-carac[5]->w/2;
    position.y = 248-carac[5]->h/2;
    SDL_BlitSurface(carac[5], NULL, ecran, &position);//TAI

    position.x = 718-carac[6]->w/2;
    position.y = 80-carac[6]->h/2;
    SDL_BlitSurface(carac[6], NULL, ecran, &position);//INT

    position.x = 718-carac[7]->w/2;
    position.y = 248-carac[7]->h/2;
    SDL_BlitSurface(carac[7], NULL, ecran, &position);//EDU

    position.x = 455-carac[8]->w/2;
    position.y = 248-carac[8]->h/2;
    SDL_BlitSurface(carac[8], NULL, ecran, &position);//SAN

    position.x = 1250-carac[9]->w/2;
    position.y = 330-carac[9]->h/2;
    SDL_BlitSurface(carac[9], NULL, ecran, &position);//PDV

    position.x = 1140-carac[10]->w/2;
    position.y = 80-carac[10]->h/2;
    SDL_BlitSurface(carac[10], NULL, ecran, &position);//idée

    position.x = 1140-carac[11]->w/2;
    position.y = 160-carac[11]->h/2;
    SDL_BlitSurface(carac[11], NULL, ecran, &position);//chance

    position.x = 1300-carac[12]->w/2;
    position.y = 248-carac[12]->h/2;
    SDL_BlitSurface(carac[12], NULL, ecran, &position);//connaissance

    position.x = 604-carac[13]->w/2;
    position.y = 425-carac[13]->h/2;
    SDL_BlitSurface(carac[13], NULL, ecran, &position);//BAD

    position.x = 610-carac[14]->w/2;
    position.y = 330-carac[14]->h/2;
    SDL_BlitSurface(carac[14], NULL, ecran, &position);//mythe

    position.x = 1250-carac[15]->w/2;
    position.y = 425-carac[15]->h/2;
    SDL_BlitSurface(carac[15], NULL, ecran, &position);//magie

    SDL_Flip(ecran);
    }

    for(i=0;i<16;i++)
    {
        SDL_FreeSurface(carac[i]);
    }
    SDL_Quit();
    return 0;
}
