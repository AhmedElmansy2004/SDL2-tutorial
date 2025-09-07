#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] ) {
    SDL_Window* window = NULL;
    //SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL2 Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    bool gameIsRunning = true;
    int cntm = 0,
        cntkd = 0;

    //The event Loop
    while (gameIsRunning) {
        SDL_Event event;
        // Start of our event loop
        while (SDL_PollEvent(&event)) {
            //hanadle each specific event
            switch (event.type)
            {
            case SDL_QUIT:
                gameIsRunning = false;
                break;
            case SDL_MOUSEMOTION:
                printf("Mouse has been moved: %d\n", cntm);
                cntm++;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_w)
                    printf("\"w\" was pressed\n");
                printf("Key has been pressed down: %d\n", cntkd);
                cntkd++;
                break;
            
            default:
                break;
            }
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]) {
                printf("Right arrow is pressed\n");
            }
        }
        
    }
    
    //SDL_Delay(30000);

    //SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}