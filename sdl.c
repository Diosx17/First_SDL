#include <SDL.h>
#include <stdio.h>

int main(int argc, char  **argv)
{
    SDL_Window *window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Fenetre SDL 2",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600,0);

    if(window = NULL)
    {
        SDL_Log("Erreur : Creation fenetre echouee > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);

    }

    SDL_bool program_launched = SDL_TRUE;

    while (program_launched)
    {
        SDL_Event event;

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
    


    return EXIT_SUCCESS;
}
