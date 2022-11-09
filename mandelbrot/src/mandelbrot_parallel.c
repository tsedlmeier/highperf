#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <pthread.h>
#include <signal.h>

#define W 640
#define H 480

struct Args
{
    int* pBuf;
    int start;
};

void calc_mandel(void* args)
{
    int start = ((struct Args*)args)->start;
    printf("Thread: %d, start: %d\n", gettid(), start);
    int* pBuf = ((struct Args*)args)->pBuf;

    double complex c = 0;
    double complex z = 0;
    double complex z_1 = 0;

    for (double i = start; i < start+300; i++) {
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
                int w = (int)(i+W/2);
                int h = (int)(j+H/2);
                pBuf[w*h] = 1;
            }
        }
    }
}

void sig_handler()
{
    exit(1); 
}
int main()
{
    signal(SIGINT,sig_handler);
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    window = SDL_CreateWindow
    (
        "Mandelbrot", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        W,
        H,
        SDL_WINDOW_SHOWN
    );
    // Setup renderer
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    // Clear winow
    SDL_RenderClear(renderer);
    // Draw Foreground
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

    int buffer[W*H] = {0};
    pthread_t tid;
    struct Args args;
    args.pBuf = buffer;
    args.start = -300;
    pthread_create(&tid, NULL, (void*)&calc_mandel, &args);
    pthread_join(tid, NULL);

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    for(int w = 0; w < W; w++){
        for (int h = 0; h < H; h++) {
            if(buffer[w*h]==1)
                SDL_RenderDrawPoint(renderer, w,h);
        }
    }
    // Render the Mandelbrot to the screen
    SDL_RenderPresent(renderer);

    // Wait for 5 sec
    SDL_Delay(20000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}
