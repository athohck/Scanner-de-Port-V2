#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[]){
    int sock;
    int ouvert;
    

    if (argc == 3)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
        {
            printf("ERREUR: Impossible de cree le socket\n");
            return 2;
        }
        struct sockaddr_in adress;
        adress.sin_family = AF_INET;
        adress.sin_addr.s_addr = inet_addr(argv[1]);//On se connecte a l'ip de l'argv[1]
        adress.sin_port = htons(atoi(argv[2])); 
        //argv est un string et htons prend un int et atoi permet de convertir un string en int 

        //Premet de se connecter 
        ouvert = connect(sock, (struct sockaddr *)&adress, sizeof(adress));
        if (ouvert < 0)
        {
            printf("Port %s fermer\n", argv[2]);
            return 3;
        }
        else
        {
            
            printf("Port %s Ouvert\n", argv[2]);
            close(sock);    //On ferme le socket 
        }
    }
    else{
        printf("ERREUR: <ip> <port>\n");
        return 1;
    }
    


    
    return 0;
}