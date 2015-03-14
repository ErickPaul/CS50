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

// colors
char c[5][10]={"BLUE","GREEN","RED","YELLOW","CYAN"};

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    double v1,v2;
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

    // keep playing until game over
    v1=drand48()*2;
    v2=drand48()*2;
    while (lives > 0 && bricks > 0)
    {
        // TODO
        
        // move circle along x-axis
        move(ball, v1, v2);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            v1 = -v1;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            v1 = -v1;
        }
            
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            v2 = -v2;
        }

        // bounce off left edge of window
        else if (getY(ball) <= 0)
        {
            v2 = -v2;
        }

        // linger before moving again
        pause(10);

        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle moves only in horizontal direction
                double x = getX(event) - getWidth(paddle) / 2;
                setLocation(paddle, x, HEIGHT-100);
            }
                       
        }
        
        GObject object = detectCollision(window, ball);
    
        if (object==paddle&&getY(ball)<HEIGHT-100)
        {
            // TODO
            
            v2=-v2;
        }
        
        if(getY(ball)<200&&object!=NULL)
        {
            removeGWindow(window, object);
            v2=-v2;
            points++;
            bricks--;
        }

        /*if (object==label)
        {
            // TODO
            
            int temp=v1;

            v1=-v2;
            
            v2=-temp;
        }*/
        
        if(getY(ball)>HEIGHT-100)
        {
            lives--;
            setLocation(ball,WIDTH/2,HEIGHT/2);
            v1=drand48()*2;
            v2=drand48()*2;
            continue;
        }
        updateScoreboard(window,label,points);
    }        

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
    // TODO
    int k=5;
    int l=50;
    for(int i=1;i<=ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            k=5+40*j;
    
            GRect rect = newGRect(k, l, 30, 10);
            
            setColor(rect,c[i-1]);
     
            setFilled(rect, true);
    
            add(window, rect);
    
        }
        
        l=50+20*i;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH/2,HEIGHT/2,2*RADIUS,2*RADIUS);
    
    setColor(ball,"BLACK");
     
    setFilled(ball, true);
    
    add(window,ball);
    
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect rect = newGRect(WIDTH/2, HEIGHT-100, 70, 10);
    
    setColor(rect,"BLACK");
     
    setFilled(rect, true);
    
    add(window, rect);

    return rect;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    double x,y;
    GLabel score = newGLabel("0");
    setFont(score, "SansSerif-32");
    setColor(score,"LIGHT_GRAY");
    x = WIDTH/2;
    y = HEIGHT/2-110+getFontAscent(score) / 2;
    setLocation(score, x, y);
    add(window, score);
    return score;
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
