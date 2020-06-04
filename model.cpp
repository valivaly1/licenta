#include "librarie"

void setup()
{
// Aici se realizeza setarea initiala a modulului LoRaWAN	
}

void loop(void)
{
//Aici se scrie codul care trebuie executat intr-un loop, de exmplu trimiterea de date catre server sau citirea acestora din cache
}

void functie_custom(){
// de asemenea se pot realiza si alte functii custom acestea fiind apelate in int main sau in orice alta fuctie care este apelata in int main
}

int main (){
	setup();
	functie_custom();
	while(1){
		loop();
	}
	return (0);
}
