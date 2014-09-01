//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
void removeGWindow(GWindow gw, GObject gobj);

int main(int argc, char const *argv[])
{
    bool god_mod = false;

    // accept extra one arg(option)
    if (argc > 2)
    {
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "god") == 0)
    {
        god_mod = true;
    }
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // init number of ball x y velocity
    double velocity_x = drand48() * 3 + 1;
    double velocity_y = drand48() * 3 + 1;

    GLine baseline = newGLine(WIDTH/2, 0, WIDTH/2, HEIGHT);
    add(window, baseline);

    GObject object;

    // wait for click start the game
    waitForClick();

    double x, y, paddle_x, paddle_y = 0.0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        // check for mouse event
        // make paddle follow the mouse move
        // check god_mode if is not, use mouse control
        // if is true, dont use mouse control
        // auto set paddle'x = ball'x
        if(!god_mod){
            GEvent event = getNextEvent(MOUSE_EVENT);

            // if we heard one
            if (event != NULL)
            {
                // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                {
                    // ensure circle follows top cursor
                    paddle_x = getX(event) - getWidth(paddle) / 2;
                    paddle_y = getY(paddle);
                    setLocation(paddle, paddle_x, paddle_y);
                }
            }
        }
        else{
            paddle_x = getX(ball) - (getWidth(paddle)/2);
            paddle_y = getY(paddle);
            setLocation(paddle, paddle_x, paddle_y);
        }


        // check velocity x direction
        // if reach window left or right, turn back
        if(getX(ball) >= (getWidth(window) - getWidth(ball)) || getX(ball) <= 0){
            velocity_x = - velocity_x;
        }

        // check velocity y direction
        // if reach window top or bottom, turn back
        // if hit buttom live minus 1
        // relocation ball
        if(getY(ball) >= (getHeight(window) - getHeight(ball))){
            velocity_y = - velocity_y;
            lives --;
            x = (getWidth(window) - getWidth(ball)) / 2;
            y = (getHeight(window) + getFontAscent(ball)) / 2;
            setLocation(ball, x, y);
        }
        else if(getY(ball) <= 0){
            velocity_y = - velocity_y;
        }

        // collision object
        object = detectCollision(window, ball);

        // if hit something
        if (object != NULL){
            // if hit paddle, velocity y turn back
            if(object == paddle){
                velocity_y = -velocity_y;
            }
            //strcmp (key,buffer) == 0
            //0 the contents of both strings are equal
            // hit the brick, velocity y turn back
            // update points and sorce broad and minus brick number
            else if(strcmp(getType(object), "GRect") == 0){
                removeGWindow(window, object);
                velocity_y = -velocity_y;
                points += 1;
                updateScoreboard(window, label, points);
                bricks --;
            }
        }

        // move ball
        move(ball, velocity_x, velocity_y);

        // pause 10 micro second
        pause(10);
    }

    // show game over label
    GLabel game_over = newGLabel("GAME OVER");
    setFont(game_over, "SansSerif-18");
    setColor(game_over, "RED");
    x = (getWidth(window) - getWidth(game_over)) / 2;
    y = (getHeight(window) + getFontAscent(game_over)) / 2;
    setLocation(game_over, x, y + 50);
    add(window, game_over);


    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // init row bricks
    // brick width
    int brick_width = 35;
    // birck height
    int brick_height = 8;

    // start position
    double start_x = 2.5;
    double start_y = 100;

    // x span
    double x_span = WIDTH / COLS;
    // y span
    double y_span = 10;

    // color list
    string color[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};

    for (int i = 0; i < ROWS; i++)
    {
        // init col bricks
        for (int j = 0; j < COLS; j++)
        {
            GRect brick = newGRect(start_x + j*x_span, start_y + i*y_span, brick_width, brick_height);
            setFilled(brick, true);
            setColor(brick, color[i]);
            //setLocation(label, x, y - 50);
            add(window, brick);
        }
    }

}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    int ball_rad = RADIUS;
    GOval ball = newGOval(0, 0, ball_rad*2, ball_rad*2);
    double x = (getWidth(window) - getWidth(ball)) / 2;
    double y = (getHeight(window) + getFontAscent(ball)) / 2;
    setLocation(ball, x, y);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    int paddle_width = 100;
    int paddle_height = 10;
    GRect paddle = newGRect(0, 0, paddle_width, paddle_height);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    double x = (getWidth(window) - getWidth(paddle)) / 2;
    double y = (getHeight(window) + getFontAscent(paddle)) / 2 + 100;
    setLocation(paddle, x, y);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("Socre board");
    setFont(label, "SansSerif-18");
    setColor(label, "GRAY");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) + getFontAscent(label)) / 2;
    setLocation(label, x, y - 50);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
