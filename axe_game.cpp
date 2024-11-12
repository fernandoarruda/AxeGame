#include "raylib.h"

int main ()
{
    //window dimensions
    int width = 1920;
    int height = 1080;
    InitWindow(width, height, "Fernando Arruda");

    //circle cordinates
    int circle_x = 300;
    int circle_y = 600;
    int raio = 100;

    //circle edges
    int l_circle_x = circle_x - raio;
    int r_circle_x = circle_x + raio;
    int u_circle_y = circle_y - raio;
    int b_circle_y = circle_y + raio;
  
    //rectangle cordinates
    int axe_y = 0;
    int axe_width = 100;
    int axe_height =150;
    int axe_x = (width / 2 - (axe_width / 2));//coloca o quadrado no centro da tela

    //rectangle edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_width;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_height;

    // Main game loop
    int direction = 10;

    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!!!", 400, 200, 120, RED);
        }
        else
        {
        //Game logic begins

        //update de edges
        l_circle_x = circle_x - raio;
        r_circle_x = circle_x + raio;
        u_circle_y = circle_y - raio;
        b_circle_y = circle_y + raio;
        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_width;
        u_axe_y = axe_y;
        b_axe_y = axe_y + axe_height;

        //update collision_with_axe

        collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= r_circle_x);

        DrawCircle(circle_x,circle_y,raio, BLUE);
        DrawRectangle (axe_x, axe_y, axe_width, axe_height,RED);

        // move the axe

        axe_y += direction;

        if (axe_y > (height-axe_height) || axe_y < 0)
        {
            direction = -direction;
        }
        
        /*if (axe_y > (height - axe_height))
        {
            direction -= 10;
        }
        
         if (axe_y < (height - height + axe_height))
        {
            direction += 10;
        }*/

        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT) && circle_x < (width - raio))
        {
            circle_x = circle_x + 10;
        }

         if (IsKeyDown(KEY_A)|| IsKeyDown(KEY_LEFT) && circle_x > (width + raio - width))
        {
            circle_x = circle_x - 10;
        }
    
        //Game logic ends
        }
        

        
        EndDrawing();
    }
}
