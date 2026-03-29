Scanner de ports en C - V2
Scanner de ports TCP écrit en C. Version améliorée du scanner V1 avec une commande help et un affichage amélioré.
Nouveautés par rapport à la V1

Commande help qui affiche les ports principaux et leurs descriptions
Affichage du résultat encadré
Meilleure gestion des erreurs (segfault corrigé quand aucun argument n'est passé)
Ajout de la fonction affichePort()

-------------------
Compilation
bashgcc scannerV2.c -o scan

-------------------
Utilisation
bash./scan <ip> <port>
./scan help

------------------
Exemples
bash./scan 192.168.1.1 80
./scan 127.0.0.1 22
./scan help

-----------------
Résultat
|-------------------|
|Port 80 Ouvert
|-------------------|

|-------------------|
|Port 22 fermer
|-------------------|

-----------------
Commande help
./scan help

|21 |FTP | Transfert de fichiers
|22 |SSH | Connexion distante sécurisée
|23 |Telnet | Connexion non sécurisée
|25 |SMTP | Envoi d'emails
|53 |DNS | Résolution de domaines
|80 |HTTP | Web non sécurisé
|110 |POP3 | Réception d'emails
|443 |HTTPS | Web sécurisé
|3306 |MySQL | Base de données
|3389 |RDP | Bureau à distance Windows
|8080 |HTTP alternatif

------------------
Comment ça marche
Le programme tente une connexion TCP sur le port ciblé via une socket.
Si la connexion réussit, le port est ouvert. Sinon, il est fermé.
La fonction affichePort() affiche les ports principaux et leurs descriptions.
