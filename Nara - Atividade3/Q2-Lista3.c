#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

float Distancia(float, float, float, float);
int main()
{
	setlocale(LC_ALL, "");
	float x1, y1, x2, y2, r;

	printf("Informe as coordenadas do ponto 1:\n");
	scanf("%f", &x1);
	scanf("%f", &y1);
	printf("Informe as coordenadas do ponto 2: \n");
	scanf("%f", &x2);
	scanf("%f", &y2);
	r = Distancia(x1, y1, x2, y2);
	printf("A distância é:", r);
	return 0;

}



float Distancia(float x1, float y1, float x2, float y2)
{
	float Dist1, Dist2, res ;

	Dist1 = pow((x1 - x2), 2);
	Dist2 = pow((y1 - y2), 2);

	res = sqrt(Dist1 + Dist2);

	return res;
}
