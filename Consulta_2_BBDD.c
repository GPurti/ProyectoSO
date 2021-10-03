#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char identificador[20]="3";
	char consulta [80];
	int ismael=0;
	int itziar=0;
	int guillem=0;
	int victor=0;
	int azahara=0;
	char avatar[20];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "BBDD",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	// consulta SQL para obtener una tabla con todos los datos
	// de la base de datos
	strcpy(consulta,"SELECT Participacion.Avatar FROM (Jugador, Participacion) WHERE Jugador.Identificador = '");
	strcat (consulta, identificador);
	strcat (consulta,"' AND Participacion.Id_J = Jugador.Identificador");
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de un jugador.
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	// En una fila hay tantas columnas como datos tiene un
	// jugador. En nuestro caso hay dos columnas: Partidas_ganadas(row[0]) y
	// Partidas_jugadas(row[1]) .
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	{
		while (row !=NULL) {
			if (strcmp(row[0],"Ismael")==0)
				ismael=ismael+1;
			else if (strcmp(row[0],"Itziar")==0)
				itziar=itziar+1;
			else if (strcmp(row[0],"Guillem")==0)
				guillem=guillem+1;
			else if (strcmp(row[0],"Victor")==0)
				victor=victor+1;
			else if (strcmp(row[0],"Azahara")==0)
				azahara=azahara+1;
			
			strcpy(avatar,"Ismael");
			int i=ismael;
			if (i<itziar){
				i=itziar;
				strcpy(avatar,"Itziar");
			}
			if (i<guillem){
				i=guillem;
				strcpy(avatar,"Guillem");
			}
			if (i<victor){
				i=victor;
				strcpy(avatar,"Victor");
			}
			if (i<azahara){
				i=azahara;
				strcpy(avatar,"Azahara");
			}
			
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
		}
		
		printf("El avatar m�s jugado es: %s \n",avatar);
	}
	// cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);
	
}
