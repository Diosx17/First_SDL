#include <SDL.h>
#include <stdio.h>

void SDL_ExitWithError(const char *message);


int main(int argc, char  **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(SDL_CreateWindowAndRenderer(800, 600, 0,&window,&renderer)!=0)
    {
        SDL_ExitWithError("Rendu Impossible");
    }

    if(SDL_SetRenderDrawColor(renderer,112,168,237,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_ExitWithError("impossible de charger couleur");

    }

    if(SDL_RenderDrawPoint(renderer,100,450)!=0)
    {
        SDL_ExitWithError("Point");
    }

    if(SDL_RenderDrawLine(renderer,50,50,500,500)!=0)
    {
        SDL_ExitWithError("Ligne");
    }

    SDL_bool program_launched = SDL_TRUE;
    SDL_Rect Dessin;
    Dessin.h=200;
    Dessin.w=380;
    Dessin.x=200;
    Dessin.y=100;


    while (program_launched)
    {
        SDL_Event event;
        //SDL_BlitSurface(&Dessin);
        SDL_RenderPresent(renderer);
        SDL_RenderDrawRect(renderer,&Dessin);
        SDL_RenderFillRect(renderer,&Dessin);

        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
            
            default:
                break;
            }

        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur : %s > %s \n",message,SDL_GetError());
}