#include <SDL.h>
#include <SDL_ttf.h>

int ecrire(char texte[], int taille)
{
    SDL_Surface *ecrit = NULL;

    SDL_Color noire = {0,0,0};
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    TTF_Font *police = NULL;
    police = TTF_OpenFont("ressources\\1942.ttf",taille);
    ecrit = TTF_RenderText_Blended(police, texte, noire);
    TTF_CloseFont(police);
    TTF_Quit();
    return ecrit;
}
