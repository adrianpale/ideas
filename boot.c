//boot.c
void main(){
void kmain(void)
{
	const char *str = "Welcome to Hakerio Productions OS";
	char *vidptr = (char*)0xb8000;	//Inicia memoria de video

	unsigned int i = 0;
	unsigned int j = 0;

	while(j<80*25*2){				//Esto bucle limpia la pantalla
		vidptr[j] = ' ';			//Caracter en blanco que se imprimira para limpiarla
		vidptr[j+1] = 0x07;			//Atributo-Byte, Gris Claro en Pantalla Negra
		j = j+2;					//(Hay 25 lineas cada 80 columnas, cada elemento tiene 2 bytes)
	}

	j = 0;

	while(str[j] != '\0'){			//Este bucle escribe el String en la memoria de video
		vidptr[i] = str[j];			//Caracteres ASCII
		vidptr[i+1] = 0x07;			//Atributo-Byte, Da el caracter 'Black bg' y 'Gris Claro fg'
		++j;
		i = i+2;
	}

	return;
}
}