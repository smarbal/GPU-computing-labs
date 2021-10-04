/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "rlgl.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    float rotationSpeed = 0.2f;     
    float cubeRotation = 0.0f;         // Rotation of earth around itself (days) in degrees
    float cubeOrbitRotation = 0.0f;    // Rotation of earth around the Sun (years) in degrees
    float smallCubesRotation = 0.0f;          // Rotation of moon around itself
    float smallCubesOrbitRotation = 0.0f;     // Rotation of moon around earth in degrees
    float miniCubesRotation = 0.0f;          // Rotation of moon around itself
    float miniCubesOrbitRotation = 0.0f;     // Rotation of moon around earth in degrees

    InitWindow(screenWidth, screenHeight, "raylib");

    Camera camera = { 0 };
    camera.position = (Vector3){ 3,10, 0 };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    SetCameraMode(camera, CAMERA_FREE);

    Vector3 cubePosition = { 0 };
    Vector3 cube2Position = {0 , 0, 0 }; 
    Vector3 cube3Position = { 0 , 0, 0  };
    Vector3 cube4Position = { 0, 0, 0 };  
    Vector3 miniCube1 = { 0, 0, 0}; 
    Vector3 miniCube2 = {0, 0, 0};  
    Vector3 miniCube3 = { 0, 0, 0 };
    Vector3 miniCube4 = { 0, 0, 0 };
    Vector3 miniCube5 = { 0, 0, 0 };
    Vector3 miniCube6 = { 0, 0, 0 };


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        cubeRotation += (5.0f*rotationSpeed);
        smallCubesRotation += (8.0f*rotationSpeed);
        smallCubesOrbitRotation += (5.0f*rotationSpeed);
        miniCubesRotation += (-4.0f*rotationSpeed);
        miniCubesOrbitRotation += (-5.0f*rotationSpeed);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(WHITE);


            BeginMode3D(camera);

                rlPushMatrix();
                    rlRotatef(cubeRotation, 0, 1.0, 0.0);       // Rotation for Earth itself
                    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                rlPopMatrix();


                rlPushMatrix();
                    rlRotatef(smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                    rlTranslatef(3.9f, 0.0f, 0.0f);          // Translation for Moon orbit
                    rlRotatef(-smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                   
                    rlPushMatrix();
                        rlRotatef(smallCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(cube3Position, 1.0f, 1.0f, 1.0f, RED);// Draw the Earth
                    rlPopMatrix();

                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube1, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 
                    
                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(-1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube2, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 

                rlPopMatrix();

                rlPushMatrix();
                    rlRotatef(smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                    rlTranslatef(-3.0f, 0.0f, -3.0f);          // Translation for Moon orbit
                    rlRotatef(-smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                   
                    rlPushMatrix();
                        rlRotatef(smallCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(cube3Position, 1.0f, 1.0f, 1.0f, RED);// Draw the Earth
                    rlPopMatrix();

                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube3, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 
                    
                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(-1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube4, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 
                rlPopMatrix();

                
                rlPushMatrix();
                    rlRotatef(smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                    rlTranslatef(-3.0f, 0.0f, 3.0f);          // Translation for Moon orbit
                    rlRotatef(-smallCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                    rlPushMatrix();
                        rlRotatef(smallCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(cube4Position, 1.0f, 1.0f, 1.0f, RED);// Draw the Earth
                    rlPopMatrix();
                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube5, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 
                    
                    rlPushMatrix();
                        rlRotatef(miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);     // Rotation for Moon orbit around Earth
                        rlTranslatef(-1.5f, 0.0f, 0.0f);          // Translation for Moon orbit
                        rlRotatef(-miniCubesOrbitRotation, 0.0f, 1.0f, 0.0f);    // Rotation for Moon orbit around Earth inverted
                        rlRotatef(miniCubesRotation, 0.0f, 1.0f, 0.0f);          // Rotation for Moon itself
                        DrawCube(miniCube6, 0.4f, 0.4f, 0.4f, RED);
                    rlPopMatrix(); 

                rlPopMatrix();
                

            EndMode3D();

            DrawText("EXO 1", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}