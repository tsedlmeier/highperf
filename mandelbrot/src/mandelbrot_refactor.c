#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>

#include <SDL2/SDL.h>

#include <sys/resource.h>
// Mandelbrot resolution
#define NPOINTS 1000
#define W NPOINTS // 10000
#define H NPOINTS // 10000
#define RES 0.001

struct Args
{
    int* pBuf;
    int start;
    int end;
};

void sig_handler()
{
    exit(1); 
}

float diff_user_time(struct rusage *start, struct rusage *end)
{
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

void calc_mandel(void* args)
{
    struct rusage t_start, t_end;
    getrusage(RUSAGE_SELF, &t_start);
    //t_start = usage.ru_utime;
    int start = ((struct Args*)args)->start;
    int end = ((struct Args*)args)->end;
    int* pBuf = ((struct Args*)args)->pBuf;

    double complex c = 0;
    double complex z = 0;
    double complex z_1 = 0;

    double res = 0.001;
    for (double i = start; i < end; i+=res) {
        for (double j = -3; j < 3; j+=res) {
            c = j + I*i;
            int cnt = 0;
            int is_mandelbrot = 1;
            while(cnt < 300)
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
                // int w = (int)((i+W/2)/res);
                // int h = (int)((j+H/2)/res);
                int w = (int)((i*NPOINTS/(2*3) + NPOINTS/2));
                int h = (int)((j*NPOINTS/(2*3) + NPOINTS/2));
                pBuf[NPOINTS*h+w] = 1;
                // pBuf[h+w*H] = 1;
            }
        }
    }
    getrusage(RUSAGE_SELF, &t_end);
    printf(" TID %d: : %.06f sec \n", gettid(), diff_user_time(&t_start, &t_end));
    printf("Calc: %d -> %d\n", start, end);
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

    int *buffer = (int*) malloc(NPOINTS*NPOINTS*sizeof(int));
    int n_threads = 6;
    pthread_t tid[n_threads];
    struct Args args[n_threads];

    for (int i = 0; i <n_threads; i++) { // Thread 1
        args[i].pBuf = buffer;
        args[i].start = i-3;
        args[i].end = args[i].start+1;
        pthread_create(&tid[i], NULL, (void*)&calc_mandel, &args[i]);
    }

    for (int i = 0; i <n_threads; i++) { // Thread 1
        pthread_join(tid[i], NULL);
    }

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    for(int w = 0; w < NPOINTS; w++){
        for (int h = 0; h < NPOINTS; h++) {
            if(buffer[NPOINTS*h+w]==1)
                SDL_RenderDrawPoint(renderer, h,w);
        }
    }

    // SDL_RenderSetLogicalSize(renderer, 1280, 720);
    // Render the Mandelbrot to the screen
    SDL_RenderPresent(renderer);

    // Wait for 5 sec
    SDL_Delay(20000);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}
