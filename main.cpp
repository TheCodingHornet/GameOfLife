#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;

void initGrid(std::vector<std::vector<int> > &grid) {
    std::srand(std::time(0));
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            grid[x][y] = std::rand() % 2;
        }
    }
}

int countNeighbors(const std::vector<std::vector<int> > &grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + GRID_WIDTH) % GRID_WIDTH;
            int ny = (y + j + GRID_HEIGHT) % GRID_HEIGHT;
            count += grid[nx][ny];
        }
    }
    return count;
}

void updateGrid(const std::vector<std::vector<int> > &grid, std::vector<std::vector<int> > &newGrid) {
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            int neighbors = countNeighbors(grid, x, y);
            if (grid[x][y] == 1) {
                newGrid[x][y] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newGrid[x][y] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void drawGrid(SDL_Renderer *renderer, const std::vector<std::vector<int> > &grid) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            if (grid[x][y] == 1) {
                SDL_Rect cell = {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
                                          HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    std::vector<std::vector<int> > grid(GRID_WIDTH, std::vector<int>(GRID_HEIGHT, 0));
    std::vector<std::vector<int> > newGrid(GRID_WIDTH, std::vector<int>(GRID_HEIGHT, 0));

    initGrid(grid);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        updateGrid(grid, newGrid);
        grid = newGrid;

        drawGrid(renderer, grid);

        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
