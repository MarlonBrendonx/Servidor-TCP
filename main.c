#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main(void)
{

	 int sock;
	 struct sockaddr_in address;

	 //socket para para domínio TCP/IP e tipo de comunicação TCP
	 sock = socket(AF_INET, SOCK_STREAM, 0);
	 sock == -1  ? perror("Socket:") :  perror("Socket:") ;

	 address.sin_family 	 	= AF_INET;	//Atribuindo a família do endereço como sendo TCP/IP
	 address.sin_port 	 	= htons(8000);	//Porta para comunicação,mantendo a ordem dos bytes
	 address.sin_addr.s_addr 	= INADDR_ANY;	//Aceitando todos os IPs locais
	 bzero(&(address.sin_zero), 8);			//Preenche os bytes com 0 

 	 //associa o socket criado a porta local do sistema
	 bind(sock,(struct sockaddr *)&address,sizeof(struct sockaddr)) == -1 ? perror("Bind: ") : 
	 perror("Bind: ");

	 //Habilitando socket para receber 3 conexões
	 ( listen(sock,3) < 0  ) ? perror("Listen:") : perror("Listen:"); 


	 do{

		 int accpt;
	
		 struct sockaddr_in cliente_address;
		 socklen_t sin_size;
		 

		 sin_size = sizeof(struct sockaddr_in);
		 
		 //Aceitando conexões
		 (accpt=accept(sock,(struct sockaddr*)&cliente_address,&sin_size) < 0) ? perror("Accept:") : 			 perror("Accept:");

		 printf("\nRecebendo conexao de: %s",inet_ntoa(cliente_address.sin_addr));

		 
		 close(accpt);

	}while(1);
}
