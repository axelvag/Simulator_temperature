#include <Grapic.h>
#include <cmath>
#include <iostream>

using namespace std;
using namespace grapic;
const int DIMW = 512;

const int MAX_HEATDIM = 64;

const int AIR = 0;
const int WALL = 1;
const float TEMP_MIN= -5.f;
const float TEMP_MAX= 38.f;



struct Color
{
    int r,g,b;
};

Color make_color(int r, int g, int b)
{
    Color c;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}

Color operator+(Color a, Color b)
{
    return make_color(a.r+b.r, a.g+b.g, a.b+b.b);
}

Color operator*(float f, Color b)
{
    return make_color(f*b.r, f*b.g, f*b.b);
}


/// Question 1 : structure Parcelle, structure World
/// DEBUT REPONSE

struct Parcelle
{
    int type;
    float t;
};



/// FIN REPONSE

struct World
{
/// DEBUT REPONSE
    Parcelle tab[MAX_HEATDIM ][MAX_HEATDIM ];
    int dx, dy;
/// FIN REPONSE
};


void rectangleCell(World& w, int xm, int ym, int xM, int yM, int type, float t)
{
/// Question 2 :
/// DEBUT REPONSE
    int i,j;
    for(i=xm;i<=xM;i++)
        for(j=ym;j<=yM;j++)
        {
            w.tab[i][j].type = type;
            w.tab[i][j].t = t;
        }
/// FIN REPONSE
}



void init (World & w)
{
/// Question 3 : init
/// DEBUT REPONSE

    w.dx = 32;
    w.dy = 32;
    rectangleCell( w, 0,0, w.dx-1, w.dy-1, AIR, 0.f );

    rectangleCell( w, 10,10, w.dx-10, w.dy-10, AIR, 38.f );

    rectangleCell( w, 10,10, 10, w.dy-10, WALL, 0.f );



/// FIN REPONSE
}


Color temperatureToColor(float temperature)
{
    Color b = make_color(0,0,255);
    Color r = make_color(255,0,0);

/// Question 4 : interpolation
/// DEBUT REPONSE
    float t;
    t = (temperature-TEMP_MIN) / (TEMP_MAX-TEMP_MIN);

    Color resultat = (1-t)*b + t*r;
    return resultat;

/// FIN REPONSE
}


void draw(World w)
{
/// Question 5 : draw
/// DEBUT REPONSE

    float hl, lc;
    Color col;
    hl = float(DIMW) / w.dy;
    lc = float(DIMW) / w.dx;
    int i,j;
    for(i=0;i<w.dx;i++)
        for(j=0;j<w.dy;j++)
        {
            if (w.tab[i][j].type==WALL)
                color(0,0,0);
            else
            {
                col = temperatureToColor( w.tab[i][j].t);
                //color(255,0,0);
                color( col.r, col.g, col.b);
            }
            rectangleFill( i*lc, j*hl,  (i+1)*lc, (j+1)*hl );
        }



/// FIN REPONSE
    color(0,0,0);
    grid( 0,0, DIMW-1, DIMW-1, w.dx, w.dy);
}



/// Question 6 : laplacien
/// DEBUT REPONSE



float laplacien(World w, int i, int j)
{
    int x,y;
    float t_moy = 0.f;
    int n=0;
    for( x=i-1; x<=i+1; x++)
        for( y=j-1; y<=j+1; y++)
            if ((x>=0) && (x<w.dx))
                if ((y>=0) && (y<w.dy))
                    if (!( (x==i)  && (y==j)))
                        if (w.tab[x][y].type==AIR)
                        {

                            t_moy += w.tab[x][y].t;
                            n++;
                        }
    t_moy /= n;

    return t_moy - w.tab[i][j].t;

}

/// FIN REPONSE


void update (World &w)
{
/// Question 7 : update
/// DEBUT REPONSE

    const float dt = 0.1f;
    int i,j;
    World w_old = w;
    float l;
    for(i=0;i<w.dx;i++)
        for(j=0;j<w.dy;j++)
        {
            l = laplacien( w_old, i, j);
            w.tab[i][j].t  = w_old.tab[i][j].t + dt * l;
        }


    int x,y;
    float hl, lc;
    mousePos(x,y);
    hl = float(DIMW) / w.dy;
    lc = float(DIMW) / w.dx;

    x = x / lc;
    y = y / hl;
    color(255,255,0);

    print( 5, 5, x);
    print( 55, 5, y);
    print( 5, 480, w.tab[x][y].t);

    if (isMousePressed(SDL_BUTTON_LEFT))
    {
        if(w.tab[x][y].type!=WALL)
        {
            rectangleCell( w, x,y, x, y, AIR, 38.f );
        }
    }


    rectangleCell( w, 0,10, 0, 11, AIR, -5.f );

/// FIN REPONSE
}




int main(int argc, char** argv)
{
    bool stop=false;
         winInit("Chaud, froid ...", DIMW, DIMW);
         backgroundColor(0,255,255);
    World w;
    init(w);
    while (!stop)
    {

        winClear();
        draw(w);
        update(w);
        stop= winDisplay();
    }
     winQuit();
    return 0;
}
