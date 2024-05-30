#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>   
#include <fstream>  

#define SCREEN_WIDTH 340 //240 
#define SCREEN_HEIGHT 400 //300
#define GRID_SIZE 20
#define GRID_WIDTH (SCREEN_WIDTH / GRID_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / GRID_SIZE)
#define TOP_MARGIN 20

Color green = { 173, 204, 96, 255 };
Color backgroundColor = green;
Color textColor = BLACK;
Color puntaje = WHITE;
Color BARRA = BLACK;
bool isFullscreen = false;

typedef struct
{
    int x;
    int y;
} Vector2Int;

typedef struct
{
    Vector2Int position;
    Vector2Int velocity;
} SnakeSegment;

enum MenuOption
{
    PLAY,
    RANKING,
    OPTIONS,
    EXIT
};

enum OptionMenu
{
    CHANGE_COLOR,
    BACK
};

bool gameOver = false, jugando = false, play = false;
int score = 0;
char scoreText[10];
int tempScore = score;
int scoreLength = 0;

Vector2Int GenerateFoodPosition(SnakeSegment snake[], int snakeLength) //esta función se encarga de generar la comiuda en una casilla valida donde no la estorben
{
    Vector2Int newFoodPosition;
    bool isValidPosition;

    do
    {
        isValidPosition = true;
        newFoodPosition.x = GetRandomValue(0, GRID_WIDTH - 1);
        newFoodPosition.y = GetRandomValue(1, GRID_HEIGHT - 1);

        for (int i = 0; i < snakeLength; i++)
        {
            if (newFoodPosition.x == snake[i].position.x && newFoodPosition.y == snake[i].position.y)
            {
                isValidPosition = false;
                break;
            }
        }
    } while (!isValidPosition);

    return newFoodPosition;
}

void SaveScore(int score) // guarda el puntaje 
{
    std::ofstream file("ranking.txt", std::ios::app);
    if (file.is_open())
    {
        file << score << std::endl;
        file.close();
    }
}

void LoadTopScores(int topScores[], int size) //carga los puntajes mas altos en el documento txt 
{
    std::ifstream file("ranking.txt");
    int score;
    int count = 0;
    if (file.is_open())
    {
        while (file >> score && count < size)
        {
            topScores[count++] = score;
        }
        file.close();
    }

    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (topScores[j] < topScores[j + 1])
            {
                int temp = topScores[j];
                topScores[j] = topScores[j + 1];
                topScores[j + 1] = temp;
            }
        }
    }
}

void ShowRanking()//muestra los puntajes dentro del top 3 mas altos
{
    int topScores[100] = { 0 };
    LoadTopScores(topScores, 100);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawText("Top 3 Puntajes", (SCREEN_WIDTH / 2) - 60, 50, 20, textColor);

        for (int i = 0; i < 3; i++)
        {
            if (topScores[i] > 0)
            {
                char scoreText[10];
                sprintf(scoreText, "%d", topScores[i]);
                DrawText(scoreText, (SCREEN_WIDTH / 2) - 10, 100 + i * 30, 20, textColor);
            }
        }

        DrawText("Presiona ESPACIO para salir", (SCREEN_WIDTH / 2) - 100, 200, 14, textColor);
        EndDrawing();

        if (IsKeyDown(KEY_SPACE))
            break;
    }
}

void ShowOptions()// es el menu de opciones
{
    OptionMenu currentOption = CHANGE_COLOR;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundColor);
        if (currentOption == CHANGE_COLOR) DrawText(">", (SCREEN_WIDTH / 2) - 110, 80, 25, textColor);
        DrawText("Cambiar Color", (SCREEN_WIDTH / 2) - 80, 80, 25, textColor);
        if (currentOption == BACK) DrawText(">", (SCREEN_WIDTH / 2) - 110, 130, 25, textColor);
        DrawText("Atras", (SCREEN_WIDTH / 2) - 80, 130, 25, textColor);
        EndDrawing();

        if (IsKeyPressed(KEY_DOWN))
        {
            currentOption = (OptionMenu)((currentOption + 1) % 3);
        }
        else if (IsKeyPressed(KEY_UP))
        {
            currentOption = (OptionMenu)((currentOption - 1 + 3) % 3);
        }
        else if (IsKeyPressed(KEY_ENTER))
        {
            switch (currentOption)
            {
            case CHANGE_COLOR:
                if (backgroundColor.r == green.r && backgroundColor.g == green.g && backgroundColor.b == green.b)
                {
                    backgroundColor = BLACK;
                    textColor = WHITE;
                    BARRA = RED;
                }
                else
                {
                    backgroundColor = green;
                    textColor = BLACK;
                    BARRA = BLACK;

                }
                break;
            case BACK:
                return;
            }
        }
    }
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    SetTargetFPS(60);


    //se cargan todas las texturas
    InitAudioDevice();
    Sound fxWav = LoadSound("assets/musica.mp3");
    Sound comer = LoadSound("assets/eating.mp3");
    Sound intro = LoadSound("assets/intro.mp3");
    Sound gameover = LoadSound("assets/gameover.mp3");

    Image headImage = LoadImage("assets/La_creatura1.png");
    ImageResize(&headImage, GRID_SIZE, GRID_SIZE);
    Texture2D headTexture = LoadTextureFromImage(headImage);
    UnloadImage(headImage);

    Image headImagederecha = LoadImage("assets/La_creatura1.1.png");
    ImageResize(&headImagederecha, GRID_SIZE, GRID_SIZE);
    Texture2D headTexturederecha = LoadTextureFromImage(headImagederecha);
    UnloadImage(headImagederecha);

    Image headImageabajo = LoadImage("assets/La_creatura1.2.png");
    ImageResize(&headImageabajo, GRID_SIZE, GRID_SIZE);
    Texture2D headTextureabajo = LoadTextureFromImage(headImageabajo);
    UnloadImage(headImageabajo);

    Image headImageizquierda = LoadImage("assets/La_creatura1.3.png");
    ImageResize(&headImageizquierda, GRID_SIZE, GRID_SIZE);
    Texture2D headTextureizquierda = LoadTextureFromImage(headImageizquierda);
    UnloadImage(headImageizquierda);

    Image bodyImage = LoadImage("assets/La_creatura2.png");
    ImageResize(&bodyImage, GRID_SIZE, GRID_SIZE);
    Texture2D bodyTexture = LoadTextureFromImage(bodyImage);
    UnloadImage(bodyImage);

    Image bodyImagederecha = LoadImage("assets/La_creatura2.1.png");
    ImageResize(&bodyImagederecha, GRID_SIZE, GRID_SIZE);
    Texture2D bodyTexturederecha = LoadTextureFromImage(bodyImagederecha);
    UnloadImage(bodyImagederecha);

    Image bodyImageabajo = LoadImage("assets/La_creatura2.2.png");
    ImageResize(&bodyImageabajo, GRID_SIZE, GRID_SIZE);
    Texture2D bodyTextureabajo = LoadTextureFromImage(bodyImageabajo);
    UnloadImage(bodyImageabajo);

    Image bodyImageizquierda = LoadImage("assets/La_creatura2.3.png");
    ImageResize(&bodyImageizquierda, GRID_SIZE, GRID_SIZE);
    Texture2D bodyTextureizquierda = LoadTextureFromImage(bodyImageizquierda);
    UnloadImage(bodyImageizquierda);

    Image tailImage = LoadImage("assets/La_creatura3.png");
    ImageResize(&tailImage, GRID_SIZE, GRID_SIZE);
    Texture2D tailTexture = LoadTextureFromImage(tailImage);
    UnloadImage(tailImage);

    Image tailImagederecha = LoadImage("assets/La_creatura3.1.png");
    ImageResize(&tailImagederecha, GRID_SIZE, GRID_SIZE);
    Texture2D tailTexturederecha = LoadTextureFromImage(tailImagederecha);
    UnloadImage(tailImagederecha);

    Image tailImageabajo = LoadImage("assets/La_creatura3.2.png");
    ImageResize(&tailImageabajo, GRID_SIZE, GRID_SIZE);
    Texture2D tailTextureabajo = LoadTextureFromImage(tailImageabajo);
    UnloadImage(tailImageabajo);

    Image tailImageizquierda = LoadImage("assets/La_creatura3.3.png");
    ImageResize(&tailImageizquierda, GRID_SIZE, GRID_SIZE);
    Texture2D tailTextureizquierda = LoadTextureFromImage(tailImageizquierda);
    UnloadImage(tailImageizquierda);

    Image image = LoadImage("assets/pan.png");
    ImageResize(&image, GRID_SIZE, GRID_SIZE);
    Texture2D foodTexture = LoadTextureFromImage(image);
    UnloadImage(image);
    


    while (!WindowShouldClose())
    {
        PlaySound(intro);
        MenuOption currentOption = PLAY;
        gameOver = false;
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(backgroundColor);
            if (currentOption == PLAY) DrawText(">", (SCREEN_WIDTH / 2) - 80, 50, 40, textColor);
            DrawText("Jugar", (SCREEN_WIDTH / 2) - 60, 50, 40, textColor);
            if (currentOption == RANKING) DrawText(">", (SCREEN_WIDTH / 2) - 80, 100, 40, textColor);
            DrawText("Ranking", (SCREEN_WIDTH / 2) - 60, 100, 40, textColor);
            if (currentOption == OPTIONS) DrawText(">", (SCREEN_WIDTH / 2) - 80, 150, 40, textColor);
            DrawText("Ajustes", (SCREEN_WIDTH / 2) - 60, 150, 40, textColor);
            if (currentOption == EXIT) DrawText(">", (SCREEN_WIDTH / 2) - 80, 200, 40, textColor);
            DrawText("Salir", (SCREEN_WIDTH / 2) - 60, 200, 40, textColor);
            EndDrawing();

            if (IsKeyPressed(KEY_DOWN))
            {
                currentOption = (MenuOption)((currentOption + 1) % 4);
            }
            else if (IsKeyPressed(KEY_UP))
            {
                currentOption = (MenuOption)((currentOption - 1 + 4) % 4);
            }
            else if (IsKeyPressed(KEY_ENTER))
            {
                switch (currentOption)
                {
                case PLAY:
                    play = true;
                    break;
                case RANKING:
                    while (!WindowShouldClose() && !IsKeyPressed(KEY_SPACE))
                    {
                        ShowRanking();
                    }
                    currentOption = RANKING;
                    break;
                case OPTIONS:
                    ShowOptions();
                    currentOption = OPTIONS;
                    break;
                case EXIT:
                    return 0;
                }
            }

            if (play)
                break;
        }

        if (currentOption == EXIT)
            break;

        PlaySound(fxWav);
        SnakeSegment snake[GRID_WIDTH * GRID_HEIGHT];
        int snakeLength = 1;
       
        snake[0].position.x = GRID_WIDTH / 2;  //determina donde empieza la serpiente que es en el centro
        snake[0].position.y = GRID_HEIGHT / 2;

        Vector2Int food = GenerateFoodPosition(snake, snakeLength);

        float timeSinceLastMove = 0;
        int LastMove = 0;
        float moveInterval = 0.1f;
        UnloadSound(intro);

        Vector2Int desiredDirection = { 0, 0 };

        while (!gameOver)
        {
            while (!jugando)
            {
                BeginDrawing();
                ClearBackground(backgroundColor);
                
                DrawText("Flecha Abajo", (SCREEN_WIDTH / 2) - 60, 100, 20, textColor);
                DrawText("Para Iniciar", (SCREEN_WIDTH / 2) - 60, 160, 20, textColor);
                DrawTexture(headTextureabajo, snake[0].position.x * GRID_SIZE, snake[0].position.y * GRID_SIZE, WHITE);
                if (IsKeyPressed(KEY_DOWN))
                {
                    jugando = true; //activa el ciclo de juego
                    break;
                }

                EndDrawing();
            }

            if (IsKeyPressed(KEY_UP) && snake[0].velocity.y != 1) //mueve la serpiente
            {
                desiredDirection.x = 0;
                desiredDirection.y = -1;
            }
            else if (IsKeyPressed(KEY_DOWN) && snake[0].velocity.y != -1)
            {
                desiredDirection.x = 0;
                desiredDirection.y = 1;
            }
            else if (IsKeyPressed(KEY_LEFT) && snake[0].velocity.x != 1)
            {
                desiredDirection.x = -1;
                desiredDirection.y = 0;
            }
            else if (IsKeyPressed(KEY_RIGHT) && snake[0].velocity.x != -1)
            {
                desiredDirection.x = 1;
                desiredDirection.y = 0;
            }

            timeSinceLastMove += GetFrameTime();
            if (timeSinceLastMove >= moveInterval)
            {
                snake[0].velocity = desiredDirection;

                for (int i = snakeLength - 1; i > 0; i--)
                {
                    snake[i].position = snake[i - 1].position;
                }
                snake[0].position.x += snake[0].velocity.x;
                snake[0].position.y += snake[0].velocity.y;

                if (snake[0].position.x == food.x && snake[0].position.y == food.y)
                {
                    PlaySound(comer);
                    score++;
                    snakeLength++;

                    food = GenerateFoodPosition(snake, snakeLength);
                }

                if (snake[0].position.x < 0 || snake[0].position.x >= GRID_WIDTH ||
                    snake[0].position.y < 1 || snake[0].position.y >= GRID_HEIGHT)
                {
                    DrawText("Game Over!", (SCREEN_WIDTH / 2) - 110, 120, 40, RED);
                    EndDrawing();
                    while (!IsKeyPressed(KEY_ENTER))
                    {
                        gameOver = true;
                        StopSound(fxWav);
                        PlaySound(gameover);
                        SaveScore(score);
                        WaitTime(5);
                        break;
                    }
                    break;
                }

                for (int i = 1; i < snakeLength; i++)
                {
                    if (snake[0].position.x == snake[i].position.x &&
                        snake[0].position.y == snake[i].position.y)
                    {
                        DrawText("Game Over!", (SCREEN_WIDTH / 2) - 110, 120, 40, RED);
                        EndDrawing();
                        while (!IsKeyPressed(KEY_ENTER))
                        {
                            gameOver = true;
                            StopSound(fxWav);
                            PlaySound(gameover);
                            SaveScore(score);
                            WaitTime(5);
                            break;
                        }
                        break;
                    }
                }

                timeSinceLastMove = 0;
            }

            BeginDrawing();
            ClearBackground(backgroundColor);

            DrawTexture(foodTexture, food.x * GRID_SIZE, food.y * GRID_SIZE, WHITE);

            //usa las diferentes texturas dependiendo de a donde gire la serpiente

            Vector2 cabezaDirection;
            cabezaDirection.x = snake[0].position.x - snake[1].position.x;
            cabezaDirection.y = snake[0].position.y - snake[1].position.y;
            
            
            if (desiredDirection.x == 1 && desiredDirection.y == 0)     // Derecha
                DrawTexture(headTexturederecha, snake[0].position.x * GRID_SIZE, snake[0].position.y * GRID_SIZE, WHITE);
            else if (desiredDirection.x == -1 && desiredDirection.y == 0) // Izquierda
                DrawTexture(headTextureizquierda, snake[0].position.x * GRID_SIZE, snake[0].position.y * GRID_SIZE, WHITE);
            else if (desiredDirection.x == 0 && desiredDirection.y == 1)  // Abajo
                DrawTexture(headTextureabajo, snake[0].position.x * GRID_SIZE, snake[0].position.y * GRID_SIZE, WHITE);
            else if (desiredDirection.x == 0 && desiredDirection.y == -1) // Arriba
                DrawTexture(headTexture, snake[0].position.x * GRID_SIZE, snake[0].position.y * GRID_SIZE, WHITE);
             
            for (int i = 1; i < snakeLength - 1; i++)
            {
                
                Vector2 cuerpoDirection;
                cuerpoDirection.x = snake[snakeLength - 1].position.x - snake[snakeLength - 2].position.x;
                cuerpoDirection.y = snake[snakeLength - 1].position.y - snake[snakeLength - 2].position.y;

                Texture2D tailSprite;
                if (cuerpoDirection.x == 1 && cuerpoDirection.y == 0)      // Derecha
                    DrawTexture(bodyTextureizquierda, snake[i].position.x * GRID_SIZE, snake[i].position.y * GRID_SIZE, WHITE);
                else if (cuerpoDirection.x == -1 && cuerpoDirection.y == 0) // Izquierda
                    DrawTexture(bodyTexturederecha, snake[i].position.x* GRID_SIZE, snake[i].position.y* GRID_SIZE, WHITE);
                else if (cuerpoDirection.x == 0 && cuerpoDirection.y == 1)  // Abajo
                    DrawTexture(bodyTexture, snake[i].position.x* GRID_SIZE, snake[i].position.y* GRID_SIZE, WHITE);
                else if (cuerpoDirection.x == 0 && cuerpoDirection.y == -1) // Arriba
                    DrawTexture(bodyTextureabajo, snake[i].position.x * GRID_SIZE, snake[i].position.y * GRID_SIZE, WHITE);
            }

            
            Vector2 tailDirection;
            tailDirection.x = snake[snakeLength - 1].position.x - snake[snakeLength - 2].position.x;
            tailDirection.y = snake[snakeLength - 1].position.y - snake[snakeLength - 2].position.y;

            Texture2D tailSprite;
            if (tailDirection.x == 1 && tailDirection.y == 0)      // Derecha
                DrawTexture(tailTextureizquierda, snake[snakeLength - 1].position.x * GRID_SIZE, snake[snakeLength - 1].position.y * GRID_SIZE, WHITE);
            else if (tailDirection.x == -1 && tailDirection.y == 0) // Izquierda
                DrawTexture(tailTexturederecha, snake[snakeLength - 1].position.x * GRID_SIZE, snake[snakeLength - 1].position.y * GRID_SIZE, WHITE);
            else if (tailDirection.x == 0 && tailDirection.y == 1)  // Abajo
                DrawTexture(tailTexture, snake[snakeLength - 1].position.x * GRID_SIZE, snake[snakeLength - 1].position.y * GRID_SIZE, WHITE);
            else if (tailDirection.x == 0 && tailDirection.y == -1) // Arriba
                DrawTexture(tailTextureabajo, snake[snakeLength - 1].position.x * GRID_SIZE, snake[snakeLength - 1].position.y * GRID_SIZE, WHITE);


            DrawRectangle(0, 0, SCREEN_WIDTH, 20, BARRA);
            while (tempScore != 0)
            {
                tempScore /= 10;
                scoreLength++;
            }
            tempScore = score;
            for (int i = scoreLength - 1; i >= 0; i--)
            {
                scoreText[i] = '0' + (tempScore % 10);
                tempScore /= 10;
            }
            scoreText[scoreLength] = '\0';
            DrawText("Puntaje", 0, 0, 20, puntaje);
            DrawText(scoreText, 80, 0, 20, puntaje);
            EndDrawing();
        }

        break;
        
    }

    UnloadSound(comer);
    UnloadSound(fxWav);
    CloseAudioDevice();
    UnloadTexture(headTexture);
    UnloadTexture(bodyTexture);
    UnloadTexture(tailTexture);
    CloseWindow();

    return 0;
}
