/*
ball with pause/start
*/


// standard libraries
#include <stdio.h>
#include <string.h>

// Stanford Portable Library
#include "gevents.h"
#include "ginteractors.h"
#include "gwindow.h"

int main(int argc, char const *argv[])
{
    // init window
    GWindow window = newGWindow(320, 240);

    // init ball
    GOval circle = newGOval(0, 110, 20, 20);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);

    // init velocity of ball, x
    double velocity = 2.0;

    // init pause/start button
    GButton button = newGButton("Pause/Start");
    setActionCommand(button, "click");

    // add button to southern region of window
    addToRegion(window, button, "SOUTH");

    // while loop
    while (true)
    {

        // move circle along x-axis
        move(circle, velocity, 0);
        // init event
        GActionEvent event = waitForEvent(ACTION_EVENT);

        // listen window close event
        if (getEventType(event) == WINDOW_CLOSED)
        {
            // break loop
            break;
        }

        // control ball velocity



        // bounce off right edge of window
        if (getX(circle) + getWidth(circle) >= getWidth(window))
        {
            velocity = -velocity;
        }

        // bounce off left edge of window
        else if (getX(circle) <= 0)
        {
            velocity = -velocity;
        }

        // listen button event
        if (strcmp(getActionCommand(event), "click") == 0)
        {
            printf("button was clicked\n");
        }

        pause(10);

    }
    // close window
    closeGWindow(window);
    return 0;
}
