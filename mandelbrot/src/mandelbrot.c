#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Mandelbrot", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );
    
    // Draw Foreground
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    double complex c = 0;
    double complex z = 0;
    double complex z_1 = 0;

    for (double i = -200; i < 100; i++) {
        for (double j = -200; j < 100; j++) {
            c = j/100 + I*(i/100);
            int cnt = 0;
            int is_mandelbrot = 1;
            while(cnt < 50)
            {
                cnt++;
                z_1 = z*z + c;
                z = z_1;
                if(cabs(z_1) > 2.0) 
                {
                    is_mandelbrot = 0;
                    break;
                }
            }
            z = 0;
            if(is_mandelbrot)
            {
                SDL_RenderDrawPoint(renderer, j+320 ,i+240);
            }
        }
    }
    // Set render color to blue ( rect will be rendered in this color )

    // Render the Mandelbrot to the screen
    SDL_RenderPresent(renderer);

    // Wait for 5 sec
    SDL_Delay(20000);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}
