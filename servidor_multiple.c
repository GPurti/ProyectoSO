#include <stdio.h>
#include <string.h>
typedef struct {
	char nombre [20];
	int socket;
	
} Conectado;

typedef struct {
	Conectado conectados [100];
	int num;
	
} ListaConectados;
int Pon (ListaConectados *lista, char nombre[20], int socket){
	if (lista->num ==100)
		return -1;
	else{
		strcpy(lista->conectados[lista->num].nombre,nombre);
		lista->conectados[lista->num].socket = socket;
		lista->num++;
		return 0;
	}
}
int DameSocket (ListaConectados *lista, char nombre[20]){
	// Devuelve el socket o -1 si no está en la lista
	int i=0;
	int encontrado =0;
	while ((i< lista->num) && !encontrado ){
		if (strcmp(lista->conectados[i].nombre,nombre)==0)
			encontrado =1;
		if (!encontrado)
			i=i+1;
	}
	if (encontrado)
		return lista->conectados[i].socket;
	else
		return -1;
		
}
int DamePos (ListaConectados *lista, char nombre[20]){
	// Devuelve la posicion en la lista o -1 si no está en la lista
	int i=0;
	int encontrado =0;
	while ((i< lista->num) && !encontrado ){
		if (strcmp(lista->conectados[i].nombre,nombre)==0)
			encontrado =1;
		if (!encontrado)
			i=i+1;
	}
	if (encontrado)
		return i;
	else
		return -1;
}
int Elimina(ListaConectados *lista, char nombre[20])
	//Devuelve el socket o -1 si no está en la lista
{
	int pos = DamePos (lista,nombre);
	if (pos==-1)
		return -1;
	else
	{
		int i;
		for (i=pos; i< lista->num-1;i++)
		{
			lista->conectados[i] = lista->conectados[i+1];
			//strcpy(lista->conectados[i].nombre, lista->conectados[i+1].nombre);
			//lista->conectados[i].socket=lista->conectados[i+1].socket;
		}
		lista->num--;
		return 0;
		
	}
}
void DameConectados ( ListaConectados *lista, char conectados[300]){
	//Pone en conectados los nombres de todos los conectados separados por /. Primero pone el num de conectados
	sprintf(conectados,"%d", lista->num);
	int i;
	for (i=0; i< lista->num; i++)
		sprintf(conectados, "%s/%s", conectados, lista->conectados[i].nombre);
}
void DameTodosSockets ( ListaConectados *lista, char nombres[80], char *sockets){
//Escribe una funciÃ³n que recibe un vector de caracteres con los nombres de jugadores
//separados por comas y revuelve una cadena de caracteres con los sockets de cada uno
//de estos jugadores, tambiÃ©n separados por comas.
	printf("vector nombres %s\n", nombres);
	char *p=strtok(nombres,",");
	int i=0;
	int n=lista->num;
	printf("%d\n",n);
	while (p!=NULL){
		while (i<n){
			if (strcmp(lista->conectados[i].nombre,p)==0)
			{
				printf("He entrado %s\n",lista->conectados[i].nombre);
				int valor=lista->conectados[i].socket;
				sprintf(sockets,"%s, %d", sockets, valor);
			}
			i=i+1;
		}
		i=0;
		p=strtok(NULL,",");

	}
}
int main(int argc, char *argv[]) {
	ListaConectados miLista;
	miLista.num=0;
	Pon(&miLista, "Guillem", 3);
	Pon(&miLista, "Itziar", 14);
	Pon(&miLista, "Xavi", 30);
/*	int res = Pon(&miLista, "Juan", 5);*/
/*	if (res ==-1)*/
/*		printf("Lista llena. No se puede añadir.\n");*/
/*	else */
/*		printf("Añadido bien.\n");*/
	
/*	int pos = DamePos (&miLista, "Juan");*/
/*	if(pos != -1)*/
/*		printf("El socket de Juan es: %d\n", miLista.conectados[pos].socket);*/
/*	else*/
/*		printf("Ese usuario no esta en la lista,\n");*/
/*	res = Elimina (&miLista, "Juan");*/
/*	if (res==-1)*/
/*		printf ("No está.\n");*/
/*	else*/
/*		printf( "Eliminado.\n");*/
	
/*	pos = DamePos (&miLista, "Juan");*/
/*	if(pos != -1)*/
/*		printf("El socket de Pedro es: %d\n", miLista.conectados[pos].socket);*/
/*	else*/
/*		printf("Ese usuario no esta en la lista,\n");*/
/*	char conectados[300];*/
/*	DameConectados (&miLista,conectados);*/
/*	printf("Resultado: %s\n", conectados);*/
/*	char *p = strtok(conectados, "/");*/
/*	int n=atoi(p);*/
/*	int i;*/
/*	for (i=0; i<n;i++){*/
/*		char nombre [20];*/
/*		p=strtok(NULL, "/");*/
/*		strcpy(nombre,p);*/
/*		printf("Conectado: %s\n", nombre);*/
		
/*	}*/
	char nombres[20];
	strcpy(nombres, "Guillem,Xavi,Itziar,Isma,Genis");
	char vectorsockets[60];
	DameTodosSockets ( &miLista, nombres, vectorsockets);
	printf("%s",vectorsockets);
	return 0;
}

