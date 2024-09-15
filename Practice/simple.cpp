/* program to implement text box
press esc key to terminate
with comments
*/
#include <graphics.h>

int poly[8];                      // a polygon to display the textbox
int curposx = 100, curposy = 100; // current cursor position
int flag;                         // flag to indicate blinking of cursor
char str[20];                     // string containing typed text
// Function to draw cursor while blinking it
void drawcursor()
{
     if (flag == 0)
          setcolor(WHITE);
     else
          setcolor(BLACK);
     line(curposx, curposy, curposx, curposy + 20);
}
// Function to display key(character) typed
void display(char key[2])
{

     int len;
     cleardevice();
     setfillstyle(1, LIGHTGRAY);
     setcolor(WHITE);
     fillpoly(4, poly);
     flag = (flag == 0) ? 1 : 0;
     switch (key[0])
     {
     case 8: // if backspace is pressed delete the last character from str
          len = strlen(str);
          if (strlen != 0)
          {
               str[len - 1] = '\0';
               curposx -= 7;
          }
          break;
     case '\0': // if the key string is empty then do nothing
          break;
     default:
          strcat(str, key);
          curposx += 7;
     }

     outtextxy(100, 106, str);
     drawcursor();
}
int main()
{
     char key[2];
     int keycount = 0, enough = 0, len;
     /* our polygon array */

     poly[0] = 100;
     poly[1] = 100;
     poly[2] = 200;
     poly[3] = 100;
     poly[4] = 200;
     poly[5] = 130;
     poly[6] = 100;
     poly[7] = 130;
     int gd = DETECT, gm;
     char str[] ="C:\\TurboC++\\Disk\\TurboC3\\BGI";
     //initgraph(&gd, &gm, str);
     initwindow(400, 300, "Form");
     key[0] = '\0';
     flag = 0; // set the flag for cursor blinking
     if (kbhit())
          key[0] = getch(); // get the character typed if any before the loop starts
     key[1] = '\0';
     while (key[0] != 27) // if it is not escape be in loop
     {
          key[0] = '\0'; // destroy the key code from previous loop run
          delay(200);    // delay for cursor blinking
          if (kbhit())
          {                       // if keyboard is hit
               key[0] = getch();  // get the key code of pressed key
               keycount++;        // increment the key count
               if (keycount > 18) // If key count greater than 18 stop taking input
                    enough = 1;
          }
          if (enough)
               key[0] = '\0'; // if enough set key code to zero
          display(key);
     }
     // set the last character as "\0" to terminate the str
     len = strlen(str);
     if (len > 0)
     {
          str[len - 1] = '\0';
     }
     setcolor(WHITE);
     outtextxy(200, 200, str);

     printf("%d,%s", len, str);

     getch();
     closegraph();
     return 0;
}
