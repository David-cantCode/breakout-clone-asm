//compile 

//nasm -f elf64 main.asm -o main.o
//gcc sdl.c main.o -o window -lSDL3


#define SDL_MAIN_USE_CALLBACKS 1  //use call back instead of main()
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;




extern int update(void);






//on startup
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
 
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("window", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }






    return SDL_APP_CONTINUE; 
}



//EVENT
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS; 
    }
    return SDL_APP_CONTINUE;
}




//once everyframe
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_RenderClear(renderer);


    update();





    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE; 

}



//shutdown
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
 
}



