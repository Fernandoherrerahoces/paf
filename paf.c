#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int N,p,i,j,aux,aux1,dif,menor;
	int *arreglo;
	FILE *archivo_entrada, *archivo_salida;
	archivo_entrada=fopen("entrada.ent","r");
	archivo_salida=fopen("salida.sal","w+");
	fscanf(archivo_entrada,"%d",&N);
	arreglo=(int *)calloc(N,sizeof(int));
	for (i=0;i<N;i++)
	{
		fscanf(archivo_entrada,"%d",arreglo+i);
	}
	for (p=1;p<N;p++)
	{
		aux=0;
		aux1=0;
		for (i=0;i<p;i++)
		{
			aux=*(arreglo+i)+aux;
		}
		for (j=i;j<N;j++)
		{
			aux1=*(arreglo+j)+aux1;
		}
		if (p==1)
		{
			dif=abs(aux-aux1);
		}
		else
		{
			menor=abs(aux-aux1);
			if (menor<dif) dif=menor;
		}
	}
	fprintf (archivo_salida,"%d",dif);
	fclose(archivo_entrada);
	fclose(archivo_salida);
}