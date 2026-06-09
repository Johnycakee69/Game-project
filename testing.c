#include <SDL3/SDL.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_video.h>


#define SPEED 300.0f   // pixels per second
#define SIZE  50       // player square size

//Wall  Structure
typedef struct {
    SDL_FRect rect;
}Wall;

int collides(SDL_FRect a, SDL_FRect b) {
    return  a.x < b.x + b.w &&
            a.x + b.w > b.x &&
            a.y < b.y + b.h &&
            a.y + a.h > b.y;

}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window   *window   = SDL_CreateWindow("Game!", 1920, 1200, SDL_WINDOW_MAXIMIZED);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    // Player position
    float x = 375, y = 275;

    Uint64 last = SDL_GetTicks();   
    int running = 1;
    SDL_Event event;

    //Wall
    Wall walls[] = {
        { { 200, 150,}}
    }

    while (running) {
        // --- Delta time (makes movement frame-rate independent) ---
        Uint64 now = SDL_GetTicks();
        float dt = (now - last) / 1000.0f;
        last = now;

        // --- 1. Events ---
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = 0;
        }

        // --- 2. Update (read keys & move) ---
        const bool *keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_SCANCODE_UP])    y -= SPEED * dt;
        if (keys[SDL_SCANCODE_DOWN])  y += SPEED * dt;
        if (keys[SDL_SCANCODE_LEFT])  x -= SPEED * dt;
        if (keys[SDL_SCANCODE_RIGHT]) x += SPEED * dt;

        // --- 2.1 Update (WASD) ---
        if(keys[SDL_SCANCODE_W]) y -= SPEED * dt;
        if(keys[SDL_SCANCODE_S]) y += SPEED * dt;
        if(keys[SDL_SCANCODE_A]) x -= SPEED * dt;
        if(keys[SDL_SCANCODE_D]) x += SPEED * dt;

        // --- 3. Render ---
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // dark bg
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 74, 144, 226, 255);  // blue player
        SDL_FRect player = { x, y, SIZE, SIZE };
        SDL_RenderFillRect(renderer, &player);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

