#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> 

void affichePort(){
    printf("|21 |FTPT | ransfert de fichiers\n");
    printf("|22 |SSH | Connexion distante sécurisée\n");
    printf("|23 |Telnet | Connexion non sécurisée\n");
    printf("|25 |SMTP | Envoi d'emails\n");
    printf("|53 |DNS | Résolution de domaines\n");
    printf("|80 |HTTP | Web non sécurisé\n");
    printf("|110 |POP3 | Réception d'emails\n");
    printf("|443 |HTTPS | Web sécurisé\n");
    printf("|3306 |MySQL | Base de données\n");
    printf("|3389 |RDP | Bureau à distance Windows\n");
    printf("|8080 |HTTP alternatif\n");
}
int main(int argc, char *argv[]){
    int sock;
    int ouvert;
    if (argc == 1)
    {
        printf("ERREUR: <help>");
        return 1;
    }
    
    //On affiche la liste des port si l'argument est help
    if (strcmp( argv[1], "help") == 0)
    {
      affichePort();
    }
    else if(argc == 3)
    {
        //Crée le socket 
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
            printf("|-------------------|\n");
            printf("|Port %s fermer\n", argv[2]);
            printf("|-------------------|\n");
            return 3;
        }
        else
        {
            printf("|-------------------|\n");
            printf("|Port %s Ouvert\n", argv[2]);
            printf("|-------------------|\n");
            close(sock);    //On ferme le socket 
        }
    }
    else{
        printf("ERREUR: <ip> <port>\n");
        return 4;
    }
    


    
    return 0;
}