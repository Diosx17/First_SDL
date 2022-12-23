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

    if(SDL_CreateWindowAndRenderer(1024, 768, 0,&window,&renderer)!=0)
    {
        SDL_ExitWithError("Rendu Impossible");
    }

    if(SDL_SetRenderDrawColor(renderer,112,168,237,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_ExitWithError("impossible de charger couleur");

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
        //SDL_RenderDrawRect(renderer,&Dessin);
       // SDL_RenderFillRect(renderer,&Dessin);

        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
            case SDL_KEYUP:
            for(int i = 0; i<3000;++i)
            {
                SDL_Rect Condi;
                Condi.h=(rand()%(100-30+1))+30;
                Condi.w=(rand()%(200-20+1))+20;
                Condi.x=(rand()%(1024-0+1))+0;
                Condi.y=(rand()%(768-0+1))+0;
                SDL_SetRenderDrawColor(renderer,rand()%256,rand()%256,rand()%256,SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer,&Condi);
                SDL_RenderFillRect(renderer,&Condi);


            }
                
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