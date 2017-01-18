#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// moyenneDesValeursEntrees2
/* Calcul de la moyenne des valeurs contenues dans un tableau (dynamique)
 * tableau dynamique: vector<type>nom(taille); et en haut un include <vector> */
/* vais avoir besoin de cette fonction pour qui entrerait n'importe quoi: */
bool read_choice( double & N )  /* fonction read_choice qui va se servir de
                                 * numeric_limits: alors include <limits> */
{
    cout << "Entrez une note entre 0 et 20 : " ;
    while ( ! ( cin >> N ) || N < 0 || N > 20 )
     {
        if ( cin.eof() )
         {
            // ^D  (^Z sous windows); Fin du flux d'entree !
            return false;
         }
        else if ( cin.fail() )
         {
	cout << "Saisie incorrecte, c'est pas bien ! recommence : ";
	cin.clear();
	/* cin.clear()  c'est pour effacer les bits d'erreurs  */
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	/* cin.ignore ci-dessus pour supprimer la ligne erronée dans le buffer 
*/
         }
        else
         {
            cout << "La note n'est pas entre 0 et 20, recommence : ";
         }
     }
    return true; // succès; la fonction renvoie la note comme il faut
}

int main()
{
 // Je déclare un tableau que je nomme notesSur20:
/*  vector<double> notesSur20;  / tableau vide: pas de parenthèses ni de
 * taille, ce qui => pb pour l'itération ligne 20 */
vector<double> notesSur20(1,0);  /* je déclare un tableau dynamique de taille
                                  * 1 et de  valeur 0  */
 int i(0); // je déclare la variable d'itération
 double moyenne(0); // je déclare la variable moyenne
 double note ; // je déclare la variable note qui répondra au cout ci-dessous
 char OuiNon; // pour ligne 60
 // boucle for pour entrer les notes:
  for(int i=0; i<notesSur20.size(); ++i)
    /* au départ de cette boucle, si déclaration ligne 12, donc  i=0, déjà un
    * truc curieux: i doit être < à la taille du tableau qui à ce moment est
    * zéro: donc ça ne peut pas marcher. Il faut: déclarer le tableau au moins
    * de taille 1: ligne 14 : ainsi la boucle commence avec i=0 et size=1 */
    {
     // cout<<"donne une note sur 20 : "; cin >> note;  // l'utilisateur tape sa 
note
     /* je remplace la ligne ci-dessus par: */
     if ( read_choice( note ) )
      {
        cout << "Vous avez entré : " << note << " sur 20 " << '\n';
        cout << "Sont-ce là toutes les notes ? Si Oui, tapez o et si Non, tu 
tapes n" << endl;
      }
        char OuiNon;
      cin >> OuiNon;
      if (OuiNon ='o')  // j'avais oublié les guillemets simples
       {
         ++i;
       }
      else
      {
       cout <<"On passe à la phase 2: on va moyenner tout ça... "<<endl;
      }
    }
    // ensuite on ajoute cette valeur note dans le tableau notesSur20:
     notesSur20.push_back(note); /* grace à  pushback, le tableau grandit tout
                                  * seul en rajoutant une case à chaque fois;
                                  * pour le vérifier affichons dans la boucle: 
*/
     cout <<" ce qui fait "<< notesSur20.size() -1 <<" notes entrées."<<endl;
     /* ça marche jusque là; l'a fallu que je rajoute -1 pour que ce soit vrai,
      * à cause de la déclaration ligne 14 du tableau avec taille 1, case = 0;
      * pour ci-dessous, je suppose qu'il faut une autre boucle for ? */
    /* Oui mais auparavant, il y a un pb: mon job ne sait que me demander 
d'entrer
     * des notes... il ne sait jamais quand c'est fini; dixit ternel et donc il
     * ne passe jamais au for suivant: calcul des moyennes...
     * Alors quand se termine cette boucle ? Faudra poser la question: */
     /* cout << "Est-ce la dernière note ?" << endl; / qui => réponse booléenne.
     * En fait, faut aussi considérer que l'usager tape n'importe quoi, soit
     * pour rigoler, soit pour signifier que sa liste est terminée; pour cela:
     * pour cela, Winjerome me donne un conseil très interessant par lien:
     * http://cpp.developpez.com/faq/cpp/?page=Manipulation-de-la-
     * console#Comment-verifier-les-valeurs-saisies-avec-cin que j'essaie
     * d'intégrer ici: OK, c'est bon!!! chouette. Maintenant: */

  // autre boucle d'itération for parcourant toutes les cases du tableau:
  for(int i=0; i<notesSur20.size(); ++i)
     {
      moyenne += notesSur20 [i]; /* dans la variable moyenne, += on ajoute
                                 * les valeurs contenues dans le tableau */
     }
 // puis, boucle terminée,  on en sort et /= on divise cette somme
   moyenne /= notesSur20.size();  // par la taille du tableau
   cout <<"Ces "<< notesSur20.size() <<" notes font une moyenne de "<<endl;
   cout << moyenne << " /20 pour la classe" << endl;

 return 0;
}
