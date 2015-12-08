#define cle_bal 10
#define cle_shmem 20
#define cle_mutex 21

#define NB_VOITURES 100

#define NORD 1
#define EST 2
#define SUD 3
#define OUEST 4

#define VERT 1
#define ROUGE 0

int depart_prio = 0;
int arrivee_prio = 0;

Coordinateur {
    créer la mémoire partagée qui contient : pid_coord, pid_feux, feu1, feu2, feu3, feu4, id_prio, depart_prio, arrivee_prio
    attacher la mémoire partagée en RW

    créer la boîte aux lettres
    attacher la boîte aux lettres

    créer le sémaphore mutex

    créer le processus fils Generateur_traffic_prio
    créer le processus fils Feux

    down(mutex)
    stocker les PID de Coordinateur et de Feux dans la mémoire partagée
    up(mutex)

    rediriger le signal SIGUSR1 vers la fonction alerter_feux

    int[NB_VOITURES][3] voitures
    int nb;

    for(i=0;i<NB_VOITURES;i++) {
        voitures[i][0] = 0
        voitures[i][1] = 0
        voitures[i][2] = 0
    }

    while(1) {
        nb = 0;
        lire état des feux

        for(i=0;i<NB_VOITURES;i++) {
            if(voiture[i][2] == 0){
                if(il y a une voiture dans la file) {
                    voitures[i][0] = depart
                    voitures[i][1] = arrivee
                    voitures[i][2] = id
                    nb++
                }
            } else {
                nb++
            }
        }

        afficher l''état des voitures

        for(i = 0; i < nb; i++) {
            if(feu_nord == VERT && feu_sud == VERT && feu_est == ROUGE && feu_ouest == ROUGE) {
                if((voitures[i][0] == NORD && (voitures[i][1] == SUD || voitures[i][1] == OUEST)) || (voitures[i][0] == SUD && (voitures[i][1] == NORD || voitures[i][1] == EST))) {
                    voitures[i][0] = voitures[i][1] = voitures[i][2] = 0
                    afficher "Coordinateur : La voiture `voitures[i][2]` a pu franchir le carrefour."
                }

                if((voitures[i][0] == NORD && voitures[i][1] == EST) || (voitures[i][0] == SUD && voitures[i][1] == OUEST)) {
                    voitures[i][0] = voitures[i][1] = voitures[i][2] = 0
                    afficher "Coordinateur : La voiture `voitures[i][2]` a pu franchir le carrefour."
                }
            } else if(feu_est == VERT && feu_ouest == VERT && feu_nord = ROUGE && feu_sud == ROUGE) {
                if((voitures[i][0] == EST && (voitures[i][1] == OUEST || voitures[i][1] == NORD)) || (voitures[i][0] == OUEST && (voitures[i][1] == EST || voitures[i][1] == SUD))) {
                    voitures[i][0] = voitures[i][1] = voitures[i][2] = 0
                    afficher "Coordinateur : La voiture `voitures[i][2]` a pu franchir le carrefour."
                }

                if((voitures[i][0] == EST && voitures[i][1] == SUD) || (voitures[i][0] == OUEST && voitures[i][1] == NORD)) {
                    voitures[i][0] = voitures[i][1] = voitures[i][2] = 0
                    afficher "Coordinateur : La voiture `voitures[i][2]` a pu franchir le carrefour."
                }
               afficher état des voitures
            }
        }

        mettre les voitures restantes au début du tableau pour qu''elles soient au début de la file du feu...
    }

    se détacher de la boite aux lettres
    se détacher de la mémoire partagée
}

Generateur_traffic {
    attacher la boite aux lettres

    int id, depart, arrive;

    while(1) {
        depart = random(1..4);
        arrivee = random(1..4);

        while(depart == arrivee) {
            depart = random(1..4);
        }

        afficher "Générateur traffic : La voiture `id` vient de `depart` et veut aller vers `arrivee`"
        écrire id, depart et arrivee dans la boite aux lettres

        id++
        sleep(1)
    }

    se détacher de la boite aux lettres
}

Generateur_traffic_prio {
        attacher le mutex
        attacher la mémoire partagée en RW
        récupérer le PID de Coordinateur

        int id_prio = 0;

        while(1) {
            int t = random(15..25)
            sleep(t)

            depart_prio = random(1..4)
            arrivee_prio = random(1..4)

            while(depart_prio == arrivee_prio) {
                depart_prio = random(1..4)
            }

            down(mutex)
            envoyer id_prio, depart_prio et arrivee_prio dans la mémoire partagée
            up(mutex)

            afficher "!!! PRIORITAIRE Génération traffic prio : La voiture `id_prio` vient de `depart` et veut aller vers `arrivee`. Je préviens le coordinateur."
            id_prio++
            envoyer un signal SIGUSR1 au Coordinateur
        }

        se détacher de la mémoire partagée
}

Feux {
    attacher le mutex
    attacher la mémoire partagée en RW
    armer redirection signal SIGUSR2 vers fonction gestion_prio
    int k = 0;

    while(1) {
        sleep(5);
        k++;

        if(k%2 == 0) { // On passe les feux nord/sud au vert et les feux est/ouest au rouge
            feu_nord = VERT;
            feu_sud = VERT;
            feu_est = ROUGE;
            feu_ouest = ROUGE;
            afficher "Feux : passage des feux Nord et Sud au vert."
        } else { // On fait l'inverse
            feu_nord = VERT;
            feu_sud = VERT;
            feu_est = ROUGE;
            feu_ouest = ROUGE;
            afficher "Feux : passage des feux Est et Ouest au vert."
        }

        down(mutex)
        envoyer l''état des feux dans la mémoire partagée
        up(mutex)
    }

    se détacher de la mémoire partagée
}

alerter_feux {
    attacher la mémoire partagée et récupérer le PID de Feux
    afficher "!!! PRIORITAIRE Coordinateur : un véhicule prioritaire arrive. Je préviens les feux."
    envoyer signal SIGUSR2 à Feux
    se détacher de la mémoire partagée
}

gestion_prio() {
    attacher la mémoire partagée en RW

    afficher "!!! PRIORITAIRE Feux : passage de tous les feux au rouge"
    feu_nord = feu_est = feu_sud = feu_ouest = ROUGE;

    afficher "!!! PRIORITAIRE Feux : passage du feu "
    switch(depart_prio) {
        case NORD:
            feu_nord = VERT;
            afficher "Nord"
            break;
        case EST:
            feu_est = VERT;
            afficher "Est"
            break;
        case SUD:
            feu_sud = VERT;
            afficher "Sud"
            break;
        case OUEST:
            feu_ouest = VERT;
            afficher "Ouest"
            break;
    }
    afficher " au vert"

    envoyer l''état des feux dans la mémoire partagée
    se détacher de la mémoire partagée
}
