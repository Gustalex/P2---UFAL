#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void batalhas(int vida_clodes, int vida_bezaliel, int dano_clodes, int dano_bezaliel) {
    if (vida_clodes > 0) {
        if (ceil((double) vida_clodes / dano_bezaliel) < ceil((double) vida_bezaliel / dano_clodes)) dano_clodes += 50;
          
        else vida_bezaliel -= dano_clodes;
            
        if (vida_bezaliel > 0) vida_clodes -= dano_bezaliel;
           
        if (vida_clodes > 0 && vida_bezaliel > 0) batalhas(vida_clodes, vida_bezaliel, dano_clodes, dano_bezaliel);
           
        else{
            if (vida_clodes > vida_bezaliel) printf("Clodes\n");
                
            else if (vida_bezaliel > vida_clodes) printf("Bezaliel\n");
        }
    }
}
void rodadas_bat(int rodadas, int cont){
    
    if (cont == rodadas){
        return;
    }
    else{
        int vida_clodes, vida_bezaliel, dano_clodes, dano_bezaliel;

        scanf("%d %d %d %d", &vida_clodes, &vida_bezaliel, &dano_clodes, &dano_bezaliel);

        batalhas(vida_clodes, vida_bezaliel, dano_clodes, dano_bezaliel);
    }
        rodadas_bat(rodadas, cont + 1);
}
int main() {
    
    int rodadas;
    scanf("%d", &rodadas);

    rodadas_bat(rodadas, 0);

    return 0;
}